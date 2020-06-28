#Find
		onPressKeyDict[app.DIK_F4]	= lambda : self.__PressQuickSlot(7)

#Add
		if app.ENABLE_BANK_SYSTEM:
			onPressKeyDict[app.DIK_F7]  = lambda : self.OpenBank()

#Find
	def BINARY_Cube_UpdateInfo(self, gold, itemVnum, count):
		self.interface.UpdateCubeInfo(gold, itemVnum, count)
	
#Add
	if app.ENABLE_BANK_SYSTEM:
		def OpenBank(self):
			if self.interface:
				self.interface.AskBankPassword()
			
		def InitBank(self, b_open):
			if self.interface:
				self.interface.OpenBankk(b_open)