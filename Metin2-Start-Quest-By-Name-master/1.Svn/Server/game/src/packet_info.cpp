//Find
	Set(HEADER_CG_SCRIPT_BUTTON, sizeof(TPacketCGScriptButton), "ScriptButton", true);
	
///Add
#if defined(QUEST_BY_NAME)
	Set(HEADER_CG_QUEST_BYNAME, sizeof(TPacketCGScriptButtonByName), "ScriptButtonByName", true);
#endif