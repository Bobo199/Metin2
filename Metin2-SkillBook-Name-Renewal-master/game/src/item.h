///Add
#ifdef RENEWAL_BOOK_NAME
#include "skill.h"
#include "unique_item.h"
#include "mob_manager.h"
#endif

//Find
		const char *	GetName()
		
///Change
		const char *	GetName()
		{ 
#ifdef RENEWAL_BOOK_NAME
			if (!m_pProto) return "";
			std::string lname;
			switch (m_dwVnum) {
				case 70104:
					lname = CMobManager::instance().GetMobName(GetSocket(0)) + ' ' + m_pProto->szLocaleName;
				break;
				case 50300:
				case ITEM_SKILLFORGET_VNUM:
					lname = CSkillManager::instance().GetSkillName(GetSocket(0)) + ' ' + m_pProto->szLocaleName;
				break;
				default:
					lname = m_pProto->szLocaleName;
				break;
			}
			return lname.c_str();
#else
			return m_pProto ? m_pProto->szLocaleName : ""; 
#endif
		}
