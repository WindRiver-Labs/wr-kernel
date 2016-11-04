#
# Copyright (C) 2015 Wind River Systems, Inc.
#

PCMCIA_MANAGER = "pcmciautils"

MACHINE_FEATURES = "alsa pcmcia bluetooth irda usbgadget screen"

IMAGE_FSTYPES += "tar.bz2"

ROOT_FLASH_SIZE = "280"

# Don't include kernels in standard images
RDEPENDS_kernel-base = ""

PREFERRED_VERSION_linux-windriver ?= "4.8%"

QB_OPT_APPEND_append = " -bios mips_bios.bin"
QB_CPU = "-cpu MIPS64R2-generic"
QB_KERNEL_CMDLINE_APPEND_append = " oprofile.timer=1"
