//1.1 Search for:
			bool			bShowSalesText;
//1.1 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
			bool			bGraphicMaskTerrain;
			bool			bGraphicMaskObject;
			bool			bGraphicMaskCloud;
			bool			bGraphicMaskWater;
			bool			bGraphicMaskTree;
#endif

//1.2 Search for:
		void							SetShowSalesTextFlag(int iFlag);
//1.2 Add after:
#if defined(ENABLE_GRAPHIC_MASK)
		bool							GetGraphicMaskPart(const BYTE bPart);
		void							SetGraphicMaskPart(const BYTE bPart, const bool bFlag);
#endif