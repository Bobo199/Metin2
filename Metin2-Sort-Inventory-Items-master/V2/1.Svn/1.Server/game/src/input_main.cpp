//Find
void CInputMain::ItemMove(LPCHARACTER ch, const char * data)
{
	struct command_item_move * pinfo = (struct command_item_move *) data;

	if (ch)
		ch->MoveItem(pinfo->Cell, pinfo->CellTo, pinfo->count);
}

///Add
#ifdef ENABLE_SORT_INVEN
void CInputMain::SortInven(LPCHARACTER ch, const char * data)
{
	TPacketCGSortInven * pinfo = (TPacketCGSortInven *) data;
	if (ch) ch->SortInven(pinfo->option);
}
#endif

//Find
		case HEADER_CG_ITEM_MOVE:
			if (!ch->IsObserverMode())
				ItemMove(ch, c_pData);
			break;
			
///Add
#ifdef ENABLE_SORT_INVEN
		case SORT_INVEN:
			if (!ch->IsObserverMode())
				SortInven(ch, c_pData);
		break;
#endif