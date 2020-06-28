//Find
		BYTE		GetAttributeType(int i)	{ return m_aAttr[i].bType;	}
		
///Add
#ifdef ENABLE_SORT_INVEN
		const int CustomSort() const {
			switch (m_pProto->bType) {
				case ITEM_WEAPON:	return 1;
				case ITEM_ARMOR:	return 2;
				case ITEM_USE:	return 3;
				case ITEM_BELT:	return 4;
				case ITEM_COSTUME:	return 5;
				case ITEM_SKILLBOOK:
				case ITEM_SKILLFORGET:	return 6;
			}
			return 7;
		}
#endif
