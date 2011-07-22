/*************************************************************************
 *
 * MODULE NAME:    rda5870_init.c
 * PROJECT CODE:   rdabt
 * DESCRIPTION:    rda5870 initiation.
 * MAINTAINER:     mql
 * CREATION DATE:  18/12/08
 *
 * SOURCE CONTROL: $Id: rda5870_init.c 7309 2011-04-29 03:21:22Z huangjf $
 *
 * LICENSE:
 *     This source code is copyright (c) 2010-2011 rda.
 *     All rights reserved.
 *
 * NOTES TO USERS:
 *   
 *   version 3.20
 *				 
 *************************************************************************/
#ifdef __BT_RDABT__
#include "kal_release.h"      	/* Basic data type */
#include "stack_common.h"          /* message and module IDs */
#include "stack_msgs.h"            /* enum for message IDs */
#include "app_ltlcom.h"       	/* Task message communiction */
//#include "syscomp_config.h"         /* type of system module components */
//#include "task_config.h"      	/* Task creation */
#include "stacklib.h"        	   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"       	/* Event scheduler */
#include "stack_timer.h"      	/* Stack timer */
#include "stdio.h"                  /* Basic C I/O functions */
//#include "eint.h"                   /* External interrupt */

#include "uart_sw.h"               /* header file for UART */
#include "rdabt_drv.h"
#include "mmi_trace.h"


#ifdef __RDA_CHIP_R8_5870__
const unsigned short rdabt_rf_init_8[][2] = 
{
{0x3f,0x0000},//page 0
{0x0B,0x3200},// pll_cal_eachtime
{0x0E,0x5200},// rxfilter_op_cal_bit_dr rxfilter_sys_cal_bit_dr
{0x13,0x016D},// fts_cap=01, for high nak rate at high temperature°£
{0x16,0x9C23},// Load8.5pf  crystal,2.2pf cap
{0x17,0xBB12},// xtal_cpuclk_en,*
{0x19,0xEE18},// rxfilter_bp_mode rxfilter_tuning_cap_for die
{0x1A,0x59EE},// rmx_lo_reg=1011, tmx_iqswap
{0x1C,0x008F},//
{0x30,0x002B},//
{0x32,0xe540},//agc table
{0x3a,0x9e3c},
{0x39,0x9a3c},
{0x38,0x9a3c},
{0x37,0x8e3c},
{0x36,0x813c},
{0x35,0x823c},
{0x34,0x88bc},
{0x33,0x807c},
{0x3B,0x33EA},// rxfilter_imgrej_lo
{0x3E,0x0040},// tmx_lo_reg set to1
{0x3f,0x0001},//page 1
{0x02,0x0001},// rxfilter_sys_cal_polarity
{0x04,0xE41E},// ldo_ictrl<5bit> set to 1
{0x05,0xBC00},//  ldo_ictrl<5bit> set to 1
{0x06,0x259D},// 
{0x0B,0x001F},// vco_bit=111
{0x10,0x0100},// thermo power setting
{0x13,0x001C},// pre_sca=1100
{0x19,0x001C},// lo_buff=1100, improve RF per formance at high temp
{0x1a,0x1408},
{0x1E,0x3A48},// resetn_ex_selfgen_enable=0, for 32K is no need when poweron
{0x27,0x0070},// power table setting, maxpower
{0x26,0x3254},// power table setting
{0x25,0x2180},// power table setting
{0x24,0x0000},// power table setting
{0x23,0x0000},// power table setting
{0x22,0x0000},// power table setting
{0x21,0x0000},// power table setting
{0x20,0x0000},// power table setting
{0x2d,0x0077},//;for resume from 5872,sleep patch off
{0x37,0x0600},// padrv_cal_bypass
#ifdef __587x_USE_DCDC__
{0x3A,0x06E0},// dcdc setting
#else
{0x3A,0x06c0},// ldo setting
#endif
{0x3f,0x0000},//page 0
};


const kal_uint32 rdabt_pskey_rf_8[][2] =
{
{0x40240000,0x0004F39C},//enable spi2
                      
//{0x40220328,0x00000700},//4a for id packet
{0x40220334,0x00000072},//4D REF_A2_SEEK
{0x4022034C,0x00000915},//53 MIX_GUARD
{0x40220350,0x00004018},//54 TH
{0x40220354,0x00004018},//55 TH_LG
{0x40220358,0x0000AD42},//56
{0x4022035C,0x00004810},//57 AGC_TIMER
{0x402203A4,0x00004071},//69 REF_A2_DEM
                      
{0x10000080,0x00000007},//PSKEY: Total number
{0x10000084,0x00470d37},//PSKEY: GFSK ct_u
{0x10000088,0x00482a57},//PSKEY: DPSK ct_u
{0x1000008c,0x00520400},//PSKEY: Ref_ready_th
{0x10000090,0x00530915},//PSKEY: Mix_guard_th
{0x10000094,0x00437f58},//PSKEY: TX Delay
{0x10000098,0x00300029},//PSKEY: clear chip_self_cal_enable bit
{0x1000009c,0x0030002b},//PSKEY: set chip_self_cal_enable bit
                      
                      
{0x10000000,0x10000000},//pskey flag
};

const kal_uint32 rda_pskey_8[][2] =
{

#ifdef __RDA_SHARE_CRYSTAL__
{0x10000030,0x00002108},//pskey sco cfg
{0x4024001C,0x00408155},//clock req
#else
{0x10000030,0x00002008},//pskey sco cfg
#endif
{0x10000000,0x00001000},//pskey flag

{0x10000034,0xa5025010},//pskey shorter timing sleep
{0x10000038,0x0F055000},//pskey rf delay
{0x1000003C,0xA0A0BF40},//pskey rf timing

{0x10000000,0x0000e000},//pskey flag
{0x1000405c,0x788dffff},//disable edr

{0x40200004,0x0000077c},//set gpio to function
{0x40200000,0x78000aaf},//enable bt cts
                      
{0x40240000,0x0000F298},//disable spi2
};


