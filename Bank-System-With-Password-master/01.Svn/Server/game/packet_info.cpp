//Find
	Set(HEADER_CG_MYSHOP, sizeof(TPacketCGMyShop), "MyShop", true);
	
///Add
#ifdef __BANK_SYSTEM__
	Set(HEADER_CG_BANK, sizeof(TPacketCGBank), "Bank", true);
#endif