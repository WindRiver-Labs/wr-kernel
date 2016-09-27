# For backwards compatibility since we were
# using lm-sensors for the recipe name
RPROVIDES_${PN} = "lm-sensors"
RREPLACES_${PN} = "lm-sensors"
RCONFLICTS_${PN} = "lm-sensors"

# we were using a different packaging and just add
# lm-sensors (usually added by bsp or other layer)
# to includes most of the sensors and tools,
# so the following ensure that we can keep the same
# way to includes same stuff.
ALLOW_EMPTY_${PN} = "1"
RDEPENDS_${PN} += "lmsensors-fancontrol \
                   ${@bb.utils.contains_any('TARGET_ARCH', [ 'x86_64', 'i586', 'i686' ], 'lmsensors-isatools', '', d)} \
                   lmsensors-pwmconfig \
                   lmsensors-sensord \
                   lmsensors-sensorsconfconvert \
                   lmsensors-sensorsdetect \
"
