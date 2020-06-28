//Find in void CHARACTER::Initialize()

	m_pkMyShop		= NULL;
	
///Add

	m_bValidPos = true;
	
//Find in void CHARACTER::OpenMyShop(const char * c_pszSign, TShopItemTable * pTable, BYTE bItemCount)
	
	if (bItemCount == 0)
		return;
	
///Add
	LPSECTREE sectree = GetSectree();
	if (sectree)
	{
		CheckValidPos f(this, "shop", 200);
		sectree->ForEachAround(f);

		if(!GetCheckValidPos())
		{
			ChatPacket(CHAT_TYPE_INFO, "You cannot open a shop here (too close to other shop).");
			return;
		}

		if (!sectree->IsAttr(GetX(), GetY(), ATTR_BANPK))
		{
			ChatPacket(CHAT_TYPE_INFO, "You cannot open a shop here (use safezone).");
			return;
		}
	}