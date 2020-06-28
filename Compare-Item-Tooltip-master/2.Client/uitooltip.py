#Find in : class ToolTip(ui.ThinBoard) / def __init__(self, width = TOOL_TIP_WIDTH, isPickable=False):
#########################################################		
		self.ClearToolTip()
#########################################################
		
#Add
#########################################################
		if app.__COMPARE_TOOLTIP__:
			self.CompareTooltip = None
			self.IsCompare = False
#########################################################
			
#Find in : class ToolTip(ui.ThinBoard) / def __del__(self):
#########################################################
		ui.ThinBoard.__del__(self)
#########################################################
		
#Add
#########################################################
		if app.__COMPARE_TOOLTIP__ and self.CompareTooltip:
			del self.CompareTooltip
#########################################################		
			
#Find in def HideToolTip(self):
#########################################################
		self.Hide()
#########################################################

#Add
#########################################################
		if app.__COMPARE_TOOLTIP__ and self.CompareTooltip:
			self.CompareTooltip.Hide()
#########################################################
			
#Find
#########################################################
		self.SetPosition(x, y)
#########################################################
		
#Add Above
#########################################################
		if app.__COMPARE_TOOLTIP__:
			if self.IsCompare:
				return
			if self.CompareTooltip:
				val = [0] * 2
				if x < self.CompareTooltip.GetWidth():
					val[0] = self.GetWidth()
				else:
					val[0] = -self.CompareTooltip.GetWidth()
				CompareHeight = wndMgr.GetScreenHeight() - self.CompareTooltip.GetHeight()
				if y > CompareHeight:
					val[1] = CompareHeight - y
				elif y < 0:
					val[1] = 0 - y
				self.CompareTooltip.SetPosition(x + val[0], y + val[1])
#########################################################
					
#Add New Function
#########################################################
	if app.__COMPARE_TOOLTIP__:
		def SetCompareItem(self, itemVnum):
			slotIndex = item.GetCompareIndex(itemVnum)
			if slotIndex:
				if not self.CompareTooltip:
					self.CompareTooltip = ItemToolTip()
					self.CompareTooltip.IsCompare = True

				self.CompareTooltip.SetInventoryItem(slotIndex, player.INVENTORY, False)
				self.CompareTooltip.AutoAppendTextLine("Equipped", 0xffADFF2F)
				self.CompareTooltip.ResizeToolTip()
#########################################################
				
#Find
#########################################################
	def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY):
#########################################################

#Change
#########################################################
	# def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY):
	def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY, CompareItem = True):
#########################################################

#Find in same function
#########################################################
		self.AddItemData(itemVnum, metinSlot, attrSlot)
#########################################################
		
#Add
#########################################################
		if app.__COMPARE_TOOLTIP__ and app.IsPressed(app.DIK_LALT) and not slotIndex >= player.EQUIPMENT_SLOT_START and CompareItem:
			self.SetCompareItem(itemVnum)
#########################################################
			
#Find in def SetShopItem(self, slotIndex):
#########################################################
		self.AppendPrice(price)
#########################################################
		
#Add
#########################################################
		if app.__COMPARE_TOOLTIP__ and shop.IsOpen() and not shop.IsMainPlayerPrivateShop():
			self.SetCompareItem(itemVnum)
#########################################################

#Find in def SetExchangeTargetItem(self, slotIndex):
#########################################################
		self.AddItemData(itemVnum, metinSlot, attrSlot)
#########################################################
		
#Add
#########################################################
		if app.__COMPARE_TOOLTIP__:
			self.SetCompareItem(itemVnum)
#########################################################
		
#Find in def SetSafeBoxItem(self, slotIndex):
#########################################################
		self.AddItemData(itemVnum, metinSlot, attrSlot, safebox.GetItemFlags(slotIndex))
#########################################################
		
#Add
#########################################################
		if app.__COMPARE_TOOLTIP__:
			self.SetCompareItem(itemVnum)
#########################################################
			
#Find in def SetMallItem(self, slotIndex):
#########################################################
		self.AddItemData(itemVnum, metinSlot, attrSlot)
#########################################################

#Add
#########################################################
		if app.__COMPARE_TOOLTIP__:
			self.SetCompareItem(itemVnum)
#########################################################
