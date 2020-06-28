// Search

void CPythonSystem::SetDefaultConfig()
{

// Add after

	m_Config.bPickupFilterWeapon = false;
	m_Config.bPickupFilterArmor = false;
	m_Config.bPickupFilterEar = false;
	m_Config.bPickupFilterNeck = false;
	m_Config.bPickupFilterFoots = false;
	m_Config.bPickupFilterShield = false;
	m_Config.bPickupFilterBook = false;
	m_Config.bPickupFilterStone = false;
	m_Config.bPickupFilterEtc = false;
  
 // Search
 
 void CPythonSystem::SetShowSalesTextFlag(int iFlag)
{
	m_Config.bShowSalesText = iFlag == 1 ? true : false;
}

// Add after

//Weapon
bool CPythonSystem::IsPickUpFilterWeapon()
{
	return m_Config.bPickupFilterWeapon;
}
void CPythonSystem::SetPickUpFilterWeaponFlag(int iFlag)
{
	m_Config.bPickupFilterWeapon = iFlag == 1 ? true : false;
	//TraceError("Weapon %d", iFlag);
}
//Armor
bool CPythonSystem::IsPickUpFilterArmor()
{
	return m_Config.bPickupFilterArmor;
}
void CPythonSystem::SetPickUpFilterArmorFlag(int iFlag)
{
	m_Config.bPickupFilterArmor = iFlag == 1 ? true : false;
	//TraceError("Armor %d", iFlag);
}
//Ear
bool CPythonSystem::IsPickUpFilterEar()
{
	return m_Config.bPickupFilterEar;
}
void CPythonSystem::SetPickUpFilterEarFlag(int iFlag)
{
	m_Config.bPickupFilterEar = iFlag == 1 ? true : false;
	//TraceError("Ear %d", iFlag);
}
//Neck
bool CPythonSystem::IsPickUpFilterNeck()
{
	return m_Config.bPickupFilterNeck;
}
void CPythonSystem::SetPickUpFilterNeckFlag(int iFlag)
{
	m_Config.bPickupFilterNeck = iFlag == 1 ? true : false;
	//TraceError("Neck %d", iFlag);
}
//Foots
bool CPythonSystem::IsPickUpFilterFoots()
{
	return m_Config.bPickupFilterFoots;
}
void CPythonSystem::SetPickUpFilterFootsFlag(int iFlag)
{
	m_Config.bPickupFilterFoots = iFlag == 1 ? true : false;
	//TraceError("Foots %d", iFlag);
}
//Shield
bool CPythonSystem::IsPickUpFilterShield()
{
	return m_Config.bPickupFilterShield;
}
void CPythonSystem::SetPickUpFilterShieldFlag(int iFlag)
{
	m_Config.bPickupFilterShield = iFlag == 1 ? true : false;
	//TraceError("Shield %d", iFlag);
}
//Book
bool CPythonSystem::IsPickUpFilterBook()
{
	return m_Config.bPickupFilterBook;
}
void CPythonSystem::SetPickUpFilterBookFlag(int iFlag)
{
	m_Config.bPickupFilterBook = iFlag == 1 ? true : false;
	//TraceError("Book %d", iFlag);
}
//Stone
bool CPythonSystem::IsPickUpFilterStone()
{
	return m_Config.bPickupFilterStone;
}
void CPythonSystem::SetPickUpFilterStoneFlag(int iFlag)
{
	m_Config.bPickupFilterStone = iFlag == 1 ? true : false;
	//TraceError("Stone %d", iFlag);
}
//Etc
bool CPythonSystem::IsPickUpFilterEtc()
{
	return m_Config.bPickupFilterEtc;
}
void CPythonSystem::SetPickUpFilterEtcFlag(int iFlag)
{
	m_Config.bPickupFilterEtc = iFlag == 1 ? true : false;
	//TraceError("Etc %d", iFlag);
}

// Search

		else if (!stricmp(command, "SHOW_SALESTEXT"))
			m_Config.bShowSalesText = atoi(value) == 1 ? true : false;
      
 // Add after
 
 		else if (!stricmp(command, "PICKUP_FILTER_WEAPON"))
			m_Config.bPickupFilterWeapon = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "PICKUP_FILTER_ARMOR"))
			m_Config.bPickupFilterArmor = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "PICKUP_FILTER_EAR"))
			m_Config.bPickupFilterEar = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "PICKUP_FILTER_NECK"))
			m_Config.bPickupFilterNeck = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "PICKUP_FILTER_FOOTS"))
			m_Config.bPickupFilterFoots = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "PICKUP_FILTER_SHIELD"))
			m_Config.bPickupFilterShield = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "PICKUP_FILTER_BOOK"))
			m_Config.bPickupFilterBook = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "PICKUP_FILTER_STONE"))
			m_Config.bPickupFilterStone = atoi(value) == 1 ? true : false;
		else if (!stricmp(command, "PICKUP_FILTER_ETC"))
			m_Config.bPickupFilterEtc = atoi(value) == 1 ? true : false;
      
 // Search
 
 	if (m_Config.bShowSalesText == 0)
		fprintf(fp, "SHOW_SALESTEXT		%d\n", m_Config.bShowSalesText);
    
 // Add after
 
	if (m_Config.bPickupFilterWeapon == 0)
		fprintf(fp, "PICKUP_FILTER_WEAPON		%d\n", m_Config.bPickupFilterWeapon);
	if (m_Config.bPickupFilterArmor == 0)
		fprintf(fp, "PICKUP_FILTER_ARMOR		%d\n", m_Config.bPickupFilterArmor);
	if (m_Config.bPickupFilterEar == 0)
		fprintf(fp, "PICKUP_FILTER_EAR		%d\n", m_Config.bPickupFilterEar);
	if (m_Config.bPickupFilterNeck == 0)
		fprintf(fp, "PICKUP_FILTER_NECK		%d\n", m_Config.bPickupFilterNeck);
	if (m_Config.bPickupFilterFoots == 0)
		fprintf(fp, "PICKUP_FILTER_FOOTS		%d\n", m_Config.bPickupFilterFoots);
	if (m_Config.bPickupFilterShield == 0)
		fprintf(fp, "PICKUP_FILTER_SHIELD		%d\n", m_Config.bPickupFilterShield);
	if (m_Config.bPickupFilterStone == 0)
		fprintf(fp, "PICKUP_FILTER_STONE		%d\n", m_Config.bPickupFilterStone);
	if (m_Config.bPickupFilterEtc == 0)
		fprintf(fp, "PICKUP_FILTER_ETC		%d\n", m_Config.bPickupFilterEtc);
