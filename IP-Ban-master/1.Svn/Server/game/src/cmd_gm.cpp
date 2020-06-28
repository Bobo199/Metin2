///Add
#ifdef _ENABLE_IPBAN_
#include "ip_ban.h"
#endif

///Add anywhere
#ifdef _ENABLE_IPBAN_
void do_ipban(LPCHARACTER ch, const char *argument, int cmd, int subcmd)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));
	if (!*arg1) {
		ch->ChatPacket(CHAT_TYPE_INFO, "Usage: ipban <name>");
		return;
	}
	LPDESC d = DESC_MANAGER::instance().FindByCharacterName(arg1);
	if (d && d->GetCharacter()) {
		if (ch == d->GetCharacter()) {
			ch->ChatPacket(CHAT_TYPE_INFO, "Do not ban yourself!");
			return;
		}
		if (d->GetCharacter()->IsGM()) {
			ch->ChatPacket(CHAT_TYPE_INFO, "Do not ban a GameMaster!");
			return;
		}
		std::unique_ptr<SQLMsg> msg(DBManager::instance().DirectQuery("SELECT ip FROM player.player WHERE name = '%s'", d->GetCharacter()->GetName()));
		if (msg->Get()->uiNumRows) {
			const auto row = mysql_fetch_row(msg->Get()->pSQLResult);
			AddBanIP(row[0]);
			ch->ChatPacket(CHAT_TYPE_INFO, "%s banned, ip: %s", d->GetCharacter()->GetName(), row[0]);
			DESC_MANAGER::instance().DestroyDesc(d);
		}
		else
			ch->ChatPacket(CHAT_TYPE_INFO, "error wtf!!?");
	}
	else
		ch->ChatPacket(CHAT_TYPE_INFO, "Cannot find %s", arg1);
}
#endif