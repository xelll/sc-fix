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
//  $HeadURL: http://svn.coolsand-tech.com/svn/developing1/Sources/edrv/trunk/lcdd/dc2200/ebc/src/drv_lcd.h $ //
//	$Author: huazeng $                                                        // 
//	$Date: 2010-08-23 13:47:34 +0800 (Mon, 23 Aug 2010) $                     //   
//	$Revision: 1532 $                                                          //   
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
/// @file drv_lcd.h                                                           //
/// That file provides the private interface for the AU lcd driver.           //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#ifndef _DRV_LCD_H
#define _DRV_LCD_H
// =============================================================================
// 
// -----------------------------------------------------------------------------
// =============================================================================



// =============================================================================
//  MACROS
// =============================================================================


// =============================================================================
//  TYPES
// =============================================================================
typedef struct {
    UINT16   hsa;
    UINT16   hea;
    UINT16   vsa;
    UINT16   vea;
} LCDD_ACTIVE_WIN_STATUS_T;

// =============================================================================
//  GLOBAL VARIABLES
// =============================================================================


// =============================================================================
//  FUNCTIONS
// =============================================================================


#endif // _DRV_LCD_H_


