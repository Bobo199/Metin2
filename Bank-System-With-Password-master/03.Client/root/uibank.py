import ui, bank, net, player, localeInfo, constInfo, chat, grp, wndMgr, math, app
class BankDialog(ui.ScriptWindow):
	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.__LoadDialog()
		self.priceInputBoard = None
		self.InputBoard = None
		self.BlChangePassword = None
		self.islem = 0
		self.karakterid = 0
		self.xStart = 0
		self.yStart = 0
		
	def __del__(self):
		ui.ScriptWindow.__del__(self)
		
	def Open(self):
		self.SetPosition((wndMgr.GetScreenWidth() / 2) - int(math.floor(self.GetWidth() / 2.)), (wndMgr.GetScreenHeight() / 2) - int(math.floor(self.GetHeight() / 2.)))
		(self.xStart, self.yStart, z) = player.GetMainCharacterPosition()
		self.Show()
	
	def __LoadDialog(self):
		try:
			pyScrLoader = ui.PythonScriptLoader()
			pyScrLoader.LoadScriptFile(self, "uiscript/bankwindow.py")

			self.GetChild("TitleBar").SetCloseEvent(ui.__mem_func__(self.BClose))
			self.Yang = self.GetChild("Yang")
			self.YangBank = self.GetChild("YangBank")
			self.EpBank = self.GetChild("EpBank")
			self.Epp = self.GetChild("Epp")
			self.WonBank = self.GetChild("Wonbannk")
			self.Wonn = self.GetChild("Wonn")
			self.GetChild("ChangePassword").SetEvent(ui.__mem_func__(self.OnChangePassword))
			self.GetChild("Yattir").SetEvent(ui.__mem_func__(self.Add))
			self.GetChild("Cehh").SetEvent(ui.__mem_func__(self.WithDraw))
			self.GetChild("Gonder").SetEvent(ui.__mem_func__(self.Gonderrrrr))
			self.GetChild("Gapat").SetEvent(ui.__mem_func__(self.BClose))
		except:
			import exception
			exception.Abort("[Error] in Bank System")
			
	def OnChangePassword(self):
		if self.InputBoard or self.priceInputBoard or bank.GetChangePassword() == 1:
			return True
		self.BlChangePassword = ChangePasswordDialog()
		bank.OpenChangePassword(1)
		self.BlChangePassword.Open()
		
	def BClose(self):
		bank.SendClosePacket()
		
	def Close(self):
		self.Destroy()
		self.Hide()
		
	def OnPressEscapeKey(self):
		self.BClose()
		return TRUE	
		
	def OnUpdate(self):
		(yang, coins, won, nw_coins) = bank.GetFields()
		self.Yang.SetText(localeInfo.NumberToBankString(player.GetElk()))
		self.YangBank.SetText(localeInfo.NumberToBankString(yang))
		self.EpBank.SetText(localeInfo.NumberToBankString(coins))
		self.Epp.SetText(localeInfo.NumberToBankString(nw_coins))
		self.WonBank.SetText(localeInfo.NumberToBankString(won))
		self.Wonn.SetText(localeInfo.NumberToBankString(player.GetWon()))
		(x, y, z) = player.GetMainCharacterPosition()
		if abs(x - self.xStart) > bank.LIMIT_RANGE or abs(y - self.yStart) > bank.LIMIT_RANGE:
			(self.xStart, self.yStart, z) = player.GetMainCharacterPosition()
			self.BClose()
			
	def Add(self):
		if self.priceInputBoard or self.InputBoard or bank.GetChangePassword() == 1:
			return True
		self.islem = 1
		self.priceInputBoard = MoneyInputDialogNew()
		self.priceInputBoard.SetTitle(localeInfo.PRIVATE_SHOP_INPUT_PRICE_DIALOG_TITLE)
		self.priceInputBoard.SetAcceptEvent(ui.__mem_func__(self.AcceptAdd))
		self.priceInputBoard.SetCancelEvent(ui.__mem_func__(self.CancelAdd))
		self.priceInputBoard.Open()		
	def WithDraw(self):
		if self.priceInputBoard or self.InputBoard or bank.GetChangePassword() == 1:
			return True		
		self.islem = 2
		self.priceInputBoard = MoneyInputDialogNew()
		self.priceInputBoard.SetTitle(localeInfo.PRIVATE_SHOP_INPUT_PRICE_DIALOG_TITLE)
		self.priceInputBoard.SetAcceptEvent(ui.__mem_func__(self.AcceptAdd))
		self.priceInputBoard.SetCancelEvent(ui.__mem_func__(self.CancelAdd))
		self.priceInputBoard.Open()	
	def AcceptAdd(self):
		if not self.priceInputBoard:
			return True

		text = self.priceInputBoard.inputValue.GetText()
		text2 = self.priceInputBoard.InputValue_Cheque.GetText()
		text3 = self.priceInputBoard.GetText2()

		if not text and not text2 and not text3:
			chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.NEED_PRICE_BANK)
			return True

		if not text.isdigit() and not text2.isdigit() and not text3.isdigit():
			chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.NEED_PRICE_BANK)
			return True

		if int(text) <= 0:
			if int(text2) <= 0:
				if int(text3) <= 0:
					chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.NEED_PRICE_BANK)
					return True

		yang = int(self.priceInputBoard.inputValue.GetText())
		won = int(self.priceInputBoard.InputValue_Cheque.GetText())
		ep = int(self.priceInputBoard.inputValue2.GetText())

		if self.islem == 1:
			bank.SendAddPacket(yang, ep, won)
		elif self.islem == 2:
			bank.SendWithDrawPacket(yang, ep, won)
		elif self.islem == 3:
			bank.SendSendPacket(self.InputBoard.GetText(), yang, ep, won)
		else:
			chat.AppendChat(chat.CHAT_TYPE_INFO, "errorr bank")
		self.Destroy()
		return True
		
	def CancelAdd(self):
		if not self.priceInputBoard:
			return True
		self.Destroy()
		return True
		
	def Destroy(self):
		if self.priceInputBoard:
			self.priceInputBoard.Close()
		if self.InputBoard:
			self.InputBoard.Close()
		if self.BlChangePassword:
			self.BlChangePassword.Close()
		self.priceInputBoard = None
		self.InputBoard = None
		self.BlChangePassword = None
		self.karakterid = 0
		self.islem = 0
		bank.OpenChangePassword(0)
		
	def Gonderrrrr(self):
		if self.InputBoard or self.priceInputBoard or bank.GetChangePassword() == 1:
			return True
			
		self.InputBoard = InputDialogOld()
		self.InputBoard.SetTitle(localeInfo.BANK_TARGET_NAME)
		self.InputBoard.SetAcceptEvent(ui.__mem_func__(self.AcceptSend))
		self.InputBoard.SetCancelEvent(ui.__mem_func__(self.CancelSend))
		self.InputBoard.Open()
		
	def AcceptSend(self):
		if self.priceInputBoard or not self.InputBoard:
			return True
			
		self.islem = 3
		self.priceInputBoard = MoneyInputDialogNew()
		self.priceInputBoard.SetTitle(localeInfo.PRIVATE_SHOP_INPUT_PRICE_DIALOG_TITLE)
		self.priceInputBoard.SetAcceptEvent(ui.__mem_func__(self.AcceptAdd))
		self.priceInputBoard.SetCancelEvent(ui.__mem_func__(self.CancelAdd))
		self.priceInputBoard.Open()
		self.InputBoard.Hide()
		
	def CancelSend(self):
		if not self.InputBoard:
			return True
		self.Destroy()
		return True
		
