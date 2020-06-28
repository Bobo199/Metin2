#ifndef __INC_METIN2_GAME_LOCALE_H__
#define __INC_METIN2_GAME_LOCALE_H__
#include "../../common/CommonDefines.h"

extern "C"
{
#ifdef ENABLE_MULTILANGUAGE
	void locale_init(BYTE blang, const char *filename);
	const char *locale_find(BYTE blang, const char *string);
#else
	void locale_init(const char *filename);
	const char *locale_find(const char *string);
#endif
	extern int g_iUseLocale;
#ifdef ENABLE_MULTILANGUAGE
#define LC_TEXT(lang, str) locale_find(lang, str)
#else
#define LC_TEXT(str) locale_find(str)
#endif
};

#endif
