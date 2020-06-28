///Add
#if defined(WJ_MULTI_TEXTLINE)
PyObject* wndSetEnterToken(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWindow;
	bool option;
	if (!PyTuple_GetWindow(poArgs, 0, &pWindow) || !PyTuple_GetBoolean(poArgs, 1, &option))
		return Py_BuildException();

	dynamic_cast<UI::CTextLine*>(pWindow)->SetEnterToken(option);

	return Py_BuildNone();
}
#endif

//Find
		{ "IsDown",						wndButtonIsDown,					METH_VARARGS },
		
///Add
#if defined(WJ_MULTI_TEXTLINE)
		{ "SetEnterToken",				wndSetEnterToken,					METH_VARARGS },
#endif