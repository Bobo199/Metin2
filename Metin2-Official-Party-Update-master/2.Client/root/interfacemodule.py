#Find
	def AddPartyMember(self, pid, name):
		self.wndParty.AddPartyMember(pid, name)
		self.__ArrangeQuestButton()
		
#Change
	if app.BL_PARTY_UPDATE:
		def AddPartyMember(self, pid, name, mapIdx, channel):
			self.wndParty.AddPartyMember(pid, name, mapIdx, channel)
			self.__ArrangeQuestButton()
	else:
		def AddPartyMember(self, pid, name):
			self.wndParty.AddPartyMember(pid, name)
			self.__ArrangeQuestButton()
			
#Find
	def LinkPartyMember(self, pid, vid):
		self.wndParty.LinkPartyMember(pid, vid)
		
#Change
	if app.BL_PARTY_UPDATE:
		def LinkPartyMember(self, pid, vid, mapIdx, channel):
			self.wndParty.LinkPartyMember(pid, vid, mapIdx, channel)
	else:
		def LinkPartyMember(self, pid, vid):
			self.wndParty.LinkPartyMember(pid, vid)