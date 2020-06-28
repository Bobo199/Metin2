#pragma once

#if defined(TIME_SYSTEM)
#include <chrono>
class TimerInfo : public singleton<TimerInfo>
{
public:
	bool IsExist(const LPCHARACTER ch) const { return ChTimerMap.find(ch->GetPlayerID()) != ChTimerMap.end(); }
	bool IsRunning(const LPCHARACTER ch) const { return IsExist(ch) && ChTimerMap.at(ch->GetPlayerID()).running; }
	void AddCH(const LPCHARACTER ch)
	{
		if (!IsExist(ch))
			ChTimerMap.emplace(ch->GetPlayerID(), black());
		else if (!IsRunning(ch))
			Return(ch);
	};
	void Stop(const LPCHARACTER ch)
	{
		if (IsRunning(ch)) {
			ChTimerMap.at(ch->GetPlayerID()).elapsed = GetTimeOfCH<std::chrono::seconds>(ch);
			ChTimerMap.at(ch->GetPlayerID()).running = false;
		}
	}
	void Return(const LPCHARACTER ch)
	{
		if (!IsRunning(ch)) {
			ChTimerMap.at(ch->GetPlayerID()).time = std::chrono::steady_clock::now();
			ChTimerMap.at(ch->GetPlayerID()).running = true;
		}
	}
	template<typename T> typename T::rep GetTimeOfCH(LPCHARACTER ch)
	{
		return IsExist(ch) ? std::chrono::duration_cast<T>(std::chrono::steady_clock::now() - ChTimerMap.at(ch->GetPlayerID()).time).count() + static_cast<T::rep>(ChTimerMap.at(ch->GetPlayerID()).elapsed)
			: static_cast<T::rep>(0);
	};
	void DeleteCH(const LPCHARACTER ch)
	{
		if (IsExist(ch))
			ChTimerMap.erase(ch->GetPlayerID());
	};
private:
	struct black
	{
		std::chrono::time_point<std::chrono::system_clock> time = std::chrono::steady_clock::now();
		long long elapsed = 0;
		bool running = true;
	};
	std::map<DWORD, black> ChTimerMap;
};
#endif