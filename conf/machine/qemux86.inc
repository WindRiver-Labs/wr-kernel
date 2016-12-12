PCMCIA_MANAGER = "pcmciautils"

MACHINE_FEATURES = "alsa pcmcia bluetooth irda usbgadget screen"

IMAGE_FSTYPES += "tar.bz2"

KERNEL_FEATURES += "${@bb.utils.contains('IMAGE_FSTYPES', 'live', 'cfg/boot-live.scc', '', d)}"

ROOT_FLASH_SIZE = "280"

# Don't include kernels in standard images
RDEPENDS_kernel-base = ""

PREFERRED_VERSION_linux-windriver ?= "4.8%"

QB_KERNEL_CMDLINE_APPEND_append = " clocksource=pit console=ttyS0,115200"
