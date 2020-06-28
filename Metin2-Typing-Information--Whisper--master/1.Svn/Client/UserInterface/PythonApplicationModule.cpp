//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef ENABLE_WHISPER_RENEWAL
	PyModule_AddIntConstant(poModule, "ENABLE_WHISPER_RENEWAL",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_WHISPER_RENEWAL",	0);
#endif