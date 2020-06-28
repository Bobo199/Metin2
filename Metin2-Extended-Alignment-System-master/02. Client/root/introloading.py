#1.1) Search for:
	def __RegisterTitleName(self):
		for i in xrange(len(localeInfo.TITLE_NAME_LIST)):
				chrmgr.RegisterTitleName(i, localeInfo.TITLE_NAME_LIST[i])
#1.2) Replace with :
	if app.ENABLE_EXTENDED_ALIGNMENT_SYSTEM:
		def __RegisterTitleName(self):

			def GetTitleData(gender):
				return localeInfo.TITLE_NAME_DICT.get(gender, ('UNKNOWN_GENDER', ))

			def GetTitleNamesTuple(*title_data):
				titleNamesTuple = map(iter, title_data)
				while titleNamesTuple:
					yield tuple(map(next, titleNamesTuple))

			for titleNameIndex, (titleNameFemale, titleNameMale) in enumerate(GetTitleNamesTuple(GetTitleData(localeInfo.GENDER_FEMALE), GetTitleData(localeInfo.GENDER_MALE))):
				chrmgr.RegisterTitleName(titleNameIndex, titleNameFemale, titleNameMale)
	else:
		def __RegisterTitleName(self):
			for i in xrange(len(localeInfo.TITLE_NAME_LIST)):
					chrmgr.RegisterTitleName(i, localeInfo.TITLE_NAME_LIST[i])
