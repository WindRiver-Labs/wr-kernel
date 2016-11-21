#
# Copyright (C) 2012 Wind River Systems, Inc.
#
SUMMARY = "inject machine check errors on the software level into a running Linux kernel"

DESCRIPTION = "mce-inject allows to inject machine check errors on the \
software level into a running Linux kernel. This is intended for \
validation of the kernel machine check handler."

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://README;md5=26cb2dca1b099a7e8397f7a18db6fdfc"

SRC_URI = "git://git.kernel.org/pub/scm/utils/cpu/mce/mce-inject.git;protocol=git"
SRCREV = "4cbe46321b4a81365ff3aafafe63967264dbfec5"

S ="${WORKDIR}/git"

COMPATIBLE_HOST = '(i.86|x86_64).*-linux'

DEPENDS = "bison-native flex-native"

EXTRA_OEMAKE_append_task-install = " destdir=${D}"

inherit autotools-brokensep
