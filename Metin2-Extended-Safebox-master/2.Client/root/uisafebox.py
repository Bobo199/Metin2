#Find in class SafeboxWindow(ui.ScriptWindow):
	BOX_WIDTH = 176
	
#Add
	if app.__EXTENDED_SAFEBOX__:
		BUTTON_PER_LINE = 3
		
#Find
	def __MakePageButton(self, pageCount):
		...
		...
		
#Change
	if app.__EXTENDED_SAFEBOX__:
		def __MakePageButton(self, pageCount):
			self.curPageIndex = 0
			self.pageButtonList = []
			page_names = ["I", "II", "III", "IV", "V", "VI"] # edit manually for more page
			width = 52
			pos = []
			for i in xrange(pageCount):
				if i > len(page_names) - 1:
					page_names.append("X")
				if not i % self.BUTTON_PER_LINE:
					pos.append(-int((max(1, min(self.BUTTON_PER_LINE, pageCount))-1) * (width / 2)))
				button = ui.RadioButton()
				button.SetParent(self)
				button.SetUpVisual("d:/ymir work/ui/game/windows/tab_button_middle_01.sub")
				button.SetOverVisual("d:/ymir work/ui/game/windows/tab_button_middle_02.sub")
				button.SetDownVisual("d:/ymir work/ui/game/windows/tab_button_middle_03.sub")
				button.SetWindowHorizontalAlignCenter()
				button.SetWindowVerticalAlignBottom()
				button.SetPosition(pos[len(pos) - 1], (85 + ((pageCount-self.BUTTON_PER_LINE) + 1 % 3) * 4) - (len(pos) - 1) * 20)
				pos[len(pos) - 1] += width
				button.SetText(page_names[i])
				button.SetEvent(lambda arg=i: self.SelectPage(arg))
				button.Show()
				self.pageButtonList.append(button)
			self.pageButtonList[0].Down()
	else:
		def __MakePageButton(self, pageCount):
			self.curPageIndex = 0
			self.pageButtonList = []
			text = "I"
			pos = -int(float(pageCount-1)/2 * 52)
			for i in xrange(pageCount):
				button = ui.RadioButton()
				button.SetParent(self)
				button.SetUpVisual("d:/ymir work/ui/game/windows/tab_button_middle_01.sub")
				button.SetOverVisual("d:/ymir work/ui/game/windows/tab_button_middle_02.sub")
				button.SetDownVisual("d:/ymir work/ui/game/windows/tab_button_middle_03.sub")
				button.SetWindowHorizontalAlignCenter()
				button.SetWindowVerticalAlignBottom()
				button.SetPosition(pos, 85)
				button.SetText(text)
				button.SetEvent(lambda arg=i: self.SelectPage(arg))
				button.Show()
				self.pageButtonList.append(button)
				pos += 52
				text += "I"
			self.pageButtonList[0].Down()
			
#Find
		wnd_height = 130 + 32 * size
		
#Add
		if app.__EXTENDED_SAFEBOX__:
			wnd_height += (len(self.pageButtonList) / self.BUTTON_PER_LINE) * 7
			
#Find and Delete(2x)
		pageCount = min(3, pageCount)