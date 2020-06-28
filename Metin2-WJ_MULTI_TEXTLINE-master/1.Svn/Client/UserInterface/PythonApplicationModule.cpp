//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(WJ_MULTI_TEXTLINE)
	PyModule_AddIntConstant(poModule, "WJ_MULTI_TEXTLINE", 1);
#else
	PyModule_AddIntConstant(poModule, "WJ_MULTI_TEXTLINE", 0);
#endif