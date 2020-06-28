# Multi Lang System
Multi Language System


- Instructions:

# Installation:

You will need add https://metin2.dev/board/topic/20397-guideemoji-in-textline/ by xP3NG3Rx for IMG in Chat and Whisper, the all definitions for Chats with IMG Icons it's "Multilanguage with KingDom"

Just Search in all Archives the DEFINES and place things as I have arranged.

DEFINES: 

- ENABLE_MULTILANGUAGE

If you like translate text you just change with Notepad++ or other all ChatPacket with a LC_TEXT  for TRANSLATE_LANGUAGE, if you like your default you just for DEFAULT_LANGUAGE.

For example:

	- CHAT_TYPE_TALKING, LC_TEXT(TRANSLATE_LANGUAGE,
	
	- CHAT_TYPE_INFO, LC_TEXT(TRANSLATE_LANGUAGE,
	
	- CHAT_TYPE_NOTICE, LC_TEXT(TRANSLATE_LANGUAGE,
	
	- CHAT_TYPE_PARTY, LC_TEXT(TRANSLATE_LANGUAGE,
	
	- CHAT_TYPE_GUILD, LC_TEXT(TRANSLATE_LANGUAGE,
	
	- CHAT_TYPE_SHOUT, LC_TEXT(TRANSLATE_LANGUAGE,
	
	- CHAT_TYPE_WHISPER, LC_TEXT(TRANSLATE_LANGUAGE,
	
	- CHAT_TYPE_BIG_NOTICE, LC_TEXT(TRANSLATE_LANGUAGE,
	
	- CHAT_TYPE_MONARCH_NOTICE, LC_TEXT(TRANSLATE_LANGUAGE,
	
	- CHAT_TYPE_DICE_INFO, LC_TEXT(TRANSLATE_LANGUAGE,

but not replace all please

	- CHAT_TYPE_COMMAND,
	
or if the CHAT have not a LC_TEXT, for the all cases i add parts in the code.

# Modifications for add or remove countrys:

- For change DEFAULT LANGUAGE you need change in length.h DEFAULT_LANGUAGE = 1 for your number language or other.

If you want add or remove a country you need:

Search in Client PythonApplicationModule.cpp and InstanceBaseEffect.cpp :

// FOR CHANGE COUNTRY

and replace the switch case for your switch case, but remember you need to couple the cases, to the order of the DB "common.lang".

Search in Server length.h:

enum ELanguages

and replace:

	MAX_LANGUAGES = 6,
	TRANSLATE_LANGUAGE = 7,
	
For a number greater than the number of languages you have, just remember, TRANSLATE_LANGUAGE must be greater than MAX_LANGUAGES

In your DB common.lang 

Just remove or add the language, but remember, the order that you have in the database must match that of PythonApplicationModule and InstanceBaseEffect of the Client.

# Note

You just need to accommodate the translations of your server and client, in addition to adding a button to change language, I was already lazy to do so.

The system works fine, I have already tried it.

For references I took the free system of Languages in a Turkish forum and fixed it.
