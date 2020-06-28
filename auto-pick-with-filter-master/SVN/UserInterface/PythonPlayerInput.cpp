// If you don't have a some autopickup Replace 

void CPythonPlayer::PickCloseItem()

// With:

void CPythonPlayer::PickCloseItem()
{
	CInstanceBase * pkInstMain = NEW_GetMainActorPtr();
	if (!pkInstMain)
		return;

	TPixelPosition kPPosMain;
	pkInstMain->NEW_GetPixelPosition(&kPPosMain);

	std::vector<DWORD> itemVidList;
	
	CPythonItem& rkItem=CPythonItem::Instance();
	if (!rkItem.GetCloseItemVector(pkInstMain->GetNameString(), kPPosMain, itemVidList))
		return;
	
	if(itemVidList.empty())
		return;
	
	for (int i = 0; i < itemVidList.size(); i++)
		SendClickItemPacket(itemVidList[i]);
    
 }
