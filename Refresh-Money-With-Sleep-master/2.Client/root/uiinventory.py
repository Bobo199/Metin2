#Find
	def RefreshStatus(self):
		money = player.GetElk()
		self.wndMoney.SetText(localeInfo.NumberToMoneyString(money))
		
#Add
	def OnUpdate(self):
		self.RefreshStatus()