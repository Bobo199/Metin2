#Add
if app.ENABLE_BANK_SYSTEM:
	import bank
	
#Find
	def OnAccept(self):
		net.SendChatPacket(self.sendMessage + self.passwordValue.GetText())
		self.CloseDialog()
		return TRUE
		
#Change
	def OnAccept(self):
		if app.ENABLE_BANK_SYSTEM:
			if self.sendMessage == "bank_system":
				bank.SendStartPacket(self.passwordValue.GetText())
			else:
				net.SendChatPacket(self.sendMessage + self.passwordValue.GetText())
		else:
			net.SendChatPacket(self.sendMessage + self.passwordValue.GetText())
		self.CloseDialog()
		return TRUE