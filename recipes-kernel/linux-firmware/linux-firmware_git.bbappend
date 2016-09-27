#
# Copyright (C) 2014 Wind River Systems, Inc.
#

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

FWPATH = "/lib/firmware"

do_install_append() {
	install -d ${D}${FWPATH}
	install -d ${D}${FWPATH}/bnx2x
	install -d ${D}${FWPATH}/bnx2
	install -m 0644 iwlwifi-5000-5.ucode ${D}${FWPATH}
	install -m 0644 iwlwifi-8000C-13.ucode ${D}${FWPATH}
	install -d ${D}${FWPATH}/intel
	install -m 0644 intel/ibt-hw-37.7.10-fw-1.80.2.3.d.bseq ${D}${FWPATH}/intel
	install -m 0644 intel/ibt-hw-37.8.10-fw-1.10.2.27.d.bseq ${D}${FWPATH}/intel
	install -m 0644 intel/ibt-11-5.sfi ${D}${FWPATH}/intel
	install -m 0644 bnx2x/bnx2x-e2-7.2.16.0.fw ${D}${FWPATH}/bnx2x
	install -m 0644 bnx2x/bnx2x-e2-7.8.17.0.fw ${D}${FWPATH}/bnx2x
	install -m 0644 bnx2x/bnx2x-e2-7.10.51.0.fw ${D}${FWPATH}/bnx2x
	install -m 0644 bnx2/bnx2-rv2p-09-6.0.17.fw ${D}${FWPATH}/bnx2
	install -m 0644 bnx2/bnx2-rv2p-09ax-6.0.17.fw ${D}${FWPATH}/bnx2
	install -m 0644 bnx2/bnx2-mips-09-6.2.1b.fw ${D}${FWPATH}/bnx2
	install -m 0644 bnx2/bnx2-rv2p-06-6.0.15.fw ${D}${FWPATH}/bnx2
	install -m 0644 bnx2/bnx2-mips-06-6.2.3.fw ${D}${FWPATH}/bnx2
	install -d ${D}${FWPATH}/rtl_nic
	install -m 0644 rtl_nic/rtl8168g-2.fw ${D}${FWPATH}/rtl_nic
}

PACKAGES =+ "\
	     ${PN}-iwlwifi-5000-5 \
	     ${PN}-iwlwifi-8000c-13 \
	     ${PN}-ibt-hw-37.7.10-fw-1.80.2.3.d \
	     ${PN}-ibt-hw-37.8.10-fw-1.10.2.27.d \
	     ${PN}-ibt-11-5 \
	     ${PN}-bnx2x-e2-7.2.16.0 \
	     ${PN}-bnx2x-e2-7.8.17.0 \
	     ${PN}-bnx2-rv2p-09-6.0.17 \
	     ${PN}-bnx2-rv2p-09ax-6.0.17 \
             ${PN}-bnx2x-e2-7.10.51.0 \
	     ${PN}-bnx2-mips-09-6.2.1b \
	     ${PN}-bnx2-rv2p-06-6.0.15 \
	     ${PN}-bnx2-mips-06-6.2.3 \
	     ${PN}-rtl8168g-2 \
	     ${PN}-bxt-dmc-ver1 \
	     ${PN}-skl-dmc-ver1 \
	     ${PN}-skl-guc-ver1 \
	     ${PN}-skl-guc-ver4 \
	    "

RPROVIDES_${PN}-bnx2-mips-09-6.2.1b += "${PN}-bnx2-mips"

FILES_${PN}-bxt-dmc-ver1 = " \
	${FWPATH}/i915/bxt_dmc_ver1*.bin \
"

FILES_${PN}-skl-dmc-ver1 = " \
	${FWPATH}/i915/skl_dmc_ver1*.bin \
"

FILES_${PN}-skl-guc-ver1 = " \
	${FWPATH}/i915/skl_guc_ver1*.bin \
"

FILES_${PN}-skl-guc-ver4 = " \
	${FWPATH}/i915/skl_guc_ver4*.bin \
"

RDEPENDS_${PN}-bxt-dmc-ver1 += "${PN}-i915-license"
RDEPENDS_${PN}-skl-dmc-ver1 += "${PN}-i915-license"
RDEPENDS_${PN}-skl-guc-ver1 += "${PN}-i915-license"
RDEPENDS_${PN}-skl-guc-ver4 += "${PN}-i915-license"

RDEPENDS_${PN}-iwlwifi-5000-5 = "${PN}-iwlwifi-license"
FILES_${PN}-iwlwifi-5000-5 = " \
  ${FWPATH}/iwlwifi-5000-5.ucode \
"

RDEPENDS_${PN}-iwlwifi-8000c-13 = "${PN}-iwlwifi-license"
FILES_${PN}-iwlwifi-8000c-13 = " \
  ${FWPATH}/iwlwifi-8000C-13.ucode \
"

RDEPENDS_${PN}-ibt-hw-37.7.10-fw-1.80.2.3.d = "${PN}-iwlwifi-license"
FILES_${PN}-ibt-hw-37.7.10-fw-1.80.2.3.d = " \
  ${FWPATH}/intel/ibt-hw-37.7.10-fw-1.80.2.3.d.bseq \
"

RDEPENDS_${PN}-ibt-hw-37.8.10-fw-1.10.2.27.d = "${PN}-iwlwifi-license"
FILES_${PN}-ibt-hw-37.8.10-fw-1.10.2.27.d = " \
  ${FWPATH}/intel/ibt-hw-37.8.10-fw-1.10.2.27.d.bseq \
"

RDEPENDS_${PN}-ibt-11-5 = "${PN}-iwlwifi-license"
FILES_${PN}-ibt-11-5 = " \
  ${FWPATH}/intel/ibt-11-5.sfi \
"

FILES_${PN}-bnx2x-e2-7.2.16.0 = " \
  ${FWPATH}/bnx2x/bnx2x-e2-7.2.16.0.fw \
"

FILES_${PN}-bnx2x-e2-7.8.17.0 = " \
  ${FWPATH}/bnx2x/bnx2x-e2-7.8.17.0.fw \
"

FILES_${PN}-bnx2x-e2-7.10.51.0 = " \
  ${FWPATH}/bnx2x/bnx2x-e2-7.10.51.0.fw \
"

FILES_${PN}-bnx2-rv2p-09-6.0.17 = " \
  ${FWPATH}/bnx2/bnx2-rv2p-09-6.0.17.fw \
"

FILES_${PN}-bnx2-rv2p-09ax-6.0.17 = " \
  ${FWPATH}/bnx2/bnx2-rv2p-09ax-6.0.17.fw \
"

FILES_${PN}-bnx2-mips-09-6.2.1b = " \
  ${FWPATH}/bnx2/bnx2-mips-09-6.2.1b.fw \
"

FILES_${PN}-bnx2-rv2p-06-6.0.15 = " \
  ${FWPATH}/bnx2/bnx2-rv2p-06-6.0.15.fw \
"

FILES_${PN}-bnx2-mips-06-6.2.3 = " \
  ${FWPATH}/bnx2/bnx2-mips-06-6.2.3.fw \
"

FILES_${PN}-rtl8168g-2 = " \
  ${FWPATH}/rtl_nic/rtl8168g-2.fw \
"
