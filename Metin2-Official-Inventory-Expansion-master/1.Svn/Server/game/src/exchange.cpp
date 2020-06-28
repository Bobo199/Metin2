//Find
bool CExchange::CheckSpace()
{
	....
}
///Change
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
bool CExchange::CheckSpace()
{	
	std::array<std::unique_ptr<CGrid>, static_cast<const int>(INVENTORY_PAGE_COUNT)> s_grid;
	static std::vector <WORD> s_vDSGrid(DRAGON_SOUL_INVENTORY_MAX_NUM);
	LPITEM item;
	bool bDSInitialized = false;
	int new_size, invenpoint = GetCompany()->GetOwner()->Inven_Point();

	for (size_t i = 0; i < s_grid.size(); i++) {
		if (i < INVENTORY_OPEN_PAGE_COUNT) {
			s_grid[i] = std::make_unique<CGrid>(INVENTORY_WIDTH,INVENTORY_HEIGHT);
			continue;
		}
		if (invenpoint > 0 && invenpoint <= INVENTORY_HEIGHT)
			new_size = invenpoint;
		else if (invenpoint >= INVENTORY_HEIGHT)
			new_size = INVENTORY_HEIGHT;
		else
			new_size = 0;
		s_grid[i] = std::make_unique<CGrid>(INVENTORY_WIDTH,new_size);
		invenpoint -= INVENTORY_HEIGHT;
	}
	for (size_t j = 0; j < s_grid.size(); j++) {
		s_grid[j]->Clear();
		for (auto i = INVENTORY_PAGE_SIZE * j; i < INVENTORY_PAGE_SIZE * (j+1); ++i) 
		{
			if (!(item = GetCompany()->GetOwner()->GetInventoryItem(i))) 
				continue;
			s_grid[j]->Put(i - INVENTORY_PAGE_SIZE * j, 1, item->GetSize());
		}
	}
	for (auto i = 0; i < EXCHANGE_ITEM_MAX_NUM; ++i) 
	{
		if (!(item = m_apItems[i])) 
			continue;
		if (item->IsDragonSoul()) 
		{
			if (!GetCompany()->GetOwner()->DragonSoul_IsQualified()) 
				return false;
			if (!bDSInitialized) 
			{
				bDSInitialized = true;
				GetCompany()->GetOwner()->CopyDragonSoulItemGrid(s_vDSGrid);
			}
			bool bExistEmptySpace = false;
			WORD wBasePos = DSManager::instance().GetBasePosition(item);
			if (wBasePos >= DRAGON_SOUL_INVENTORY_MAX_NUM) 
				return false;
			for (int i = 0; i < DRAGON_SOUL_BOX_SIZE; i++) {
				WORD wPos = wBasePos + i;
				if (0 == s_vDSGrid[wBasePos]) 
				{
					bool bEmpty = true;
					for (int j = 1; j < item->GetSize(); j++)	
					{
						if (s_vDSGrid[wPos + j * DRAGON_SOUL_BOX_COLUMN_NUM]) 
						{
							bEmpty = false;
							break;
						}
					} 
					if (bEmpty)	
					{
						for (int j = 0; j < item->GetSize(); j++)
							s_vDSGrid[wPos + j * DRAGON_SOUL_BOX_COLUMN_NUM] =  wPos + 1;
						bExistEmptySpace = true;
						break;
					}
				}
				if (bExistEmptySpace) 
					break;
            } 
			if (!bExistEmptySpace) 
				return false;
		}
		else 
		{
			bool existspace = false;
			for (size_t i = 0; i < s_grid.size(); i++) 
			{
				const auto& iPos = s_grid[i]->FindBlank(1, item->GetSize());
				if (iPos >= 0) {
					s_grid[i]->Put(iPos, 1, item->GetSize());
					existspace = true;
					break;
				}
			}
			if (!existspace)
				return false;
		}
	}
	return true;
}
#else
bool CExchange::CheckSpace()
{
	static CGrid s_grid1(5, INVENTORY_MAX_NUM/5 / 2); // inven page 1
	static CGrid s_grid2(5, INVENTORY_MAX_NUM/5 / 2); // inven page 2

	s_grid1.Clear();
	s_grid2.Clear();

	LPCHARACTER	victim = GetCompany()->GetOwner();
	LPITEM item;

	int i;

	for (i = 0; i < INVENTORY_MAX_NUM / 2; ++i)
	{
		if (!(item = victim->GetInventoryItem(i)))
			continue;

		s_grid1.Put(i, 1, item->GetSize());
	}
	for (i = INVENTORY_MAX_NUM / 2; i < INVENTORY_MAX_NUM; ++i)
	{
		if (!(item = victim->GetInventoryItem(i)))
			continue;

		s_grid2.Put(i - INVENTORY_MAX_NUM / 2, 1, item->GetSize());
	}

	// 아... 뭔가 개병신 같지만... 용혼석 인벤을 노멀 인벤 보고 따라 만든 내 잘못이다 ㅠㅠ
	static std::vector <WORD> s_vDSGrid(DRAGON_SOUL_INVENTORY_MAX_NUM);
	
	// 일단 용혼석을 교환하지 않을 가능성이 크므로, 용혼석 인벤 복사는 용혼석이 있을 때 하도록 한다.
	bool bDSInitialized = false;
	
	for (i = 0; i < EXCHANGE_ITEM_MAX_NUM; ++i)
	{
		if (!(item = m_apItems[i]))
			continue;

		if (item->IsDragonSoul())
		{
			if (!victim->DragonSoul_IsQualified())
			{
				return false;
			}

			if (!bDSInitialized)
			{
				bDSInitialized = true;
				victim->CopyDragonSoulItemGrid(s_vDSGrid);
			}

			bool bExistEmptySpace = false;
			WORD wBasePos = DSManager::instance().GetBasePosition(item);
			if (wBasePos >= DRAGON_SOUL_INVENTORY_MAX_NUM)
				return false;
			
			for (int i = 0; i < DRAGON_SOUL_BOX_SIZE; i++)
			{
				WORD wPos = wBasePos + i;
				if (0 == s_vDSGrid[wBasePos])
				{
					bool bEmpty = true;
					for (int j = 1; j < item->GetSize(); j++)
					{
						if (s_vDSGrid[wPos + j * DRAGON_SOUL_BOX_COLUMN_NUM])
						{
							bEmpty = false;
							break;
						}
					}
					if (bEmpty)
					{
						for (int j = 0; j < item->GetSize(); j++)
						{
							s_vDSGrid[wPos + j * DRAGON_SOUL_BOX_COLUMN_NUM] =  wPos + 1;
						}
						bExistEmptySpace = true;
						break;
					}
				}
				if (bExistEmptySpace)
					break;
			}
			if (!bExistEmptySpace)
				return false;
		}
		else
		{
			int iPos = s_grid1.FindBlank(1, item->GetSize());

			if (iPos >= 0)
			{
				s_grid1.Put(iPos, 1, item->GetSize());
			}
			else
			{
				iPos = s_grid2.FindBlank(1, item->GetSize());

				if (iPos >= 0)
				{
					s_grid2.Put(iPos, 1, item->GetSize());
				}
				else
				{
					return false;
				}
			}
		}
	}

	return true;
}	
#endif
