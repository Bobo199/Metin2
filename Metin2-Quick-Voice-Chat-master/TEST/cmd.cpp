//Find
ACMD(do_fishing);

///Add
#if defined(VOICE_CHAT)
	ACMD(do_voice_chat);
	ACMD(do_guild_voice_chat);
	ACMD(do_party_voice_chat);
#endif

//Find
	{ "set_walk_mode",	do_set_walk_mode,	0,			POS_DEAD,	GM_PLAYER	},
		
///Add
#if defined(VOICE_CHAT)
	{ "voice_chat",			do_voice_chat,			0,			POS_DEAD,	GM_PLAYER	},
	{ "guild_voice_chat",	do_guild_voice_chat,	0,			POS_DEAD,	GM_PLAYER	},
	{ "party_voice_chat",	do_party_voice_chat,	0,			POS_DEAD,	GM_PLAYER	},
#endif