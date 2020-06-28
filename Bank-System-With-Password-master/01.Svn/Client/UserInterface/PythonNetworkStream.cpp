//Find
			Set(HEADER_GC_VIEW_EQUIP, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCViewEquip), STATIC_SIZE_PACKET));
		
///Add
			#ifdef __BANK_SYSTEM__
			Set(HEADER_GC_BANK, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCBank), STATIC_SIZE_PACKET));
			#endif