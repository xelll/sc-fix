////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//            Copyright (C) 2003-2007, Coolsand Technologies, Inc.            //
//                            All Rights Reserved                             //
//                                                                            //
//      This source code is the property of Coolsand Technologies and is      //
//      confidential.  Any  modification, distribution,  reproduction or      //
//      exploitation  of  any content of this file is totally forbidden,      //
//      except  with the  written permission  of  Coolsand Technologies.      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//	$Author: ytt $                                                        // 
//	$Date: 2008-07-22 11:00:00 +0800 (Tue, 22 Jul 2007) $                     //   
//	$Revision: 7769 $                                                          //   
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
/// @file drv_flsh_map.c                                                      //
/// That file provides the flah mapping structures.                           //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////



// Bank and sector mapping of the flash chip.

#include "cs_types.h"
#include "memd_m.h"


// =============================================================================
//  MACROS
// =============================================================================
#define KBYTES 1024
#define MBYTES (1024*KBYTES)

// -------------------------------
// FLASH Mapping
// -------------------------------
#define NUMBER_OF_BANKS 16
#define BANK0_BASE 0
#define BANK1_BASE (512*KBYTES)
#define BANK2_BASE (512*2*KBYTES)
#define BANK3_BASE (512*3*KBYTES)
#define BANK4_BASE (512*4*KBYTES)
#define BANK5_BASE (512*5*KBYTES)
#define BANK6_BASE (512*6*KBYTES)
#define BANK7_BASE (512*7*KBYTES)
#define BANK8_BASE (512*8*KBYTES)
#define BANK9_BASE (512*9*KBYTES)
#define BANK10_BASE (512*10*KBYTES)
#define BANK11_BASE (512*11*KBYTES)
#define BANK12_BASE (512*12*KBYTES)
#define BANK13_BASE (512*13*KBYTES)
#define BANK14_BASE (512*14*KBYTES)
#define BANK15_BASE (512*15*KBYTES)

#define FLASH_SIZE      (8*MBYTES)

// =============================================================================
//  GLOBAL VARIABLES
// =============================================================================

PUBLIC CONST MEMD_BANK_LAYOUT_T g_memdFlashBankLayout [NUMBER_OF_BANKS]
     =
{
    { BANK0_BASE, { {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK1_BASE, { {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK2_BASE, { {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK3_BASE, { {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK4_BASE, { {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK5_BASE, { {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK6_BASE, { {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK7_BASE, { {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK8_BASE, { {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK9_BASE, { {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK10_BASE,{ {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK11_BASE,{ {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK12_BASE,{ {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK13_BASE,{ {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK14_BASE,{ {8  , 64*KBYTES}, {0 , 0*KBYTES}, {0 , 0*KBYTES} } },
    { BANK15_BASE,{ {7  , 64*KBYTES}, {8 , 8*KBYTES},{0 , 0*KBYTES} } }
};

PUBLIC CONST MEMD_FLASH_LAYOUT_T g_memdFlashLayout
     =
{
    NUMBER_OF_BANKS, g_memdFlashBankLayout, FLASH_SIZE, USER_DATA_BASE, USER_DATA_SIZE, USER_DATA_BLOCK_SIZE
};


