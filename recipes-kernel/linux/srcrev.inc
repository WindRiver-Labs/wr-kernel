#
# This file is generated based on the kernel-4.8.x and kernel-cache repos
# any manual changes will be overwritten.
#

OVERRIDES =. "kb-${@d.getVar('KBRANCH', True).replace("/", "-")}:"

# kernel-4.8.x branch entries
SRCREV_machine_kb-master ?= "e56c91c9785cb3bd91cae064b03299a9340b9f58"
SRCREV_machine_kb-standard-amd-x86 ?= "f6990d3afdd8868df5764bb408a2ac410f453b9a"
SRCREV_machine_kb-standard-arm-versatile-926ejs ?= "9bf2a7ce0b13b079444167a12d49372021e1ca32"
SRCREV_machine_kb-standard-axxiaarm ?= "366814ac793feaa57db3673fcfe8688d004d85e7"
SRCREV_machine_kb-standard-base ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-bcm-2xxx-rpi ?= "261adedb1e8a1b66ee259f0f148f0745259dff92"
SRCREV_machine_kb-standard-bcm-587xx ?= "3423c0184a0b3b7254473173b84bf73bf86f3d68"
SRCREV_machine_kb-standard-beaglebone ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-cav-octeontx ?= "300afeff86f7d87ecdb12b5d93c6a9c1ad0b1045"
SRCREV_machine_kb-standard-cgl-amd-x86 ?= "d1589b7b17edbd58a4b47a2e14f749aecd3b384a"
SRCREV_machine_kb-standard-cgl-axxiaarm ?= "cd84d872b3e665c8b22f5993e94e61362c3b09b2"
SRCREV_machine_kb-standard-cgl-base ?= "a0ebe27dc78a2d1efa0651b71aae420c0853a1f6"
SRCREV_machine_kb-standard-cgl-cav-octeontx ?= "75cc25efc5193e55e6a161b854be423088cecf6f"
SRCREV_machine_kb-standard-cgl-intel-socfpga ?= "5c81ca93157e0ba3d574d3d4bf184e3dfdfde681"
SRCREV_machine_kb-standard-cgl-intel-x86-32 ?= "746377ffa955e18c8f524391896795ef4c1e5d4a"
SRCREV_machine_kb-standard-cgl-intel-x86-64 ?= "f20671cd58c6b284103115e660423ae57ba2b3b1"
SRCREV_machine_kb-standard-cgl-nxp-base ?= "a7cfcb39eba527a8227fe4c0ba00afb5c9736e7a"
SRCREV_machine_kb-standard-cgl-nxp-sdk-2-0-base ?= "f6f7388730cc26180d9aca5126538fcc467e16f9"
SRCREV_machine_kb-standard-cgl-nxp-sdk-2-0-nxp-t4xxx ?= "be9a01c460b028aa569695780ebd31f0c8c84a7f"
SRCREV_machine_kb-standard-cgl-nxp-sdk-2-0-sdk-2-0-1703-base ?= "ebb30059153da951c4b8a37668283ab43d97fca4"
SRCREV_machine_kb-standard-cgl-nxp-sdk-2-0-sdk-2-0-1703-nxp-ls1012 ?= "a5bf83dc58eb4f6ac062a18b13915d75d48a10f3"
SRCREV_machine_kb-standard-cgl-nxp-sdk-2-0-sdk-2-0-1703-nxp-ls1046 ?= "c9ea3d4ccf39dee58825921e453e349d9f2a6a85"
SRCREV_machine_kb-standard-cgl-xilinx-zynq ?= "54dad7efec13a5517975b3678e81697839573507"
SRCREV_machine_kb-standard-cgl-xilinx-base ?= "8aee304bcc48879720b5a73aebd1f67019ab65cd"
SRCREV_machine_kb-standard-cgl-xilinx-sdk-2017-01-base ?= "bf9106f00b607024967eb0741173a3740587b11f"
SRCREV_machine_kb-standard-cgl-xilinx-sdk-2017-01-sdk-2017-03-base ?= "b370edf2e4bd8b0729a8f1d721d0bae89dadf567"
SRCREV_machine_kb-standard-cgl-xilinx-sdk-2017-01-sdk-2017-03-xilinx-zynqmp ?= "98f9fb6e5217e63584a745f70fd274ddf175b3e5"
SRCREV_machine_kb-standard-cgl-xilinx-sdk-2017-01-xilinx-zynq ?= "c65beeddb517f4a76b572297968e3f8bd507fb06"
SRCREV_machine_kb-standard-edgerouter ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-fsl-mpc8315e-rdb ?= "896dc21b3a78c4e42da4d9a96925a77121eff791"
SRCREV_machine_kb-standard-intel ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-intel-socfpga ?= "b6c96f6e3ecc32bdc21a66b80dd651d0187a3cd8"
SRCREV_machine_kb-standard-intel-x86-32 ?= "8b584fbe9cba834e4b20b7da0827000e173d9f8b"
SRCREV_machine_kb-standard-intel-x86-64 ?= "baa0289df66b55983376b39cc28127625024f063"
SRCREV_machine_kb-standard-mti-malta32 ?= "07e8821bf247cb2669f4f42e6d3499a48f76dd4d"
SRCREV_machine_kb-standard-mti-malta64 ?= "660a0eee607c5dbe5912e2b7fed7a37acb5c5e27"
SRCREV_machine_kb-standard-nxp-imx-base ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-nxp-imx-sdk-4.1.15-base ?= "aeeb80125d729d412b03a6476ac9524231b02e3a"
SRCREV_machine_kb-standard-nxp-imx-sdk-4.1.15-nxp-imx6 ?= "de1474a2c9cc45710d2d1e8ecf60204f6a44aa3a"
SRCREV_machine_kb-standard-nxp-base ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-nxp-sdk-2-0-base ?= "925d65ed98d158d3fc8addad9c47a72dd917a8d5"
SRCREV_machine_kb-standard-nxp-sdk-2-0-nxp-ls10xx ?= "be97fd1c907fbb379330759b5b791a3eabf1aebd"
SRCREV_machine_kb-standard-nxp-sdk-2-0-nxp-t4xxx ?= "ec7d2e8cf3081e73e5111f37300693e74fade9e2"
SRCREV_machine_kb-standard-nxp-sdk-2-0-sdk-2-0-1703-base ?= "12d0cf592074adaedf8f4415d545882a9c0dcaa7"
SRCREV_machine_kb-standard-nxp-sdk-2-0-sdk-2-0-1703-nxp-ls1012 ?= "03e3808ddf0e2a3596e4773eabafeebc87a307f2"
SRCREV_machine_kb-standard-nxp-sdk-2-0-sdk-2-0-1703-nxp-ls1046 ?= "1aae849b7b83858250c6a2efbf13269c6b770bbd"
SRCREV_machine_kb-standard-ovp-base ?= "4be24dedc7ad48927b07286040a1aeb605a85e21"
SRCREV_machine_kb-standard-ovp-intel-x86-32 ?= "e476801c20b50ad9701cf2664a7080391fa04ae4"
SRCREV_machine_kb-standard-ovp-intel-x86-64 ?= "4e0f0d70fa8479c15d069195e906607011865df9"
SRCREV_machine_kb-standard-ovp-qemux86 ?= "34879a0bf26b6f7490786e5a8d8362a91e0d1432"
SRCREV_machine_kb-standard-ovp-qemux86-64 ?= "444ead08e8b162a9b46a2bc9d8fd960f3b04d00e"
SRCREV_machine_kb-standard-ovp-x86-64-kvm-guest ?= "a7a280f128aa14eaf194aac5366436acd9a73d89"
SRCREV_machine_kb-standard-ovp-x86-kvm-guest ?= "4f54698fe163880e43681a5cb8c120d3b751dc18"
SRCREV_machine_kb-standard-preempt-rt-amd-x86 ?= "6211eaece8f3915b4f63929b874819ea70f1e4a5"
SRCREV_machine_kb-standard-preempt-rt-axxiaarm ?= "6c82d37d0ce835053e94b2e7196a80d385b2c5a8"
SRCREV_machine_kb-standard-preempt-rt-base ?= "a0281685718a5113be6591d0f23784a86709c131"
SRCREV_machine_kb-standard-preempt-rt-bcm-2xxx-rpi ?= "84483f73bae4c37cb593f057674fdb5b7d5def9f"
SRCREV_machine_kb-standard-preempt-rt-bcm-587xx ?= "92df20f9e0e139b173bf8de21faefdbae6c42e2a"
SRCREV_machine_kb-standard-preempt-rt-cav-octeontx ?= "0c641a32007e7b353b0b7f67ca02b4226f8ba6bf"
SRCREV_machine_kb-standard-preempt-rt-intel ?= "e97ca0a4096ea6460810e43c0c6c00a88084e39c"
SRCREV_machine_kb-standard-preempt-rt-intel-socfpga ?= "e6becfd03879ca69b5b246100d452bb9dba46200"
SRCREV_machine_kb-standard-preempt-rt-intel-x86-32 ?= "0f3855aa39cf38730a406245c45fe77d5d807cbc"
SRCREV_machine_kb-standard-preempt-rt-intel-x86-64 ?= "8530661d8acc066f54ca091ce009f52b5030531b"
SRCREV_machine_kb-standard-preempt-rt-nxp-imx-base ?= "f3bcd7bcbb1121e6364314b067dba48a69d7b5d2"
SRCREV_machine_kb-standard-preempt-rt-nxp-imx-sdk-4.1.15-base ?= "a7651df7774467c9d672f0816c01a009afb9a5f3"
SRCREV_machine_kb-standard-preempt-rt-nxp-imx-sdk-4.1.15-nxp-imx6 ?= "1af31dded4b1acbf8649379bc49424d6cf31874b"
SRCREV_machine_kb-standard-preempt-rt-nxp-base ?= "942f911e84e50d0ff82e7daba1cea8f59dd777d2"
SRCREV_machine_kb-standard-preempt-rt-nxp-sdk-2-0-base ?= "7e29fde483d01664aca3989a1ac0c8fad4869147"
SRCREV_machine_kb-standard-preempt-rt-nxp-sdk-2-0-nxp-ls10xx ?= "b561fc23d86607c1f2c22d742ec04e012fef640d"
SRCREV_machine_kb-standard-preempt-rt-nxp-sdk-2-0-nxp-t4xxx ?= "f2ffab1a1a1f64072cbf25167853d0d568abe9bb"
SRCREV_machine_kb-standard-preempt-rt-nxp-sdk-2-0-sdk-2-0-1703-base ?= "2f11a07a531d17dfda401f2f31627d4605155c7b"
SRCREV_machine_kb-standard-preempt-rt-nxp-sdk-2-0-sdk-2-0-1703-nxp-ls1012 ?= "a655c999f95897732929d2c84ab2baa47a13e60b"
SRCREV_machine_kb-standard-preempt-rt-nxp-sdk-2-0-sdk-2-0-1703-nxp-ls1046 ?= "7bce1e892937cfbe3ae65c05cc56f57d22931a5a"
SRCREV_machine_kb-standard-preempt-rt-rebase ?= "fc5215b02adf93360fc2288689d2d17d94cd2ed2"
SRCREV_machine_kb-standard-preempt-rt-ti-66ak2xxx ?= "71f5f437a4accc0b1eae1875869a734c4d4a8bf1"
SRCREV_machine_kb-standard-preempt-rt-ti-am335x ?= "ac3ee982c3bedbcfb1520ef19bb171e04082d401"
SRCREV_machine_kb-standard-preempt-rt-xilinx-zynq ?= "cab814d4f7f5cee692c0dc2c85206a9b55f41c81"
SRCREV_machine_kb-standard-preempt-rt-xilinx-zynqmp ?= "1beeb3a1ab0164f9f1964672b00dff3985754725"
SRCREV_machine_kb-standard-preempt-rt-xilinx-base ?= "b1e54f1ba60f5d3f2e6e3a2838b7f3d5affae709"
SRCREV_machine_kb-standard-preempt-rt-xilinx-sdk-2017-01-base ?= "3015e69980a599bf7ea6fd59a0c96986667f1b4d"
SRCREV_machine_kb-standard-preempt-rt-xilinx-sdk-2017-01-sdk-2017-03-base ?= "019957f87b995f9463c17aae5c6faf584bd41a99"
SRCREV_machine_kb-standard-preempt-rt-xilinx-sdk-2017-01-sdk-2017-03-xilinx-zynqmp ?= "305b4b4470f1ce8d3bdb5946bbb2a37baa7c82ad"
SRCREV_machine_kb-standard-preempt-rt-xilinx-sdk-2017-01-xilinx-zynq ?= "f44fbd28f568698a7a88d7760619e5a407f40d62"
SRCREV_machine_kb-standard-preempt-rt-xilinx-sdk-2017-01-xilinx-zynqmp ?= "2930138c6f86ed528cc05385ea65c2c4c9725512"
SRCREV_machine_kb-standard-qemuarm64 ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-qemuppc ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-rebase ?= "b3b4721c63e27f0e58cf448ae8ae4ac7f663526c"
SRCREV_machine_kb-standard-ti-66ak2xxx ?= "43f53c68ed2eaebb3965587e1321512deb900ed4"
SRCREV_machine_kb-standard-ti-am335x ?= "a109bbd384efafe54c37e60a9891fc1082d29242"
SRCREV_machine_kb-standard-tiny-amd-x86 ?= "7dde1be5ad9228d40f58db30e03144d650d59450"
SRCREV_machine_kb-standard-tiny-base ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-tiny-common-pc ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-tiny-intel ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-tiny-intel-x86-32 ?= "10ec3f3718a83fe7dbaf39970402b4029ad0f681"
SRCREV_machine_kb-standard-tiny-intel-x86-64 ?= "90180a20dacfcbb2786a9fe98e0db9cbc5260522"
SRCREV_machine_kb-standard-xilinx-zynq ?= "bc0a38aba091f74373d87f4daaca9946e351633b"
SRCREV_machine_kb-standard-xilinx-zynqmp ?= "4b05ffef1e5b8d541f4805b6c0e26be42aad05c3"
SRCREV_machine_kb-standard-xilinx-base ?= "b6db4bcc7bb0eee4398b53050d7541d4e91c1464"
SRCREV_machine_kb-standard-xilinx-sdk-2017-01-base ?= "2a5010a648b032ec61131e6162e5ce0d507560f5"
SRCREV_machine_kb-standard-xilinx-sdk-2017-01-sdk-2017-03-base ?= "52cea2c9b74054f72077f568734173b21f7a01f1"
SRCREV_machine_kb-standard-xilinx-sdk-2017-01-sdk-2017-03-xilinx-zynqmp ?= "b728f8b69823db66494a832aecb951aea2b8e03a"
SRCREV_machine_kb-standard-xilinx-sdk-2017-01-xilinx-zynq ?= "e524e0507717e4fe80dae64cf059068224893bf6"
SRCREV_machine_kb-standard-xilinx-sdk-2017-01-xilinx-zynqmp ?= "a4a380bfeab13e15b170e317844fbf73015b0cad"

# kernel-cache branch entry
SRCREV_meta = "60e42a9cefe926320ff142abf465f1bfc1825a8d"
