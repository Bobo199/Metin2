//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	PyModule_AddIntConstant(poModule, "ENABLE_RENEWAL_SHOPEX",	true);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_RENEWAL_SHOPEX",	false);
#endif