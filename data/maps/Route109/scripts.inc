@ NOTE: Route 109's sail to Dewford script references local IDs from Dewford's map.
@  These are labeled in DewfordTown/scripts.inc

Route109_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route109_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, Route109_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route109_OnResume
	.byte 0

Route109_OnFrame:
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route109_EventScript_StartSailing
	.2byte 0

Route109_EventScript_StartSailing::
	lockall
	goto Route109_EventScript_Sailing
	end

Route109_OnLoad:
	call_if_set FLAG_HIDE_BEACH_TUBES, Route109_EventScript_HideInnerTubes
	end

Route109_EventScript_HideInnerTubes::
	setmetatile 27, 45, METATILE_General_SandPit_Center, FALSE
	return

Route109_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_BOARD_BRINEY_BOAT_STATE, 1, Route109_EventScript_SetBrineyPos
	call_if_unset FLAG_HIDE_ROUTE_109_OBSTACLE_MAN, Route109_EventScript_ChangeTMGiverDirection
	call_if_set FLAG_HIDE_BEACH_TUBES, Route109_EventScript_TryShowRegitube
	end

Route109_EventScript_SetBrineyPos:
	setobjectxyperm LOCALID_DEWFORD_BRINEY, 32, 25
	setobjectmovementtype LOCALID_DEWFORD_BRINEY, MOVEMENT_TYPE_FACE_DOWN
	return

Route109_EventScript_ChangeTMGiverDirection::
	setobjectmovementtype LOCALID_ROUTE109_TM_GIVER, MOVEMENT_TYPE_FACE_LEFT
	return

Route109_EventScript_TryShowRegitube::
	call_if_set FLAG_CAUGHT_REGITUBE, Route109_EventScript_HideRegitube
	call_if_unset FLAG_CAUGHT_REGITUBE, Route109_EventScript_ShowRegitube
	return

Route109_EventScript_ShowRegitube::
	goto_if_set FLAG_DEFEATED_REGITUBE, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_REGITUBE
	return

Route109_EventScript_HideRegitube::
	setflag FLAG_HIDE_REGITUBE
	return

Route109_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route109_EventScript_TryRemoveRegitube
	end

Route109_EventScript_TryRemoveRegitube::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ROUTE_109_REGITUBE
	return

Route109_EventScript_MrBriney::
	lock
	faceplayer
	msgbox Route109_Text_ReadyToSetSail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route109_EventScript_DeclineSailing
	goto Route109_EventScript_SettingSail
	end

Route109_EventScript_DeclineSailing::
	msgbox Route109_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_SettingSail::
	msgbox Route109_Text_AnchorsAweigh, MSGBOX_DEFAULT
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	warp MAP_ROUTE109, 32, 26
	waitstate
	releaseall
	end

Route109_EventScript_Sailing::
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
	setflag FLAG_IS_PLAYER_BOATING
	setflag FLAG_BRINEY_STEERING_BOAT
	dofieldeffect FLDEFF_USE_SURF
	waitstate
	applymovement LOCALID_ROUTE109_BRINEY, Route109_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_ROUTE109_BRINEY
	msgbox Route109_Text_BrineyOffWeGo, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route109_EventScript_WantToLand::
	lock
	msgbox Route109_Text_WantToLandHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_EventScript_GetOffBoat
	release
	end

Route109_EventScript_GetOffBoat::
	clearflag FLAG_BRINEY_STEERING_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	warp MAP_ROUTE109, 32, 25
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	waitstate
	release
	end

Route109_Movement_BrineyBoardBoat:
	walk_down
	walk_down
	step_end

Route109_EventScript_Regitube::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGITUBE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGITUBE, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route109_EventScript_DefeatedRegitube
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route109_EventScript_RanFromRegitube
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route109_EventScript_RanFromRegitube
	setflag FLAG_CAUGHT_REGITUBE
	release
	end

Route109_EventScript_DefeatedRegitube::
	setflag FLAG_DEFEATED_REGITUBE
	setvar VAR_0x8004, SPECIES_REGITUBE
	goto Common_EventScript_LegendaryFlewAway
	end

