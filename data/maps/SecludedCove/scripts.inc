SecludedCove_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SecludedCove_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SecludedCove_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SecludedCove_OnTransition
	.byte 0

SecludedCove_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SecludedCove_EventScript_TryRemoveRegieleki
	end

SecludedCove_EventScript_TryRemoveRegieleki::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

SecludedCove_OnLoad:
	setflag FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED
	call_if_unset FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, SecludedCove_EventScript_HideRegiEntrance
	end

SecludedCove_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

SecludedCove_OnTransition:
	setflag FLAG_LANDMARK_SECLUDED_COVE
	call SecludedCove_EventScript_ClearSteps
	call_if_unset FLAG_DEFEATED_REGIELEKI, IslandCave_EventScript_ShowRegieleki
	end

IslandCave_EventScript_ShowRegieleki::
	clearflag FLAG_HIDE_REGIELEKI
	return

SecludedCove_EventScript_OpenRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setflag FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED
	end

SecludedCove_EventScript_CaveEntranceMiddle::
	lockall
	call_if_set FLAG_TEMP_REGICE_PUZZLE_FAILED, SecludedCove_EventScript_ClearSteps
	goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, SecludedCove_EventScript_BigHoleInWall
	braillemessage IslandCave_Braille_RunLapAroundWall
	setflag FLAG_TEMP_REGICE_PUZZLE_STARTED
	special ShouldDoBrailleRegicePuzzle
	goto SecludedCove_EventScript_CloseBrailleMsg
	end

SecludedCove_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

SecludedCove_EventScript_CaveEntranceSide::
	lockall
	call_if_set FLAG_TEMP_REGICE_PUZZLE_FAILED, SecludedCove_EventScript_ClearSteps
	braillemessage IslandCave_Braille_RunLapAroundWall
	goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, SecludedCove_EventScript_CloseBrailleMsg
	setflag FLAG_TEMP_REGICE_PUZZLE_STARTED
	special ShouldDoBrailleRegicePuzzle
	goto SecludedCove_EventScript_CloseBrailleMsg
	end

SecludedCove_EventScript_CloseBrailleMsg::
	waitbuttonpress
	closebraillemessage
	releaseall
	end

SecludedCove_EventScript_ClearSteps::
	setvar VAR_REGICE_STEPS_1, 0
	setvar VAR_REGICE_STEPS_2, 0
	setvar VAR_REGICE_STEPS_3, 0
	clearflag FLAG_TEMP_REGICE_PUZZLE_FAILED
	return

SecludedCove_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SecludedCove_EventScript_DefeatedRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SecludedCove_EventScript_RanFromRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SecludedCove_EventScript_RanFromRegieleki
	setflag FLAG_DEFEATED_REGIELEKI
	release
	end

SecludedCove_EventScript_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

SecludedCove_EventScript_RanFromRegieleki::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end
