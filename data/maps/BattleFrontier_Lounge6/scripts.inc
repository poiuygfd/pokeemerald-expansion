BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_TraderLeaf::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompletedLeaf
	setvar VAR_0x8008, INGAME_TRADE_EEVEE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_NiceToSeeYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTradeLeaf
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTradeLeaf
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_TakeCareOfEevee, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_TraderRed::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE2_DONE, BattleFrontier_Lounge6_EventScript_TradeCompletedRed
	setvar VAR_0x8008, INGAME_TRADE_PIKACHU
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_RedGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTradeRed
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTradeRed
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_RedAfterTrade, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE2_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTradeLeaf::
	msgbox BattleFrontier_Lounge6_Text_LeafCancelTrade, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTradeRed::
	msgbox BattleFrontier_Lounge6_Text_RedDeclineTrade, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompletedLeaf::
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, BattleFrontier_Lounge6_EventScript_LeafRedPresent
	msgbox BattleFrontier_Lounge6_Text_LeafSmallTalkNoRed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_LeafRedPresent::
	msgbox BattleFrontier_Lounge6_Text_LeafSmallTalkWithRed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompletedRed::
	msgbox BattleFrontier_Lounge6_Text_RedSmallTalk, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_NiceToSeeYou:
	.string "LEAF: Oh, hey {PLAYER}!\n"
	.string "Nice to see you again!\p"
	.string "Been having a good time here at the\n"
	.string "BATTLE FRONTIER?\p"
	.string "I know I sure have!\p"
	.string "Remember how I told you last time we\n"
	.string "spoke that if you visited me then I'd\l"
	.string "trade you something nice?\p"
	.string "Well if you're still up for that, then\n"
	.string "I've got an EEVEE here to trade!\p"
	.string "This EEVEE is a bit different to normal\n"
	.string "EEVEE, it doesn't seem to be able to\l"
	.string "evolve but is stronger than your run\l"
	.string "of the mill EEVEE.\p"
	.string "I'll take anything in exchange!$"

BattleFrontier_Lounge6_Text_LeafCancelTrade:
	.string "Oh, having second thoughts?\n"
	.string "No worries, if you want to trade then\l"
	.string "you know where to find me!$"

BattleFrontier_Lounge6_Text_TakeCareOfEevee:
	.string "Thanks! You be sure to take care of\n"
	.string "that EEVEE!\p"
	.string "I'll be sure to take good care of\n"
	.string "The POKéMON you gave me too!$"

BattleFrontier_Lounge6_Text_LeafSmallTalkNoRed:
	.string "LEAF: Hey there, {PLAYER}!\n"
	.string "Nice of you to drop by!\p"
	.string "You know, I've still seen no sign of\n"
	.string "my friend RED anywhere…\p"
	.string "If you ever bump into him, send him\n"
	.string "my regards!\p"
	.string "You'll know him when you see him cause\n"
	.string "he, uh, doesn't tend to speak much and\l"
	.string "has an unmistakable red hat on.$"

BattleFrontier_Lounge6_Text_LeafSmallTalkWithRed:
	.string "LEAF: Hey there, {PLAYER}!\n"
	.string "Nice of you to drop by!\p"
	.string "So RED actually came back!\n"
	.string "I have no idea where he's been!\p"
	.string "Judging by the look in his eyes though\n"
	.string "I'm guessing this isn't your first\l"
	.string "time meeting, right?\p"
	.string "Man, I wish I coulda seen the battle\n"
	.string "between you two, no doubt it was\l"
	.string "an intense one!$"

BattleFrontier_Lounge6_Text_RedGreeting:
	.string "RED: … … …$"

BattleFrontier_Lounge6_Text_RedDeclineTrade:
	.string "… … …$"

BattleFrontier_Lounge6_Text_RedAfterTrade:
	.string "… … …!$"

BattleFrontier_Lounge6_Text_RedSmallTalk:
	.string "RED: … … …$"

