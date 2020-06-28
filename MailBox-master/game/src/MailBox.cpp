/**
	Created by blackdragonx61, 29.07.2018
**/
#include "stdafx.h"
#include "char.h"
#include "char_manager.h"
#include "packet.h"
#include "item.h"
#include "item_manager.h"
#include "messenger_manager.h"
#include "db.h"
#include "desc.h"
#include "locale_service.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <chrono>
#include <ctime>

using namespace std;
using namespace boost::gregorian;
typedef std::chrono::system_clock Clock;
namespace date_data {
	auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *tm = std::localtime(&now_c);
	auto day = tm->tm_mday, month = tm->tm_mon + 1, year = tm->tm_year + 1900;
}

#ifdef MAILING_SYSTEM
enum MailBox
{
	TR,
	EN,
	LANG_MAX,
	DEFAULT_LANG = TR, // change lang
	ICON_EMPTY = 0,
	ICON_ITEM,
	ICON_GM,
	ICON_POST,
	DUR_GM = 7,
	MAX_MAIL_COUNT = 20,
	DUR_NORM = 30
};
auto Translate(string input, BYTE lang)
{
	map<string, string> Langs[LANG_MAX];
	Langs[TR]["DeleteMail"] = "[TR]Test at DeleteMail";
	Langs[EN]["DeleteMail"] = "[EN]Test at DeleteMail";
   
	if (not(Langs[lang].count(input)) or lang >= LANG_MAX) {
		sys_err("Error in [%s], chat[%s]", __FUNCTION__, input.c_str());
		return "error";
	}
	return Langs[lang][input].c_str();
   
    /* only test
	auto Lang_Name = [](auto lang) -> string {
		return lang == TR ? "TR" : "EN";
	};
	for (auto exist_langs : {TR, EN})
		for (auto [inp,output] : Langs[exist_langs])
			cout << "Lang:[" << Lang_Name(exist_langs) << "] " << "input: " << inp << " output: " << output << endl;
		*/
}

auto SendPacket(LPCHARACTER ch, BYTE subheader) 
{
	if (ch->GetDesc()) {
		packet_mail_gc paket;
		paket.header 	= HEADER_GC_MAIL;
		paket.subheader = subheader;	
		ch->GetDesc()->Packet(&paket, sizeof(paket));
	}
}

