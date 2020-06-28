#Find in class AffectShower(ui.Window): / def __init__(self):
		self.affectImageDict={}
		
#Add
		self.AffectList = []
		
#Then Add in def ClearAllAffects(self): and def ClearAffects(self):
		self.AffectList.clear()
		
#Find
		if not self.AFFECT_DATA_DICT.has_key(affect):
			return
		
#Add
		if not self.CheckAffect(affect):
			self.AffectList.append(affect)
			
#Find
		del self.affectImageDict[affect]
		
#Add
		if self.CheckAffect(affect):
			self.AffectList.remove(affect)
			
#Add this function to last of py file:
	def CheckAffect(self, affect):
		return affect in self.AffectList