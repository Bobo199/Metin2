//Find
		bool		MoveItem(BYTE bCell, BYTE bDestCell, BYTE count);
		
///Change
#if defined(__EXTENDED_SAFEBOX__)
		bool		MoveItem(DWORD bCell, DWORD bDestCell, BYTE count);
#else
		bool		MoveItem(BYTE bCell, BYTE bDestCell, BYTE count);
#endif

//Find
		LPITEM		GetItem(BYTE bCell);
		
///Change
#if defined(__EXTENDED_SAFEBOX__)
		LPITEM		GetItem(DWORD bCell);
#else
		LPITEM		GetItem(BYTE bCell);
#endif