Route109_EventScript_RanFromRegitube::
	setvar VAR_0x8004, SPECIES_REGITUBE
	goto Common_EventScript_LegendaryFlewAway
	end

Route109_EventScript_SeashoreHouseGirl::
	msgbox Route109_Text_ChillAtMyPapasSpot, MSGBOX_NPC
	end

Route109_EventScript_SandCastleBoy::
	lock
	faceplayer
	msgbox Route109_Text_SandCastleTakingLongTime, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route109_EventScript_SoftSandGirl::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_RECEIVED_SOFT_SAND, Route109_EventScript_AlreadyReceivedSoftSand
	msgbox Route109_Text_YouCanHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_SOFT_SAND
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_RECEIVED_SOFT_SAND
	release
	end

Route109_EventScript_AlreadyReceivedSoftSand::
	msgbox Route109_Text_WereGoingToMakeBigCastle, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route109_EventScript_Woman::
	msgbox Route109_Text_LittleKidsDartAround, MSGBOX_NPC
	end

Route109_EventScript_OldMan::
	msgbox Route109_Text_ZigzagoonPicksUpLitter, MSGBOX_NPC
	end

Route109_EventScript_PierBoy::
	msgbox Route109_Text_ThisWasRecentlyConstructed, MSGBOX_NPC
	end

Route109_EventScript_ChillingWaterGiver::
	lock
	goto_if_unset FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS, Route109_EventScript_ChillingWaterObstacle
	faceplayer
	goto_if_set FLAG_RECEIVED_CHILLING_WATER, Route109_EventScript_ExplainChillingWater
	msgbox Route109_Text_WaterIsWarm, MSGBOX_DEFAULT
	giveitem ITEM_TM_CHILLING_WATER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHILLING_WATER
	msgbox Route109_Text_ChillingWaterExplanation, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_ExplainChillingWater::
	msgbox Route109_Text_ChillingWaterExplanation, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_ChillingWaterObstacle::
	lock
	msgbox Route109_Text_ColdWaterIsBetter, MSGBOX_DEFAULT
	waitmessage 0
	closemessage
	release
	end

Route109_EventScript_ObstacleMan::
	lock
	msgbox Route109_Text_HotWaterIsBetter, MSGBOX_DEFAULT
	waitmessage 0
	closemessage
	release
	end

Route109_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox Route109_Text_ZigzagoonCry, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route109_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 1
	goto Route109_EventScript_RivalScene
	end

Route109_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 2
	goto Route109_EventScript_RivalScene
	end

Route109_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 3
	goto Route109_EventScript_RivalScene
	end

Route109_EventScript_RivalTrigger4::
	setvar VAR_0x8008, 3 @ don't forget to change this when you deal with the rival stuff
	goto Route109_EventScript_RivalScene
	end

Route109_EventScript_RivalScene::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route109_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route109_EventScript_PlayBrendanMusic
	applymovement LOCALID_ROUTE109_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_ROUTE109_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE109_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 1, Route109_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route109_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route109_EventScript_RivalApproachPlayer3
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route109_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route109_EventScript_BrendanBattle
	releaseall
	end

Route109_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route109_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route109_EventScript_MayBattle::
	msgbox Route109_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route109_EventScript_MayBattleTreecko
	case 1, Route109_EventScript_MayBattleTorchic
	case 2, Route109_EventScript_MayBattleMudkip
	end

Route109_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_109_TREECKO, Route109_Text_MayDefeated
	goto Route109_EventScript_MayDefeated
	end

Route109_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_109_TORCHIC, Route109_Text_MayDefeated
	goto Route109_EventScript_MayDefeated
	end

Route109_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_109_MUDKIP, Route109_Text_MayDefeated
	goto Route109_EventScript_MayDefeated
	end

Route109_EventScript_MayDefeated::
	msgbox Route109_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route109_EventScript_GiveItemfinder
	msgbox Route109_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route109_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	msgbox Route109_Text_MayLeaves, MSGBOX_DEFAULT
	goto Route109_EventScript_RivalExit
	end

