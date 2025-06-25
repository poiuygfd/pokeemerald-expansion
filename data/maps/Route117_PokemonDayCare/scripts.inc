Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_Man::
	msgbox Route117_PokemonDayCare_Text_NotVeryStrongTrainer, MSGBOX_NPC
	end

Route117_PokemonDayCare_EventScript_OvalCharmGirl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OVAL_CHARM, Route117_PokemonDayCare_EventScript_ReceivedOvalCharm
	msgbox Route117_PokemonDayCare_Text_EasierToFindEggs, MSGBOX_DEFAULT
	giveitem ITEM_OVAL_CHARM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_OVAL_CHARM
	msgbox Route117_PokemonDayCare_Text_ExplainOvalCharm, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_ReceivedOvalCharm::
	msgbox Route117_PokemonDayCare_Text_ExplainOvalCharm, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Text_NotVeryStrongTrainer:
	.string "I love my POKéMON, but I'm not a\n"
	.string "very strong TRAINER.\p"
	.string "But that's okay, because the DAY CARE\n"
	.string "can raise my POKéMON for me!$"

Route117_PokemonDayCare_Text_EasierToFindEggs:
	.string "Did you know?\n"
	.string "There's actually a mysterious item that\l"
	.string "makes you more likely to find EGGs when\l"
	.string "you visit the DAY CARE.\p"
	.string "And I happen to have this item on me!\p"
	.string "Here! A gift for you!$"

Route117_PokemonDayCare_Text_ExplainOvalCharm:
	.string "The OVAL CHARM will make you more\n"
	.string "likely to find EGGs from the DAY CARE.$"
