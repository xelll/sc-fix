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
/// @file                                                                     //
/// That file Implements the functions to register the module.
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "cs_types.h"

#include "hal_map_engine.h"

#include "dll_map.h"

#include "dll_m.h"



// =============================================================================
//  MACROS
// =============================================================================

#define DLL_VERSION_STRING "Hello, I'm dll!"
#include "dllp_version.h"


// =============================================================================
//  GLOBAL VARIABLES
// =============================================================================


// =============================================================================
// g_palMapVersion
// -----------------------------------------------------------------------------
/// Contains the version of the module.
/// The macro used is generated by the make process.
// =============================================================================
PROTECTED HAL_MAP_VERSION_T g_dllMapVersion = DLL_VERSION_STRUCT;



// =============================================================================
// g_dllMapAccess
// -----------------------------------------------------------------------------
/// Contains the addresses of the structures of the module that will be
/// accessible from a remote PC (e.g. through CoolWatcher).
// =============================================================================
PROTECTED DLL_MAP_ACCESS_T g_dllMapAccess =
{
    // Put your initialization here.
};


// =============================================================================
//  FUNCTIONS
// =============================================================================

// =============================================================================
// dll_RegisterYourself
// -----------------------------------------------------------------------------
/// This function registers the module itself to HAL so that the version and
/// the map accessor are filled. Then, the CSW get version function and the
/// CoolWatcher get version command will work.
// =============================================================================
PUBLIC VOID dll_RegisterYourself(VOID)
{
    hal_MapEngineRegisterModule(HAL_MAP_ID_PAL, &g_dllMapVersion, &g_dllMapAccess);

   dl_envInit();
}

