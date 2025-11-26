Route106_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route106_OnTransition
	.byte 0

Route106_OnTransition:
	call_if_eq VAR_ROUTE106_STATE, 1, Route106_EventScript_SetSpelunkerPos
	end

Route106_EventScript_SetSpelunkerPos:
	setobjectxyperm LOCALID_ROUTE106_SPELUNKER, 51, 16
	setobjectmovementtype LOCALID_ROUTE106_SPELUNKER, MOVEMENT_TYPE_FACE_RIGHT
	return

Route106_EventScript_SpelunkerTrigger1::
	lock
	msgbox Route106_Text_HeScream, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE106_SPELUNKER, Route106_Movement_SpelunkerRun1
	waitmovement 0
	removeobject LOCALID_ROUTE106_SPELUNKER
	clearflag FLAG_HIDE_DEWFORD_TOWN_SPELUNKER
	setvar VAR_ROUTE106_STATE, 2
	release
	end

Route106_EventScript_SpelunkerTrigger2::
	lock
	msgbox Route106_Text_HeScream, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE106_SPELUNKER, Route106_Movement_SpelunkerRun2
	waitmovement 0
	removeobject LOCALID_ROUTE106_SPELUNKER
	clearflag FLAG_HIDE_DEWFORD_TOWN_SPELUNKER
	setvar VAR_ROUTE106_STATE, 2
	release
	end

Route106_EventScript_Spelunker::
	lock
	msgbox Route106_Text_SelfAffirmation, MSGBOX_DEFAULT
	release
	end

Route106_Movement_SpelunkerRun1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route106_Movement_SpelunkerRun2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_ElliotRematch::
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned::
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_Text_SelfAffirmation:
	.string "Come on, man.\n"
	.string "You can do this…\p"
	.string "You've scaled countless mountains!\n"
	.string "What's one cave got on you?\p"
	.string "One dark, deep, scary cave…\p"
	.string "Agh! It's no good!\n"
	.string "Now I'm thinking about how scary it is!\p"
	.string "Gotta take deep breaths…\n"
	.string "In and out, in and out…$"

Route106_Text_HeScream:
	.string "Aiiiiiyeeeeeeee!!!!!$"

Route106_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

