EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_EventScript_WolfesBodyguard::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_EventScript_YouAreReady
	msgbox EverGrandeCity_Text_YouAreNotReady, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_EventScript_YouAreReady::
	msgbox EverGrandeCity_Text_YouAreReady, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	applymovement LOCALID_EVER_GRANDE_CITY_WOLFE_BODYGUARD, EverGrandeCity_Movement_BodyguardExit
	waitmovement 0
	removeobject LOCALID_EVER_GRANDE_CITY_WOLFE_BODYGUARD
	end

EverGrandeCity_Movement_BodyguardExit:
	slide_up
	slide_up
	step_end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

EverGrandeCity_Text_YouAreNotReady:
	.string "You are not ready.$"

EverGrandeCity_Text_YouAreReady:
	.string "You are ready.$"

