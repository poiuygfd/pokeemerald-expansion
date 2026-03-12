DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_DEWFORD_NPC_TRADE_COMPLETED, DewfordTown_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_FLETCHLING, DewfordTown_House1_Text_NotManyRoundHere, DewfordTown_House1_EventScript_DeclineTrade, DewfordTown_House1_EventScript_NotRequestedMon, DewfordTown_House1_Text_PleaseBeGoodToMyPokemon
	setflag FLAG_DEWFORD_NPC_TRADE_COMPLETED
	release
	end

DewfordTown_House1_EventScript_DeclineTrade::
	msgbox DewfordTown_House1_Text_GettingColdFeet, MSGBOX_DEFAULT
	release
	end

DewfordTown_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox DewfordTown_House1_Text_DontThinkThatsRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_House1_EventScript_TradeCompleted::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	release
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "There's a lot to be said for living on\n"
	.string "a small island like this in harmony with\l"
	.string "POKéMON and the family.$"

DewfordTown_House1_Text_NotManyRoundHere:
	.string "You don't see many POKéMON on this\n"
	.string "island that don't live in the sea.\p"
	.string "I've been wanting to get a {STR_VAR_1}\n"
	.string "but they just don't live round here.\p"
	.string "If you find one, I'll trade you my\n"
	.string "{STR_VAR_2} for it.$"

DewfordTown_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Be sure to take care of Fletchling!\n"
	.string "And I'll take good care of Taillow!$"

DewfordTown_House1_Text_DontThinkThatsRight:
	.string "Hmm…\n"
	.string "That doesn't seem quite right to me…$"

DewfordTown_House1_Text_GettingColdFeet:
	.string "Getting cold feet?\n"
	.string "If you change your mind, let me know.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "I left the major port of SLATEPORT\n"
	.string "CITY when I married my husband here.\p"
	.string "Life goes by slowly on this little\n"
	.string "island. But being surrounded by the\l"
	.string "beautiful sea--that's happiness, too.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"

