#ifdef CHAT_SLOW_MODE
	PyModule_AddIntConstant(poModule, "CHAT_SLOW_MODE", true);
#else
	PyModule_AddIntConstant(poModule, "CHAT_SLOW_MODE", false);
#endif