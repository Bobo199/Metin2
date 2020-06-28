#! /usr/bin/env python
'''
     ______               _          _____      _                _            
    |  ____|             | |        / ____|    | |              | |           
    | |____   _____ _ __ | |_ ___  | |     __ _| | ___ _ __   __| | __ _ _ __ 
    |  __\ \ / / _ | '_ \| __/ __| | |    / _` | |/ _ | '_ \ / _` |/ _` | '__|
    | |___\ V |  __| | | | |_\__ \ | |___| (_| | |  __| | | | (_| | (_| | |   
    |______\_/ \___|_| |_|\__|___/  \_____\__,_|_|\___|_| |_|\__,_|\__,_|_|   
                                                                                                                                    																									   
	MIT License
	Copyright (c) 2018 Vegas Projects << http://vegas-projects.com >>
	
	LINK PREVIEW : https://i.gyazo.com/526a56218a33e9a826fc2eae14e0e821.mp4

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
'''
__author__		= 'VegaS'
__date__		= '2018-02-04'
__software__	= 'PyCharm'
__license__		= 'MIT License - https://opensource.org/licenses/MIT'
__version__		= 'r0.1.2'

import ui
import localeInfo
import collections
import re

from uiToolTip import ToolTip
from uiGuild import MouseReflector
from datetime import date, datetime, timedelta
from operator import *

'''
	EVENTS_CALENDAR_DICT is just a configuration for <Python-Live-Test>.
	The struct of the dictionary need to get it like EVENTS_CALENDAR_DICT = calendar.GetEventsData() << Source Client.

	Parse the values from server to binary with Concrete Objects Layer example:
______________________________________________________________________________________________________
		PyObject * pDict = PyDict_New();
			- Return a new empty dictionary.
		
			PyDict_SetItemString(pDict, "key", Py_BuildValue("type_value", value));
				- Insert value into the dictionary p using key as a key. key should be a char. 
				- The key object is created using PyString_FromString(key). 
			
		PyObject * pList = PyList_New(max_length);
			- Return a new list of length len on success.
			
			PyList_SetItem(pList, index, value);
				- This is normally only used to fill in new lists where there is no previous content.
______________________________________________________________________________________________________

	You can insert how many events you want for each type of period [DAILY, WEEKLY, MONTHLY, ANNUALLY].
	The concept isn't 100% finished in r0.1.2, contact author for further informations.
'''

# calendar.GetEventsData() < Get from client-server.
# This dictionary is just a example for live-test.
EVENTS_CALENDAR_DICT = \
{
	### Flag Event << Using server event flags like: << [fishing_event, fotball_drop, drop_moon, choco_drop, herbs_drop, ...] >>
	'FLAG': \
	{
		'WEEKLY': [{'name': 'Moon Drop Event', 'start_time': '2:14:00', 'end_time': '4'}, ],
	},
	
	### Ox Event
	'OX': {},
	### Tournament Event
	'PVP': {},
	### Guild Event
	'GUILD': {},
	### Monarch Event
	'MONARCH': {},
	### Gold Event
	'GOLD_EVENT': {},
	### Empire War Event
	'EMPIRE_WAR': {},
};

MONTH_MAX_NUM           = 12
DAY_MAX_NUM             = 31
WEEK_MONTH_MAX_NUM      = 4
WEEK_DAY_MAX_NUM        = 7
DAYS_PER_YEAR_MAX_NUM   = 365