class InputDialogOld(ui.ScriptWindow):

	def __init__(self):
		ui.ScriptWindow.__init__(self)

		self.__CreateDialog()

	def __del__(self):
		ui.ScriptWindow.__del__(self)

	def __CreateDialog(self):

		pyScrLoader = ui.PythonScriptLoader()
		pyScrLoader.LoadScriptFile(self, "uiscript/inputdialog.py")

		getObject = self.GetChild
		self.board = getObject("Board")
		self.acceptButton = getObject("AcceptButton")
		self.cancelButton = getObject("CancelButton")
		self.inputSlot = getObject("InputSlot")
		self.inputValue = getObject("InputValue")

	def Open(self):
		self.inputValue.SetFocus()
		self.SetCenterPosition()
		self.SetTop()
		self.Show()

	def Close(self):
		self.ClearDictionary()
		self.board = None
		self.acceptButton = None
		self.cancelButton = None
		self.inputSlot = None
		self.inputValue = None
		self.Hide()

	def SetTitle(self, name):
		self.board.SetTitleName(name)

	def SetNumberMode(self):
		self.inputValue.SetNumberMode()

	def SetSecretMode(self):
		self.inputValue.SetSecret()

	def SetFocus(self):
		self.inputValue.SetFocus()

	def SetMaxLength(self, length):
		width = length * 6 + 10
		self.SetBoardWidth(max(width + 50, 160))
		self.SetSlotWidth(width)
		self.inputValue.SetMax(length)

	def SetSlotWidth(self, width):
		self.inputSlot.SetSize(width, self.inputSlot.GetHeight())
		self.inputValue.SetSize(width, self.inputValue.GetHeight())
		if self.IsRTL():
			self.inputValue.SetPosition(self.inputValue.GetWidth(), 0)

	def SetBoardWidth(self, width):
		self.SetSize(max(width + 50, 160), self.GetHeight())
		self.board.SetSize(max(width + 50, 160), self.GetHeight())	
		if self.IsRTL():
			self.board.SetPosition(self.board.GetWidth(), 0)
		self.UpdateRect()

	def SetAcceptEvent(self, event):
		self.acceptButton.SetEvent(event)
		self.inputValue.OnIMEReturn = event

	def SetCancelEvent(self, event):
		self.board.SetCloseEvent(event)
		self.cancelButton.SetEvent(event)
		self.inputValue.OnPressEscapeKey = event

	def GetText(self):
		return self.inputValue.GetText()
		
