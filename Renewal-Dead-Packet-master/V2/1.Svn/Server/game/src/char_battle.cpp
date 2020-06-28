//Find
	TPacketGCDead pack;
	pack.header	= HEADER_GC_DEAD;
	pack.vid	= m_vid;
	PacketAround(&pack, sizeof(pack));
	
///Change
#ifndef RENEWAL_DEAD_PACKET
	TPacketGCDead pack;
	pack.header	= HEADER_GC_DEAD;
	pack.vid	= m_vid;
	PacketAround(&pack, sizeof(pack));
#endif

//Find
	if (m_pkExchange != NULL)
	{
		m_pkExchange->Cancel();
	}
///Add below
#ifdef RENEWAL_DEAD_PACKET
	TPacketGCDead pack;
	pack.header	= HEADER_GC_DEAD;
	pack.vid	= m_vid;
	for (BYTE i = REVIVE_TYPE_HERE; i < REVIVE_TYPE_MAX; i++)
		pack.t_d[i] = CalculateDeadTime(i);
	PacketAround(&pack, sizeof(pack));
#endif
