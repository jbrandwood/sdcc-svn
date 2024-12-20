/*
   bug2686159.c
 */

#include <testfwk.h>

#ifdef __SDCC_pic16
# define ADDRESS(x) (0x02 ## x)
#elif defined(__SDCC_pic14)
# define ADDRESS(x) (0x01A0 + 0x ## x)
#elif defined(__SDCC_stm8)
# define ADDRESS(x) (0x10 ## x)
#elif defined(__SDCC_f8)
# define ADDRESS(x) (0x30 ## x)
#elif defined( __SDCC_pdk14) || defined( __SDCC_pdk15) // No RAM above 0x7f / 0xff.
# define ADDRESS(x) (0x78 + 0x ## x)
#else
# define ADDRESS(x) (0xCA ## x)
#endif

/* This produces incorrect code */
#define REG_1 (*(__xdata unsigned char*)ADDRESS(00))

// Absolute addresses should use an initial value to make sure compiler does not use these addresses.
// From manual: If you provide an initializer actual memory allocation will take place and overlaps will be detected by the linker
__xdata unsigned char  __at(ADDRESS(00)) REG_1_RES = 0;

void incorrect(void)
{
	REG_1 |= 1;
	REG_1 |= 2;
}

/* This produces correct code */
__xdata unsigned char __at(ADDRESS(01)) REG_2 = 0;

void correct(void)
{
	REG_2 |= 1;
	REG_2 |= 2;
}

void testBug(void)
{
#ifdef __SDCC
	REG_1 = 0x40;
	incorrect();
	ASSERT (REG_1 == 0x43);
#endif
	REG_2 = 0x50;
	correct();
	ASSERT (REG_2 == 0x53);
}
