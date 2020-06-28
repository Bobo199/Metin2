//Find
	m_dwLastAttackTime = get_dword_time() - 20000;
	
///Add
#if defined(CHAT_SLOW_MODE)
	m_dwLastTalkTime = 0;
#endif

//Find
void CHARACTER::StopStateMachine()
{
	CHARACTER_MANAGER::instance().RemoveFromStateList(this);
}

///Add
#if defined(CHAT_SLOW_MODE)
bool CHARACTER::CheckSlowMode(bool button, BYTE type)
{
	auto slowtime = quest::CQuestManager::instance().GetEventFlag("chatslowmode");
	if (slowtime < 0)
		slowtime = -1;
	auto IsEqual = [type](const std::list<BYTE>& list) -> bool {return std::find(list.begin(), list.end(), type) != list.end();};
	auto GenerateTime = [](auto sec) {
		char buf[128 + 1];
		long hour = sec / 3600;
		sec -= hour * 3600;
		long min = (sec / 60);
		sec -= min * 60;
		if (hour > 0 && min > 0)
			snprintf(buf, sizeof(buf), "Slow mode enabled.You can talk in %d hour, %d min and %d sec after.", hour, min, sec);
		else if (hour > 0 && min == 0)
			snprintf(buf, sizeof(buf), "Slow mode enabled.You can talk in %d hour and %d sec after.", hour, sec);
		else if (hour == 0 && min > 0)
			snprintf(buf, sizeof(buf), "Slow mode enabled.You can talk in %d min and %d sec after.", min, sec);
		else
			snprintf(buf, sizeof(buf), "Slow mode enabled.You can talk in %d sec after.", sec);
		return buf;
	};
	if (button) {
		ChatPacket(CHAT_TYPE_COMMAND, "chatslowmode %d", slowtime);
		if (slowtime > 0)
			ChatPacket(CHAT_TYPE_INFO, "Slow mode enabled.");
		if (slowtime < 0)
			ChatPacket(CHAT_TYPE_INFO, "Chat closed.");
		return false;
	}
	if (slowtime && /*!IsGM() &&*/ IsEqual({ CHAT_TYPE_TALKING , CHAT_TYPE_PARTY , CHAT_TYPE_GUILD, CHAT_TYPE_SHOUT })) {
		if (slowtime < 0) {
			ChatPacket(CHAT_TYPE_INFO, "Chat closed.");
			return true;
		}
		if (get_global_time() < GetLastTalkTime()) {
			ChatPacket(CHAT_TYPE_INFO, GenerateTime(GetLastTalkTime() - get_global_time()));
			return true;
		}
		SetLastTalkTime(get_global_time() + slowtime);
	}
	return false;
}
#endif
