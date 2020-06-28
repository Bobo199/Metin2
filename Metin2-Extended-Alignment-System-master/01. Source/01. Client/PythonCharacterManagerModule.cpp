//1.1) Search for:
PyObject * chrmgrRegisterTitleName(PyObject* poSelf, PyObject* poArgs)
{
	[........]
}
//1.2) Replace with:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
PyObject * chrmgrRegisterTitleName(PyObject* poSelf, PyObject* poArgs)
{
	int	iIndex;
	char * szTitleNameF, * szTitleNameM;
	if (!PyTuple_GetInteger(poArgs, 0, &iIndex) || !PyTuple_GetString(poArgs, 1, &szTitleNameF) || !PyTuple_GetString(poArgs, 2, &szTitleNameM))
		return Py_BadArgument();

	CInstanceBase::RegisterTitleName(iIndex, szTitleNameF, szTitleNameM);
	return Py_BuildNone();
}
#else
PyObject * chrmgrRegisterTitleName(PyObject* poSelf, PyObject* poArgs)
{
	int	iIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iIndex))
		return Py_BadArgument();
	char * szTitleName;
	if (!PyTuple_GetString(poArgs, 1, &szTitleName))
		return Py_BadArgument();
	CInstanceBase::RegisterTitleName(iIndex, szTitleName);
	return Py_BuildNone();
}
#endif