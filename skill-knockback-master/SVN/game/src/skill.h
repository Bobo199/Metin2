// In enum ESkillFlags add SKILL_FLAG_KNOCKBACK = (1 << x), in my case is:

enum ESkillFlags
{
	SKILL_FLAG_ATTACK			= (1 << 0),	// °ø°Ý ±â¼ú
	SKILL_FLAG_USE_MELEE_DAMAGE		= (1 << 1),	// ±âº» ¹Ð¸® Å¸°ÝÄ¡¸¦ b °ªÀ¸·Î »ç¿ë
	SKILL_FLAG_COMPUTE_ATTGRADE		= (1 << 2),	// °ø°Ýµî±ÞÀ» °è»êÇÑ´Ù
	SKILL_FLAG_SELFONLY			= (1 << 3),	// ÀÚ½Å¿¡°Ô¸¸ ¾µ ¼ö ÀÖÀ½
	SKILL_FLAG_USE_MAGIC_DAMAGE		= (1 << 4),	// ±âº» ¸¶¹ý Å¸°ÝÄ¡¸¦ b °ªÀ¸·Î »ç¿ë
	SKILL_FLAG_USE_HP_AS_COST		= (1 << 5),	// HP¸¦ SP´ë½Å ¾´´Ù
	SKILL_FLAG_COMPUTE_MAGIC_DAMAGE	= (1 << 6),
	SKILL_FLAG_SPLASH			= (1 << 7),
	SKILL_FLAG_GIVE_PENALTY		= (1 << 8),	// ¾²°í³ª¸é Àá½Ãµ¿¾È(3ÃÊ) 2¹è µ¥¹ÌÁö¸¦ ¹Þ´Â´Ù.
	SKILL_FLAG_USE_ARROW_DAMAGE		= (1 << 9),	// ±âº» È­»ì Å¸°ÝÄ¡¸¦ b °ªÀ¸·Î »ç¿ë
	SKILL_FLAG_PENETRATE		= (1 << 10),	// ¹æ¾î¹«½Ã
	SKILL_FLAG_IGNORE_TARGET_RATING	= (1 << 11),	// »ó´ë ·¹ÀÌÆÃ ¹«½Ã
	SKILL_FLAG_SLOW			= (1 << 12),	// ½½·Î¿ì °ø°Ý
	SKILL_FLAG_STUN			= (1 << 13),	// ½ºÅÏ °ø°Ý
	SKILL_FLAG_HP_ABSORB		= (1 << 14),	// HP Èí¼ö
	SKILL_FLAG_SP_ABSORB		= (1 << 15),	// SP Èí¼ö
	SKILL_FLAG_FIRE_CONT		= (1 << 16),	// FIRE Áö¼Ó µ¥¹ÌÁö
	SKILL_FLAG_REMOVE_BAD_AFFECT	= (1 << 17),	// ³ª»ÛÈ¿°ú Á¦°Å
	SKILL_FLAG_REMOVE_GOOD_AFFECT	= (1 << 18),	// ³ª»ÛÈ¿°ú Á¦°Å
	SKILL_FLAG_CRUSH			= (1 << 19),	// »ó´ë¹æÀ» ³¯¸²
	SKILL_FLAG_POISON			= (1 << 20),	// µ¶ °ø°Ý
	SKILL_FLAG_TOGGLE			= (1 << 21),	// Åä±Û
	SKILL_FLAG_DISABLE_BY_POINT_UP	= (1 << 22),	// Âï¾î¼­ ¿Ã¸± ¼ö ¾ø´Ù.
	SKILL_FLAG_CRUSH_LONG		= (1 << 23),	// »ó´ë¹æÀ» ¸Ö¸® ³¯¸²
	SKILL_FLAG_WIND		= (1 << 24),	// ¹Ù¶÷ ¼Ó¼º
	SKILL_FLAG_ELEC		= (1 << 25),	// Àü±â ¼Ó¼º
	SKILL_FLAG_FIRE		= (1 << 26),	// ºÒ ¼Ó¼º
#ifdef ENABLE_WOLFMAN_CHARACTER
	SKILL_FLAG_BLEEDING	= (1 << 27),
	SKILL_FLAG_PARTY	= (1 << 28),
#endif
#ifdef NEW_SKILL_KNOCKBACK
	SKILL_FLAG_KNOCKBACK	= (1 << 29),
#endif
};
