///Add
PyObject * appCustomLog(PyObject * poSelf, PyObject * poArgs)
{
#if defined(CUSTOM_LOGS)	
	int type; char * sz;
	if (!PyTuple_GetInteger(poArgs, 0, &type))
		return Py_BuildException();
	if (!PyTuple_GetString(poArgs, 1, &sz))
		return Py_BuildException();
	LogFileWithType(type,sz);
#endif
	return Py_BuildNone();
}

//Find
		{ "GetTextFileLine",			appGetTextFileLine,				METH_VARARGS },
		
///Add
		{ "CustomLog",					appCustomLog,					METH_VARARGS },