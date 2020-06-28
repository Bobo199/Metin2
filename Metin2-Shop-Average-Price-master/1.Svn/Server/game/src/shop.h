//Find
		void	SetShopItems(TShopItemTable * pItemTable, BYTE bItemCount);
		
///Add
#if defined(__SHOP_ITEM_AVERAGE__)
		const std::vector<SHOP_ITEM>& GetItemVector() const { return m_itemVector; };
#endif