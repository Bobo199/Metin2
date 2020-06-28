// Search

	ARMOR_NUM_TYPES
};

// add before

#ifdef ITEM_TALISMAN_EQUIPMENT
	ARMOR_PENDANT,
#endif


// Search

enum EItemWearableFlag
{

// Add under

#ifdef ITEM_TALISMAN_EQUIPMENT
	WEARABLE_PENDANT = (1 << 14),
#endif

// Example of my case:

enum EItemWearableFlag
{
	WEARABLE_BODY	= (1 << 0),
	WEARABLE_HEAD	= (1 << 1),
	WEARABLE_FOOTS	= (1 << 2),
	WEARABLE_WRIST	= (1 << 3),
	WEARABLE_WEAPON	= (1 << 4),
	WEARABLE_NECK	= (1 << 5),
	WEARABLE_EAR	= (1 << 6),
	WEARABLE_UNIQUE	= (1 << 7),
	WEARABLE_SHIELD	= (1 << 8),
	WEARABLE_ARROW	= (1 << 9),
	WEARABLE_HAIR	= (1 << 10),
	WEARABLE_ABILITY		= (1 << 11),
	WEARABLE_COSTUME_BODY	= (1 << 12),
	WEARABLE_COSTUME_ACCE = (1 << 13),
#ifdef ITEM_TALISMAN_EQUIPMENT
	WEARABLE_PENDANT = (1 << 14),
#endif
#ifdef ENABLE_AURA_COSTUME_SYSTEM
	WEARABLE_COSTUME_AURA = (1 << 15),
#endif
};