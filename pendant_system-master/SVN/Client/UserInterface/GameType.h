// Search

	const DWORD c_Equipment_Belt  = c_New_Equipment_Start + 2;
#endif


// And after do you need put the position for PENDANT = for you SERVER, for example, my case is:

#ifdef ITEM_TALISMAN_EQUIPMENT
	const DWORD c_Equipment_Pendant = 27;
#endif


// Search

const DWORD c_Costume_Slot_Count = 4;

// Replace for

#ifdef ENABLE_AURA_COSTUME_SYSTEM
	const DWORD c_Costume_Slot_Count	= 5;
#else
	const DWORD c_Costume_Slot_Count = 4;
#endif