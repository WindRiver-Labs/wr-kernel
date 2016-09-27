DESCRIPTION = "U-boot bootloader fw_printenv/setenv utils"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=4c6cde5df68eff615d36789dc18edd3b"
SECTION = "bootloader"
DEPENDS = "mtd-utils"

SRCREV = "ca6e1c136ddb720c3bb2cc043b99f7f06bc46c55"

PV = "2010.03+git${SRCREV}"

SRC_URI = "git://git.denx.de/u-boot.git;branch=master;protocol=git "
SRC_URI_append_lsi-acp34xx = "file://0001-Applied-lsi.patch.patch \
                              file://0002-acp344xv2-acp342x-update-the-device-tree-header-file.patch \
                              file://0003-lsi-acp-Using-the-status-field-to-replace-enabled.patch \
                              file://0001-tools-env-use-host-build-flags.patch \
                              file://0001-tools-env-cleanup-host-build-flags.patch "

S = "${WORKDIR}/git"

EXTRA_OEMAKE = 'HOSTCC="${CC}" HOSTSTRIP="true" CROSS_COMPILE="${TARGET_PREFIX}"'

inherit uboot-config

do_compile () {
  oe_runmake ${UBOOT_MACHINE}_config
  oe_runmake env
}

do_install () {
  install -d ${D}${base_sbindir}
  install -m 755 ${S}/tools/env/fw_printenv ${D}${base_sbindir}/fw_printenv
  install -m 755 ${S}/tools/env/fw_printenv ${D}${base_sbindir}/fw_setenv
}

PACKAGE_ARCH = "${MACHINE_ARCH}"
