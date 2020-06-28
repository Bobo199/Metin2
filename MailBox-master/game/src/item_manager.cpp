#ifdef MAILING_SYSTEM
LPITEM ITEM_MANAGER::FindAtSQL(DWORD id)
{
	std::unique_ptr<SQLMsg> msg(DBManager::instance().DirectQuery("SELECT vnum, count, dwVnum, attrtype0, attrtype1, attrtype2, attrtype3, attrtype4, attrtype5, attrtype6, attrvalue0, attrvalue1, attrvalue2, attrvalue3, attrvalue4, attrvalue5, attrvalue6, socket0, socket1, socket2 FROM player.item WHERE id = '%u'", id));
	
	if (!msg->Get()->uiNumRows) return NULL;
	
	const int MAX_ATTR = MAX_NORM_ATTR_NUM + MAX_RARE_ATTR_NUM;
	std::array<DWORD, 3> data;
	std::array<unsigned int, MAX_ATTR> attr_vals;
	std::array<unsigned int, MAX_ATTR> attr_types;
	std::array<unsigned int, ITEM_SOCKET_MAX_NUM> sockets;
	auto counter = 0;
	MYSQL_ROW row = mysql_fetch_row(msg->Get()->pSQLResult);
	for (auto i : {0,1,2})
		str_to_number(data[i], row[i]);

	auto newitem = CreateItem(data[0],data[1]);
	if (!newitem) return NULL;
#ifdef __CHANGE_LOOK_SYSTEM__
	newitem->SetItemLook(data[2]);
#endif
	newitem->ClearAttribute();
	
	for (auto &j : {3,4,5,6,7,8,9}) {
		str_to_number(attr_types[counter], row[j]);
		counter++;
	}
	counter = 0;
	for (auto &k : {10,11,12,13,14,15,16}) {
		str_to_number(attr_vals[counter], row[k]);
		counter++;
	}
	counter = 0;
	for (auto &l : {17,18,19}) {
		str_to_number(sockets[counter], row[l]);
		counter++;
	}
	for (auto i = 0; i < MAX_ATTR; i++)
		newitem->SetForceAttribute(i, attr_types[i], attr_vals[i]);
	for (auto c = 0; c < ITEM_SOCKET_MAX_NUM; c++)
		newitem->SetSocket(c, sockets[c]);
	
	return newitem;
}
#endif
