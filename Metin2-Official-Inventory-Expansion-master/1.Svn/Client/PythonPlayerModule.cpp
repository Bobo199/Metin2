//Find
PyObject * playerGetElk(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CPythonPlayer::Instance().GetStatus(POINT_GOLD));
}

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
PyObject * playerGetEnvanter(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CPythonPlayer::Instance().GetStatus(POINT_BLACK));
}
PyObject * playerIsExInvenKey(PyObject* poSelf, PyObject* poArgs)
{
	int vnum;
	if (!PyTuple_GetInteger(poArgs, 0,&vnum))
		return Py_BuildException();
	if (vnum == INVENTORY_OPEN_KEY_VNUM || vnum == INVENTORY_OPEN_KEY_VNUM2)
		return Py_BuildValue("i", TRUE);
	return Py_BuildValue("i", FALSE);
}
#endif

//Find
		{ "GetMoney",					playerGetElk,						METH_VARARGS },

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
		{ "GetExtendInvenStage",		playerGetEnvanter,						METH_VARARGS },
		{ "IsExtendInvenKey",			playerIsExInvenKey,						METH_VARARGS },
#endif

//Find
		PyModule_AddIntConstant(poModule, "ENERGY",		POINT_ENERGY);
		
///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	PyModule_AddIntConstant(poModule, "INVENTORY_OPEN_PAGE_COUNT",	c_Inventory_Open_Page_Count);
	PyModule_AddIntConstant(poModule, "INVENTORY_LOCKED_PAGE_COUNT",c_Inventory_Locked_Page_Count);
	PyModule_AddIntConstant(poModule, "INVENTORY_NEED_KEY_START",c_Inventory_Need_Key_Start);
	PyModule_AddIntConstant(poModule, "INVENTORY_NEED_KEY_INCREASE",c_Inventory_Need_Key_Increase);
#endif		