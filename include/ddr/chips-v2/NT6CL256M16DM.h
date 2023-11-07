#ifndef __LPDDR3_W63CH2MBVABE_H
#define __LPDDR3_W63CH2MBVABE_H

static inline void LPDDR3_W63CH2MBVABE_init(void *data)
{
    struct ddr_chip_info *c = (struct ddr_chip_info *)data;

    c->DDR_ROW          = 14,
    c->DDR_ROW1         = 14,
    c->DDR_COL          = 11,
    c->DDR_COL1         = 11,
    c->DDR_BL           = 8,
    c->DDR_BANK8        = 1,

  	c->DDR_RL	   	= DDR__tck(12),
	c->DDR_WL	   	= DDR__tck(6),

	c->DDR_tMRW  		= DDR_SELECT_MAX__tCK_ps(10, 14 * 1000);

    c->DDR_tDQSCK 		= DDR__ps(2500);
	c->DDR_tDQSCKMAX 	= DDR__ps(5500);
	c->DDR_tRAS  		= DDR_SELECT_MAX__tCK_ps(3, 42 * 1000);
	c->DDR_tRTP  		= DDR_SELECT_MAX__tCK_ps(4, 7500);
	c->DDR_tRP   		= DDR_SELECT_MAX__tCK_ps(3, 21 * 1000);
	c->DDR_tRCD  		= DDR_SELECT_MAX__tCK_ps(3, 18 * 1000);
	c->DDR_tRC   		= c->DDR_tRAS + c->DDR_tRP;
	c->DDR_tRRD  		= DDR_SELECT_MAX__tCK_ps(2, 10 * 1000);
	c->DDR_tWR   		= DDR_SELECT_MAX__tCK_ps(4, 15 * 1000);
	c->DDR_tWTR  		= DDR_SELECT_MAX__tCK_ps(4, 7500);
	c->DDR_tCCD  		= DDR__tck(4);
	c->DDR_tFAW  		= DDR_SELECT_MAX__tCK_ps(8, 50 * 1000);

	c->DDR_tRFC  		= DDR__ns(130);
	c->DDR_tREFI 		= DDR__ns(7800);

	c->DDR_tCKE  		= DDR_SELECT_MAX__tCK_ps(3, 7500);
	c->DDR_tCKESR 		= DDR_SELECT_MAX__tCK_ps(3, 15 * 1000);
	c->DDR_tXSR  		= DDR_SELECT_MAX__tCK_ps(2, (c->DDR_tRFC + 10 * 1000));
	c->DDR_tXP  		= DDR_SELECT_MAX__tCK_ps(3, 7500);
}

#ifndef CONFIG_LPDDR3_W63CH2MBVABE_MEM_FREQ
#define CONFIG_LPDDR3_W63CH2MBVABE_MEM_FREQ CONFIG_SYS_MEM_FREQ
#endif

#define LPDDR3_W63CH2MBVABE {						\
	.name 	= "W63CH2MBVABE",					\
	.id	= DDR_CHIP_ID(VENDOR_WINBOND, TYPE_LPDDR3, MEM_256M),	\
	.type	= LPDDR3,						\
	.size	= 256,							\
	.freq	= CONFIG_LPDDR3_W63CH2MBVABE_MEM_FREQ,			\
	.init	= LPDDR3_W63CH2MBVABE_init,				\
}


#endif
