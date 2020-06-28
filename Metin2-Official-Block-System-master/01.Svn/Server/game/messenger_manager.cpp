//Find
void MessengerManager::Login(MessengerManager::keyA account)
{
	if (m_set_loginAccount.find(account) != m_set_loginAccount.end())
		return;

	DBManager::instance().FuncQuery(std::bind1st(std::mem_fun(&MessengerManager::LoadList), this),
			"SELECT account, companion FROM messenger_list%s WHERE account='%s'", get_table_postfix(), account.c_str());

	m_set_loginAccount.insert(account);
}

///Replace
void MessengerManager::Login(MessengerManager::keyA account)
{
	if (m_set_loginAccount.find(account) != m_set_loginAccount.end())
		return;

	DBManager::instance().FuncQuery(std::bind1st(std::mem_fun(&MessengerManager::LoadList), this),
			"SELECT account, companion FROM messenger_list%s WHERE account='%s'", get_table_postfix(), account.c_str());
#ifdef ENABLE_MESSENGER_BLOCK
	DBManager::instance().FuncQuery(std::bind1st(std::mem_fun(&MessengerManager::LoadBlockList), this),
			"SELECT account, companion FROM messenger_block_list%s WHERE account='%s'", get_table_postfix(), account.c_str());
#endif

	m_set_loginAccount.insert(account);
}

//Find
void MessengerManager::LoadList(SQLMsg * msg)
{
	.....
	
}

///Add
#ifdef ENABLE_MESSENGER_BLOCK
bool MessengerManager::CheckMessengerList(std::string ch, std::string tch, BYTE type)
{
	const char* check = type == SYST_BLOCK ? "messenger_block_list" : "messenger_list";
	// std::unique_ptr<SQLMsg> msg(DBManager::Instance().DirectQuery("SELECT * FROM player.%s", check));
	std::auto_ptr<SQLMsg> msg(DBManager::Instance().DirectQuery("SELECT * FROM player.%s", check));
	if (!msg->Get()->uiNumRows)
		return false;
	
	for (int i = 0; i < (int)msg->Get()->uiNumRows; ++i) {
		MYSQL_ROW row = mysql_fetch_row(msg->Get()->pSQLResult);
		if ((row[0] == ch and row[1] == tch) or (row[1] == ch and row[0] == tch))
			return true;
	}
	return false;
}
void MessengerManager::LoadBlockList(SQLMsg * msg)
{
	if (NULL == msg or NULL == msg->Get() or msg->Get()->uiNumRows == 0)
		return;
	
	std::string account;

	for (uint i = 0; i < msg->Get()->uiNumRows; ++i)
	{
		MYSQL_ROW row = mysql_fetch_row(msg->Get()->pSQLResult);

		if (row[0] && row[1])
		{
			if (account.length() == 0)
				account = row[0];

			m_BlockRelation[row[0]].insert(row[1]);
			m_InverseBlockRelation[row[1]].insert(row[0]);
		}
	}

	SendBlockList(account);

	std::set<MessengerManager::keyBL>::iterator it;

	for (it = m_InverseBlockRelation[account].begin(); it != m_InverseBlockRelation[account].end(); ++it)
		SendBlockLogin(*it, account);
}
void MessengerManager::SendBlockList(MessengerManager::keyA account)
{
	LPCHARACTER ch = CHARACTER_MANAGER::instance().FindPC(account.c_str());

	if (!ch)
		return;

	LPDESC d = ch->GetDesc();

	// if (!d or m_BlockRelation.find(account) == m_BlockRelation.end() or m_BlockRelation[account].empty())
	if (!d)
		return;

	TPacketGCMessenger pack;

	pack.header		= HEADER_GC_MESSENGER;
	pack.subheader	= MESSENGER_SUBHEADER_GC_BLOCK_LIST;
	pack.size		= sizeof(TPacketGCMessenger);

	TPacketGCMessengerBlockListOffline pack_offline;
	TPacketGCMessengerBlockListOnline pack_online;

	TEMP_BUFFER buf(128 * 1024); // 128k

	itertype(m_BlockRelation[account]) it = m_BlockRelation[account].begin(), eit = m_BlockRelation[account].end();

	while (it != eit)
	{
		if (m_set_loginAccount.find(*it) != m_set_loginAccount.end())
		{
			pack_online.connected = 1;

			// Online
			pack_online.length = it->size();

			buf.write(&pack_online, sizeof(TPacketGCMessengerBlockListOnline));
			buf.write(it->c_str(), it->size());
		}
		else
		{
			pack_offline.connected = 0;

			// Offline
			pack_offline.length = it->size();

			buf.write(&pack_offline, sizeof(TPacketGCMessengerBlockListOffline));
			buf.write(it->c_str(), it->size());
		}

		++it;
	}

	pack.size += buf.size();

	d->BufferedPacket(&pack, sizeof(TPacketGCMessenger));
	d->Packet(buf.read_peek(), buf.size());
}
void MessengerManager::SendBlockLogin(MessengerManager::keyA account, MessengerManager::keyA companion)
{
	LPCHARACTER ch = CHARACTER_MANAGER::instance().FindPC(account.c_str());
	LPDESC d = ch ? ch->GetDesc() : NULL;

	if (!d)
		return;

	if (!d->GetCharacter())
		return;

	BYTE bLen = companion.size();

	TPacketGCMessenger pack;

	pack.header			= HEADER_GC_MESSENGER;
	pack.subheader		= MESSENGER_SUBHEADER_GC_BLOCK_LOGIN;
	pack.size			= sizeof(TPacketGCMessenger) + sizeof(BYTE) + bLen;

	d->BufferedPacket(&pack, sizeof(TPacketGCMessenger));
	d->BufferedPacket(&bLen, sizeof(BYTE));
	d->Packet(companion.c_str(), companion.size());
}