Route109_EventScript_BrendanBattle::
	msgbox Route109_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route109_EventScript_BrendanBattleTreecko
	case 1, Route109_EventScript_BrendanBattleTorchic
	case 2, Route109_EventScript_BrendanBattleMudkip
	end

Route109_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_109_TREECKO, Route109_Text_BrendanDefeated
	goto Route109_EventScript_BrendanDefeated
	end

Route109_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_109_TORCHIC, Route109_Text_BrendanDefeated
	goto Route109_EventScript_BrendanDefeated
	end

Route109_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_109_MUDKIP, Route109_Text_BrendanDefeated
	goto Route109_EventScript_BrendanDefeated
	end

Route109_EventScript_BrendanDefeated::
	msgbox Route109_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route109_EventScript_GiveItemfinder
	msgbox Route109_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route109_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	msgbox Route109_Text_BrendanLeaves, MSGBOX_DEFAULT
	goto Route109_EventScript_RivalExit
	end

Route109_EventScript_GiveItemfinder::
	giveitem ITEM_DOWSING_MACHINE
	return

Route109_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route109_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route109_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route109_EventScript_MoveRival3
	setobjectmovementtype LOCALID_ROUTE109_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_ROUTE109_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_ROUTE109_RIVAL
	addobject LOCALID_ROUTE109_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route109_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route109_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route109_EventScript_RivalExit3
	removeobject LOCALID_ROUTE109_RIVAL_ON_BIKE
	setvar VAR_ROUTE109_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route109_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_ROUTE109_RIVAL, Route109_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route109_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_ROUTE109_RIVAL, Route109_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Route109_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_ROUTE109_RIVAL, Route109_Movement_RivalApproachPlayer3
	waitmovement 0
	return

Route109_EventScript_RivalExit1::
	applymovement LOCALID_ROUTE109_RIVAL_ON_BIKE, Route109_Movement_RivalExit1
	waitmovement 0
	return

Route109_EventScript_RivalExit2::
	applymovement LOCALID_ROUTE109_RIVAL_ON_BIKE, Route109_Movement_RivalExit2
	waitmovement 0
	return

Route109_EventScript_RivalExit3::
	applymovement LOCALID_ROUTE109_RIVAL_ON_BIKE, Route109_Movement_RivalExit3
	waitmovement 0
	return

Route109_EventScript_MoveRival1::
	setobjectxyperm LOCALID_ROUTE109_RIVAL_ON_BIKE, 33, 55
	return

Route109_EventScript_MoveRival2::
	setobjectxyperm LOCALID_ROUTE109_RIVAL_ON_BIKE, 34, 55
	return

Route109_EventScript_MoveRival3::
	setobjectxyperm LOCALID_ROUTE109_RIVAL_ON_BIKE, 35, 55
	return

Route109_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route109_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route109_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route109_Movement_RivalExit1:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route109_Movement_RivalExit2:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route109_Movement_RivalExit3:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route109_EventScript_SeashoreHouseSign::
	msgbox Route109_Text_SeashoreHouseSign, MSGBOX_SIGN
	end

Route109_EventScript_TrainerTipsSign::
	msgbox Route109_Text_TrainerTipsSign, MSGBOX_SIGN
	end

Route109_EventScript_InnerTubes::
	msgbox Route109_Text_PileOfInnerTubes, MSGBOX_SIGN
	checkspecies SPECIES_REGIGIGAS, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_SpawnRegitube
	end

