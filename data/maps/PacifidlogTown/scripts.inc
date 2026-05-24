PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_SlowbroGuy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SLOWBRONITE_G, Route113_EventScript_ReceivedSlowbroniteG
	goto_if_defeated TRAINER_SLOWBRO_GUY, Route113_EventScript_GiftedSlowbroniteG
	msgbox PacifidlogTown_Text_DidYouKnowAboutSlowbro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SLOWBRO_GUY, PacifidlogTown_Text_SlowbroGuyDefeat
	goto Route113_EventScript_GiftedSlowbroniteG
	release
	end

Route113_EventScript_GiftedSlowbroniteG:
	msgbox PacifidlogTown_Text_UseThisPowerForYourself, MSGBOX_DEFAULT
	giveitem ITEM_SLOWBRONITE_G
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route117_Text_ShowThemAll, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_SLOWBRONITE_G
	release
	end

Route113_EventScript_ReceivedSlowbroniteG:
	msgbox Route117_Text_ShowThemAll, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "The sea between PACIFIDLOG and\n"
	.string "SLATEPORT has a fast-running tide.\p"
	.string "If you decide to SURF, you could end\n"
	.string "up swept away somewhere else.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "See, isn't it neat?\n"
	.string "These houses are on water!\p"
	.string "I was born here!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "The SKY PILLAR?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in PACIFIDLOG,\n"
	.string "that suits me fine.$"

PacifidlogTown_Text_DidYouKnowAboutSlowbro:
	.string "That MEGA RING on your wrist tells\n"
	.string "me that you know about MEGA EVOLUTION.\p"
	.string "I'm sure you are aware of the fact that\n"
	.string "SLOWBRO is capable of MEGA EVOLUTION.\p"
	.string "Well, to be specific, KANTONIAN SLOWBRO\n"
	.string "can MEGA EVOLVE.\p"
	.string "There also exists GALARIAN SLOWBRO, but\n"
	.string "no records of that form MEGA EVOLVING\l"
	.string "seem to exist…\p"
	.string "Until now.$"

PacifidlogTown_Text_SlowbroGuyDefeat:
	.string "Did I getcha?$"

PacifidlogTown_Text_UseThisPowerForYourself:
	.string "Haha, sorry, I shouldn't have jumped\n"
	.string "you like that.\p"
	.string "Here, take this as an apology.\n"
	.string "Use this power for yourself!$"

Route117_Text_ShowThemAll:
	.string "Get out there and show the world that\n"
	.string "both SLOWBRO forms mean business!$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIDLOG TOWN\p"
	.string "“Where the morning sun smiles upon\n"
	.string "the waters.”$"

