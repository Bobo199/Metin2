#pragma once
#if defined(__LOADING_TIP__)
namespace NS_TipList
{
	//enum { VNUM_VEC, MAP_VEC };
	enum { NAMESTR, VNUM_VEC, MAP_VEC };
	static const std::vector<std::tuple<std::string, std::vector<int>, std::vector<int>>> Tip_List
	{
		{
			"Normal", // group name(should first line)
			{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,107}, // vnum list
			{} // map list
		},
		{
			"monkey", // group name
			{22,23,24,25}, // vnum list
			{5,25,45,107,108,109} // map list
		},
		{
			"spider", // group name
			{26,27,28,29,30}, // vnum list
			{71,104,217} // map list
		},
		{
			"devilcatacomb", // group name
			{35,36,37,38,39}, // vnum list
			{216} // map list
		},
		{
			"skipia", // group name
			{41,42,43,44,45,46,47,48}, // vnum list
			{72,73,208} // map list
		},
		{
			"flame", // group name
			{49,50,51,52,53}, // vnum list
			{351} // map list
		},
		{
			"thunder", // group name
			{60,61,62,63,64,65,66}, // vnum list
			{353,354} // map list
		},
		{
			"flamedragon", // group name
			
			{67,68,69,70,71,72,73,74}, // vnum list
			{356} // map list
		},
		{
			"12zi", // group name
			{75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97}, // vnum list
			{355} // map list
		},
		{
			"defensewave", // group name
			{98,99,100,101,102,103,104,105}, // vnum list
			{358} // map list
		},
		{
			"defenseport", // group name
			{106}, // vnum list
			{359} // map list
		},
		{
			"bossdungeon", // group name
			{108,109,110,111,112,113,114}, // vnum list
			{363,364,365,366,367,368,369,370,371} // map list
		},
		{
			"elemental", // group name
			{115,116,117,118,119,120}, // vnum list
			{378,379,380,381} // map list		
		},
	};
}
#endif