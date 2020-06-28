//Add
#include "map_manager.h"

//Search:
else if (ch->GetMapIndex() == 113)

//Add before:
else if (MapManager::instance().IsUniqueIPMap(ch->GetMapIndex())) MapManager::instance().Enter(ch);