class MoneyInputDialogNew(ui.ScriptWindow):

	def __init__(self):
		ui.ScriptWindow.__init__(self)

		self.moneyHeaderText = localeInfo.MONEY_INPUT_DIALOG_SELLPRICE
		self.chequeHeaderText = " Won"
		self.__CreateDialog()
		self.SetMaxLength(9)

	def __del__(self):
		ui.ScriptWindow.__del__(self)

	def __CreateDialog(self):
		pyScrLoader = ui.PythonScriptLoader()
		pyScrLoader.LoadScriptFile(self, "uiscript/bankinputdialog.py")
		getObject = self.GetChild
		self.board = self.GetChild("board")
		self.acceptButton = getObject("AcceptButton")
		self.cancelButton = getObject("CancelButton")
		self.inputValue = getObject("InputValue")
		self.inputValue.SetNumberMode()
		self.inputValue.OnIMEUpdate = ui.__mem_func__(self.__OnValueUpdate)
		self.inputValue2 = getObject("InputValue2")
		self.inputValue2.SetNumberMode()
		self.inputValue2.OnIMEUpdate = ui.__mem_func__(self.__OnValueUpdate2)
		self.moneyText = getObject("MoneyValue")
		self.moneyText2 = getObject("MoneyValue2")
		self.InputValue_Cheque = getObject("InputValue_Cheque")
		self.InputValue_Cheque.SetNumberMode()
		self.InputValue_Cheque.OnIMEUpdate = ui.__mem_func__(self.__OnValueUpdateCheque)
		self.chequeText = getObject("ChequeValue")

	def Open(self):
		self.inputValue.SetText("0")
		self.inputValue2.SetText("0")
		self.inputValue.SetFocus()
		self.inputValue2.SetFocus()
		self.__OnValueUpdate()
		self.InputValue_Cheque.SetText("0")
		self.InputValue_Cheque.SetFocus()
		self.__OnValueUpdateCheque()
		self.__OnValueUpdate2()
		self.SetCenterPosition()
		self.SetTop()
		self.Show()

	def Close(self):
		self.ClearDictionary()
		self.board = None
		self.acceptButton = None
		self.cancelButton = None
		self.inputValue = None
		self.InputValue_Cheque = None
		self.inputValue2 = None
		self.Hide()

	def SetTitle(self, name):
		self.board.SetTitleName(name)

	def SetFocus(self):
		self.inputValue.SetFocus()
		self.inputValue2.SetFocus()
		self.InputValue_Cheque.SetFocus()

	def SetMaxLength(self, length):
		length = min(9, length)
		self.inputValue.SetMax(length)
		self.inputValue2.SetMax(length)
		
	def SetMaxLengthCheque(self, length):
		length = min(2, length)
		self.InputValue_Cheque.SetMax(length)

	def SetMoneyHeaderText(self, text):
		self.moneyHeaderText = text
		if app.ENABLE_CHEQUE_SYSTEM:
			self.chequeHeaderText = text
		
	def SetMoneyHeaderText2(self, text):
		self.moneyHeaderText2 = text

	def SetAcceptEvent(self, event):
		self.acceptButton.SetEvent(event)
		self.inputValue.OnIMEReturn = event
		self.inputValue2.OnIMEReturn = event
		if app.ENABLE_CHEQUE_SYSTEM:
			self.InputValue_Cheque.OnIMEReturn = event

	def SetCancelEvent(self, event):
		self.board.SetCloseEvent(event)
		self.cancelButton.SetEvent(event)
		self.inputValue.OnPressEscapeKey = event
		self.inputValue2.OnPressEscapeKey = event
		if app.ENABLE_CHEQUE_SYSTEM:
			self.InputValue_Cheque.OnPressEscapeKey = event

	def SetValue(self, value):
		value=str(value)
		self.inputValue.SetText(value)
		self.__OnValueUpdate()
		ime.SetCursorPosition(len(value))		

	def SetValue2(self, value):
		value=str(value)
		self.inputValue2.SetText(value)
		self.__OnValueUpdate2()
		ime.SetCursorPosition(len(value))			

	def GetText(self):
		return self.inputValue.GetText()
		
	def SetValueCheque(self, value):
		value=str(value)
		self.InputValue_Cheque.SetText(value)
		self.__OnValueUpdateCheque()
		ime.SetCursorPosition(len(value))
		
	def GetText2(self):
		return self.inputValue2.GetText()

	def __OnValueUpdate(self):
		ui.EditLine.OnIMEUpdate(self.inputValue)

		text = self.inputValue.GetText()

		money = 0
		cheque = 0
		if text and text.isdigit():
			try:
				money = int(text)
			except ValueError:
				money = 199999999
				
		self.moneyText.SetText(localeInfo.NumberToBankString(money) + " Yang")
		
	def __OnValueUpdateCheque(self):
		ui.EditLine.OnIMEUpdate(self.InputValue_Cheque)

		text = self.InputValue_Cheque.GetText()

		cheque = 0
		if text and text.isdigit():
			try:
				cheque = int(text)
			except ValueError:
				cheque = 99

		self.chequeText.SetText(localeInfo.NumberToBankString(cheque) + self.chequeHeaderText)
	
	def __OnValueUpdate2(self):
		ui.EditLine.OnIMEUpdate(self.inputValue2)
		
		text = self.inputValue2.GetText()
		
		money = 0
		if text and text.isdigit():
			try:
				money = int(text)
			except ValueError:
				money = 199999999
				
		self.moneyText2.SetText(localeInfo.NumberToBankString(money) + " " + localeInfo.COINS_BANK)
		
