//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(__BL_HIDE_EFFECT__)
	PyModule_AddIntConstant(poModule, "__BL_HIDE_EFFECT__", true);
#else
	PyModule_AddIntConstant(poModule, "__BL_HIDE_EFFECT__", false);
#endif