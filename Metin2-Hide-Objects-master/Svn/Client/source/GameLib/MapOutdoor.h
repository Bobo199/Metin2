//Find
			PART_SKY,
	
///Add
			#ifdef HIDE_OBJECTS
			PART_SHOP,
			#endif

///Find and Change(Because it's protected):
		#ifndef HIDE_OBJECTS
		bool IsVisiblePart(int ePart);
		#endif
//Find
		void			SetVisiblePart(int ePart, bool isVisible);
		
///Add
		#ifdef HIDE_OBJECTS
		bool IsVisiblePart(int ePart);
		#endif