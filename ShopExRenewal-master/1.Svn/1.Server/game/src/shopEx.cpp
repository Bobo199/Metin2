//Find
			memset(pack_tab.items[i].aAttr, 0, sizeof(pack_tab.items[i].aAttr));
			memset(pack_tab.items[i].alSockets, 0, sizeof(pack_tab.items[i].alSockets));
			
///Change
#ifdef ENABLE_RENEWAL_SHOPEX
			pack_tab.items[i].price_type = shop_tab.items[i].price_type;
			pack_tab.items[i].price_vnum = shop_tab.items[i].price_vnum;
			thecore_memcpy(pack_tab.items[i].aAttr, shop_tab.items[i].aAttr, sizeof(pack_tab.items[i].aAttr));
			thecore_memcpy(pack_tab.items[i].alSockets, shop_tab.items[i].alSockets, sizeof(pack_tab.items[i].alSockets));
#else
			memset(pack_tab.items[i].aAttr, 0, sizeof(pack_tab.items[i].aAttr));
			memset(pack_tab.items[i].alSockets, 0, sizeof(pack_tab.items[i].alSockets));
#endif

//Find
	switch (shopTab.coinType)
	{
		case SHOP_COIN_TYPE_GOLD:
			if (it->second)
				dwPrice *= 3;

			if (ch->GetGold() < (int) dwPrice)
			{
				sys_log(1, "ShopEx::Buy : Not enough money : %s has %d, price %d", ch->GetName(), ch->GetGold(), dwPrice);
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
			}
			break;
		case SHOP_COIN_TYPE_SECONDARY_COIN:
			{
				int count = ch->CountSpecifyTypeItem(ITEM_SECONDARY_COIN);
				if (count < dwPrice)
				{
					sys_log(1, "ShopEx::Buy : Not enough myeongdojun : %s has %d, price %d", ch->GetName(), count, dwPrice);
					return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX;
				}
			}
			break;
	}
	
///Change
#ifndef ENABLE_RENEWAL_SHOPEX	
	switch (shopTab.coinType)
	{
	case SHOP_COIN_TYPE_GOLD:
		if (it->second)
			dwPrice *= 3;

		if (ch->GetGold() < (int)dwPrice)
		{
			sys_log(1, "ShopEx::Buy : Not enough money : %s has %d, price %d", ch->GetName(), ch->GetGold(), dwPrice);
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
		}
		break;
	case SHOP_COIN_TYPE_SECONDARY_COIN:
	{
		int count = ch->CountSpecifyTypeItem(ITEM_SECONDARY_COIN);
		if (count < dwPrice)
		{
			sys_log(1, "ShopEx::Buy : Not enough myeongdojun : %s has %d, price %d", ch->GetName(), count, dwPrice);
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX;
		}
	}
	break;
	}
#else
	switch (r_item.price_type)
	{
	case EX_GOLD:
		if (static_cast<decltype(dwPrice)>(ch->GetGold()) < (it->second ? dwPrice * 3 : dwPrice))
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
	break;
	case EX_SECONDARY:
		if (static_cast<decltype(dwPrice)>(ch->CountSpecifyTypeItem(ITEM_SECONDARY_COIN)) < dwPrice)
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX;
	break;
	case EX_ITEM:
		if (static_cast<decltype(dwPrice)>(ch->CountSpecifyItem(r_item.price_vnum)) < dwPrice)
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM;
	break;
	case EX_EXP:
		if (ch->GetExp() < dwPrice)
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_EXP;
	}
#endif

//Find
	switch (shopTab.coinType)
	{
		case SHOP_COIN_TYPE_GOLD:
			ch->PointChange(POINT_GOLD, -dwPrice, false);
			break;
		case SHOP_COIN_TYPE_SECONDARY_COIN:
			ch->RemoveSpecifyTypeItem(ITEM_SECONDARY_COIN, dwPrice);
			break;
	}
	
///Change
#ifdef ENABLE_RENEWAL_SHOPEX
	switch (r_item.price_type)
	{
	case EX_GOLD:
		ch->PointChange(POINT_GOLD, -static_cast<int>(dwPrice), false);
		break;
	case EX_SECONDARY:
		ch->RemoveSpecifyTypeItem(ITEM_SECONDARY_COIN, dwPrice);
		break;
	case EX_ITEM:
		ch->RemoveSpecifyItem(r_item.price_vnum, dwPrice);
		break;
	case EX_EXP:
		ch->PointChange(POINT_EXP, -static_cast<int>(dwPrice), false);
	}
	if (!std::all_of(std::begin(r_item.aAttr), std::end(r_item.aAttr), [](const TPlayerItemAttribute& s) { return !s.bType; }))
		item->SetAttributes(r_item.aAttr);
	if (!std::all_of(std::begin(r_item.alSockets), std::end(r_item.alSockets), [](const long& s) { return !s; }))
		item->SetSockets(r_item.alSockets);
#else
	switch (shopTab.coinType)
	{
	case SHOP_COIN_TYPE_GOLD:
		ch->PointChange(POINT_GOLD, -dwPrice, false);
		break;
	case SHOP_COIN_TYPE_SECONDARY_COIN:
		ch->RemoveSpecifyTypeItem(ITEM_SECONDARY_COIN, dwPrice);
		break;
	}
#endif