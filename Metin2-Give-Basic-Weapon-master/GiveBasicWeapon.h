#pragma once
#include "item_manager.h"
#include "char.h"
#include "stdafx.h"
#include <array>
#include "../../common/length.h"
struct StructBasicWeapon
{
	DWORD	dwVnum;
	DWORD	count;
	bool	equip;
};
static const std::map<BYTE, std::vector<StructBasicWeapon>> m_mapBasicWeapon =
{
	{
		JOB_WARRIOR,
		{
			{11209, 1, true},
			{16259, 1, false}
		}
	},
	{
		JOB_ASSASSIN,
		{
			{1,2, true}
		}
	},
	{
		JOB_SURA,
		{
			{1,2, true}
		}
	},
	{
		JOB_SHAMAN,
		{
			{1,2, true}
		}
	},
};
static void GiveBasicWeapon(LPCHARACTER ch)
{
	if (!ch)
		return;

	if (true) {
		ch->SetHorseLevel(21);
		ch->StartRiding();
	}
	if (true && !m_mapBasicWeapon.empty()) {
		try {
			for (const auto& v : m_mapBasicWeapon.at(ch->GetJob())) {
				auto item = ch->AutoGiveItem(v.dwVnum, v.count);
				if (!item) {
					sys_err("Cannot create item for GiveBasicWeapon, vnum: %d, job: %d", v.dwVnum, ch->GetJob());
					continue;
				}
				if (v.equip)
					ch->EquipItem(item);
			}
		}
		catch (const std::out_of_range & e)	{
			sys_err("what: %s, at GiveBasicWeapon", e.what());
		}
	}
	if (true) {
		static const std::array<const char*, JOB_MAX_NUM> JobNames { "Warrior", "Assassin", "Sura", "Shaman" };
		static const std::array<const char*, EMPIRE_MAX_NUM> EmpireNames{ "전제국","신수국","천조국","진노국" };
		char buf[256];
		try {
			snprintf(buf, sizeof(buf), "New player %s, job: %s, empire: %s", ch->GetName(), JobNames.at(ch->GetJob()), LC_TEXT(EmpireNames.at(ch->GetEmpire())));
			SendNotice(buf);
		}
		catch (const std::out_of_range & e) {
			sys_err("what: %s, at Empire Announcement", e.what());
		}
	};
}