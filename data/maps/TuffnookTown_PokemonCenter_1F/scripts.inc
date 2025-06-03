TuffnookTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TuffnookTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

TuffnookTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_TUFFNOOK_TOWN
	end

TuffnookTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TUFFNOOK_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TuffnookTown_PokemonCenter_1F_EventScript_Man::
	msgbox TuffnookTown_PokemonCenter_1F_Text_MyNewSong, MSGBOX_NPC
	end

TuffnookTown_PokemonCenter_1F_EventScript_Boy::
	msgbox TuffnookTown_PokemonCenter_1F_Text_ARealLifeSaver, MSGBOX_NPC
	end

TuffnookTown_PokemonCenter_1F_Text_MyNewSong:
	.string "I just can't seem to get my new song\n"
	.string "to sound the way I want it to…\p"
	.string "Well, at least I'm having fun trying\n"
	.string "so that's what matters most!$"

TuffnookTown_PokemonCenter_1F_Text_ARealLifeSaver:
	.string "This place is seriously a life saver…\p"
	.string "I thought me and my POKéMON were done\n"
	.string "for out in the desert, but who would\l"
	.string "have thought there would be a\l"
	.string "POKéMON CENTER somewhere like this!$"
