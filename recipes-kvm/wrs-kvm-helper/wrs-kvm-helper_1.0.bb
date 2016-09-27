#
# Copyright (C) 2012-2013 Wind River Systems, Inc.
#
DESCRIPTION = "This package contains the helper scripts to run KVM on \
target."

LICENSE = "windriver"

LICENSE_FLAGS = "commercial_windriver"

LIC_FILES_CHKSUM = "file://run-kvm-guest;beginline=2;endline=4;md5=de6aa5c42d590965ee906eb1628a2182"

SRC_URI = "\
	file://run-kvm-guest \
	file://qemu-ifup \
	"

S = "${WORKDIR}"

do_install() {
	install -d ${D}${bindir}
	install -m 0755 run-kvm-guest ${D}${bindir}
	install -d ${D}/etc
	install -m 0755 qemu-ifup ${D}/etc
}

FILES_${PN}  = "${bindir}/*"
FILES_${PN} += "/etc/*"
