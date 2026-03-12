TuffnookTown_House3_MapScripts::
	.byte 0

TuffnookTown_House3_EventScript_Boy::
	msgbox TuffnookTown_House3_Text_AStrangeMan, MSGBOX_NPC
	end

TuffnookTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_TUFFNOOK_NPC_TRADE_COMPLETED, TuffnookTown_House3_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MUNCHLAX, TuffnookTown_House3_Text_CanBeFoundInTheDesert, TuffnookTown_House3_EventScript_DeclineTrade, TuffnookTown_House3_EventScript_NotRequestedMon, TuffnookTown_House3_Text_ExcessiveHype
	setflag FLAG_TUFFNOOK_NPC_TRADE_COMPLETED
	release
	end

TuffnookTown_House3_EventScript_DeclineTrade::
	msgbox TuffnookTown_House3_Text_AlasIfOnly, MSGBOX_DEFAULT
	release
	end

TuffnookTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox TuffnookTown_House3_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

TuffnookTown_House3_EventScript_TradeCompleted::
	msgbox TuffnookTown_House3_Text_UnlikelyToMe, MSGBOX_DEFAULT
	release
	end

TuffnookTown_House3_Text_AStrangeMan:
	.string "Most of the people living here in\n"
	.string "TUFFNOOK TOWN were born here.\p"
	.string "I mean, it would be pretty weird for\n"
	.string "an outsider to want to come here and\l"
	.string "move into a cave, right?\p"
	.string "But I met a guy the other day, who\n"
	.string "I think was called STEVEN?\p"
	.string "He had some terrifyingly powerful\n"
	.string "POKéMON with him!\p"
	.string "But anyway, he just seemed absolutely\n"
	.string "enamored with this place, saying that\l"
	.string "he wanted to move here!\p"
	.string "What a strange man!$"

TuffnookTown_House3_Text_CanBeFoundInTheDesert:
	.string "Have you heard?\p"
	.string "Apparently, a POKéMON called {STR_VAR_1}\n"
	.string "can be found in the desert.\p"
	.string "And yet, no matter how hard I look,\n"
	.string "I just can't seem to find one!\p"
	.string "Please! If you can find one, I'll\n"
	.string "trade you a {STR_VAR_2} for it!$"

TuffnookTown_House3_Text_ExcessiveHype:
	.string "Yes! YES!!\n"
	.string "Finally, a Sigilyph of my own!$"

TuffnookTown_House3_Text_DoesntLookLikeMonToMe:
	.string "That doesn't look like a {STR_VAR_1}\n"
	.string "to me… Are you pulling my leg?$"

TuffnookTown_House3_Text_AlasIfOnly:
	.string "Alas, I suppose if they were that easy\n"
	.string "to find, I'd already have one…$"

TuffnookTown_House3_Text_UnlikelyToMe:
	.string "Somebody told me that they saw a\n"
	.string "big, ghostly tower in the desert.\p"
	.string "That sounds pretty unlikely to me!$"
