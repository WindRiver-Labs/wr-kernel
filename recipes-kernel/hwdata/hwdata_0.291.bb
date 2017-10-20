#
# Copyright (C) 2015 Wind River Systems, Inc.
#
SUMMARY = "Hardware identification and configuration data."
DESCRIPTION = "This package contains various hardware identification and configuration data, such as the pci.ids database, or the XFree86/xorg Cards database."

LICENSE = "GPL-2.0 | XFree86-1.0"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263\
                    file://LICENSE;md5=1556547711e8246992b999edd9445a57"

DEPENDS = "pciutils usbutils"

inherit allarch

#S="${WORKDIR}/${BPN}-${BP}"

PV = "0.291+git${SRCPV}"
SRCREV = "4bfbdcf5913d6dd53336d31b8035708075e6fdfa"
SRC_URI = "git://github.com/vcrhonek/${BPN}.git"

S = "${WORKDIR}/git"

do_configure() {
     ${S}/configure
}

do_install() {
        make install DESTDIR=${D}
}


FILES_${PN} += "${libdir}/modprobe.d/dist-blacklist.conf"
