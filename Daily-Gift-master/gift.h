#define GUNLUK_ITEM
#ifdef GUNLUK_ITEM
	int min_level = 50;
	int bl_items[] = { 299, 469, 19, 289, 279 };
	int gun = 86400;
	const char* asdasfv = "gunluk.hediye";
	if ((get_global_time() - ch->GetQuestFlag(asdasfv)) >= gun && ch->GetLevel() >= min_level)
	{
		int a_ite = number(0, _countof(bl_items));
		int a_gol = number(20, ch->GetLevel() * 1000);
		ch->AutoGiveItem(bl_items[a_ite]);
		ch->ChatPacket(CHAT_TYPE_INFO, "Gunluk hediye aldin, hediyen %s", ITEM_MANAGER::instance().GetTable(bl_items[a_ite])->szLocaleName);
		ch->SetQuestFlag(asdasfv, get_global_time());
		if (a_gol % 2 != 0)
			a_gol--;
		ch->GiveGold(a_gol);
	}
#endif
