//Find
void CInputMain::ItemUse(LPCHARACTER ch, const char * data)
{
	if (ch)
		ch->UseItem(((struct command_item_use *) data)->Cell);
}

///Add
#ifdef ENABLE_CHECK_INSULT
void CInputMain::BlockChatInsult(LPCHARACTER ch, const char * data)
{
    long bantime = 60 * 1; // 1 minute
    // long bantime = 60 * 60; // 1 hour
    // long bantime = 60 * 60 * 24; // 1 day
	if (ch)
		ch->AddAffect(AFFECT_BLOCK_CHAT, POINT_NONE, 0, AFF_NONE, bantime, 0, true);
}
#endif

//Find
		case HEADER_CG_ITEM_USE:
			if (!ch->IsObserverMode())
				ItemUse(ch, c_pData);
			break;
			
///Add
	#ifdef ENABLE_CHECK_INSULT
		case HEADER_CG_INSULT_BLOCK:
            if (!ch->IsObserverMode())
                BlockChatInsult(ch, c_pData);
        break;
	#endif