#Find
	def StartShop(self, vid):
		self.interface.OpenShopDialog(vid)
			
#Change
	def StartShop(self, vid, count = 0):
		if app.ENABLE_SHOP_SEEN:
			self.interface.OpenShopDialog(vid, count)
		else:
			self.interface.OpenShopDialog(vid)