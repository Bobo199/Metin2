//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef CLEAR_CHAT
	PyModule_AddIntConstant(poModule, "ENABLE_CLEAR_CHAT", true);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_CLEAR_CHAT", false);
#endif
