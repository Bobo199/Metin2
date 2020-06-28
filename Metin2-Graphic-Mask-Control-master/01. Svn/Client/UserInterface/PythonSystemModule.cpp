//1.1 Search for:
PyObject * systemGetShadowLevel(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().GetShadowLevel());
}
//1.1 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
PyObject * systemGetGraphicMaskPart(PyObject * poSelf, PyObject * poArgs)
{
	BYTE bPart;
	if (!PyTuple_GetInteger(poArgs, 0, &bPart))
		return Py_BuildException();

	return Py_BuildValue("i", CPythonSystem::Instance().GetGraphicMaskPart(bPart));
}

PyObject * systemSetGraphicMaskPart(PyObject * poSelf, PyObject * poArgs)
{
	BYTE bPart;
	if (!PyTuple_GetInteger(poArgs, 0, &bPart))
		return Py_BuildException();
	
	bool bFlag;
	if (!PyTuple_GetBoolean(poArgs, 1, &bFlag))
		return Py_BuildException();

	CPythonSystem::Instance().SetGraphicMaskPart(bPart, bFlag);
	return Py_BuildNone();
}
#endif

//1.2 Search for:
		{ "SetShadowLevel",				systemSetShadowLevel,			METH_VARARGS },
//1.2 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
		{ "GetGraphicMaskPart",			systemGetGraphicMaskPart,			METH_VARARGS },
		{ "SetGraphicMaskPart",			systemSetGraphicMaskPart,			METH_VARARGS },
#endif