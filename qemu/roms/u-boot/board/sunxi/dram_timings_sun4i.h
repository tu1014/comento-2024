/* This file is automatically generated, do not edit */

#if defined(CONFIG_DRAM_TIMINGS_DDR3_1066F_1333H)
# if CONFIG_DRAM_CLK <= 360 /* DDR3-1066F @360MHz, timings: 6-5-5-14 */
	.cas  = 6,
	.tpr0 = 0x268e5590,
	.tpr1 = 0xa090,
	.tpr2 = 0x22a00,
	.emr2 = 0x0,
# elif CONFIG_DRAM_CLK <= 384 /* DDR3-1066F @384MHz, timings: 6-6-6-15 */
	.cas  = 6,
	.tpr0 = 0x288f6690,
	.tpr1 = 0xa0a0,
	.tpr2 = 0x22a00,
	.emr2 = 0x0,
# elif CONFIG_DRAM_CLK <= 396 /* DDR3-1066F @396MHz, timings: 6-6-6-15 */
	.cas  = 6,
	.tpr0 = 0x2a8f6690,
	.tpr1 = 0xa0a0,
	.tpr2 = 0x22a00,
	.emr2 = 0x0,
# elif CONFIG_DRAM_CLK <= 408 /* DDR3-1066F @408MHz, timings: 7-6-6-16 */
	.cas  = 7,
	.tpr0 = 0x2ab06690,
	.tpr1 = 0xa0a8,
	.tpr2 = 0x22a00,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 432 /* DDR3-1066F @432MHz, timings: 7-6-6-17 */
	.cas  = 7,
	.tpr0 = 0x2cb16690,
	.tpr1 = 0xa0b0,
	.tpr2 = 0x22e00,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 456 /* DDR3-1066F @456MHz, timings: 7-6-6-18 */
	.cas  = 7,
	.tpr0 = 0x30b26690,
	.tpr1 = 0xa0b8,
	.tpr2 = 0x22e00,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 468 /* DDR3-1066F @468MHz, timings: 7-7-7-18 */
	.cas  = 7,
	.tpr0 = 0x30b27790,
	.tpr1 = 0xa0c0,
	.tpr2 = 0x23200,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 480 /* DDR3-1066F @480MHz, timings: 7-7-7-18 */
	.cas  = 7,
	.tpr0 = 0x32b27790,
	.tpr1 = 0xa0c0,
	.tpr2 = 0x23200,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 504 /* DDR3-1066F @504MHz, timings: 7-7-7-19 */
	.cas  = 7,
	.tpr0 = 0x34d37790,
	.tpr1 = 0xa0d0,
	.tpr2 = 0x23600,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 528 /* DDR3-1066F @528MHz, timings: 7-7-7-20 */
	.cas  = 7,
	.tpr0 = 0x36d47790,
	.tpr1 = 0xa0d8,
	.tpr2 = 0x23600,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 540 /* DDR3-1333H @540MHz, timings: 9-8-8-20 */
	.cas  = 9,
	.tpr0 = 0x36b488b4,
	.tpr1 = 0xa0c8,
	.tpr2 = 0x2b600,
	.emr2 = 0x10,
# elif CONFIG_DRAM_CLK <= 552 /* DDR3-1333H @552MHz, timings: 9-8-8-20 */
	.cas  = 9,
	.tpr0 = 0x38b488b4,
	.tpr1 = 0xa0c8,
	.tpr2 = 0x2ba00,
	.emr2 = 0x10,
# elif CONFIG_DRAM_CLK <= 576 /* DDR3-1333H @576MHz, timings: 9-8-8-21 */
	.cas  = 9,
	.tpr0 = 0x3ab588b4,
	.tpr1 = 0xa0d0,
	.tpr2 = 0x2ba00,
	.emr2 = 0x10,
# elif CONFIG_DRAM_CLK <= 600 /* DDR3-1333H @600MHz, timings: 9-9-9-22 */
	.cas  = 9,
	.tpr0 = 0x3cb699b4,
	.tpr1 = 0xa0d8,
	.tpr2 = 0x2be00,
	.emr2 = 0x10,
# elif CONFIG_DRAM_CLK <= 624 /* DDR3-1333H @624MHz, timings: 9-9-9-23 */
	.cas  = 9,
	.tpr0 = 0x3eb799b4,
	.tpr1 = 0xa0e8,
	.tpr2 = 0x2be00,
	.emr2 = 0x10,
# elif CONFIG_DRAM_CLK <= 648 /* DDR3-1333H @648MHz, timings: 9-9-9-24 */
	.cas  = 9,
	.tpr0 = 0x42b899b4,
	.tpr1 = 0xa0f0,
	.tpr2 = 0x2c200,
	.emr2 = 0x10,
