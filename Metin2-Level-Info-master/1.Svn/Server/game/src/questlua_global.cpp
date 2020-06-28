///Add
#if defined(LEVEL_INFO)
	int _add_level_info(lua_State* L)
	{
		if (!lua_isnumber(L, 1) || !lua_isstring(L, 2) || !lua_isnumber(L, 3))
			return 0;

		const auto level = static_cast<int>(lua_tonumber(L, 1));
		const auto msg = std::string(lua_tostring(L, 2));
		const auto type = static_cast<BYTE>(lua_tonumber(L, 3));
		
		if (!msg.empty() && level > 0 && type >= CHAT_TYPE_TALKING && type < CHAT_TYPE_MAX_NUM)
			LvlInfoMap.emplace(level, std::make_pair(msg, type));

		return 0;
	}
#endif

//Find
			{	"add_bgm_info",				_add_bgm_info			},
			
///Add
#if defined(LEVEL_INFO)
			{	"add_level_info",			_add_level_info			},
#endif
