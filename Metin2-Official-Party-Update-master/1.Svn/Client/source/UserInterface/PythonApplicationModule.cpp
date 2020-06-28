//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef BL_PARTY_UPDATE
	PyModule_AddIntConstant(poModule, "BL_PARTY_UPDATE",	1);
#else
	PyModule_AddIntConstant(poModule, "BL_PARTY_UPDATE",	0);
#endif