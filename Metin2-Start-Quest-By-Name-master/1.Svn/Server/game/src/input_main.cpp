//Find
void CInputMain::UseSkill(LPCHARACTER ch, const char * pcData)
{
	...
}

///Add
#if defined(QUEST_BY_NAME)
#include <unordered_set>
void CInputMain::ScriptButtonByName(const LPCHARACTER& ch, const void* pvData)
{
	if (!ch)
		return;
	
	const std::unordered_set<std::string> blockqlist {"example", "example2"};
	const auto p = (TPacketCGScriptButtonByName*)pvData;
	const auto strqname = std::string(p->questname);
	
	if (!blockqlist.count(strqname))
		quest::CQuestManager::Instance().QuestButtonByName(ch, strqname);
	else
		sys_log(0, "QUEST ScriptButtonByName %s called blocked qname: %s", ch->GetName(), p->questname);
}
#endif

//Find
		case HEADER_CG_PARTY_USE_SKILL:
			PartyUseSkill(ch, c_pData);
			break;
			
///Add
#if defined(QUEST_BY_NAME)
		case HEADER_CG_QUEST_BYNAME:
			ScriptButtonByName(ch, c_pData);
			break;
#endif