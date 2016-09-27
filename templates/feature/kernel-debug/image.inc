# pull in predefined profile tools in oe-core
IMAGE_FEATURES += "tools-profile"

# add our necessary user land tools for profile / debug etc
IMAGE_INSTALL += "packagegroup-core-kdbg-tune"
