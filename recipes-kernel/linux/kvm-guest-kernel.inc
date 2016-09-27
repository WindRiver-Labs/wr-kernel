#
# Copyright (C) 2012 Wind River Systems, Inc.
#
# ----------------------------------------------------------------------------
# Build a kernel image suitable for a kvm guest image.  See the
# wr-kernel/Documents/kvm-build-multiple-guests.txt file for details.
# ----------------------------------------------------------------------------
require recipes-kernel/linux/linux-windriver.inc

SRC_URI += " \
           file://configs"

MULTI_CONFIG_BASE_SUFFIX = "multi-config-"
MODULES_IMAGE_BASE_NAME = "modules-${PV}-${PR}-${MACHINE}"

do_kernel_build_guest () {
	# ----------------------------------------------------------
	# wr-kernel/recipes-kernel/linux/configs will contain all the
	# scc files, patches, cfgs to use for all guests.
	# Configure passes in a set of guests to build in the format
	# --enable-kvm-multi-guest-build=kvm-x86-guest1:kvm-x86-guest2
	# where x86-guest1 will be x86-guest1.scc.  Since there may be cfg
	# files, patches etc.  keep it simple.  The scc file
	# references what it wants to use. Just copy all the files in the config dir
	# into the the META dir and Set KMACHINE to the
	# scc file name.  Then, call do_patch with a parameter, i.e.
	# what the new KMACHINE will be, e.g. x86-kvm-guest1.
	# ----------------------------------------------------------
	META=${S}/.meta/cfg/kernel-cache/bsp/kvm-multi-guest
	mkdir -p ${META}
	CFG_DIR=${WORKDIR}/configs
	mkdir -p ${CFG_DIR}
	cp -r ${THISDIR}/configs/* ${CFG_DIR}/
	cp -r ${CFG_DIR}/* ${META}

	# multiple guests definitions delimited by : may be passed
	# into configure, so strip them
	GUESTS=`echo ${COMPILE_KVM_GUESTS} | sed 's/\:/ /g'`
	ORIG_KMACHINE=${KMACHINE}
	echo "GUESTS=${GUESTS}"
	mv ${KERNEL_OUTPUT} ${KERNEL_OUTPUT}.backup
	for guest in $GUESTS; do
		if ! [ -e "${META}/${guest}.scc" ]; then
			echo "Error: configure used --enable-kvm-multi-guest-build=$GUESTS"
			echo "${CRG_DIR}/${guest}.scc not found"
			exit 1
		fi

		# pass in param to do_patch.
		do_patch "KMACHINE=$guest"
		do_kernel_configme

		# configme leaves us in source dir cd to the build dir
		cd ${B}
		do_configure
		kernel_do_compile

		# not compiling kmods now.
		echo "Installing files into ${DEPLOY_DIR_IMAGE}/opt/windriver"
		install -d ${DEPLOY_DIR_IMAGE}/opt/windriver
		install -m 0644 ${KERNEL_OUTPUT} ${DEPLOY_DIR_IMAGE}/opt/windriver/${KERNEL_IMAGE_SYMLINK_NAME}.${MULTI_CONFIG_BASE_SUFFIX}$(basename $guest).bin
		install -m 644 ${B}/.config ${DEPLOY_DIR_IMAGE}/opt/windriver/config-${PV}-${PR}-${MACHINE}.${MULTI_CONFIG_BASE_SUFFIX}$(basename $guest).config
	done
	mv ${KERNEL_OUTPUT}.backup ${KERNEL_OUTPUT}
	KMACHINE=${ORIG_KMACHINE}
}

# add this task after the main kernel is done
addtask kernel_build_guest after do_install before do_populate_sysroot
