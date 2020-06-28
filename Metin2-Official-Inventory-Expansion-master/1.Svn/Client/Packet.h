//Find
HEADER_CG_WHISPER							= 19,

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	ENVANTER_BLACK		            			= 23,
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
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
typedef struct envanter_paketi
{
	BYTE		header;
} TPacketCGEnvanter;
#endif

///Find

//POINT_MAX_NUM = 255,=>stdafx.h ?/
};

///Add on

#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	POINT_BLACK = 145,
#endif