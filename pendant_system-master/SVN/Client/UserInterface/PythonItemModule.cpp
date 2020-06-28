// Search

#ifdef ENABLE_NEW_EQUIPMENT_SYSTEM
	PyModule_AddIntConstant(poModule, "EQUIPMENT_RING1",			c_Equipment_Ring1);
	PyModule_AddIntConstant(poModule, "EQUIPMENT_RING2",			c_Equipment_Ring2);
	PyModule_AddIntConstant(poModule, "EQUIPMENT_BELT",				c_Equipment_Belt);
#endif

// Add after

#ifdef ITEM_TALISMAN_EQUIPMENT
	PyModule_AddIntConstant(poModule, "EQUIPMENT_PENDANT", c_Equipment_Pendant);
#endif

// Search


	PyModule_AddIntConstant(poModule, "WEARABLE_ARROW",				CItemData::WEARABLE_ARROW);

// Add after

#ifdef ITEM_TALISMAN_EQUIPMENT
	PyModule_AddIntConstant(poModule, "WEARABLE_PENDANT",				CItemData::WEARABLE_PENDANT);
#endif

// Search

	PyModule_AddIntConstant(poModule, "ARMOR_EAR",					CItemData::ARMOR_EAR);

// Add after

#ifdef ITEM_TALISMAN_EQUIPMENT
	PyModule_AddIntConstant(poModule,	"ARMOR_PENDANT",	CItemData::ARMOR_PENDANT);
#endif
