//1.1) Search for:
	PyModule_AddIntConstant(poModule, "CAMERA_STOP",			CPythonApplication::CAMERA_STOP);
//1.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_EXTENDED_ALIGNMENT_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_EXTENDED_ALIGNMENT_SYSTEM", 0);
#endif