//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef __LOADING_TIP__
	PyModule_AddIntConstant(poModule, "__LOADING_TIP__", true);
#else
	PyModule_AddIntConstant(poModule, "__LOADING_TIP__", false);
#endif