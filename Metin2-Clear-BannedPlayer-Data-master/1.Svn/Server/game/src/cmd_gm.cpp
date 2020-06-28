///Add
const std::map<const char*, const char*> _Deleter
{
	{"log.log", "who"},
	{"log.cube", "pid"},
	{"log.goldlog", "pid"},
	{"log.levellog", "pid"},
	{"log.speedhack", "pid"},
	{"log.refinelog", "pid"},
	{"log.quest_reward_log", "2"},
	{"log.loginlog", "pid"},
	{"log.loginlog2", "pid"},
	{"log.goldlog", "pid"},
	{"player.item", "owner_id"},
	{"player.player", "id"},
	{"player.guild_member", "pid"},
	{"player.affect", "dwPID"}
};
ACMD(do_clean)
{
	std::array<MYSQL_ROW, 2> row;
	std::unique_ptr<SQLMsg> msg(DBManager::instance().DirectQuery("SELECT id FROM account.account WHERE availDt - NOW() > 0"));
	while ((row[0] = mysql_fetch_row(msg->Get()->pSQLResult))) {
		DBManager::instance().DirectQuery("DELETE FROM player.player_index WHERE id = %d", std::atoi(row[0][0]));
		std::unique_ptr<SQLMsg> msg2(DBManager::instance().DirectQuery("SELECT id FROM player.player WHERE account_id='%d'", std::atoi(row[0][0])));
		while ((row[1] = mysql_fetch_row(msg2->Get()->pSQLResult)))
			for (const auto& [table, where] : _Deleter)
				DBManager::instance().DirectQuery("DELETE FROM %s WHERE %s = %d", table,where,std::atoi(row[1][0]));
	}
}
