//1.1 Search for:
PyObject * backgroundDisableGuildArea(PyObject * poSelf, PyObject * poArgs)
{
	CPythonBackground::Instance().DisableGuildArea();
	return Py_BuildNone();
}
//1.1 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
PyObject * backgroundLoadGraphicMaskSettings(PyObject * poSelf, PyObject * poArgs)
{
	for (BYTE bPart = 0; bPart <= CMapOutdoor::PART_TREE; ++bPart)
	{
		const bool bFlag = !CPythonSystem::Instance().GetGraphicMaskPart(bPart);
		CPythonBackground::Instance().SetVisiblePart(bPart, bFlag);
	}
	return Py_BuildNone();
}
#endif

//1.2 Search for:
		{ "DisableGuildArea",					backgroundDisableGuildArea,					METH_VARARGS },
//1.2 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
		{ "LoadGraphicMaskSettings",			backgroundLoadGraphicMaskSettings,			METH_VARARGS },
#endif