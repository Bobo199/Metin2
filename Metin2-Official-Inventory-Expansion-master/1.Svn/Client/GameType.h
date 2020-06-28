//Find
const DWORD c_Equipment_Start = c_ItemSlot_Count;

///Add
#ifdef ENABLE_EXTEND_INVEN_SYSTEM
const DWORD INVENTORY_OPEN_KEY_VNUM = 72319;
const DWORD INVENTORY_OPEN_KEY_VNUM2 = 72320;
const DWORD c_Inventory_Open_Page_Count = 2;
const DWORD c_Inventory_Locked_Page_Count = c_Inventory_Page_Count-c_Inventory_Open_Page_Count;
const DWORD c_Inventory_Need_Key_Start = 2;
const DWORD c_Inventory_Need_Key_Increase = 3;
#endif