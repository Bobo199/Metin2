//Find
		channelStatus.nPort = mother_port;
		
///Add
#if defined(__CHANNEL_STATUS_UPDATE__)
		channelStatus.player_count = iTotal;
#endif


/**
		CHANNELSTATUS_UPDATE_PERIOD = 5*60*1000,
		is default 5 minute, you can change for faster update
**/