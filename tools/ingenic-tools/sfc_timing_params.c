#include <stdio.h>
#include <stdint.h>
#include <config.h>

#define DEV_CONF_SMP_DELAY_OFFSET       (16)
#define DEV_CONF_SMP_DELAY_MSK          (0x3 << DEV_CONF_SMP_DELAY_OFFSET)
#define DEV_CONF_THOLD_OFFSET           (11)
#define DEV_CONF_THOLD_MSK              (0x3 << DEV_CONF_THOLD_OFFSET)
#define DEV_CONF_TSETUP_OFFSET          (9)
#define DEV_CONF_TSETUP_MSK             (0x3 << DEV_CONF_TSETUP_OFFSET)
#define DEV_CONF_TSH_OFFSET             (5)
#define DEV_CONF_TSH_MSK                (0xf << DEV_CONF_TSH_OFFSET)
#define DEF_TCHSH       5
#define DEF_TSLCH       5
#define DEF_TSHSL_R     20
#define DEF_TSHSL_W     50

static void file_head_print(void)
{
	printf("/*\n");
	printf(" * DO NOT MODIFY.\n");
	printf(" *\n");
	printf(" * This file was generated by sfc_timing_params\n");
	printf(" *\n");
	printf(" */\n");
	printf("\n");

	printf("#ifndef __SFC_TIMING_VAL_H__\n");
	printf("#define __SFC_TIMING_VAL_H__\n\n");
}

static void file_end_print(void)
{
	printf("\n#endif /* __SFC_TIMING_VAL_H__ */\n");
}

int main()
{
	unsigned int c_hold;
	unsigned int c_setup;
	unsigned int t_in, c_in, val = 0;
	unsigned long cycle;
	unsigned int tmp = 0x7;
#ifdef CONFIG_MTD_SFCNAND
	unsigned int rate =  (unsigned long long)CONFIG_SFC_NAND_RATE / 1000000;
#else
	unsigned int rate =  (unsigned long long)CONFIG_SFC_NOR_RATE / 1000000;
#endif
	cycle = 1000 / rate;


	c_hold = DEF_TCHSH / cycle;
	if(c_hold > 0)
		val = c_hold - 1;
	tmp &= ~DEV_CONF_THOLD_MSK;
	tmp |= val << DEV_CONF_THOLD_OFFSET;

	c_setup = DEF_TSLCH / cycle;
	if(c_setup > 0)
		val = c_setup - 1;
	tmp &= ~DEV_CONF_TSETUP_MSK;
	tmp |= val << DEV_CONF_TSETUP_OFFSET;

	if (DEF_TSHSL_R >= DEF_TSHSL_W)
		t_in = DEF_TSHSL_R;
	else
		t_in = DEF_TSHSL_W;
	c_in = t_in / cycle;
	if(c_in > 0)
		val = c_in - 1;
	tmp &= ~DEV_CONF_TSH_MSK;
	tmp |= val << DEV_CONF_TSH_OFFSET;

	if(rate >= 100){
		val = 1;
		tmp &= ~DEV_CONF_SMP_DELAY_MSK;
		tmp |= val << DEV_CONF_SMP_DELAY_OFFSET;
	}

	file_head_print();
	printf("#define DEF_TIM_VAL 0x%08x\n", tmp);
	file_end_print();
	return 0;
}