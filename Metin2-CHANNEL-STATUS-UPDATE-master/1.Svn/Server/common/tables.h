//Find
typedef struct SChannelStatus
{
	...
}

///Change
typedef struct SChannelStatus
{
	short nPort;
	BYTE bStatus;
#if defined(__CHANNEL_STATUS_UPDATE__)
	int player_count;
#endif
} TChannelStatus;