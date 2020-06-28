//Find
	Set(HEADER_CG_ITEM_MOVE, sizeof(TPacketCGItemMove), "ItemMove", true);
	
///Add
#ifdef ENABLE_SORT_INVEN
	Set(SORT_INVEN, sizeof(TPacketCGSortInven), "InventorySort", true);
#endif