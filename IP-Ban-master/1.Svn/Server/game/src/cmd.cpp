///Add
#ifdef _ENABLE_IPBAN_
ACMD(do_ipban);
#endif

//Find
	{ "eclipse",			do_eclipse,				0,	POS_DEAD,	GM_HIGH_WIZARD	},
	
///Add
#ifdef _ENABLE_IPBAN_
	{ "ipban",				do_ipban,				0,	POS_DEAD,	GM_IMPLEMENTOR	},
#endif