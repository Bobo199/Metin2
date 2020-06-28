#Find
	def SetShopItemBySecondaryCoin(self, slotIndex):
	
#Add
	if app.ENABLE_RENEWAL_SHOPEX:
		def SetShopItemByShopEx(self, slotIndex, type):
			itemVnum = shop.GetItemID(slotIndex)
			PriceVnum = shop.GetItemPriceVnum(slotIndex)
			if itemVnum == 0 or (PriceVnum == 0 and type == 3):
				return
			price = shop.GetItemPrice(slotIndex)
			self.ClearToolTip()
			self.isShopItem = True
			metinSlot = []
			for i in xrange(player.METIN_SOCKET_MAX_NUM):
				metinSlot.append(shop.GetItemMetinSocket(slotIndex, i))
			attrSlot = []
			for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
				attrSlot.append(shop.GetItemAttribute(slotIndex, i))
			self.AddItemData(itemVnum, metinSlot, attrSlot)
			self.AppendSpace(5)
			if type == 3:
				self.AddSHOPEXItem(PriceVnum, price)
			else:
				self.AppendTextLine(localeInfo.TOOLTIP_BUYPRICE  % (localeInfo.NumberToShopEXP(price)), self.GetPriceColor(price))

		def AddSHOPEXItem(self, itemVnum, price):
			self.AppendTextLine("Price:")
			item.SelectItem(itemVnum)
			name = "%s(%dx)" % (item.GetItemName(), price)
			self.AutoAppendTextLine(name, self.SPECIAL_TITLE_COLOR)
			itemImage = ui.ImageBox()
			itemImage.SetParent(self)
			itemImage.Show()			
			itemImage.LoadImage(item.GetIconImageFileName())
			itemImage.SetPosition(75, self.toolTipHeight)
			self.toolTipHeight += itemImage.GetHeight() - 10
			self.childrenList.append(itemImage)
			self.ResizeToolTip()