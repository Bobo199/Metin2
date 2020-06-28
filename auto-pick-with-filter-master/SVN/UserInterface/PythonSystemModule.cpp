// Search

PyObject * systemSetShowSalesTextFlag(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();

	CPythonSystem::Instance().SetShowSalesTextFlag(iFlag);

	return Py_BuildNone();
}

// Add after


PyObject * systemIsPickUpFilterWeapon(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsPickUpFilterWeapon());
}
PyObject * systemSetPickUpFilterWeapon(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();
	CPythonSystem::Instance().SetPickUpFilterWeaponFlag(iFlag);
	
	return Py_BuildNone();
}

PyObject * systemIsPickUpFilterArmor(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsPickUpFilterArmor());
}
PyObject * systemSetPickUpFilterArmor(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();
	CPythonSystem::Instance().SetPickUpFilterArmorFlag(iFlag);
	
	return Py_BuildNone();
}

PyObject * systemIsPickUpFilterEar(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsPickUpFilterEar());
}
PyObject * systemSetPickUpFilterEar(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();
	CPythonSystem::Instance().SetPickUpFilterEarFlag(iFlag);
	
	return Py_BuildNone();
}

PyObject * systemIsPickUpFilterNeck(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsPickUpFilterNeck());
}
PyObject * systemSetPickUpFilterNeck(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();
	CPythonSystem::Instance().SetPickUpFilterNeckFlag(iFlag);
	
	return Py_BuildNone();
}

PyObject * systemIsPickUpFilterFoots(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsPickUpFilterFoots());
}
PyObject * systemSetPickUpFilterFoots(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();
	CPythonSystem::Instance().SetPickUpFilterFootsFlag(iFlag);
	
	return Py_BuildNone();
}

PyObject * systemIsPickUpFilterShield(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsPickUpFilterShield());
}
PyObject * systemSetPickUpFilterShield(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();
	CPythonSystem::Instance().SetPickUpFilterShieldFlag(iFlag);
	
	return Py_BuildNone();
}

PyObject * systemIsPickUpFilterBook(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsPickUpFilterBook());
}
PyObject * systemSetPickUpFilterBook(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();
	CPythonSystem::Instance().SetPickUpFilterBookFlag(iFlag);
	
	return Py_BuildNone();
}

PyObject * systemIsPickUpFilterStone(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsPickUpFilterStone());
}
PyObject * systemSetPickUpFilterStone(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();
	CPythonSystem::Instance().SetPickUpFilterStoneFlag(iFlag);
	
	return Py_BuildNone();
}

PyObject * systemIsPickUpFilterEtc(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsPickUpFilterEtc());
}
PyObject * systemSetPickUpFilterEtc(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();
	CPythonSystem::Instance().SetPickUpFilterEtcFlag(iFlag);
	
	return Py_BuildNone();
}

// Search

		{ NULL,							NULL,							NULL }
	};
  
// Add before

		{ "IsPickUpFilterWeapon",			systemIsPickUpFilterWeapon,			METH_VARARGS },
		{ "SetPickUpFilterWeapon",			systemSetPickUpFilterWeapon,			METH_VARARGS },
		{ "IsPickUpFilterArmor",			systemIsPickUpFilterArmor,			METH_VARARGS },
		{ "SetPickUpFilterArmor",			systemSetPickUpFilterArmor,			METH_VARARGS },
		{ "IsPickUpFilterEar",			systemIsPickUpFilterEar,			METH_VARARGS },
		{ "SetPickUpFilterEar",			systemSetPickUpFilterEar,			METH_VARARGS },
		{ "IsPickUpFilterNeck",			systemIsPickUpFilterNeck,			METH_VARARGS },
		{ "SetPickUpFilterNeck",			systemSetPickUpFilterNeck,			METH_VARARGS },
		{ "IsPickUpFilterFoots",			systemIsPickUpFilterFoots,			METH_VARARGS },
		{ "SetPickUpFilterFoots",			systemSetPickUpFilterFoots,			METH_VARARGS },
		{ "IsPickUpFilterShield",			systemIsPickUpFilterShield,			METH_VARARGS },
		{ "SetPickUpFilterShield",			systemSetPickUpFilterShield,			METH_VARARGS },
		{ "IsPickUpFilterBook",			systemIsPickUpFilterBook,			METH_VARARGS },
		{ "SetPickUpFilterBook",			systemSetPickUpFilterBook,			METH_VARARGS },
		{ "IsPickUpFilterStone",			systemIsPickUpFilterStone,			METH_VARARGS },
		{ "SetPickUpFilterStone",			systemSetPickUpFilterStone,			METH_VARARGS },		
		{ "IsPickUpFilterEtc",			systemIsPickUpFilterEtc,			METH_VARARGS },
		{ "SetPickUpFilterEtc",			systemSetPickUpFilterEtc,			METH_VARARGS },
