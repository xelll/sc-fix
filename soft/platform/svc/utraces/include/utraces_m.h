////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//            Copyright (C) 2003-2008, Coolsand Technologies, Inc.            //
//                            All Rights Reserved                             //
//                                                                            //
//      This source code is the property of Coolsand Technologies and is      //
//      confidential.  Any  modification, distribution,  reproduction or      //
//      exploitation  of  any content of this file is totally forbidden,      //
//      except  with the  written permission  of  Coolsand Technologies.      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//
//  $HeadURL$
//  $Author$
//  $Date$
//  $Revision$
//
////////////////////////////////////////////////////////////////////////////////
//
/// @file utraces_m.h
///
/// Usb Trace service
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _UTRACES_M_H_
#define _UTRACES_M_H_

#include "cs_types.h"

// =============================================================================
// MACROS                                                                       
// =============================================================================


// =============================================================================
// TYPES                                                                        
// =============================================================================


// =============================================================================
// GLOBAL VARIABLES                                                             
// =============================================================================

// =============================================================================
// g_utracesCallback
// -----------------------------------------------------------------------------
/// Trace service callback define the callback use by uctls for activate or
/// desactivate the trace service.
// =============================================================================
EXPORT PUBLIC CONST UCTLS_SERVICE_CALLBACK_T    g_utracesCallback;

// =============================================================================
// FUNCTIONS                                                                    
// =============================================================================


#endif // _UTRACES_M_H_
