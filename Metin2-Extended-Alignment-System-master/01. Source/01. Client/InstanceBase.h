//1.1) Search for:
		static void RegisterTitleName(int iIndex, const char * c_szTitleName);
//1.2) Replace with:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
		static void RegisterTitleName(const int iIndex, const char * c_szTitleNameF, const char * c_szTitleNameM);
#else
		static void RegisterTitleName(int iIndex, const char * c_szTitleName);
#endif

//2.1) Search in struct SCreateData for:
			DWORD	m_dwRace;
//2.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
			DWORD	m_bJob;	
#endif

//3.1) Search in: struct SCreateData
	public:
		void CreateSpecialEffect(DWORD iEffectIndex);
		void AttachSpecialEffect(DWORD effect);
//3.2) Add after:
#ifdef ENABLE_EXTENDED_ALIGNMENT_SYSTEM
	public:
		const BYTE				GetJob() { return m_bJob; }
		void					SetJob(const BYTE job) { m_bJob = job; }
	protected:
		BYTE					m_bJob;
#endif