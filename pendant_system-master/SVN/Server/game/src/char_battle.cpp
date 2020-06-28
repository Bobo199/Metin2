// In class CFuncShoot search 
	
	iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_BOW)) / 100;

// Replace with

#ifdef ELEMENT_NEW_BONUSES
						iDam = iDam * (100 - (pkVictim->GetPoint(POINT_RESIST_BOW) - pkVictim->GetPoint(POINT_RESIST_BOW_REDUCTION))) / 100;
#else
						iDam = iDam * (100 - pkVictim->GetPoint(POINT_RESIST_BOW)) / 100;
#endif


