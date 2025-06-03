TuffnookTownExterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TuffnookTownExterior_OnTransition
	.byte 0

TuffnookTownExterior_OnTransition:
	setflag FLAG_VISITED_TUFFNOOK_TOWN
	end

TuffnookTownExterior_EventScript_Man::
	msgbox TuffnookTownExterior_Text_ThisTownIsFascinating, MSGBOX_NPC
	end

TuffnookTownExterior_Text_ThisTownIsFascinating:
	.string "This town is truly fascinating!\p"
	.string "It appears that long ago, the people of\n"
	.string "this desert carved into that softer\l"
	.string "white rock over there to protect them\l"
	.string "from the harsh sandstorm.\p"
	.string "Nowadays, an entire settlement has\n"
	.string "established themselves here!$"
