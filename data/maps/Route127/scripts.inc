Route127_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route127_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route127_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route127_OnFrame
	.byte 0

Route127_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_NORTH, AbnormalWeather_StartKyogreWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_SOUTH, AbnormalWeather_StartKyogreWeather
	end

Route127_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute127North
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute127South
	end

Route127_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route127_EventScript_WeathermanRain::
	lock
	faceplayer
	goto_if_eq VAR_WEATHERMAN_STATE, 1, Route127_EventScript_BattleWeatherman
	msgbox Route127_Text_ExResearcher, MSGBOX_DEFAULT
	setvar VAR_WEATHERMAN_STATE, 1
	release
	end

Route127_EventScript_BattleWeatherman::
	msgbox Route127_Text_ReadyToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route127_EventScript_WeathermanWait
	msgbox Route127_Text_HereWeCome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WEATHERMAN_RAIN, Route127_Text_ExperimentFailed
	msgbox Route127_Text_LetsTryFireNext, MSGBOX_DEFAULT
	closemessage
	fadescreenspeed FADE_TO_BLACK, 2
	setflag FLAG_HIDE_WEATHERMAN_RAIN
	clearflag FLAG_HIDE_WEATHERMAN_SUN
	removeobject LOCALID_ROUTE_127_WEATHERMAN
	delay 10
	fadescreen FADE_FROM_BLACK
	release
	end

Route127_EventScript_WeathermanWait::
	msgbox Route127_Text_TakeTimeToPrepare, MSGBOX_DEFAULT
	release
	end

Route127_EventScript_Camden::
	trainerbattle_single TRAINER_CAMDEN, Route127_Text_CamdenIntro, Route127_Text_CamdenDefeat
	msgbox Route127_Text_CamdenPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Donny::
	trainerbattle_single TRAINER_DONNY, Route127_Text_DonnyIntro, Route127_Text_DonnyDefeat
	msgbox Route127_Text_DonnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH, Route127_Text_JonahIntro, Route127_Text_JonahDefeat
	msgbox Route127_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Henry::
	trainerbattle_single TRAINER_HENRY, Route127_Text_HenryIntro, Route127_Text_HenryDefeat
	msgbox Route127_Text_HenryPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Roger::
	trainerbattle_single TRAINER_ROGER, Route127_Text_RogerIntro, Route127_Text_RogerDefeat
	msgbox Route127_Text_RogerPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Aidan::
	trainerbattle_single TRAINER_AIDAN, Route127_Text_AidanIntro, Route127_Text_AidanDefeat
	msgbox Route127_Text_AidanPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Athena::
	trainerbattle_single TRAINER_ATHENA, Route127_Text_AthenaIntro, Route127_Text_AthenaDefeat
	msgbox Route127_Text_AthenaPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Koji::
	trainerbattle_single TRAINER_KOJI_1, Route127_Text_KojiIntro, Route127_Text_KojiDefeat, Route127_EventScript_RegisterKoji
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route127_EventScript_RematchKoji
	msgbox Route127_Text_KojiPostBattle, MSGBOX_DEFAULT
	release
	end

Route127_EventScript_RegisterKoji::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route127_Text_KojiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KOJI_1
	release
	end

Route127_EventScript_RematchKoji::
	trainerbattle_rematch TRAINER_KOJI_1, Route127_Text_KojiRematchIntro, Route127_Text_KojiRematchDefeat
	msgbox Route127_Text_KojiPostRematch, MSGBOX_AUTOCLOSE
	end

Route127_Text_ExResearcher:
	.string "Hm?\p"
	.string "How'd you find me in a secluded\n"
	.string "place like this?\p"
	.string "Well, perhaps you can help me out\n"
	.string "since you're here.\p"
	.string "I'm an ex-researcher for the WEATHER\n"
	.string "INSTITUTE near FORTREE.\p"
	.string "At the WEATHER INSTITUTE, we were able\n"
	.string "to achieve something truly marvelous\l"
	.string "and create an entirely new POKéMON.\p"
	.string "I am now trying to draw out the true\n"
	.string "potential of this POKéMON, CASTFORM.\p"
	.string "Please, battle me!\p"
	.string "I want to expose CASTFORM to the\n"
	.string "very essence of WATER here in the\l"
	.string "middle of the ocean to draw out\l"
	.string "its true hidden powers!\p"
	.string "When you're ready, talk to me again.$"

Route127_Text_ReadyToBattle:
	.string "Ready to battle me and my CASTFORM?$"

Route127_Text_TakeTimeToPrepare:
	.string "No worries, take all the time you\n"
	.string "need to prepare.$"

Route127_Text_HereWeCome:
	.string "Alright then, here we come!$"

Route127_Text_ExperimentFailed:
	.string "Experiment failed…$"

Route127_Text_LetsTryFireNext:
	.string "Well that could have went better.\p"
	.string "I definitely feel like I wasn't able\n"
	.string "to draw out CASTFORM's power there…\p"
	.string "Well, onto the next location.\p"
	.string "Somewhere where I can maybe expose\n"
	.string "CASTFORM to the true essence of FIRE…\p"
	.string "So it would have to be somewhere\n"
	.string "that's really, really hot.\p"
	.string "Well, I'll think of something.\n"
	.string "If I see you again, then please battle\l"
	.string "me once more if you wouldn't mind.$"

