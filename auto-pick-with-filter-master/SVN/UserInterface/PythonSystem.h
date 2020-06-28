// Search  in typedef struct SConfig

bool			bShowSalesText; 

// Add after

			bool			bPickupFilterWeapon;
			bool			bPickupFilterArmor;
			bool			bPickupFilterEar;
			bool			bPickupFilterNeck;
			bool			bPickupFilterFoots;
			bool			bPickupFilterShield;
			bool			bPickupFilterBook;
			bool			bPickupFilterStone;
			bool			bPickupFilterEtc;
      
// Search

void							SetShowSalesTextFlag(int iFlag);

// Add after

		bool 							IsPickUpFilterWeapon();
		void 							SetPickUpFilterWeaponFlag(int iFlag);
		bool 							IsPickUpFilterArmor();
		void 							SetPickUpFilterArmorFlag(int iFlag);
		bool 							IsPickUpFilterEar();
		void 							SetPickUpFilterEarFlag(int iFlag);
		bool 							IsPickUpFilterNeck();
		void 							SetPickUpFilterNeckFlag(int iFlag);
		bool 							IsPickUpFilterFoots();
		void 							SetPickUpFilterFootsFlag(int iFlag);
		bool 							IsPickUpFilterShield();
		void 							SetPickUpFilterShieldFlag(int iFlag);
		bool 							IsPickUpFilterBook();
		void 							SetPickUpFilterBookFlag(int iFlag);	
		bool 							IsPickUpFilterStone();
		void 							SetPickUpFilterStoneFlag(int iFlag);
		bool 							IsPickUpFilterEtc();
		void 							SetPickUpFilterEtcFlag(int iFlag);
