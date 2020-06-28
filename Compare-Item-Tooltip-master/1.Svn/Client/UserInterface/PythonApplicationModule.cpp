//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(__COMPARE_TOOLTIP__)
	PyModule_AddIntConstant(poModule, "__COMPARE_TOOLTIP__", true);
#else
	PyModule_AddIntConstant(poModule, "__COMPARE_TOOLTIP__", false);
#endif