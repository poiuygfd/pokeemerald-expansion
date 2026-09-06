MtPyre_4F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_4F_OnTransition
	.byte 0

MtPyre_4F_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	call_if_eq VAR_RESULT, MALE, MtPyre_5F_EventScript_May
	call_if_eq VAR_RESULT, FEMALE, MtPyre_5F_EventScript_Brendan
	release
	end

MtPyre_5F_EventScript_Brendan::
	msgbox MtPyre_5F_Text_BrendanGotThis, MSGBOX_DEFAULT
	return

MtPyre_5F_EventScript_May::
	msgbox MtPyre_5F_Text_MayGotThis, MSGBOX_DEFAULT
	return

MtPyre_5F_Text_AtsushiIntro:
	.string "Teacher…\n"
	.string "Please watch over my progress!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Teacher…\n"
	.string "Please forgive me!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Until I improve, my teacher, who rests\n"
	.string "here, will never find true peace…$"

MtPyre_5F_Text_BrendanGotThis:
	.string "BRENDAN: {PLAYER}?\n"
	.string "Shouldn't you be checking the mountain?\p"
	.string "You don't need to worry about me, I've\n"
	.string "got the inside covered.\p"
	.string "Make sure you do your part, too!$"

MtPyre_5F_Text_MayGotThis:
	.string "MAY: {PLAYER}{KUN}?\n"
	.string "Aren't you going to check the mountain?\p"
	.string "I appreciate you worrying about me, but\n"
	.string "I can handle this myself.\p"
	.string "We can't let them get away!$"

