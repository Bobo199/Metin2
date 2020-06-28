# Search

if (localeInfo.IsEUROPE() and rgcapplic.GetLocalePath() != "locale/br"):

# Replace for:

if (localeInfo.IsEUROPE() and app.GetMyLang() != "locale/br"):


# Search

LoadGuildBuildingList(rgcapplic.GetLocalePath()+"/GuildBuildingList.txt")

# Replace for

LoadGuildBuildingList(app.GetMyLang()+"/GuildBuildingList.txt")
