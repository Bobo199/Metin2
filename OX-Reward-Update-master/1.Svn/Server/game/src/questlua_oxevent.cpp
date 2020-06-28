//Find
	int oxevent_give_item(lua_State* L)
	{
		if (lua_isnumber(L, 1) && lua_isnumber(L, 2))
			COXEventManager::instance().GiveItemToAttender((int)lua_tonumber(L, 1), (int)lua_tonumber(L, 2));
		return 0;
	}
	
///Add
#ifdef OX_REWARD_UPDATE	
	int oxevent_autoreward(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		if (ch && !COXEventManager::instance().GiveReward())
			ch->ChatPacket(CHAT_TYPE_INFO, "Error");
		return 0;
	}
	int oxevent_reloadreward(lua_State* L)
	{
		COXEventManager::instance().LoadRewardTable();
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		if (ch)
			ch->ChatPacket(CHAT_TYPE_INFO, "OX reward list reloaded.");
		return 0;
	}
#endif

//Find
			{	"open",			oxevent_open		},
			
///Add
#ifdef OX_REWARD_UPDATE
			{	"autoreward",	oxevent_autoreward	},
			{	"reloadreward",	oxevent_reloadreward },
#endif