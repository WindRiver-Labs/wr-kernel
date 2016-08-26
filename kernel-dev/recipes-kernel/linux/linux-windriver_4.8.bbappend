FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

# force compatibility when "kernel-dev" is being used
COMPATIBLE_MACHINE = "${MACHINE}"

# force autorev
SRCREV_machine_${MACHINE} ?= "${AUTOREV}"
SRCREV_meta ?= "${AUTOREV}"

FILES_kernel-extra-headers-misc_append = " ${KERNEL_ALT_HEADER_DIR}"

do_install_append() {
	make headers_install INSTALL_HDR_PATH=${D}${KERNEL_ALT_HEADER_DIR}

	# remove export artifacts
	find ${D}${KERNEL_ALT_HEADER_DIR} -name .install -exec rm {} \;
	find ${D}${KERNEL_ALT_HEADER_DIR} -name ..install.cmd -exec rm {} \;
}

do_install_kernel_headers_append() {
	for f in ${KERNEL_INSTALL_HEADER}; do
	src_file="${S}/include/$f"
	dest_path="${D}${KERNEL_ALT_HEADER_DIR}/include/$f"

	if [ -a ${src_file} ]; then
		install -d ${dest_path%/*}
			cp -Rn $src_file ${dest_path%/*}
			echo $f >> ${D}${KERNEL_ALT_HEADER_DIR}/kernel_install_header.manifest
		else
			echo "WARNING: header file/directory not found: $f"
		fi
	done
}

sysroot_stage_all_append() {
    sysroot_stage_dir ${D}${KERNEL_ALT_HEADER_DIR} ${SYSROOT_DESTDIR}${KERNEL_ALT_HEADER_DIR}
}

# pick up feature handlers
require linux-windriver-handlers.inc
