#
# Copyright (C) 2012 Wind River. Ltd.
#

DESCRIPTION = "Add kernel-debug feature related packages"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=4d92cd373abda3937c2bc47fbc49d690 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"
PR = "r0"

PACKAGES = "\
    packagegroup-core-kdbg-tune \
    packagegroup-core-kdbg-tune-dbg \
    packagegroup-core-kdbg-tune-dev \
    "

ALLOW_EMPTY_packagegroup-core-kdbg-tune = "1"

RDEPENDS_packagegroup-core-kdbg-tune = "trace-cmd perf \
       packagegroup-core-tools-profile-lttng \
"

# the "real" packages will still be in world
# if MACHINE_COMPATIBLE
#
EXCLUDE_FROM_WORLD = "1"
