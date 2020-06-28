//Find
	HEADER_CG_QUEST_CONFIRM                     = 31,
	
///Add
#ifdef ENABLE_CHECK_INSULT
	HEADER_CG_INSULT_BLOCK						= 35,
#endif

//Find
typedef struct command_item_pickup
{
	BYTE header;
	DWORD vid;
} TPacketCGItemPickUp;

///Add
#ifdef ENABLE_CHECK_INSULT
typedef struct block_insult
{
	BYTE	header;
} TPacketCGChatInsult;
#endif