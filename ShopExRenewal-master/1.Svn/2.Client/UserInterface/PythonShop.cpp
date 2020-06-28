///Add
#ifdef ENABLE_RENEWAL_SHOPEX
PyObject * shopGetItemPriceType(PyObject * poSelf, PyObject * poArgs)
{
	int nPos;
	if (!PyTuple_GetInteger(poArgs, 0, &nPos))
		return Py_BuildException();

	const TShopItemData * c_pItemData;
	if (CPythonShop::Instance().GetItemData(nPos, &c_pItemData))
		return Py_BuildValue("i", c_pItemData->price_type);

	return Py_BuildValue("i", 1);
}
PyObject * shopGetItemPriceVnum(PyObject * poSelf, PyObject * poArgs)
{
	int nPos;
	if (!PyTuple_GetInteger(poArgs, 0, &nPos))
		return Py_BuildException();

	const TShopItemData * c_pItemData;
	if (CPythonShop::Instance().GetItemData(nPos, &c_pItemData))
		return Py_BuildValue("i", c_pItemData->price_vnum);

	return Py_BuildValue("i", 0);
}
#endif

//Find
		{ "BuildPrivateShop",			shopBuildPrivateShop,			METH_VARARGS },
		
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
		{ "GetItemPriceType",			shopGetItemPriceType,			METH_VARARGS },
		{ "GetItemPriceVnum",			shopGetItemPriceVnum,			METH_VARARGS },
#endif