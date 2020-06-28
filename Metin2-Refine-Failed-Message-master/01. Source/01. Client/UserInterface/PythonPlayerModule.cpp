//1.) Search for:
extern const DWORD c_iSkillIndex_Summon		= 131;
//1.2) Add after:
#ifdef ENABLE_REFINE_MSG_ADD
enum ERefineFailType
{
	REFINE_FAIL_GRADE_DOWN,
	REFINE_FAIL_DEL_ITEM,
	REFINE_FAIL_KEEP_GRADE,
	REFINE_FAIL_MAX,
};
#endif

//2.1) Search for:
	PyModule_AddIntConstant(poModule, "ENERGY",		POINT_ENERGY);
	PyModule_AddIntConstant(poModule, "ENERGY_END_TIME",		POINT_ENERGY_END_TIME);
//2.2) Add after:
#ifdef ENABLE_REFINE_MSG_ADD
	PyModule_AddIntConstant(poModule, "REFINE_FAIL_GRADE_DOWN",		REFINE_FAIL_GRADE_DOWN);
	PyModule_AddIntConstant(poModule, "REFINE_FAIL_DEL_ITEM",		REFINE_FAIL_DEL_ITEM);
	PyModule_AddIntConstant(poModule, "REFINE_FAIL_KEEP_GRADE",		REFINE_FAIL_KEEP_GRADE);
	PyModule_AddIntConstant(poModule, "REFINE_FAIL_MAX",			REFINE_FAIL_MAX);
#endif