# else
#   error CONFIG_DRAM_CLK is set too high
# endif
#elif defined(CONFIG_DRAM_TIMINGS_DDR3_800E_1066G_1333J)
# if CONFIG_DRAM_CLK <= 360 /* DDR3-800E @360MHz, timings: 6-6-6-14 */
	.cas  = 6,
	.tpr0 = 0x268e6690,
	.tpr1 = 0xa090,
	.tpr2 = 0x22a00,
	.emr2 = 0x0,
# elif CONFIG_DRAM_CLK <= 384 /* DDR3-800E @384MHz, timings: 6-6-6-15 */
	.cas  = 6,
	.tpr0 = 0x2a8f6690,
	.tpr1 = 0xa0a0,
	.tpr2 = 0x22a00,
	.emr2 = 0x0,
# elif CONFIG_DRAM_CLK <= 396 /* DDR3-800E @396MHz, timings: 6-6-6-15 */
	.cas  = 6,
	.tpr0 = 0x2a8f6690,
	.tpr1 = 0xa0a0,
	.tpr2 = 0x22a00,
	.emr2 = 0x0,
# elif CONFIG_DRAM_CLK <= 408 /* DDR3-1066G @408MHz, timings: 8-7-7-16 */
	.cas  = 8,
	.tpr0 = 0x2cb07790,
	.tpr1 = 0xa0a8,
	.tpr2 = 0x22a00,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 432 /* DDR3-1066G @432MHz, timings: 8-7-7-17 */
	.cas  = 8,
	.tpr0 = 0x2eb17790,
	.tpr1 = 0xa0b0,
	.tpr2 = 0x22e00,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 456 /* DDR3-1066G @456MHz, timings: 8-7-7-18 */
	.cas  = 8,
	.tpr0 = 0x30b27790,
	.tpr1 = 0xa0b8,
	.tpr2 = 0x22e00,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 468 /* DDR3-1066G @468MHz, timings: 8-8-8-18 */
	.cas  = 8,
	.tpr0 = 0x32b28890,
	.tpr1 = 0xa0c0,
	.tpr2 = 0x23200,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 480 /* DDR3-1066G @480MHz, timings: 8-8-8-18 */
	.cas  = 8,
	.tpr0 = 0x34b28890,
	.tpr1 = 0xa0c0,
	.tpr2 = 0x23200,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 504 /* DDR3-1066G @504MHz, timings: 8-8-8-19 */
	.cas  = 8,
	.tpr0 = 0x36d38890,
	.tpr1 = 0xa0d0,
	.tpr2 = 0x23600,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 528 /* DDR3-1066G @528MHz, timings: 8-8-8-20 */
	.cas  = 8,
	.tpr0 = 0x38d48890,
	.tpr1 = 0xa0d8,
	.tpr2 = 0x23600,
	.emr2 = 0x8,
# elif CONFIG_DRAM_CLK <= 540 /* DDR3-1333J @540MHz, timings: 10-9-9-20 */
	.cas  = 10,
	.tpr0 = 0x38b499b4,
	.tpr1 = 0xa0c8,
	.tpr2 = 0x2b600,
	.emr2 = 0x10,
# elif CONFIG_DRAM_CLK <= 552 /* DDR3-1333J @552MHz, timings: 10-9-9-20 */
	.cas  = 10,
	.tpr0 = 0x3ab499b4,
	.tpr1 = 0xa0c8,
	.tpr2 = 0x2ba00,
	.emr2 = 0x10,
# elif CONFIG_DRAM_CLK <= 576 /* DDR3-1333J @576MHz, timings: 10-9-9-21 */
	.cas  = 10,
	.tpr0 = 0x3cb599b4,
	.tpr1 = 0xa0d0,
	.tpr2 = 0x2ba00,
	.emr2 = 0x10,
# elif CONFIG_DRAM_CLK <= 600 /* DDR3-1333J @600MHz, timings: 10-9-9-22 */
	.cas  = 10,
	.tpr0 = 0x3eb699b4,
	.tpr1 = 0xa0d8,
	.tpr2 = 0x2be00,
	.emr2 = 0x10,
# elif CONFIG_DRAM_CLK <= 624 /* DDR3-1333J @624MHz, timings: 10-10-10-23 */
	.cas  = 10,
	.tpr0 = 0x40b7aab4,
	.tpr1 = 0xa0e8,
	.tpr2 = 0x2be00,
	.emr2 = 0x10,
# elif CONFIG_DRAM_CLK <= 648 /* DDR3-1333J @648MHz, timings: 10-10-10-24 */
	.cas  = 10,
	.tpr0 = 0x44b8aab4,
	.tpr1 = 0xa0f0,
	.tpr2 = 0x2c200,
	.emr2 = 0x10,
# else
#   error CONFIG_DRAM_CLK is set too high
# endif
#else
# error CONFIG_DRAM_TIMINGS_* is not defined
#endif