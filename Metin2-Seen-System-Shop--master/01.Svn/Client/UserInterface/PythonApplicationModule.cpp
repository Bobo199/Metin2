//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef ENABLE_SHOP_SEEN
	PyModule_AddIntConstant(poModule, "ENABLE_SHOP_SEEN",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SHOP_SEEN",	0);
#endif