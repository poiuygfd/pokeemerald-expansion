EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call Common_EventScript_SetupRivalGfxId
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

EverGrandeCity_EventScript_RivalBattle::
	lock
	msgbox EverGrandeCity_Text_WaitUpPlayer, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_EventScript_RivalMay
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_EventScript_RivalBrendan
	end

EverGrandeCity_EventScript_RivalMay::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	addobject LOCALID_EVER_GRANDE_RIVAL
	applymovement LOCALID_EVER_GRANDE_RIVAL, EverGrandeCity_Movement_RivalApproachPlayer
	waitmovement 0
	msgbox EverGrandeCity_Text_MayWorkedHard, MSGBOX_DEFAULT
	case 0, EverGrandeCity_EventScript_StartMayBattleTreecko
	case 1, EverGrandeCity_EventScript_StartMayBattleTorchic
	case 2, EverGrandeCity_EventScript_StartMayBattleMudkip
	end

EverGrandeCity_EventScript_RivalBrendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	addobject LOCALID_EVER_GRANDE_RIVAL
	applymovement LOCALID_EVER_GRANDE_RIVAL, EverGrandeCity_Movement_RivalApproachPlayer
	waitmovement 0
	msgbox EverGrandeCity_Text_BrendanWorkedHard, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, EverGrandeCity_EventScript_StartBrendanBattleTreecko
	case 1, EverGrandeCity_EventScript_StartBrendanBattleTorchic
	case 2, EverGrandeCity_EventScript_StartBrendanBattleMudkip
	end

EverGrandeCity_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_EVER_GRANDE_TREECKO, EverGrandeCity_Text_MayDefeated
	goto EverGrandeCity_EventScript_AfterMayBattle
	end

EverGrandeCity_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_EVER_GRANDE_TORCHIC, EverGrandeCity_Text_MayDefeated
	goto EverGrandeCity_EventScript_AfterMayBattle
	end

EverGrandeCity_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_EVER_GRANDE_MUDKIP, EverGrandeCity_Text_MayDefeated
	goto EverGrandeCity_EventScript_AfterMayBattle
	end

EverGrandeCity_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_EVER_GRANDE_TREECKO, EverGrandeCity_Text_BrendanDefeated
	goto EverGrandeCity_EventScript_AfterBrendanBattle
	end

EverGrandeCity_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_EVER_GRANDE_TORCHIC, EverGrandeCity_Text_BrendanDefeated
	goto EverGrandeCity_EventScript_AfterBrendanBattle
	end

EverGrandeCity_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_EVER_GRANDE_MUDKIP, EverGrandeCity_Text_BrendanDefeated
	goto EverGrandeCity_EventScript_AfterBrendanBattle
	end

EverGrandeCity_EventScript_AfterMayBattle::
	msgbox EverGrandeCity_Text_MayGoodLuckWithLeague, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EVER_GRANDE_RIVAL, EverGrandeCity_Movement_RivalLeaves
	waitmovement 0
	goto EverGrandeCity_EventScript_RivalLeave
	end

EverGrandeCity_EventScript_AfterBrendanBattle::
	msgbox EverGrandeCity_Text_BrendanGoodLuckWithLeague, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EVER_GRANDE_RIVAL, EverGrandeCity_Movement_RivalLeaves
	waitmovement 0
	goto EverGrandeCity_EventScript_RivalLeave
	end

EverGrandeCity_EventScript_RivalLeave::
	removeobject LOCALID_EVER_GRANDE_RIVAL
	setvar VAR_EVER_GRANDE_CITY_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

EverGrandeCity_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	step_end

EverGrandeCity_Movement_RivalLeaves:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

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
	delay 20
	applymovement LOCALID_EVER_GRANDE_CITY_WOLFE_BODYGUARD, EverGrandeCity_Movement_BodyguardSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_EVER_GRANDE_CITY_WOLFE_BODYGUARD, EverGrandeCity_Movement_BodyguardExit
	waitmovement 0
	removeobject LOCALID_EVER_GRANDE_CITY_WOLFE_BODYGUARD
	end

EverGrandeCity_Movement_BodyguardSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

EverGrandeCity_Movement_BodyguardExit:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
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

EverGrandeCity_Text_WaitUpPlayer:
	.string "Wait up, {PLAYER}!$"

EverGrandeCity_Text_MayWorkedHard:
	.string "MAY: I'm glad I was able to catch up\n"
	.string "to you before you set off!\p"
	.string "To think you've finally made it to\n"
	.string "the POKéMON LEAGUE…\p"
	.string "All that stands between you and the\n"
	.string "ELITE FOUR is VICTORY ROAD.\p"
	.string "VICTORY ROAD is no joke though.\n"
	.string "We should make sure you're ready!\p"
	.string "I'm not holding anything back!$"

EverGrandeCity_Text_MayDefeated:
	.string "Deep down, I think I knew you would\n"
	.string "win, {PLAYER}{KUN}.$"

EverGrandeCity_Text_MayGoodLuckWithLeague:
	.string "MAY: You truly are amazing, {PLAYER}{KUN}!\p"
	.string "The experience you have gained during\n"
	.string "your long journey really shows!\l"
	.string "Your strength is truly impressive!\p"
	.string "At this point, I doubt even the LEAGUE\n"
	.string "stands a chance against you!\p"
	.string "I'm rooting for you!\n"
	.string "I wish you the best of luck!$"

EverGrandeCity_Text_BrendanWorkedHard:
	.string "BRENDAN: Phew, I'm glad I managed to\n"
	.string "catch you before you went in.\p"
	.string "You've finally made it to the POKéMON\n"
	.string "LEAGUE, then.\p"
	.string "The only thing standing between you\n"
	.string "and the LEAGUE is VICTORY ROAD.\p"
	.string "Before you embark though, let's make\n"
	.string "sure you're truly ready!\p"
	.string "I'm giving this all I've got!$"

EverGrandeCity_Text_BrendanDefeated:
	.string "Somehow I had a feeling this would\n"
	.string "happen, {PLAYER}.$"

EverGrandeCity_Text_BrendanGoodLuckWithLeague:
	.string "BRENDAN: Honestly, I'm not even\n"
	.string "upset anymore.\p"
	.string "After everything you've done and\n"
	.string "been through on your journey,\l"
	.string "it makes sense you're so strong.\p"
	.string "Even the POKéMON LEAGUE should be\n"
	.string "no trouble at all for you!\p"
	.string "I'll be rooting for you, so give it\n"
	.string "everything you've got!$"

EverGrandeCity_Text_YouAreNotReady:
	.string "You are not ready.$"

EverGrandeCity_Text_YouAreReady:
	.string "You are ready.$"

