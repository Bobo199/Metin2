#1.1) Search for:
		self.toolTipAlignment.AutoAppendTextLine(localeInfo.TITLE_NAME_LIST[grade], gradeColor)
#1.2) Replace with:
		if app.ENABLE_EXTENDED_ALIGNMENT_SYSTEM:
			self.toolTipAlignment.AutoAppendTextLine(localeInfo.GetAlignmentTitleName(point), gradeColor)
		else:
			self.toolTipAlignment.AutoAppendTextLine(localeInfo.TITLE_NAME_LIST[grade], gradeColor)