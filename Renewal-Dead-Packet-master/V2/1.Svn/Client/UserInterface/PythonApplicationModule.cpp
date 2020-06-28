#ifdef RENEWAL_DEAD_PACKET
	PyModule_AddIntConstant(poModule, "RENEWAL_DEAD_PACKET",	true);
#else
	PyModule_AddIntConstant(poModule, "RENEWAL_DEAD_PACKET",	false);
#endif