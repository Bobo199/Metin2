//Find in : SShopItemTable
	BYTE		display_pos;
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	long alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
	DWORD 	price_type = 1;
	DWORD 	price_vnum = 0;
	SShopItemTable() {
		memset(&alSockets, 0, sizeof(alSockets));
		memset(&aAttr, 0, sizeof(aAttr));
	}
#endif

//Find
	SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX,
		
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM,
	SHOP_SUBHEADER_GC_NOT_ENOUGH_EXP,
#endif