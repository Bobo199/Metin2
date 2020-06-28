#Find
					## Equipment Slot
#Add before					
					{
						"name" : "YenileButtonn",
						"type" : "image",
						"style" : ("attach",),

						"x" : 8,
						"y" : 7,

						"image" : "d:/ymir work/ui/pattern/titlebar_inv_refresh_baseframe.tga",

						"children" :
						(
							{
								"name" : "YenileButton",
								"type" : "button",

								"x" : 11,
								"y" : 3,

								"default_image" : "d:/ymir work/ui/refresh_small_button_01.sub",
								"over_image" : "d:/ymir work/ui/refresh_small_button_02.sub",
								"down_image" : "d:/ymir work/ui/refresh_small_button_03.sub",
								"disable_image" : "d:/ymir work/ui/refresh_small_button_04.sub",
							},
						),
					},
					
#Change Title (x, width)
					## Title
					{
						"name" : "TitleBar",
						"type" : "titlebar",
						"style" : ("attach",),

						"x" : 46,
						"y" : 7,

						"width" : 123,
						"color" : "yellow",

						"children" :
						(
							{ "name":"TitleName", "type":"text", "x":77, "y":3, "text":uiScriptLocale.INVENTORY_TITLE, "text_horizontal_align":"center" },
						),
					},