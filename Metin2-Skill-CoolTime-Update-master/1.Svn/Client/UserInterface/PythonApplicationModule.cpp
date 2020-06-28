//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(SKILL_COOLTIME_UPDATE)
	PyModule_AddIntConstant(poModule, "SKILL_COOLTIME_UPDATE", true);
#else
	PyModule_AddIntConstant(poModule, "SKILL_COOLTIME_UPDATE", false);
#endif