Route109_EventScript_SpawnRegitube::
	lockall
	msgbox Route109_Text_RegigigasReacting, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route109_EventScript_PlayerMove1
	call_if_eq VAR_FACING, DIR_NORTH, Route109_EventScript_PlayerMove2
	call_if_eq VAR_FACING, DIR_EAST, Route109_EventScript_PlayerMove3
	call_if_eq VAR_FACING, DIR_WEST, Route109_EventScript_PlayerMove4
	delay 20
	fadescreen FADE_TO_BLACK
	addobject LOCALID_ROUTE_109_REGIGIGAS
	playse SE_BALL_OPEN
	delay 30
	fadescreen FADE_FROM_BLACK
	delay 100
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_NORMAL
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 160
	fadescreen FADE_TO_WHITE
	setflag FLAG_HIDE_BEACH_TUBES
	removeobject LOCALID_ROUTE_109_BEACH_TUBES
	call Route109_EventScript_HideInnerTubes
	addobject LOCALID_ROUTE_109_REGITUBE
	clearflag FLAG_HIDE_REGITUBE
	special DrawWholeMapView
	playse SE_ORB
	delay 90
	fadescreen FADE_FROM_WHITE
	delay 120
	applymovement LOCALID_ROUTE_109_REGIGIGAS, Route109_Movement_EnterBall
	waitmovement 0
	removeobject LOCALID_ROUTE_109_REGIGIGAS
	setflag FLAG_HIDE_CUTSCENE_REGIGIGAS
	special DrawWholeMapView
	releaseall
	end

Route109_Movement_EnterBall:
	enter_pokeball
	step_end

Route109_EventScript_PlayerMove1::
	applymovement LOCALID_PLAYER, Route109_Movement_PlayerMovement1
	waitmovement 0
	return

Route109_EventScript_PlayerMove2::
	applymovement LOCALID_PLAYER, Route109_Movement_PlayerMovement2
	waitmovement 0
	return

Route109_EventScript_PlayerMove3::
	applymovement LOCALID_PLAYER, Route109_Movement_PlayerMovement3
	waitmovement 0
	return

Route109_EventScript_PlayerMove4::
	applymovement LOCALID_PLAYER, Route109_Movement_PlayerMovement4
	waitmovement 0
	return

Route109_Movement_PlayerMovement1:
	walk_left
	walk_down
	walk_down
	walk_left
	face_right
	step_end

Route109_Movement_PlayerMovement2:
	walk_left
	walk_left
	face_right
	step_end

Route109_Movement_PlayerMovement3:
	walk_down
	walk_left
	face_right
	step_end

Route109_Movement_PlayerMovement4:
	walk_down
	walk_left
	walk_left
	walk_left
	face_right
	step_end

Route109_EventScript_David::
	trainerbattle_single TRAINER_DAVID, Route109_Text_DavidIntro, Route109_Text_DavidDefeated
	msgbox Route109_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Alice::
	trainerbattle_single TRAINER_ALICE, Route109_Text_AliceIntro, Route109_Text_AliceDefeated
	msgbox Route109_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY, Route109_Text_HueyIntro, Route109_Text_HueyDefeated
	msgbox Route109_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Edmond::
	trainerbattle_single TRAINER_EDMOND, Route109_Text_EdmondIntro, Route109_Text_EdmondDefeated
	msgbox Route109_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_1, Route109_Text_RickyIntro, Route109_Text_RickyDefeated, Route109_EventScript_RickyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_RickyRematch
	msgbox Route109_Text_RickyPostBattle, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_RickyRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route109_Text_RickyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RICKY_1
	release
	end

Route109_EventScript_RickyRematch::
	trainerbattle_rematch TRAINER_RICKY_1, Route109_Text_RickyRematchIntro, Route109_Text_RickyRematchDefeated
	msgbox Route109_Text_RickyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_1, Route109_Text_LolaIntro, Route109_Text_LolaDefeated, Route109_EventScript_LolaRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_LolaRematch
	msgbox Route109_Text_LolaPostBattle, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_LolaRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route109_Text_LolaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LOLA_1
	release
	end

