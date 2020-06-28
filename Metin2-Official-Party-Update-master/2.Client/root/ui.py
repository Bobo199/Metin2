#Find in->class Gauge(Window):
		imgSlotRight.AddFlag("attach")
		
#Add
		if app.BL_PARTY_UPDATE:
			imgSlotLeft.AddFlag("not_pick")
			imgSlotCenter.AddFlag("not_pick")
			imgSlotRight.AddFlag("not_pick")
			imgGauge.AddFlag("not_pick")
			
#Find in->class Gauge(Window):
	def SetPercentage(self, curValue, maxValue):
		if maxValue > 0.0:
			percentage = min(1.0, float(curValue)/float(maxValue))
		else:
			percentage = 0.0
		gaugeSize = -1.0 + float(self.width - self.GAUGE_TEMPORARY_PLACE*2) * percentage / self.GAUGE_WIDTH
		self.imgGauge.SetRenderingRect(0.0, 0.0, gaugeSize, 0.0)
		
#Add
	if app.BL_PARTY_UPDATE:	
		def GaugeImgBoxAddFlag(self, flag):
			self.imgLeft.AddFlag(flag)
			self.imgCenter.AddFlag(flag)
			self.imgRight.AddFlag(flag)
			self.imgGauge.AddFlag(flag)	