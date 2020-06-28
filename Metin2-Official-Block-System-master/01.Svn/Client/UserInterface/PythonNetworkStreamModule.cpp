//Find
PyObject* netRegisterEmoticonString(PyObject* poSelf, PyObject* poArgs)
{
	char * pcEmoticonString;
	if (!PyTuple_GetString(poArgs, 0, &pcEmoticonString))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.RegisterEmoticonString(pcEmoticonString);
	return Py_BuildNone();
}

///Add
#ifdef ENABLE_MESSENGER_BLOCK
PyObject* netSendMessengerAddBlockByVIDPacket(PyObject* poSelf, PyObject* poArgs)
{
	int vid;
	if (!PyTuple_GetInteger(poArgs, 0, &vid))
		return Py_BuildException();

	CPythonNetworkStream& rns=CPythonNetworkStream::Instance();
	rns.SendMessengerAddBlockByVIDPacket(vid);
	
	return Py_BuildNone();
}

PyObject* netSendMessengerAddBlockByNamePacket(PyObject* poSelf, PyObject* poArgs)
{
	char * szName;
	if (!PyTuple_GetString(poArgs, 0, &szName))
		return Py_BuildException();

	CPythonNetworkStream& rns=CPythonNetworkStream::Instance();
	rns.SendMessengerAddBlockByNamePacket(szName);
	
	return Py_BuildNone();
}

PyObject* netSendMessengerBlockRemovePacket(PyObject* poSelf, PyObject* poArgs)
{
	char * szKey;
	if (!PyTuple_GetString(poArgs, 0, &szKey))
		return Py_BuildException();
	char * szName;
	if (!PyTuple_GetString(poArgs, 1, &szName))
		return Py_BuildException();

	CPythonNetworkStream& rns=CPythonNetworkStream::Instance();
	rns.SendMessengerRemoveBlockPacket(szKey, szName);
	
	return Py_BuildNone();
}
#endif

//Find
		{ "SendMessengerRemovePacket",			netSendMessengerRemovePacket,			METH_VARARGS },
		
///Add
		//Block
		#ifdef ENABLE_MESSENGER_BLOCK
		{ "SendMessengerAddBlockByVIDPacket",		netSendMessengerAddBlockByVIDPacket,			METH_VARARGS },
		{ "SendMessengerAddBlockByNamePacket",		netSendMessengerAddBlockByNamePacket,			METH_VARARGS },
		{ "SendMessengerRemoveBlockPacket",			netSendMessengerBlockRemovePacket,				METH_VARARGS },
		#endif