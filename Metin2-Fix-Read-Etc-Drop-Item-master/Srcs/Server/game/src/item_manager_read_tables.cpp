// Search for:
		if (!ITEM_MANAGER::instance().GetVnumByOriginalName(szItemName, dwItemVnum))
		{
			sys_err("No such an item (name: %s)", szItemName);
			fclose(fp);
			return false;
		}
// Replace with:
#ifdef ENABLE_FIX_READ_ETC_DROP_ITEM_FILE_BY_VNUM
		if (!ITEM_MANAGER::instance().GetVnumByOriginalName(szItemName, dwItemVnum))
		{
			str_to_number(dwItemVnum, szItemName);
			if (!ITEM_MANAGER::instance().GetTable(dwItemVnum))
			{
				sys_err("No such an item (name/vnum: %s)", szItemName);
				fclose(fp);
				return false;
			}
		}
#else
		if (!ITEM_MANAGER::instance().GetVnumByOriginalName(szItemName, dwItemVnum))
		{
			sys_err("No such an item (name: %s)", szItemName);
			fclose(fp);
			return false;
		}
#endif