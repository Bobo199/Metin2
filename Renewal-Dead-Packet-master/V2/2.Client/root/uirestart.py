#Add
if app.RENEWAL_DEAD_PACKET:
	import player
	import localeInfo
	
#Find
		self.restartHereButton.SetEvent(ui.__mem_func__(self.RestartHere))
	
#Add
		if app.RENEWAL_DEAD_PACKET:
			self.reviveTimeStamp = [0 for i in xrange(player.REVIVE_TYPE_MAX)]
			self.reviveTimeTexts = map(lambda i:self.GetChild("T{:02d}".format(i)), xrange(player.REVIVE_TYPE_MAX))
			
#Find
		self.restartHereButton=0
	
#Add
		if app.RENEWAL_DEAD_PACKET:
			del self.reviveTimeStamp[:]
			del self.reviveTimeTexts[:]
			
#Find
	def OpenDialog(self):
		self.Show()
			
#Change
	if app.RENEWAL_DEAD_PACKET:
		def OpenDialog(self, times):
			for x in xrange(player.REVIVE_TYPE_MAX):
				self.reviveTimeStamp[x] = app.GetTime() + times[x]
				self.reviveTimeTexts[x].Show()
			self.restartHereButton.Disable()
			self.restartTownButton.Disable()
			self.Show()

		def OnUpdate(self):
			for x in xrange(player.REVIVE_TYPE_MAX): 
				endtime = self.reviveTimeStamp[x] - app.GetTime()
				if endtime <= .1:
					self.reviveTimeTexts[x].Hide()
					if x == player.REVIVE_TYPE_HERE:
						self.restartHereButton.Enable()
					if x == player.REVIVE_TYPE_TOWN:
						self.restartTownButton.Enable()

				if x == player.REVIVE_TYPE_AUTO_TOWN:
					self.reviveTimeTexts[x].SetText(localeInfo.REVIVE_AUTO_TOWN_MESSAGE.format(localeInfo.SecondToMS(endtime)))
				else:
					self.reviveTimeTexts[x].SetText("{0:.1f}".format(endtime))
	else:
		def OpenDialog(self):
			self.Show()
