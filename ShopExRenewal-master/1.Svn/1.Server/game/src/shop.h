//Find
			int		itemid;
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
			long	alSockets[ITEM_SOCKET_MAX_NUM];
			TPlayerItemAttribute	aAttr[ITEM_ATTRIBUTE_MAX_NUM];
			DWORD price_type;
			DWORD price_vnum;
#endif

//Find
				pkItem = NULL;
		
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
				price_type = 1,
				price_vnum = 0,
				memset(&alSockets, 0, sizeof(alSockets));
				memset(&aAttr, 0, sizeof(aAttr));
#endif	

//Find
		virtual bool	IsPCShop()	{ return m_pkPC ? true : false; }
		
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
		virtual bool	IsShopEx() const { return false; };
#endif