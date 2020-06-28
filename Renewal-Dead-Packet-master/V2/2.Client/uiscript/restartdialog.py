import app
import localeInfo
import uiScriptLocale

ROOT = "d:/ymir work/ui/public/"

window = {
	"name" : "RestartDialog",
	"style" : ("float",),

	"x" : 50,
	"y" : 50,

	"width" : 200,
	"height" : 88,

	"children" :
	(
		{
			"name" : "board",
			"type" : "thinboard",

			"x" : 0,
			"y" : 0,

			"width" : 200,
			"height" : 88,

			"r" : 0.3333,
			"g" : 0.2941,
			"b" : 0.2588,
			"a" : 1.0,

			"children" :
			(
				{
					"name" : "restart_here_button",
					"type" : "button",

					"x" : 10,
					"y" : 17,

					"text" : uiScriptLocale.RESTART_HERE,

					"default_image" : ROOT + "XLarge_Button_01.sub",
					"over_image" : ROOT + "XLarge_Button_02.sub",
					"down_image" : ROOT + "XLarge_Button_03.sub",
					"disable_image" : ROOT + "XLarge_Button_03.sub",
				},
				{
					"name" : "restart_town_button",
					"type" : "button",

					"x" : 10,
					"y" : 47,

					"text" : uiScriptLocale.RESTART_TOWN,

					"default_image" : ROOT + "XLarge_Button_01.sub",
					"over_image" : ROOT + "XLarge_Button_02.sub",
					"down_image" : ROOT + "XLarge_Button_03.sub",
					"disable_image" : ROOT + "XLarge_Button_03.sub",
				},
			),
		},
	),
}

if app.RENEWAL_DEAD_PACKET:
	window["height"] = window["height"] + 15
	window["children"][0]["height"] = window["children"][0]["height"] + 15
	window["children"][0]["children"] = window["children"][0]["children"] + (
				{
					"name" : "T00",
					"type" : "text",
					"x" : 170,
					"y" : 23,
					"text" : "",
				},
				{
					"name" : "T01",
					"type" : "text",
					"x" : 170,
					"y" : 53,
					"text" : "",
				},
				{
					"name" : "T02",
					"type" : "text",
					"x" : 8,
					"y" : 78,
					"text" : localeInfo.REVIVE_AUTO_TOWN_MESSAGE,
				},
	)
