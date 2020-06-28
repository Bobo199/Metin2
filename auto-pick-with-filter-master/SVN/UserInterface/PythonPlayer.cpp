// Search 

void CPythonPlayer::SendClickItemPacket(DWORD dwIID)

// Replace with

void CPythonPlayer::SendClickItemPacket(DWORD dwIID)
{

	if (IsObserverMode())
		return;
		
	const char * c_szOwnerName;
	CItemData * pItemData;
	if (!CPythonItem::Instance().GetOwnership(dwIID, &c_szOwnerName))
		return;
	if (strlen(c_szOwnerName) > 0)
	if (0 != strcmp(c_szOwnerName, GetName()))
	{
		
		if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData))
		{
			Tracenf("CPythonPlayer::SendClickItemPacket(dwIID=%d) : Non-exist item.", dwIID);
			return;
		}
		
		if (!IsPartyMemberByName(c_szOwnerName) || pItemData->IsAntiFlag(CItemData::ITEM_ANTIFLAG_DROP | CItemData::ITEM_ANTIFLAG_GIVE))
		{
			PyCallClassMemberFunc(m_ppyGameWindow, "OnCannotPickItem", Py_BuildValue("()"));
			return;
		}
	}
	if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData))
	{
		Tracenf("CPythonPlayer::SendClickItemPacket(dwIID=%d) : Non-exist item.", dwIID);
		return;
	}
	CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();
	if (CPythonSystem::Instance().IsPickUpFilterWeapon())
		if (pItemData->IsWearableFlag(CItemData::WEARABLE_WEAPON))
			rkNetStream.SendItemPickUpPacket(dwIID);
	if (CPythonSystem::Instance().IsPickUpFilterArmor())
		if (pItemData->IsWearableFlag(CItemData::WEARABLE_BODY))
			rkNetStream.SendItemPickUpPacket(dwIID);
	if (CPythonSystem::Instance().IsPickUpFilterEar())
		if (pItemData->IsWearableFlag(CItemData::WEARABLE_EAR))
			rkNetStream.SendItemPickUpPacket(dwIID);
	if (CPythonSystem::Instance().IsPickUpFilterNeck())
		if (pItemData->IsWearableFlag(CItemData::WEARABLE_NECK))
			rkNetStream.SendItemPickUpPacket(dwIID);
	if (CPythonSystem::Instance().IsPickUpFilterFoots())
		if (pItemData->IsWearableFlag(CItemData::WEARABLE_FOOTS))
			rkNetStream.SendItemPickUpPacket(dwIID);
	if (CPythonSystem::Instance().IsPickUpFilterShield())
		if (pItemData->IsWearableFlag(CItemData::WEARABLE_SHIELD))
			rkNetStream.SendItemPickUpPacket(dwIID);
	if (CPythonSystem::Instance().IsPickUpFilterBook())
		if (pItemData->GetType() == CItemData::ITEM_TYPE_SKILLBOOK)
			rkNetStream.SendItemPickUpPacket(dwIID);
	if (CPythonSystem::Instance().IsPickUpFilterStone())
		if (pItemData->GetType() == CItemData::ITEM_TYPE_METIN)
			rkNetStream.SendItemPickUpPacket(dwIID);
	if (CPythonSystem::Instance().IsPickUpFilterEtc())
			rkNetStream.SendItemPickUpPacket(dwIID);
	if (!CPythonSystem::Instance().IsPickUpFilterWeapon() && !CPythonSystem::Instance().IsPickUpFilterArmor() && !CPythonSystem::Instance().IsPickUpFilterEar()
		&& !CPythonSystem::Instance().IsPickUpFilterNeck() && !CPythonSystem::Instance().IsPickUpFilterFoots() &&
		!CPythonSystem::Instance().IsPickUpFilterShield() && !CPythonSystem::Instance().IsPickUpFilterBook() &&
		!CPythonSystem::Instance().IsPickUpFilterStone())
		rkNetStream.SendItemPickUpPacket(dwIID);
}

