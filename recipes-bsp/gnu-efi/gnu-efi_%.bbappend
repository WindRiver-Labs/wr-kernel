FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_append = "file://disable-ms-abi.patch"

BBCLASSEXTEND = "native"