class ChangePasswordDialog(ui.ScriptWindow):
	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.__LoadDialog()
		self.LoadDialog()

	def __del__(self):
		ui.ScriptWindow.__del__(self)

	def __LoadDialog(self):
		self.dlgMessage = ui.ScriptWindow()
		try:
			pyScrLoader = ui.PythonScriptLoader()
			pyScrLoader.LoadScriptFile(self.dlgMessage, "uiscript/popupdialog.py")
			self.dlgMessage.GetChild("message").SetText(localeInfo.SAFEBOX_WRONG_PASSWORD)
			self.dlgMessage.GetChild("accept").SetEvent(ui.__mem_func__(self.OnCloseMessageDialog))
		except:
			import exception
			exception.Abort("SafeboxWindow.__LoadDialog.LoadObject")

	def LoadDialog(self):
		try:
			pyScrLoader = ui.PythonScriptLoader()
			pyScrLoader.LoadScriptFile(self, "uiscript/changepassworddialog.py")

		except:
			import exception
			exception.Abort("ChangePasswordDialog.LoadDialog.LoadObject")

		try:
			self.GetChild("accept_button").SetEvent(ui.__mem_func__(self.OnAccept))
			self.GetChild("cancel_button").SetEvent(ui.__mem_func__(self.OnCancel))
			self.GetChild("titlebar").SetCloseEvent(ui.__mem_func__(self.OnCancel))
			oldPassword = self.GetChild("old_password_value")
			newPassword = self.GetChild("new_password_value")
			newPasswordCheck = self.GetChild("new_password_check_value")
		except:
			import exception
			exception.Abort("ChangePasswordDialog.LoadDialog.BindObject")

		oldPassword.SetTabEvent(lambda arg=1: self.OnNextFocus(arg))
		newPassword.SetTabEvent(lambda arg=2: self.OnNextFocus(arg))
		newPasswordCheck.SetTabEvent(lambda arg=3: self.OnNextFocus(arg))
		oldPassword.SetReturnEvent(lambda arg=1: self.OnNextFocus(arg))
		newPassword.SetReturnEvent(lambda arg=2: self.OnNextFocus(arg))
		newPasswordCheck.SetReturnEvent(ui.__mem_func__(self.OnAccept))
		oldPassword.OnPressEscapeKey = self.OnCancel
		newPassword.OnPressEscapeKey = self.OnCancel
		newPasswordCheck.OnPressEscapeKey = self.OnCancel

		self.oldPassword = oldPassword
		self.newPassword = newPassword
		self.newPasswordCheck = newPasswordCheck

	def OnNextFocus(self, arg):
		if 1 == arg:
			self.oldPassword.KillFocus()
			self.newPassword.SetFocus()
		elif 2 == arg:
			self.newPassword.KillFocus()
			self.newPasswordCheck.SetFocus()
		elif 3 == arg:
			self.newPasswordCheck.KillFocus()
			self.oldPassword.SetFocus()

	def Destroy(self):
		self.ClearDictionary()
		self.dlgMessage.ClearDictionary()
		self.oldPassword = None
		self.newPassword = None
		self.newPasswordCheck = None

	def Open(self):
		self.oldPassword.SetText("")
		self.newPassword.SetText("")
		self.newPasswordCheck.SetText("")
		self.oldPassword.SetFocus()
		self.SetCenterPosition()
		self.SetTop()
		self.Show()

	def Close(self):
		self.oldPassword.SetText("")
		self.newPassword.SetText("")
		self.newPasswordCheck.SetText("")
		self.oldPassword.KillFocus()
		self.newPassword.KillFocus()
		self.newPasswordCheck.KillFocus()
		self.Hide()
		bank.OpenChangePassword(0)
		
	def SetCancelEvent(self, event):
		self.dlgMessage.SetCloseEvent(event)
		self.oldPassword.SetText("")
		self.newPassword.SetText("")
		self.newPasswordCheck.SetText("")
		self.oldPassword.KillFocus()
		self.newPassword.KillFocus()
		self.newPasswordCheck.KillFocus()
		self.Hide()

	def OnAccept(self):
		oldPasswordText = self.oldPassword.GetText()
		newPasswordText = self.newPassword.GetText()
		newPasswordCheckText = self.newPasswordCheck.GetText()
		if newPasswordText != newPasswordCheckText:
			self.dlgMessage.SetCenterPosition()
			self.dlgMessage.SetTop()
			self.dlgMessage.Show()
			return TRUE
		bank.SendChangePassword(oldPasswordText, newPasswordText)
		self.Close()
		return TRUE

	def OnCancel(self):
		self.Close()
		return TRUE

	def OnCloseMessageDialog(self):
		self.newPassword.SetText("")
		self.newPasswordCheck.SetText("")
		self.newPassword.SetFocus()
		self.dlgMessage.Hide()
		
