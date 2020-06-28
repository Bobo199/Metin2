#Find
	def OpenShopDialog(self, vid):
		self.wndInventory.Show()
		self.wndInventory.SetTop()
		self.dlgShop.Open(vid)
		self.dlgShop.SetTop()
		
#Change
	def OpenShopDialog(self, vid, count = 0):
		self.wndInventory.Show()
		self.wndInventory.SetTop()
		if app.ENABLE_SHOP_SEEN:
			self.dlgShop.Open(vid, count)
		else:
			self.dlgShop.Open(vid)
		self.dlgShop.SetTop()