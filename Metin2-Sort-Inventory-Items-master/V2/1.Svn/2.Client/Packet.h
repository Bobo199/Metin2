//Find
	HEADER_CG_ON_CLICK							= 26,
	
///Add
#ifdef ENABLE_SORT_INVEN
	SORT_INVEN = 140,
#endif

//Find
typedef struct command_item_move
{
	BYTE header;
	TItemPos pos;
	TItemPos change_pos;
	BYTE num;
} TPacketCGItemMove;

///Add
#ifdef ENABLE_SORT_INVEN
typedef struct sort_inven
{
	BYTE	header;
	BYTE 	option;
} TPacketCGSortInven;
#endif