Route106_MapScripts::
	.byte 0

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ESCAPE_ROPE , Route106_Text_ReceivedEscapeRope
	msgbox Route106_Text_HikerScared, MSGBOX_DEFAULT
	giveitem ITEM_ESCAPE_ROPE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_ESCAPE_ROPE
	msgbox Route106_Text_ReceivedEscapeRope, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_GiftedRope::
	msgbox Route106_Text_ReceivedEscapeRope, MSGBOX_NPC
	release
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

Route106_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

Route106_Text_HikerScared:
	.string "Aiiiiyyeeeeee!!!\p"
	.string "Uwoh… Sorry about that…\n"
	.string "I was just spelunking in this here cave…\p"
	.string "But part-way through exploring, I ran\n"
	.string "into this freaky little guy with gems\l"
	.string "for eyes! Scared the life out of me!\p"
	.string "I used my ESCAPE ROPE to get out of\n"
	.string "there as fast as I could!\p"
	.string "My heart can't take any more scares like\n"
	.string "that…\p"
	.string "My days as a spelunker are over!\n"
	.string "You'll get more use out of this than me!$"

Route106_Text_ReceivedEscapeRope:
	.string "I still feel sick…\n"
	.string "I'm just gonna stick to mountains…$"