void CHARACTER::LoadMyMails()
{
	if (!GetDesc()) return;
	auto GetMailTime = [=](int id)
	{
		date today(date(date_data::year, date_data::month, date_data::day));
		array <int, 4> time_data = {}; auto result = 0;
		unique_ptr<SQLMsg> pMsg(DBManager::Instance().DirectQuery("SELECT type, day, month, year FROM player.mails WHERE id='%d' and name='%s'", id, GetName()));
		if (pMsg->Get()->uiNumRows) {
			auto row = mysql_fetch_row(pMsg->Get()->pSQLResult);
			for (auto i : {0,1,2,3}) str_to_number(time_data[i], row[i]);	
			date maildate(date(time_data[3], time_data[2], time_data[1]));
			date_period range(maildate, today);
			auto Conversion = time_data[ICON_EMPTY] != ICON_GM ? DUR_NORM : DUR_GM;
			result = Conversion-range.length().days();
		}
		else
			sys_err("Error in %s", __FUNCTION__);
		return result;
	};
	
	packet_mail_gc paket;
	paket.header 	= HEADER_GC_MAIL;
	paket.subheader = MAIL_SUBHEADER_ADD_DATA;
	
	unique_ptr<SQLMsg> pMsg(DBManager::Instance().DirectQuery("SELECT * FROM player.mails WHERE name='%s' ORDER BY id DESC LIMIT %d", GetName(), MAX_MAIL_COUNT));
	int count = 0, j = 0; array<int, 6> NRow = {};
	if (pMsg->Get()->uiNumRows) {
		while (MYSQL_ROW MRow = mysql_fetch_row(pMsg->Get()->pSQLResult)) {
			j = 0;
			for (auto i : {1,5,6,7,8,9}) str_to_number(NRow[j++], MRow[i]);
			j = 0;
			paket.line[NRow[4]].type = NRow[j++];
			auto item = ITEM_MANAGER::Instance().FindAtSQL(NRow[j++]);
			paket.line[NRow[4]].gold = NRow[j++];
			paket.line[NRow[4]].won = NRow[j++];
			paket.line[NRow[4]].read = NRow[++j];
			paket.line[NRow[4]].day = GetMailTime(NRow[4]);
			if (GetMailTime(NRow[4]) < 1)
				DeleteMail(NRow[4], false);
			
			if (item) {
				paket.line[NRow[4]].vnum = item->GetVnum();
				paket.line[NRow[4]].count = item->GetCount();
				#ifdef __CHANGE_LOOK_SYSTEM__
				paket.line[NRow[4]].dwVnum = item->GetItemLook();
				#endif
				thecore_memcpy(paket.line[NRow[4]].alSockets, item->GetSockets(), sizeof(paket.line[NRow[4]].alSockets));
				thecore_memcpy(paket.line[NRow[4]].aAttr, item->GetAttributes(), sizeof(paket.line[NRow[4]].aAttr));
			} else {
				paket.line[NRow[4]].vnum = 0;
				paket.line[NRow[4]].count = 0;
				#ifdef __CHANGE_LOOK_SYSTEM__
				paket.line[NRow[4]].dwVnum = 0;
				#endif
				memset(paket.line[NRow[4]].alSockets, 0, sizeof(paket.line[NRow[4]].alSockets));
				memset(paket.line[NRow[4]].aAttr, 0, sizeof(paket.line[NRow[4]].aAttr));
			}
			
			strlcpy(paket.line[NRow[4]].title, MRow[2], sizeof(paket.line[NRow[4]].title));
			strlcpy(paket.line[NRow[4]].message, MRow[3], sizeof(paket.line[NRow[4]].message));
			strlcpy(paket.line[NRow[4]].from, MRow[4], sizeof(paket.line[NRow[4]].from));
			count++;
			if (item) ITEM_MANAGER::Instance().DestroyItem(item);
		}
	}
	paket.m_count = count;
	
	GetDesc()->Packet(&paket, sizeof(paket));
}
static bool CheckMails(int id, bool all, LPCHARACTER ch)
{
	char szQuery[QUERY_MAX_LEN + 1];
	if (!all)
		snprintf(szQuery, sizeof(szQuery), "SELECT itemid, gold, won FROM player.mails WHERE id='%d' AND name='%s'", id, ch->GetName());
	else
		snprintf(szQuery, sizeof(szQuery), "SELECT itemid, gold, won FROM player.mails WHERE name='%s'", ch->GetName());
	
	unique_ptr<SQLMsg> pMsg(DBManager::Instance().DirectQuery(szQuery));
	
	auto reg = 0;
	if (pMsg->Get()->uiNumRows) {
		while (MYSQL_ROW mRow = mysql_fetch_row(pMsg->Get()->pSQLResult)) {
			for (auto i : {0, 1, 2}) {
				str_to_number(reg, mRow[i]);
				if (reg > 0)
					return false;
			}
		}
	}
	return true;
}

void CHARACTER::GetMail(int id, bool all)
{
	char szQuery[QUERY_MAX_LEN + 1];
	if (!all)
		snprintf(szQuery, sizeof(szQuery), "SELECT itemid, gold, won, type FROM player.mails WHERE id='%d' AND name='%s'", id, GetName());
	else
		snprintf(szQuery, sizeof(szQuery), "SELECT itemid, gold, won, type FROM player.mails WHERE name='%s'", GetName());
	unique_ptr<SQLMsg> pMsg(DBManager::Instance().DirectQuery(szQuery));
	
	if (!pMsg->Get()->uiNumRows) return;
	auto counter = 0, deleted = 0;
	while (MYSQL_ROW mRow = mysql_fetch_row(pMsg->Get()->pSQLResult)) {
		!all ? deleted = id : deleted = counter;
		counter++;
		array<int, 4> req;
		for (auto i : {0,1,2,3})
			str_to_number(req[i], mRow[i]);
		
		if (req[1] + GetGold() >= GOLD_MAX) {
			SendPacket(this, MAILBOX_POST_GET_ITEMS_YANG_OVERFLOW);
			continue;
		}
		if (req[2] + GetCheque() >= CHEQUE_MAX) {
			SendPacket(this, MAILBOX_POST_GET_ITEMS_WON_OVERFLOW);
			continue;
		}
		auto item = ITEM_MANAGER::Instance().FindAtSQL(req[0]);
		if (item) {
			int pos = GetEmptyInventory(item->GetSize());
			if (-1 == pos) {
				item->AddToGround (GetMapIndex(), GetXYZ());
				item->StartDestroyEvent();

				item->SetOwnership (this, 300);
			} else item->AddToCharacter(this, TItemPos(INVENTORY, pos));
		}
		auto j = 1;
		for (auto k : {POINT_GOLD, POINT_CHEQUE})
			PointChange(k, req[j++], true);
		auto type = req[3] == ICON_GM ? req[3] : ICON_POST;
		unique_ptr<SQLMsg> pMsg2(DBManager::Instance().DirectQuery("UPDATE mails%s SET type = %d gold = 0 won = 0 itemid = 0 WHERE id = %d AND name = '%s'", get_table_postfix(),type,deleted,GetName()));
		if (pMsg2->uiSQLErrno != 0) {
			sys_err("Read mail Query Failed, Error code: %ld", pMsg2->uiSQLErrno);
			return;
		}
	}
}
void CHARACTER::DeleteMail(int id, bool all)
{
	auto ReplaceMyMails = 
	[this, &id]()
	{
		unique_ptr<SQLMsg> pMsg(DBManager::Instance().DirectQuery("SELECT id FROM player.mails WHERE name='%s'", GetName()));
		if (!pMsg->Get()->uiNumRows) return;
		auto reg = 0;
		while (MYSQL_ROW mRow = mysql_fetch_row(pMsg->Get()->pSQLResult)) {
			str_to_number(reg, mRow[0]);
			if (reg > id)
				unique_ptr<SQLMsg> pMsg(DBManager::Instance().DirectQuery("UPDATE player.mails SET id='%d' WHERE id='%d' AND name='%s'", reg-1, reg, GetName()));
		}
		LoadMyMails();
	};
	char szQuery[QUERY_MAX_LEN + 1];
	if (all)
		snprintf(szQuery, sizeof(szQuery), "DELETE FROM player.mails WHERE name='%s'", GetName());
	else
		snprintf(szQuery, sizeof(szQuery), "DELETE FROM player.mails WHERE name='%s' AND id='%d'", GetName(), id);
	
	if (!CheckMails(id,all,this)) {
		SendPacket(this, MAILBOX_POST_DELETE_FAIL_EXIST_ITEMS);
		return;
	}
		
	unique_ptr<SQLMsg> pMsg(DBManager::Instance().DirectQuery(szQuery));
	if (!pMsg->Get()->uiNumRows) return;
	ReplaceMyMails();
	ChatPacket(CHAT_TYPE_INFO, Translate("DeleteMail", DEFAULT_LANG));
}

