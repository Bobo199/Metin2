// Search static string arSub2[] in

int get_Item_SubType_Value(unsigned int type_value, string inputString)

// Add under:
	
"ARMOR_PENDANT",

// this is example of my case:

	static string arSub2[] = { "ARMOR_BODY", "ARMOR_HEAD", "ARMOR_SHIELD", "ARMOR_WRIST", "ARMOR_FOOTS",
				"ARMOR_NECK", "ARMOR_EAR", "ARMOR_PENDANT", "ARMOR_NUM_TYPES"};


// Search string arWearrFlag[] = in 

int get_Item_WearFlag_Value(string inputString)

// Add under:

"WEAR_PENDANT",

// this is example of my case:

	string arWearrFlag[] = {"WEAR_BODY", "WEAR_HEAD", "WEAR_FOOTS", "WEAR_WRIST", "WEAR_WEAPON", "WEAR_NECK", "WEAR_EAR", "WEAR_SHIELD", "WEAR_UNIQUE",
					"WEAR_ARROW", "WEAR_HAIR", "WEAR_ABILITY", "WEAR_COSTUME_MOUNT", "WEAR_COSTUME_ACCE", "WEAR_PENDANT", "WEAR_COSTUME_AURA"};


// Search

	};

	int retInt = -1;
	//cout << "ApplyType : " << applyTypeStr << " -> ";
	for (unsigned int j=0;j<sizeof(arApplyType)/sizeof(arApplyType[0]);j++) {
		string tempString = arApplyType[j];
		string tempInputString = trim(inputString);
		if	(tempInputString.compare(tempString)==0)
		{
			//cout << j << " ";
			retInt =  j;
			break;
		}
	}

// in

int get_Item_ApplyType_Value(string inputString)

// Add before

			,"APPLY_ATTBONUS_ELECT", "APPLY_ATTBONUS_FIRE", "APPLY_ATTBONUS_ICE", "APPLY_ATTBONUS_WIND", "APPLY_ATTBONUS_EARTH", "APPLY_ATTBONUS_DARK",
			"APPLY_RESIST_HUMAN", "APPLY_RESIST_SWORD_REDUCTION", "APPLY_RESIST_TWOHAND_REDUCTION", "APPLY_RESIST_DAGGER_REDUCTION", 
			"APPLY_RESIST_BELL_REDUCTION", "APPLY_RESIST_FAN_REDUCTION", "APPLY_RESIST_BOW_REDUCTION", "APPLY_ATTBONUS_ZODIAC", "APPLY_ATTBONUS_DESERT",
			"APPLY_ATTBONUS_INSECT", "APPLY_RESIST_CLAW_REDUCTION"
