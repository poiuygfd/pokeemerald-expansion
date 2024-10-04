SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "How did you manage to get here without\n"
	.string "a submarine?\l"
	.string "What an impressive child!\p"
	.string "But… It won't do to have you\n"
	.string "meddling about here.\p"
	.string "And, I do want payback for what\n"
	.string "happened at the WEATHER INSTITUTE…\p"
	.string "I'm going to give you a little taste\n"
	.string "of pain! Resign yourself to it!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Ouch!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha!\n"
	.string "You're so darn strong.\p"
	.string "It's terribly disappointing that you're\n"
	.string "not a TEAM AQUA member.\p"
	.string "You could have enjoyed the fabulous\n"
	.string "world our BOSS has promised as\l"
	.string "one of us…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Who on earth- Bwuh?!\p"
	.string "Of all the people to run into under the\n"
	.string "literal ocean, of course it's you!\p"
	.string "After you thwarted me in the PETALBURG\n"
	.string "WOODS, and then stole the parts from me\l"
	.string "in RUSTURF TUNNEL, I thought it was over!\p"
	.string "But no, after finally being trusted with\n"
	.string "an important mission after my previous\l"
	.string "failures, of course you would show up!\p"
	.string "Well things are going to be different\n"
	.string "this time! Just you see!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah! Not again!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Darn it! What is it that makes you\n"
	.string "insist on getting in our way?\p"
	.string "Maybe I'm just not cut out for this\n"
	.string "job…\p"
	.string "When this mission is over, I'm going\n"
	.string "to just get a job at the POKé MART…$"

