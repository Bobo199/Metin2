#Find
	def BINARY_Cube_Open(self, npcVNUM):
		self.currentCubeNPC = npcVNUM

#Change
	if app.CUBE_RELOAD_FIX:
		def BINARY_Reload_Cube(self):
			self.cubeInformation.clear()
			self.interface.wndCube.ClearOldSlots()