//Find in : ACMD(do_item)
		iCount = MINMAX(1, iCount, ITEM_MAX_COUNT);
		
///Change
		iCount = MAX(1, abs(iCount));
		
//Find
	LPITEM item = ITEM_MANAGER::instance().CreateItem(dwVnum, iCount, 0, true);

	if (item)
	{
		....
		....
		....
	}
	else
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "#%u item not exist by that vnum.", dwVnum);
	}
	
///Change All
	while (iCount > 0) {
		const auto& item = ITEM_MANAGER::instance().CreateItem(dwVnum, iCount, 0, true);
		if (!item) {
			ch->ChatPacket(CHAT_TYPE_INFO, "#%u item not exist by that vnum.", dwVnum);
			return;
		}
		const auto iEmptyPos = item->IsDragonSoul() ? ch->GetEmptyDragonSoulInventory(item) : ch->GetEmptyInventory(item->GetSize());
		if (iEmptyPos == -1) {
			ch->ChatPacket(CHAT_TYPE_INFO, "Not enough %s space.", item->IsDragonSoul() ? "dragonsoul" : "inventory");
			ITEM_MANAGER::instance().DestroyItem(item);
			return;
		}
		item->AddToCharacter(ch, TItemPos(item->IsDragonSoul() ? DRAGON_SOUL_INVENTORY : INVENTORY, iEmptyPos));
		LogManager::instance().ItemLog(ch, item, "GM", item->GetName());
		iCount -= item->IsStackable() ? ITEM_MAX_COUNT : 1;
	}

//Find
ACMD(do_book)
{
	...
	...
}

///Change all
ACMD(do_book)
{
	char arg1[256], arg2[256];
	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));

	CSkillProto * pkProto;
	if (*arg1 && isnhdigit(*arg1)) {
		const DWORD vnum = std::stoul(arg1);
		pkProto = CSkillManager::instance().Get(vnum);
	}
	else 
		pkProto = CSkillManager::instance().Get(arg1);

	if (!pkProto) {
		ch->ChatPacket(CHAT_TYPE_INFO, "There is no such a skill.");
		return;
	}

	int count = 1;
	if (*arg2 && isnhdigit(*arg2))
		count = std::stoi(arg2);

	while (count > 0) {
		const LPITEM item = ch->AutoGiveItem(50300, count > ITEM_MAX_COUNT ? ITEM_MAX_COUNT : count);
		if (!item)
			return;
		item->SetSocket(0, pkProto->dwVnum);
		count-= ITEM_MAX_COUNT;
	}
}