'''
	A smart class based by mathematical operations.
	Conventions add, sub, gt, mul are modules from library 'operator'.
	The operator module exports a set of efficient functions corresponding to the intrinsic operators of Python.
	For example, operator.add(x, y) is equivalent to the expression x+y.
'''
class Math(object):
	# Text attributes (name for days of week & number day).
	FONT_HEIGHT                 = 15
	LINE_HEIGHT                 = 35

	# Objects positions.
	BASE_START_X                = 294
	BASE_START_Y                = 62
	BASE_DISTANCE_X             = 46
	BASE_DISTANCE_Y             = 40

	# Sequences generators.
	SEQUENCE_MONTH_LIST			= range(1, MONTH_MAX_NUM + 1);
	SEQUENCE_WEEK_DAY_LIST		= range(WEEK_DAY_MAX_NUM);
	SEQUENCE_DAY_LIST			= range(1, DAY_MAX_NUM + 1);
	
	# Range days for all months.
	OFFSETS_MONTH_RANGE_TUPLE   = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
	
	# Range for week first, second, third, fourth + 1. 
	OFFSETS_WEEK_RANGE_TUPLE    = ([1, 8], [8, 15], [15, 22], [22, 29]);
	
	# Translations Week days & Months.
	NAMES_MONTH_TUPLE =  tuple(eval('localeInfo.CALENDAR_MONTH_{:d}'.format(item)) for item in SEQUENCE_MONTH_LIST);
	NAMES_WEEKDAY_TUPLE = tuple(eval('localeInfo.CALENDAR_EVENTS_WEEKDAY_{:d}'.format(item)) for item in SEQUENCE_WEEK_DAY_LIST);

	@staticmethod
	# MINMAX
	def MINMAX(min, value, max):
		tv = [value, min][min > value]
		return [tv, max][max < tv]

	@staticmethod
	# Generate a list as comprehension with a range for each week.
	def GetWeekRange():
		return [range(*seek) for seek in Math.OFFSETS_WEEK_RANGE_TUPLE]
		
	@staticmethod
	def GetLeapYear(year):
		"""
			03.27.2019:
				A normal year has 365 days. 
				A Leap Year has 366 days (the extra day is the 29th of February).
				yes	Leap Years are any year that can be exactly divided by 4 (such as 2012, 2016, etc)
				not	except if it can be exactly divided by 100, then it isn't (such as 2100, 2200, etc)
				yes	except if it can be exactly divided by 400, then it is (such as 2000, 2400)
				
				Provides support for maintaining a list in sorted order without having to sort the list after each insertion.
				Return True for leap years, False for non-leap years.
			
		"""
		return year % 4 == 0 and (year % 100 <> 0 or year % 400 == 0)

	@staticmethod
	# Get maximum number of days for the specified month.
	def GetRangeDaysMonth﻿(calendarMonth):
		""" TODO-DONE: Fix the calendar range days-month if month is February and is a bisection year like 2016, 2020, 2024 ... """
		return Math.OFFSETS_MONTH_RANGE_TUPLE[calendarMonth - 1] + (calendarMonth == 2 and Math.GetLeapYear(Math.GetCurrentYear()))
	
	@staticmethod
	# Get month name.
	def GetMonthName(calendarMonth):
		return Math.NAMES_MONTH_TUPLE[calendarMonth - 1]
	
	@staticmethod
	# Get tuple of week days.
	def GetWeekDayTupleNames():
		return Math.NAMES_WEEKDAY_TUPLE
		
	@staticmethod
	# Get current year.
	def GetCurrentYear():
		return datetime.now().year

	@staticmethod
	# Get all days of the week from first, second, third, fourth by a specific date of event.
	def GetUniqueWeekDay(calendarMonth, calendarDay, seek = 2, offsets = [0]):		
		round = list(reversed(range(seek)))[gt(calendarMonth, seek)]

		# Get a smart list with sum of each max-range of days from month << [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334] >>
		for attr in Math.OFFSETS_MONTH_RANGE_TUPLE[:MONTH_MAX_NUM - 1]:
			offsets.append(offsets[-1] + attr)	
		offsets.append(Math.GetCurrentYear() - 318)
		
		# Todo-Done: Fix days per year if is a leap year 366, if not 365.
		daysPerYear = DAYS_PER_YEAR_MAX_NUM
		if Math.GetLeapYear(Math.GetCurrentYear()):
			daysPerYear = DAYS_PER_YEAR_MAX_NUM + 1 

		result_day_of_week = add(WEEK_MONTH_MAX_NUM, 1)
		result_day_of_week += mul(add(Math.GetCurrentYear() - offsets[-1] - round, round), daysPerYear)
		result_day_of_week += add(offsets[calendarMonth - 1], calendarDay)
		return result_day_of_week % WEEK_DAY_MAX_NUM

	@staticmethod
	# Get duration of event, start_time & end_time.
	def GetDurationTime(start_time, end_time, format_time = '%H:%M'):
		result_start_time = '{:02d}:{:02d}'.format(*start_time)
		result_end_time = add(datetime.strptime(result_start_time, format_time), timedelta(hours = end_time)).strftime(format_time)
		return result_start_time, result_end_time
		
	@staticmethod
	# Sort position by weekDay 1-28 (4 weeks), for rest of days (29-30-31) do a arithmetic position.
	def GetPositions(calendarDay, calendarMonth, result_week_pos = None):
		for calendarWeekNum, calendarWeekRange in enumerate(Math.GetWeekRange()):
			if calendarDay in calendarWeekRange:
				result_week_pos = add(mul(sub(calendarDay, calendarWeekRange[-1]), Math.BASE_DISTANCE_X), Math.BASE_START_X), add(Math.BASE_START_Y, mul(Math.BASE_DISTANCE_Y, calendarWeekNum))

		result_arithmetic_pos = (result_week_pos, (add(mul(sub(calendarDay, Math.GetRangeDaysMonth(calendarMonth)), Math.BASE_DISTANCE_X), Math.BASE_START_X), add(Math.BASE_START_Y, mul(Math.BASE_DISTANCE_Y, WEEK_MONTH_MAX_NUM))))
		return result_arithmetic_pos[not result_week_pos]

