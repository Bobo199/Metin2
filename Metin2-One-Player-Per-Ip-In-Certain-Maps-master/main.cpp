//Add
#include "map_manager.h"

//Search:
COXEventManager OXEvent_manager;

//Add before:
MapManager map_manager;

//Search:
OXEvent_manager.Initialize();

//Add before:
map_manager.Initialize();

//Search:
OXEvent_manager.Destroy();

//Add after:
map_manager.Destroy();