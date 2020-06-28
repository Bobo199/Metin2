//Find
	if (!strcmpi(szCmd, "quit"))
	{
		PostQuitMessage(0);
	}
	
///Add
#if defined(VOICE_CHAT)
	else if (!strcmpi(szCmd, "voicechat")) 
		CSoundManager::Instance().PlaySound2D(TokenVector[1].c_str());
#endif