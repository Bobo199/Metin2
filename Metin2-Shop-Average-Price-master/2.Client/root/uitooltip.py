#Find in def SetShopItem(self, slotIndex):
		self.AppendPrice(price)
		
#Add
		if app.__SHOP_ITEM_AVERAGE__ and shop.IsPrivateShop():
			average_price = shop.GetItemAveragePrice(slotIndex)
			self.AppendSpace(5)
			self.AppendTextLine("Average Price: %s"  % (localeInfo.NumberToMoneyString(average_price)), self.GetPriceColor(average_price))