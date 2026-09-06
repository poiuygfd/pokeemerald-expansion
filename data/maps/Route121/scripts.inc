Route121_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route121_OnTransition
	.byte 0

Route121_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

Route121_EventScript_Woman::
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
	end

Route121_EventScript_MtPyrePierSign::
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
	end

Route121_EventScript_SafariZoneSign::
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
	end

Route121_EventScript_MagmaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	goto Route121_EventScript_MagmaGruntsMoveOut
	end

Route121_EventScript_MagmaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	goto Route121_EventScript_MagmaGruntsMoveOut
	end

Route121_EventScript_MagmaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	goto Route121_EventScript_MagmaGruntsMoveOut
	end

Route121_EventScript_MagmaTrigger3::
	lockall
	setvar VAR_0x8008, 3
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	goto Route121_EventScript_MagmaGruntsMoveOut
	end

Route121_EventScript_MagmaGruntsMoveOut::
	applymovement LOCALID_ROUTE121_GRUNT_2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route121_Text_OkayMoveOutToMtPyre, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE121_GRUNT_1, Route121_Movement_Grunt1Exit
	applymovement LOCALID_ROUTE121_GRUNT_2, Route121_Movement_Grunt2Exit
	applymovement LOCALID_ROUTE121_GRUNT_3, Route121_Movement_Grunt3Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ROUTE121_GRUNT_1
	removeobject LOCALID_ROUTE121_GRUNT_2
	removeobject LOCALID_ROUTE121_GRUNT_3
	delay 30
	goto_if_eq VAR_0x8008, 0, Route121_EventScript_RivalEnter0
	goto_if_eq VAR_0x8008, 1, Route121_EventScript_RivalEnter1
	goto_if_eq VAR_0x8008, 2, Route121_EventScript_RivalEnter2
	goto_if_eq VAR_0x8008, 3, Route121_EventScript_RivalEnter3
	end

Route121_EventScript_RivalEnter0::
	addobject LOCALID_ROUTE121_RIVAL
	applymovement LOCALID_ROUTE121_RIVAL, Route121_Movement_RivalEnter0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route121_EventScript_MayDialogue
	call_if_eq VAR_RESULT, FEMALE, Route121_EventScript_BrendanDialogue
	closemessage
	applymovement LOCALID_ROUTE121_RIVAL, Route121_Movement_RivalExit0
	waitmovement 0
	removeobject LOCALID_ROUTE121_RIVAL
	setvar VAR_ROUTE121_STATE, 1
	releaseall
	end

Route121_EventScript_RivalEnter1::
	addobject LOCALID_ROUTE121_RIVAL
	applymovement LOCALID_ROUTE121_RIVAL, Route121_Movement_RivalEnter1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route121_EventScript_MayDialogue
	call_if_eq VAR_RESULT, FEMALE, Route121_EventScript_BrendanDialogue
	closemessage
	applymovement LOCALID_ROUTE121_RIVAL, Route121_Movement_RivalExit0
	waitmovement 0
	removeobject LOCALID_ROUTE121_RIVAL
	setvar VAR_ROUTE121_STATE, 1
	releaseall
	end

Route121_EventScript_RivalEnter2::
	addobject LOCALID_ROUTE121_RIVAL
	applymovement LOCALID_ROUTE121_RIVAL, Route121_Movement_RivalEnter2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route121_EventScript_MayDialogue
	call_if_eq VAR_RESULT, FEMALE, Route121_EventScript_BrendanDialogue
	closemessage
	applymovement LOCALID_ROUTE121_RIVAL, Route121_Movement_RivalExit0
	waitmovement 0
	removeobject LOCALID_ROUTE121_RIVAL
	setvar VAR_ROUTE121_STATE, 1
	releaseall
	end

Route121_EventScript_RivalEnter3::
	addobject LOCALID_ROUTE121_RIVAL
	applymovement LOCALID_ROUTE121_RIVAL, Route121_Movement_RivalEnter3
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route121_EventScript_MayDialogue
	call_if_eq VAR_RESULT, FEMALE, Route121_EventScript_BrendanDialogue
	closemessage
	applymovement LOCALID_ROUTE121_RIVAL, Route121_Movement_RivalExit1
	waitmovement 0
	removeobject LOCALID_ROUTE121_RIVAL
	setvar VAR_ROUTE121_STATE, 1
	releaseall
	end

Route121_EventScript_BrendanDialogue:
	msgbox Route121_Text_BrendanWasThatTeamMagma, MSGBOX_DEFAULT
	return

Route121_EventScript_MayDialogue:
	msgbox Route121_Text_MayWasThatTeamMagma, MSGBOX_DEFAULT
	return

