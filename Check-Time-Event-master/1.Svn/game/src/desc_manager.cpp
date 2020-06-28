///Add
#if defined(CHECK_TIME_EVENT)
#include <ctime>
#include "questmanager.h"
void DESC_MANAGER::CheckTimeEvent() {
	const auto curr_time = time(nullptr);
	struct tm* vKey = std::localtime(&curr_time);
	vKey->tm_mon++;
	// for custom usage hour and minute converted like 20.11
	const auto hmin = std::atof((std::to_string(vKey->tm_hour) + "." + std::to_string(vKey->tm_min)).c_str());
	struct dateinfo { int day, month; };
	std::map<std::string, dateinfo> specialdays	{
		// syntax: {"name", {day, month}}
		{"Pi Day", {14,3}},
	};
//funcs:
	auto makerange = [](int less = 0, int max = 0) -> std::vector<int> {
		// coded for this system
		// syntax: makerange(1,3) : {1,2,3}
		// makerange(3) : {0,1,2,3}
		std::vector <int> range;
		if (!less && !max)
			return {};
		if ((less && !max) || less > max) {
			const auto oless = less;
			less = max;
			max = oless;
		}
		for (auto i = less; i <= max; i++)
			range.emplace_back(i);
		return range;
	};
	auto CheckDayMode = 
	[=] {
		const auto & light_hours = makerange(6, 21); // changeable
		const auto & night_hours = makerange();
		for (const auto & i : makerange(24))
			if (std::find(light_hours.begin(), light_hours.end(), i) == light_hours.end())
				night_hours.emplace_back(i);
		for (const auto & j : night_hours)
			if (vKey->tm_hour == j && !quest::CQuestManager::instance().GetEventFlag("eclipse"))
				goto setflag;
		for (const auto & i : light_hours)
			if (vKey->tm_hour == i && quest::CQuestManager::instance().GetEventFlag("eclipse"))
				goto setflag;
		return;
	setflag: // break
		quest::CQuestManager::instance().SetEventFlag("eclipse", !quest::CQuestManager::instance().GetEventFlag("eclipse"));
	};
	auto CheckSnowMode = 
	[=] {
		for (const auto & i : { 1,2,12 }) // winter
			if (i == vKey->tm_mon && !quest::CQuestManager::instance().GetEventFlag("xmas_snow"))
				goto setflag;
		for (const auto & i : makerange(3, 11))
			if (i == vKey->tm_mon && quest::CQuestManager::instance().GetEventFlag("xmas_snow"))
				goto setflag;
		return;
	setflag: // break
		quest::CQuestManager::instance().SetEventFlag("xmas_snow", !quest::CQuestManager::instance().GetEventFlag("xmas_snow"));
	};
	auto CheckSpecialDays = 
	[=] {
		for (const auto & [name, dateinf] : specialdays)
			if (dateinf.month == vKey->tm_mon && vKey->tm_mday == dateinf.day && vKey->tm_min == 0 && vKey->tm_sec == 0)
				for (const auto & it : m_set_pkDesc)
					if (const auto ch = it->GetCharacter())
						ch->ChatPacket(CHAT_TYPE_NOTICE, "Today is %s!", name.c_str());
	};
	auto SendMessageHour = 
	[=] {
		for (const auto & i : makerange(24))
			if (i == hmin && vKey->tm_sec == 0) {
				for (const auto & it : m_set_pkDesc)
					if (const auto ch = it->GetCharacter())
						ch->ChatPacket(CHAT_TYPE_INFO, "Hour is: %d:00, Good Luck!", i);
				break; // stop needless first loop
			}
	};
//options:
	CheckDayMode();
	CheckSnowMode();
	CheckSpecialDays();
	SendMessageHour();
}
#endif
