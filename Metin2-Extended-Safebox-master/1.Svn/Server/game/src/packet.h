//Find in typedef struct packet_item_del
	BYTE	pos;
	
///Change
#if defined(__EXTENDED_SAFEBOX__)
	DWORD	pos;
#else
	BYTE	pos;
#endif

//Find in typedef struct command_safebox_checkout
	BYTE	bSafePos;
	
///Change
#if defined(__EXTENDED_SAFEBOX__)
	DWORD	bSafePos;
#else
	BYTE	bSafePos;
#endif

//Find in typedef struct command_safebox_checkin
	BYTE	bSafePos;
	
///Change
#if defined(__EXTENDED_SAFEBOX__)
	DWORD	bSafePos;
#else
	BYTE	bSafePos;
#endif