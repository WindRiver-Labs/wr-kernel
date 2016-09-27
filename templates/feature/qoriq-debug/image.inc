# add qoriq-debug into build
IMAGE_INSTALL += "${@base_conditional('MACHINE', 'e500mc', 'qoriq-debug', '', d)}"
IMAGE_INSTALL += "${@base_conditional('MACHINE', 'e5500-64b', 'qoriq-debug', '', d)}"
IMAGE_INSTALL += "${@base_conditional('MACHINE', 'fsl-b4xxx', 'qoriq-debug', '', d)}"
IMAGE_INSTALL += "${@base_conditional('MACHINE', 'fsl-t4xxx', 'qoriq-debug', '', d)}"
IMAGE_INSTALL += "${@base_conditional('MACHINE', 'fsl-t2xxx', 'qoriq-debug', '', d)}"
