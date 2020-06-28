//Find
		CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
		rkNetStream.SendItemPickUpPacket(dwIID);
		
///Add before
		CItemData* pItemData;
		if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData))
			return;

		std::string base = "sound/ui/";
		switch (pItemData->GetType()) {
		case CItemData::ITEM_TYPE_ELK:
			base += "money.wav";
			break;
		case CItemData::ITEM_TYPE_WEAPON:
			base += "bracelet.wav";
			break;
		case CItemData::ITEM_TYPE_ARMOR:
			base += "pickup_item_in_inventory.wav";
			break;
		default:
			base += "close.wav";
		}
		CSoundManager::Instance().PlaySound2D(base.c_str());
		
		/*
		//For subtypes
		CItemData* pItemData;
		if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData))
			return;
		 // -1: all subtypes
		 // don't forget to add #include <tuple>
		static const std::vector<std::tuple<BYTE, BYTE, std::string>> pickup {
			{ CItemData::ITEM_TYPE_ELK, -1, "money.wav" },
			{ CItemData::ITEM_TYPE_WEAPON, -1, "pickup_item_in_inventory.wav" },
			{ CItemData::ITEM_TYPE_ARMOR, CItemData::ARMOR_BODY, "bracelet.wav" },
			{ CItemData::ITEM_TYPE_ARMOR, CItemData::ARMOR_SHIELD, "drop.wav" },
			{ CItemData::ITEM_TYPE_ARMOR, -1, "itemget.wav" }, // rest
		};
		std::string base = "sound/ui/";
		const decltype(pickup)::const_iterator it = std::find_if(pickup.begin(), pickup.end(), [&pItemData](const std::tuple<BYTE, BYTE, std::string>& t) { return pItemData->GetType() == std::get<0>(t) && (pItemData->GetSubType() == std::get<1>(t) || static_cast<BYTE>(-1) == std::get<1>(t));});
		base += it != pickup.end() ? std::get<2>(*it) : "close.wav";
		CSoundManager::Instance().PlaySound2D(base.c_str());
		*/
