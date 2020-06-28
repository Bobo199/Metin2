///Add
#if defined(CHAT_SLOW_MODE)
ACMD(chat_slow_mode)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));

	if (*arg1) {
		int set;
		str_to_number(set, arg1);
		quest::CQuestManager::instance().SetEventFlag("chatslowmode", set);
		for (auto it : DESC_MANAGER::instance().GetClientSet())
			if (auto ch = it->GetCharacter())
				ch->CheckSlowMode(true);
	}
}
#endif