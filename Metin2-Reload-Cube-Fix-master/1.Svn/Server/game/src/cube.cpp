///Add new Func
#if defined(CUBE_RELOAD_FIX)
#include "desc.h"
#include "desc_manager.h"
static void CubeReload()
{
	cube_info_map.clear();
	cube_result_info_map_by_npc.clear();
	Cube_InformationInitialize();
	for (DESC_MANAGER::DESC_SET::const_iterator it = DESC_MANAGER::instance().GetClientSet().begin(); it != DESC_MANAGER::instance().GetClientSet().end(); ++it) {
		LPCHARACTER ch = (*it)->GetCharacter();
		if (ch) {
			Cube_close(ch);
			ch->ChatPacket(CHAT_TYPE_COMMAND, "cube reload");
		}
	}
}
#endif

//Find
	if (false == Cube_load(file_name))
		sys_err("Cube_Init failed");
	
///Add
#if defined(CUBE_RELOAD_FIX)
	if (s_isInitializedCubeMaterialInformation)
		CubeReload();
#endif