//1.1 Search for:
	PyModule_AddIntConstant(poModule, "CAMERA_STOP",			CPythonApplication::CAMERA_STOP);
//1.1 Add after:
#ifdef ENABLE_GRAPHIC_MASK
	PyModule_AddIntConstant(poModule, "ENABLE_GRAPHIC_MASK", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_GRAPHIC_MASK", 0);
#endif