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

SRC_URI = "http://ftp.slackware.com/pub/slackware/slackware-current/source/a/hwdata/${BP}.tar.xz"
SRC_URI[md5sum] = "20c5cab3adffdac55a80d05b4290ae69"
SRC_URI[sha256sum] = "aaf07f1f446ae818252128de56905c33c48da93cf548cb82dacc36d8728f3888"

do_configure() {
     ${S}/configure
}

do_install() {
        make install DESTDIR=${D}
}


FILES_${PN} += "${libdir}/modprobe.d/dist-blacklist.conf"
