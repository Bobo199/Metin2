#Find
			self.loadingGage=self.GetChild("FullGage")
			
#Add
			if app.__LOADING_TIP__:
				self.loadingTip=self.GetChild("LoadingTip")
				
#Find
		self.errMsg.Hide()
		
#Add
		if app.__LOADING_TIP__:
			self.loadingTip.SetText(net.GetTipInfo())