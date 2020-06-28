#Add Last of Py
import app
if app.__BL_HIDE_EFFECT__:
	window["height"] += 25
	window["children"][0]["height"] += 25
	window["children"][0]["children"] += (
				{
				"name" : "BL_EFFECT_on_off",
				"type" : "text",

				"x" : LINE_LABEL_X,
				"y" : 240 + 25,

				"text" : "Effects",
				},
				{
					"name" : "BL_EFFECT_BuffEffect",
					"type" : "toggle_button",

					"x" : LINE_DATA_X,
					"y" : 240 + 25,

					"text" : "Buff",

					"default_image" : ROOT_PATH + "middle_button_01.sub",
					"over_image" : ROOT_PATH + "middle_button_02.sub",
					"down_image" : ROOT_PATH + "middle_button_03.sub",
				},
				{
					"name" : "BL_EFFECT_SkillEffect",
					"type" : "toggle_button",

					"x" : LINE_DATA_X+MIDDLE_BUTTON_WIDTH,
					"y" : 240 + 25,

					"text" : "Skill",

					"default_image" : ROOT_PATH + "middle_button_01.sub",
					"over_image" : ROOT_PATH + "middle_button_02.sub",
					"down_image" : ROOT_PATH + "middle_button_03.sub",
				},)