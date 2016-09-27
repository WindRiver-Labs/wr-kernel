SUMMARY = "Random number generator daemon"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=0b6f033afe6db235e559456585dc8cdc"
DEPENDS_append_libc-uclibc = " argp-standalone"

SRC_URI = "http://heanet.dl.sourceforge.net/sourceforge/gkernel/${BP}.tar.gz \
           file://init \
           file://default"

SRC_URI[md5sum] = "6726cdc6fae1f5122463f24ae980dd68"
SRC_URI[sha256sum] = "60a102b6603bbcce2da341470cad42eeaa9564a16b4490e7867026ca11a3078e"

inherit autotools update-rc.d

PACKAGECONFIG ??= "libgcrypt"
PACKAGECONFIG[libgcrypt] = "--with-libgcrypt, --without-libgcrypt, libgcrypt"

do_install_append() {
    install -d "${D}${sysconfdir}/init.d"
    install -m 0755 ${WORKDIR}/init ${D}${sysconfdir}/init.d/rng-tools
    sed -i -e 's,/etc/,${sysconfdir}/,' -e 's,/usr/sbin/,${sbindir}/,' \
        ${D}${sysconfdir}/init.d/rng-tools

    install -d "${D}${sysconfdir}/default"
    install -m 0644 ${WORKDIR}/default ${D}${sysconfdir}/default/rng-tools
}

INITSCRIPT_NAME = "rng-tools"
INITSCRIPT_PARAMS = "defaults"
