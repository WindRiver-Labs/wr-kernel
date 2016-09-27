#
# Copyright (C) 2014 Wind River Systems, Inc.
#

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI += "\
file://0001-add-i586-support.patch  \
file://0002-libhugetlbfs-Only-update-mtab-when-it-s-not-a-symlin.patch  \
file://0003-libhugetlbfs-Don-t-install-LDSCRIPT_TESTS-and-xB-HUG.patch \
"
COMPATIBLE_HOST = "(i.86|x86_64|powerpc|powerpc64|aarch64|arm).*-linux*"