void MessengerManager::SendBlockLogout(MessengerManager::keyA account, MessengerManager::keyA companion)
{
	if (!companion.size())
		return;

	LPCHARACTER ch = CHARACTER_MANAGER::instance().FindPC(account.c_str());
	LPDESC d = ch ? ch->GetDesc() : NULL;

	if (!d)
		return;

	BYTE bLen = companion.size();

	TPacketGCMessenger pack;

	pack.header		= HEADER_GC_MESSENGER;
	pack.subheader	= MESSENGER_SUBHEADER_GC_BLOCK_LOGOUT;
	pack.size		= sizeof(TPacketGCMessenger) + sizeof(BYTE) + bLen;

	d->BufferedPacket(&pack, sizeof(TPacketGCMessenger));
	d->BufferedPacket(&bLen, sizeof(BYTE));
	d->Packet(companion.c_str(), companion.size());
}
///not compleated

void MessengerManager::AddToBlockList(MessengerManager::keyA account, MessengerManager::keyA companion)
{
	if (companion.size() == 0)
		return;

	if (m_BlockRelation[account].find(companion) != m_BlockRelation[account].end())
		return;

	// sys_log(0, "Messenger Add %s %s", account.c_str(), companion.c_str());
	DBManager::instance().Query("INSERT INTO messenger_block_list%s VALUES ('%s', '%s', NOW())", 
			get_table_postfix(), account.c_str(), companion.c_str());

	__AddToBlockList(account, companion);

	TPacketGGMessenger p2ppck;

	p2ppck.bHeader = HEADER_GG_MESSENGER_BLOCK_ADD;
	strlcpy(p2ppck.szAccount, account.c_str(), sizeof(p2ppck.szAccount));
	strlcpy(p2ppck.szCompanion, companion.c_str(), sizeof(p2ppck.szCompanion));
	P2P_MANAGER::instance().Send(&p2ppck, sizeof(TPacketGGMessenger));
}
void MessengerManager::__AddToBlockList(MessengerManager::keyA account, MessengerManager::keyA companion)
{
	//yeni eklerken
	m_BlockRelation[account].insert(companion);
	m_InverseBlockRelation[companion].insert(account);

	LPCHARACTER ch = CHARACTER_MANAGER::instance().FindPC(account.c_str());
	LPDESC d = ch ? ch->GetDesc() : NULL;

	if (d)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s bloklandi"), companion.c_str());
	}

	LPCHARACTER tch = CHARACTER_MANAGER::instance().FindPC(companion.c_str());

	if (tch)
		SendBlockLogin(account, companion);
	else
		SendBlockLogout(account, companion);
}
void MessengerManager::RemoveFromBlockList(MessengerManager::keyA account, MessengerManager::keyA companion)
{
	if (companion.size() == 0)
		return;

	// sys_log(1, "Messenger Remove %s %s", account.c_str(), companion.c_str());
	DBManager::instance().Query("DELETE FROM messenger_block_list%s WHERE account='%s' AND companion = '%s'",
	get_table_postfix(), account.c_str(), companion.c_str());
			
	__RemoveFromBlockList(account, companion);

	TPacketGGMessenger p2ppck;

	p2ppck.bHeader = HEADER_GG_MESSENGER_BLOCK_REMOVE;
	strlcpy(p2ppck.szAccount, account.c_str(), sizeof(p2ppck.szAccount));
	strlcpy(p2ppck.szCompanion, companion.c_str(), sizeof(p2ppck.szCompanion));
	P2P_MANAGER::instance().Send(&p2ppck, sizeof(TPacketGGMessenger));
}
void MessengerManager::__RemoveFromBlockList(MessengerManager::keyA account, MessengerManager::keyA companion)
{
	m_BlockRelation[account].erase(companion);
	m_InverseBlockRelation[companion].erase(account);

	LPCHARACTER ch = CHARACTER_MANAGER::instance().FindPC(account.c_str());
	LPDESC d = ch ? ch->GetDesc() : NULL;

	if (d)
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<메신져> %s 님을 메신저에서 삭제하였습니다."), companion.c_str());
}
void MessengerManager::RemoveAllBlockList(keyA account)
{
	std::set<keyBL>	company(m_BlockRelation[account]);

	DBManager::instance().Query("DELETE FROM messenger_block_list%s WHERE account='%s' OR companion='%s'",
			get_table_postfix(), account.c_str(), account.c_str());

	for (std::set<keyT>::iterator iter = company.begin(); iter != company.end(); iter++)
	{
		this->RemoveFromList(account, *iter);
	}

	for (std::set<keyBL>::iterator iter = company.begin(); iter != company.end();)
	{
		company.erase(iter++);
	}

	company.clear();
}
#endif

//Find
	for (it = m_InverseRelation[account].begin(); it != m_InverseRelation[account].end(); ++it)
	{
		SendLogout(*it, account);
	}

	std::map<keyT, std::set<keyT> >::iterator it2 = m_Relation.begin();

	while (it2 != m_Relation.end())
	{
		it2->second.erase(account);
		++it2;
	}
	
///Add
	#ifdef ENABLE_MESSENGER_BLOCK
	std::set<MessengerManager::keyBL>::iterator it61;
	
	for (it61 = m_InverseBlockRelation[account].begin(); it61 != m_InverseBlockRelation[account].end(); ++it61)
	{
		SendBlockLogout(*it61, account);
	}

	std::map<keyBL, std::set<keyBL> >::iterator it3 = m_BlockRelation.begin();

	while (it3 != m_BlockRelation.end())
	{
		it3->second.erase(account);
		++it3;
	}
	m_BlockRelation.erase(account);
	#endif
