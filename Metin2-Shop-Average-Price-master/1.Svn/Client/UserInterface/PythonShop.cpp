///Add
#if defined(__SHOP_ITEM_AVERAGE__)
PyObject* shopGetItemAveragePrice(PyObject* poSelf, PyObject* poArgs)
{
	int nPos;
	if (!PyTuple_GetInteger(poArgs, 0, &nPos))
		return Py_BuildException();

	const TShopItemData* c_pItemData;
	if (CPythonShop::Instance().GetItemData(nPos, &c_pItemData))
		return Py_BuildValue("l", c_pItemData->average_price);

	return Py_BuildValue("i", 0);
}
#endif

//Find
		{ "GetItemID",					shopGetItemID,					METH_VARARGS },
		
///Add
#if defined(__SHOP_ITEM_AVERAGE__)
		{ "GetItemAveragePrice",		shopGetItemAveragePrice,		METH_VARARGS },
#endif