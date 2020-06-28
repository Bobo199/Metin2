//Find
	Set(HEADER_CG_ITEM_MOVE, sizeof(TPacketCGItemMove), "ItemMove", true);

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	Set(ENVANTER_BLACK, sizeof(TPacketCGEnvanter), "InventoryExpansion", true);
#endif