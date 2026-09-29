MagmaHideout_4F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_4F_OnTransition
	.byte 0

MagmaHideout_4F_OnTransition:
	call_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, MagmaHideout_4F_EventScript_PreventTrigger
	call Common_EventScript_SetupRivalGfxId
	end

MagmaHideout_4F_EventScript_PreventTrigger::
	setvar VAR_TEMP_1, 1
	return

MagmaHideout_4F_EventScript_MaxieTrigger0::
	lockall
	applymovement LOCALID_PLAYER, MagmaHideout_4F_Movement_PlayerApproach0
	waitmovement 0
	goto MagmaHideout_4F_EventScript_RivalMultiBattle
	end

MagmaHideout_4F_EventScript_MaxieTrigger1::
	lockall
	applymovement LOCALID_PLAYER, MagmaHideout_4F_Movement_PlayerApproach1
	waitmovement 0
	goto MagmaHideout_4F_EventScript_RivalMultiBattle
	end

MagmaHideout_4F_EventScript_MaxieTrigger2::
	lockall
	applymovement LOCALID_PLAYER, MagmaHideout_4F_Movement_PlayerApproach2
	waitmovement 0
	goto MagmaHideout_4F_EventScript_RivalMultiBattle
	end

MagmaHideout_4F_EventScript_RivalMultiBattle::
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieWhyMustYouBotherUs, MSGBOX_DEFAULT
	applymovement LOCALID_MAGMA_HIDEOUT_4F_TABITHA, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MagmaHideout_4F_Text_TabithaBackInMeteorFalls, MSGBOX_DEFAULT
	applymovement LOCALID_MAGMA_HIDEOUT_4F_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, MagmaHideout_4F_EventScript_MayMultiBattle
	goto_if_eq VAR_RESULT, FEMALE, MagmaHideout_4F_EventScript_BrendanMultiBattle
	end

MagmaHideout_4F_EventScript_MayMultiBattle::
	msgbox MagmaHideout_4F_Text_MayIveBeenTraining, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, MagmaHideout_4FEventScript_MayMultiBattleTreecko
	case 1, MagmaHideout_4FEventScript_MayMultiBattleTorchic
	case 2, MagmaHideout_4FEventScript_MayMultiBattleMudkip
	releaseall
	end

MagmaHideout_4F_EventScript_MayLoop::
	applymovement LOCALID_MAGMA_HIDEOUT_4F_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MayLoop, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, MagmaHideout_4FEventScript_MayMultiBattleTreecko
	case 1, MagmaHideout_4FEventScript_MayMultiBattleTorchic
	case 2, MagmaHideout_4FEventScript_MayMultiBattleMudkip
	releaseall
	end

MagmaHideout_4F_EventScript_BrendanMultiBattle::
	msgbox MagmaHideout_4F_Text_BrendanIveBeenTraining, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, MagmaHideout_4FEventScript_BrendanMultiBattleTreecko
	case 1, MagmaHideout_4FEventScript_BrendanMultiBattleTorchic
	case 2, MagmaHideout_4FEventScript_BrendanMultiBattleMudkip
	releaseall
	end

MagmaHideout_4F_EventScript_BrendanLoop::
	applymovement LOCALID_MAGMA_HIDEOUT_4F_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MagmaHideout_4F_Text_BrendanLoop, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, MagmaHideout_4FEventScript_BrendanMultiBattleTreecko
	case 1, MagmaHideout_4FEventScript_BrendanMultiBattleTorchic
	case 2, MagmaHideout_4FEventScript_BrendanMultiBattleMudkip
	releaseall
	end

MagmaHideout_4FEventScript_MayMultiBattleTreecko::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, MagmaHideout_4FEventScript_DoMayMultiBattleTreecko
	special LoadPlayerParty
	goto MagmaHideout_4F_EventScript_MayLoop

MagmaHideout_4FEventScript_DoMayMultiBattleTreecko::
	multi_2_vs_2 TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat, TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaDefeat, PARTNER_MAY_MAGMA_HIDEOUT_TREECKO
	switch VAR_RESULT
	case 1, MagmaHideout_4F_EventScript_Groudon
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

MagmaHideout_4FEventScript_MayMultiBattleTorchic::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, MagmaHideout_4FEventScript_DoMayMultiBattleTorchic
	special LoadPlayerParty
	goto MagmaHideout_4F_EventScript_MayLoop

MagmaHideout_4FEventScript_DoMayMultiBattleTorchic::
	multi_2_vs_2 TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat, TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaDefeat, PARTNER_MAY_MAGMA_HIDEOUT_TORCHIC
	switch VAR_RESULT
	case 1, MagmaHideout_4F_EventScript_Groudon
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

MagmaHideout_4FEventScript_MayMultiBattleMudkip::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, MagmaHideout_4FEventScript_DoMayMultiBattleMudkip
	special LoadPlayerParty
	goto MagmaHideout_4F_EventScript_MayLoop

MagmaHideout_4FEventScript_DoMayMultiBattleMudkip::
	multi_2_vs_2 TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat, TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaDefeat, PARTNER_MAY_MAGMA_HIDEOUT_MUDKIP
	switch VAR_RESULT
	case 1, MagmaHideout_4F_EventScript_Groudon
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

