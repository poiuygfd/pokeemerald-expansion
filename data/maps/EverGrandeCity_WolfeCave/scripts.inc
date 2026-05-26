EverGrandeCity_WolfeCave_MapScripts::
	.byte 0

EverGrandeCity_WolfeCave_EventScript_WolfeGlick::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WOLFE_GLICK, EverGrandeCity_WolfeCave_EventScript_WolfeOfferTrade
	msgbox EverGrandeCity_WolfeCave_Text_WorldChampDifferece, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WOLFE, EverGrandeCity_WolfeCave_Text_WolfeDefeated
	msgbox EverGrandeCity_WolfeCave_Text_WolfePostBattle, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_WOLFE_GLICK
	release
	end

EverGrandeCity_WolfeCave_EventScript_WolfeOfferTrade::
	goto_if_set FLAG_TRADED_WOLFE_INCINEROAR, EverGrandeCity_WolfeCave_EventScript_DefeatedWolfe
	setvar VAR_0x8005, INGAME_TRADE_INCINEROAR
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox EverGrandeCity_WolfeCave_Text_WolfeOfferTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_WolfeCave_EventScript_DeclineTradeWolfe
	chooseboxmon SELECT_PC_MON_NORMAL
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EverGrandeCity_WolfeCave_EventScript_DeclineTradeWolfe
	specialvar VAR_0x800B, GetTradeSpecies
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox EverGrandeCity_WolfeCave_Text_WolfeAfterTrade, MSGBOX_DEFAULT
	setflag FLAG_TRADED_WOLFE_INCINEROAR
	release
	end

EverGrandeCity_WolfeCave_EventScript_DeclineTradeWolfe::
	msgbox EverGrandeCity_WolfeCave_Text_WolfeDeclineTrade, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_WolfeCave_EventScript_DefeatedWolfe::
	msgbox EverGrandeCity_WolfeCave_Text_WolfePostBattle, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_WolfeCave_Text_WorldChampDifferece:
	.string "I hope you're ready.\p"
	.string "Because you're about to experience\n"
	.string "the WORLD CHAMP DIFFERENCE BAYBEE!$"

EverGrandeCity_WolfeCave_Text_WolfeDefeated:
	.string "Aw, man!$"

EverGrandeCity_WolfeCave_Text_WolfePostBattle:
	.string "GGs, that was a good match.\n"
	.string "Let's have a rematch some time.$"

EverGrandeCity_WolfeCave_Text_WolfeOfferTrade:
	.string "Hey, do you wanna trade POKéMON?\n"
	.string "I've got this stupid dumb cat here\l"
	.string "thats been tormenting me for too long.\p"
	.string "I'll take anything you have, I just\n"
	.string "need someone to take this stupid cat\l"
	.string "off of my hands.$"

EverGrandeCity_WolfeCave_Text_WolfeDeclineTrade:
	.string "That's okay.\n"
	.string "I don't want this stupid cat either.$"

EverGrandeCity_WolfeCave_Text_WolfeAfterTrade:
	.string "Well, enjoy your dumb stupid cat.\n"
	.string "Thanks for taking it off my hands.$"

