//Find
	typedef boost::unordered_map<short, BYTE> TChannelStatusMap;

///Change
#if defined(__CHANNEL_STATUS_UPDATE__)
	typedef boost::unordered_map<short, std::pair<BYTE, int>> TChannelStatusMap;
#else
	typedef boost::unordered_map<short, BYTE> TChannelStatusMap;
#endif
	