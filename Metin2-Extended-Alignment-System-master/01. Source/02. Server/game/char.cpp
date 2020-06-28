//1.1) Search in: void CHARACTER::EncodeInsertPacket(LPENTITY entity)
		addPacket.bEmpire = m_bEmpire;
//1.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
		addPacket.bJob = IsPC() ? m_points.job : 0;
#endif