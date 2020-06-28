//Find
bool CPythonNetworkStream::SendSafeBoxCheckinPacket(TItemPos InventoryPos, BYTE bySafeBoxPos)

///Change
#if defined(__EXTENDED_SAFEBOX__)
bool CPythonNetworkStream::SendSafeBoxCheckinPacket(TItemPos InventoryPos, DWORD bySafeBoxPos)
#else
bool CPythonNetworkStream::SendSafeBoxCheckinPacket(TItemPos InventoryPos, BYTE bySafeBoxPos)
#endif

//Find
bool CPythonNetworkStream::SendSafeBoxCheckoutPacket(BYTE bySafeBoxPos, TItemPos InventoryPos)

///Change
#if defined(__EXTENDED_SAFEBOX__)
bool CPythonNetworkStream::SendSafeBoxCheckoutPacket(DWORD bySafeBoxPos, TItemPos InventoryPos)
#else
bool CPythonNetworkStream::SendSafeBoxCheckoutPacket(BYTE bySafeBoxPos, TItemPos InventoryPos)
#endif

//Find
bool CPythonNetworkStream::SendSafeBoxItemMovePacket(BYTE bySourcePos, BYTE byTargetPos, BYTE byCount)

///Change
#if defined(__EXTENDED_SAFEBOX__)
bool CPythonNetworkStream::SendSafeBoxItemMovePacket(DWORD bySourcePos, DWORD byTargetPos, BYTE byCount)
#else
bool CPythonNetworkStream::SendSafeBoxItemMovePacket(BYTE bySourcePos, BYTE byTargetPos, BYTE byCount)
#endif

//Find
bool CPythonNetworkStream::SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos)

///Change
#if defined(__EXTENDED_SAFEBOX__)
bool CPythonNetworkStream::SendMallCheckoutPacket(DWORD byMallPos, TItemPos InventoryPos)
#else
bool CPythonNetworkStream::SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos)
#endif