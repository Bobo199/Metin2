#Find
	def OnChangeCurrentSkill(self, skillSlotNumber):
		self.wndTaskBar.OnChangeCurrentSkill(skillSlotNumber)
		
#Add
	if app.SKILL_COOLTIME_UPDATE:
		def	SkillClearCoolTime(self, slotIndex):
			self.wndCharacter.SkillClearCoolTime(slotIndex)
			self.wndTaskBar.SkillClearCoolTime(slotIndex)