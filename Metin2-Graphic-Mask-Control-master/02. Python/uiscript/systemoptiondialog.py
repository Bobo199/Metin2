#1.1 Search for:
import uiScriptLocale
#1.2 Add after:
import app

# Go at end of file and add:
if app.ENABLE_GRAPHIC_MASK:
	window['height'] += 20
	window['children'][0]['height'] += 20
	window['children'][0]['children'] += ( \
		{
			"name" : "background_text",
			"type" : "text",
			"x" : 40 + TEXT_TEMPORARY_X,
			"y" : 210,
			"text" : uiScriptLocale.OPTION_BACKGROUND_MASK,
		},
		{
			"name" : "background_terrain",
			"type" : "toggle_button",
			"x" : 110,
			"y" : 210,
			"text" : uiScriptLocale.OPTION_BACKGROUND_MASK_TERRAIN,
			"default_image" : ROOT_PATH + "small_Button_01.sub",
			"over_image" : ROOT_PATH + "small_Button_02.sub",
			"down_image" : ROOT_PATH + "small_Button_03.sub",
		},
		{
			"name" : "background_object",
			"type" : "toggle_button",
			"x" : 110 + 50,
			"y" : 210,
			"text" : uiScriptLocale.OPTION_BACKGROUND_MASK_OBJECT,
			"default_image" : ROOT_PATH + "small_Button_01.sub",
			"over_image" : ROOT_PATH + "small_Button_02.sub",
			"down_image" : ROOT_PATH + "small_Button_03.sub",
		},
		{
			"name" : "background_cloud",
			"type" : "toggle_button",
			"x" : 110 + 50 + 50,
			"y" : 210,
			"text" : uiScriptLocale.OPTION_BACKGROUND_MASK_CLOUD,
			"default_image" : ROOT_PATH + "small_Button_01.sub",
			"over_image" : ROOT_PATH + "small_Button_02.sub",
			"down_image" : ROOT_PATH + "small_Button_03.sub",
		},
		{
			"name" : "background_tree",
			"type" : "toggle_button",
			"x" : 110,
			"y" : 235,
			"text" : uiScriptLocale.OPTION_BACKGROUND_MASK_TREE,
			"default_image" : ROOT_PATH + "small_Button_01.sub",
			"over_image" : ROOT_PATH + "small_Button_02.sub",
			"down_image" : ROOT_PATH + "small_Button_03.sub",
		},
		{
			"name" : "background_water",
			"type" : "toggle_button",
			"x" : 110 + 50,
			"y" : 235,
			"text" : uiScriptLocale.OPTION_BACKGROUND_MASK_WATER,
			"default_image" : ROOT_PATH + "small_Button_01.sub",
			"over_image" : ROOT_PATH + "small_Button_02.sub",
			"down_image" : ROOT_PATH + "small_Button_03.sub",
		},
	)