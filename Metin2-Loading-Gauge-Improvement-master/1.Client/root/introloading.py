#Find
			self.loadingGage.SetPercentage(2+98*p/100, 100)
			
#Change
			self.loadingGage.SetPercentage(p, 160)
		
#Find
		self.__SetProgress(0)
		
#Add Above		
		tmpLoadStepList = tuple(zip(*self.loadStepList))[0]
		for progress in set(range(tmpLoadStepList[0], tmpLoadStepList[-1] + 1)).difference(tmpLoadStepList):
			self.loadStepList.append((progress, lambda: None))
		self.loadStepList.sort()
