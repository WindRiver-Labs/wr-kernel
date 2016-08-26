#
# Copyright (C) 2013,2014 Wind River Systems, Inc.
#
# Note: overriding libc-headers can cause system level problems, due to
#       changed APIs and partial rebuilds. So it should only be considered
#       as a last resort. 

DESCRIPTION = "Sanitized set of windriver kernel headers for the C library's use."
SECTION = "devel"
LICENSE = "GPLv2"

PROVIDES = "linux-libc-headers"
RPROVIDES_${PN}-dev = "linux-libc-headers-dev"
RPROVIDES_${PN}-dbg = "linux-libc-headers-dbg"

PV = "4.1"
PR = "r0"

INHIBIT_DEFAULT_DEPS = "1"

DEPENDS = "virtual/kernel"
RDEPENDS_${PN}-dev = ""
RRECOMMENDS_${PN}-dbg = "${PN}-dev (= ${EXTENDPKGV})"

ALLOW_EMPTY_${PN} = "1"

# We only need the populating and packaging tasks - disable the rest
do_fetch[noexec] = "1"
do_unpack[noexec] = "1"
do_patch[noexec] = "1"
do_configure[noexec] = "1"
do_compile[noexec] = "1"

do_install[prefuncs] += "wrl_buildlink"

do_install() {
	install -d ${D}${includedir}

	staging_kernel_dir=${STAGING_KERNEL_DIR}
	kernel_sysroot_copy=${staging_kernel_dir%/usr/src/kernel}${KERNEL_ALT_HEADER_DIR}/include
	cp -dR --preserve=timestamps ${kernel_sysroot_copy}/. ${D}${includedir}
}

#
# Dont populate headers listed in KERNEL_INSTALL_HEADER, to avoid overlapping.
#
SYSROOT_PREPROCESS_FUNCS += "linux_header_sysroot_preprocess"

linux_header_sysroot_preprocess () {
	staging_kernel_dir=${STAGING_KERNEL_DIR}
	linux_header_manifest=${staging_kernel_dir%/usr/src/kernel}${KERNEL_ALT_HEADER_DIR}/kernel_install_header.manifest
	if [ -f $linux_header_manifest ]; then
		for f in `cat $linux_header_manifest`; do
			rm -rf ${SYSROOT_DESTDIR}${includedir}/$f
		done
	fi
}
