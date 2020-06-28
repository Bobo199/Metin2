//1.1) Search in: typedef struct packet_char_additional_info
	DWORD   dwMountVnum;
//1.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
	BYTE	bJob;
#endif