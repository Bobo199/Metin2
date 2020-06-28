///Add
#ifdef RENEWAL_BOOK_NAME
#include "skilldesc.h"
#endif

//Find
		CSkillProto * Get(const char * c_pszSkillName);
		
///Add
#ifdef RENEWAL_BOOK_NAME
		std::string GetSkillName(DWORD dwVnum) {
			auto it = skill_list.find(dwVnum);
			return it == skill_list.end() ? "" : it->second;
		}
#endif