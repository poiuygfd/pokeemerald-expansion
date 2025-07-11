SealedChamber_InnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_InnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_InnerRoom_OnResume
	.byte 0

SealedChamber_InnerRoom_OnTransition:
	call_if_set FLAG_IS_CHAMPION, SealedChamber_InnerRoom_EventScript_TryShowRegigigas
	end

SealedChamber_InnerRoom_EventScript_TryShowRegigigas::
	call_if_set FLAG_AWOKEN_REGIGIGAS, SealedChamber_InnerRoom_EventScript_TryShowAwakeRegigigas
	call_if_unset FLAG_AWOKEN_REGIGIGAS, SealedChamber_InnerRoom_EventScript_ShowAsleepRegigigas
	return

SealedChamber_InnerRoom_EventScript_TryShowAwakeRegigigas::
	setflag FLAG_HIDE_STATIC_REGIGIGAS
	call_if_set FLAG_CAUGHT_REGIGIGAS, SealedChamber_InnerRoom_EventScript_HideAwakeRegigigas
	call_if_unset FLAG_CAUGHT_REGIGIGAS, SealedChamber_InnerRoom_EventScript_ShowAwakeRegigigas
	return

SealedChamber_InnerRoom_EventScript_ShowAwakeRegigigas::
	goto_if_set FLAG_DEFEATED_REGIGIGAS, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_REGIGIGAS
	return

SealedChamber_InnerRoom_EventScript_HideAwakeRegigigas::
	setflag FLAG_HIDE_REGIGIGAS
	return

SealedChamber_InnerRoom_EventScript_ShowAsleepRegigigas::
	setflag FLAG_HIDE_REGIGIGAS
	clearflag FLAG_HIDE_STATIC_REGIGIGAS

SealedChamber_InnerRoom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SealedChamber_InnerRoom_EventScript_TryRemoveRegigigas
	end

SealedChamber_InnerRoom_EventScript_TryRemoveRegigigas::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SEALED_CHAMBER_REGIGIGAS
	return

SealedChamber_InnerRoom_EventScript_BrailleBackWall::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth
	goto_if_set FLAG_REGI_DOORS_OPENED, SealedChamber_InnerRoom_EventScript_NoEffect
	specialvar VAR_RESULT, CheckRelicanthWailord
	goto_if_eq VAR_RESULT, FALSE, SealedChamber_InnerRoom_EventScript_NoEffect
	fadeoutbgm 0
	playse SE_TRUCK_MOVE
	special DoSealedChamberShakingEffect_Long
	waitstate
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	msgbox gText_DoorOpenedFarAway, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setflag FLAG_REGI_DOORS_OPENED
	releaseall
	end

SealedChamber_InnerRoom_EventScript_NoEffect::
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart1::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart2::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart3::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart4::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_WeFearedIt
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart5::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart6::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
	releaseall
	end

SealedChamber_InnerRoom_EventScript_SleepingRegigigas::
	lockall
	checkspecies SPECIES_REGIROCK, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, FALSE, SealedChamber_InnerRoom_EventScript_RegisNotInParty
	checkspecies SPECIES_REGICE, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, FALSE, SealedChamber_InnerRoom_EventScript_RegisNotInParty
	checkspecies SPECIES_REGISTEEL, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, FALSE, SealedChamber_InnerRoom_EventScript_RegisNotInParty
	checkspecies SPECIES_REGIELEKI, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, FALSE, SealedChamber_InnerRoom_EventScript_RegisNotInParty
	checkspecies SPECIES_REGIDRAGO, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, FALSE, SealedChamber_InnerRoom_EventScript_RegisNotInParty
	message SealedChamber_InnerRoom_Text_StatueAwakens
	waitmessage
	delay 60
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 2  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	delay 100
	call_if_eq VAR_FACING, DIR_SOUTH, SealedChamber_InnerRoom_EventScript_PlayerBackAway1
	call_if_eq VAR_FACING, DIR_NORTH, SealedChamber_InnerRoom_EventScript_PlayerBackAway2
	call_if_eq VAR_FACING, DIR_EAST, SealedChamber_InnerRoom_EventScript_PlayerBackAway3
	call_if_eq VAR_FACING, DIR_WEST, SealedChamber_InnerRoom_EventScript_PlayerBackAway4
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	delay 100
	addobject LOCALID_SEALED_CHAMBER_REGIGIGAS
	removeobject LOCALID_SEALED_CHAMBER_REGIGIGAS_STATIC
	setflag FLAG_AWOKEN_REGIGIGAS
	clearflag FLAG_HIDE_REGIGIGAS
	setflag FLAG_HIDE_STATIC_REGIGIGAS
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_NORMAL
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	delay 80
	releaseall
	end

