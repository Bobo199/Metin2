///Add
#if defined(QUEST_BY_NAME)
PyObject* eventQuestButtonClickByName(PyObject* poSelf, PyObject* poArgs)
{
	char* questname;
	if (!PyTuple_GetString(poArgs, 0, &questname))
		return Py_BuildException();
	CPythonNetworkStream::Instance().SendScriptButtonPacketByName(questname);
	return Py_BuildNone();
}
#endif

//Find
		{ "QuestButtonClick",			eventQuestButtonClick,				METH_VARARGS },
		
///Add
#if defined(QUEST_BY_NAME)
		{ "QuestClickByName",			eventQuestButtonClickByName,		METH_VARARGS },
#endif