class EventsCalendarWindow(ui.ScriptWindow):
	# Page state
	PAGE_STATE_PREVIOUS			= 0
	PAGE_STATE_NEXT				= 1

	# Open calendar with month 1 = January.
	BASE_DEFAULT_MONTH			= 3 				# << 1 - 12 >>
	
	# Set color for days of the week. 
	WEEK_NAME_COLOR				= (242, 231, 193) 	# << R, G, B >>
	
	# Set the characters limit. 
	WEEK_NAME_LENGTH			= 2					# << 'Su, Mo, Tu' >>
	
	# Do events just for day 1 - 28. 
	DAY_INSERT_MAX_NUM			= 28				# << Configured from server >>

	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.selectedMonth		= 1
		self.cacheSelectedMonth = 1
		self.eventManagerDict 	= {item: list() for item in Math.SEQUENCE_MONTH_LIST}
		self.eventWeekNamesList = []
		self.__LoadWindow()

	def __del__(self):
		ui.ScriptWindow.__del__(self)
		
	def Destroy(self):
		self.ClearDictionary()

	def __LoadWindow(self):
		try:
			ui.PythonScriptLoader().LoadScriptFile(self, 'UIScript/EventsCalendarWindow.py')
		except:
			import exception
			exception.Abort('EventsCalendarWindow.LoadWindow.LoadScript')

		try:
			self.board = self.GetChild('board')
			self.GetChild('prev_button').SAFE_SetEvent(self.CalendarSelectMonth, self.PAGE_STATE_PREVIOUS)
			self.GetChild('next_button').SAFE_SetEvent(self.CalendarSelectMonth, self.PAGE_STATE_NEXT)
		except:
			import exception
			exception.Abort('EventsCalendarWindow.LoadWindow.BindObject')

		self.CalendarSetObjects()
		self.CalendarGetParser()
		self.CalendarLoad(self.BASE_DEFAULT_MONTH)
		self.Show()

	def CalendarSetObjects(self):
		for calendarWeekDayIndex, calendarWeekDayName in enumerate(Math.GetWeekDayTupleNames()):
			self.eventWeekNamesList.append(ui.CalendarMakeBigTextBar(self.board, 30 + (Math.BASE_DISTANCE_X * calendarWeekDayIndex), Math.BASE_START_Y - 20, \
												Math.LINE_HEIGHT, Math.FONT_HEIGHT, calendarWeekDayName[:self.WEEK_NAME_LENGTH], self.WEEK_NAME_COLOR))

		for calendarMonth in Math.SEQUENCE_MONTH_LIST:
			for calendarDay in Math.SEQUENCE_DAY_LIST[:Math.GetRangeDaysMonth(calendarMonth)]: # Insert the day-range object by a specific month.
				self.eventManagerDict.get(calendarMonth, list()).append(EventsCalendarObject(self.board, calendarMonth, calendarDay, *Math.GetPositions(calendarDay, calendarMonth)))

	def CalendarGetParser(self):
		for eventType, baseDict in EVENTS_CALENDAR_DICT.iteritems():
			for eventPeriod, baseData in baseDict.iteritems():
				for eventData in baseData:

					# TODO DONE: Convert start_time < split string list to int.
					eventName, eventResult = eventData.get('name'), list(map(int, eventData.get('start_time').split(':')))
					if not len(eventResult):
						continue

					eventStartime, eventEndTime = Math.GetDurationTime((eventResult[-2], eventResult[-1]), int(eventData.get('end_time')))
					
					# TODO DONE: Insert the event for all days in each month. | 21:50
					# << 336-372 (1 * 31 * 12)
					if eventPeriod == 'DAILY':
						for calendarMonth in Math.SEQUENCE_MONTH_LIST:
							for calendarDay, calendarObject in enumerate(self.eventManagerDict[calendarMonth][:self.DAY_INSERT_MAX_NUM]):
								calendarObject.InsertEvent(eventPeriod, eventType, eventName, eventStartime, eventEndTime, calendarMonth, calendarDay)

					# TODO DONE: Insert the event by a specific day of week for each month. | 1:15:00
					# << (1 * 4 * 12)
					elif eventPeriod == 'WEEKLY':
						for calendarMonth in Math.SEQUENCE_MONTH_LIST:
							for calendarDay, calendarObject in enumerate(self.eventManagerDict[calendarMonth][:self.DAY_INSERT_MAX_NUM]):
								if Math.GetUniqueWeekDay(calendarMonth, calendarDay) == eventResult[-3]:
									calendarObject.InsertEvent(eventPeriod, eventType, eventName, eventStartime, eventEndTime, calendarMonth, calendarDay)

					# TODO DONE: Insert the event by a specific day of month. | 1:5:16:00
					elif eventPeriod == 'MONTHLY':
						for calendarMonth in Math.SEQUENCE_MONTH_LIST:
							if calendarMonth == eventResult[-4]:
								for calendarDay, calendarObject in enumerate(self.eventManagerDict[calendarMonth][:self.DAY_INSERT_MAX_NUM]):
									 if calendarDay + 1 == eventResult[-3]:
										calendarObject.InsertEvent(eventPeriod, eventType, eventName, eventStartime, eventEndTime, calendarMonth, calendarDay)

					# TODO DONE: Insert the event by a specific month, week from month and day from week.  | 3:4:5:13:00
					elif eventPeriod == 'ANNUALLY':
						for calendarMonth in Math.SEQUENCE_MONTH_LIST:
								if calendarMonth == eventResult[-5]:
									for calendarWeekNum in xrange(1, WEEK_MONTH_MAX_NUM + 1):
										if calendarWeekNum == eventResult[-4]:
											for calendarDay in Math.GetWeekRange()[calendarWeekNum - 1]:
												if Math.GetUniqueWeekDay(calendarMonth, calendarDay) == eventResult[-3]:
													self.eventManagerDict[calendarMonth][calendarDay].InsertEvent(eventPeriod, eventType, eventName, eventStartime, eventEndTime, calendarMonth, calendarDay)
		
	def CalendarSelectMonth(self, selected, offset = 1):
		# Conventions of select month page:
			# Operator << : January => ++December
			# Operator >> : December => ++January

		toggleStateDict =\
		{
			self.PAGE_STATE_PREVIOUS: (lambda: sub(self.selectedMonth, offset), lambda: MONTH_MAX_NUM)[self.selectedMonth is offset],
			self.PAGE_STATE_NEXT: (lambda: add(self.selectedMonth, offset), lambda: offset)[self.selectedMonth is MONTH_MAX_NUM]
		}

		self.cacheSelectedMonth = self.selectedMonth
		self.selectedMonth = Math.MINMAX(1, toggleStateDict[selected](), MONTH_MAX_NUM)
		self.CalendarLoad(self.selectedMonth)

	def CalendarLoad(self, calendarMonth):
		# Set the title name as month, year.
		self.board.SetTitleName('{:s} {:s}'.format(Math.GetMonthName(calendarMonth), Math.GetCurrentYear()))

		 # Hide previous month.
		map(EventsCalendarObject.Hide, self.eventManagerDict.get(self.cacheSelectedMonth))
		
		# Load month events.
		map(EventsCalendarObject.Show, self.eventManagerDict.get(calendarMonth)) 

