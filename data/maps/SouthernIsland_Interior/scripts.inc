.set LOCALID_COURTNEY, 4
.set LOCALID_ISLAND_GRUNT, 3
.set LOCALID_STEVEN, 5
.set LOCALID_LATIAS, 6

SouthernIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_OnTransition
	.byte 0

SouthernIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_TryRemoveLati
	end

SouthernIsland_Interior_EventScript_TryRemoveLati::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SOUTHERN_ISLAND_LATI
	return

SouthernIsland_Interior_OnTransition:
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatios
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatias
	call SouthernIsland_Interior_EventScript_SetUpPlayerGfx
	end

SouthernIsland_Interior_EventScript_LatiMagmaTrigger1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, SouthernIsland_Interior_Movement_PlayerMove1
	waitmovement 0
	goto SouthernIsland_Interior_EventScript_EncounterMagma
	end

SouthernIsland_Interior_EventScript_LatiMagmaTrigger2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, SouthernIsland_Interior_Movement_PlayerMove2
	waitmovement 0
	goto SouthernIsland_Interior_EventScript_EncounterMagma
	end

SouthernIsland_Interior_EventScript_EncounterMagma::
	lockall
	msgbox SouthernIsland_Interior_Text_Steven, MSGBOX_DEFAULT
	closemessage
	delay 10
	msgbox SouthernIsland_Interior_Text_MagmaGrunt, MSGBOX_DEFAULT
	closemessage
	delay 10
	msgbox SouthernIsland_Interior_Text_Courtney, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SouthernIsland_Interior_EventScript_SaidYes
	goto_if_eq VAR_RESULT, NO, SouthernIsland_Interior_EventScript_SaidNo
	end

SouthernIsland_Interior_EventScript_SaidYes::
	msgbox SouthernIsland_Interior_Text_CourtneyRepeatThat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SouthernIsland_Interior_EventScript_SaidYes
	goto_if_eq VAR_RESULT, NO, SouthernIsland_Interior_EventScript_SaidNo
	end

SouthernIsland_Interior_EventScript_SaidNo::
	msgbox SouthernIsland_Interior_Text_StevenWellSaid, MSGBOX_DEFAULT
	closemessage
	delay 10
	msgbox SouthernIsland_Interior_Text_CourtneyBattle, MSGBOX_DEFAULT
	closemessage
	goto SouthernIsland_Interior_EventScript_ChoosePartyForMultiBattle
	releaseall
	end

SouthernIsland_Interior_EventScript_ChoosePartyForMultiBattle::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, SouthernIsland_Interior_EventScript_DoStevenMultiBattle
	special LoadPlayerParty
	goto SouthernIsland_Interior_EventScript_SaidNo

SouthernIsland_Interior_EventScript_DoStevenMultiBattle::
	multi_2_vs_2 TRAINER_GRUNT_SOUTHERN_ISLAND, SouthernIsland_Interior_Text_GruntDefeat, TRAINER_COURTNEY_SOUTHERN_ISLAND, SouthernIsland_Interior_Text_CourtneyDefeat, PARTNER_STEVEN_SOUTHERN_ISLAND
	switch VAR_RESULT
	case 1, SouthernIsland_Interior_EventScript_DefeatedCourtney
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

SouthernIsland_Interior_EventScript_DefeatedCourtney::
	msgbox SouthernIsland_Interior_Text_CourtneyAfterBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_COURTNEY
	removeobject LOCALID_ISLAND_GRUNT
	fadescreen FADE_FROM_BLACK
	delay 10
	applymovement LOCALID_LATIAS, SouthernIsland_Interior_Movement_LatiasMove
	waitmovement 0
	playmoncry SPECIES_LATIAS, CRY_MODE_ENCOUNTER
	msgbox SouthernIsland_Interior_Text_LatiasCry, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_STEVEN, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox SouthernIsland_Interior_Text_StevenLatias, MSGBOX_DEFAULT
	playmoncry SPECIES_LATIAS, CRY_MODE_ENCOUNTER
	msgbox SouthernIsland_Interior_Text_LatiasCry2, MSGBOX_DEFAULT
	removeobject LOCALID_LATIAS
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LATIAS
	givemon SPECIES_LATIAS, 25, ITEM_SOUL_DEW
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, SouthernIsland_Interior_EventScript_SendLatiasParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, SouthernIsland_Interior_EventScript_SendLatiasPC
	goto Common_EventScript_NoMoreRoomForPokemon
	releaseall
	end

