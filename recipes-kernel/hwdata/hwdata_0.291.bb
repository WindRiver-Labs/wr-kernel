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

SRC_URI = "https://git.fedorahosted.org/cgit/hwdata.git/snapshot/${BP}.tar.gz"
SRC_URI[md5sum] = "90ffce584bbcb1a5e77eac8503949f71"
SRC_URI[sha256sum] = "e1007a96645cb3390aa9c0ed3f090a69d2302ce4d801914b6af1ab4ec85ede4e"

do_configure() {
     ${S}/configure
}

do_install() {
        make install DESTDIR=${D}
}


FILES_${PN} += "${libdir}/modprobe.d/dist-blacklist.conf"
