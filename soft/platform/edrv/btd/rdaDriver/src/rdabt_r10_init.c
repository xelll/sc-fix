/*************************************************************************
 *
 * MODULE NAME:    rdabt_r10_init.c
 * PROJECT CODE:   rdabt
 * DESCRIPTION:    rda bt r10 initiation.
 * MAINTAINER:     mql
 * CREATION DATE:  16/04/10
 *
 * SOURCE CONTROL: $Id: rdabt_r10_init.c 6568 2011-03-16 03:52:55Z huazeng $
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


#if defined( __RDA_CHIP_R10_5872__) || defined(__RDA_CHIP_R10_5868E__) || defined(__RDA_CHIP_R10_5872H__) || defined(__RDA_CHIP_R10_5868H__) || defined(__RDA_CHIP_R10_5870E__)




const kal_uint32 rda_pskey_10[][2] =
{
//sleep
{0x80000070,0x00002008},//disalbe esco
{0x80000074,0xa5025010},//sleep
{0x800000a8,0x0Bbfbf30},//min power level
{0x80000040,0x04003000},//PSKEY: modify flag
                               
//{0x80003ff8,0x,0x,0x,0x788dffff},//disable edr
#ifndef __RDA_SHARE_CRYSTAL__

#endif
};


const kal_uint32 rda_trap_10[][2] = 
{
{0x800000C4,0xFC00FC1B},//tc map table
{0x800000C8,0xFC00FC66},
{0x800000CC,0xFD42FC42},
{0x800000D0,0xFC00FC34},
{0x800000D4,0xFC00FC76},
{0x800000D8,0xFC1DFC56},
{0x800000DC,0xFC0BFC5B},
{0x800000E0,0xFC00FC1E},
{0x800000E4,0x00000000},
{0x800078A8,0x800000C4},

{0x80000000,0xea00001e},//sleep rom
{0x80000080,0xe1a00000},
{0x80000084,0xe1a00000},
{0x80000088,0xe1a00000},
{0x8000008c,0xe1a00000},
{0x80000090,0xe2800001},
{0x80000094,0xe3500020},
{0x80000098,0xbafffff8},
{0x8000009c,0xe3a00b8a},
{0x800000a0,0xe280fffe},
{0x800000a4,0xe3a0f480},
{0x40180010,0x00022bc8},
{0x40180030,0x800000a4},

{0x40180014,0x00003e20},//name length patch
{0x40180034,0x00022df8},
                      
{0x40180018,0x0002bbac},//diable simple pair
{0x40180038,0x0002dc14},
                      
                      
{0x80000004,0xea00003A},//master poll interval to 0
{0x800000F4,0xe59f5014},
{0x800000F8,0xe5d55001},
{0x800000Fc,0x03550000},
{0x80000100,0xe3a05cfd},
{0x80000104,0x1285f010},
{0x80000108,0x03a02f7e},
{0x8000010c,0xe285f00c},
{0x80000110,0x800057Dc},
{0x4018001c,0x0000fd08},
{0x4018003c,0x00032e7c},

#if 0
{0x80000008,0xea000041},//orign opcode =0
{0x80000114,0xe3500000},
{0x80000118,0xe3a00b95},
{0x8000011c,0x1280f0e4},
{0x80000120,0xe280f0d8},
{0x40180020,0x000254d4},
{0x40180040,0x00032e80},
#else
{0x80000008,0xea000069},
{0x800001b4,0xe3a0eb95},
{0x800001b8,0xe28ee0e4},
{0x800001bc,0xea000003},
{0x800001c0,0xe51ff004},
{0x800001c4,0x00001974},
{0x800001c8,0xe51ff004},
{0x800001cc,0x00001688},
{0x800001d0,0xe92d4008},
{0x800001d4,0xe3a02004},
{0x800001d8,0xe3a01000},
{0x800001dc,0xe3a00000},
{0x800001e0,0xebfffff6},
{0x800001e4,0xe1a02000},
{0x800001e8,0xe5921000},
{0x800001ec,0xe59f0018},
{0x800001f0,0xe5810000},
{0x800001f4,0xe3a00001},
{0x800001f8,0xe1c201b2},
{0x800001fc,0xe8bd4008},
{0x80000200,0xe3a00000},
{0x80000204,0xe3a01000},
{0x80000208,0xeaffffee},
{0x8000020c,0x0000fcc0},
{0x40180020,0x000254d4},
{0x40180040,0x00032e80},
#endif

{0x8000000c,0xea000044},//disable switch twice
{0x80000124,0xe1a05001},
{0x80000128,0xe5d11000},
{0x8000012C,0xe3510001},
{0x80000130,0xe3a01b66},
{0x80000134,0x0281f014},
{0x80000138,0x1281f044},
{0x40180100,0x00019810},
{0x40180120,0x00032e84},

{0x80000010,0xea00004a},///queues init 
{0x80000140,0xe3a03f56},
{0x80000144,0xe3a01006},
{0x80000148,0xe3a0ebab},
{0x8000014c,0xe28eff53},
{0x40180104,0x0002ad44},
{0x40180124,0x00032e88},

#ifdef _RDA_PATCH_UART3_
{0x80000014,0xea0014b4},//buff init start address
#else
{0x80000014,0xEA00004d},
{0x80000150,0xe59f0048},        
{0x80000154,0xe3a01004},        
{0x80000158,0xe1c010b6},  
{0x8000015c,0xe1c010b4},
{0x80000160,0xe59f103c},
{0x80000164,0xe2812048},
{0x80000168,0xe580200c},
{0x8000016c,0xe3a00000},
{0x80000170,0xe581005c},
{0x80000174,0xe59f202c},
{0x80000178,0xe3a00008},
{0x8000017c,0xe1c200b6},
{0x80000180,0xe1c200b4},
{0x80000184,0xe2813060},
{0x80000188,0xe5823008},
{0x8000018c,0xe2812094},
{0x80000190,0xe581208c},
{0x80000194,0xe59f1010},
{0x80000198,0xe1c108b8},
{0x8000019c,0xe49df004},
{0x800001a0,0x80002c58},
{0x800001a4,0x80002c94},
{0x800001a8,0x80002c6c},
{0x800001ac,0x80003fd4},
#endif

{0x40180108,0x00008468},
{0x40180128,0x00032e8c},
                      
                      
{0x4018010c,0x00011e2c},//sniff slave accept auto
{0x4018012c,0x00012020},
                      
{0x40180110,0x00003448},//uart len>240
{0x40180130,0x0001d548},


#ifdef _RDA_PATCH_UART3_
{0x50000044,0x00000001},
#else
{0x50000044,0x00220003},
#endif
{0x8000005c,0x03200000},//
{0x80000040,0x00000080},//flag


#if defined(_RDA_PATCH_UART2_) || defined(_RDA_PATCH_UART3_)

#if 1
#ifdef _RDA_PATCH_UART3_
{0x80000064,0x0030d400},//new baudrate 3200000
#else
{0x80000064,0x000e1000},//new baudrate 921600
#endif

{0x8000005c,0x03200000},//convert baud delay 16slot
{0x80000040,0x00000280},//flag
#endif
#ifdef _RDA_PATCH_UART3_
{0x80004c38,0x00000001},//flag chip
#else
{0x80004c38,0x00000000},
#endif
{0x80004c3c,0x00000000},


{0x40180004,0x00003208},
{0x40180024,0x800051B4},//patch uart rx
                      
{0x800000C0,0xEA001454},
{0x40180008,0x000034E4},
{0x40180028,0x80005214},//patch uart tx
                      
{0x4018000C,0x00031C58},
{0x4018002C,0x800052A4},//patch uart convert baud
{0x40180000,0x00001fff},//patch flag
#else
{0x40180000,0x00001ff8},//patch flag
#endif

};

#ifdef _RDA_PATCH_UART3_
const kal_uint32 rda_patch_acl[] = 
{
0x800052EC,0xE59F10C8,0xE1A00000,0xE3A00004,0xE1C100B6,0xE59F10B8,0xE59F20B4,0xE1C100B4,0xE59F00B0,0xE59F30B4,0xE2801048,0xE582100C,0xE59F10A4,0xE59FC0AC,0xE2812D40,0xE2822EBD,0xE5802000,0xE2832E87,0xE5802030,0xE2832EA1,0xE5802048,0xE3A02000,0xE580205C,0xE59F2080,0xE5801018,0xE1CC20B0,0xE3A02008,0xE1CC20B6,0xE1CC20B4,0xE280E060,0xE58CE008,0xE280C094,0xE580C08C,0xE281CE5A,0xE580C060,0xE281CE9A,0xE580C078,0xE281CD5F,0xE580C0AC,0xE281CD40,0xE2811F68,0xE58010DC,0xE58030F4,0xE2831E40,0xE28CCED7,0xE5A0C0C4,0xE2811038,0xE5801048,0xE59F0024,0xE59F1018,0xE1C028B8,0xE1C018B4,0xE49DF004,0x80002C58,0x80002C94,0x800004C8,0x80003324,0x000003FD,0x80002C6C,0x80003FD4,0x00000000,0x00000000
};
#endif


#if defined(_RDA_PATCH_UART2_) || defined(_RDA_PATCH_UART3_)

const kal_uint32 rda_patch_10[][62]=
{
{0x80004C40,0xE51FF004,0x00032AF0,0xE51FF004,0x00032D2C,0xE51FF004,0x00032C9C,0xE51FF004,0x00032780,0xE51FF004,0x00032BD4,0xE92D41FC,0xE1A06000,0xE3500001,0x13560000,0x1A000108,0xE59F0420,0xE3560002,0xE0802286,0x03A00000,0x11A00281,0xE0820000,0xE5904010,0xE59F0408,0xE3560001,0xE3A08002,0xE59F7400,0x1A000044,0xE5941000,0xE5D10003,0xE5D12004,0xE1805402,0xE59F03E4,0xE245CCFC,0xE25CC042,0xE5900000,0xE245CCFC,0x03500000,0x03A02004,0x05C12006,0xE25CC056,0x1A000002,0xE5940000,0xEBFFFFD4,0xEA000080,0xE245CD40,0xE25CC001,0x1A000011,0xE3500001,0x1A00007B,0xE5940000,0xE3A02005,0xE5C02006,0xE5941000,0xE3A00000,0xE5C10007,0xE5941000,0xE5C12009,0xE5942000,0xE3A01046,0xE5C2100A,0xE5941000},          
{0x80004D34,0xE5C1000B,0xE5941000,0xE5C1000C,0xEA00006B,0xE245CCFC,0xE25CC05B,0x1A000068,0xE3500000,0x1A00000A,0xE5941000,0xE3A000AB,0xE5C10006,0xE5941000,0xE3A00096,0xE5C10007,0xE5941000,0xE3A0000C,0xE5C10008,0xE3A000C8,0xEA00000B,0xE3500001,0x1A000059,0xE5941000,0xE3A000BB,0xE5C10006,0xE5941000,0xE3A000BC,0xE5C10007,0xE5941000,0xE3A0007B,0xE5C10008,0xE3A000C9,0xE5941000,0xE5C10009,0xEA00004C,0xE3560000,0x1A00004A,0xE5942000,0xE5D21000,0xE5D23001,0xE1815403,0xE245CCFC,0xE25CC0C4,0xE3A01001,0x1A000028,0xE5D23004,0xE3530010,0x91A02003,0x9A000010,0xE3A02000,0xE594C000,0xE083E002,0xE08CC00E,0xE55CC008,0xE087E002,0xE2822001,0xE3520010,0xE5CEC001,0x3AFFFFF6,0xEA000018,0xE087C002},          
{0x80004E28,0xE5DCC001,0xE042E003,0xE08EE007,0xE5CEC001,0xE2822001,0xE3520010,0x3AFFFFF7,0xE1A00000,0xE1A00000,0xE1A00000,0xE1A00000,0xE1A00000,0xE1A00000,0xE2632010,0xE3520010,0x2A000007,0xE594C000,0xE083E002,0xE08CC00E,0xE55CC008,0xE087E002,0xE2822001,0xE5CEC001,0xEAFFFFF5,0xE5C71000,0xE245CCF0,0xE25CCECD,0x1A000004,0xE5942000,0xE5D22007,0xE3520077,0x05801004,0xEA000011,0xE245CCFC,0xE25CC077,0x1A000007,0xE5901004,0xE3510001,0x1A00000B,0xE5941000,0xE5D11004,0xE3110080,0x15808004,0xEA000006,0xE245CEC0,0xE25CC003,0x05D70000,0x03500001,0x1A000001,0xEBFFFF55,0xEBFFFF56,0xE5D70000,0xE3500002,0x1A000015,0xE3560000,0x1A000010,0xE5940000,0xE5D72011,0xE5D01000,0xE0211002,0xE5C01000},          
{0x80004F1C,0xE5940000,0xE5D72012,0xE5F01001,0xE0211002,0xE5C01000,0xE1A00004,0xEBFFFF47,0xE5940000,0xE5D01000,0xE5D00001,0xE1815400,0xEA000004,0xE1A00004,0xEB000057,0xEA000013,0xE3560000,0x1A000011,0xE5D70000,0xE3500002,0x0245CCFC,0x025CC056,0x1A00003D,0xE5940000,0xE5D00003,0xE5C7001D,0xE5940000,0xE5D00004,0xE5C7001E,0xE5940000,0xE5D00005,0xE5C7001F,0xE5940000,0xE5D00006,0xE5C70020,0xEA000030,0xE3560001,0x05D70000,0x01A0E007,0x03500002,0x0245CCFC,0x025CC0DF,0x1A000029,0xE5DE0011,0xE59FC0E0,0xE28000E4,0xE5CD0004,0xE5DE0012,0xE28000D2,0xE5CD0005,0xE5DE0013,0xE2800056,0xE5CD0006,0xE5DE0014,0xE2800013,0xE5CD0007,0xE3A00000,0xE28D1004,0xE7D11000,0xE1A023A1,0xE1821081,0xE20120FF},          
{0x80005010,0xE08E1000,0xE5D1301D,0xE0222003,0xE1A031A2,0xE1832282,0xE7DC3000,0xE20220FF,0xE0222003,0xE1A03322,0xE1832102,0xE5D13019,0xE0822003,0xE20220FF,0xE1A03222,0xE1832202,0xE28D3004,0xE7C32000,0xE2800001,0xE3500004,0xE5C12011,0x3AFFFFE5,0xEBFFFEF9,0xEBFFFEFC,0xE1A00000,0xE1A00000,0xE1A00000,0xE1A00000,0xE1A00000,0xE3560001,0x05D70000,0x03500001,0x0245CEC0,0x025CC003,0x05C78000,0x08BD41FC,0x0AFFFEEF,0xE8BD81FC,0x800027B8,0x80004C38,0x80007818,0x80003FD4,0xE92D400C,0xE5901000,0xE59F20EC,0xE5D13000,0xE5D2C015,0xE023300C,0xE5C13000,0xE5D21015,0xE5CD1004,0xE5D21016,0xE5CD1005,0xE5D21017,0xE5CD1006,0xE5D21018,0xE5CD1007,0xE3A01002,0xEA000029,0xE2412002,0xE2122003,0x1A00001F},          
{0x80005104,0xE5DD3004,0xE223309D,0xE5CD3000,0xE5DD3005,0xE2233071,0xE5CD3001,0xE5DD3006,0xE2233042,0xE5CD3002,0xE5DD3007,0xE22330D2,0xE5CD3003,0xE5DD3002,0xE5DDC001,0xE1A03183,0xE18332AC,0xE5CD3004,0xE5DD3003,0xE5DDC002,0xE1A03183,0xE18332AC,0xE5CD3005,0xE5DD3000,0xE5DDC003,0xE1A03183,0xE18332AC,0xE5CD3006,0xE5DD3001,0xE5DDC000,0xE1A03183,0xE18332AC,0xE5CD3007,0xE5903000,0xE28DE004,0xE7DE2002,0xE7F3C001,0xE2811001,0xE02C2002,0xE5C32000,0xE1D020BC,0xE1520001,0x8AFFFFD2,0xE8BD800C,0x80007818,0xE284FC10,0xE3A00000,0xEA00000C,0xE5D13000,0xE59FC044,0xE59CC000,0xE35C0003,0x03530077,0x05D13000,0x022330FF,0xE594C00C,0xE5CC3000,0xE28CC001,0xE2800001,0xE3C00B40,0xE584C00C,0xE591C014},          
{0x800051F8,0xE20CC001,0xE35C0000,0x11500002,0x3AFFFFED,0xE3A01C32,0xE281F068,0x80004C3C,0xE289F208,0xE59F1048,0xE5912000,0xEA00000C,0xE5D51000,0xE3520003,0x15C81000,0x1A000006,0xE3510077,0x13510011,0x13510013,0x03A00077,0x05C80000,0x022110FF,0xE5C81000,0xE2855001,0xE2444001,0xE3540000,0x1AFFFFF0,0xE3A00C35,0xE280F028,0x80004C3C,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xE241FC17,0xE1C100B0,0xE59F1014,0xE5910000,0xE3500002,0x03A00003,0x05810000,0xE3A01BC7,0xE281F05C,0x80004C3C,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}          
};

#endif

const kal_uint8 rdabt_unsniff_prerxon_10[] = {0x01,0x72,0xfc,0x05,0x05,0x64,0x00,0x00,0x00};

#if defined(_RDA_PATCH_UART_)
const kal_uint8 rda_filter_10[] = {0x01,0x72,0xfc,0x05,0x01,0x01,0x00,0x00,0x00};
#elif defined(_RDA_PATCH_UART2_) || defined(_RDA_PATCH_UART3_)
const kal_uint8 rda_filter_10[] = {0x01,0x72,0xfc,0x05,0x01,0x68,0x4c,0x00,0x80};
#else
const kal_uint8 rda_filter_10[] = {0x01,0x72,0xfc,0x05,0x01,0x00,0x00,0x00,0x00};
#endif

//////////////////////////////////////////////////////////


void Rdabt_Pskey_Write_r10(void)
{
   kal_int32 i;
   for(i=0;i<sizeof(rda_pskey_10)/sizeof(rda_pskey_10[0]);i++)
   {
      rdabt_wirte_memory(rda_pskey_10[i][0],&rda_pskey_10[i][1],1,0);
      RDABT_DELAY(2);
   }	
}


void Rdabt_trap_write_r10(void)
{
   kal_int32 i;
   for(i=0;i<sizeof(rda_trap_10)/sizeof(rda_trap_10[0]);i++)
   {
      rdabt_wirte_memory(rda_trap_10[i][0],&rda_trap_10[i][1],1,0);
      RDABT_DELAY(1);
   }	
}

void Rdabt_patch_write_r10(void)
{
#if defined(_RDA_PATCH_UART2_) || defined(_RDA_PATCH_UART3_)

   kal_int32 i;
   for(i=0;i<sizeof(rda_patch_10)/sizeof(rda_patch_10[0]);i++)
   {
      rdabt_wirte_memory(rda_patch_10[i][0],&rda_patch_10[i][1],61,0);
      RDABT_DELAY(10);
   }	
#endif   
}

void Rdabt_acl_patch_write_r10(void)
{
#ifdef _RDA_PATCH_UART3_
   rdabt_wirte_memory(rda_patch_acl[0],&rda_patch_acl[1],61,0);
   RDABT_DELAY(10);
#endif   
}

void Rdabt_unsniff_prerxon_write_r10(void)
{
   kal_uint16 num_send;	
   rdabt_uart_tx(rdabt_unsniff_prerxon_10,sizeof(rdabt_unsniff_prerxon_10),&num_send);
   RDABT_DELAY(1);
}



void Rdabt_setfilter_r10(void)
{
   kal_uint16 num_send;	
   rdabt_uart_tx(rda_filter_10,sizeof(rda_filter_10),&num_send);
   RDABT_DELAY(1);
}



#endif//#if defined__RDA_CHIP_R10__ || __RDA_CHIP_R10_5872H__

#endif

