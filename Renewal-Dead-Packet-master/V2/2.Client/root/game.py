#Find
	def OnGameOver(self):
		self.CloseTargetBoard()
		self.OpenRestartDialog()
		
#Change
	if app.RENEWAL_DEAD_PACKET:
		def OnGameOver(self, d_time):
			self.CloseTargetBoard()
			self.OpenRestartDialog(d_time)
	else:
		def OnGameOver(self):
			self.CloseTargetBoard()
			self.OpenRestartDialog()
			
#Find
	def OpenRestartDialog(self):
		self.interface.OpenRestartDialog()
		
#Change
	if app.RENEWAL_DEAD_PACKET:
		def OpenRestartDialog(self, d_time):
			self.interface.OpenRestartDialog(d_time)
	else:
		def OpenRestartDialog(self):
			self.interface.OpenRestartDialog()