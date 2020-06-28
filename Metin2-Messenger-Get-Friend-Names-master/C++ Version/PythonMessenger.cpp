//1.1 Search for:
		{ "RemoveFriend",				messengerRemoveFriend,				METH_VARARGS },
//1.1 Add after:
		{ "GetFriendNames",				messengerGetFriendNames,			METH_VARARGS },

//1.2 Search for:
void CPythonMessenger::SetMessengerHandler(PyObject* poHandler)
{
	m_poMessengerHandler = poHandler;
}
//1.2 Add after:
const CPythonMessenger::TFriendNameMap CPythonMessenger::GetFriendNames()
{
	return m_FriendNameMap;
}

//1.3 Search for:
PyObject * messengerRefreshGuildMember(PyObject* poSelf, PyObject* poArgs)
{
	CPythonMessenger::Instance().RefreshGuildMember();
	return Py_BuildNone();
}
//1.3 Add after:
PyObject* messengerGetFriendNames(PyObject* poSelf, PyObject* poArgs)
{
	const CPythonMessenger::TFriendNameMap friendNameMap = CPythonMessenger::Instance().GetFriendNames();
	PyObject * pyTupleFriendNames = PyTuple_New(friendNameMap.size());

	int iPos = 0;
	for (CPythonMessenger::TFriendNameMap::const_iterator itor = friendNameMap.begin(); itor != friendNameMap.end(); ++itor, ++iPos)
		PyTuple_SetItem(pyTupleFriendNames, iPos, Py_BuildValue("s", (*itor).c_str()));

	return pyTupleFriendNames;
}