//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef HIDE_OBJECTS
	PyModule_AddIntConstant(poModule, "ENABLE_HIDE_OBJECTS",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_HIDE_OBJECTS",	0);
#endif