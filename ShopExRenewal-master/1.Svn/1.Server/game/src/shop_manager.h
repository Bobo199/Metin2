//Find (private)
	bool	ReadShopTableEx(const char* stFileName);

///Change
#ifndef ENABLE_RENEWAL_SHOPEX
	bool	ReadShopTableEx(const char* stFileName);
#endif

//Find
	void	DestroyPCShop(LPCHARACTER ch);
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	bool	ReadShopTableEx(const char* stFileName);
#endif