ShoalCave_LowTideIceRoom_MapScripts::
	.byte 0

ShoalCave_LowTideIceRoom_EventScript_WeathermanSnow::
	lock
	faceplayer
	goto_if_eq VAR_WEATHERMAN_STATE, 3, ShoalCave_LowTideIceRoom_EventScript_BattleWeatherman
	msgbox ShoalCave_LowTideIceRoom_Text_ColdHasToWork, MSGBOX_DEFAULT
	setvar VAR_WEATHERMAN_STATE, 3
	release
	end

ShoalCave_LowTideIceRoom_EventScript_BattleWeatherman::
	msgbox ShoalCave_LowTideIceRoom_Text_ShallWe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShoalCave_LowTideIceRoom_EventScript_WeathermanWait
	msgbox ShoalCave_LowTideIceRoom_Text_LastExperiment, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WEATHERMAN_SNOW, ShoalCave_LowTideIceRoom_Text_YouReallyAreSomething
	msgbox ShoalCave_LowTideIceRoom_Text_TheLastStraw, MSGBOX_DEFAULT
	closemessage
	fadescreenspeed FADE_TO_BLACK, 2
	setflag FLAG_HIDE_WEATHERMAN_SNOW
	clearflag FLAG_HIDE_WEATHERMAN_FINAL
	removeobject LOCALID_SHOAL_CAVE_WEATHERMAN
	delay 10
	fadescreen FADE_FROM_BLACK
	release
	end

ShoalCave_LowTideIceRoom_EventScript_WeathermanWait::
	msgbox ShoalCave_LowTideIceRoom_Text_PleaseHurry, MSGBOX_DEFAULT
	release
	end

ShoalCave_LowTideIceRoom_Text_ColdHasToWork:
	.string "Hello once again, helpful TRAINER.\p"
	.string "Part of me didn't expect you to\n"
	.string "actually follow me all the way here,\l"
	.string "but I'm glad you did.\p"
	.string "The last place was unbearably hot, so\n"
	.string "I thought this might be nice, but this\l"
	.string "place is just unbearably cold instead…\p"
	.string "In a place this cold and icy, surely I\n"
	.string "can draw out the essence of ICE and\l"
	.string "really bring forth CASTFORM's power.\p"
	.string "I really hope I can at least, because\n"
	.string "this is CASTFORM's last form.\p"
	.string "If this doesn't work, I don't know what\n"
	.string "will…\p"
	.string "Well, no point worrying about it now.\n"
	.string "As usual, let me know when you're ready.$"

ShoalCave_LowTideIceRoom_Text_ShallWe:
	.string "Well then, shall we?$"

ShoalCave_LowTideIceRoom_Text_PleaseHurry:
	.string "Make sure you're ready, but also please\n"
	.string "be quick, I'm starting to lose feeling\l"
	.string "in my fingers…$"

ShoalCave_LowTideIceRoom_Text_LastExperiment:
	.string "Excellent.\n"
	.string "Then let us begin the last experiment!$"

ShoalCave_LowTideIceRoom_Text_YouReallyAreSomething:
	.string "You really are something else…$"

ShoalCave_LowTideIceRoom_Text_TheLastStraw:
	.string "So this failed too…\n"
	.string "That was my last chance as well…\p"
	.string "CASTFORM takes its power from the\n"
	.string "weather of the skies, so it doesn't\l"
	.string "have any changes in a SANDSTORM…\p"
	.string "Which means that was the last weather…\p"
	.string "Wait, now that I think about it, how\n"
	.string "did we even create SNOW underground…?\p"
	.string "POKéMON truly are something else, huh.\p"
	.string "Well, I'm going to need to do some real\n"
	.string "thinking.\p"
	.string "I don't want to give up on CASTFORM, it\n"
	.string "really is quite a unique little POKéMON\l"
	.string "that me and my previous colleagues did\l"
	.string "spend a lot of time creating.\p"
	.string "But it's clear to me that CASTFORM isn't\n"
	.string "strong enough right now.\p"
	.string "I'm not sure if we'll meet again, but I\n"
	.string "really do appreciate all your help.\p"
	.string "Take care, young TRAINER.$"

