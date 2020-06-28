//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(__SHOP_ITEM_AVERAGE__)
	PyModule_AddIntConstant(poModule, "__SHOP_ITEM_AVERAGE__", true);
#else
	PyModule_AddIntConstant(poModule, "__SHOP_ITEM_AVERAGE__", false);
#endif