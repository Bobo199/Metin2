///Add
#ifdef CLEAR_CHAT
PyObject* chatClearChat(PyObject* poSelf, PyObject* poArgs)
{
	CPythonChat::Instance().ClearChat();
	return Py_BuildNone();
}
#endif

//Find
		{ "GetLineStep",			chatGetLineStep,			METH_VARARGS },
		
///Add
#ifdef CLEAR_CHAT
		{ "ClearChat",				chatClearChat,				METH_VARARGS },
#endif
