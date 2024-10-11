FortreeCity_House3_MapScripts::
	.byte 0

FortreeCity_House3_EventScript_Maniac::
	msgbox FortreeCity_House3_Text_MetStevenHadAmazingPokemon, MSGBOX_NPC
	end

FortreeCity_House3_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_RAZOR_CLAW, FortreeCity_House3_EventScript_ReceivedRazorClaw
	msgbox FortreeCity_House3_Text_OhYouHavePokedex, MSGBOX_DEFAULT
	giveitem ITEM_RAZOR_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_RAZOR_CLAW
	release
	end

FortreeCity_House3_EventScript_ReceivedRazorClaw::
	msgbox FortreeCity_House3_Text_IWantAPokeDexToo, MSGBOX_DEFAULT
	release
	end

FortreeCity_House3_Text_MetStevenHadAmazingPokemon:
	.string "I met this TRAINER, STEVEN, when\n"
	.string "I was searching for rare stones.\p"
	.string "Hoo, boy, he had some amazing POKéMON\n"
	.string "with him.\p"
	.string "They weren't just rare, they were\n"
	.string "trained to terrifying extremes!\p"
	.string "He might even be stronger than the\n"
	.string "GYM LEADER in this town…$"

FortreeCity_House3_Text_OhYouHavePokedex:
	.string "What's that thing you have there?\p"
	.string "… … … … … …\p"
	.string "Oh, it's called a POKéDEX?\n"
	.string "It's really awesome!$"
	.string "Thanks for showing me something so\n"
	.string "cool!\p"
	.string "Here, you can have this thing I\n"
	.string "found earlier!$"

FortreeCity_House3_Text_IWantAPokeDexToo:
	.string "One day, I'd like to be a TRAINER\n"
	.string "with my own POKéDEX too!$"