SealedChamber_InnerRoom_EventScript_PlayerBackAway1::
	applymovement LOCALID_PLAYER, SealedChamber_InnerRoom_Movement_PlayerBackAway1
	applymovement OBJ_EVENT_ID_FOLLOWER, SealedChamber_InnerRoom_Movement_PlayerBackAway1
	return

SealedChamber_InnerRoom_EventScript_PlayerBackAway2::
	applymovement LOCALID_PLAYER, SealedChamber_InnerRoom_Movement_PlayerBackAway2
	applymovement OBJ_EVENT_ID_FOLLOWER, SealedChamber_InnerRoom_Movement_PlayerBackAway2
	return

SealedChamber_InnerRoom_EventScript_PlayerBackAway3::
	applymovement LOCALID_PLAYER, SealedChamber_InnerRoom_Movement_PlayerBackAway3
	applymovement OBJ_EVENT_ID_FOLLOWER, SealedChamber_InnerRoom_Movement_PlayerBackAway3
	return

SealedChamber_InnerRoom_EventScript_PlayerBackAway4::
	applymovement LOCALID_PLAYER, SealedChamber_InnerRoom_Movement_PlayerBackAway4
	applymovement OBJ_EVENT_ID_FOLLOWER, SealedChamber_InnerRoom_Movement_PlayerBackAway4
	return

SealedChamber_InnerRoom_Movement_PlayerBackAway1:
	face_down
	lock_facing_direction
	walk_slow_up
	walk_slow_up
	unlock_facing_direction
    step_end

SealedChamber_InnerRoom_Movement_PlayerBackAway2:
	face_up
	lock_facing_direction
	walk_slow_down
	walk_slow_down
	unlock_facing_direction
    step_end

SealedChamber_InnerRoom_Movement_PlayerBackAway3:
	face_right
	lock_facing_direction
	walk_slow_left
	walk_slow_left
	unlock_facing_direction
    step_end

SealedChamber_InnerRoom_Movement_PlayerBackAway4:
	face_left
	lock_facing_direction
	walk_slow_right
	walk_slow_right
	unlock_facing_direction
    step_end

SealedChamber_InnerRoom_EventScript_RegisNotInParty::
	msgbox SealedChamber_InnerRoom_Text_StatueOfAPokemon, MSGBOX_DEFAULT
	releaseall
	end

SealedChamber_InnerRoom_EventScript_Regigigas::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 60
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SealedChamber_InnerRoom_EventScript_DefeatedRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SealedChamber_InnerRoom_EventScript_RanFromRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SealedChamber_InnerRoom_EventScript_RanFromRegigigas
	setflag FLAG_CAUGHT_REGIGIGAS
	release
	end

SealedChamber_InnerRoom_EventScript_DefeatedRegigigas::
	setflag FLAG_DEFEATED_REGIGIGAS
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto Common_EventScript_LegendaryFlewAway
	end

SealedChamber_InnerRoom_EventScript_RanFromRegigigas::
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto Common_EventScript_LegendaryFlewAway
	end

SealedChamber_InnerRoom_Text_StatueOfAPokemon:
	.string "It appears to be a statue of a POKéMON.\p"
	.string "…Was this statue always here?$"

SealedChamber_InnerRoom_Text_StatueAwakens:
	.string "It appears to be a statue of a POKéMON.\p"
	.string "…Did the statue's arm just move?$"
