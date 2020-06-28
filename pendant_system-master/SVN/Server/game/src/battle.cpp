// Search

		else if (pkVictim->IsRaceFlag(RACE_FLAG_DESERT))
			iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_DESERT)) / 100;
		else if (pkVictim->IsRaceFlag(RACE_FLAG_TREE))
			iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_TREE)) / 100;

// Add after

#ifdef ELEMENT_NEW_BONUSES
		else if (pkVictim->IsRaceFlag(RACE_FLAG_ATT_ELEC))
			iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_ELEC)) / 100;
		else if (pkVictim->IsRaceFlag(RACE_FLAG_ATT_WIND))
			iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_WIND)) / 100;
		else if (pkVictim->IsRaceFlag(RACE_FLAG_ATT_EARTH))
			iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_EARTH)) / 100;
		else if (pkVictim->IsRaceFlag(RACE_FLAG_ATT_DARK))
			iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_DARK)) / 100;
		else if (pkVictim->IsRaceFlag(RACE_FLAG_ZODIAC))
			iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_ZODIAC)) / 100;
		else if (pkVictim->IsRaceFlag(RACE_FLAG_DESERT))
			iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_DESERT)) / 100;
		else if (pkVictim->IsRaceFlag(RACE_FLAG_INSECT))
			iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_INSECT)) / 100;
#endif

// Search

	else if (pkVictim->IsPC())
	{
		iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_HUMAN)) / 100;

// Replace with

	else if (pkVictim->IsPC())
	{
		iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_HUMAN)) / 100;
#ifdef ELEMENT_NEW_BONUSES
		iAtk += (iAtk * (pkAttacker->GetPoint(POINT_ATTBONUS_HUMAN) - pkAttacker->GetPoint(POINT_RESIST_HUMAN))) / 100;
#else
		iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_HUMAN)) / 100;
#endif

// Search in int battle_hit(LPCHARACTER pkAttacker, LPCHARACTER pkVictim, int & iRetDam)

		switch (pkWeapon->GetSubType())
		{
			case WEAPON_SWORD:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_SWORD)) / 100;
				break;

			case WEAPON_TWO_HANDED:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_TWOHAND)) / 100;
				break;

			case WEAPON_DAGGER:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_DAGGER)) / 100;
				break;

			case WEAPON_BELL:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_BELL)) / 100;
				break;

			case WEAPON_FAN:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_FAN)) / 100;
				break;

			case WEAPON_BOW:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_BOW)) / 100;
				break;
#ifdef ENABLE_WOLFMAN_CHARACTER
			case WEAPON_CLAW:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_CLAW)) / 100;
#if defined(ENABLE_WOLFMAN_CHARACTER) && defined(USE_ITEM_CLAW_AS_DAGGER)
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_DAGGER)) / 100;
#endif
				break;
#endif

#endif
		}

//Replace all case for:

		switch (pkWeapon->GetSubType())
		{
#ifdef ELEMENT_NEW_BONUSES
			case WEAPON_SWORD:
				iDam = iDam * (100 - (pkVictim->GetPoint(POINT_RESIST_SWORD) - pkVictim->GetPoint(POINT_RESIST_SWORD_REDUCTION))) / 100;
				break;

			case WEAPON_TWO_HANDED:
				iDam = iDam * (100 - (pkVictim->GetPoint(POINT_RESIST_TWOHAND) - pkVictim->GetPoint(POINT_RESIST_TWOHAND_REDUCTION))) / 100;
				break;

			case WEAPON_DAGGER:
				iDam = iDam * (100 - (pkVictim->GetPoint(POINT_RESIST_DAGGER) - pkVictim->GetPoint(POINT_RESIST_DAGGER_REDUCTION))) / 100;
				break;

			case WEAPON_BELL:
				iDam = iDam * (100 - (pkVictim->GetPoint(POINT_RESIST_BELL) - pkVictim->GetPoint(POINT_RESIST_BELL_REDUCTION))) / 100;
				break;

			case WEAPON_FAN:
				iDam = iDam * (100 - (pkVictim->GetPoint(POINT_RESIST_FAN) - pkVictim->GetPoint(POINT_RESIST_FAN_REDUCTION))) / 100;
				break;

			case WEAPON_BOW:
				iDam = iDam * (100 - (pkVictim->GetPoint(POINT_RESIST_BOW) - pkVictim->GetPoint(POINT_RESIST_BOW_REDUCTION))) / 100;
				break;
#ifdef ENABLE_WOLFMAN_CHARACTER
			case WEAPON_CLAW:
				iDam = iDam * (100 - (pkVictim->GetPoint(POINT_RESIST_CLAW) - pkVictim->GetPoint(POINT_RESIST_CLAW_REDUCTION))) / 100;
#if defined(ENABLE_WOLFMAN_CHARACTER) && defined(USE_ITEM_CLAW_AS_DAGGER)
				iDam = iDam * (100 - (pkVictim->GetPoint(POINT_RESIST_DAGGER) - - pkVictim->GetPoint(POINT_RESIST_DAGGER_REDUCTION))) / 100;
#endif
				break;
#endif

#else
			case WEAPON_SWORD:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_SWORD)) / 100;
				break;

			case WEAPON_TWO_HANDED:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_TWOHAND)) / 100;
				break;

			case WEAPON_DAGGER:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_DAGGER)) / 100;
				break;

			case WEAPON_BELL:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_BELL)) / 100;
				break;

			case WEAPON_FAN:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_FAN)) / 100;
				break;

			case WEAPON_BOW:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_BOW)) / 100;
				break;
#ifdef ENABLE_WOLFMAN_CHARACTER
			case WEAPON_CLAW:
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_CLAW)) / 100;
#if defined(ENABLE_WOLFMAN_CHARACTER) && defined(USE_ITEM_CLAW_AS_DAGGER)
				iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_DAGGER)) / 100;
#endif
				break;
#endif

#endif
		}

