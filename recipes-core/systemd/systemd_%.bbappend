do_install_append() {
	# Enable all sysrq functions
	if ${@bb.utils.contains('DISTRO_FEATURES','systemdebug','true','false',d)}; then
		sed -i -e 's/^kernel\.sysrq *=.*/kernel\.sysrq = 1/' ${D}/${exec_prefix}/lib/sysctl.d/50-default.conf
	fi
}
