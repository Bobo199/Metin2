#Find
			self.titleBar = GetObject("TitleBar")
	
#Add
			self.Seen = GetObject("Seen")	
			self.SeenText = GetObject("SeenText")
			
#Find
	def Open(self, vid):

#Change
	def Open(self, vid, count = 0):
	
#Find
		shop.Open(isPrivateShop, isMainPlayerPrivateShop)

#Add
		if app.ENABLE_SHOP_SEEN:
			self.SeenText.SetText(str(count))
			if (isPrivateShop):
				self.Seen.Show()
			else:
				self.Seen.Hide()