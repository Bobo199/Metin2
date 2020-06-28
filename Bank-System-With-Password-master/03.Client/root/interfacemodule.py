#Add
if app.ENABLE_BANK_SYSTEM:
	import uibank
	
#Find
		self.wndDragonSoul = None
	
#Add
		if app.ENABLE_BANK_SYSTEM:
			self.wndBank = None
			
#Find
		wndSafebox = uiSafebox.SafeboxWindow()
		
#Add
		if app.ENABLE_BANK_SYSTEM:
			wndBank = uibank.BankDialog()
			
#Find
		self.wndDragonSoul = wndDragonSoul
		
#Add
		if app.ENABLE_BANK_SYSTEM:
			self.wndBank = wndBank
			
#Find
		if self.wndDragonSoul:
			self.wndDragonSoul.Destroy()
			
#Add
		if self.wndBank and app.ENABLE_BANK_SYSTEM:
			self.wndBank.Destroy()
			
#Find
		if self.wndDragonSoul:
			del self.wndDragonSoul
			
#Add
		if self.wndBank and app.ENABLE_BANK_SYSTEM:
			del self.wndBank
			
#Find
		if self.wndChat:
			self.wndChat.Hide()
			
#Add
		if self.wndBank and app.ENABLE_BANK_SYSTEM:
			self.wndBank.Hide()
			
#Find

	def DragonSoulActivate(self, deck):
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoul.ActivateDragonSoulByExtern(deck)
			
#Add
	
	if app.ENABLE_BANK_SYSTEM:
		def AskBankPassword(self):
			if not self.wndBank.IsShow():

				self.dlgPassword.SetTitle(localeInfo.PASSWORD_TITLE)
				self.dlgPassword.SetSendMessage("bank_system")

				self.dlgPassword.ShowDialog()
		
		def OpenBankk(self, b_open):
			if FALSE == player.IsObserverMode():
				if b_open == TRUE:
					if not self.wndBank.IsShow():
						self.wndBank.Open()
				else:
					if self.wndBank.IsShow():
						self.wndBank.Close()
