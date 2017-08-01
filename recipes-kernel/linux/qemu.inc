# qemuarm
TARGET_SUPPORTED_KTYPES_qemuarm = "standard preempt-rt"
KERNEL_DEVICETREE_qemuarm = "versatile-pb.dtb"
KBRANCH_qemuarm_standard ?= "standard/arm-versatile-926ejs"

# qemuarm64
TARGET_SUPPORTED_KTYPES_qemuarm64 = "standard preempt-rt"
KBRANCH_qemuarm64_standard ?= "standard/qemuarm64"

# qemuarma9
TARGET_SUPPORTED_KTYPES_qemuarma9 = "standard"
KERNEL_DEVICETREE_qemuarma9 = "vexpress-v2p-ca9.dtb"
KBRANCH_qemuarma9_standard ?= "standard/arm-versatile-926ejs"

# qemumips
TARGET_SUPPORTED_KTYPES_qemumips = "standard preempt-rt"
KBRANCH_qemumips_standard ?= "standard/mti-malta32"

# qemumips64
TARGET_SUPPORTED_KTYPES_qemumips64 = "standard preempt-rt"
KBRANCH_qemumips64_standard ?= "standard/mti-malta64"

# qemuppc
TARGET_SUPPORTED_KTYPES_qemuppc = "standard preempt-rt"
KBRANCH_qemuppc_standard ?= "standard/qemuppc"

# qemux86
TARGET_SUPPORTED_KTYPES_qemux86 = "standard preempt-rt cgl tiny ovp"
# A method to install/update for bzImage on a deployed target
KERNELLOADEREXTENSION_append_qemux86 = " kernel-grub"
KBRANCH_qemux86_tiny ?= "standard/tiny/common-pc"
KBRANCH_DEFAULT_ovp_qemux86 = "standard/ovp/${KMACHINE}"

# qemux86-64
TARGET_SUPPORTED_KTYPES_qemux86-64 = "standard preempt-rt cgl tiny ovp"
# A method to install/update for bzImage on a deployed target
KERNELLOADEREXTENSION_append_qemux86-64 = " kernel-grub"
KBRANCH_DEFAULT_ovp_qemux86-64 = "standard/ovp/${KMACHINE}"

