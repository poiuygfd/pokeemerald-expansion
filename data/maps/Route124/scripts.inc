Route124_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
	.byte 0

Route124_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

Route124_EventScript_HuntersHouseSign::
	msgbox Route124_Text_HuntersHouse, MSGBOX_SIGN
	end

Route124_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER, Route124_Text_SpencerIntro, Route124_Text_SpencerDefeat
	msgbox Route124_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roland::
	trainerbattle_single TRAINER_ROLAND, Route124_Text_RolandIntro, Route124_Text_RolandDefeat
	msgbox Route124_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Jenny::
	trainerbattle_single TRAINER_JENNY_1, Route124_Text_JennyIntro, Route124_Text_JennyDefeat, Route124_EventScript_RegisterJenny
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchJenny
	msgbox Route124_Text_JennyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterJenny::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route124_Text_JennyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JENNY_1
	release
	end

Route124_EventScript_RematchJenny::
	trainerbattle_rematch TRAINER_JENNY_1, Route124_Text_JennyRematchIntro, Route124_Text_JennyRematchDefeat
	msgbox Route124_Text_JennyPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE, Route124_Text_GraceIntro, Route124_Text_GraceDefeat
	msgbox Route124_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD, Route124_Text_ChadIntro, Route124_Text_ChadDefeat
	msgbox Route124_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Lila::
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaIntro, Route124_Text_LilaDefeat, Route124_Text_LilaNotEnoughMons, Route124_EventScript_RegisterLila
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchLila
	msgbox Route124_Text_LilaPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterLila::
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_RematchLila::
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaRematchIntro, Route124_Text_LilaRematchDefeat, Route124_Text_LilaRematchNotEnoughMons
	msgbox Route124_Text_LilaPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roy::
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyIntro, Route124_Text_RoyDefeat, Route124_Text_RoyNotEnoughMons, Route124_EventScript_RegisterRoy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchRoy
	msgbox Route124_Text_RoyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterRoy::
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_RematchRoy::
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyRematchIntro, Route124_Text_RoyRematchDefeat, Route124_Text_RoyRematchNotEnoughMons
	msgbox Route124_Text_RoyPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Declan::
	trainerbattle_single TRAINER_DECLAN, Route124_Text_DeclanIntro, Route124_Text_DeclanDefeat
	msgbox Route124_Text_DeclanPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Isabella::
	trainerbattle_single TRAINER_ISABELLA, Route124_Text_IsabellaIntro, Route124_Text_IsabellaDefeat
	msgbox Route124_Text_IsabellaPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_RouteMaster::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_VOLT_SWITCH, Route124_EventScript_RouteMasterGivenItem
	goto_if_defeated TRAINER_ROUTE_MASTER_124, Route124_EventScript_RouteMasterDefeated
	goto_if_not_defeated TRAINER_SPENCER, Route124_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_ROLAND, Route124_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_JENNY_1, Route124_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_GRACE, Route124_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_CHAD, Route124_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_LILA_AND_ROY_1, Route124_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_DECLAN, Route124_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_ISABELLA, Route124_EventScript_RouteMasterNotReady
	msgbox Route124_Text_DastardlyAndDeceptive, MSGBOX_DEFAULT
	msgbox Route124_Text_IllGiveYouAShock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route124_EventScript_RouteMasterWillWait
	msgbox Route124_Text_PrepareToBeConfounded, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ROUTE_MASTER_124, Route124_Text_RouteMasterDefeat
	goto Route124_EventScript_RouteMasterDefeated
	end

Route124_EventScript_RouteMasterDefeated::
	msgbox Route124_Text_ForYou, MSGBOX_DEFAULT
	giveitem ITEM_TM_VOLT_SWITCH
	msgbox Route124_Text_VoltSwitchExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_VOLT_SWITCH
	release
	end

Route124_EventScript_RouteMasterNotReady::
	msgbox Route124_Text_DastardlyAndDeceptive, MSGBOX_DEFAULT
	msgbox Route124_Text_WantATasteOfTrickery, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RouteMasterWillWait::
	msgbox Route124_Text_Unfortunate, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RouteMasterGivenItem::
	msgbox Route124_Text_VoltSwitchExplanation, MSGBOX_DEFAULT
	release
	end

Route124_Text_DastardlyAndDeceptive:
	.string "My team specialises in dastardly and\n"
	.string "deceptive strategies.\p"
	.string "Thinking you've lined up your POKéMON\n"
	.string "correctly only for your opponent to\l"
	.string "switch and deal damage all at once…\p"
	.string "That is what my strategy is all about.$"

Route124_Text_WantATasteOfTrickery:
	.string "If you want a taste of my trickery\n"
	.string "then go ahead and beat every TRAINER\l"
	.string "swimming around this ROUTE.\p"
	.string "Let me know when you've done that!$"

Route124_Text_IllGiveYouAShock:
	.string "Since you've beaten every TRAINER on\n"
	.string "this ROUTE, I'll give you a shock.\p"
	.string "Ready to face the electrifying,\n"
	.string "head-spinning strategy of my team?$"

Route124_Text_Unfortunate:
	.string "How unfortunate…\n"
	.string "Very well, I will be here waiting.$"

Route124_Text_PrepareToBeConfounded:
	.string "Prepare to be confounded!$"

Route124_Text_RouteMasterDefeat:
	.string "I was the one who ended up confounded…$"

Route124_Text_ForYou:
	.string "Here, this is for you.$"

Route124_Text_VoltSwitchExplanation:
	.string "This TM is for VOLT SWITCH.\n"
	.string "VOLT SWITCH deals damage and swaps\l"
	.string "your POKéMON out of battle.\p"
	.string "Use this to swing the momentum of the\n"
	.string "battle in your favour!$"

Route124_Text_HuntersHouse:
	.string "HUNTER'S HOUSE$"

