//1.1) Search for:
	PyModule_AddIntConstant(poModule, "CAMERA_STOP",			CPythonApplication::CAMERA_STOP);
//1.2) Add after:
#ifdef ENABLE_REFINE_MSG_ADD
	PyModule_AddIntConstant(poModule, "ENABLE_REFINE_MSG_ADD", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_REFINE_MSG_ADD", 0);
#endif