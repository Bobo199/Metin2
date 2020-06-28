//Find
	POINT_RESIST_PENETRATE = 137,

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	POINT_INVEN = 145,
#endif

//Find
	long			gold;

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	int 			envanter;
#endif

//Find
		INT				GetGold() const		{ return m_points.gold;	}
		void			SetGold(INT gold)	{ m_points.gold = gold;	}

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
		INT				Inven_Point() const			{ return m_points.envanter; }
		INT				Inventory_Size() const			{ return INVENTORY_OPEN_PAGE_SIZE + (INVENTORY_WIDTH*Inven_Point()); }
		void			Set_Inventory_Point(INT black)	{ m_points.envanter = black; }
		bool            Update_Inven();
#endif