Route109_EventScript_LolaRematch::
	trainerbattle_rematch TRAINER_LOLA_1, Route109_Text_LolaRematchIntro, Route109_Text_LolaRematchDefeated
	msgbox Route109_Text_LolaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Austina::
	trainerbattle_single TRAINER_AUSTINA, Route109_Text_AustinaIntro, Route109_Text_AustinaDefeated
	msgbox Route109_Text_AustinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Gwen::
	trainerbattle_single TRAINER_GWEN, Route109_Text_GwenIntro, Route109_Text_GwenDefeated
	msgbox Route109_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER, Route109_Text_CarterIntro, Route109_Text_CarterDefeated
	msgbox Route109_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Paul::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_PaulIntro, Route109_Text_PaulDefeated, Route109_Text_PaulNotEnoughPokemon
	msgbox Route109_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Mel::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_MelIntro, Route109_Text_MelDefeated, Route109_Text_MelNotEnoughPokemon
	msgbox Route109_Text_MelPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Chandler::
	trainerbattle_single TRAINER_CHANDLER, Route109_Text_ChandlerIntro, Route109_Text_ChandlerDefeated
	msgbox Route109_Text_ChandlerPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Hailey::
	trainerbattle_single TRAINER_HAILEY, Route109_Text_HaileyIntro, Route109_Text_HaileyDefeated
	msgbox Route109_Text_HaileyPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Elijah::
	trainerbattle_single TRAINER_ELIJAH, Route109_Text_ElijahIntro, Route109_Text_ElijahDefeated
	msgbox Route109_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Text_BrineyLandedInSlateportDeliverGoods:
	.string "MR. BRINEY: Ahoy!\n"
	.string "We've made land in SLATEPORT!\p"
	.string "I suppose you're going to visit CAPT.\n"
	.string "STERN and deliver the DEVON PARTS?$"

Route109_Text_ReadyToSetSail:
	.string "MR. BRINEY: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Are you ready to set sail, my friend?$"

Route109_Text_AnchorsAweigh:
	.string "MR. BRINEY: Anchors aweigh!\p"
	.string "PEEKO, we're setting sail, my darling!$"

Route109_Text_BrineyOffWeGo:
	.string "MR. BRINEY: Alright, PEEKO, {PLAYER}{KUN}!\n"
	.string "We're setting sail!$"

Route109_Text_JustTellMeWhenYouNeedToSetSail:
	.string "MR. BRINEY: You just tell me whenever\n"
	.string "you need to set sail again!$"

Route109_Text_WantToLandHere:
	.string "MR. BRINEY: Did you want to\n"
	.string "land near SLATEPORT?$"

Route109_Text_ChillAtMyPapasSpot:
	.string "Yo, TRAINERS!\n"
	.string "Whether you're hot to trot,\l"
	.string "or cool cat not,\l"
	.string "chill at my papa's spot!$"

Route109_Text_LittleKidsDartAround:
	.string "Little kids can dart around so quickly…\p"
	.string "You don't dare take your eyes off them\n"
	.string "for an instant. It's very taxing.\p"
	.string "Mine are with my POKéMON, so they\n"
	.string "should be okay, but…$"

Route109_Text_SandCastleTakingLongTime:
	.string "Our sand castle's taking a long time\n"
	.string "to make.$"

Route109_Text_YouCanHaveThis:
	.string "You can have this!$"

Route109_Text_WereGoingToMakeBigCastle:
	.string "We're going to get all the sand from\n"
	.string "the beach and make a big castle!\p"
	.string "And then we're going to be a king and\n"
	.string "queen.\p"
	.string "We'll let you be a servant.$"

Route109_Text_WaterIsWarm:
	.string "The water at the beach here is pretty\n"
	.string "warm, much moreso than the water when\l"
	.string "I'm out sailing at sea.\p"
	.string "I much prefer the refreshing feeling of\n"
	.string "some nice, cold water though.\p"
	.string "Here, you can have this.$"

Route109_Text_ChillingWaterExplanation:
	.string "CHILLING WATER lets you blast the\n"
	.string "opponent in the face with cold water.\p"
	.string "POKéMON don't seem to appreciate it\n"
	.string "as much as I do though, as it seems\l"
	.string "to just lower their ATTACK.$"

Route109_Text_HotWaterIsBetter:
	.string "Are you crazy?\p"
	.string "On what world is a cold shower better\n"
	.string "than a hot shower?\p"
	.string "Hot showers are much more relaxing\n"
	.string "and enjoyable!$"

Route109_Text_ColdWaterIsBetter:
	.string "Are you serious?\p"
	.string "Hot showers are obviously worse than\n"
	.string "cold showers.\p"
	.string "Cold showers are super refreshing and\n"
	.string "more enjoyable!$"

