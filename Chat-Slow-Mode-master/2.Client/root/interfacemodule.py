#Add
if app.CHAT_SLOW_MODE:
	import uiChatSlow
	
#Find
	def __MakeGuildWindow(self):
		self.wndGuild = uiGuild.GuildWindow()
		
#Add
	if app.CHAT_SLOW_MODE:
		def ChatSlowMode(self, var):
			self.wndChat.SetSlowMode(var)
		def OpenChatSlowDialog(self):
			self.dlgChatSlow.OpenDialog()
			
#Find
		self.dlgShop.Hide()
		
#Add
		if app.CHAT_SLOW_MODE:
			self.dlgChatSlow = uiChatSlow.ChatSlowMode()
			self.dlgChatSlow.LoadDialog()
			self.dlgChatSlow.Hide()
			
#Find
		if self.dlgRestart:
			self.dlgRestart.Destroy()
			
#Add
		if app.CHAT_SLOW_MODE and self.dlgChatSlow:
			self.dlgChatSlow.Destroy()
		
#Find
		del self.dlgRestart
		
#Add
		if app.CHAT_SLOW_MODE:
			del self.dlgChatSlow