SouthernIsland_Interior_EventScript_SendLatiasParty::
	call SouthernIsland_Interior_EventScript_ReceivedLatiasFanfare
	call Common_EventScript_GetGiftMonPartySlot
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SouthernIsland_Interior_EventScript_StevenFarewell
	call Common_EventScript_NameReceivedPartyMon
	goto SouthernIsland_Interior_EventScript_StevenFarewell
	end

SouthernIsland_Interior_EventScript_SendLatiasPC::
	call SouthernIsland_Interior_EventScript_ReceivedLatiasFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SouthernIsland_Interior_EventScript_LatiasTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SouthernIsland_Interior_EventScript_LatiasTransferredToPC
	end

SouthernIsland_Interior_EventScript_LatiasTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto SouthernIsland_Interior_EventScript_StevenFarewell
	end

SouthernIsland_Interior_EventScript_ReceivedLatiasFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_LATIAS
	playfanfare MUS_OBTAIN_ITEM
	message SouthernIsland_Interior_Text_ObtainedLatias
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LATIAS
	return

SouthernIsland_Interior_EventScript_StevenFarewell::
	msgbox SouthernIsland_Interior_Text_StevenGoodbye, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_118_LATIOS
	special InitRoamer
	playmoncry SPECIES_LATIOS, CRY_MODE_ENCOUNTER
	warp MAP_ROUTE118, 44, 10
	releaseall
	end

SouthernIsland_Interior_Movement_PlayerMove1:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_PlayerMove2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_LatiasMove:
	walk_down
	walk_down
	walk_down
	step_end

SouthernIsland_Interior_EventScript_SetUpLatios::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIOS
	setvar VAR_TEMP_4, SPECIES_LATIOS
	return

SouthernIsland_Interior_EventScript_SetUpLatias::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIAS
	setvar VAR_TEMP_4, SPECIES_LATIAS
	return

SouthernIsland_Interior_EventScript_SetUpPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SouthernIsland_Interior_EventScript_SetBrendanGfx
	goto_if_eq VAR_RESULT, FEMALE, SouthernIsland_Interior_EventScript_SetMayGfx
	end

SouthernIsland_Interior_EventScript_SetBrendanGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

SouthernIsland_Interior_EventScript_SetMayGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

SouthernIsland_Interior_EventScript_TryLatiEncounter::
	lockall
	setvar VAR_0x8008, 12  @ Player's Y coordinate. Not read
	goto SouthernIsland_Interior_EventScript_Lati
	end

SouthernIsland_Interior_EventScript_Lati::
	goto_if_set FLAG_TEMP_2, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_DEFEATED_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_CAUGHT_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SouthernIsland_Interior_EventScript_Sign
	setflag FLAG_ENCOUNTERED_LATIAS_OR_LATIOS
	setflag FLAG_TEMP_2
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry VAR_TEMP_4, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	addobject LOCALID_SOUTHERN_ISLAND_LATI
	delay 30
	applymovement LOCALID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
	applymovement LOCALID_SOUTHERN_ISLAND_LATI, SouthernIsland_Interior_Movement_LatiApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_LAST_TALKED, LOCALID_SOUTHERN_ISLAND_LATI
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiosBattleVars
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiasBattleVars
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLatiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SouthernIsland_Interior_EventScript_LatiDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SouthernIsland_Interior_EventScript_RanFromLati
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SouthernIsland_Interior_EventScript_RanFromLati
	setflag FLAG_CAUGHT_LATIAS_OR_LATIOS
	releaseall
	end

SouthernIsland_Interior_EventScript_LatiDefeated::
	setflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_RanFromLati::
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_Sign::
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_SetLatiosBattleVars::
	seteventmon SPECIES_LATIOS, 50, ITEM_SOUL_DEW
	return

