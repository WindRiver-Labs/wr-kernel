#
# Copyright (C) 2012 - 2015 Wind River Systems, Inc.
#
def machine_ktype_compatibility(d):
    kernel_type = d.getVar('LINUX_KERNEL_TYPE', True)
    supported_types = (d.getVar('TARGET_SUPPORTED_KTYPES', True) or '').split()

    if kernel_type and kernel_type in supported_types:
        return d.getVar('MACHINE', True)
    else:
        bb.warn("%s doesn't support %s, supported types are: %s" % \
                    (d.getVar('PN', True), kernel_type, supported_types))
        return 'none'

KERNEL_SYSTEM_MAP_BASE_NAME ?= "System.map-${PV}-${PR}-${MACHINE}-${DATETIME}"
VMLINUX_SYMBOLS_BASE_NAME ?= "vmlinux-symbols-${PV}-${PR}-${MACHINE}-${DATETIME}"

# Don't include the DATETIME variable in the sstate package signatures
KERNEL_SYSTEM_MAP_BASE_NAME[vardepsexclude] = "DATETIME"
VMLINUX_SYMBOLS_BASE_NAME[vardepsexclude] = "DATETIME"

do_deploy_append() {
        set +e

	install -d ${DEPLOYDIR}

	install -m 0644 ${STAGING_KERNEL_BUILDDIR}/System.map-${KERNEL_VERSION} ${DEPLOYDIR}/${KERNEL_SYSTEM_MAP_BASE_NAME}
	install -m 0644 ${D}/boot/vmlinux-${KERNEL_VERSION} ${DEPLOYDIR}/${VMLINUX_SYMBOLS_BASE_NAME}

	cd ${DEPLOYDIR}

	ln -sf ${KERNEL_SYSTEM_MAP_BASE_NAME} System.map-${MACHINE}
	ln -sf ${VMLINUX_SYMBOLS_BASE_NAME} vmlinux-symbols-${MACHINE}
}


OE_TERMINAL_EXPORTS += "GUILT_BASE KBUILD_OUTPUT LDFLAGS CC KCFLAGS"
GUILT_BASE = "meta"
python do_devshell () {
    # The CROSS_COMPILE and ARCH are already exported by the global
    # OE_TERMINAL_EXPORTS, and hence we don't need to add them explicitly
    # in the list.
    d.setVar("GUILT_BASE", "meta")
    d.setVar("KBUILD_OUTPUT", "${B}")
    d.setVar("LDFLAGS", "")
    # We clear CC, so the kernel can use CROSS_COMPILE directly
    d.setVar("CC", "")
    # We use KCFLAGS to set a sysroot for cross-toolchain,
    # so that it can locate libgcc properly.
    d.setVar("KCFLAGS", "--sysroot=%s" % (d.getVar('STAGING_DIR_TARGET', False) or ''))
    oe_terminal( d.getVar('SHELL', True), 'Wind River Kernel Developer Shell', d)
}

# builds an individual external module in directory M or builds
# all modules if M is not set.
do_module() {
	if [ -n "${M}" ]; then
		unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS MACHINE
		oe_runmake ${PARALLEL_MAKE} M=${M} CC="${KERNEL_CC}" LD="${KERNEL_LD}"
	else
		do_compile_kernelmodules
	fi
}
addtask do_module after do_compile

do_menuconfig[vardepsexclude] += "DATETIME"
python do_menuconfig_append() {
    import subprocess

    # save the .config
    cmd = d.expand("cp -f ${B}/.config ${WORKDIR}/config-${PV}-${PR}-${MACHINE}-${DATETIME}")
    ret, result = subprocess.getstatusoutput("%s" % (cmd))
    bb.plain(d.expand("Saving .config to ${WORKDIR}/config-${PV}-${PR}-${MACHINE}-${DATETIME}"))
}

# sanity updates. The do_package_qa_prepend and vmlinux sanity
# flags allow a 64 bit kernel + modules to be packaged against a
# 32 bit userspace. If external modules are built, they must supply
# their own INSANE_SKIP_<module> = "arch" if they want to be properly
# packaged.
python do_package_qa_prepend () {
    pkgs = d.getVar( 'PACKAGES', True )
    module_pattern = 'kernel-module-%s'
    module_regex = '^(.*)\.k?o$'
    dvar = d.getVar('PKGD', True)
    root = '/lib/modules'

    objs = []
    for walkroot, dirs, files in os.walk(dvar + root):
        for file in files:
            relpath = os.path.join(walkroot, file).replace(dvar + root + '/', '', 1)
            if relpath:
                objs.append(relpath)

    for o in sorted(objs):
        import re, stat

        m = re.match(module_regex, os.path.basename(o))

        if not m:
            continue

        f = os.path.join(dvar + root, o)
        mode = os.lstat(f).st_mode
        if not (stat.S_ISREG(mode) or (allow_links and stat.S_ISLNK(mode)) or (allow_dirs and stat.S_ISDIR(mode))):
            continue
        on = legitimize_package_name(m.group(1))
        pkg = module_pattern % on

        bb.note( "INFO: flagging %s to skip arch sanity checking" % pkg )

        d.setVar('INSANE_SKIP_%s' % pkg, "arch")
}
INSANE_SKIP_kernel-vmlinux += "arch"
INSANE_SKIP_kernel-image += "arch"
