//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(__CHANNEL_STATUS_UPDATE__)
	PyModule_AddIntConstant(poModule, "__CHANNEL_STATUS_UPDATE__", true);
#else
	PyModule_AddIntConstant(poModule, "__CHANNEL_STATUS_UPDATE__", false);
#endif