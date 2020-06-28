//Find
	HEADER_CG_QUEST_CONFIRM                     = 31,
	
///Add
#ifdef __BANK_SYSTEM__
	HEADER_CG_BANK								= 36,
#endif

//Find
	HEADER_GC_QUEST_CONFIRM                     = 46,
	
///Add
#ifdef __BANK_SYSTEM__
	HEADER_GC_BANK								= 55,
#endif

//Find
typedef struct command_shop
{
	BYTE        header;
	BYTE		subheader;
} TPacketCGShop;

///Add
#ifdef __BANK_SYSTEM__
enum
{
	BANK_SUBHEADER_CG_START,
	BANK_SUBHEADER_CG_CLOSE,
	BANK_SUBHEADER_CG_ADD,	
	BANK_SUBHEADER_CG_WITHDRAW,	
	BANK_SUBHEADER_CG_SEND,
	BANK_SUBHEADER_CG_CHANGE_PASSWORD,
	
	BANK_SUBHEADER_GC_START,
	BANK_SUBHEADER_GC_UPDATE,
	BANK_SUBHEADER_GC_CLOSE,
};

typedef struct command_bank
{
	BYTE		header;
	BYTE		subheader;
	DWORD		arg1;
	DWORD		arg2;
	DWORD		arg3;
	DWORD		arg4;
	char 		pass[100];
	char 		pass2[100];
} TPacketCGBank;

typedef struct packet_bank
{
    BYTE        header;
    BYTE        subheader;
    DWORD       arg1;
    DWORD       arg2;
    DWORD       arg3;
    DWORD       arg4;
} TPacketGCBank;
#endif