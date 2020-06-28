//Find
	public:
		bool		DragonSoul_RefineWindow_Open(LPENTITY pEntity);
		bool		DragonSoul_RefineWindow_Close();
		LPENTITY	DragonSoul_RefineWindow_GetOpener() { return  m_pointsInstant.m_pDragonSoulRefineWindowOpener; }
		bool		DragonSoul_RefineWindow_CanRefine();
		
///Add
	#ifdef __BANK_SYSTEM__
	public:
		bool	bBankOpen;
		bool 	IsBankOpened() { return bBankOpen; }
	#endif