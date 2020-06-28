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
	for (int i = 0; i < 2; i++)
		pack.t_d[i]	= CalculateDeadTime(i);
	PacketAround(&pack, sizeof(pack));
#endif
