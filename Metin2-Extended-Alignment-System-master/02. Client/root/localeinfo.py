#1.1) Search for:
import constInfo
#1.2) Add after:
if app.ENABLE_EXTENDED_ALIGNMENT_SYSTEM:
	import chr, net
	GENDER_FEMALE	= 0
	GENDER_MALE 	= 1

#2.1) Search for:
TITLE_NAME_LIST = ( PVP_LEVEL0, PVP_LEVEL1, PVP_LEVEL2, PVP_LEVEL3, PVP_LEVEL4, PVP_LEVEL5, PVP_LEVEL6, PVP_LEVEL7, PVP_LEVEL8, )
#2.2) Replace with:
if app.ENABLE_EXTENDED_ALIGNMENT_SYSTEM:
	TITLE_NAME_DICT = {
		GENDER_FEMALE : ( PVP_LEVEL0_F, PVP_LEVEL1_F, PVP_LEVEL2_F, PVP_LEVEL3_F, PVP_LEVEL4_F, PVP_LEVEL5_F, PVP_LEVEL6_F, PVP_LEVEL7_F, PVP_LEVEL8_F, ),
		GENDER_MALE : ( PVP_LEVEL0_M, PVP_LEVEL1_M, PVP_LEVEL2_M, PVP_LEVEL3_M, PVP_LEVEL4_M, PVP_LEVEL5_M, PVP_LEVEL6_M, PVP_LEVEL7_M, PVP_LEVEL8_M, ),
	}
else:
	TITLE_NAME_LIST = ( PVP_LEVEL0, PVP_LEVEL1, PVP_LEVEL2, PVP_LEVEL3, PVP_LEVEL4, PVP_LEVEL5, PVP_LEVEL6, PVP_LEVEL7, PVP_LEVEL8, )

#3.1) Search for:
def GetAlignmentTitleName(alignment):
	if alignment >= 12000:
		return TITLE_NAME_LIST[0]
	elif alignment >= 8000:
		return TITLE_NAME_LIST[1]
	elif alignment >= 4000:
		return TITLE_NAME_LIST[2]
	elif alignment >= 1000:
		return TITLE_NAME_LIST[3]
	elif alignment >= 0:
		return TITLE_NAME_LIST[4]
	elif alignment > -4000:
		return TITLE_NAME_LIST[5]
	elif alignment > -8000:
		return TITLE_NAME_LIST[6]
	elif alignment > -12000:
		return TITLE_NAME_LIST[7]

	return TITLE_NAME_LIST[8]
#3.2) Replace with:
if app.ENABLE_EXTENDED_ALIGNMENT_SYSTEM:
	def GetAlignmentTitleName(currentAlignment):
		titleNameTuple = TITLE_NAME_DICT.get(chr.RaceToSex(net.GetMainActorRace()), ('UNKNOWN_GENDER', ))
		
		for alignmentIndex, alignmentValue in enumerate((12000, 8000, 4000, 1000, 0, -4000, -8000, -12000)):
			if currentAlignment >= alignmentValue:
				return titleNameTuple[alignmentIndex]

		return titleNameTuple[-1]
else:
	def GetAlignmentTitleName(alignment):
		if alignment >= 12000:
			return TITLE_NAME_LIST[0]
		elif alignment >= 8000:
			return TITLE_NAME_LIST[1]
		elif alignment >= 4000:
			return TITLE_NAME_LIST[2]
		elif alignment >= 1000:
			return TITLE_NAME_LIST[3]
		elif alignment >= 0:
			return TITLE_NAME_LIST[4]
		elif alignment > -4000:
			return TITLE_NAME_LIST[5]
		elif alignment > -8000:
			return TITLE_NAME_LIST[6]
		elif alignment > -12000:
			return TITLE_NAME_LIST[7]

		return TITLE_NAME_LIST[8]