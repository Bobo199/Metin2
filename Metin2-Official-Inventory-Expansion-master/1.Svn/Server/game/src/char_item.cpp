//Find
bool CHARACTER::IsEmptyItemGrid(TItemPos Cell, BYTE bSize, int iExceptionCell) const

///Change

bool CHARACTER::IsEmptyItemGrid(TItemPos Cell, BYTE bSize, int iExceptionCell) const
{
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	switch (Cell.window_type)
	{
	case INVENTORY:
		{
			BYTE bCell = Cell.cell;
			++iExceptionCell;

			if (Cell.IsBeltInventoryPosition())
			{
				LPITEM beltItem = GetWear(WEAR_BELT);
				if (NULL == beltItem)
					return false;
				if (false == CBeltInventoryHelper::IsAvailableCell(bCell - BELT_INVENTORY_SLOT_START, beltItem->GetValue(0)))
					return false;
				if (m_pointsInstant.bItemGrid[bCell]) {
					if (m_pointsInstant.bItemGrid[bCell] == iExceptionCell)
						return true;
					return false;
				}
				if (bSize == 1)
					return true;
			}
			//black
			else if (bCell >= Inventory_Size())
				return false;

			if (m_pointsInstant.bItemGrid[bCell]) {
				if (m_pointsInstant.bItemGrid[bCell] == iExceptionCell) {
					if (bSize == 1)
						return true;

					int j = 1;
					BYTE bPage = bCell / (INVENTORY_PAGE_SIZE);
					do {
						BYTE p = bCell + (5 * j);

						if (p >= Inventory_Size())
							return false;

						if (p / (INVENTORY_PAGE_SIZE) != bPage)
							return false;

						if (m_pointsInstant.bItemGrid[p])
							if (m_pointsInstant.bItemGrid[p] != iExceptionCell)
								return false;
					}
					while (++j < bSize);
					return true;
				} else
					return false;
			}
			if (1 == bSize)
				return true;
			else {
				int j = 1;
				BYTE bPage = bCell / (INVENTORY_PAGE_SIZE);

				do {
					BYTE p = bCell + (5 * j);

					if (p >= Inventory_Size())
						return false;
					if (p / (INVENTORY_PAGE_SIZE) != bPage)
						return false;

					if (m_pointsInstant.bItemGrid[p])
						if (m_pointsInstant.bItemGrid[p] != iExceptionCell)
							return false;
				} while (++j < bSize);
				return true;
			}
		} break;
#else
		switch (Cell.window_type)
		{
		case INVENTORY:
			{
				BYTE bCell = Cell.cell;

				// bItemCell은 0이 false임을 나타내기 위해 + 1 해서 처리한다.
				// 따라서 iExceptionCell에 1을 더해 비교한다.
				++iExceptionCell;

				if (Cell.IsBeltInventoryPosition())
				{
					LPITEM beltItem = GetWear(WEAR_BELT);

					if (NULL == beltItem)
						return false;

					if (false == CBeltInventoryHelper::IsAvailableCell(bCell - BELT_INVENTORY_SLOT_START, beltItem->GetValue(0)))
						return false;

					if (m_pointsInstant.bItemGrid[bCell])
					{
						if (m_pointsInstant.bItemGrid[bCell] == iExceptionCell)
							return true;

						return false;
					}

					if (bSize == 1)
						return true;

				}
				//black
				else if (bCell >= INVENTORY_MAX_NUM)
					return false;

				if (m_pointsInstant.bItemGrid[bCell])
				{
					if (m_pointsInstant.bItemGrid[bCell] == iExceptionCell)
					{
						if (bSize == 1)
							return true;

						int j = 1;
						BYTE bPage = bCell / (INVENTORY_MAX_NUM / 2);

						do
						{
							BYTE p = bCell + (5 * j);

							if (p >= INVENTORY_MAX_NUM)
								return false;

							if (p / (INVENTORY_MAX_NUM / 2) != bPage)
								return false;

							if (m_pointsInstant.bItemGrid[p])
								if (m_pointsInstant.bItemGrid[p] != iExceptionCell)
									return false;
						}
						while (++j < bSize);

						return true;
					}
					else
						return false;
				}

				// 크기가 1이면 한칸을 차지하는 것이므로 그냥 리턴
				if (1 == bSize)
					return true;
				else
				{
					int j = 1;
					BYTE bPage = bCell / (INVENTORY_MAX_NUM / 2);

					do
					{
						BYTE p = bCell + (5 * j);

						if (p >= INVENTORY_MAX_NUM)
							return false;
						if (p / (INVENTORY_MAX_NUM / 2) != bPage)
							return false;

						if (m_pointsInstant.bItemGrid[p])
							if (m_pointsInstant.bItemGrid[p] != iExceptionCell)
								return false;
					}
					while (++j < bSize);

					return true;
				}
			}
			break;
#endif
	case DRAGON_SOUL_INVENTORY:
		{
			WORD wCell = Cell.cell;
			if (wCell >= DRAGON_SOUL_INVENTORY_MAX_NUM)
				return false;

			// bItemCell은 0이 false임을 나타내기 위해 + 1 해서 처리한다.
			// 따라서 iExceptionCell에 1을 더해 비교한다.
			iExceptionCell++;

			if (m_pointsInstant.wDSItemGrid[wCell])
			{
				if (m_pointsInstant.wDSItemGrid[wCell] == iExceptionCell)
				{
					if (bSize == 1)
						return true;

					int j = 1;

					do
					{
						BYTE p = wCell + (DRAGON_SOUL_BOX_COLUMN_NUM * j);

						if (p >= DRAGON_SOUL_INVENTORY_MAX_NUM)
							return false;

						if (m_pointsInstant.wDSItemGrid[p])
							if (m_pointsInstant.wDSItemGrid[p] != iExceptionCell)
								return false;
					}
					while (++j < bSize);

					return true;
				}
				else
					return false;
			}

			// 크기가 1이면 한칸을 차지하는 것이므로 그냥 리턴
			if (1 == bSize)
				return true;
			else
			{
				int j = 1;

				do
				{
					BYTE p = wCell + (DRAGON_SOUL_BOX_COLUMN_NUM * j);

					if (p >= DRAGON_SOUL_INVENTORY_MAX_NUM)
						return false;

					if (m_pointsInstant.bItemGrid[p])
						if (m_pointsInstant.wDSItemGrid[p] != iExceptionCell)
							return false;
				}
				while (++j < bSize);

				return true;
			}
		}
	}
}

//Find
int CHARACTER::GetEmptyInventory(BYTE size) const

///Change like this
int CHARACTER::GetEmptyInventory(BYTE size) const
{
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	for ( int i = 0; i < Inventory_Size(); ++i)
#else
	for ( int i = 0; i < INVENTORY_MAX_NUM; ++i)	
#endif
		if (IsEmptyItemGrid(TItemPos (INVENTORY, i), size))
			return i;
	return -1;
}

//Find
int CHARACTER::CountEmptyInventory() const
{
	int	count = 0;

	for (int i = 0; i < INVENTORY_MAX_NUM; ++i)
		if (GetInventoryItem(i))
			count += GetInventoryItem(i)->GetSize();

	return (INVENTORY_MAX_NUM - count);
}

///Change
int CHARACTER::CountEmptyInventory() const
{
	int	count = 0;
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	for (int i = 0; i < Inventory_Size(); ++i)
#else
	for (int i = 0; i < INVENTORY_MAX_NUM; ++i)	
#endif
		if (GetInventoryItem(i))
			count += GetInventoryItem(i)->GetSize();

#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	return (Inventory_Size() - count);
#else
	return (INVENTORY_MAX_NUM - count);
#endif
}

//Find
LPITEM CHARACTER::FindSpecifyItem(DWORD vnum) const

///Change
LPITEM CHARACTER::FindSpecifyItem(DWORD vnum) const
{
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	for (int i = 0; i < Inventory_Size(); ++i)
#else
	for (int i = 0; i < INVENTORY_MAX_NUM; ++i)	
#endif
	if (GetInventoryItem(i) && GetInventoryItem(i)->GetVnum() == vnum)
		return GetInventoryItem(i);

	return NULL;
}

//Find
LPITEM CHARACTER::FindItemByID(DWORD id) const

///Change
LPITEM CHARACTER::FindItemByID(DWORD id) const
{
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	for (int i = 0; i < Inventory_Size(); ++i)
#else
	for (int i = 0; i < INVENTORY_MAX_NUM; ++i)	
#endif
	{
		if (NULL != GetInventoryItem(i) && GetInventoryItem(i)->GetID() == id)
			return GetInventoryItem(i);
	}

	for (int i=BELT_INVENTORY_SLOT_START; i < BELT_INVENTORY_SLOT_END ; ++i)
	{
		if (NULL != GetInventoryItem(i) && GetInventoryItem(i)->GetID() == id)
			return GetInventoryItem(i);
	}

	return NULL;
}

//Find
int CHARACTER::CountSpecifyItem(DWORD vnum) const

///Change
int CHARACTER::CountSpecifyItem(DWORD vnum) const
{
	int	count = 0;
	LPITEM item;
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	for (int i = 0; i < Inventory_Size(); ++i)
#else
	for (int i = 0; i < INVENTORY_MAX_NUM; ++i)	
#endif
	{
		item = GetInventoryItem(i);
		if (NULL != item && item->GetVnum() == vnum)
		{
			// 개인 상점에 등록된 물건이면 넘어간다.
			if (m_pkMyShop && m_pkMyShop->IsSellingItem(item->GetID()))
			{
				continue;
			}
			else
			{
				count += item->GetCount();
			}
		}
	}

	return count;
}

//Find
void CHARACTER::RemoveSpecifyItem(DWORD vnum, DWORD count)

///Change
void CHARACTER::RemoveSpecifyItem(DWORD vnum, DWORD count)
{
	if (0 == count)
		return;

#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	for (UINT i = 0; i < Inventory_Size(); ++i)
#else
	for (UINT i = 0; i < INVENTORY_MAX_NUM; ++i)
#endif
	{
		if (NULL == GetInventoryItem(i))
			continue;

		if (GetInventoryItem(i)->GetVnum() != vnum)
			continue;

		//개인 상점에 등록된 물건이면 넘어간다. (개인 상점에서 판매될때 이 부분으로 들어올 경우 문제!)
		if(m_pkMyShop)
		{
			bool isItemSelling = m_pkMyShop->IsSellingItem(GetInventoryItem(i)->GetID());
			if (isItemSelling)
				continue;
		}

		if (vnum >= 80003 && vnum <= 80007)
			LogManager::instance().GoldBarLog(GetPlayerID(), GetInventoryItem(i)->GetID(), QUEST, "RemoveSpecifyItem");

		if (count >= GetInventoryItem(i)->GetCount())
		{
			count -= GetInventoryItem(i)->GetCount();
			GetInventoryItem(i)->SetCount(0);

			if (0 == count)
				return;
		}
		else
		{
			GetInventoryItem(i)->SetCount(GetInventoryItem(i)->GetCount() - count);
			return;
		}
	}

	// 예외처리가 약하다.
	if (count)
		sys_log(0, "CHARACTER::RemoveSpecifyItem cannot remove enough item vnum %u, still remain %d", vnum, count);
}

//Find
int CHARACTER::CountSpecifyTypeItem(BYTE type) const

///Change
int CHARACTER::CountSpecifyTypeItem(BYTE type) const
{
	int	count = 0;
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	for (UINT i = 0; i < Inventory_Size(); ++i)
#else
	for (UINT i = 0; i < INVENTORY_MAX_NUM; ++i)
#endif
	{
		LPITEM pItem = GetInventoryItem(i);
		if (pItem != NULL && pItem->GetType() == type)
		{
			count += pItem->GetCount();
		}
	}

	return count;
}

//Find
void CHARACTER::RemoveSpecifyTypeItem(BYTE type, DWORD count)

///Change
void CHARACTER::RemoveSpecifyTypeItem(BYTE type, DWORD count)
{
	if (0 == count)
		return;

#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	for (UINT i = 0; i < Inventory_Size(); ++i)
#else
	for (UINT i = 0; i < INVENTORY_MAX_NUM; ++i)
#endif
	{
		if (NULL == GetInventoryItem(i))
			continue;

		if (GetInventoryItem(i)->GetType() != type)
			continue;

		//개인 상점에 등록된 물건이면 넘어간다. (개인 상점에서 판매될때 이 부분으로 들어올 경우 문제!)
		if(m_pkMyShop)
		{
			bool isItemSelling = m_pkMyShop->IsSellingItem(GetInventoryItem(i)->GetID());
			if (isItemSelling)
				continue;
		}

		if (count >= GetInventoryItem(i)->GetCount())
		{
			count -= GetInventoryItem(i)->GetCount();
			GetInventoryItem(i)->SetCount(0);

			if (0 == count)
				return;
		}
		else
		{
			GetInventoryItem(i)->SetCount(GetInventoryItem(i)->GetCount() - count);
			return;
		}
	}
}