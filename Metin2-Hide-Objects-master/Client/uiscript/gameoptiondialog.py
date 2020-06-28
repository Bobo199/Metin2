#Find
				{
					"name" : "pvp_free",
					"type" : "radio_button",

					"x" : LINE_DATA_X+SMALL_BUTTON_WIDTH*3,
					"y" : 90,

					"text" : uiScriptLocale.OPTION_PVPMODE_FREE,
					"tooltip_text" : uiScriptLocale.OPTION_PVPMODE_FREE_TOOLTIP,

					"default_image" : ROOT_PATH + "small_Button_01.sub",
					"over_image" : ROOT_PATH + "small_Button_02.sub",
					"down_image" : ROOT_PATH + "small_Button_03.sub",
				},
#Add
				# SetVisible
				{
					"name" : "visible_board",
					"type" : "text",

					"x" : LINE_LABEL_X,
					"y" : 290+2,

					"text" : "Visible",
				},
				{
					"name" : "vsble0",
					"type" : "toggle_button",

					"x" : LINE_DATA_X+SMALL_BUTTON_WIDTH*0,
					"y" : 290,

					"text" : "TREE",

					"default_image" : ROOT_PATH + "small_Button_01.sub",
					"over_image" : ROOT_PATH + "small_Button_02.sub",
					"down_image" : ROOT_PATH + "small_Button_03.sub",
				},
				{
					"name" : "vsble1",
					"type" : "toggle_button",

					"x" : LINE_DATA_X+SMALL_BUTTON_WIDTH*1,
					"y" : 290,

					"text" : "CLOUD",

					"default_image" : ROOT_PATH + "small_Button_01.sub",
					"over_image" : ROOT_PATH + "small_Button_02.sub",
					"down_image" : ROOT_PATH + "small_Button_03.sub",
				},
				{
					"name" : "vsble2",
					"type" : "toggle_button",

					"x" : LINE_DATA_X+SMALL_BUTTON_WIDTH*2,
					"y" : 290,

					"text" : "WATER",

					"default_image" : ROOT_PATH + "small_Button_01.sub",
					"over_image" : ROOT_PATH + "small_Button_02.sub",
					"down_image" : ROOT_PATH + "small_Button_03.sub",
				},
				{
					"name" : "vsble3",
					"type" : "toggle_button",

					"x" : LINE_DATA_X+SMALL_BUTTON_WIDTH*3,
					"y" : 290,

					"text" : "OBJECT",

					"default_image" : ROOT_PATH + "small_Button_01.sub",
					"over_image" : ROOT_PATH + "small_Button_02.sub",
					"down_image" : ROOT_PATH + "small_Button_03.sub",
				},
				{
					"name" : "vsble4",
					"type" : "toggle_button",

					"x" : LINE_DATA_X+SMALL_BUTTON_WIDTH*4,
					"y" : 290,

					"text" : "TERRAIN",

					"default_image" : ROOT_PATH + "small_Button_01.sub",
					"over_image" : ROOT_PATH + "small_Button_02.sub",
					"down_image" : ROOT_PATH + "small_Button_03.sub",
				},
				{
					"name" : "vsble5",
					"type" : "toggle_button",

					"x" : LINE_DATA_X+SMALL_BUTTON_WIDTH*5,
					"y" : 290,

					"text" : "SHOP",

					"default_image" : ROOT_PATH + "small_Button_01.sub",
					"over_image" : ROOT_PATH + "small_Button_02.sub",
					"down_image" : ROOT_PATH + "small_Button_03.sub",
				},