class MapManager : public singleton<MapManager>
{
	private :
	
		std::map<DWORD, std::map<DWORD, DWORD>> maps = {
			{ 181, {} },
			{ 182, {} },
			{ 183, {} }
		};
		
	public :
		bool Initialize();
		void Destroy();
		void Enter(LPCHARACTER pChar);
		bool IsPlayerIPInMap(LPCHARACTER pChar);
		bool IsUniqueIPMap(DWORD map_index);
};

