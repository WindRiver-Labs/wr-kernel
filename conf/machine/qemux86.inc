PCMCIA_MANAGER = "pcmciautils"

MACHINE_FEATURES = "alsa pcmcia bluetooth irda usbgadget screen"

IMAGE_FSTYPES += "tar.bz2"

KERNEL_FEATURES += "${@bb.utils.contains('IMAGE_FSTYPES', 'live', 'cfg/boot-live.scc', '', d)}"

ROOT_FLASH_SIZE = "280"

# Don't include kernels in standard images
RDEPENDS_kernel-base = ""

# Use a common kernel recipe for all QEMU machines
PREFERRED_PROVIDER_virtual/kernel ?= "linux-windriver"
PREFERRED_VERSION_linux-windriver ?= "4.8%"

EXTRA_IMAGEDEPENDS += "qemu-native qemu-helper-native"


TARGET_QEMU_BIN = "qemu-system-i386"
TARGET_QEMU_KERNEL="bzImage"
TARGET_QEMU_KERNEL_OPTS="clock=pit oprofile.timer=1"
TARGET_QEMU_ENET_MODEL="i82557b"
TARGET_QEMU_OPTS="-show-cursor -usb -usbdevice wacom-tablet -vga vmware"
TARGET_QEMU_BOOT_CONSOLE="ttyS0,115200"
TARGET_VIRT_DISK_DEV="hda"
