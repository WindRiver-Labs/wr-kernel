#
# Copyright (C) 2013-14 Wind River Systems, Inc.
#

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI += "\
            file://libvirtd.sh \
           "

PACKAGECONFIG ?= "qemu yajl uml openvz vmware vbox esx \
                  lxc test remote macvtap libvirtd udev python ebtables iproute2 \
                  ${@bb.utils.contains('DISTRO_FEATURES', 'selinux', 'selinux', '', d)} \
                  ssh2 \
                 "

PACKAGECONFIG[ssh2] = "--with-ssh2,--without-ssh2,libssh2,"
