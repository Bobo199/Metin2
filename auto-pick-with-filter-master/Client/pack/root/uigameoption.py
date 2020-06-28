# Search

	def __init__(self):

# Add after

		self.RefreshPickupFilter
    
# Search

	def __Initialize(self):
  
# Add after

		self.PickUpFilterList = []
    
# Search

	def __Load_BindObject(self):
  
# Add after

			self.PickUpFilterList.append(GetObject("Pick_Up_FilterWeapon"))
			self.PickUpFilterList.append(GetObject("Pick_Up_FilterArmor"))
			self.PickUpFilterList.append(GetObject("Pick_Up_FilterEar"))
			self.PickUpFilterList.append(GetObject("Pick_Up_FilterNeck"))
			self.PickUpFilterList.append(GetObject("Pick_Up_FilterFoots"))
			self.PickUpFilterList.append(GetObject("Pick_Up_FilterShield"))
			self.PickUpFilterList.append(GetObject("Pick_Up_FilterBook"))
			self.PickUpFilterList.append(GetObject("Pick_Up_FilterStone"))
			self.PickUpFilterList.append(GetObject("Pick_Up_FilterEtc"))
      
# Search

		self.showsalesTextButtonList[0].SAFE_SetEvent(self.__OnClickSalesTextOnButton)
		self.showsalesTextButtonList[1].SAFE_SetEvent(self.__OnClickSalesTextOffButton)
    
# Add after

		self.PickUpFilterList[0].SetToggleUpEvent(self.__OnClickPickupFilterButtonWeapon) # Weapon
		self.PickUpFilterList[0].SetToggleDownEvent(self.__OnClickPickupFilterButtonWeapon) # Weapon
		self.PickUpFilterList[1].SetToggleUpEvent(self.__OnClickPickupFilterButtonArmor) # Armor
		self.PickUpFilterList[1].SetToggleDownEvent(self.__OnClickPickupFilterButtonArmor) # Armor
		self.PickUpFilterList[2].SetToggleUpEvent(self.__OnClickPickupFilterButtonEar) # Ear
		self.PickUpFilterList[2].SetToggleDownEvent(self.__OnClickPickupFilterButtonEar) # Ear
		self.PickUpFilterList[3].SetToggleUpEvent(self.__OnClickPickupFilterButtonNeck) # Neck
		self.PickUpFilterList[3].SetToggleDownEvent(self.__OnClickPickupFilterButtonNeck) # Neck
		self.PickUpFilterList[4].SetToggleUpEvent(self.__OnClickPickupFilterButtonFoots) # Foots
		self.PickUpFilterList[4].SetToggleDownEvent(self.__OnClickPickupFilterButtonFoots) # Foots
		self.PickUpFilterList[5].SetToggleUpEvent(self.__OnClickPickupFilterButtonShield) # Shield
		self.PickUpFilterList[5].SetToggleDownEvent(self.__OnClickPickupFilterButtonShield) # Shield
		self.PickUpFilterList[6].SetToggleUpEvent(self.__OnClickPickupFilterButtonBook) # Books
		self.PickUpFilterList[6].SetToggleDownEvent(self.__OnClickPickupFilterButtonBook) # Books
		self.PickUpFilterList[7].SetToggleUpEvent(self.__OnClickPickupFilterButtonStone) # Stone
		self.PickUpFilterList[7].SetToggleDownEvent(self.__OnClickPickupFilterButtonStone) # Stone
		self.PickUpFilterList[8].SetToggleUpEvent(self.__OnClickPickupFilterButtonEtc) # Etc
		self.PickUpFilterList[8].SetToggleDownEvent(self.__OnClickPickupFilterButtonEtc) # Etc
    
# Search

	def __OnClickSalesTextOffButton(self):
		systemSetting.SetShowSalesTextFlag(FALSE)
		self.RefreshShowSalesText()		
    
# Add after

	def __OnClickPickupFilterButtonWeapon(self):
		systemSetting.SetPickUpFilterWeapon(not systemSetting.IsPickUpFilterWeapon())
		self.RefreshPickupFilter()
	def __OnClickPickupFilterButtonArmor(self):
		systemSetting.SetPickUpFilterArmor(not systemSetting.IsPickUpFilterArmor())
		self.RefreshPickupFilter()
	def __OnClickPickupFilterButtonEar(self):
		systemSetting.SetPickUpFilterEar(not systemSetting.IsPickUpFilterEar())
		self.RefreshPickupFilter()
	def __OnClickPickupFilterButtonNeck(self):
		systemSetting.SetPickUpFilterNeck(not systemSetting.IsPickUpFilterNeck())
		self.RefreshPickupFilter()
	def __OnClickPickupFilterButtonFoots(self):
		systemSetting.SetPickUpFilterFoots(not systemSetting.IsPickUpFilterFoots())
		self.RefreshPickupFilter()
	def __OnClickPickupFilterButtonShield(self):
		systemSetting.SetPickUpFilterShield(not systemSetting.IsPickUpFilterShield())
		self.RefreshPickupFilter()
	def __OnClickPickupFilterButtonBook(self):
		systemSetting.SetPickUpFilterBook(not systemSetting.IsPickUpFilterBook())
		self.RefreshPickupFilter()
	def __OnClickPickupFilterButtonStone(self):
		systemSetting.SetPickUpFilterStone(not systemSetting.IsPickUpFilterStone())
		self.RefreshPickupFilter()
	def __OnClickPickupFilterButtonEtc(self):
		systemSetting.SetPickUpFilterEtc(not systemSetting.IsPickUpFilterEtc())
		self.RefreshPickupFilter()
	##End PickUpFilter	
  
# Search

	def RefreshShowSalesText(self):
		if systemSetting.IsShowSalesText():
			self.showsalesTextButtonList[0].Down()
			self.showsalesTextButtonList[1].SetUp()
		else:
			self.showsalesTextButtonList[0].SetUp()
			self.showsalesTextButtonList[1].Down()
      
# Add after

	def RefreshPickupFilter(self):
		#Weapon
		if systemSetting.IsPickUpFilterWeapon():
			self.PickUpFilterList[0].Down()
		else:
			self.PickUpFilterList[0].SetUp()
		#Armor
		if systemSetting.IsPickUpFilterArmor():
			self.PickUpFilterList[1].Down()
		else:
			self.PickUpFilterList[1].SetUp()
		#Ear
		if systemSetting.IsPickUpFilterEar():
			self.PickUpFilterList[2].Down()
		else:
			self.PickUpFilterList[2].SetUp()
		#Neck
		if systemSetting.IsPickUpFilterNeck():
			self.PickUpFilterList[3].Down()
		else:
			self.PickUpFilterList[3].SetUp()
		#Foots
		if systemSetting.IsPickUpFilterFoots():
			self.PickUpFilterList[4].Down()
		else:
			self.PickUpFilterList[4].SetUp()		
		#Shield
		if systemSetting.IsPickUpFilterShield():
			self.PickUpFilterList[5].Down()
		else:
			self.PickUpFilterList[5].SetUp()		
		#Book
		if systemSetting.IsPickUpFilterBook():
			self.PickUpFilterList[6].Down()
		else:
			self.PickUpFilterList[6].SetUp()		
		#Stone
		if systemSetting.IsPickUpFilterStone():
			self.PickUpFilterList[7].Down()
		else:
			self.PickUpFilterList[7].SetUp()		
		#Etc
		if systemSetting.IsPickUpFilterEtc():
			self.PickUpFilterList[8].Down()
		else:
			self.PickUpFilterList[8].SetUp()
