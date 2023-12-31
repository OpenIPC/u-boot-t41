#include <stdio.h>
#include "nand_common.h"

#define ATO_MID			    0xCD
#define ATO_NAND_DEVICD_COUNT	    5

static unsigned char fs_xaw[] = {0x02};

static struct device_struct device[] = {
	DEVICE_STRUCT(0xEA, 2048, 2, 4, 2, 1, fs_xaw),
	DEVICE_STRUCT(0xEB, 2048, 2, 4, 2, 1, fs_xaw),
	DEVICE_STRUCT(0x70, 2048, 2, 4, 2, 1, fs_xaw),
	DEVICE_STRUCT(0x71, 2048, 2, 4, 2, 1, fs_xaw),
	DEVICE_STRUCT(0x72, 2048, 2, 4, 2, 1, fs_xaw),
};

static struct nand_desc foresee_nand = {

	.id_manufactory = ATO_MID,
	.device_counts = ATO_NAND_DEVICD_COUNT,
	.device = device,
};

int foresee_nand_register_func(void) {
	return nand_register(&foresee_nand);
}
