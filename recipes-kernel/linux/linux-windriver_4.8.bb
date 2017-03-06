#
# Copyright (C) 2016 Wind River Systems, Inc.
#
inherit kernel
inherit urlmap
# Decide which kernel inc to pull in.  MULTI_KVM_GUEST_TRIGGER is
# defined in local.conf and is set by configure flag --enable-kvm-multi-guest-build
KERNEL_INC = "${@base_conditional('MULTI_KVM_GUEST_TRIGGER', '1','kvm-guest-kernel.inc','linux-windriver.inc',d)}"
require recipes-kernel/linux/${KERNEL_INC}

KBRANCH_DEFAULT ?= "standard/base"
KBRANCH_DEFAULT_preempt-rt ?= "standard/preempt-rt/base"
KBRANCH_DEFAULT_cgl ?= "standard/cgl/base"
KBRANCH_DEFAULT_tiny ?= "standard/tiny/base"

KBRANCH = "${KBRANCH_DEFAULT}"

LINUX_VERSION = "4.8.18"

PV = "${LINUX_VERSION}"

# This checks if LINUX_KERNEL_TYPE is in TARGET_SUPPORTED_KTYPES,
# declared compatible if yes.
COMPATIBLE_MACHINE ?= '${@machine_ktype_compatibility(d)}'

# disabled: linux-tools.inc provides a perf building/packaging
# hook. Instead we'll use a standalone perf package.
# require recipes-kernel/linux/linux-tools.inc

KMETA ?= "kernel-meta"
KSRC_linux_windriver_4_8 ?= "${THISDIR}/../../git/kernel-4.8.x.git"
KSRC_kernel_cache ?= "${THISDIR}/../../git/kernel-cache.git"
EXTRA_KERNEL_SRC_URI ?= ""
SRC_URI = "git://${KSRC_linux_windriver_4_8};protocol=file;branch=${KBRANCH};name=machine \
	   git://${KSRC_kernel_cache};protocol=file;type=kmeta;name=meta;branch=WRLINUX_9_0_HEAD;destsuffix=${KMETA} \
	   ${EXTRA_KERNEL_SRC_URI} \
	   "

include qemu.inc
include srcrev.inc
