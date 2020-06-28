#Add
if app.ENABLE_SORT_INVEN:
	import uiToolTip
	
#Find
			self.equipmentTab.append(self.GetChild("Equipment_Tab_02"))

#Add
			if app.ENABLE_SORT_INVEN:
				self.yenilebutton = self.GetChild2("YenileButton")
				self.yenilebutton.SetEvent(ui.__mem_func__(self.ClickYenileButton))
				self.tooltipI = uiToolTip.ToolTip()
				self.tooltipI.Hide()
				self.tooltipInfo = [self.tooltipI]*4
				self.InformationText = [localeInfo.YENILE_BUTTON_TITLE,
										localeInfo.YENILE_BUTTON,
										localeInfo.YENILE_BUTTON2,
										localeInfo.YENILE_BUTTON3
				]
				for i in xrange(len(self.tooltipInfo)):
					self.tooltipInfo[i].SetFollow(True)
					self.tooltipInfo[i].AlignHorizonalCenter()
					if i == 0:
						self.tooltipInfo[i].AppendTextLine(self.InformationText[i], 0xffffff00)
					else:
						self.tooltipInfo[i].AppendTextLine(self.InformationText[i])
					self.tooltipInfo[i].Hide()

#Find
	def Close(self):
		self.Hide()
		
#Add
	if app.ENABLE_SORT_INVEN:
		def ClickYenileButton(self):
			if app.IsPressed(app.DIK_LALT):
				net.SortInven(2)
			elif app.IsPressed(app.DIK_LCONTROL):
				net.SortInven(3)
			else:
				net.SortInven(1)
				
#Find 
	def OnUpdate(self):
	
#Add in
		if app.ENABLE_SORT_INVEN and self.tooltipInfo:
			for i in xrange(len(self.tooltipInfo)):
				if self.yenilebutton.IsIn():
					self.tooltipInfo[i].Show()
				else:
					self.tooltipInfo[i].Hide()