MagmaHideout_4FEventScript_BrendanMultiBattleTreecko::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, MagmaHideout_4FEventScript_DoBrendanMultiBattleTreecko
	special LoadPlayerParty
	goto MagmaHideout_4F_EventScript_BrendanLoop

MagmaHideout_4FEventScript_DoBrendanMultiBattleTreecko::
	multi_2_vs_2 TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat, TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaDefeat, PARTNER_BRENDAN_MAGMA_HIDEOUT_TREECKO
	switch VAR_RESULT
	case 1, MagmaHideout_4F_EventScript_Groudon
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

MagmaHideout_4FEventScript_BrendanMultiBattleTorchic::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, MagmaHideout_4FEventScript_DoBrendanMultiBattleTorchic
	special LoadPlayerParty
	goto MagmaHideout_4F_EventScript_BrendanLoop

MagmaHideout_4FEventScript_DoBrendanMultiBattleTorchic::
	multi_2_vs_2 TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat, TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaDefeat, PARTNER_BRENDAN_MAGMA_HIDEOUT_TORCHIC
	switch VAR_RESULT
	case 1, MagmaHideout_4F_EventScript_Groudon
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

MagmaHideout_4FEventScript_BrendanMultiBattleMudkip::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, MagmaHideout_4FEventScript_DoBrendanMultiBattleMudkip
	special LoadPlayerParty
	goto MagmaHideout_4F_EventScript_BrendanLoop

MagmaHideout_4FEventScript_DoBrendanMultiBattleMudkip::
	multi_2_vs_2 TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat, TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaDefeat, PARTNER_BRENDAN_MAGMA_HIDEOUT_MUDKIP
	switch VAR_RESULT
	case 1, MagmaHideout_4F_EventScript_Groudon
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

MagmaHideout_4F_EventScript_Groudon::
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieThisChangesNothing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MagmaHideout_4F_Movement_PlayerApproachMaxie
	applymovement LOCALID_MAGMA_HIDEOUT_4F_RIVAL, MagmaHideout_4F_Movement_RivalApproachMaxie
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieApproachGroudon
	applymovement LOCALID_MAGMA_HIDEOUT_4F_TABITHA, MagmaHideout_4F_Movement_TabithaApproachGroudon
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MAGMA_HIDEOUT_4F_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_MAGMA_HIDEOUT_4F_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_MAGMA_HIDEOUT_4F_TABITHA, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	applymovement LOCALID_MAGMA_HIDEOUT_4F_TABITHA, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MagmaHideout_4F_Text_TabithaWeShouldGoLook, MSGBOX_DEFAULT
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieYoureRight, MSGBOX_DEFAULT
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGoodbye, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, 1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, MagmaHideout_4F_EventScript_HideWailmerGrunt
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_HIDEOUT_4F_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, MagmaHideout_4F_EventScript_MayConcern
	goto_if_eq VAR_RESULT, FEMALE, MagmaHideout_4F_EventScript_BrendanConcern
	end

MagmaHideout_4F_EventScript_HideWailmerGrunt::
	setflag FLAG_HIDE_LILYCOVE_WAILMER_GRUNT
	fadescreen FADE_FROM_BLACK
	release
	end

MagmaHideout_4F_EventScript_MayConcern:
	msgbox MagmaHideout_4F_Text_MayThisIsBad, MSGBOX_DEFAULT
	closemessage
	goto MagmaHideout_4F_EventScript_RivalLeaves
	end

MagmaHideout_4F_EventScript_BrendanConcern:
	msgbox MagmaHideout_4F_Text_BrendanThisIsBad, MSGBOX_DEFAULT
	closemessage
	goto MagmaHideout_4F_EventScript_RivalLeaves
	end

MagmaHideout_4F_EventScript_RivalLeaves:
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MAGMA_HIDEOUT_4F_RIVAL, MagmaHideout_4F_Movement_RivalLeaves
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_MAGMA_HIDEOUT_4F_RIVAL
	waitse
	releaseall
	end

MagmaHideout_4F_Movement_PlayerApproach0:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

MagmaHideout_4F_Movement_PlayerApproach1:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

MagmaHideout_4F_Movement_PlayerApproach2:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

MagmaHideout_4F_Movement_PlayerApproachMaxie:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MagmaHideout_4F_Movement_RivalApproachMaxie:
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_4
	delay_4
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MagmaHideout_4F_Movement_MaxieApproachGroudon:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_faster_up
	step_end

MagmaHideout_4F_Movement_TabithaApproachGroudon:
	walk_in_place_faster_right
	delay_4
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_faster_up
	step_end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_RivalLeaves:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "I want to see GROUDON, too, but they\n"
	.string "won't let me see even its tail…\p"
	.string "It's got me feeling really frustrated.\p"
	.string "Oh, no!\n"
	.string "I blabbed about GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "I guess it's impossible to win if one\n"
	.string "doesn't have a calm mind…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "I wonder if GROUDON even has a tail?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Soon! Very soon!\l"
	.string "Our grand objective will be achieved!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "I've come so far, but now this?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAXIE, sir!\n"
	.string "An intruder is headed your way!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "You're not finished yet!\n"
	.string "You're not getting by me easily!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Was I that easy to knock down?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "C-come on, one more match…$"

