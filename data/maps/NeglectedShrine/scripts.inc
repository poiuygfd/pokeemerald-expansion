NeglectedShrine_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NeglectedShrine_OnResume
	map_script MAP_SCRIPT_ON_LOAD, NeglectedShrine_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NeglectedShrine_OnTransition
	.byte 0

NeglectedShrine_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NeglectedShrine_EventScript_TryRemoveRegidrago
	end

NeglectedShrine_EventScript_TryRemoveRegidrago::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

NeglectedShrine_OnLoad:
	setflag FLAG_SYS_REGIDRAGO_PUZZLE_COMPLETED
	call_if_unset FLAG_SYS_REGIDRAGO_PUZZLE_COMPLETED, NeglectedShrine_EventScript_HideRegiEntrance
	end

NeglectedShrine_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

NeglectedShrine_OnTransition:
	setflag FLAG_LANDMARK_NEGLECTED_SHRINE
	call_if_unset FLAG_DEFEATED_REGIDRAGO, NeglectedShrine_EventScript_ShowRegidrago
	end

NeglectedShrine_EventScript_ShowRegidrago::
	clearflag FLAG_HIDE_REGIDRAGO
	return

NeglectedShrine_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_REGIDRAGO_PUZZLE_COMPLETED, NeglectedShrine_EventScript_BigHoleInWall
	braillemsgbox DesertRuins_Braille_UseRockSmash
	releaseall
	end

NeglectedShrine_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

NeglectedShrine_EventScript_CaveEntranceSide::
	lockall
	braillemsgbox DesertRuins_Braille_UseRockSmash
	releaseall
	end

NeglectedShrine_EventScript_Regidrago::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NeglectedShrine_EventScript_DefeatedRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NeglectedShrine_EventScript_RanFromRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NeglectedShrine_EventScript_RanFromRegidrago
	setflag FLAG_DEFEATED_REGIDRAGO
	release
	end

NeglectedShrine_EventScript_DefeatedRegidrago::
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

NeglectedShrine_EventScript_RanFromRegidrago::
	setvar VAR_0x8004, SPECIES_REGIDRAGO
	goto Common_EventScript_LegendaryFlewAway
	end

