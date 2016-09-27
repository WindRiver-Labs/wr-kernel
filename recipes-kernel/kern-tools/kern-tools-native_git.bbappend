#
# Copyright (C) 2012 Wind River Systems, Inc.
#
SRCREV="${AUTOREV}"
LOCALCOUNT = "0"

THISDIR := "${@os.path.dirname(d.getVar('FILE', True))}"

LIC_FILES_CHKSUM = "file://git/tools/kgit;beginline=5;endline=9;md5=a6c2fa8aef1bda400e2828845ba0d06c"

KERN_TOOLS_SRC = "${THISDIR}/../../git/windriver-kernel-tools.git;branch=WRLINUX_9_0_HEAD;protocol=file"
SRC_URI = "git://${KERN_TOOLS_SRC}"