static bool AddSQL(string name, int type, string title, string message, LPCHARACTER ch, DWORD itemid, DWORD gold, DWORD won)
{	
	auto GetMailCount = [&ch]()->int 
	{
		unique_ptr<SQLMsg> pMsg(DBManager::Instance().DirectQuery("SELECT * FROM player.mails WHERE name='%s'", ch->GetName()));
		return pMsg->Get()->uiNumRows;
	};
	
	if (GetMailCount() > MAX_MAIL_COUNT) {
		return false;
	}
	unique_ptr<SQLMsg> pMsgh(DBManager::instance().DirectQuery("INSERT INTO player.mails(name, type, title, message, from, itemid, gold, won, id, isread, day, month, year)" "VALUES('%s', '%d', '%s', '%s', %s, %d, %d, %d, %d, %d, %d, %d, %d)", 
		name.c_str(), type, title.c_str(), message.c_str(), ch->IsGM() ? "GAMEMASTER" : ch->GetName(), itemid, gold, won, GetMailCount()+1, 0, date_data::day, date_data::month, date_data::year));
	return true;
}
void CHARACTER::SendMail(string title, string message, string to, DWORD itemid, DWORD gold, DWORD won)
{	
#ifdef ENABLE_MESSENGER_BLOCK
	if (MessengerManager::instance().CheckMessengerList(GetName(), to, 0))
		ChatPacket(CHAT_TYPE_INFO, "engelli bu");
#endif
	if (gold > (DWORD)GetGold()) {
		ChatPacket(CHAT_TYPE_INFO, "yeterli para yok");
		return;
	}
	if (won > (DWORD)GetCheque()) {
		ChatPacket(CHAT_TYPE_INFO, "yeterli won yok");
		return;
	}
	auto type = ICON_POST;
	auto item = ITEM_MANAGER::Instance().Find(itemid);
	if (item)
		type = ICON_ITEM;
	if (IsGM())
		type = ICON_GM;
	
	if (!AddSQL(to, type, title, message, this, itemid, gold, won)) {
		ChatPacket(CHAT_TYPE_INFO, "Karakterin %d'den fazla mesaji bulunmaz.", MAX_MAIL_COUNT);
		ChatPacket(CHAT_TYPE_INFO, "Onceki mesajlari silmesi gerekiyor.");
		return;
	}
	if (item)
		ITEM_MANAGER::Instance().DestroyItem(item);
	PointChange(POINT_GOLD, -gold);
	PointChange(POINT_CHEQUE, -won);
	ChatPacket(CHAT_TYPE_INFO, "Gonderildi");
}

void CHARACTER::SetReadMail(int id) 
{
	unique_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery("UPDATE mails%s SET isread = 1 WHERE isread = 0 AND id = %d AND name = '%s'", get_table_postfix(), id, GetName()));
	LoadMyMails();
}
#endif