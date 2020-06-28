//Find
typedef struct packet_shop_start
{
	DWORD   owner_vid;
	struct packet_shop_item	items[SHOP_HOST_ITEM_MAX_NUM];
} TPacketGCShopStart;

///Change
typedef struct packet_shop_start
{
	DWORD   owner_vid;
	#ifdef ENABLE_SHOP_SEEN
	DWORD   looked;
	#endif
	struct packet_shop_item	items[SHOP_HOST_ITEM_MAX_NUM];
} TPacketGCShopStart;
