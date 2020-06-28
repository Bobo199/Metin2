import app
import item
import uiScriptLocale
P_X = 200
P_Y = 145
BUTTON_ROOT = "d:/ymir work/ui/public/"
window = {
	"name" : "ChatSlowMode",
	"x" : 0,
	"y" : 0,
	"style" : ("movable", "float",),
	"width" : P_X,
	"height" : P_Y,
	"children" :
	(
		{
			"name" : "board",
			"type" : "board",
			"style" : ("attach",),
			"x" : 0,
			"y" : 0,
			"width" : P_X,
			"height" : P_Y,
			"children" :
			(
				{
					"name" : "TitleBar",
					"type" : "titlebar",
					"style" : ("attach",),
					"x" : 6,
					"y" : 6,
					"width" : P_X-12,
					"color" : "yellow",
					"children" :
					(
						{
							"name":"TitleName",
							"type":"text",
							"x":95,
							"y":3,
							"text":"Chat Slow",
							"text_horizontal_align":"center"
						},
					),
				},
				{
					"name":"ValText",
					"type":"text",
					"x":105,
					"y":30,
					"text":"",
					"text_horizontal_align":"center"
				},
				{
					"name" : "type_0",
					"type" : "toggle_button",

					"x" : 27,
					"y" : 80,

					"text" : "Sec",

					"default_image" : BUTTON_ROOT + "small_Button_01.sub",
					"over_image" : BUTTON_ROOT + "small_Button_02.sub",
					"down_image" : BUTTON_ROOT + "small_Button_03.sub",
				},
				{
					"name" : "type_1",
					"type" : "toggle_button",

					"x" : 77,
					"y" : 80,

					"text" : "Min",

					"default_image" : BUTTON_ROOT + "small_Button_01.sub",
					"over_image" : BUTTON_ROOT + "small_Button_02.sub",
					"down_image" : BUTTON_ROOT + "small_Button_03.sub",
				},
				{
					"name" : "type_2",
					"type" : "toggle_button",

					"x" : 127,
					"y" : 80,

					"text" : "Hour",

					"default_image" : BUTTON_ROOT + "small_Button_01.sub",
					"over_image" : BUTTON_ROOT + "small_Button_02.sub",
					"down_image" : BUTTON_ROOT + "small_Button_03.sub",
				},
				{
					"name" : "AcceptButton",
					"type" : "button",
					"x" : 35,
					"y" : 110,
					"text" : "",
					"default_image" : BUTTON_ROOT+"AcceptButton00.sub",
					"over_image" : BUTTON_ROOT+"AcceptButton01.sub",
					"down_image" : BUTTON_ROOT+"AcceptButton02.sub",
				},
				{
					"name" : "CancelButton",
					"type" : "button",
					"x" : 109,
					"y" : 110,
					"text" : "",
					"default_image" : BUTTON_ROOT+"CancleButton00.sub",
					"over_image" : BUTTON_ROOT+"CancleButton01.sub",
					"down_image" : BUTTON_ROOT+"CancleButton02.sub",
				},
				{
					"name" : "gaugeslow",
					"type" : "sliderbar",

					"x" : 15,
					"y" : 55,
				},
			),
		},
	),
}