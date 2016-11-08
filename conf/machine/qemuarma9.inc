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

PREFERRED_VERSION_linux-windriver ?= "4.8%"
