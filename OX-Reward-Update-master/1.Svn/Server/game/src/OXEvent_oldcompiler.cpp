//Find in : bool COXEventManager::Initialize()
	m_map_attender.clear();
	
///Add
#ifdef OX_REWARD_UPDATE
	LoadRewardTable();
#endif

//Find in : void COXEventManager::Destroy()
	m_map_attender.clear();
	
///Add
#ifdef OX_REWARD_UPDATE
	for (int i = 0; i < m_ox_reward.size(); i++)
		m_ox_reward[i].clear();
	m_ox_reward.clear();
#endif

///Add new func
#ifdef OX_REWARD_UPDATE
#include "group_text_parse_tree.h"
const char* joblist[] = {
	"oxrewardwarrior",
	"oxrewardassassin",
	"oxrewardsura",
	"oxrewardshaman"
};
void COXEventManager::LoadRewardTable()
{
	char c_pszFileName[FILE_MAX_LEN];
	snprintf(c_pszFileName, sizeof(c_pszFileName), "%s/ox_reward.txt", LocaleService_GetBasePath().c_str());
	std::auto_ptr<CGroupTextParseTreeLoader> loader(new CGroupTextParseTreeLoader);
	if (!loader->Load(c_pszFileName)) {
		sys_err ("%s: load error", c_pszFileName);
		return;
	}
	for (int i = 0; i < m_ox_reward.size(); i++)
		m_ox_reward[i].clear();
	m_ox_reward.clear();
	int k = 0;
	for (int job = 0; job < sizeof(joblist)/sizeof(joblist[0]); job++) {
		CGroupNode* OxRewardGroup = loader->GetGroup(joblist[job]);
		if (!OxRewardGroup) {
			sys_err ("ox_reward.txt need %s", joblist[job]);
			return;
		}
		if (!OxRewardGroup->GetRowCount()) {
			sys_err	("Group %s is Empty.", joblist[job]);
			return;
		}
		std::vector<OX_reward> vec;
		for (int i = 0; i < OxRewardGroup->GetRowCount(); i++) {
			OX_reward rewardtable;
			DWORD val, empty = 0;
			if (OxRewardGroup->GetValue(i, "item", val)) {
				rewardtable.item = val;
				empty++;
			}
			if (OxRewardGroup->GetValue(i, "count", val))
				rewardtable.count = val;
			if (OxRewardGroup->GetValue(i, "gold", val)) {
				rewardtable.gold = val;
				empty++;
			}
			if (empty) 
				vec.push_back(rewardtable);
		}
		m_ox_reward[k] = vec;
		k++;
	}
}
bool COXEventManager::GiveReward()
{
	if (m_ox_reward.size()) {
		itertype(m_map_attender) iter = m_map_attender.begin();
		for (; iter != m_map_attender.end(); ++iter)
		{
			LPCHARACTER pkChar = CHARACTER_MANAGER::instance().FindByPID(iter->second);
			if (pkChar) {
				OX_reward data = m_ox_reward[pkChar->GetJob()][number(0,m_ox_reward[pkChar->GetJob()].size()-1)];
				if (!pkChar->AutoGiveItem(data.item, data.count))
					sys_err("Give Reward item error.");
				pkChar->GiveGold(data.gold);
			}
		}
		LogWinner();
		return true;
	}
	return false;
}
#endif