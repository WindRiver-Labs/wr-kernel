#
# Copyright (C) 2012 Wind River. Ltd.
#

DESCRIPTION = "Add use packages that cooperate with certain kernel features"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=4d92cd373abda3937c2bc47fbc49d690 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"
PR = "r0"

PACKAGES = "\
    packagegroup-core-kernel-tune \
    packagegroup-core-kernel-tune-dbg \
    packagegroup-core-kernel-tune-dev \
    "

ALLOW_EMPTY_packagegroup-core-kernel-tune = "1"

RDEPENDS_packagegroup-core-kernel-tune = "irqbalance xfsprogs xfsdump \
	powertop latencytop \
"

