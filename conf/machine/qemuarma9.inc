#
# Copyright (C) 2013 - 2016 Wind River Systems, Inc.
#
PCMCIA_MANAGER = "pcmciautils"
PREFERRED_PROVIDER_virtual/xserver ?= "xserver-kdrive"
PREFERRED_PROVIDER_virtual/libgl ?= "mesa"

MACHINE_FEATURES = "alsa pcmcia bluetooth irda usbgadget screen"

IMAGE_FSTYPES += "tar.bz2"

ROOT_FLASH_SIZE = "280"

# Don't include kernels in standard images
RDEPENDS_kernel-base = ""

# Use a common kernel recipe for all QEMU machines
PREFERRED_PROVIDER_virtual/kernel ?= "linux-windriver"
PREFERRED_VERSION_linux-windriver ?= "4.8%"

TARGET_QEMU_BIN="qemu-system-arm"
TARGET_QEMU_OPTS="-M vexpress-a9"
TARGET_QEMU_MEM="128"
TARGET_QEMU_KERNEL="zImage"
TARGET_QEMU_DTB="vexpress-v2p-ca9.dtb"
TARGET_QEMU_BOOT_CONSOLE="ttyAMA0,115200"
TARGET_QEMU_KERNEL_OPTS=" oprofile.timer=1"
TARGET_QEMU_DISK_ARGS="-sd"
TARGET_VIRT_DISK_DEV="mmcblk0"
