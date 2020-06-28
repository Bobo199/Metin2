#Find
ITEM_FLAG_APPLICABLE = 1 << 14

#Add
if app.ENABLE_EXTEND_INVEN_SYSTEM:
	EX_INVEN_COVER_IMG_OPEN		= "d:/ymir work/ui/ex_inven_cover_button_open.sub"
	EX_INVEN_COVER_IMG_CLOSE	= "d:/ymir work/ui/ex_inven_cover_button_close.sub"
	
#Find
			self.equipmentTab.append(self.GetChild("Equipment_Tab_02"))
		
#Add
			if app.ENABLE_EXTEND_INVEN_SYSTEM:
				self.__CreateExtendInvenButton()
				self.ExInvenQuestionDlg = uiCommon.QuestionDialog()
				self.ExInvenQuestionDlg.Close()
				self.pop = None
				
#Find
		self.dlgPickMoney = 0
		
#Add
		if app.ENABLE_EXTEND_INVEN_SYSTEM:
			self.ExInvenButton = []
			if self.ExInvenQuestionDlg:
				self.ExInvenQuestionDlg.Close()
				
#Find
	def SetEquipmentPage(self, page):
		self.equipmentPageIndex = page
		self.equipmentTab[1-page].SetUp()
		self.RefreshEquipSlotWindow()
			
#Add
	if app.ENABLE_EXTEND_INVEN_SYSTEM:
		def __CreateExtendInvenButton(self):
			parent = self.GetChild("board")
			self.ExInvenButton = []
			start_x		= 8
			start_y		= 246
			img_height	= 32
			for button_index in range(player.INVENTORY_LOCKED_PAGE_COUNT*9):
				ex_inven_button = ui.Button()			
				increase_y	= img_height * (button_index % 9)
				ex_inven_button.SetParent(parent)
				ex_inven_button.SetPosition(start_x, start_y + increase_y )
				ex_inven_button.SetUpVisual(EX_INVEN_COVER_IMG_CLOSE)
				ex_inven_button.SetOverVisual(EX_INVEN_COVER_IMG_CLOSE)
				ex_inven_button.SetDownVisual(EX_INVEN_COVER_IMG_CLOSE)
				ex_inven_button.SetDisableVisual(EX_INVEN_COVER_IMG_CLOSE)
				ex_inven_button.SetEvent(ui.__mem_func__(self.__ClickExtendInvenButton), button_index)
				ex_inven_button.Hide()
				self.ExInvenButton.append(ex_inven_button)
				
		def __ClickExtendInvenButton(self, index):
			if index >= len(self.ExInvenButton):
				self.__OpenExInvenMsgDlg(localeInfo.EXINVEN_USE_ITEM_FAIL_FOURTH_PAGE_STAGE_MAX)
				return
			if self.ExInvenQuestionDlg and index == player.GetExtendInvenStage():
				needkeys = []
				for n in range(player.INVENTORY_NEED_KEY_START, (player.INVENTORY_LOCKED_PAGE_COUNT*player.INVENTORY_NEED_KEY_INCREASE)+2):
					for i in range(3):
						needkeys.append(n)
				self.ExInvenQuestionDlg.SetText(localeInfo.EXINVEN_USE_ITEM_QUESTION % needkeys[index])
				self.ExInvenQuestionDlg.SetAcceptEvent(ui.__mem_func__(self.__AcceptExInvenItemUse))
				self.ExInvenQuestionDlg.SetCancelEvent(ui.__mem_func__(self.__CancelExInvenItemUse))
				w,h = self.ExInvenQuestionDlg.GetTextSize()
				self.ExInvenQuestionDlg.SetWidth( w + 40 )
				self.ExInvenQuestionDlg.Open()
		def __HideAllExtendInvenButton(self):		
			for index in range( len(self.ExInvenButton) ):
				self.ExInvenButton[index].Hide()				
		def __ShowExtendInvenButton(self, cur_stage):
			if self.inventoryPageIndex < player.INVENTORY_OPEN_PAGE_COUNT:
				return
			count = 9
			min_range = (self.inventoryPageIndex - player.INVENTORY_OPEN_PAGE_COUNT) * count
			max_range = min_range + count		
			for button_index in range(min_range, max_range):
				if button_index == cur_stage:
					self.ExInvenButton[button_index].SetUpVisual(EX_INVEN_COVER_IMG_OPEN)
					self.ExInvenButton[button_index].SetOverVisual(EX_INVEN_COVER_IMG_OPEN)
					self.ExInvenButton[button_index].SetDownVisual(EX_INVEN_COVER_IMG_OPEN)
					self.ExInvenButton[button_index].SetDisableVisual(EX_INVEN_COVER_IMG_OPEN)				
				if button_index < cur_stage:
					self.ExInvenButton[button_index].Hide()
				else:
					self.ExInvenButton[button_index].Show()
		def __RefreshExinvenCoverSlot(self):	
			self.__HideAllExtendInvenButton()
			self.__ShowExtendInvenButton(player.GetExtendInvenStage())
		def __AcceptExInvenItemUse(self):
			net.Envanter_genislet()
			self.ExInvenQuestionDlg.Close()		
		def __CancelExInvenItemUse(self):		
			self.ExInvenQuestionDlg.Close()
		def __OpenExInvenMsgDlg(self, msg):
			popup = uiCommon.PopupDialog()
			popup.SetText(msg)
			popup.SetAcceptEvent(self.__OnClosePopupDialog)
			w,h = popup.GetTextSize()
			popup.SetWidth( w + 40 )
			popup.Open()
			if self.pop:
				self.pop.Destroy()			
			self.pop = popup				
		def OpenExInvenFallShortCountMsgDlg(self, enough_count):
			popup = uiCommon.PopupDialog()
			popup.SetText(localeInfo.EXINVEN_USE_ITEM_FAIL_FALL_SHORT % int(enough_count) )
			popup.SetAcceptEvent(self.__OnClosePopupDialog)
			popup.Open()			
			if self.pop:
				self.pop.Destroy()		
			self.pop = popup
			
#Find
		self.wndItem.RefreshSlot()
		
#Add
		if app.ENABLE_EXTEND_INVEN_SYSTEM:
			self.__RefreshExinvenCoverSlot()
			
#Find
	def __UseItem(self, slotIndex):
		ItemVNum = player.GetItemIndex(slotIndex)
		item.SelectItem(ItemVNum)
		
#Add
		if player.IsExtendInvenKey(ItemVNum) and app.ENABLE_EXTEND_INVEN_SYSTEM:
			self.__ClickExtendInvenButton(player.GetExtendInvenStage())
