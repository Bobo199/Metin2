#Find
		localeInfo.TARGET_BUTTON_EMOTION_ALLOW,
		
#Add
		localeInfo.TARGET_BUTTON_BLOCK,
		localeInfo.TARGET_BUTTON_UNBLOCK,
		
#Find
		self.buttonDict[localeInfo.TARGET_BUTTON_WHISPER].SetEvent(ui.__mem_func__(self.OnWhisper))
		
#Add
		if app.ENABLE_MESSENGER_BLOCK:
			self.buttonDict[localeInfo.TARGET_BUTTON_BLOCK].SetEvent(ui.__mem_func__(self.OnAppendToBlockMessenger))
			self.buttonDict[localeInfo.TARGET_BUTTON_UNBLOCK].SetEvent(ui.__mem_func__(self.OnRemoveToBlockMessenger))
			
#Find
	def OnAppendToMessenger(self):
		net.SendMessengerAddByVIDPacket(self.vid)
		
#Add
	if app.ENABLE_MESSENGER_BLOCK:
		def OnAppendToBlockMessenger(self):
			net.SendMessengerAddBlockByVIDPacket(self.vid)
		def OnRemoveToBlockMessenger(self):
			messenger.RemoveBlock(constInfo.ME_KEY)
			net.SendMessengerRemoveBlockPacket(constInfo.ME_KEY, chr.GetNameByVID(self.vid))
			
#Find
		if not messenger.IsFriendByName(self.nameString):
			self.__ShowButton(localeInfo.TARGET_BUTTON_FRIEND)
			
#Add
		if app.ENABLE_MESSENGER_BLOCK and not str(self.nameString)[0] == "[":
			if not messenger.IsBlockByName(self.nameString):
				self.__ShowButton(localeInfo.TARGET_BUTTON_BLOCK)
				self.__HideButton(localeInfo.TARGET_BUTTON_UNBLOCK)
			else:
				self.__ShowButton(localeInfo.TARGET_BUTTON_UNBLOCK)
				self.__HideButton(localeInfo.TARGET_BUTTON_BLOCK)