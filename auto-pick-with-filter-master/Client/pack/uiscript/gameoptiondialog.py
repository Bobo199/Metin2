# You probably have things added, just change "height" to fit the image, in my case is:

window = {
	"name" : "GameOptionDialog",
	"style" : ["movable", "float",],

	"x" : 0,
	"y" : 0,

	"width" : 300,
	"height" : 25*11+8+105, # Change for you.
  
	"children" :
	[
		{
			"name" : "board",
			"type" : "board",

			"x" : 0,
			"y" : 0,

			"width" : 300,
			"height" : 25*11+8+105,  # Change for you.

# Search

				{
					"name" : "salestext_off_button",
					"type" : "radio_button",

					"x" : LINE_DATA_X+MIDDLE_BUTTON_WIDTH,
					"y" : 240,

					"text" : uiScriptLocale.OPTION_SALESTEXT_VIEW_OFF,

					"default_image" : ROOT_PATH + "middle_button_01.sub",
					"over_image" : ROOT_PATH + "middle_button_02.sub",
					"down_image" : ROOT_PATH + "middle_button_03.sub",
				},
        
        
# Add after

				#PickUpFilter
					{
						"name" : "PickUpFilter",
						"type" : "text",
						
						"multi_line" : 1,
						
						"x" : LINE_LABEL_X,
						"y" : 300+2,

						"text" : "Recoger Filt.",
					},
					{
						"name" : "Pick_Up_FilterWeapon",
						"type" : "toggle_button",

						"x" : LINE_DATA_X,
						"y" : 300,

						"text" : "Armas",

						"default_image" : ROOT_PATH + "middle_button_01.sub",
						"over_image" : ROOT_PATH + "middle_button_02.sub",
						"down_image" : ROOT_PATH + "middle_button_03.sub",
					},
					{
						"name" : "Pick_Up_FilterArmor",
						"type" : "toggle_button",

						"x" : LINE_DATA_X+MIDDLE_BUTTON_WIDTH,
						"y" : 300,

						"text" : "Armaduras",

						"default_image" : ROOT_PATH + "middle_button_01.sub",
						"over_image" : ROOT_PATH + "middle_button_02.sub",
						"down_image" : ROOT_PATH + "middle_button_03.sub",
					},
					{
						"name" : "Pick_Up_FilterEar",
						"type" : "toggle_button",

						"x" : LINE_DATA_X+MIDDLE_BUTTON_WIDTH*2,
						"y" : 300,

						"text" : "Pendientes",

						"default_image" : ROOT_PATH + "middle_button_01.sub",
						"over_image" : ROOT_PATH + "middle_button_02.sub",
						"down_image" : ROOT_PATH + "middle_button_03.sub",
					},
					{
						"name" : "Pick_Up_FilterNeck",
						"type" : "toggle_button",

						"x" : LINE_DATA_X,
						"y" : 325,

						"text" : "Cuello",

						"default_image" : ROOT_PATH + "middle_button_01.sub",
						"over_image" : ROOT_PATH + "middle_button_02.sub",
						"down_image" : ROOT_PATH + "middle_button_03.sub",
					},
					{
						"name" : "Pick_Up_FilterFoots",
						"type" : "toggle_button",

						"x" : LINE_DATA_X+MIDDLE_BUTTON_WIDTH,
						"y" : 325,

						"text" : "Zapatos",

						"default_image" : ROOT_PATH + "middle_button_01.sub",
						"over_image" : ROOT_PATH + "middle_button_02.sub",
						"down_image" : ROOT_PATH + "middle_button_03.sub",
					},
					{
						"name" : "Pick_Up_FilterShield",
						"type" : "toggle_button",

						"x" : LINE_DATA_X+MIDDLE_BUTTON_WIDTH*2,
						"y" : 325,

						"text" : "Escudo",

						"default_image" : ROOT_PATH + "middle_button_01.sub",
						"over_image" : ROOT_PATH + "middle_button_02.sub",
						"down_image" : ROOT_PATH + "middle_button_03.sub",
					},
					{
						"name" : "Pick_Up_FilterBook",
						"type" : "toggle_button",

						"x" : LINE_DATA_X,
						"y" : 350,

						"text" : "Libros",

						"default_image" : ROOT_PATH + "middle_button_01.sub",
						"over_image" : ROOT_PATH + "middle_button_02.sub",
						"down_image" : ROOT_PATH + "middle_button_03.sub",
					},
					{
						"name" : "Pick_Up_FilterStone",
						"type" : "toggle_button",

						"x" : LINE_DATA_X+MIDDLE_BUTTON_WIDTH,
						"y" : 350,

						"text" : "Piedras",

						"default_image" : ROOT_PATH + "middle_button_01.sub",
						"over_image" : ROOT_PATH + "middle_button_02.sub",
						"down_image" : ROOT_PATH + "middle_button_03.sub",
					},
					{
						"name" : "Pick_Up_FilterEtc",
						"type" : "toggle_button",

						"x" : LINE_DATA_X+MIDDLE_BUTTON_WIDTH*2,
						"y" : 350,

						"text" : "ETC",

						"default_image" : ROOT_PATH + "middle_button_01.sub",
						"over_image" : ROOT_PATH + "middle_button_02.sub",
						"down_image" : ROOT_PATH + "middle_button_03.sub",
					},
          
