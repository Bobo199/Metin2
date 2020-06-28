///Add
#if defined(__COMPARE_TOOLTIP__)
static const std::map<BYTE, std::map<BYTE, BYTE>> m_mapItemSlotIndex =
{
	{
		CItemData::ITEM_TYPE_ARMOR,
		{
			{ CItemData::ARMOR_BODY, c_Equipment_Body },
			{ CItemData::ARMOR_HEAD, c_Equipment_Head },
			{ CItemData::ARMOR_SHIELD, c_Equipment_Shield },
			{ CItemData::ARMOR_WRIST, c_Equipment_Wrist },
			{ CItemData::ARMOR_FOOTS, c_Equipment_Shoes },
			{ CItemData::ARMOR_NECK, c_Equipment_Neck },
			{ CItemData::ARMOR_EAR, c_Equipment_Ear },
			#if defined(ENABLE_PENDANT)
			{ CItemData::ARMOR_PENDANT, c_Equipment_Pendant },
			#endif
		}
	},

	{
		CItemData::ITEM_TYPE_COSTUME,
		{
			{ CItemData::COSTUME_BODY, c_Costume_Slot_Body },
			{ CItemData::COSTUME_HAIR, c_Costume_Slot_Hair },
			#if defined(ENABLE_MOUNT_COSTUME_SYSTEM)
			{ CItemData::COSTUME_MOUNT, c_Costume_Slot_Mount },
			#endif	
			#if defined(ENABLE_ACCE_COSTUME_SYSTEM)
			{ CItemData::COSTUME_ACCE, c_Costume_Slot_Acce },
			#endif
			#if defined(ENABLE_WEAPON_COSTUME_SYSTEM)
			{ CItemData::COSTUME_WEAPON, c_Costume_Slot_Weapon },
			#endif
		}
	},
};

PyObject* itemGetCompareIndex(PyObject* poSelf, PyObject* poArgs)
{
	int iVnum;
	if (!PyTuple_GetInteger(poArgs, 0, &iVnum))
		return Py_BadArgument();

	CItemData * pItemData;
	CItemManager::Instance().GetItemDataPointer(iVnum, &pItemData);

	const auto& bItemType = pItemData->GetType();
	const auto& bItemSubType = pItemData->GetSubType();

	switch (bItemType)
	{
		case CItemData::ITEM_TYPE_WEAPON:
			return Py_BuildValue("i", c_Equipment_Weapon);
		case CItemData::ITEM_TYPE_BELT:
			return Py_BuildValue("i", c_Equipment_Belt);
		default:
			const auto& itType = m_mapItemSlotIndex.find(bItemType);
			if (itType != m_mapItemSlotIndex.end())
			{
				const auto& itSubType = itType->second.find(bItemSubType);
				if (itSubType != itType->second.end())
					return Py_BuildValue("i", itSubType->second);
			}
	};

	return Py_BuildValue("i", 0);
}
#endif

//Find
		{ NULL,								NULL,									NULL		 },
		
///Add Below
#if defined(__COMPARE_TOOLTIP__)		
		{ "GetCompareIndex",				itemGetCompareIndex,					METH_VARARGS },
#endif