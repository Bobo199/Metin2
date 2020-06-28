//1.) Search for:
		DWORD	GetNPCVnum() { return m_dwNPCVnum; }
//1.2) Add after:
#ifdef ENABLE_PRIVATE_SHOP_AUTO_CLOSE
		bool 	IsSoldOut() const;
#endif	