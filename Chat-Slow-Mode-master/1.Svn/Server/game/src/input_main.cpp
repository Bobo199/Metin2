//Find
	if (true == SpamBlockCheck(ch, buf, buflen))
	{
		return iExtraLen;
	}
	
///Add
#if defined(CHAT_SLOW_MODE)
	if (ch->CheckSlowMode(false, pinfo->type))
		return iExtraLen;
#endif