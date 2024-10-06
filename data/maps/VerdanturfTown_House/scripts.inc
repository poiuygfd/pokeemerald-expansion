VerdanturfTown_House_MapScripts::
	.byte 0

VerdanturfTown_House_EventScript_Woman1::
	msgbox VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague, MSGBOX_NPC
	end

VerdanturfTown_House_EventScript_Woman2::
	msgbox VerdanturfTown_House_Text_DefeatEliteFourInARow, MSGBOX_NPC
	end

VerdanturfTown_House_EventScript_BodyPressBlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BODY_PRESS , VerdanturfTown_House_EventScript_ReceivedBodyPress
	msgbox VerdanturfTown_House_Text_OffenseDefense, MSGBOX_DEFAULT
	giveitem ITEM_TM58
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_BODY_PRESS 
	msgbox VerdanturfTown_House_Text_ExplainBodyPress, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_House_EventScript_ReceivedBodyPress::
	msgbox VerdanturfTown_House_Text_ExplainBodyPress, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague:
	.string "Far away, deep in EVER GRANDE CITY,\n"
	.string "is the POKéMON LEAGUE.\p"
	.string "The TRAINERS who gather there are\n"
	.string "all frighteningly well skilled.$"

VerdanturfTown_House_Text_DefeatEliteFourInARow:
	.string "In the POKéMON LEAGUE, I think the\n"
	.string "rules say that you have to battle the\l"
	.string "ELITE FOUR all in a row.\p"
	.string "If you lose to any of them, you have\n"
	.string "to begin your challenge again from the\l"
	.string "first one.$"

VerdanturfTown_House_Text_OffenseDefense:
	.string "Have you ever heard of the saying\n"
	.string "the best OFFENSE is a good DEFENSE?\p"
	.string "I know a move that takes this truth\n"
	.string "To the next level!\p"
	.string "Here! Give it a try yourself!$"

VerdanturfTown_House_Text_ExplainBodyPress:
	.string "TM58 contains BODY PRESS! Now you too\n"
	.string "can turn your DEFENSE into OFFENSE.$"

