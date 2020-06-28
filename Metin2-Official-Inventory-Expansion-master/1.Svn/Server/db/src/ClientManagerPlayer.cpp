//Find
"horse_skill_point = %d, ",

///Change
"horse_skill_point = %d, " "envanter = %d, ",

//Find
pkTab->horse_skill_point);

///Change
pkTab->horse_skill_point, pkTab->envanter);

//Find
"horse_skill_point"

///Add
",envanter"

//Find
	str_to_number(pkTab->horse_skill_point, row[col++]);

///Add
	str_to_number(pkTab->envanter, row[col++]);
	
//Find in: void CClientManager::__QUERY_PLAYER_CREATE(CPeer *peer, DWORD dwHandle, TPlayerCreatePacket* packet)
	gold,
	
///Change
	gold, envanter,
	
//Find
	%d, 0, ",
	
///Change
	%d, %d, 0, ",
	
//Find
	packet->player_table.gold);
	
///Change
	packet->player_table.gold, packet->player_table.envanter);