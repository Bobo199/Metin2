//Add
#include "map_manager.h"

//Search:
ALUA(pc_get_name)

//Add before:
ALUA(pc_is_player_ip_in_map)
{
	LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
	lua_pushboolean(L, MapManager::instance().IsPlayerIPInMap(ch));
	return 1;
}

//Search:
{ "getname",		pc_get_name		},

//Add before:
{ "is_pc_ip_in_map",		pc_is_player_ip_in_map	},