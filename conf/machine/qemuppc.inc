#
# Copyright (C) 2013 Wind River Systems, Inc.
#

PCMCIA_MANAGER = "pcmciautils"

MACHINE_FEATURES = "alsa pcmcia bluetooth irda usbgadget screen"

IMAGE_FSTYPES += "tar.bz2"

ROOT_FLASH_SIZE = "280"

# Don't include kernels in standard images
RDEPENDS_kernel-base = ""

PREFERRED_VERSION_linux-windriver ?= "4.8%"

USE_SDK_GLIBC = "0"

QB_KERNEL_CMDLINE_APPEND = "console=ttyS0,115200 oprofile.timer=1"
