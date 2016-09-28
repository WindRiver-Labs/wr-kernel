#
# Copyright (C) 2013 Wind River Systems, Inc.
#

PCMCIA_MANAGER = "pcmciautils"

MACHINE_FEATURES = "alsa pcmcia bluetooth irda usbgadget screen"

IMAGE_FSTYPES += "tar.bz2"

ROOT_FLASH_SIZE = "280"

# Don't include kernels in standard images
RDEPENDS_kernel-base = ""

# Use a common kernel recipe for all QEMU machines
PREFERRED_PROVIDER_virtual/kernel ?= "linux-windriver"
PREFERRED_VERSION_linux-windriver ?= "4.8%"

EXTRA_IMAGEDEPENDS += "qemu-native qemu-helper-native"

USE_SDK_GLIBC = "0"

TARGET_QEMU_BIN="qemu-system-ppc"
TARGET_QEMU_BOOT_CONSOLE="ttyS0,115200"
TARGET_QEMU_KERNEL_OPTS=" oprofile.timer=1"
TARGET_QEMU_OPTS="-M mac99"
TARGET_QEMU_KERNEL="vmlinux"
TARGET_QEMU_ENET_MODEL="pcnet"
TARGET_QEMU_CPU="G4"
TARGET_QEMU_MEM="128"
