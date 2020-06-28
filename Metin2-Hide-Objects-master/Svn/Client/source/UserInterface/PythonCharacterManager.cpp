//Find
void CPythonCharacterManager::__DeleteBlendOutInstance(CInstanceBase* pkInstDel)
{
	....
	....
}

///Add
#ifdef HIDE_OBJECTS
void CPythonCharacterManager::SetVisibleShops(bool visible)
{
	CPythonCharacterManager::CharacterIterator itor = CharacterInstanceBegin();
	CPythonCharacterManager::CharacterIterator itorEnd = CharacterInstanceEnd();
	CInstanceBase * pMainInstance = GetMainInstancePtr();
	int shop_vnum_count = 7;///30007
	for (; itor != itorEnd; ++itor) {
		CInstanceBase * pInstance = *itor;
		if (pInstance && pMainInstance != pInstance) {
			for (int i = 0; i <= shop_vnum_count; i++) {
				if (pInstance->GetRace() == 30000 + i) {
					if (visible)
						pInstance->Hide();
					else
						pInstance->Show();
				}
			}
			SCRIPT_SetAffect(pInstance->GetVirtualID(), 1, visible);
		}
	}
}
#endif