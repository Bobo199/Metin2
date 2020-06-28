//Find
	PyModule_AddIntConstant(poModule, "DS_SUB_HEADER_DO_REFINE",	DS_SUB_HEADER_DO_REFINE);
	
///Add
#ifdef RENEWAL_DEAD_PACKET
	PyModule_AddIntConstant(poModule, "REVIVE_TYPE_HERE",		REVIVE_TYPE_HERE);
	PyModule_AddIntConstant(poModule, "REVIVE_TYPE_TOWN",		REVIVE_TYPE_TOWN);
	PyModule_AddIntConstant(poModule, "REVIVE_TYPE_AUTO_TOWN",	REVIVE_TYPE_AUTO_TOWN);
	PyModule_AddIntConstant(poModule, "REVIVE_TYPE_MAX",		REVIVE_TYPE_MAX);
#endif