MagmaHideout_4F_Text_MaxieWhyMustYouBotherUs:
	.string "MAXIE: Tch…\n"
	.string "And another one shows up…\p"
	.string "Why must you bother us?\n"
	.string "We have very important things to do.\p"
	.string "Especially YOU.\n"
	.string "You have been nothing but a thorn in\l"
	.string "our side for far too long.\p"
	.string "Come, TABITHA. Let's eliminate this\n"
	.string "problem child once and for all.$"

MagmaHideout_4F_Text_TabithaBackInMeteorFalls:
	.string "TABITHA: Hehehehehe!\n"
	.string "It would be my pleasure, BOSS.\p"
	.string "The other child shouldn't be a threat.\n"
	.string "I've already beaten them thoroughly\l"
	.string "once before in METEOR FALLS.\p"
	.string "If we work together, this should\n"
	.string "be a cinch.$"

MagmaHideout_4F_Text_BrendanIveBeenTraining:
	.string "BRENDAN: It's true I lost to you.\n"
	.string "However, I've been training hard since\l"
	.string "we last battled.\p"
MagmaHideout_4F_Text_BrendanLoop:
	.string "Don't go assuming this will be easy, now.\n"
	.string "If me and {PLAYER} work together, there's\l"
	.string "nothing that can stand in our way!\p"
	.string "Let's give them all we got, {PLAYER}!$"

MagmaHideout_4F_Text_MayIveBeenTraining:
	.string "MAY: I may have lost to you then.\n"
	.string "However, I've been hard at work since\l"
	.string "our last battle.\p"
MagmaHideout_4F_Text_MayLoop:
	.string "You will regret underestimating me.\n"
	.string "Especially since I've got {PLAYER}{KUN}\l"
	.string "right by my side!\p"
	.string "Together, I think we could beat anybody!\n"
	.string "Let's do this, {PLAYER}{KUN}!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "What makes you so adept at handling\n"
	.string "POKéMON?$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Hehe…\n"
	.string "Guess you really have grown stronger…$"

MagmaHideout_4F_Text_MaxieThisChangesNothing:
	.string "MAXIE: So what if you managed to win?\n"
	.string "This changes nothing!\p"
	.string "We already have the BLUE ORB, and\n"
	.string "are mere moments away from our goal!\p"
	.string "Come, you may watch the moment where\n"
	.string "we, TEAM MAGMA, change the world!$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: GROUDON…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This BLUE ORB is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the BLUE ORB.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: GROUDON!\n"
	.string "What's wrong?\p"
	.string "Wasn't the BLUE ORB the key?\p"
	.string "GROUDON!\n"
	.string "Where have you gone…$"

MagmaHideout_4F_Text_TabithaWeShouldGoLook:
	.string "TABITHA: BOSS!\n"
	.string "What happened?\p"
	.string "No, it doesn't matter, does it?\n"
	.string "We should go look for GROUDON!$"

MagmaHideout_4F_Text_MaxieYoureRight:
	.string "MAXIE: TABITHA…\n"
	.string "Yes, you are correct.\p"
	.string "I do not know where GROUDON went.\n"
	.string "But we won't give up here.\p"
	.string "With GROUDON gone, there is no longer\n"
	.string "any need for this blasted volcano.$"

MagmaHideout_4F_Text_MaxieGoodbye:
	.string "I am going after GROUDON, so this\n"
	.string "is where we part!$"

MagmaHideout_4F_Text_BrendanThisIsBad:
	.string "BRENDAN: This is bad…\n"
	.string "I don't know much about GROUDON, but\l"
	.string "I do know it is a fearsome POKéMON.\p"
	.string "We can't let something like that\n"
	.string "fall into the hands of TEAM MAGMA.\p"
	.string "And here I was, so happy that I was\n"
	.string "able to actually win that battle…\p"
	.string "Well, whatever.\n"
	.string "Celebrations can wait until later.\p"
	.string "Let's split up and search for both\n"
	.string "TEAM MAGMA and GROUDON.\p"
	.string "I'll let you know if I find anything.\n"
	.string "You try your best too, okay, {PLAYER}?$"

MagmaHideout_4F_Text_MayThisIsBad:
	.string "MAY: This is bad…\n"
	.string "I only know a little about GROUDON, but\l"
	.string "I know it is incredibly powerful.\p"
	.string "There's no way we can let TEAM MAGMA\n"
	.string "catch a POKéMON as dangerous as that.\p"
	.string "I was so happy that we managed to\n"
	.string "actually win against TEAM MAGMA…\p"
	.string "Well, I guess it was never going to\n"
	.string "be that easy, was it?\p"
	.string "Let's both go look for GROUDON, okay?\n"
	.string "We can cover more ground separately.\p"
	.string "I'll call you if I find anything.\n"
	.string "I hope your search goes well, {PLAYER}{KUN}.$"

