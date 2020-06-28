import uiScriptLocale
WINDOW_WIDTH = 350
WINDOW_HEIGHT = 240
BLCOLOR = "|cff00ccff"
window = {
	"name" : "BankWindow",
	"style" : ("movable", "float",),

	"x" : SCREEN_WIDTH / 2 - WINDOW_WIDTH / 2,
	"y" : SCREEN_HEIGHT / 2 - WINDOW_HEIGHT / 2,

	"width" : WINDOW_WIDTH,
	"height" : WINDOW_HEIGHT,

	"children" :
	(
		{
			"name" : "board",
			"type" : "board",

			"x" : 0,
			"y" : 0,

            "horizontal_align" : "center",
            "vertical_align" : "center",

			"width" : WINDOW_WIDTH,
			"height" : WINDOW_HEIGHT,

			"children" :
			(
				## Title
				{
					"name" : "TitleBar",
					"type" : "titlebar",
					"style" : ("attach",),

					"x" : 6,
					"y" : 6,

					"width" : 340,
					"color" : "yellow",

					"children" :
					(
						{
							"name" : "TitleName",
							"type" : "text",

							"x" : 0,
							"y" : 3,

							"horizontal_align" : "center",

							"text" : uiScriptLocale.BANK,

							"text_horizontal_align" : "center",
						},
					),
				},
				{
					"name" : "EpSlot",
					"type" : "button",

					"x" : -75,
					"y" : 150,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"over_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"down_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",

					"children" :
					(
						{
							"name" : "EpText",
							"type" : "text",

							"x" : 0,
							"y" : -15,

							"horizontal_align" : "center",

							"text" : uiScriptLocale.BANK_CURRENT_COINS,

							"text_horizontal_align" : "center",
						},
						{
							"name" : "Epp",
							"type" : "text",

							"x" : 0,
							"y" : 3,

							"horizontal_align" : "center",

							"text_horizontal_align" : "center",
						},
					),
				},
				{
					"name" : "YangSlot",
					"type" : "button",

					"x" : -75,
					"y" : 50,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"over_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"down_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",

					"children" :
					(
						{
							"name" : "YangText",
							"type" : "text",

							"x" : 0,
							"y" : -15,

							"horizontal_align" : "center",

							"text" : uiScriptLocale.BANK_CURRENT_YANG,

							"text_horizontal_align" : "center",
						},
						{
							"name" : "Yang",
							"type" : "text",

							"x" : 0,
							"y" : 3,

							"horizontal_align" : "center",


							"text_horizontal_align" : "center",
						},
					),
				},
				{
					"name" : "YangBankSlot",
					"type" : "button",

					"x" : 75,
					"y" : 50,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"over_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"down_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",

					"children" :
					(
						{
							"name" : "YangBankText",
							"type" : "text",

							"x" : 0,
							"y" : -15,

							"horizontal_align" : "center",

							"text" : uiScriptLocale.BANK_BANK_YANG,

							"text_horizontal_align" : "center",
						},
						{
							"name" : "YangBank",
							"type" : "text",

							"x" : 0,
							"y" : 3,

							"horizontal_align" : "center",
							"text_horizontal_align" : "center",
						},
					),
				},
				{
					"name" : "WonSlot",
					"type" : "button",

					"x" : -75,
					"y" : 100,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"over_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"down_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",

					"children" :
					(
						{
							"name" : "WonText",
							"type" : "text",

							"x" : 0,
							"y" : -15,

							"horizontal_align" : "center",

							"text" : uiScriptLocale.BANK_CURRENT_WON,

							"text_horizontal_align" : "center",
						},
						{
							"name" : "Wonn",
							"type" : "text",

							"x" : 0,
							"y" : 3,

							"horizontal_align" : "center",
							"text_horizontal_align" : "center",
						},
					),
				},
				{
					"name" : "EpSlot",
					"type" : "button",

					"x" : 75,
					"y" : 150,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"over_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"down_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",

					"children" :
					(
						{
							"name" : "EpText",
							"type" : "text",

							"x" : 0,
							"y" : -15,

							"horizontal_align" : "center",

							"text" : uiScriptLocale.BANK_BANK_COIN,

							"text_horizontal_align" : "center",
						},
						{
							"name" : "EpBank",
							"type" : "text",

							"x" : 0,
							"y" : 3,

							"horizontal_align" : "center",
							"text_horizontal_align" : "center",
						},
					),
				},
				{
					"name" : "WonSlottt",
					"type" : "button",

					"x" : 75,
					"y" : 100,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"over_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"down_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",

					"children" :
					(
						{
							"name" : "WonnTsext",
							"type" : "text",

							"x" : 0,
							"y" : -15,

							"horizontal_align" : "center",
							"text" : uiScriptLocale.BANK_BANK_WON,
							"text_horizontal_align" : "center",
						},
						{
							"name" : "Wonbannk",
							"type" : "text",

							"x" : 0,
							"y" : 3,
							"horizontal_align" : "center",
							"text_horizontal_align" : "center",
						},
					),
				},
				{
					"name" : "Yattir",
					"type" : "button",

					"x" : -95,
					"y" : 180,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/large_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/large_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/large_button_03.sub",

					"text" : BLCOLOR + " " + uiScriptLocale.BANK_ADD,
				},
				{
					"name" : "Cehh",
					"type" : "button",

					"x" : 95,
					"y" : 180,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/large_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/large_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/large_button_03.sub",

					"text" : BLCOLOR + " " + uiScriptLocale.BANK_WITHDRAW,
				},
				{
					"name" : "Gonder",
					"type" : "button",

					"x" : 0,
					"y" : 180,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/large_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/large_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/large_button_03.sub",

					"text" : BLCOLOR + " " + uiScriptLocale.BANK_SEND,
				},
				{
					"name" : "Gapat",
					"type" : "button",

					"x" : 50,
					"y" : 205,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/large_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/large_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/large_button_03.sub",

					"text" : BLCOLOR + " " + uiScriptLocale.BANK_CLOSE,
				},
				{
					"name" : "ChangePassword",
					"type" : "button",

					"x" : -50,
					"y" : 205,

					"horizontal_align" : "center",

					"default_image" : "d:/ymir work/ui/public/large_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/large_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/large_button_03.sub",

					"text" : BLCOLOR + " " + uiScriptLocale.BANK_PASS,
				},
			),
		},
	),
}