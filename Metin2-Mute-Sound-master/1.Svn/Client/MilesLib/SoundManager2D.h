//Find
		ISoundInstance *	GetInstance(const char* filename);
		
///Add
		ISoundInstance* CSoundManager2D::GetInstance(DWORD dwIndex)
		{
			return dwIndex >= INSTANCE_MAX_COUNT ? nullptr : &ms_Instances[dwIndex];
		};