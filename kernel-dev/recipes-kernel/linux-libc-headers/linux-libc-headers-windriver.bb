#
# Copyright (C) 2013 - 2016 Wind River Systems, Inc.
#
require recipes-kernel/linux-libc-headers/linux-libc-headers.inc

PROVIDES = "linux-libc-headers"

PV = "4.8"

KBRANCH ?= "standard/base"
SRCREV = "${AUTOREV}"

KSRC_linux_windriver_4_8 ?= "${THISDIR}/../../../git/kernel-4.8.x.git"
SRC_URI = "git://${KSRC_linux_windriver_4_8};protocol=file;branch=${KBRANCH};name=machine"

S = "${WORKDIR}/git"
