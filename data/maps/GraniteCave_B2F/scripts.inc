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
