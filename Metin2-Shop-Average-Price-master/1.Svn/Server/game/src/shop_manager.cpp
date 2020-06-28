///Add
#if defined(__SHOP_ITEM_AVERAGE__)
/*
#include <numeric>
double CShopManager::GetItemAverage(const DWORD vnum)
{
	std::vector<long> price_vec;
	for (const auto& PCShopMap : m_map_pkShopByPC) {
		for (const auto & ItemVector: PCShopMap.second->GetItemVector())
			if (ItemVector.vnum == vnum && ItemVector.pkItem)
				price_vec.emplace_back(ItemVector.price);
	}
	return price_vec.empty() ? 0.0 : (std::accumulate(price_vec.begin(), price_vec.end(), 0.0) / price_vec.size());
}
*/
double CShopManager::GetItemAverage(const DWORD vnum)
{
	auto average = 0.0;
	auto counter = 1;

	for (const auto& PCShopMap : m_map_pkShopByPC) {
		const auto& ItemVector = PCShopMap.second->GetItemVector();
		for (auto it = ItemVector.begin(); (it = std::find_if(it, ItemVector.end(), [&vnum](const CShop::SHOP_ITEM& item) { return vnum == item.vnum && item.pkItem; })) != ItemVector.end(); ++it)
			average += (static_cast<decltype(average)>(it->price) - average) / (counter++);
	}

	return average;
}
#endif