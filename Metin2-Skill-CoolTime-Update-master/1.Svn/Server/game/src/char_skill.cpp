///Add
#if defined(SKILL_COOLTIME_UPDATE)
void CHARACTER::ResetSkillCoolTimes()
{
	if (!GetSkillGroup() || m_SkillUseInfo.empty())
		return;
	
	for (std::map<int, TSkillUseInfo>::iterator it = m_SkillUseInfo.begin(); it != m_SkillUseInfo.end(); ++it)
		it->second.dwNextSkillUsableTime = 0;
}
#endif