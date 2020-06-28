#Find
	def RefreshStamina(self):
		self.wndTaskBar.RefreshStamina()
			
#Add
	if app.ENABLE_EXTEND_INVEN_SYSTEM:
		def ExInvenItemUseMsg(self, enough_count):
			self.wndInventory.OpenExInvenFallShortCountMsgDlg(enough_count)