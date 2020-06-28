#Find
		self.showsalesTextButtonList = []
		
#Add
		if app.__BL_HIDE_EFFECT__:
			self.BLEffectGroupList = []
			
#Find
			self.showsalesTextButtonList.append(GetObject("salestext_off_button"))
			
#Add
			if app.__BL_HIDE_EFFECT__:
				for BLEffectNames in ('BuffEffect', 'SkillEffect'):
					self.BLEffectGroupList.append(GetObject('BL_EFFECT_{}'.format(BLEffectNames)))
					
#Find
		self.pvpModeButtonDict[player.PK_MODE_FREE].SAFE_SetEvent(self.__OnClickPvPModeFreeButton)
		
#Add
		if app.__BL_HIDE_EFFECT__:
			for (Index, Button) in enumerate(self.BLEffectGroupList):
				Button.SetToggleDownEvent(lambda arg=Index: self.__OnClickBLEffectButton(arg))
				Button.SetToggleUpEvent(lambda arg=Index: self.__OnClickBLEffectButton(arg))
			self.__RefreshBLEffectButton()
			
#Find
	def __SetPeacePKMode(self):
		self.__SetPKMode(player.PK_MODE_PEACE)
		
#Add
	if app.__BL_HIDE_EFFECT__:
		def __OnClickBLEffectButton(self, Index):
			systemSetting.SetBLEffectOption(Index, not systemSetting.GetBLEffectOption(Index))
			self.__RefreshBLEffectButton()
		
		def __RefreshBLEffectButton(self):
			for (Index, Button) in enumerate(self.BLEffectGroupList):
				if systemSetting.GetBLEffectOption(Index):
					Button.Down()
				else:
					Button.SetUp()