//Find
		if (!pItemGroup->GetValue(i, "price", shopItems[i].price))
		{
			sys_err("row(%d) of group items of group %s does not have price column", i, pNode->GetNodeName().c_str());
			return false;
		}
		
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
		if (shopItems[i].price_type >= EX_MAX || shopItems[i].price_type < EX_GOLD) {
			sys_err("row(%d) of group items of group %s price_type is wrong!", i, pNode->GetNodeName().c_str());
			return false;
		}
		char getval[20];
		for (int j = 0; j < ITEM_SOCKET_MAX_NUM; j++) {
			snprintf(getval, sizeof(getval), "socket%d", j);
			if (!pItemGroup->GetValue(i, getval, shopItems[i].alSockets[j])) {
				sys_err("row(%d) stage %d of group items of group %s does not have socket column", i, j, pNode->GetNodeName().c_str());
				return false;
			}
		}
		for (int j = 0; j < ITEM_ATTRIBUTE_MAX_NUM; j++) {
			snprintf(getval, sizeof(getval), "attr_type%d", j);
			if (!pItemGroup->GetValue(i, getval, shopItems[i].aAttr[j].bType)) {
				sys_err("row(%d) stage %d of group items of group %s does not have attr_type column", i, j, pNode->GetNodeName().c_str());
				return false;
			}
			snprintf(getval, sizeof(getval), "attr_value%d", j);
			if (!pItemGroup->GetValue(i, getval, shopItems[i].aAttr[j].sValue)) {
				sys_err("row(%d) stage %d of group items of group %s does not have attr_value column", i, j, pNode->GetNodeName().c_str());
				return false;
			}
		}
		if (pItemGroup->GetValue(i, "price_type", shopItems[i].price_type) && pItemGroup->GetValue(i, "price_vnum", shopItems[i].price_vnum) && shopItems[i].price_type == 3) {
			if (!ITEM_MANAGER::instance().GetTable(shopItems[i].price_vnum)) {
				sys_err("NOT GET ITEM PROTO %d", shopItems[i].price_vnum);
				return false;
			}
		}
#endif

//Find
	if (boost::iequals(stSort, "Asc"))
	{
		std::sort(shopItems.begin(), shopItems.end(), CompareShopItemName);
	}
	else if(boost::iequals(stSort, "Desc"))
	{
		std::sort(shopItems.rbegin(), shopItems.rend(), CompareShopItemName);
	}
	
///Add

#ifdef ENABLE_RENEWAL_SHOPEX
	else {
		std::sort(shopItems.begin(), shopItems.end(), [&stSort](const TShopItemTable& i1, const TShopItemTable& i2) {
			const auto lItem = ITEM_MANAGER::instance().GetTable(i1.vnum);
			const auto rItem = ITEM_MANAGER::instance().GetTable(i2.vnum);
			if (!stSort.compare("Vnum"))
				return i1.vnum > i2.vnum;
			else if (!stSort.compare("Price"))
				return i1.price > i2.price;
			else if (!stSort.compare("Name") && lItem && rItem)
				return strcmp(lItem->szLocaleName, rItem->szLocaleName) < 0;
			else if (!stSort.compare("Type") && lItem && rItem)
				return lItem->bType > rItem->bType;
			return i1.vnum > i2.vnum;
		});
	}
#endif

//Find
	TMapNPCshop map_npcShop;
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	{
		std::unordered_set<CShop*> v;
		// include unordered_set
		auto ExDelete = [&v](TShopMap& c) {
			for (auto it = c.begin(); !c.empty() && it != c.end();) {
				const auto shop = it->second;
				if (shop && shop->IsShopEx()) {
					it = c.erase(it);
					v.insert(shop);
				}
				else
					++it;
			}
		};
		ExDelete(m_map_pkShopByNPCVnum);
		ExDelete(m_map_pkShop);
		for (const auto& del : v)
			delete del;
	}
#endif

//Find
		if (pkShopEx->GetVnum() != 0 && m_map_pkShop.find(pkShopEx->GetVnum()) != m_map_pkShop.end())
		{
			sys_err("Shop vnum(%d) already exist.", pkShopEx->GetVnum());
			return false;
		}
		m_map_pkShop.insert(TShopMap::value_type(pkShopEx->GetVnum(), pkShopEx));

///Change
		if (m_map_pkShop.find(table.dwVnum) != m_map_pkShop.end())
		{
			sys_err("Shop vnum(%d) already exist.", table.dwVnum);
			return false;
		}
		m_map_pkShop.insert(TShopMap::value_type(table.dwVnum, pkShopEx));

//Find
void CShopManager::Destroy()
{
	TShopMap::iterator it = m_map_pkShop.begin();
	while (it != m_map_pkShop.end())
	{
		delete it->second;
		++it;
	}

	m_map_pkShop.clear();
}

///Change
void CShopManager::Destroy()
{
	for (auto it = m_map_pkShopByNPCVnum.begin(); it != m_map_pkShopByNPCVnum.end(); ++it)
		delete it->second;
	m_map_pkShopByNPCVnum.clear();
	m_map_pkShop.clear();
}
