#Find
		self.blockButtonList = []
		
#Add
		if app.ENABLE_HIDE_OBJECTS:
			self.VisibleButtonList = []
			self.mylist = [background.PART_TREE, background.PART_CLOUD, background.PART_WATER, background.PART_OBJECT, background.PART_TERRAIN, background.PART_SHOP]

#Find
			self.pvpModeButtonDict[player.PK_MODE_FREE] = GetObject("pvp_free")
		
#Add
			if app.ENABLE_HIDE_OBJECTS:
				for bl in xrange(len(self.mylist)):
					self.VisibleButtonList.append(GetObject("vsble" + str(bl)))
					
#Find
		self.alwaysShowNameButtonList[1].SAFE_SetEvent(self.__OnClickAlwaysShowNameOffButton)
			
#Add
		if app.ENABLE_HIDE_OBJECTS:	
			for bl in xrange(len(self.mylist)):
				self.VisibleButtonList[bl].SetToggleUpEvent(lambda arg=bl: self.SetVisibleFunc(arg))
				self.VisibleButtonList[bl].SetToggleDownEvent(lambda arg=bl: self.SetVisibleFunc(arg))
				
#Add this Func
	if app.ENABLE_HIDE_OBJECTS:		
		def SetVisibleFunc(self, index):
			background.SetVisiblePart(self.mylist[index], not background.IsVisiblePart(self.mylist[index]))
			if self.mylist[index] == background.PART_SHOP:
				if not systemSetting.IsShowSalesText():
					self.__OnClickSalesTextOnButton()
				else:
					self.__OnClickSalesTextOffButton()
			for bl in xrange(len(self.mylist)):
				if background.IsVisiblePart(self.mylist[bl]):
					self.VisibleButtonList[bl].SetUp()
				else:
					self.VisibleButtonList[bl].Down()