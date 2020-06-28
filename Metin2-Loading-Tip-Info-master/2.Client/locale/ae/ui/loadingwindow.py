#Add Last
import app
if app.__LOADING_TIP__:
	window["children"] = window["children"] + (
	{
		"name" : "TipBackground",
		"type" : "thinboard",
		
		"x"	: 0,
		"y" : float(SCREEN_HEIGHT) * 500 / 600.0 - 100,
		
		"width" : SCREEN_WIDTH,
		"height" : 100,
		
		"children" :
		(
			{
				"name" : "LoadingTip",
				"type" : "text",
				
				"x"	: float(SCREEN_WIDTH) / 2,
				"y" : 40,				
				
				"text" : " ",
				"text_horizontal_align" : "center",
				"fontsize" : "LARGE",
			},
		),		
	},)