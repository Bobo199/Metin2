//Find
	HEADER_CG_WHISPER				= 19,

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	ENVANTER_BLACK		            = 23,
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
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
typedef struct envanter_paketi
{
	BYTE	header;
} TPacketCGEnvanter;
#endif