///Add
#if defined(SKILL_COOLTIME_UPDATE)
void CPythonPlayer::ResetSkillCoolTimes()
{
	if (!CPythonNetworkStream::Instance().GetMainActorSkillGroup())
		return;

	for (int i = 0; i < SKILL_MAX_NUM; ++i) {
		TSkillInstance& rkSkillInst = m_playerStatus.aSkill[i];
		if (!rkSkillInst.fLastUsedTime && !rkSkillInst.fCoolTime)
			continue;

		rkSkillInst.fLastUsedTime = rkSkillInst.fCoolTime = 0.0f;
		PyCallClassMemberFunc(m_ppyGameWindow, "SkillClearCoolTime", Py_BuildValue("(i)", i));
	}
}
#endif