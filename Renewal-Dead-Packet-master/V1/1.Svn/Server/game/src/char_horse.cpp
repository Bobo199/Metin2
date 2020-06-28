//Find
			pack.header	= HEADER_GC_DEAD;
			pack.vid    = m_chHorse->GetVID();
			
///Add
#ifdef RENEWAL_DEAD_PACKET
			memset(&pack.t_d, 0, sizeof(pack.t_d));
#endif