#
# Copyright (C) 2012 Wind River Systems, Inc.
#
require recipes-bsp/u-boot/u-boot.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=4c6cde5df68eff615d36789dc18edd3b"

# This revision corresponds to the tag "v2010.03"
# We use the revision in order to avoid having to fetch it from the repo during parse
SRCREV = "ca6e1c136ddb720c3bb2cc043b99f7f06bc46c55"

SRC_URI = "git://git.denx.de/u-boot.git;branch=master;protocol=git "
SRC_URI_append_lsi-acp34xx = "file://0001-Applied-lsi.patch.patch \
                              file://0002-acp344xv2-acp342x-update-the-device-tree-header-file.patch \
                              file://0003-lsi-acp-Using-the-status-field-to-replace-enabled.patch"

S = "${WORKDIR}/git"

do_compile () {
	unset LDFLAGS
	unset CFLAGS
	unset CPPFLAGS

	if [ "x${UBOOT_MACHINES}" == "x" ]; then
		UBOOT_MACHINES=${UBOOT_MACHINE}
	fi

	for board in ${UBOOT_MACHINES}; do
		oe_runmake distclean
		oe_runmake ${board}_config
		oe_runmake all
		
		cp ${S}/u-boot.img  ${S}/u-boot-${board}.img
	done
}

do_install(){
	if [ "x${UBOOT_MACHINES}" == "x" ]; then
		UBOOT_MACHINES=${UBOOT_MACHINE}
	fi
	
	echo ${UBOOT_MACHINES}

	for board in ${UBOOT_MACHINES}; do
		if [ -f ${S}/u-boot-${board}.img ]; then
			mkdir -p ${D}/boot/
			install ${S}/u-boot-${board}.img ${D}/boot/u-boot-${board}-${PV}-${PR}.img
		fi
	done
}

do_deploy(){
	if [ "x${UBOOT_MACHINES}" == "x" ]; then
		UBOOT_MACHINES=${UBOOT_MACHINE}
	fi

	for board in ${UBOOT_MACHINES}; do
	        if [ -f ${S}/${board}/u-boot-${board}.img ]; then
			mkdir -p ${DEPLOYDIR}
			install ${S}/u-boot-${board}.img ${DEPLOYDIR}/u-boot-${board}-${PV}-${PR}.img

			cd ${DEPLOYDIR}
			rm -f u-boot-${board}.img
		fi
	done
}
addtask deploy after do_install
