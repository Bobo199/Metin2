//Find
		void			ClearItem();

///Add
#ifdef ENABLE_SORT_INVEN
		void			SortInven(BYTE option);
		DWORD			GetLastSortTime() const { return m_dwLastSortTime; }
		void			SetLastSortTime(DWORD time) { m_dwLastSortTime = time; }
#endif

//Find
		bool				m_bDisableCooltime;

///Add
#ifdef ENABLE_SORT_INVEN
		DWORD				m_dwLastSortTime;
#endif
