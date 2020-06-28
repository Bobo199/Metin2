#Find
	def AddPartyMember(self, pid, name):
		self.interface.AddPartyMember(pid, name)
#Change
	if app.BL_PARTY_UPDATE:
		def AddPartyMember(self, pid, name, mapIdx, channel):
			self.interface.AddPartyMember(pid, name, mapIdx, channel)
	else:
		def AddPartyMember(self, pid, name):
			self.interface.AddPartyMember(pid, name)
			
#Find
	def LinkPartyMember(self, pid, vid):
		self.interface.LinkPartyMember(pid, vid)
		
#Change
	if app.BL_PARTY_UPDATE:
		def LinkPartyMember(self, pid, vid, mapIdx, channel):
			self.interface.LinkPartyMember(pid, vid, mapIdx, channel)
	else:
		def LinkPartyMember(self, pid, vid):
			self.interface.LinkPartyMember(pid, vid)