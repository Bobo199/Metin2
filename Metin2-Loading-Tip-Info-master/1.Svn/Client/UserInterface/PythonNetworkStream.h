///Add
#if defined(__LOADING_TIP__)
#include <unordered_map>
#endif

//Find
		void __DirectEnterMode_Initialize();
		
///Add
#if defined(__LOADING_TIP__)
		std::unordered_map<int, std::string> m_TipVnum;
#endif

//Find
		DWORD EXPORT_GetBettingGuildWarValue(const char* c_szValueName);
		
///Add
#if defined(__LOADING_TIP__)
		bool LoadTipVnum(const char* FileName);
		const decltype(m_TipVnum)& GetTipMap() const { return m_TipVnum; };
#endif