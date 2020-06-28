// Search

									switch( item2->GetType() )
									{
										case ITEM_WEAPON:
											break;
										case ITEM_ARMOR:
											switch (item2->GetSubType())
											{
											case ARMOR_EAR:
											case ARMOR_WRIST:
											case ARMOR_NECK:

// Add after

#ifdef ITEM_TALISMAN_EQUIPMENT
											case ARMOR_PENDANT:
#endif

//Search

									else
									{
										// ??? ????
										// ??? ??? ?? ???? ?? ?? ???.
										if (item->GetVnum() == 71151 || item->GetVnum() == 76023)
										{
											if ((item2->GetType() == ITEM_WEAPON)
												|| (item2->GetType() == ITEM_ARMOR && item2->GetSubType() == ARMOR_BODY))

// Replace with

									else
									{
										// ??? ????
										// ??? ??? ?? ???? ?? ?? ???.
										if (item->GetVnum() == 71151 || item->GetVnum() == 76023)
										{
#ifdef ITEM_TALISMAN_EQUIPMENT
											if ((item2->GetType() == ITEM_WEAPON)
												|| ((item2->GetType() == ITEM_ARMOR && item2->GetSubType() == ARMOR_BODY) || (item2->GetType() == ITEM_ARMOR && item2->GetSubType() == ARMOR_PENDANT)))
#else
											if ((item2->GetType() == ITEM_WEAPON)
												|| (item2->GetType() == ITEM_ARMOR && item2->GetSubType() == ARMOR_BODY))
#endif

// Search

									if (item2->GetAttributeCount() < 4)
									{
										// ??? ????
										// ??? ??? ?? ???? ?? ?? ???.
										if (item->GetVnum() == 71152 || item->GetVnum() == 76024)
										{
											if ((item2->GetType() == ITEM_WEAPON)
												|| (item2->GetType() == ITEM_ARMOR && item2->GetSubType() == ARMOR_BODY))

// Replace With

									if (item2->GetAttributeCount() < 4)
									{
										// ??? ????
										// ??? ??? ?? ???? ?? ?? ???.
										if (item->GetVnum() == 71152 || item->GetVnum() == 76024)
										{
#ifdef ITEM_TALISMAN_EQUIPMENT
											if ((item2->GetType() == ITEM_WEAPON)
												|| ((item2->GetType() == ITEM_ARMOR && item2->GetSubType() == ARMOR_BODY) || (item2->GetType() == ITEM_ARMOR && item2->GetSubType() == ARMOR_PENDANT)))
#else
											if ((item2->GetType() == ITEM_WEAPON)
												|| (item2->GetType() == ITEM_ARMOR && item2->GetSubType() == ARMOR_BODY))
#endif

// Search

		case BLACKSMITH_ARMOR_MOB:
		case DEVILTOWER_BLACKSMITH_ARMOR_MOB:
			if (item->GetType() == ITEM_ARMOR &&
					(item->GetSubType() == ARMOR_BODY || item->GetSubType() == ARMOR_SHIELD || item->GetSubType() == ARMOR_HEAD || item->GetSubType() == ARMOR_PENDANT) &&
					item->GetRefinedVnum())

//Replace the condition "if" with

#ifdef ITEM_TALISMAN_EQUIPMENT
			if (item->GetType() == ITEM_ARMOR &&
					(item->GetSubType() == ARMOR_BODY || item->GetSubType() == ARMOR_SHIELD || item->GetSubType() == ARMOR_HEAD || item->GetSubType() == ARMOR_PENDANT) &&
					item->GetRefinedVnum())
#else
			if (item->GetType() == ITEM_ARMOR &&
					(item->GetSubType() == ARMOR_BODY || item->GetSubType() == ARMOR_SHIELD || item->GetSubType() == ARMOR_HEAD) &&
					item->GetRefinedVnum())

#endif

// Search

		case BLACKSMITH_ACCESSORY_MOB:
		case DEVILTOWER_BLACKSMITH_ACCESSORY_MOB:
			if (item->GetType() == ITEM_ARMOR &&
					!(item->GetSubType() == ARMOR_BODY || item->GetSubType() == ARMOR_SHIELD || item->GetSubType() == ARMOR_HEAD) &&
					item->GetRefinedVnum())

//Replace the condition "if" with

#ifdef ITEM_TALISMAN_EQUIPMENT
			if (item->GetType() == ITEM_ARMOR &&
					!(item->GetSubType() == ARMOR_BODY || item->GetSubType() == ARMOR_SHIELD || item->GetSubType() == ARMOR_HEAD || item->GetSubType() == ARMOR_PENDANT) &&
					item->GetRefinedVnum())
#else
			if (item->GetType() == ITEM_ARMOR &&
					!(item->GetSubType() == ARMOR_BODY || item->GetSubType() == ARMOR_SHIELD || item->GetSubType() == ARMOR_HEAD) &&
					item->GetRefinedVnum())

#endif
