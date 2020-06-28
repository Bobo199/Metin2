bool CHARACTER::RemoveSpecifyItems(std::set<DWORD> _ilist, int count)
{
	if (_ilist.empty())
		return false;

	int totalicount(0);
	for (const auto& v : _ilist)
		totalicount += CountSpecifyItem(v);

	if (1 > count || totalicount < count)
		return false;

	while (count > 0 && _ilist.size()) {
		const auto vnum = *_ilist.begin();
		const auto i_count = CountSpecifyItem(vnum);
		if (!i_count) {
			_ilist.erase(_ilist.begin());
			continue;
		}
		const auto delcount = MINMAX(1, MIN(count, i_count), ITEM_MAX_COUNT);
		RemoveSpecifyItem(vnum, static_cast<DWORD>(delcount));
		count -= delcount;
	}
	return true;
}
