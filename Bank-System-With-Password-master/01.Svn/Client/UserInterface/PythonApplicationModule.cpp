//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef __BANK_SYSTEM__
	PyModule_AddIntConstant(poModule, "ENABLE_BANK_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_BANK_SYSTEM",	0);
#endif