class Component:
	def Button(self, parent, buttonName, tooltipText, x, y, func, UpVisual, OverVisual, DownVisual):
		button = ui.Button()
		if parent != None:
			button.SetParent(parent)
		button.SetPosition(x, y)
		button.SetUpVisual(UpVisual)
		button.SetOverVisual(OverVisual)
		button.SetDownVisual(DownVisual)
		button.SetText(buttonName)
		button.SetToolTipText(tooltipText)
		button.Show()
		button.SetEvent(func)
		return button

	def ToggleButton(self, parent, buttonName, tooltipText, x, y, funcUp, funcDown, UpVisual, OverVisual, DownVisual):
		button = ui.ToggleButton()
		if parent != None:
			button.SetParent(parent)
		button.SetPosition(x, y)
		button.SetUpVisual(UpVisual)
		button.SetOverVisual(OverVisual)
		button.SetDownVisual(DownVisual)
		button.SetText(buttonName)
		button.SetToolTipText(tooltipText)
		button.Show()
		button.SetToggleUpEvent(funcUp)
		button.SetToggleDownEvent(funcDown)
		return button
		
	def HorizontalBar(self, parent, x, y, width):
		bar = ui.HorizontalBar()
		if parent != None:
			bar.SetParent(parent)
		bar.SetPosition(x, y)
		bar.Create(width)
		bar.Show()
		return bar

	def EditLine(self, parent, editlineText, x, y, width, heigh, max):
		SlotBar = ui.SlotBar()
		if parent != None:
			SlotBar.SetParent(parent)
		SlotBar.SetSize(width, heigh)
		SlotBar.SetPosition(x, y)
		SlotBar.Show()
		Value = ui.EditLine()
		Value.SetParent(SlotBar)
		Value.SetSize(width, heigh)
		Value.SetPosition(3, 2)
		Value.SetMax(max)
		Value.SetLimitWidth(width)
		Value.SetMultiLine()
		Value.SetText(editlineText)
		Value.Show()
		self.Value = Value
		return SlotBar, Value

	def EditLineText(self):
		return self.Value.GetText()
		
	def SlotWithText(self, parent, text, x, y, width, height):
		SlotBar = ui.SlotBar()
		if parent != None:
			SlotBar.SetParent(parent)
		SlotBar.SetSize(width, height)
		SlotBar.SetPosition(x, y)
		SlotBar.Show()
		textline = ui.TextLine()
		textline.SetParent(SlotBar)
		textline.SetPosition(5, 1)
		textline.SetText(text)
		textline.Show()
		return SlotBar, textline

	def TextLine(self, parent, textlineText, x, y, color):
		textline = ui.TextLine()
		if parent != None:
			textline.SetParent(parent)
		textline.SetPosition(x, y)
		if color != None:
			textline.SetFontColor(color[0], color[1], color[2])
		textline.SetText(textlineText)
		textline.Show()
		return textline
		
	def LargeTextLine(self, parent, textlineText, x, y, color):
		textline = ui.TextLine()
		if parent != None:
			textline.SetParent(parent)
		textline.SetPosition(x, y)
		textline.SetFontName(locale.UI_DEF_FONT_LARGE)
		textline.SetPackedFontColor(color)
		textline.SetText(textlineText)
		textline.Show()
		return textline

	def RGB(self, r, g, b):
		return (r*255, g*255, b*255)

	def SliderBar(self, parent, sliderPos, func, x, y):
		Slider = ui.SliderBar()
		if parent != None:
			Slider.SetParent(parent)
		Slider.SetPosition(x, y)
		Slider.SetSliderPos(sliderPos / 100)
		Slider.Show()
		Slider.SetEvent(func)
		return Slider

	def ExpandedImage(self, parent, x, y, img):
		image = ui.ExpandedImageBox()
		if parent != None:
			image.SetParent(parent)
		image.SetPosition(x, y)
		image.LoadImage(img)
		image.Show()
		return image

	def ComboBox(self, parent, text, x, y, width):
		combo = ui.ComboBox()
		if parent != None:
			combo.SetParent(parent)
		combo.SetPosition(x, y)
		combo.SetSize(width, 15)
		combo.SetCurrentItem(text)
		combo.Show()
		return combo

	def ThinBoard(self, parent, moveable, x, y, width, heigh, center):
		thin = ui.ThinBoard()
		if parent != None:
			thin.SetParent(parent)
		if moveable == TRUE:
			thin.AddFlag('movable')
			thin.AddFlag('float')
		thin.SetSize(width, heigh)
		thin.SetPosition(x, y)
		if center == TRUE:
			thin.SetCenterPosition()
		thin.Show()
		return thin

	def Gauge(self, parent, width, color, x, y):
		gauge = ui.Gauge()
		if parent != None:
			gauge.SetParent(parent)
		gauge.SetPosition(x, y)
		gauge.MakeGauge(width, color)
		gauge.Show()
		return gauge

	def ListBoxEx(self, parent, x, y, width, heigh):
		bar = ui.Bar()
		if parent != None:
			bar.SetParent(parent)
		bar.SetPosition(x, y)
		bar.SetSize(width, heigh)
		bar.SetColor(0x77000000)
		bar.Show()
		ListBox=ui.ListBoxEx()
		ListBox.SetParent(bar)
		ListBox.SetPosition(0, 0)
		ListBox.SetSize(width, heigh)
		ListBox.Show()
		scroll = ui.ScrollBar()
		scroll.SetParent(ListBox)
		scroll.SetPosition(width-15, 0)
		scroll.SetScrollBarSize(heigh)
		scroll.Show()
		ListBox.SetScrollBar(scroll)
		return bar, ListBox
