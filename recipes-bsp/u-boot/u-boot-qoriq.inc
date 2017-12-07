require u-boot-base.inc
inherit fsl-u-boot-localversion

DESCRIPTION = "U-boot provided by Freescale with focus on QorIQ boards"
PROVIDES += "u-boot"

PV_append = "+fslgit"
INHIBIT_DEFAULT_DEPS = "1"
DEPENDS = "libgcc virtual/${TARGET_PREFIX}gcc"
DEPENDS_append_qoriq-arm = " change-file-endianess-native dtc-native tcl-native"
DEPENDS_append_qoriq-arm64 = " change-file-endianess-native dtc-native tcl-native"
DEPENDS_append_qoriq-ppc = " boot-format-native"
DEPENDS_append_aarch64 = " change-file-endianess-native dtc-native tcl-native"
DEPENDS_append_nxp-ls1046 = " virtual/kernel"
DEPENDS_append_nxp-ls1012 = " virtual/kernel"

python () {
    if d.getVar("TCMODE", True) == "external-fsl":
        return

    ml = d.getVar("MULTILIB_VARIANTS", True)
    arch = d.getVar("OVERRIDES", True)
    if "e5500-64b:" in arch or "e6500-64b:" in arch:
        if not "lib32" in ml:
            raise bb.parse.SkipPackage("Building the u-boot for this arch requires multilib to be enabled")
        sys_multilib = 'powerpc' + d.getVar('TARGET_VENDOR') + 'mllib32-' + d.getVar('HOST_OS')
        d.setVar('DEPENDS_append', ' lib32-gcc-cross-powerpc lib32-libgcc')
        d.setVar('PATH_append', ':' + d.getVar('STAGING_BINDIR_NATIVE') + '/' + sys_multilib)
        d.setVar('TOOLCHAIN_OPTIONS_append', '/../lib32-' + d.getVar("MACHINE"))
        d.setVar("WRAP_TARGET_PREFIX", sys_multilib + '-')
}

LE_UBOOT_FOR_ARMBE_TARGET ?= "0"
ENDIANNESS_GCC = "${@bb.utils.contains("LE_UBOOT_FOR_ARMBE_TARGET", "1", "-mlittle-endian", "", d)}"
ENDIANNESS_LD = "${@bb.utils.contains("LE_UBOOT_FOR_ARMBE_TARGET", "1", "-EL", "", d)}"
WRAP_TARGET_PREFIX ?= "${TARGET_PREFIX}"
EXTRA_OEMAKE = 'CROSS_COMPILE=${WRAP_TARGET_PREFIX} \
    CC="${WRAP_TARGET_PREFIX}gcc ${TOOLCHAIN_OPTIONS} ${ENDIANNESS_GCC}" \
    LD="${WRAP_TARGET_PREFIX}ld ${ENDIANNESS_LD}"'
EXTRA_OEMAKE += 'HOSTCC="${BUILD_CC} ${BUILD_CFLAGS} ${BUILD_LDFLAGS}"'

LOCALVERSION = "${@d.getVar('SDK_VERSION', True).partition(' ')[0]}"

do_compile_append_aarch64() {
    unset i j k
    for config in ${UBOOT_MACHINE}; do
        i=`expr $i + 1`;
        for type in ${UBOOT_CONFIG}; do
            j=`expr $j + 1`;
            for binary in ${UBOOT_BINARIES}; do
                k=`expr $k + 1`
                if [ $j -eq $i ] && [ $k -eq $i ]; then
                    cp ${config}/${binary} ${config}/u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX}
                    # use boot-format to regenerate spi image if BOOTFORMAT_CONFIG is not empty
                    if [ -n "${BOOTFORMAT_CONFIG}" ] && echo "${type}" |grep -q spi;then
                        ${STAGING_BINDIR_NATIVE}/boot_format \
                            ${STAGING_DATADIR_NATIVE}/boot_format/${BOOTFORMAT_CONFIG} \
                            ${config}/${binary} -spi ${config}/u-boot.format.bin
                        cp ${config}/u-boot.format.bin ${config}/u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX}
                    elif [ "qspi" = "${type}" ];then
                        tclsh ${STAGING_BINDIR_NATIVE}/byte_swap.tcl ${config}/${binary} ${config}/u-boot.swap.bin 8
                        cp ${config}/u-boot.swap.bin ${config}/u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX}
                    fi
                fi
            done
            unset k
        done
        unset j
    done
    unset i
}

do_install_aarch64() {
    cd ${S}
    install -d ${D}/boot
    unset i j
    for config in ${UBOOT_MACHINE}; do
        i=`expr $i + 1`;
        for type in ${UBOOT_CONFIG}; do
            j=`expr $j + 1`;
            if [ $j -eq $i ]; then
                install ${config}/u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX} ${D}/boot/
                ln -sf u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX} ${D}/boot/u-boot-${type}.${UBOOT_SUFFIX}
                ln -sf u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX} ${D}/boot/${UBOOT_SYMLINK}
                ln -sf u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX} ${D}/boot/${UBOOT_BINARY}
            fi
        done
        unset j
    done
    unset i
}

do_deploy_aarch64() {
    cd ${S}
    install -d ${DEPLOYDIR}
    unset i j
    for config in ${UBOOT_MACHINE}; do
        i=`expr $i + 1`;
        for type in ${UBOOT_CONFIG}; do
            j=`expr $j + 1`;
            if [ $j -eq $i ]; then
                install ${config}/u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX} ${DEPLOYDIR}/
                ln -sf u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX} ${DEPLOYDIR}/u-boot-${type}.${UBOOT_SUFFIX}
                ln -sf u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX} ${DEPLOYDIR}/${UBOOT_SYMLINK}
                ln -sf u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX} ${DEPLOYDIR}/${UBOOT_BINARY}
            fi
        done
        unset j
    done
    unset i
}

PACKAGES += "${PN}-images"
FILES_${PN}-images += "/boot"

COMPATIBLE_MACHINE_nxp-ls1046 = "nxp-ls1046"
COMPATIBLE_MACHINE_nxp-ls1012 = "nxp-ls1012"
