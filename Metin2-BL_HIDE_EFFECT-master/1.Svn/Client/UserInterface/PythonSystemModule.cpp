///Add
#if defined(__BL_HIDE_EFFECT__)
PyObject* systemGetBLEffectOption(PyObject* poSelf, PyObject* poArgs)
{
	std::uint8_t idx;
	if (!PyTuple_GetInteger(poArgs, 0, &idx))
		return Py_BuildException();

	return Py_BuildValue("b", CPythonSystem::Instance().GetBLEffectOption(idx));
}

PyObject* systemSetBLEffectOption(PyObject* poSelf, PyObject* poArgs)
{
	std::uint8_t idx; bool ret;
	if (!PyTuple_GetInteger(poArgs, 0, &idx) || !PyTuple_GetBoolean(poArgs, 1, &ret))
		return Py_BuildException();

	CPythonSystem::Instance().SetBLEffectOption(idx, ret);
	return Py_BuildNone();
}
#endif

//Find
		{ "IsShowSalesText",			systemIsShowSalesText,			METH_VARARGS },
	
///Add
#if defined(__BL_HIDE_EFFECT__)
		{ "SetBLEffectOption",			systemSetBLEffectOption,		METH_VARARGS },
		{ "GetBLEffectOption",			systemGetBLEffectOption,		METH_VARARGS },
#endif