class EventsCalendarObject(ui.ImageBox):
	BASE_ROOT_PATH		= 'd:/ymir work/ui/game/calendar/{:s}.tga'
	BASE_ADD_SPACE_Y 	= 32

	def __init__(self, parent, calendarMonth, calendarDay, x, y, fileName = "d:/ymir work/ui/public/Parameter_Slot_00.sub"):
		ui.ImageBox.__init__(self)
		self.childrenList = []
		self.eventList = []
		self.calendarMonth = calendarMonth
		self.calendarDay = calendarDay

		self.SetParent(parent)
		self.SetPosition(x, y)
		self.LoadImage(fileName)

		self.InitializeSlotEventLocked()
		self.SetNumberLine()
		self.SetToolTipEvent()

		self.mouseReflector = MouseReflector(self)
		self.mouseReflector.SetSize(self.GetWidth(), self.GetHeight())
		self.mouseReflector.UpdateRect()
		self.Hide()

	def __del__(self):
		ui.ImageBox.__del__(self)
		
	def Destroy(self):
		self.Hide()

	# Get month number as integer.
	def GetMonthEvent(self):
		return self.calendarMonth

	# Get day number as string.
	def GetDayEvent(self):
		return self.calendarDay.__str__()

	# Show the tooltip just if there exist a event inserted.
	def GetToolTipEvent(self):
		return self.eventList

	# When each object is initialized <before parsing the data's from dictionary> attach a unknown event for each day of months with a slotbar red and block it.
	def InitializeSlotEventLocked(self):
		self.slotEventLocked = ui.CalendarMakeBar(self, 2, 2, self.GetWidth() - 4, self.GetHeight() - 4, 0xFF690610)

	# Hide the slot bar red after was inserted the first event.
	def SetUsableSlotEvent(self):
		if self.slotEventLocked.IsShow():
			self.slotEventLocked.Hide()

	# Set tooltip and attach the title as month & day selected.
	def SetToolTipEvent(self):
		eventToolTip = ToolTip()
		eventToolTip.ClearToolTip()
		eventToolTip.AlignHorizonalCenter()
		eventToolTip.AppendTextLine(localeInfo.CALENDAR_EVENTS_TOOLTIP_TITLE, eventToolTip.CAN_LEVEL_UP_COLOR)
		eventToolTip.AppendTextLine('{:s} {:s}'.format(self.GetDayEvent(), Math.GetMonthName(self.GetMonthEvent())))
		eventToolTip.AppendSpace(10)
		eventToolTip.HideToolTip()
		self.eventToolTip = eventToolTip

	# Set number of day 1-31 for each slot bar.
	def SetNumberLine(self):
		self.childrenList.append(ui.CalendarMakeBigTextBar(self, 5, 1, Math.LINE_HEIGHT, Math.FONT_HEIGHT, self.GetDayEvent()))

	# Set title board as current month selected and current year.
	def SetTitleNameEvent(self, eventName):
		self.childrenList.append(ui.CalendarMakeTextLine(self.eventToolTip, 45, self.eventToolTip.toolTipHeight, eventName, self.eventToolTip.HIGH_PRICE_COLOR))

	# Set information about start and end time of event.
	def SetDurationTimeEvent(self, eventStartime, eventEndTime):
		self.childrenList.append(ui.CalendarMakeTextLine(self.eventToolTip, 45, self.eventToolTip.toolTipHeight + (self.BASE_ADD_SPACE_Y / 2), '{:s} - {:s}'.format(eventStartime, eventEndTime)))

	# Set a specific icon/image for each type of event. (7 as default)
	def SetIconEvent(self, eventType):
		self.childrenList.append(ui.MakeImageBox(self.eventToolTip, self.BASE_ROOT_PATH.format(eventType.lower()), 5, self.eventToolTip.toolTipHeight))

	# Recalculated the tooltip window size after inserted the elements in childrenList.
	def SetSizeToolTipEvent(self):
		self.eventToolTip.toolTipHeight += self.BASE_ADD_SPACE_Y
		self.eventToolTip.ResizeToolTip()

	# Is called when parser running.
	# Send a list arguments for each event by a specific month & day.
	def InsertEvent(self, *eventArgs):
		(eventPeriod, eventType, eventName, eventStartime, eventEndTime, calendarMonth, calendarDay) = eventArgs[:]
		self.eventList.append(eventType)

		self.SetTitleNameEvent(eventName)
		self.SetDurationTimeEvent(eventStartime, eventEndTime)
		self.SetIconEvent(eventType)
		self.SetSizeToolTipEvent()
		self.SetUsableSlotEvent()

	def OnMouseOverIn(self):
		if self.GetToolTipEvent():
			self.eventToolTip.AlignHorizonalCenter()
			self.eventToolTip.ShowToolTip()
			self.mouseReflector.Show()

	def OnMouseOverOut(self):
		if self.GetToolTipEvent():
			self.eventToolTip.HideToolTip()
			self.mouseReflector.Hide()