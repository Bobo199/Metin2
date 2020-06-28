# In anypart add if you not have:

import app

# Search

GUILD_BUILDING_LIST_TXT

# Replace for:

GUILD_BUILDING_LIST_TXT = app.GetMyLang() + "/GuildBuildingList.txt"

# Search

def LoadLocaleData():

# Replace replace all function for
    
def LoadLocaleData():
		app.LoadLocaleData(app.GetMyLang())
