//Find
LPITEM CSafebox::GetItem(BYTE bCell)

///Change
#if defined(__EXTENDED_SAFEBOX__)
LPITEM CSafebox::GetItem(DWORD bCell)
#else
LPITEM CSafebox::GetItem(BYTE bCell)
#endif

//Find
bool CSafebox::MoveItem(BYTE bCell, BYTE bDestCell, BYTE count)

///Change
#if defined(__EXTENDED_SAFEBOX__)		
bool CSafebox::MoveItem(DWORD bCell, DWORD bDestCell, BYTE count)
#else
bool CSafebox::MoveItem(BYTE bCell, BYTE bDestCell, BYTE count)
#endif