///Add
#if defined(__SHOP_ITEM_AVERAGE__)
#include "shop_manager.h"
#endif

//Find
		pack2.items[i].vnum = item.vnum;
		
///Add
#if defined(__SHOP_ITEM_AVERAGE__)
		pack2.items[i].average_price = static_cast<long>(CShopManager::Instance().GetItemAverage(item.vnum));
#endif