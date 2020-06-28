//Find
	else if (!strcmpi(szCmd, "gift"))
	{
		PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "Gift_Show", Py_BuildValue("()")); 	
	}
	
///Add
#if defined(PC_KILL_SOUND_EFFECT)
	else if (!strcmpi(szCmd, "kill_sound"))
	{
		char buf[30];
		snprintf(buf, sizeof(buf), "BGM/kill_effect/%s.wav", TokenVector[1].c_str());
		CSoundManager::Instance().PlaySound2D(buf);
		// overhead effect etc.
	}
#endif