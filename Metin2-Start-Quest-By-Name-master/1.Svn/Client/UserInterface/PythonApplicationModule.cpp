//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(QUEST_BY_NAME)
	PyModule_AddIntConstant(poModule, "QUEST_BY_NAME", 1);
#else
	PyModule_AddIntConstant(poModule, "QUEST_BY_NAME", 0);
#endif