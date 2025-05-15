Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE_111_NPC_TRADE_COMPLETED, Route111_OldLadysRestStop_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MUNCHLAX
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Route111_OldLadysRestStop_Text_CanBeFoundInTheDesert, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route111_OldLadysRestStop_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, Route111_OldLadysRestStop_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Route111_OldLadysRestStop_Text_ExcessiveHype, MSGBOX_DEFAULT
	setflag FLAG_ROUTE_111_NPC_TRADE_COMPLETED
	release
	end

Route111_OldLadysRestStop_EventScript_DeclineTrade::
	msgbox Route111_OldLadysRestStop_Text_AlasIfOnly, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route111_OldLadysRestStop_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_EventScript_TradeCompleted::
	msgbox Route111_OldLadysRestStop_Text_UnlikelyToMe, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Oh, dear, dear.\n"
	.string "Aren't your POKéMON exhausted?\p"
	.string "If you'd like, rest up here.\n"
	.string "That's a fine idea! You should do that.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "That's right.\n"
	.string "Take your time and rest up!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Oh, dear, dear.\n"
	.string "Are your POKéMON still tired?\p"
	.string "You should take another rest here.\n"
	.string "That's a fine idea. You should do that.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Is that so?\n"
	.string "You don't need to be shy about it.$"

Route111_OldLadysRestStop_Text_CanBeFoundInTheDesert:
	.string "Have you heard?\p"
	.string "Apparently, a POKéMON called {STR_VAR_1}\n"
	.string "can be found in the desert just south.\p"
	.string "And yet, no matter how hard I look,\n"
	.string "I just can't seem to find one!\p"
	.string "Please! If you can find one, I'll\n"
	.string "trade you a {STR_VAR_2} for it!$"

Route111_OldLadysRestStop_Text_ExcessiveHype:
	.string "Yes! YES!!\n"
	.string "Finally, a Sigilyph of my own!$"

Route111_OldLadysRestStop_Text_DoesntLookLikeMonToMe:
	.string "That doesn't look like a {STR_VAR_1}\n"
	.string "to me… Are you pulling my leg?$"

Route111_OldLadysRestStop_Text_AlasIfOnly:
	.string "Alas, I suppose if they were that easy\n"
	.string "to find, I'd already have one…$"

Route111_OldLadysRestStop_Text_UnlikelyToMe:
	.string "Somebody told me that they saw a\n"
	.string "big, ghostly tower in the desert.\p"
	.string "That sounds pretty unlikely to me!$"

