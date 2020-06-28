//Find
		bool SendSafeBoxCheckinPacket(TItemPos InventoryPos, BYTE bySafeBoxPos);
		bool SendSafeBoxCheckoutPacket(BYTE bySafeBoxPos, TItemPos InventoryPos);
		bool SendSafeBoxItemMovePacket(BYTE bySourcePos, BYTE byTargetPos, BYTE byCount);
		bool SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos);
		
///Change
#if defined(__EXTENDED_SAFEBOX__)
		bool SendSafeBoxCheckinPacket(TItemPos InventoryPos, DWORD bySafeBoxPos);
		bool SendSafeBoxCheckoutPacket(DWORD bySafeBoxPos, TItemPos InventoryPos);
		bool SendSafeBoxItemMovePacket(DWORD bySourcePos, DWORD byTargetPos, BYTE byCount);
		bool SendMallCheckoutPacket(DWORD byMallPos, TItemPos InventoryPos);
#else
		bool SendSafeBoxCheckinPacket(TItemPos InventoryPos, BYTE bySafeBoxPos);
		bool SendSafeBoxCheckoutPacket(BYTE bySafeBoxPos, TItemPos InventoryPos);
		bool SendSafeBoxItemMovePacket(BYTE bySourcePos, BYTE byTargetPos, BYTE byCount);
		bool SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos);
#endif