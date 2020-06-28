//Find
		MessengerManager::instance().RemoveAllList(ch->GetName());

///Add
#ifdef ENABLE_MESSENGER_BLOCK
		MessengerManager::instance().RemoveAllBlockList(ch->GetName());
#endif

//Find
int pc_learn_grand_master_skill(lua_State* L)

///Add
#ifdef ENABLE_MESSENGER_BLOCK
	int pc_is_blocked(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

		if (!lua_isnumber(L, 1))
		{
			sys_err("wrong::pc_is_blocked");
			return 0;
		}
		const char * arg1 = lua_tostring(L, 1);
		LPCHARACTER tch = CHARACTER_MANAGER::instance().FindPC(arg1);
		if(!tch || !tch->IsPC())
		{
			sys_err("wrong::pc_is_blocked-2");
			return 0;
		}

		lua_pushboolean(L, MessengerManager::instance().CheckMessengerList(ch->GetName(), tch->GetName(), SYST_BLOCK));
		return 1;
	}
	int pc_is_friend(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

		if (!lua_isnumber(L, 1))
		{
			sys_err("wrong::pc_is_blocked");
			return 0;
		}
		const char * arg1 = lua_tostring(L, 1);
		LPCHARACTER tch = CHARACTER_MANAGER::instance().FindPC(arg1);
		if(!tch || !tch->IsPC())
		{
			sys_err("wrong::pc_is_blocked-2");
			return 0;
		}

		lua_pushboolean(L, MessengerManager::instance().CheckMessengerList(ch->GetName(), tch->GetName(), SYST_FRIEND));
		return 1;
	}
#endif

//Find
			{ "change_name",			pc_change_name },

///Add
			#ifdef ENABLE_MESSENGER_BLOCK
			{ "is_blocked",			pc_is_blocked },
			{ "is_friend",			pc_is_friend },
			#endif