#1.1 Search for:
		self.ctrlShadowQuality = 0
#1.1 Add after:
		if app.ENABLE_GRAPHIC_MASK:
			self.graphicMaskButtonList = []
			
#1.2 Search for:
			self.tilingApplyButton=GetObject("tiling_apply")
#1.2 Add after:
			if app.ENABLE_GRAPHIC_MASK:
				for graphicMaskName in ('terrain', 'object', 'cloud', 'water', 'tree'):
					self.graphicMaskButtonList.append(GetObject('background_{:s}'.format(graphicMaskName)))
			
#1.3 Search for:
		self.ctrlShadowQuality = 0
#1.3 Add after:
		if app.ENABLE_GRAPHIC_MASK:
			self.graphicMaskButtonList = []
			
#1.4 Search for:
		self.__ClickRadioButton(self.cameraModeButtonList, constInfo.GET_CAMERA_MAX_DISTANCE_INDEX())
#1.4 Add after:
		if app.ENABLE_GRAPHIC_MASK:
			for (tabKey, tabButton) in enumerate(self.graphicMaskButtonList):
				tabButton.SetToggleUpEvent(lambda arg=tabKey: self.__OnClickGraphicMaskButton(arg, False))
				tabButton.SetToggleDownEvent(lambda arg=tabKey: self.__OnClickGraphicMaskButton(arg, True))

			self.__RefreshGraphicMask()
			
#1.5 Search for:
	def __OnClickFogModeLevel2Button(self):
		self.__SetFogLevel(2)
#1.5 Add after:
	if app.ENABLE_GRAPHIC_MASK:
		def __RefreshGraphicMask(self):
			for (tabKey, tabButton) in enumerate(self.graphicMaskButtonList):
				if systemSetting.GetGraphicMaskPart(tabKey):
					tabButton.Down()
				else:
					tabButton.SetUp()

			background.LoadGraphicMaskSettings()
	
		def __OnClickGraphicMaskButton(self, bPart, bFlag):
			systemSetting.SetGraphicMaskPart(bPart, bFlag)
			self.__RefreshGraphicMask()