Route121_Movement_Grunt1Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_Grunt2Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_Grunt3Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_RivalEnter0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	step_end

Route121_Movement_RivalEnter1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	step_end

Route121_Movement_RivalEnter2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route121_Movement_RivalEnter3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

Route121_Movement_RivalExit0:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_RivalExit1:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_EventScript_Vanessa::
	trainerbattle_single TRAINER_VANESSA, Route121_Text_VanessaIntro, Route121_Text_VanessaDefeat
	msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Walter::
	trainerbattle_single TRAINER_WALTER_1, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, Route121_EventScript_RegisterWalter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchWalter
	msgbox Route121_Text_WalterPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterWalter::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_WalterRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WALTER_1
	release
	end

Route121_EventScript_RematchWalter::
	trainerbattle_rematch TRAINER_WALTER_1, Route121_Text_WalterRematchIntro, Route121_Text_WalterRematchDefeat
	msgbox Route121_Text_WalterPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Tammy::
	trainerbattle_single TRAINER_TAMMY, Route121_Text_TammyIntro, Route121_Text_TammyDefeat
	msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Kate::
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_KateIntro, Route121_Text_KateDefeat, Route121_Text_KateNotEnoughMons
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Joy::
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_JoyIntro, Route121_Text_JoyDefeat, Route121_Text_JoyNotEnoughMons
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Jessica::
	trainerbattle_single TRAINER_JESSICA_1, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat, Route121_EventScript_RegisterJessica
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchJessica
	msgbox Route121_Text_JessicaPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterJessica::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_JessicaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JESSICA_1
	release
	end

Route121_EventScript_RematchJessica::
	trainerbattle_rematch TRAINER_JESSICA_1, Route121_Text_JessicaRematchIntro, Route121_Text_JessicaRematchDefeat
	msgbox Route121_Text_JessicaPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Cale::
	trainerbattle_single TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat
	msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Myles::
	trainerbattle_single TRAINER_MYLES, Route121_Text_MylesIntro, Route121_Text_MylesDefeat
	msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Pat::
	trainerbattle_single TRAINER_PAT, Route121_Text_PatIntro, Route121_Text_PatDefeat
	msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Marcel::
	trainerbattle_single TRAINER_MARCEL, Route121_Text_MarcelIntro, Route121_Text_MarcelDefeat
	msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Cristin::
	trainerbattle_single TRAINER_CRISTIN_1, Route121_Text_CristinIntro, Route121_Text_CristinDefeat, Route121_EventScript_RegisterCristin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchCristin
	msgbox Route121_Text_CristinPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterCristin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_CristinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CRISTIN_1
	release
	end

Route121_EventScript_RematchCristin::
	trainerbattle_rematch TRAINER_CRISTIN_1, Route121_Text_CristinRematchIntro, Route121_Text_CristinRematchDefeat
	msgbox Route121_Text_CristinPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_Text_OkayMoveOutToMtPyre:
	.string "Okay!\n"
	.string "We're to move out to MT. PYRE!$"

Route121_Text_BrendanWasThatTeamMagma:
	.string "BRENDAN: {PLAYER}!\n"
	.string "Was that TEAM MAGMA just now?\p"
	.string "Why are TEAM MAGMA going to MT. PYRE?\n"
	.string "Whatever the reason, it can't be good!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "What?\n"
	.string "TEAM AQUA are involved too?\p"
	.string "I really don't like this…\n"
	.string "We need to head after them.\p"
	.string "I may have lost to them before,\n"
	.string "but I've grown much stronger now!$"

Route121_Text_MayWasThatTeamMagma:
	.string "MAY: {PLAYER}{KUN}!\n"
	.string "Was that TEAM MAGMA just now?\p"
	.string "Why are TEAM MAGMA going to MT. PYRE?\n"
	.string "I doubt that their intentions are good…\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "What?\n"
	.string "TEAM AQUA are involved too?\p"
	.string "I have a bad feeling about this…\n"
	.string "We need to head after them.\p"
	.string "TEAM MAGMA beat me once, but I have\n"
	.string "trained a lot since then!$"

Route121_Text_AheadLoomsMtPyre:
	.string "Ahead looms MT. PYRE…\p"
	.string "It is a natural monument to the spirits \n"
	.string "of departed POKéMON…$"

Route121_Text_MtPyrePierSign:
	.string "MT. PYRE PIER\p"
	.string "…The sign is old and worn out.\n"
	.string "The words are barely legible…$"

Route121_Text_SafariZoneSign:
	.string "“Filled with rare POKéMON!”\n"
	.string "SAFARI ZONE$"

