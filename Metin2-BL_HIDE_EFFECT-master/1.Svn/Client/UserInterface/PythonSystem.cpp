///Add
#if defined(__BL_HIDE_EFFECT__)
bool CPythonSystem::GetBLEffectOption(std::uint8_t idx)
{
	switch (idx)
	{
	case 0: // BUFF
		return m_Config.bBuffEffect;
	case 1: // SKILL
		return m_Config.bSkillEffect;
	default:
		return false;
	}
}

void CPythonSystem::SetBLEffectOption(std::uint8_t idx, bool ret)
{
	switch (idx)
	{
	case 0: // BUFF
		m_Config.bBuffEffect = ret;
		break;
	case 1: // SKILL
		m_Config.bSkillEffect = ret;
		break;
	default:
		return;
	}
	CEffectManager::Instance().HideOnSomeEffects(idx, ret);
}
#endif

//Find
	m_Config.bShowSalesText		= true;
		
///Add
#if defined(__BL_HIDE_EFFECT__)
	m_Config.bBuffEffect		= true;
	m_Config.bSkillEffect		= true;
#endif

//Find
		else if (!stricmp(command, "SHOW_SALESTEXT"))
			m_Config.bShowSalesText = atoi(value) == 1 ? true : false;
		
///Add
#if defined(__BL_HIDE_EFFECT__)
		else if (!stricmp(command, "BUFF_EFFECT"))
			SetBLEffectOption(0, (atoi(value) == 1));
		else if (!stricmp(command, "SKILL_EFFECT"))
			SetBLEffectOption(1, (atoi(value) == 1));
#endif

//Find
	fprintf(fp, "USE_DEFAULT_IME		%d\n", m_Config.bUseDefaultIME);
	
///Add
#if defined(__BL_HIDE_EFFECT__)
	fprintf(fp, "BUFF_EFFECT		%d\n", m_Config.bBuffEffect);
	fprintf(fp, "SKILL_EFFECT		%d\n", m_Config.bSkillEffect);
#endif