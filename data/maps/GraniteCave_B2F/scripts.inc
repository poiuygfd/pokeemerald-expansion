GraniteCave_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_B2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B2F_OnResume
	.byte 0

GraniteCave_B2F_OnTransition:
	call_if_set FLAG_IS_CHAMPION, GraniteCave_B2F_EventScript_TryShowDiancie
	end

GraniteCave_B2F_EventScript_TryShowDiancie::
	call_if_set FLAG_CAUGHT_DIANCIE, GraniteCave_B2F_EventScript_HideDiancie
	call_if_unset FLAG_CAUGHT_DIANCIE, GraniteCave_B2F_EventScript_ShowDiancie
	return

GraniteCave_B2F_EventScript_ShowDiancie::
	goto_if_set FLAG_DEFEATED_DIANCIE, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_DIANCIE
	return

GraniteCave_B2F_EventScript_HideDiancie::
	setflag FLAG_HIDE_DIANCIE
	return

GraniteCave_B2F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, GraniteCave_B2F_EventScript_TryRemoveDiancie
	end

GraniteCave_B2F_EventScript_TryRemoveDiancie::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_GRANITE_CAVE_DIANCIE
	return

GraniteCave_B2F_EventScript_Diancie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DIANCIE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_DIANCIE, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCave_B2F_EventScript_DefeatedDiancie
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, GraniteCave_B2F_EventScript_RanFromDiancie
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, GraniteCave_B2F_EventScript_RanFromDiancie
	setflag FLAG_CAUGHT_DIANCIE
	release
	end

GraniteCave_B2F_EventScript_DefeatedDiancie::
	setflag FLAG_DEFEATED_DIANCIE
	setvar VAR_0x8004, SPECIES_DIANCIE
	goto Common_EventScript_LegendaryFlewAway
	end

GraniteCave_B2F_EventScript_RanFromDiancie::
	setvar VAR_0x8004, SPECIES_DIANCIE
	goto Common_EventScript_LegendaryFlewAway
	end

GraniteCave_B2F_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE, GraniteCave_B2F_Text_PreparedForAllSituations, GraniteCave_B2F_Text_NotPrepatedForThis
	msgbox GraniteCave_B2F_Text_AmIGoingToBeOK, MSGBOX_AUTOCLOSE
	end

GraniteCave_B2F_EventScript_Robby::
	trainerbattle_single TRAINER_ROBBY, GraniteCave_B2F_Text_BigOlCave, GraniteCave_B2F_Text_DontLoveLosingThough
	msgbox GraniteCave_B2F_Text_FocusOnTheCave, MSGBOX_AUTOCLOSE
	end

GraniteCave_B2F_Text_PreparedForAllSituations:
	.string "I make sure I'm always prepared\n"
	.string "for all situations.\p"
	.string "A cave like this is no big deal\n"
	.string "for me!$"

GraniteCave_B2F_Text_NotPrepatedForThis:
	.string "Uh oh.\n"
	.string "I wasn't prepared for this.$"

GraniteCave_B2F_Text_AmIGoingToBeOK:
	.string "Stuck in a cave with all my\n"
	.string "POKéMON fainted…\p"
	.string "Am I… going to be okay…?$"

GraniteCave_B2F_Text_BigOlCave:
	.string "I love getting stuck into a big\n"
	.string "ol' cave like this!$"

GraniteCave_B2F_Text_DontLoveLosingThough:
	.string "I don't love losing though.$"

GraniteCave_B2F_Text_FocusOnTheCave:
	.string "I'm going to go back to\n"
	.string "focusing on this big ol' cave.$"
