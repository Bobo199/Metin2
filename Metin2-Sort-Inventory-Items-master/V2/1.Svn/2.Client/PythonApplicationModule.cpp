//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef ENABLE_SORT_INVEN
	PyModule_AddIntConstant(poModule, "ENABLE_SORT_INVEN",	true);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SORT_INVEN",	false);
#endif