Route109_Text_ZigzagoonPicksUpLitter:
	.string "The water around these parts is clean.\p"
	.string "But, I get my ZIGZAGOON to pick up\n"
	.string "litter from the shoreline at times.\p"
	.string "Dirty water becomes rain and joins our\n"
	.string "rivers, which we drink from…\p"
	.string "If we pollute the sea, it all comes\n"
	.string "back to haunt us eventually.$"

Route109_Text_ZigzagoonCry:
	.string "ZIGZAGOON: Guguu?$"

Route109_Text_ThisWasRecentlyConstructed:
	.string "This dock was constructed not too long\n"
	.string "ago.\p"
	.string "SLATEPORT'S main dock is on a different\n"
	.string "side of town, but this dock was created\l"
	.string "so that shipments to DEWFORD, RUSTBORO\l"
	.string "and PETALBURG can be done faster.$"

Route109_Text_MayLetsBattle:
	.string "MAY: Hi, {PLAYER}{KUN}, long time no see!\p"
	.string "While I was searching for other\n"
	.string "POKéMON, my POKéMON grew stronger.\p"
	.string "So…\n"
	.string "How about a little battle?$"

Route109_Text_MayDefeated:
	.string "Yikes!\n"
	.string "You're better than I expected!$"

Route109_Text_MayTakeThis:
	.string "MAY: {PLAYER}{KUN}, you've been busy\n"
	.string "training, too, haven't you?\p"
	.string "I think you deserve a reward!\n"
	.string "This is from me!$"

Route109_Text_MayExplainItemfinder:
	.string "MAY: That's a DOWSING MACHINE.\p"
	.string "Try it out. If there is an item that's\n"
	.string "not visible, it emits a sound.\p"
	.string "Oh, yeah!\p"
	.string "We should also register each other in\n"
	.string "our POKéNAVS!$"

Route109_Text_RegisteredMay:
	.string "{PLAYER} registered MAY\n"
	.string "in the POKéNAV.$"

Route109_Text_MayLeaves:
	.string "Okay, {PLAYER}{KUN}, let's meet again!\p"
	.string "I know it's a little silly coming from\n"
	.string "me, but I think you should train a lot\l"
	.string "harder for the next time.$"

Route109_Text_BrendanLetsBattle:
	.string "BRENDAN: Hey, {PLAYER}.\n"
	.string "So this is where you were.\l"
	.string "How's it going?\p"
	.string "Have you been raising your POKéMON?\n"
	.string "I'll check for you.$"

Route109_Text_BrendanDefeated:
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route109_Text_BrendanTakeThis:
	.string "BRENDAN: {PLAYER}, you've trained\n"
	.string "without me noticing…\p"
	.string "Good enough!\n"
	.string "Here, take this.$"

Route109_Text_BrendanExplainItemfinder:
	.string "BRENDAN: That's a DOWSING MACHINE.\p"
	.string "Use it to root around for items that\n"
	.string "aren't visible.\p"
	.string "If it senses something, it emits\n"
	.string "a sound.\p"
	.string "While we're here, we might as well\n"
	.string "register each other in our POKéNAVS.$"

Route109_Text_RegisteredBrendan:
	.string "{PLAYER} registered BRENDAN\n"
	.string "in the POKéNAV.$"

Route109_Text_BrendanLeaves:
	.string "Anyway, I'm off to look for new\n"
	.string "POKéMON.$"

Route109_Text_SeashoreHouseSign:
	.string "SEASHORE HOUSE\p"
	.string "“May hot battles rage on hot sands!\n"
	.string "The place for hot TRAINERS!”$"

Route109_Text_TrainerTipsSign:
	.string "TRAINER TIPS\p"
	.string "POKéMON at the same level may not\n"
	.string "always have identical stats.\p"
	.string "POKéMON raised by TRAINERS are said\n"
	.string "to grow stronger than wild POKéMON.$"

Route109_Text_PileOfInnerTubes:
	.string "It's a pile of inflatable inner tubes.$"

Route109_Text_RegigigasReacting:
	.string "Huh?\p"
	.string "REGIGIGAS appears to be reacting to\n"
	.string "the pile of inner tubes…$"
