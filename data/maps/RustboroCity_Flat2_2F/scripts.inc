RustboroCity_Flat2_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Flat2_2F_OnTransition
	.byte 0

RustboroCity_Flat2_2F_OnTransition:
	call RustboroCity_Flat2_2F_EventScript_ShowCorrectFloatStoneMan
	end

RustboroCity_Flat2_2F_EventScript_ShowCorrectFloatStoneMan::
	goto_if_set FLAG_RECEIVED_FLOAT_STONE, RustboroCity_Flat2_2F_EventScript_ShowLargeFloatStoneMan
	goto_if_unset FLAG_RECEIVED_FLOAT_STONE, RustboroCity_Flat2_2F_EventScript_ShowSmallFloatStoneMan
	return

RustboroCity_Flat2_2F_EventScript_ShowSmallFloatStoneMan::
	clearflag FLAG_HIDE_FLOAT_STONE_MAN_1
	setflag FLAG_HIDE_FLOAT_STONE_MAN_2
	return

RustboroCity_Flat2_2F_EventScript_ShowLargeFloatStoneMan::
	setflag FLAG_HIDE_FLOAT_STONE_MAN_1
	clearflag FLAG_HIDE_FLOAT_STONE_MAN_2
	return

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_EventScript_FloatStoneMan1::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FLOAT_STONE, RustboroCity_Flat2_2F_EventScript_FloatStoneMan1Received
	msgbox RustboroCity_Flat2_2F_Text_MyDadsARealAce, MSGBOX_DEFAULT
	giveitem ITEM_FLOAT_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FLOAT_STONE
	msgbox RustboroCity_Flat2_2F_Text_FloatStoneExplanation, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_EventScript_FloatStoneMan1Received::
	msgbox RustboroCity_Flat2_2F_Text_FloatStoneExplanation, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_EventScript_FloatStoneMan2::
	msgbox RustboroCity_Flat2_2F_Text_PutOnWeight, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "Way back in the old days, DEVON was just\n"
	.string "a teeny, tiny company.$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "My daddy's working at the CORPORATION.\p"
	.string "My daddy made this!\n"
	.string "But I can't use it, so you can have it.$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "My daddy's working at the CORPORATION.\p"
	.string "When I grow up, I'm going to work for\n"
	.string "DEVON, too.$"

RustboroCity_Flat2_2F_Text_MyDadsARealAce:
	.string "My dad is a real ace in the DEVON CORP\n"
	.string "I'll have you know!\l"
	.string "It's no wonder I'm an ace myself!\p"
	.string "Here. I'll give you something that an\n"
	.string "ace TRAINER like me uses!$"

RustboroCity_Flat2_2F_Text_FloatStoneExplanation:
	.string "If you have a POKéMON hold a FLOAT\n"
	.string "STONE, its weight will be halved.\p"
	.string "Although it looks like it will be a\n"
	.string "while before you can use something like\l"
	.string "this as well as I can.$"

RustboroCity_Flat2_2F_Text_PutOnWeight:
	.string "…\p"
	.string "For some reason, I've put on a lot\n"
	.string "of weight recently…$"
