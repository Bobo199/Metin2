//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef CUBE_RELOAD_FIX
	PyModule_AddIntConstant(poModule, "CUBE_RELOAD_FIX", TRUE);
#else
	PyModule_AddIntConstant(poModule, "CUBE_RELOAD_FIX", FALSE);
#endif