//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef __EXTENDED_SAFEBOX__
	PyModule_AddIntConstant(poModule, "__EXTENDED_SAFEBOX__", true);
#else
	PyModule_AddIntConstant(poModule, "__EXTENDED_SAFEBOX__", false);
#endif