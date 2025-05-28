.set LOCALID_HEATRAN, 2

ScorchedSlab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ScorchedSlab_OnResume
	.byte 0

ScorchedSlab_OnTransition:
	setflag FLAG_LANDMARK_SCORCHED_SLAB
	call_if_set FLAG_IS_CHAMPION, ScorchedSlab_EventScript_TryShowHeatran
	end

ScorchedSlab_EventScript_TryShowHeatran::
	call_if_set FLAG_CAUGHT_HEATRAN, ScorchedSlab_EventScript_HideHeatran
	call_if_unset FLAG_CAUGHT_HEATRAN, ScorchedSlab_EventScript_ShowHeatran
	return

ScorchedSlab_EventScript_ShowHeatran::
	goto_if_set FLAG_DEFEATED_HEATRAN, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_HEATRAN
	return

ScorchedSlab_EventScript_HideHeatran::
	setflag FLAG_HIDE_HEATRAN
	return

ScorchedSlab_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ScorchedSlab_EventScript_TryRemoveHeatran
	end

ScorchedSlab_EventScript_TryRemoveHeatran::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_HEATRAN
	return

ScorchedSlab_EventScript_Heatran::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HEATRAN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_HEATRAN, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ScorchedSlab_EventScript_DefeatedHeatran
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ScorchedSlab_EventScript_RanFromHeatran
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ScorchedSlab_EventScript_RanFromHeatran
	setflag FLAG_CAUGHT_HEATRAN
	release
	end

ScorchedSlab_EventScript_DefeatedHeatran::
	setflag FLAG_DEFEATED_HEATRAN
	setvar VAR_0x8004, SPECIES_HEATRAN
	goto Common_EventScript_LegendaryFlewAway
	end

ScorchedSlab_EventScript_RanFromHeatran::
	setvar VAR_0x8004, SPECIES_HEATRAN
	goto Common_EventScript_LegendaryFlewAway
	end
