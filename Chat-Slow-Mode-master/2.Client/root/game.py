#Find
		for serverCommandItem in serverCommandList.items():
			self.serverCommander.SAFE_RegisterCallBack(
				serverCommandItem[0], serverCommandItem[1]
			)

#Add
		if app.CHAT_SLOW_MODE:
			self.serverCommander.SAFE_RegisterCallBack("chatslowmode", self.ChatSlowMode)
			
#Add
	if app.CHAT_SLOW_MODE:
		def ChatSlowMode(self, var):
			if self.interface:
				self.interface.ChatSlowMode(var)