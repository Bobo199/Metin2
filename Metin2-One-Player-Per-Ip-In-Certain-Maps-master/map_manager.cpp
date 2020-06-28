#include "stdafx.h"
#include "constants.h"
#include "config.h"
#include "questmanager.h"
#include "start_position.h"
#include "packet.h"
#include "buffer_manager.h"
#include "log.h"
#include "char.h"
#include "char_manager.h"
#include "map_manager.h"
#include "desc.h"


bool MapManager::Initialize()
{
	itertype(maps) iter = maps.begin();
	for (; iter != maps.end(); ++iter) iter->second.clear();
	return true;
}

void MapManager::Destroy()
{
	itertype(maps) iter = maps.begin();
	for (; iter != maps.end(); ++iter) iter->second.clear();
}

bool MapManager::IsUniqueIPMap(DWORD map_index){
	if (maps.count(map_index) != 0) 
		return true;
	else return false;
}

void MapManager::Enter(LPCHARACTER pChar)
{
	if (pChar){
		DWORD player_index = pChar->GetMapIndex();
		if(IsUniqueIPMap(player_index)){
			DWORD pid = pChar->GetPlayerID();
			maps.at(player_index).insert(std::make_pair(pid, pid));
		}
	}
}


bool MapManager::IsPlayerIPInMap(LPCHARACTER pChar)
{	
	if (pChar == NULL) return false;
	if (!IsUniqueIPMap(pChar->GetMapIndex())) return false;
	
	std::map<DWORD, DWORD> map_players = maps.at(pChar->GetMapIndex());
	if (map_players.size() <= 0) return false;

	itertype(map_players) iter = map_players.begin();
	LPCHARACTER pkChar = NULL;
	
	std::string	player_ip = pChar->GetDesc()->GetHostName();

	for (; iter != map_players.end(); ++iter)
	{
		pkChar = CHARACTER_MANAGER::instance().FindByPID(iter->second);

		if (pkChar != NULL)
		{
			if ((player_ip.compare(pkChar->GetDesc()->GetHostName()) == 0) && (pChar->GetPlayerID() != pkChar->GetPlayerID())){
				return true;
			}
		}
	}
	return false;
}

