//Find
	const string & CQuestManager::GetCurrentQuestName()
	{
		return GetCurrentPC()->GetCurrentQuestName();
	}
	
///Add
#if defined(QUEST_BY_NAME)
	void CQuestManager::QuestButtonByName(const LPCHARACTER& ch, const std::string& qname)
	{
		if (!ch)
			return;
		const auto idx = GetQuestIndexByName(qname);
		if (idx)
			QuestButton(ch->GetPlayerID(), idx);
		else
			sys_err("QUEST QuestButtonByName %s, quest not found: %s", ch->GetName(), qname.c_str());
	}
	void CQuestManager::PrintQuestIndexList() //not using
	{
		if (!m_hmQuestName.size())
			return;
		const auto filename = "QuestIndexList.txt";
		std::unique_ptr<FILE, decltype(&std::fclose)> File(std::fopen(filename, "w"), &std::fclose);
		if (!File)
			return;
		for (const auto& data : m_hmQuestName)
			std::fprintf(File.get(), "%d: %s\n", data.second, data.first.c_str());
		std::printf("%Iu quest index loaded. File %s", m_hmQuestName.size(), filename);
	}
#endif