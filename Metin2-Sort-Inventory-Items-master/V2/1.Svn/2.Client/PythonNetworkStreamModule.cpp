//Find
PyObject* netSendItemPickUpPacket(PyObject* poSelf, PyObject* poArgs)
{
	...
	...
}

///Add
#ifdef ENABLE_SORT_INVEN
PyObject* netSortInven(PyObject* poSelf, PyObject* poArgs)
{
	int option;
	if (!PyTuple_GetInteger(poArgs, 0, &option))
		return Py_BuildException();
	
	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SortInven(option);
	return Py_BuildNone();
}
#endif

//Find
		{ "SendItemPickUpPacket",				netSendItemPickUpPacket,				METH_VARARGS },
		
///Add
#ifdef ENABLE_SORT_INVEN
		{ "SortInven",							netSortInven,							METH_VARARGS },
#endif
