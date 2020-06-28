//Find in : typedef struct packet_shop_item
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	DWORD 	price_type = 1;
	DWORD 	price_vnum = 0;
#endif