#Find
		self.restartHereButton.SetEvent(ui.__mem_func__(self.RestartHere))
	
#Add
		if app.RENEWAL_DEAD_PACKET:
			self.val = [None]*2
			self.TextList = []
			for bl in range(len(self.val)):
				self.TextList.append(self.GetChild("T" + str(bl)))
			
#Find
		self.restartHereButton=0
	
#Add
		if app.RENEWAL_DEAD_PACKET:
			del self.val
			del self.TextList
			
#Find
	def OpenDialog(self):
		self.Show()
			
#Change
	if app.RENEWAL_DEAD_PACKET:
		def OpenDialog(self, d_time):
			for x in xrange(len(self.val)):
				self.val[x] = app.GetTime() + d_time[x]
				self.TextList[x].Show()
			self.Show()
		def OnUpdate(self):
			for x in xrange(len(self.val)): 
				endtime = self.val[x] - app.GetTime()
				if endtime <= 1:
					self.TextList[x].Hide()
				self.TextList[x].SetText("%d" % endtime)
	else:
		def OpenDialog(self):
			self.Show()
