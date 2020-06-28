//1.1 Search for:
#include "PythonApplication.h"
//1.1 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
	#include "../gamelib/MapOutDoor.h"
#endif

//1.2 Search for:
	m_Config.bShowSalesText		= true;
//1.2 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
	m_Config.bGraphicMaskTerrain	= false;
	m_Config.bGraphicMaskObject		= false;
	m_Config.bGraphicMaskCloud		= false;
	m_Config.bGraphicMaskWater		= false;
	m_Config.bGraphicMaskTree		= false;
#endif

//1.3 Search for:
bool CPythonSystem::IsWindowed()
{
	return m_Config.bWindowed;
}
//1.3 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
bool CPythonSystem::GetGraphicMaskPart(const BYTE bPart)
{
	switch (bPart)
	{
		case CMapOutdoor::PART_TERRAIN:
			return m_Config.bGraphicMaskTerrain;
		case CMapOutdoor::PART_OBJECT:
			return m_Config.bGraphicMaskObject;
		case CMapOutdoor::PART_CLOUD:
			return m_Config.bGraphicMaskCloud;
		case CMapOutdoor::PART_WATER:
			return m_Config.bGraphicMaskWater;
		case CMapOutdoor::PART_TREE:
			return m_Config.bGraphicMaskTree;
	}
	
	return false;
}

void CPythonSystem::SetGraphicMaskPart(const BYTE bPart, const bool bFlag)
{
	switch (bPart)
	{
		case CMapOutdoor::PART_TERRAIN:
			m_Config.bGraphicMaskTerrain = bFlag;
			break;
		case CMapOutdoor::PART_OBJECT:
			m_Config.bGraphicMaskObject = bFlag;
			break;
		case CMapOutdoor::PART_CLOUD:
			m_Config.bGraphicMaskCloud = bFlag;
			break;
		case CMapOutdoor::PART_WATER:
			m_Config.bGraphicMaskWater = bFlag;
			break;
		case CMapOutdoor::PART_TREE:
			m_Config.bGraphicMaskTree = bFlag;
			break;
		default:
			break;
	}
}
#endif

//1.4 Search for:
		else if (!stricmp(command, "SHOW_SALESTEXT"))
			m_Config.bShowSalesText = atoi(value) == 1 ? true : false;
//1.4 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
		else if (!stricmp(command, "GRAPHIC_MASK_TERRAIN"))
			m_Config.bGraphicMaskTerrain = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "GRAPHIC_MASK_OBJECT"))
			m_Config.bGraphicMaskObject = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "GRAPHIC_MASK_CLOUD"))
			m_Config.bGraphicMaskCloud = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "GRAPHIC_MASK_WATER"))
			m_Config.bGraphicMaskWater = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "GRAPHIC_MASK_TREE"))
			m_Config.bGraphicMaskTree = atoi(value) == 1 ? true : false;
#endif

//1.5 Search for:
	if (m_Config.bShowSalesText == 0)
		fprintf(fp, "SHOW_SALESTEXT		%d\n", m_Config.bShowSalesText);
//1.5 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
	fprintf(fp, "GRAPHIC_MASK_TERRAIN		%d\n", m_Config.bGraphicMaskTerrain);
	fprintf(fp, "GRAPHIC_MASK_OBJECT		%d\n", m_Config.bGraphicMaskObject);
	fprintf(fp, "GRAPHIC_MASK_CLOUD		%d\n", m_Config.bGraphicMaskCloud);
	fprintf(fp, "GRAPHIC_MASK_WATER		%d\n", m_Config.bGraphicMaskWater);
	fprintf(fp, "GRAPHIC_MASK_TREE		%d\n", m_Config.bGraphicMaskTree);
#endif