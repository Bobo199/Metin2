//Find
	HEADER_CG_LOGIN5_OPENID			= 116,
	
///Add
#ifdef ENABLE_SORT_INVEN
	SORT_INVEN = 140,
#endif

//Find
typedef struct command_item_move
{
	BYTE 	header;
	TItemPos	Cell;
	TItemPos	CellTo;
	BYTE	count;
} TPacketCGItemMove;

///Add
#ifdef ENABLE_SORT_INVEN
typedef struct sort_inven
{
	BYTE	header;
	BYTE 	option;
} TPacketCGSortInven;
#endif	