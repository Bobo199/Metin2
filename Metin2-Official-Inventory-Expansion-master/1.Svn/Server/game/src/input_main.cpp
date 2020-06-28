//Find
void CInputMain::ItemMove(LPCHARACTER ch, const char * data)
{
	struct command_item_move * pinfo = (struct command_item_move *) data;

	if (ch)
		ch->MoveItem(pinfo->Cell, pinfo->CellTo, pinfo->count);
}

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
void CInputMain::InventoryExpansion(LPCHARACTER ch, const char * data)
{
    if (ch) 
		ch->Update_Inven();
}
#endif

//Find
		case HEADER_CG_ITEM_MOVE:
			if (!ch->IsObserverMode())
				ItemMove(ch, c_pData);
			break;
	
///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
		case ENVANTER_BLACK:
			if (!ch->IsObserverMode())
				InventoryExpansion(ch, c_pData);
		break;
#endif

//Find
	if (p->pos >= INVENTORY_MAX_NUM)
		
///Change
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	if (p->pos >= ch->Inventory_Size())
#else
	if (p->pos >= INVENTORY_MAX_NUM)
#endif

//Find
	if (pkItem->GetCell() >= INVENTORY_MAX_NUM && IS_SET(pkItem->GetFlag(), ITEM_FLAG_IRREMOVABLE))
		
///Chnage
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
	if (pkItem->GetCell() >= ch->Inventory_Size() && IS_SET(pkItem->GetFlag(),ITEM_FLAG_IRREMOVABLE))
#else
	if (pkItem->GetCell() >= INVENTORY_MAX_NUM && IS_SET(pkItem->GetFlag(), ITEM_FLAG_IRREMOVABLE))
#endif