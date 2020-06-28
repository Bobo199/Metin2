//Find
	bool			AddShopTable(TShopTableEx& shopTable);
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	virtual bool	IsShopEx() const { return true; };
#endif
