///Add
#if defined(CHAT_SLOW_MODE)
ACMD(chat_slow_mode);
#endif

//Find
	{ "pcbang_check", 	do_pcbang_check,	0,			POS_DEAD,	GM_LOW_WIZARD	},
		
///Add
#if defined(CHAT_SLOW_MODE)
	{ "chat_slow_mode",		chat_slow_mode,		0,	POS_DEAD,	GM_LOW_WIZARD	},
#endif