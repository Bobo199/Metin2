///Add if not exist
#include "service.h"

//Find in : SShopItemTable
	BYTE		display_pos;
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	long	alSockets[ITEM_SOCKET_MAX_NUM];
	TPlayerItemAttribute	aAttr[ITEM_ATTRIBUTE_MAX_NUM];
	DWORD 	price_type = 1;
	DWORD 	price_vnum = 0;
	SShopItemTable() {
		memset(&alSockets, 0, sizeof(alSockets));
		memset(&aAttr, 0, sizeof(aAttr));
	}
#endif

///Add anywhere
#ifdef ENABLE_RENEWAL_SHOPEX
enum STableExTypes : decltype(TShopItemTable::price_type)
{
	EX_GOLD = 1,
	EX_SECONDARY,
	EX_ITEM,
	EX_EXP,
	EX_MAX,
};
#endif