#Find
	def Clear(self):
		self.Refresh()
	
#Add
	if app.CUBE_RELOAD_FIX:
		def ClearOldSlots(self):
			[x.ClearSlot(0) for x in self.resultSlots]
			[[x.ClearSlot(0) for x in i] for i in self.materialSlots]