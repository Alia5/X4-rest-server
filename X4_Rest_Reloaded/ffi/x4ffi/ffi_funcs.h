#pragma once

// Regex to convert the lua definitions to c++ typedefs
//   \t(.+?)(([0-z])+?)\(
//   using $2 = $1(*)(

#include "ffi_funcs_menu_map.h"
#include "ffi_funcs_menu_playerinfo.h"
#include "ffi_funcs_helper.h"
#include "ffi_funcs_station_config.h"
#include "ffi_funcs_customgame.h"