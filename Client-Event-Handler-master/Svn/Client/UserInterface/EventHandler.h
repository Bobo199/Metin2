#pragma once
#include "StdAfx.h"
#include <functional>
#include "PythonApplication.h"
#define now CPythonApplication::Instance().GetGlobalTime()
struct HandlerEventInfo
{
	HandlerEventInfo(const std::function<void()> &fn, const int &_wait, const int &_count) : func(fn), wait(_wait), count(_count), time(0), bind(0){}
	int wait, count, bind;
	float time;
	std::function<void()> func;
};

class EventHandler : public singleton<EventHandler>
{
public:
	EventHandler() { Destroy();}
	virtual ~EventHandler() { Destroy(); }
	void Destroy() { EventInfoMap.clear(); }
	void AddEvent(const std::string& name, const std::function<void()> &func, const int &wait, const int &count) {
		if (GetHandler(name))
			DeleteEvent(name);
		EventInfoMap[name] = std::make_unique<HandlerEventInfo>(func, wait, count);
	}
	void DeleteEvent(const std::string& name) {
		if (GetHandler(name))
			EventInfoMap.erase(name);
	}
	void Proccess() {
		if (!EventInfoMap.size())
			return;
		for (const auto &event : EventInfoMap) {
			if (GetHandler(event.first)) {
				if (!event.second->count) {
					DeleteEvent(event.first);
					continue;
				}
				if (event.second->time <= now) {
					event.second->func();
					event.second->count--;
					event.second->bind++;
					event.second->time = now + static_cast<float>(event.second->wait);
				}
			}
		}
	};
	bool FindEvent(const std::string & name) {
		const auto &it = EventInfoMap.find(name);
		return it != EventInfoMap.end();
	};
	std::unique_ptr<HandlerEventInfo>* GetHandler(const std::string& name) { return FindEvent(name) ? &EventInfoMap.find(name)->second : nullptr; };
private:
	std::map< std::string, std::unique_ptr< HandlerEventInfo > > EventInfoMap;
};
