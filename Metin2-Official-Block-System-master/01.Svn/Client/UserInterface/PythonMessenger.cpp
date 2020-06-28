//Find

void CPythonMessenger::OnFriendLogout(const char * c_szKey)
{
	m_FriendNameMap.insert(c_szKey);

	if (m_poMessengerHandler)
		PyCallClassMemberFunc(m_poMessengerHandler, "OnLogout", Py_BuildValue("(is)", MESSENGER_GRUOP_INDEX_FRIEND, c_szKey));
}

///Add

#ifdef ENABLE_MESSENGER_BLOCK
void CPythonMessenger::OnBlockLogin(const char * c_szKey)
{
	m_BlockNameMap.insert(c_szKey);

	// if (m_poMessengerHandler)
		PyCallClassMemberFunc(m_poMessengerHandler, "OnLogin", Py_BuildValue("(is)", MESSENGER_GROUP_INDEX_BLOCK, c_szKey));
}

void CPythonMessenger::OnBlockLogout(const char * c_szKey)
{
	m_BlockNameMap.insert(c_szKey);

	if (m_poMessengerHandler)
		PyCallClassMemberFunc(m_poMessengerHandler, "OnLogout", Py_BuildValue("(is)", MESSENGER_GROUP_INDEX_BLOCK, c_szKey));
}
BOOL CPythonMessenger::IsBlockByKey(const char * c_szKey)
{
	return (m_BlockNameMap.end() != m_BlockNameMap.find(c_szKey));
}

BOOL CPythonMessenger::IsBlockByName(const char * c_szName)
{
	return IsBlockByKey(c_szName);
}
void CPythonMessenger::RemoveBlock(const char * c_szKey)
{
	m_BlockNameMap.erase(c_szKey);
	PyCallClassMemberFunc(m_poMessengerHandler, "OnRemoveList", Py_BuildValue("(is)", MESSENGER_GROUP_INDEX_BLOCK, c_szKey));
}
#endif

//Find
PyObject * messengerIsFriendByName(PyObject* poSelf, PyObject* poArgs)
{
	char * szName;
	if (!PyTuple_GetString(poArgs, 0, &szName))
		return Py_BuildException();

	return Py_BuildValue("i", CPythonMessenger::Instance().IsFriendByName(szName));
}

///Add
#ifdef ENABLE_MESSENGER_BLOCK
PyObject * messengerIsBlockByName(PyObject* poSelf, PyObject* poArgs)
{
	char * szName;
	if (!PyTuple_GetString(poArgs, 0, &szName))
		return Py_BuildException();
	
	return Py_BuildValue("i", CPythonMessenger::Instance().IsBlockByName(szName));
}
PyObject * messengerRemoveBlock(PyObject* poSelf, PyObject* poArgs)
{
	char * szKey;
	if (!PyTuple_GetString(poArgs, 0, &szKey))
		return Py_BuildException();

	CPythonMessenger::Instance().RemoveBlock(szKey);
	return Py_BuildNone();
}
#endif

//Find

		{ "IsFriendByName",				messengerIsFriendByName,			METH_VARARGS } ,

///Add
		#ifdef ENABLE_MESSENGER_BLOCK
		{ "IsBlockByName",				messengerIsBlockByName,				METH_VARARGS },
		{ "RemoveBlock",				messengerRemoveBlock,				METH_VARARGS },
		#endif
