SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	call SlateportCity_PokemonCenter_1F_EventScript_ShowOrHideMetronomeMan
	end

SlateportCity_PokemonCenter_1F_EventScript_ShowOrHideMetronomeMan::
	goto_if_unset FLAG_BADGE02_GET, SlateportCity_PokemonCenter_1F_EventScript_HideMetronomeMan
	clearflag FLAG_HIDE_SLATEPORT_METRONOME_MAN
	return

SlateportCity_PokemonCenter_1F_EventScript_HideMetronomeMan::
	setflag FLAG_HIDE_SLATEPORT_METRONOME_MAN
	return

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_MetronomeMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_METRONOME, SlateportCity_PokemonCenter_1F_EventScript_MetronomeReceived
	msgbox SlateportCity_PokemonCenter_1F_Text_WorldClassMusician, MSGBOX_DEFAULT
	giveitem ITEM_METRONOME
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_METRONOME
	msgbox SlateportCity_PokemonCenter_1F_Text_MusicianTips, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_MetronomeReceived::
	msgbox SlateportCity_PokemonCenter_1F_Text_MusicianTips, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Want a tip for battling?\p"
	.string "I'd say it's raising different kinds\n"
	.string "of POKéMON in a balanced manner.\p"
	.string "It's no good to make just one\n"
	.string "POKéMON strong.\p"
	.string "If it has a type disadvantage,\n"
	.string "it might not stand a chance.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "I trade POKéMON with my friends.\p"
	.string "If a traded POKéMON is holding an\n"
	.string "item, it makes me twice as happy!$"

SlateportCity_PokemonCenter_1F_Text_WorldClassMusician:
	.string "Heh, I know why it is you talked\n"
	.string "to me.\p"
	.string "I suppose there is no hiding it.\n"
	.string "I am a world class musician after all,\l"
	.string "I knew I'd get recognised eventually.\p"
	.string "Huh? You have no idea who I am?\p"
	.string "Oh.\p"
	.string "Well, uh, why did you talk to me then?\p"
	.string "Maybe you could tell I was a world class\n"
	.string "musician even if you don't know me, and\l"
	.string "were overcome with the desire to ask\l"
	.string "me for music tips!\p"
	.string "Well, what can I do!\n"
	.string "It's natural for a world class musician\l"
	.string "to help out struggling newcomers.\p"
	.string "For starters, take one of these.$"

SlateportCity_PokemonCenter_1F_Text_MusicianTips:
	.string "Those things are great for keeping a\n"
	.string "steady tempo.\p"
	.string "Repetition is important while using it!\p"
	.string "If you want any more tips, you can find\n"
	.string "my music tutorial series on PokéTube.$"
