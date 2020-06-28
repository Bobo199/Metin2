#Find
		self.serverCommander=stringCommander.Analyzer()
#Add
		if app.ENABLE_EXTEND_INVEN_SYSTEM:
			self.serverCommander.SAFE_RegisterCallBack("ExInvenItemUseMsg", self.ExInvenItemUseMsg)	

#Add end of file
	if app.ENABLE_EXTEND_INVEN_SYSTEM:	
		def ExInvenItemUseMsg(self, enough_count):
			if self.interface:
				self.interface.ExInvenItemUseMsg(enough_count)