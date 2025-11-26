Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_DELIVERED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_DeliveredMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_ARequestFromDevon, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_PARCEL
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_MACHO_BRACE
	msgbox Route111_WinstrateFamilysHouse_Text_ThankYouForDelivering, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_DeliveredMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_ThisMachoBrace, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_DELIVERED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_SpeakWithMyDaughter, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "You're the first TRAINER I've seen who\n"
	.string "deploys POKéMON so masterfully.\p"
	.string "But, I should tell you--my son is\n"
	.string "stronger than you.\p"
	.string "He even took the POKéMON LEAGUE\n"
	.string "challenge, I'll have you know.$"


Route111_WinstrateFamilysHouse_Text_ARequestFromDevon:
	.string "What's that?\n"
	.string "A parcel from DEVOP CORP?\p"
	.string "Ah! This is the MACHO BRACE we ordered!\n"
	.string "Thank you for delivering this to us!\p"
	.string "This should help our family train and\n"
	.string "become even stronger!$"

Route111_WinstrateFamilysHouse_Text_ThankYouForDelivering:
	.string "Oh, right, here, take this!\p"
	.string "You deserve a little something for\n"
	.string "delivering this to us!\p"
	.string "This here is a HM for the move\n"
	.string "ROCK SMASH.\p"
	.string "As long as you have defeated the GYM\n"
	.string "LEADER of MAUVILLE, you can use it\l"
	.string "to break any cracked boulders.$"

Route111_WinstrateFamilysHouse_Text_ThisMachoBrace:
	.string "This MACHO BRACE that DEVON made…\p"
	.string "It seems like a great tool for\n"
	.string "training POKéMON!\p"
	.string "I'll have to give them my thanks!$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mommy is stronger than Daddy.\p"
	.string "I'm stronger than Mommy.\p"
	.string "And Grandma's stronger than me!\p"
	.string "But my big brother is even stronger\n"
	.string "than Grandma.$"

Route111_WinstrateFamilysHouse_Text_SpeakWithMyDaughter:
	.string "I believe my daughter was the one\n"
	.string "who ordered that PARCEL.\p"
	.string "You best hand that over to her, not\n"
	.string "to me.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "There's no question that you're strong.\p"
	.string "But if you were to battle my grandson,\n"
	.string "you'd end up crying in frustration.\p"
	.string "He's much stronger than any TRAINER\n"
	.string "our family knows.\p"
	.string "He must be challenging the POKéMON\n"
	.string "LEAGUE CHAMPION by now.\p"
	.string "Knowing my grandson, he could be the\n"
	.string "CHAMPION already!$"

