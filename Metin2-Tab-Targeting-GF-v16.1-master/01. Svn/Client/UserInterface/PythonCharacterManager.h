//1.1 Search for:
	protected:
		void								UpdateTransform();
		void								UpdateDeleting();
//1.1 Add after:
#if defined(ENABLE_TAB_NEXT_TARGET)
	public:
		CInstanceBase *						GetTabNextTargetPointer(CInstanceBase * pkInstMain);
		const DWORD							GetTabNextTargetVectorIndex() { return m_adwVectorIndexTabNextTarget; }
		void								ResetTabNextTargetVectorIndex() { m_adwVectorIndexTabNextTarget = -1; }
		
	protected:
		DWORD								m_adwVectorIndexTabNextTarget;
#endif