//Find
PyObject* netGetMainActorVID(PyObject* poSelf, PyObject* poArgs)
{
	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	return Py_BuildValue("i", rkNetStream.GetMainActorVID());
}

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
PyObject* netEnvanterpaketi(PyObject* poSelf, PyObject* poArgs)
{	
	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.Envanter_paketi();
	return Py_BuildNone();
}
#endif

//Find
	{ "SendItemUseToItemPacket",			netSendItemUseToItemPacket,				METH_VARARGS },

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	{ "Envanter_genislet",					netEnvanterpaketi,						METH_VARARGS },
#endif