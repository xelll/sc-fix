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
//  $HeadURL: http://svn.coolsand-tech.com/svn/developing1/Sources/base/branches/gallite441/std/src/rand.c $ //
//	$Author: admin $                                                       // 
//	$Date: 2010-07-07 20:26:37 +0800 (Wed, 07 Jul 2010) $                     //   
//	$Revision: 268 $                                                          //   
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
/// @file rand.c                                                              //
/// Standard pseudo random generator                                          //
//                                                                            //
//////////////////////////////////////////////////////////////////////////////// 

#include "stdlib.h"

static unsigned long int g_currentRandValue = 1;

// ============================================================================
// srand
// ----------------------------------------------------------------------------
/// Initializes the generator
// ============================================================================
void srand(unsigned int init)
{
    g_currentRandValue = init;
}

// ============================================================================
// rand
// ----------------------------------------------------------------------------
/// Generates a new value
// ============================================================================
int rand()
{
    //Based on Knuth "The Art of Computer Programming"
    g_currentRandValue = g_currentRandValue * 1103515245 + 12345;
    return ( (unsigned int) (g_currentRandValue / 65536) % (RAND_MAX+1) );
}
