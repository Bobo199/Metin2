//Find
	SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX,
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM,
	SHOP_SUBHEADER_GC_NOT_ENOUGH_EXP,
#endif

//Find in : packet_shop_item
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	DWORD 	price_type = 1;
	DWORD 	price_vnum = 0;
	packet_shop_item() {
		memset(&alSockets, 0, sizeof(alSockets));
		memset(&aAttr, 0, sizeof(aAttr));
	}
#endif