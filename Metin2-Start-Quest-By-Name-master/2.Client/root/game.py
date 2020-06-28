	if app.QUEST_BY_NAME:	
		def QuestClickByName(self, qname):
			import event
			event.QuestClickByName(qname)
			
		# def TestQuestIndex(self):
			# self.QuestClickByName("anti_exp")