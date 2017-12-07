require recipes-bsp/u-boot/u-boot-qoriq_2016.01.bb

python () {
    ml = d.getVar("MULTILIB_VARIANTS", True)
    arch = d.getVar("TRANSLATED_TARGET_ARCH", True)
    if "arm" in arch:
        if not "lib32" in ml:
            raise bb.parse.SkipPackage("Building the u-boot for this arch requires multilib to be enabled")
        sys_multilib = 'aarch64-wrs-linux'
        d.setVar('PATH_append', ':' + d.getVar('STAGING_BINDIR_NATIVE', True) + '/' + sys_multilib)
        d.setVar('TOOLCHAIN_OPTIONS_append', '/../' + d.getVar("COMPATIBLE_MACHINE", True))
        d.setVar("WRAP_TARGET_PREFIX", sys_multilib + '-')
}

SRC_URI = "git://git.freescale.com/ppc/sdk/u-boot.git;nobranch=1"
SRCREV = "a06b20925c02ba3fa888a1f915ea7935084d8600"

do_compile_append_aarch64() {
    unset i j k
    for config in ${UBOOT_MACHINE}; do
        i=`expr $i + 1`;
        for type in ${UBOOT_CONFIG}; do
            j=`expr $j + 1`;
            for binary in ${UBOOT_BINARIES}; do
                k=`expr $k + 1`
                if [ $j -eq $i ] && [ $k -eq $i ]; then
                    if [ "qspi" = "${type}" ];then
                        cp ${config}/${binary} ${config}/u-boot-${type}-${PV}-${PR}.${UBOOT_SUFFIX}
                    fi
                fi
            done
            unset k
        done
        unset j
    done
    unset i
}
