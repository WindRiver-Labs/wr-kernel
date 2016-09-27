#
# Copyright (C) 2013,2014 Wind River Systems, Inc.
#
# Note: overriding libc-headers can cause system level problems, due to
#       changed APIs and partial rebuilds. So it should only be considered
#       as a last resort. 

do_unpack[depends] += "virtual/kernel:do_patch"

do_install_append() {
	install -d ${D}${includedir}

	staging_kernel_dir=${STAGING_KERNEL_DIR}
	if [ -d ${staging_kernel_dir} ]; then
		rm -rf ${S}/*
		cp -r ${staging_kernel_dir}/* ${S}
		oe_runmake headers_install INSTALL_HDR_PATH=${D}${exec_prefix}
	fi
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