#ifdef _RDA_PATCH_UART_
const kal_uint32 rda_patch_8[][62] = 
{
{0x100037c4,0xe92d40f8,0xe1a06000,0xe3500001,0x13560000,0xe1a04001,0x1a000094,0xe59f7308,0xe3560001,0x1a00000c,0xe5940000,0xe5d01003,0xe5d02004,0xe1815402,0xe245ccfc,0xe25cc042,0x03a01004,0x05c01006,0xe245ccfc,0xe25cc056,0x05940000,0x0b0000f8,0xea000031,0xe3560000,0x1a00002f,0xe5940000,0xe5d01000,0xe5d02001,0xe1815402,0xe245ccfc,0xe25cc0c4,0x1a000023,0xe5d01004,0xe3510010,0x91a00001,0x9a000010,0xe3a00000,0xe5942000,0xe0813000,0xe0822003,0xe5522008,0xe0873000,0xe2800001,0xe3500010,0xe5c32001,0x3afffff6,0xea000012,0xe0872000,0xe5d22001,0xe0403001,0xe0833007,0xe5c32001,0xe2800001,0xe3500010,0x3afffff7,0xe2610010,0xe3500010,0x2a000007,0xe5942000,0xe0813000,0xe0822003,0xe5522008},
{0x100038b8,0xe0873000,0xe2800001,0xe5c32001,0xeafffff5,0xe3a00001,0xe5c70000,0xe245cec0,0xe25cc003,0x05d70000,0x03500001,0x0b0000fe,0xe5d70000,0xe3500002,0x1a00003c,0xe5940000,0xe5d72011,0xe5d01000,0xe3560000,0xe0211002,0xe5c01000,0x1a00000b,0xe5940000,0xe5d72012,0xe5f01001,0xe0211002,0xe5c01000,0xe1a00004,0xeb000072,0xe5940000,0xe5d01000,0xe5d00001,0xe1815400,0xea00002b,0xe5d70011,0xe5cd0000,0xe5d70012,0xe5cd0001,0xe5d70013,0xe5cd0002,0xe5d70014,0xe5cd0003,0xe3a00002,0xea00001c,0xe2401001,0xe2111003,0x1a000013,0xe5dd2000,0xe5dd3000,0xe1a021a2,0xe1822283,0xe5cd2000,0xe5dd2001,0xe5dd3001,0xe1a021a2,0xe1822283,0xe5cd2001,0xe5dd2002,0xe5dd3002,0xe1a021a2,0xe1822283,0xe5cd2002},
{0x100039ac,0xe5dd2003,0xe5dd3003,0xe1a021a2,0xe1822283,0xe5cd2003,0xe5942000,0xe7dd1001,0xe7f23000,0xe2800001,0xe0231001,0xe5c21000,0xe1d410bc,0xe1510000,0x8affffdf,0xe3560000,0x1a000011,0xe5d70000,0xe3500002,0x0245ccfc,0x025cc056,0x1a00000b,0xe5940000,0xe5d00003,0xe5c7001d,0xe5940000,0xe5d00004,0xe5c7001e,0xe5940000,0xe5d00005,0xe5c7001f,0xe5940000,0xe5d00006,0xe5c70020,0xe8bd80f8,0xe3560001,0x1afffffc,0xe5d70000,0xe3500002,0x1a00001f,0xe245ccfc,0xe25cc0df,0x1afffff6,0xe59fc094,0xe3a00000,0xe0871000,0xe5d13019,0xe1a02183,0xe18222a3,0xe7dc3000,0xe0822003,0xe20220ff,0xe1a03222,0xe1832202,0xe5d1301d,0xe20220ff,0xe0222003,0xe1a031a2,0xe1832282,0xe5d13011,0xe0822003,0xe20220ff},
{0x10003aa0,0xe1a03122,0xe1832302,0xe7cd2000,0xe2800001,0xe3500004,0xe5c12011,0x3affffe7,0xeb00003a,0xe3560001,0x1affffd9,0xe5d70000,0xe3500001,0x0245cec0,0x025cc003,0x03a00002,0x05c70000,0x08bd40f8,0x0a000030,0xeaffffd0,0x10003d4c,0x10004038,0xe59f10ac,0xe92d4008,0xe5d12011,0xe5cd2000,0xe5d12012,0xe5cd2001,0xe5d12013,0xe5cd2002,0xe5d11014,0xe5cd1003,0xe3a01003,0xea00001c,0xe2412001,0xe2122003,0x1a000013,0xe5dd3000,0xe5ddc000,0xe1a032a3,0xe183318c,0xe5cd3000,0xe5dd3001,0xe5ddc001,0xe1a032a3,0xe183318c,0xe5cd3001,0xe5dd3002,0xe5ddc002,0xe1a032a3,0xe183318c,0xe5cd3002,0xe5dd3003,0xe5ddc003,0xe1a032a3,0xe183318c,0xe5cd3003,0xe5903000,0xe7dd2002,0xe7f3c001,0xe2811001,0xe02c2002},
{0x10003b94,0xe5c32000,0xe1d020bc,0xe1520001,0x8affffdf,0xe8bd8008,0x10003d4c,0xe59f2040,0xe59f1040,0xe5d20011,0xe220300e,0xe5c13001,0xe5d23012,0xe2233001,0xe5c13003,0xe5d23013,0xe22330c1,0xe5c13004,0xe5d22014,0xe22220fc,0xe5c12005,0xe1a021a0,0xe1820280,0xe5c10006,0xe1a0f00e,0x10003d4c,0x10007840,0xe92d4018,0xe3a01470,0xe591101c,0xe59fe0c8,0xe1a02421,0xe5ce1019,0xe5ce201a,0xe1a02821,0xe5ce201b,0xe1a01c21,0xe5ce101c,0xe59f40ac,0xe3a01000,0xe08e2001,0xe5d2301d,0xe1a0c323,0xe18c3103,0xe5d2c011,0xe20330ff,0xe5d22019,0xe023300c,0xe1a0c2a3,0xe18c3183,0xe0832002,0xe20220ff,0xe1a03222,0xe1832202,0xe7d43001,0xe20220ff,0xe0222003,0xe1a031a2,0xe1832282,0xe7cd2001,0xe2811001,0xe3510004},
{0x10003c88,0x3affffe8,0xe3a01000,0xe5c01005,0xe5dd1000,0xe5c01006,0xe5dd1001,0xe5c01007,0xe5dd1002,0xe5c01008,0xe5dd1003,0xe5c01009,0xe5de1019,0xe5c0100a,0xe5de101a,0xe5c0100b,0xe5de101b,0xe5c0100c,0xe5de101c,0xe5c0100d,0xe8bd8018,0x10003d4c,0x10004038,0xe59fc060,0xe3a01000,0xe08c0001,0xe5d02001,0xe2811001,0xe3510004,0xe1a03222,0xe1832202,0xe5d03005,0xe0822003,0xe20220ff,0xe1a032a2,0xe1832182,0xe5d03009,0xe20220ff,0xe0222003,0xe1a03122,0xe1832302,0xe5d0300d,0xe20220ff,0xe0222003,0xe1a032a2,0xe1832182,0xe5c02011,0x3affffe8,0xe1a0f00e,0x10003d4c,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
};

#endif


#ifdef _RDA_PATCH_UART2_
const kal_uint8 rda_patch_8[][62] = 
{
{0x100037c4,0xe92d40f8,0xe1a06000,0xe3500001,0x13560000,0xe1a04001,0x1a000080,0xe59f72ec,0xe3560001,0x1a00001d,0xe5940000,0xe5d01003,0xe5d02004,0xe1815402,0xe245ccfc,0xe25cc042,0x03a01004,0x05c01006,0xe245ccfc,0xe25cc056,0x1a000002,0xe5940000,0xeb00011c,0xea000043,0xe245ccfc,0xe25cc05b,0x1a000040,0xe5941000,0xe3a000ab,0xe5c10006,0xe5941000,0xe3a00096,0xe5c10007,0xe5941000,0xe3a0000c,0xe5c10008,0xe5941000,0xe3a000c8,0xe5c10009,0xea000033,0xe3560000,0x1a000031,0xe5940000,0xe5d01000,0xe5d02001,0xe1815402,0xe245ccfc,0xe25cc0c4,0x1a000023,0xe5d01004,0xe3510010,0x91a00001,0x9a000010,0xe3a00000,0xe5942000,0xe0813000,0xe0822003,0xe5522008,0xe0873000,0xe2800001,0xe3500010,0xe5c32001},
{0x100038b8,0x3afffff6,0xea000012,0xe0872000,0xe5d22001,0xe0403001,0xe0833007,0xe5c32001,0xe2800001,0xe3500010,0x3afffff7,0xe2610010,0xe3500010,0x2a000007,0xe5942000,0xe0813000,0xe0822003,0xe5522008,0xe0873000,0xe2800001,0xe5c32001,0xeafffff5,0xe3a00001,0xe5c70000,0xe245cec0,0xe25cc003,0x05d70000,0x03500001,0x1a000001,0xeb000167,0xeb000142,0xe5d70000,0xe3500002,0x1a000015,0xe3560000,0x1a000010,0xe5940000,0xe5d72011,0xe5d01000,0xe0211002,0xe5c01000,0xe5940000,0xe5d72012,0xe5f01001,0xe0211002,0xe5c01000,0xe1a00004,0xeb000058,0xe5940000,0xe5d01000,0xe5d00001,0xe1815400,0xea000004,0xe1a00004,0xeb00007f,0xea000013,0xe3560000,0x1a000011,0xe5d70000,0xe3500002,0x0245ccfc,0x025cc056},
{0x100039ac,0x1a00000b,0xe5940000,0xe5d00003,0xe5c7001d,0xe5940000,0xe5d00004,0xe5c7001e,0xe5940000,0xe5d00005,0xe5c7001f,0xe5940000,0xe5d00006,0xe5c70020,0xe8bd80f8,0xe3560001,0x1afffffc,0xe5d70000,0xe3500002,0x1a00002c,0xe245ccfc,0xe25cc0df,0x1afffff6,0xe5d70011,0xe59fc0c4,0xe28000e4,0xe5cd0000,0xe5d70012,0xe28000d2,0xe5cd0001,0xe5d70013,0xe2800056,0xe5cd0002,0xe5d70014,0xe2800013,0xe5cd0003,0xe3a00000,0xe7dd1000,0xe1a023a1,0xe1821081,0xe20120ff,0xe0871000,0xe5d1301d,0xe0222003,0xe1a031a2,0xe1832282,0xe7dc3000,0xe20220ff,0xe0222003,0xe1a03322,0xe1832102,0xe5d13019,0xe0822003,0xe20220ff,0xe1a03222,0xe1832202,0xe7cd2000,0xe2800001,0xe3500004,0xe5c12011,0x3affffe7,0xeb0000e6},
{0x10003aa0,0xeb0000b3,0xe3560001,0x1affffcc,0xe5d70000,0xe3500001,0x0245cec0,0x025cc003,0x03a00002,0x05c70000,0x08bd40f8,0x0a0000a9,0xeaffffc3,0x10003f38,0x10004038,0xe59f10ac,0xe92d4008,0xe5d12011,0xe5cd2000,0xe5d12012,0xe5cd2001,0xe5d12013,0xe5cd2002,0xe5d11014,0xe5cd1003,0xe3a01003,0xea00001c,0xe2412001,0xe2122003,0x1a000013,0xe5dd3000,0xe5ddc000,0xe1a032a3,0xe183318c,0xe5cd3000,0xe5dd3001,0xe5ddc001,0xe1a032a3,0xe183318c,0xe5cd3001,0xe5dd3002,0xe5ddc002,0xe1a032a3,0xe183318c,0xe5cd3002,0xe5dd3003,0xe5ddc003,0xe1a032a3,0xe183318c,0xe5cd3003,0xe5903000,0xe7dd2002,0xe7f3c001,0xe2811001,0xe02c2002,0xe5c32000,0xe1d020bc,0xe1520001,0x8affffdf,0xe8bd8008,0x10003f38,0xe92d400c},
{0x10003b94,0xe5901000,0xe59f20ec,0xe5d13000,0xe5d2c015,0xe023300c,0xe5c13000,0xe5d21015,0xe5cd1004,0xe5d21016,0xe5cd1005,0xe5d21017,0xe5cd1006,0xe5d21018,0xe5cd1007,0xe3a01002,0xea000029,0xe2412002,0xe2122003,0x1a00001f,0xe5dd3004,0xe223309d,0xe5cd3000,0xe5dd3005,0xe2233071,0xe5cd3001,0xe5dd3006,0xe2233042,0xe5cd3002,0xe5dd3007,0xe22330d2,0xe5cd3003,0xe5dd3002,0xe5ddc001,0xe1a03183,0xe18332ac,0xe5cd3004,0xe5dd3003,0xe5ddc002,0xe1a03183,0xe18332ac,0xe5cd3005,0xe5dd3000,0xe5ddc003,0xe1a03183,0xe18332ac,0xe5cd3006,0xe5dd3001,0xe5ddc000,0xe1a03183,0xe18332ac,0xe5cd3007,0xe5903000,0xe28de004,0xe7de2002,0xe7f3c001,0xe2811001,0xe02c2002,0xe5c32000,0xe1d020bc,0xe1520001,0x8affffd2},
{0x10003c88,0xe8bd800c,0x10003f38,0xe92d4018,0xe3a01470,0xe591101c,0xe59fe0c8,0xe1a02421,0xe5ce1019,0xe5ce201a,0xe1a02821,0xe5ce201b,0xe1a01c21,0xe5ce101c,0xe59f40ac,0xe3a01000,0xe08e2001,0xe5d2301d,0xe1a0c323,0xe18c3103,0xe5d2c011,0xe20330ff,0xe5d22019,0xe023300c,0xe1a0c2a3,0xe18c3183,0xe0832002,0xe20220ff,0xe1a03222,0xe1832202,0xe7d43001,0xe20220ff,0xe0222003,0xe1a031a2,0xe1832282,0xe7cd2001,0xe2811001,0xe3510004,0x3affffe8,0xe3a01000,0xe5c01005,0xe5dd1000,0xe5c01006,0xe5dd1001,0xe5c01007,0xe5dd1002,0xe5c01008,0xe5dd1003,0xe5c01009,0xe5de1019,0xe5c0100a,0xe5de101a,0xe5c0100b,0xe5de101b,0xe5c0100c,0xe5de101c,0xe5c0100d,0xe8bd8018,0x10003f38,0x10004038,0xe59f00b8,0xe92d400c},
{0x10003d7c,0xe5d01015,0xe221209d,0xe5cd2004,0xe5d02016,0xe221100e,0xe2222071,0xe5cd2005,0xe5d02017,0xe2222042,0xe5cd2006,0xe5d00018,0xe22000d2,0xe5cd0007,0xe1a00182,0xe5dd2005,0xe18002a2,0xe5cd0000,0xe5dd0007,0xe5dd2006,0xe1a00180,0xe18002a2,0xe5cd0001,0xe5dd0004,0xe5dd2007,0xe1a00180,0xe18002a2,0xe5cd0002,0xe5dd0005,0xe5dd2004,0xe1a00180,0xe18002a2,0xe5cd0003,0xe59f0034,0xe5c01001,0xe5dd1000,0xe2211001,0xe5c01003,0xe5dd1001,0xe22110c1,0xe5c01004,0xe5dd1002,0xe22110fc,0xe5c01005,0xe5dd1003,0xe5c01006,0xe8bd800c,0x10003f38,0x10007840,0xe59f0084,0xe92d4008,0xe5d01011,0xe2211023,0xe5cd1000,0xe5d01012,0xe22110a6,0xe5cd1001,0xe5d01013,0xe221109d,0xe5cd1002,0xe5d01014,0xe2211025},
{0x10003e70,0xe5cd1003,0xe5dd1002,0xe5dd2001,0xe1a01081,0xe18113a2,0xe5c01015,0xe5dd1002,0xe5dd2003,0xe1a013a1,0xe1811082,0xe5c01016,0xe5dd1000,0xe5dd2003,0xe1a01081,0xe18113a2,0xe5c01017,0xe5dd1000,0xe5dd2001,0xe1a013a1,0xe1811082,0xe5c01018,0xe8bd8008,0x10003f38,0xe59fc060,0xe3a01000,0xe08c0001,0xe5d02001,0xe2811001,0xe3510004,0xe1a03222,0xe1832202,0xe5d03005,0xe0822003,0xe20220ff,0xe1a032a2,0xe1832182,0xe5d03009,0xe20220ff,0xe0222003,0xe1a03122,0xe1832302,0xe5d0300d,0xe20220ff,0xe0222003,0xe1a032a2,0xe1832182,0xe5c02011,0x3affffe8,0xe1a0f00e,0x10003f38,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},
};

#endif


#ifdef _RDA_PATCH_UART3_

const kal_uint32 rda_patch_8[][62]= 
{
{0x10004A74,0xE51FF004,0x0001C3EC,0xE51FF004,0x000238A0,0xE92D47FC,0xE1A06000,0xE3500001,0x13560000,0xE1A04001,0x1A000101,0xE3A08001,0xE3A09002,0xE59F7414,0xE3560001,0x1A00004E,0xE5940000,0xE3A0A000,0xE5D01003,0xE5D02004,0xE1815402,0xE245CCFC,0xE25CC056,0x1A000001,0xEB000198,0xEA000013,0xE245CD40,0xE25CC001,0x1A000010,0xE3A01005,0xE5C01006,0xE5940000,0xE5C0A007,0xE5940000,0xE5C0A008,0xE5940000,0xE5C01009,0xE5941000,0xE3A00046,0xE5C1000A,0xE5940000,0xE5C0A00B,0xE5940000,0xE5C0A00C,0xE5940000,0xE5C0A00D,0xE5940000,0xE5D01004,0xE5D00005,0xE1810400,0xE240CCFC,0xE25CC077,0x03A03001,0x03A02000,0x059F1374,0x03A00010,0x0BFFFFC7,0xE245CCFC,0xE25CC0D1,0x1A000009,0xE5940000,0xE5C08006},
{0x10004B68,0xE5941000,0xE3A0008A,0xE5C10007,0xE5940000,0xE5C0A008,0xE5940000,0xE5C0A009,0xEA00005F,0xE245CCFC,0xE25CC05B,0x1A00000C,0xE5941000,0xE3A000BB,0xE5C10006,0xE5941000,0xE3A000BC,0xE5C10007,0xE5941000,0xE3A0007B,0xE5C10008,0xE5941000,0xE3A000C9,0xE5C10009,0xEA00004F,0xE245CEC0,0xE25CC003,0x03A00F40,0x03A01450,0x05810010,0x059F12E4,0x03E00000,0x05810000,0xEA000046,0xE3560000,0x1A000044,0xE5940000,0xE5D01000,0xE5D02001,0xE1815402,0xE245CCFC,0xE25CC0C4,0x1A000022,0xE5D01004,0xE3510010,0x91A00001,0x9A000010,0xE3A00000,0xE5942000,0xE0813000,0xE0822003,0xE5522008,0xE0873000,0xE2800001,0xE3500010,0xE5C32001,0x3AFFFFF6,0xEA000012,0xE0872000,0xE5D22001,0xE0403001,0xE0833007},
{0x10004C5C,0xE5C32001,0xE2800001,0xE3500010,0x3AFFFFF7,0xE2610010,0xE3500010,0x35942000,0x30813000,0x30822003,0x35522008,0x30873000,0x32800001,0x35C32001,0x3AFFFFF6,0xE1A00000,0xE5C78000,0xE245CCF0,0xE25CCECD,0xE59F0220,0x1A000004,0xE5941000,0xE5D11007,0xE3510077,0x05808000,0xEA000011,0xE245CCFC,0xE25CC077,0x1A000007,0xE5901000,0xE3510001,0x1A00000B,0xE5941000,0xE5D11004,0xE3110080,0x15809000,0xEA000006,0xE245CEC0,0xE25CC003,0x05D70000,0x03500001,0x1A000001,0xEB00019E,0xEB000176,0xE5D70000,0xE3500002,0x1A000015,0xE3560000,0x1A000010,0xE5940000,0xE5D72011,0xE5D01000,0xE0211002,0xE5C01000,0xE5940000,0xE5D72012,0xE5F01001,0xE0211002,0xE5C01000,0xE1A00004,0xEB000087,0xE5940000},
{0x10004D50,0xE5D01000,0xE5D00001,0xE1815400,0xEA000004,0xE1A00004,0xEB0000AE,0xEA000013,0xE3560000,0x1A000011,0xE5D70000,0xE3500002,0x0245CCFC,0x025CC056,0x1A000046,0xE5940000,0xE5D00003,0xE5C7001D,0xE5940000,0xE5D00004,0xE5C7001E,0xE5940000,0xE5D00005,0xE5C7001F,0xE5940000,0xE5D00006,0xE5C70020,0xEA000039,0xE3560001,0x1A000037,0xE5D70000,0xE3500002,0x1A00002E,0xE245CCFC,0xE25CC0DF,0x1A000031,0xE5D70011,0xE59FC0E8,0xE28000E4,0xE5CD0004,0xE5D70012,0xE28000D2,0xE5CD0005,0xE5D70013,0xE2800056,0xE5CD0006,0xE5D70014,0xE2800013,0xE5CD0007,0xE3A00000,0xE28D1004,0xE7D11000,0xE1A023A1,0xE1821081,0xE20120FF,0xE0871000,0xE5D1301D,0xE0222003,0xE1A031A2,0xE1832282,0xE7DC3000,0xE20220FF},
{0x10004E44,0xE0222003,0xE1A03322,0xE1832102,0xE5D13019,0xE0822003,0xE20220FF,0xE1A03222,0xE1832202,0xE28D3004,0xE7C32000,0xE2800001,0xE3500004,0xE5C12011,0x3AFFFFE5,0xEB000118,0xEB0000E5,0xE3560001,0x1A000005,0xE5D70000,0xE3500001,0x0245CEC0,0x025CC003,0x05C79000,0x0B0000DD,0xE1A00000,0xE1A00000,0xE1A00000,0xE1A00000,0xE1A00000,0xE1A00000,0xE8BD87FC,0x10000060,0x10004ED4,0x10004258,0x10000054,0x10004038,0xE52DE004,0xE24DD024,0xE3A01000,0xE3A00450,0xE5801004,0xE590200C,0xE3822F60,0xE580200C,0xE3A03001,0xE5803000,0xE5801004,0xE5801028,0xE580104C,0xE590200C,0xE3C22080,0xE580200C,0xE3A02003,0xE5802008,0xE5803004,0xE59F0034,0xE5CD1000,0xE1C010B0,0xE59F102C,0xE5910000,0xE3500002},          
{0x10004F38,0x05812000,0xE1A0100D,0xE59F001C,0xEBFFFECC,0xE1A0100D,0xE59F0014,0xEBFFFEC9,0xE28DD024,0xE49DF004,0x10006948,0x10000054,0x0000FCC0,0x0000FC77,0xE59F10AC,0xE92D4008,0xE5D12011,0xE5CD2000,0xE5D12012,0xE5CD2001,0xE5D12013,0xE5CD2002,0xE5D11014,0xE5CD1003,0xE3A01003,0xEA00001C,0xE2412001,0xE2122003,0x1A000013,0xE5DD3000,0xE5DDC000,0xE1A032A3,0xE183318C,0xE5CD3000,0xE5DD3001,0xE5DDC001,0xE1A032A3,0xE183318C,0xE5CD3001,0xE5DD3002,0xE5DDC002,0xE1A032A3,0xE183318C,0xE5CD3002,0xE5DD3003,0xE5DDC003,0xE1A032A3,0xE183318C,0xE5CD3003,0xE5903000,0xE7DD2002,0xE7F3C001,0xE2811001,0xE02C2002,0xE5C32000,0xE1D020BC,0xE1520001,0x8AFFFFDF,0xE8BD8008,0x10000060,0xE92D400C,0xE5901000},
{0x1000502C,0xE59F2100,0xE5D13000,0xE5D2C015,0xE023300C,0xE5C13000,0xE5D21015,0xE5CD1004,0xE5D21016,0xE5CD1005,0xE5D21017,0xE5CD1006,0xE5D21018,0xE5CD1007,0xE3A01002,0xEA00002E,0xE2412002,0xE2122003,0x1A000024,0xE5DD3004,0xE223309D,0xE5CD3000,0xE5DD3005,0xE2233071,0xE5CD3001,0xE5DD3006,0xE2233042,0xE5CD3002,0xE5DD3007,0xE22330D2,0xE5CD3003,0xE5DD3002,0xE5DDC001,0xE1A03183,0xE18332AC,0xE5CD3004,0xE5DD3003,0xE5DDC002,0xE1A03183,0xE18332AC,0xE5CD3005,0xE1A00000,0xE1A00000,0xE1A00000,0xE1A00000,0xE1A00000,0xE5DD3000,0xE5DDC003,0xE1A03183,0xE18332AC,0xE5CD3006,0xE5DD3001,0xE5DDC000,0xE1A03183,0xE18332AC,0xE5CD3007,0xE5903000,0xE28DE004,0xE7DE2002,0xE7F3C001,0xE2811001,0xE02C2002},          
{0x10005120,0xE5C32000,0xE1D020BC,0xE1520001,0x8AFFFFCD,0xE8BD800C,0x10000060,0xE92D4018,0xE3A01470,0xE591101C,0xE59FE0C8,0xE1A02421,0xE5CE1019,0xE5CE201A,0xE1A02821,0xE5CE201B,0xE1A01C21,0xE5CE101C,0xE59F40AC,0xE3A01000,0xE08E2001,0xE5D2301D,0xE1A0C323,0xE18C3103,0xE5D2C011,0xE20330FF,0xE5D22019,0xE023300C,0xE1A0C2A3,0xE18C3183,0xE0832002,0xE20220FF,0xE1A03222,0xE1832202,0xE7D43001,0xE20220FF,0xE0222003,0xE1A031A2,0xE1832282,0xE7CD2001,0xE2811001,0xE3510004,0x3AFFFFE8,0xE3A01000,0xE5C01005,0xE5DD1000,0xE5C01006,0xE5DD1001,0xE5C01007,0xE5DD1002,0xE5C01008,0xE5DD1003,0xE5C01009,0xE5DE1019,0xE5C0100A,0xE5DE101A,0xE5C0100B,0xE5DE101B,0xE5C0100C,0xE5DE101C,0xE5C0100D,0xE8BD8018},          
{0x10005214,0x10000060,0x10004038,0xE59F00B8,0xE92D400C,0xE5D01015,0xE221209D,0xE5CD2004,0xE5D02016,0xE221100E,0xE2222071,0xE5CD2005,0xE5D02017,0xE2222042,0xE5CD2006,0xE5D00018,0xE22000D2,0xE5CD0007,0xE1A00182,0xE5DD2005,0xE18002A2,0xE5CD0000,0xE5DD0007,0xE5DD2006,0xE1A00180,0xE18002A2,0xE5CD0001,0xE5DD0004,0xE5DD2007,0xE1A00180,0xE18002A2,0xE5CD0002,0xE5DD0005,0xE5DD2004,0xE1A00180,0xE18002A2,0xE5CD0003,0xE59F0034,0xE5C01001,0xE5DD1000,0xE2211001,0xE5C01003,0xE5DD1001,0xE22110C1,0xE5C01004,0xE5DD1002,0xE22110FC,0xE5C01005,0xE5DD1003,0xE5C01006,0xE8BD800C,0x10000060,0x10007840,0xE59F0090,0xE92D4008,0xE5D01011,0xE2211023,0xE5CD1000,0xE1A00000,0xE1A00000,0xE1A00000,0xE5D01012},          
{0x10005308,0xE22110A6,0xE5CD1001,0xE5D01013,0xE221109D,0xE5CD1002,0xE5D01014,0xE2211025,0xE5CD1003,0xE5DD1002,0xE5DD2001,0xE1A01081,0xE18113A2,0xE5C01015,0xE5DD1002,0xE5DD2003,0xE1A013A1,0xE1811082,0xE5C01016,0xE5DD1000,0xE5DD2003,0xE1A01081,0xE18113A2,0xE5C01017,0xE5DD1000,0xE5DD2001,0xE1A013A1,0xE1811082,0xE5C01018,0xE8BD8008,0x10000060,0xE59FC060,0xE3A01000,0xE08C0001,0xE5D02001,0xE2811001,0xE3510004,0xE1A03222,0xE1832202,0xE5D03005,0xE0822003,0xE20220FF,0xE1A032A2,0xE1832182,0xE5D03009,0xE20220FF,0xE0222003,0xE1A03122,0xE1832302,0xE5D0300D,0xE20220FF,0xE0222003,0xE1A032A2,0xE1832182,0xE5C02011,0x3AFFFFE8,0xE1A0F00E,0x10000060,0x00000000,0x00000000,0x00000000,0x00000000},          
{0x100053FC,0x00000000,0x00000000,0x00000000,0x00000000,0xE245FC14,0xE3A00000,0xEA00000C,0xE5DE3000,0xE59F1044,0xE5911000,0xE3510003,0x03530077,0x05DE3000,0x022330FF,0xE59C100C,0xE5C13000,0xE2811001,0xE2800001,0xE3C00B40,0xE58C100C,0xE59E1014,0xE2011001,0xE3510000,0x11500002,0x3AFFFFED,0xE3A01C33,0xE281F018,0x10000054,0x00000000,0xE289F201,0xE59F1044,0xE5912000,0xEA00000C,0xE5D51000,0xE3520003,0x15C81000,0x1A000006,0xE3510077,0x13510011,0x13510013,0x03A00077,0x05C80000,0x022110FF,0xE5C81000,0xE2855001,0xE2444001,0xE3540000,0x1AFFFFF0,0xE3A0FC35,0x10000054,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000},          
{0x10000350,0xE59F30D4,0xE59FC0D4,0xE3A0E089,0xE3A00000,0xE3A02000,0xE001009E,0xE08C1101,0xE5C12000,0xE7832100,0xE2800001,0xE3500009,0xBAFFFFF8,0xE59F10AC,0xE3A00002,0xE1C100B6,0xE1C100B4,0xE59F00A0,0xE59FC0A4,0xE2803018,0xE581300C,0xE59F1094,0xE280E030,0xE2813D40,0xE5801018,0xE580202C,0xE2833EDA,0xE5803000,0xE59F3080,0xE3A02008,0xE1C3C0B0,0xE1C320B6,0xE1C320B4,0xE583E008,0xE2803094,0xE580305C,0xE5903090,0xE5803030,0xE2833E40,0xE5803048,0xE5903124,0xE2833E40,0xE58030AC,0xE2813D7D,0xE2811F68,0xE58010DC,0xE59F103C,0xE58010F4,0xE2811E40,0xE2811038,0xE5A030C4,0xE5801048,0xE59F0028,0xE1C028B8,0xE1C0C8B4,0xE8BD83F8,0x10005748,0x10004404,0x10003484,0x100034AC,0x100004A4,0x000003FD},          

};








#endif

const kal_uint32 rda_bigpatch_8[][62]=
{
{0x10005528,0xE51FF004,0x000081D0,0xE51FF004,0x00007368,0xE51FF004,0x00013120,0xE51FF004,0x00005568,0xE92D41FC,0xE1A07000,0xE1A00001,0xE59F11A0,0xE3570002,0xE0812287,0x03A01000,0x11A01280,0xE0825001,0xE5954010,0xEBFFFFEC,0xE1A06000,0xE3A08000,0xE3570002,0x1A00002C,0xE5940000,0xE3A02017,0xE5D01000,0xE15200A1,0x1A000010,0xE5D01004,0xE5D00005,0xE0810400,0xE3500FC8,0x2A00002F,0xE3A0201E,0xE3A01017,0xE1A00006,0xEBFFFFDC,0xE3A03001,0xE58D3000,0xE3A03004,0xE3A02FC8,0xE3A01FC8,0xE1A00006,0xEBFFFFD7,0xEA000008,0xE3A0200F,0xE15200A1,0x05D00001,0x03500000,0x1A00001E,0xE3A0201A,0xE3A0100F,0xE1A00006,0xEBFFFFCB,0xE5D5001E,0xE3500000,0x05D5001F,0xE2400001,0xE5C5001E,0xE1D500B2,0xE1D410BC},          
{0x1000561C,0xE0400001,0xE1C500B2,0xE1D501BA,0xE2400001,0xE1C501BA,0xE5848000,0xEA00000C,0xE3570003,0x1A00000A,0xE3A00F7D,0xEBFFFFBD,0xE5940000,0xE3A02008,0xE5D01000,0xE15200A1,0x05D61013,0x03811010,0x05C01000,0x05D60013,0x05C6003E,0xE59F008C,0xE5902000,0xE3520000,0x11A01004,0x11A00007,0x11A0E00F,0x11A0F002,0xE3570000,0x1A000019,0xE5940000,0xE5D01000,0xE5D02001,0xE0811402,0xE241CE40,0xE25CC007,0x03A01080,0x05C01005,0x0A000010,0xE241CE40,0xE25CC028,0xE3A02060,0x05C0200F,0x05940000,0xE3A03004,0x05C08010,0x05940000,0x05C03012,0x0A000006,0xE241CE40,0xE25CC029,0x05C02013,0x05940000,0x05C08014,0x05940000,0x05C03016,0xE8BD81FC,0x10003024,0x10000050,0x00000000,0x00000000,0x00000000},	
};


#if defined( _RDA_PATCH_UART_) 
const kal_uint8 rda_filter_8[] ={0x01,0x02,0xFD,0x0A,0x00,0x01,0x50,0x00,0x00,0x10,0xC4,0x37,0x00,0x10};
#elif defined(_RDA_PATCH_UART2_)
const kal_uint8 rda_filter_8[] ={0x01,0x02,0xFD,0x0A,0x00,0x01,0x50,0x00,0x00,0x10,0xC4,0x37,0x00,0x10};
#elif defined(_RDA_PATCH_UART3_)
const kal_uint8 rda_filter_8[] = {0x01,0x02,0xFD,0x0A,0x00,0x01,0x50,0x00,0x00,0x10,0x84,0x4a,0x00,0x10};
#endif

const kal_uint32 rda_trap_8[][2] = 
{
{0x100000C4,0xFC00FC1B},
{0x100000C8,0xFC00FC66},
{0x100000CC,0xFd42FC42},
{0x100000D0,0xFC00FC34},
{0x100000D4,0xFC00FC76},
{0x100000D8,0xFC1DFC56},
{0x100000DC,0xFC0BFC5B},
{0x100000E0,0xFC0BFCD1},
{0x100000E4,0xFC00FC1e},
{0x100000E8,0x00000000},
{0x10007810,0x100000C4},
                      
{0x40180000,0x00000000},//patch flag
                      
{0x100000f0,0xe247fc5a},//sleep scan
{0x100000f4,0xe0800084},  
{0x100000f8,0xe59710ac},  
{0x100000fc,0xe3c004f0},  
{0x10000100,0xe1500001},  
{0x10000104,0xe3a01b43},  
{0x10000108,0xe281ffd3},  
{0x40180004,0x00010f3c},  
{0x40180024,0x100000f0},  


{0x10000114,0xe243fc41},////uart len >480
{0x10000118,0xe35100f0},
{0x1000011c,0x91a00001},
{0x10000120,0x83a000f0},
{0x10000124,0xe58e0024},
{0x10000128,0xe1c300b2},
{0x1000012c,0xe8bd8010},
{0x40180008,0x00003424},
{0x40180028,0x10000114},
                      
                      
{0x1000001c,0xea000046},//exit sniff wakeup
{0x1000013c,0xe59fe02c},  
{0x10000140,0xe5ce1000},  
{0x10000144,0xe1cd10b8},  
{0x10000148,0xe5d01012},  
{0x1000014c,0xe3a0e01d},  
{0x10000150,0xe001019e},  
{0x10000154,0xe59fe018},  
{0x10000158,0xe08ee101},  
{0x1000015c,0xe59e1018},  
{0x10000160,0xe2411a40},  
{0x10000164,0xe58e1018},  
{0x10000168,0xe3a0eb4b},  
{0x1000016c,0xe28eff67},  
{0x10000170,0x10006718},  
{0x10000174,0x100062a0},  
{0x10000178,0xe281f241},  
{0x4018000c,0x00012d98},  
{0x4018002c,0x10000178},  
                      
{0x100001c8,0xe595002c},////uart len >480
{0x100001cc,0xe1d520b6},
{0x100001d0,0xe0820000},
{0x100001d4,0xe3a0eb93},
{0x100001d8,0xe28effd7},
{0x100001dc,0xe245fc66},
{0x100001e0,0xeafffff8},
{0x40180010,0x00024f58},
{0x40180030,0x100001dc},
                      
{0x100001f0,0xe241fc59},///disable inquirty scan in sco
{0x100001f4,0xe59f0014},
{0x100001f8,0xe5d00001},
{0x100001fc,0xe3500000},
{0x10000200,0x18bd80f8},
{0x10000204,0xe1d106b2},
{0x10000208,0xe3a02b53},
{0x1000020c,0xe282ffc9},
{0x10000210,0x1000583c},
{0x40180014,0x00014f20},
{0x40180034,0x100001f0},
                      
                      
                      
{0x100002f0,0xe241fc58},//LMpol_Service_Imminent_Wakeup_Control adjust to fit USLCr2p_Get_Search_Window_Frames
{0x100002f4,0xe59140b4},
{0x100002f8,0xe3540000},
{0x100002fc,0x11d401b0},
{0x10000300,0x03a00008},
{0x10000304,0xe3100004},
{0x10000308,0x08bd8010},
{0x1000030c,0xe5d40012},
{0x10000310,0xe3a0e01d},
{0x10000314,0xe000009e},
{0x10000318,0xe59fe024},
{0x1000031c,0xe08e0100},
{0x10000320,0xe3a01000},
{0x10000324,0xe28fe004},
{0x10000328,0xe3a05BA2},
{0x1000032c,0xe285f094},
{0x10000330,0x15d41013},
{0x10000334,0xe3510000},
{0x10000338,0x12804008},
{0x1000033c,0xe3a0eb43},
{0x10000340,0xe28effaf},
{0x10000344,0x100062a0},
{0x40180018,0x00010e98},
{0x40180038,0x100002f0},
                      
{0x4018001c,0x00031888},//disable eir
{0x4018003c,0x0003189c},
                      
{0x40180020,0x00028930},//USLCr2p_Get_Search_Window_Frames, remove 25ms restrict
{0x40180040,0x00022638},
                      
                      
{0x10000244,0xe246fc55},//acl buff init
{0x10000248,0xe3500003},
{0x1000024c,0xb3a05c83},
{0x10000250,0xb285f0b4},
#if 1//defined( _RDA_PATCH_UART3_) ||defined(_RDA_PATCH_UART2_)|| defined(_RDA_PATCH_UART_)
{0x10000254,0xea00003d},
#else
{0x10000254,0xe8bd83f8},
#endif
#if !defined(_RDA_PATCH_UART3_)// defined(_RDA_PATCH_UART2_)|| defined(_RDA_PATCH_UART_)
{0x10000350,0xe59f0048},
{0x10000354,0xe3a01004},
{0x10000358,0xe1c010b6},
{0x1000035c,0xe1c010b4},
{0x10000360,0xe59f103c},
{0x10000364,0xe2812048},
{0x10000368,0xe580200c},
{0x1000036c,0xe3a00000},
{0x10000370,0xe581005c},
{0x10000374,0xe59f202c},
{0x10000378,0xe3a00008},
{0x1000037c,0xe1c200b6},
{0x10000380,0xe1c200b4},
{0x10000384,0xe2813060},
{0x10000388,0xe5823008},
{0x1000038c,0xe2812094},
{0x10000390,0xe581208c},
{0x10000394,0xe59f1010},
{0x10000398,0xe1c108b8},
{0x1000039c,0xe8bd83f8},
{0x100003a0,0x10003484},
{0x100003a4,0x100034ac},
{0x100003a8,0x10003498},
{0x100003ac,0x10004038},
#endif
{0x40180100,0x000083e0},
{0x40180120,0x10000244},

//{0x4018010c,0x000310e4},//connect switch slot adjust
//{0x4018012c,0x0000fcb4},
                        
//{0x40180110,0x0001ac78},///auth req ignor key exist
//{0x40180130,0x0001ad08},
//e3c2bc22 bic r11,r2,0x2200
{0x1000034c,0xe3c2bc22},//disable 3m send
{0x40180104,0x000011a8},
{0x40180124,0x1000034c},


{0x10007ffc,0xe352000b},//patch for power control
{0x40180114,0x000067fc},//patch
{0x40180134,0x10007ffc},//patch






#ifdef _RDA_PATCH_UART3_                                           

{0x10000444,0x10003498},//acl buf init
{0x10000448,0x100037c4},
{0x1000044c,0x10004038},      
                      
                      
{0x100000C0,0xEA0014eb},//uart patch 77
{0x40180108,0x000032B0},
{0x40180128,0x1000540C},
{0x4018010c,0x000034BC},
{0x4018012c,0x10005470},
                      
{0x10000080,0x00000000},
{0x10000084,0x00000000},
{0x10000088,0x00000000},
{0x1000008c,0x00000000},
{0x10000090,0x00000000},
{0x10000094,0x00000000},
{0x10000098,0x00000000},
{0x1000009c,0x00000000},
                      
{0x40180110,0x0002b584},//disable simple pair
{0x40180130,0x0002d5f4},

{0x40180000,0x00003fff},//patch plag
#else
{0x40180000,0x000023ff},
#endif

{0x10000490,0x10005548},


};


const kal_uint8 rda_hci_reset[] = {0x01,0x03,0x0c,0x00};


void rdabt_reset_write(void) 
{
     kal_uint16 num_send;	
     rdabt_uart_tx(rda_hci_reset,sizeof(rda_hci_reset),&num_send);
      RDABT_DELAY(2);

}

void Rdabt_Pskey_Write_rf_r8(void)
{
   kal_int32 i;
   for(i=0;i<sizeof(rdabt_pskey_rf_8)/sizeof(rdabt_pskey_rf_8[0]);i++)
   {
      rdabt_wirte_memory(rdabt_pskey_rf_8[i][0],&rdabt_pskey_rf_8[i][1],1,0);
      RDABT_DELAY(1);
   }
      RDABT_DELAY(10);	
}


void Rdabt_Pskey_Write_r8(void)
{
   kal_int32 i;
   for(i=0;i<sizeof(rda_pskey_8)/sizeof(rda_pskey_8[0]);i++)
   {
      rdabt_wirte_memory(rda_pskey_8[i][0],&rda_pskey_8[i][1],1,0);
      RDABT_DELAY(1);
   }
	
}

void rdabt_patch_write_r8(void)
{
#if defined(_RDA_PATCH_UART_) || defined(_RDA_PATCH_UART2_) || defined(_RDA_PATCH_UART3_)
   kal_int32 i;
   for(i=0;i<sizeof(rda_patch_8)/sizeof(rda_patch_8[0]);i++)
   {
      rdabt_wirte_memory(rda_patch_8[i][0],&rda_patch_8[i][1],61,0);
      RDABT_DELAY(10);
   }
#endif

}

void rdabt_bigpatch_write_r8(void)
{
   kal_int32 i;
   for(i=0;i<sizeof(rda_bigpatch_8)/sizeof(rda_bigpatch_8[0]);i++)
   {
      rdabt_wirte_memory(rda_bigpatch_8[i][0],&rda_bigpatch_8[i][1],61,0);
      RDABT_DELAY(10);
   }      

   
}

   
void rdabt_set_filter_r8(void)
{
#if defined( _RDA_PATCH_UART_) || defined(_RDA_PATCH_UART2_) || defined(_RDA_PATCH_UART3_)
   kal_uint16 num_send;	
   rdabt_uart_tx(rda_filter_8,sizeof(rda_filter_8),&num_send);
   RDABT_DELAY(1);
#endif   
}


void Rdabt_trap_write_r8(void)
{
   kal_int32 i;
   for(i=0;i<sizeof(rda_trap_8)/sizeof(rda_trap_8[0]);i++)
   {
      rdabt_wirte_memory(rda_trap_8[i][0],&rda_trap_8[i][1],1,0);
      RDABT_DELAY(1);
   }	
}




void  RDABT_rf_Intialization_r8(void)
{
	unsigned char i=0;
	for(i =0;i<sizeof(rdabt_rf_init_8)/sizeof(rdabt_rf_init_8[0]); i++){
		rdabt_iic_rf_write_data(rdabt_rf_init_8[i][0],&rdabt_rf_init_8[i][1],1);		
	}	
	RDABT_DELAY(10);  

}


void RDABT_core_Intialization_r8(void)
{
	kal_prompt_trace(0,"RDABT_core_Intialization_r8");
	RDA_bt_Power_On_Reset();
	RDABT_DELAY(70);
	Rdabt_Pskey_Write_rf_r8();
	Rdabt_Pskey_Write_r8();
	rdabt_patch_write_r8();
	rdabt_bigpatch_write_r8();
	rdabt_set_filter_r8();
	Rdabt_trap_write_r8();
	rdabt_reset_write();
}

#endif// __RDA_CHIP_R8_5870__

#endif
