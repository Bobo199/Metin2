///Add
#include "pythoncharactermanager.h"

//Find
	PyModule_AddIntConstant(poModule, "PART_TERRAIN",			CMapOutdoor::PART_TERRAIN);
	
///Add
#ifdef HIDE_OBJECTS
	PyModule_AddIntConstant(poModule, "PART_SHOP",				CMapOutdoor::PART_SHOP);
#endif

//Find
PyObject * backgroundSetVisiblePart(PyObject * poSelf, PyObject * poArgs)
{
	....
	....
}

///Change
PyObject * backgroundSetVisiblePart(PyObject * poSelf, PyObject * poArgs)
{
	int ePart;
	if (!PyTuple_GetInteger(poArgs, 0, &ePart))
		return Py_BadArgument();

	int isVisible;
	if (!PyTuple_GetInteger(poArgs, 1, &isVisible))
		return Py_BadArgument();

	if (ePart>=CMapOutdoor::PART_NUM)
		return Py_BuildException("ePart(%d)<background.PART_NUM(%d)", ePart, CMapOutdoor::PART_NUM);

	#ifdef HIDE_OBJECTS
	if (ePart == CMapOutdoor::PART_SHOP) {
		CPythonCharacterManager & rkChrMgr = CPythonCharacterManager::Instance();
		rkChrMgr.SetVisibleShops(isVisible ? false : true);
	}
	#endif
	CPythonBackground& rkBG=CPythonBackground::Instance();
	rkBG.SetVisiblePart(ePart, isVisible ? true : false);
	
	return Py_BuildNone();
}


///Add after
#ifdef HIDE_OBJECTS
PyObject * backgroundIsVisiblePart(PyObject * poSelf, PyObject * poArgs)
{
	int ePart;
	if (!PyTuple_GetInteger(poArgs, 0, &ePart))
		return Py_BadArgument();

	if (ePart>=CMapOutdoor::PART_NUM)
		return Py_BuildException("ePart(%d)<background.PART_NUM(%d)", ePart, CMapOutdoor::PART_NUM);
	
	CPythonBackground& rkBG = CPythonBackground::Instance();
	CMapOutdoor& rkMap = rkBG.GetMapOutdoorRef();

	return Py_BuildValue("i", rkMap.IsVisiblePart(ePart));
}
#endif
//Find
		{ "SetVisiblePart",						backgroundSetVisiblePart,					METH_VARARGS },

///Add
		#ifdef HIDE_OBJECTS
		{ "IsVisiblePart",						backgroundIsVisiblePart,					METH_VARARGS },
		#endif