SouthernIsland_Interior_EventScript_SetLatiasBattleVars::
	seteventmon SPECIES_LATIAS, 50, ITEM_SOUL_DEW
	return

SouthernIsland_Interior_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_CameraPanDown:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

SouthernIsland_Interior_Movement_LatiApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SouthernIsland_Interior_Text_Steven:
	.string "STEVEN: {PLAYER}{KUN}, it appears LATIAS\n"
	.string "is in trouble. That must be why LATIOS\l"
	.string "brought us here.\p"
	.string "TEAM MAGMA! What are you trying to do\n"
	.string "to LATIAS?$"

SouthernIsland_Interior_Text_MagmaGrunt:
	.string "M-Miss COURTNEY, that kid is the one\n"
	.string "who keeps interfering in both our and\l"
	.string "TEAM AQUA's affairs!\p"
	.string "But that dazzling looking man there\n"
	.string "next to him…\p"
	.string "I feel like I recognize him from\n"
	.string "somewhere…\p"
	.string "Is he a CONTEST STAR perhaps?$"

SouthernIsland_Interior_Text_Courtney:
	.string "COURTNEY: Yes…\p"
	.string "For the time being… get away from me.\p"
	.string "The POKéMON behind us…\p"
	.string "TEAM MAGMA needs its power…\p"
	.string "That is what…\p"
	.string "That is what TEAM MAGMA seeks…\p"
	.string "How about it?\n"
	.string "Will you get away from me…\l"
	.string "or not?$"

SouthernIsland_Interior_Text_CourtneyRepeatThat:
	.string "COURTNEY: Speak louder…\n"
	.string "I cannot hear you…$"

SouthernIsland_Interior_Text_StevenWellSaid:
	.string "STEVEN: Well said, {PLAYER}{KUN}!\n"
	.string "Full points for the correct answer!\p"
	.string "I'll partake in this battle as well.\p"
	.string "Let's protect LATIAS from these\n"
	.string "villains together!\p"
	.string "We cannot allow LATIAS to fall into\n"
	.string "the hands of TEAM MAGMA!$"

SouthernIsland_Interior_Text_CourtneyBattle:
	.string "COURTNEY:…\p"
	.string "Well then…\p"
	.string "Deleting…$"

SouthernIsland_Interior_Text_CourtneyDefeat:
	.string "…$"

SouthernIsland_Interior_Text_GruntDefeat:
	.string "That's just too strong, right?!$"

SouthernIsland_Interior_Text_CourtneyAfterBattle:
	.string "COURTNEY: Unanticipated…\p"
	.string "You.\n"
	.string "Target lock… completed.\p"
	.string "Commencing experiment…\p"
	.string "You. Forever. Aha…\p"
	.string "Returning home…$"

SouthernIsland_Interior_Text_LatiasCry:
	.string "Hyaaaaaaan!$"

SouthernIsland_Interior_Text_StevenLatias:
	.string "STEVEN: You performed spectacularly!\p"
	.string "It seems LATIAS has recognized your\n"
	.string "talent as well.\p"
	.string "It seems to me that you've earned\n"
	.string "the trust of LATIAS.\p"
	.string "LATIAS appears to want to go with\n"
	.string "you on your travels!$"

SouthernIsland_Interior_Text_LatiasCry2:
	.string "Hyaaaan!$"

SouthernIsland_Interior_Text_ObtainedLatias:
	.string "{PLAYER} obtained LATIAS!$"

SouthernIsland_Interior_Text_StevenGoodbye:
	.string "STEVEN: Well that settles that.\p"
	.string "I can tell that you're going to\n"
	.string "become a great trainer someday.\p"
	.string "I think you should be able to handle\n"
	.string "ROUTE 119 and the FORTREE GYM beyond.\p"
	.string "For now though, we should head back.\p"
	.string "I wonder what LATIOS will do now\n"
	.string "that this issue has been resolved?\p"
	.string "Perhaps you will encounter it again\n"
	.string "roaming around the region?\p"
	.string "Well, who am I to say?\p"
	.string "Farewell, {PLAYER}{KUN}!\n"
	.string "I'm sure we shall meet again!$"
