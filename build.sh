#!/bin/sh -e

export ARCH=mips
export CROSS_PATH="../../resource/toolchain/gcc_720/mips-linux-gnu-ingenic-gcc7.2.0-glibc2.29-fp64/bin"
export CROSS_COMPILE="$(readlink -f $CROSS_PATH)/mips-linux-gnu-"

declare -A cfg
cfg[t41l]="isvp_t41l_sfc_nor"
cfg[t41l-nand]="isvp_t41l_sfc0_nand"
cfg[t41lq]="isvp_t41lq_sfc_nor"
cfg[t41lq-nand]="isvp_t41lq_sfc0_nand"
cfg[t41n]="isvp_t41n_sfc_nor"
cfg[t41n-nand]="isvp_t41n_sfc0_nand"
cfg[t41nq]="isvp_t41nq_sfc_nor"
cfg[t41nq-nand]="isvp_t41nq_sfc0_nand"
cfg[t41a]="isvp_t41a_sfc_nor"
cfg[t41a-nand]="isvp_t41a_sfc0_nand"
cfg[t41zx]="isvp_t41zx_sfc_nor"
cfg[t41zx-nand]="isvp_t41zx_sfc0_nand"
cfg[t41xq]="isvp_t41xq_sfc_nor"
cfg[t41xq-nand]="isvp_t41xq_sfc0_nand"

OUTPUTDIR="${HOME}/uboot"
mkdir -p ${OUTPUTDIR} 2>&1 > /dev/null

for soc in "${!cfg[@]}" ;do

make distclean
make ${cfg[$soc]}
make -j`nproc`

cp u-boot-with-spl.bin ${OUTPUTDIR}/u-boot-${soc}-universal.bin

done
