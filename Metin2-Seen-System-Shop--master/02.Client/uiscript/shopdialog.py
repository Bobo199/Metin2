#Find
				{
					"name" : "CloseButton",
					"type" : "button",

					"x" : -110,
					"y" : 295,

					"horizontal_align" : "center",

					"text" : uiScriptLocale.PRIVATE_SHOP_CLOSE_BUTTON,

					"default_image" : "d:/ymir work/ui/public/large_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/large_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/large_button_03.sub",
				},
				
#Add
				###############
				{
					"name" : "Seen",
					"type" : "slotbar",

					"x" : 0,
					"y" : 295,
					"width" : 30,
					"height" : 18,
					"horizontal_align" : "center",

					"children" :
					(
						{
							"name" : "SeenText",
							"type" : "text",

							"x" : 3,
							"y" : 3,

							"width" : 30,
							"height" : 18,
						},
					),
				},
				###############