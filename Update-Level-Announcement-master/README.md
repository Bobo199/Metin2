# Update-Level-Announcement
Mini-Release my me, For Metin2-2016
Go char.cpp and find:

void CHARACTER::PointChange(BYTE type, int amount, bool bAmount, bool bBroadcast)


Find again:

case POINT_LEVEL:
			if ((GetLevel() + amount) > gPlayerMaxLevel)
				return;

			SetLevel(GetLevel() + amount);
			val = GetLevel();

			sys_log(0, "LEVELUP: %s %d NEXT EXP %d", GetName(), GetLevel(), GetNextExp());

			PointChange(POINT_NEXT_EXP,	GetNextExp(), false);
      
 Add my codes.
