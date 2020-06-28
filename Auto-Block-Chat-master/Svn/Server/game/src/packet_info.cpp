//Find
Set(HEADER_CG_ITEM_USE, sizeof(TPacketCGItemUse), "ItemUse", true);

///Add
#ifdef ENABLE_CHECK_INSULT
	Set(HEADER_CG_INSULT_BLOCK, sizeof(TPacketCGChatInsult), "BLOCK_INSULT", true);
#endif