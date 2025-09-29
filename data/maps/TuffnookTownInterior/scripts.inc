TuffnookTownInterior_MapScripts::
	.byte 0

TuffnookTownInterior_EventScript_Girl::
	msgbox TuffnookTownInterior_Text_LiveInACave, MSGBOX_NPC
	end

TuffnookTownInterior_EventScript_Boy::
	msgbox TuffnookTownInterior_Text_YoudBeSurprised, MSGBOX_NPC
	end

TuffnookTownInterior_EventScript_YoungBoy::
	lock
	faceplayer
	msgbox TuffnookTownInterior_Text_RockPaperScissors, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

TuffnookTownInterior_EventScript_YoungGirl::
	lock
	faceplayer
	msgbox TuffnookTownInterior_Text_IWillNotYield, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

TuffnookTownInterior_EventScript_Lass::
	msgbox TuffnookTownInterior_Text_ScaryCave, MSGBOX_NPC
	end

TuffnookTownInterior_EventScript_OldMan::
	msgbox TuffnookTownInterior_Text_LivedHereAllMyLife, MSGBOX_NPC
	end

TuffnookTownInterior_EventScript_Camper::
	msgbox TuffnookTownInterior_Text_ThatShopOverThere, MSGBOX_NPC
	end

TuffnookTownInterior_EventScript_PowerUpPunchMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWER_UP_PUNCH , TuffnookTownInterior_EventScript_ReceivedPowerUpPunch
	msgbox TuffnookTownInterior_Text_BaneOfWalls, MSGBOX_DEFAULT
	giveitem ITEM_TM_POWER_UP_PUNCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_POWER_UP_PUNCH
	msgbox TuffnookTownInterior_Text_PowerUpPunchExplanation, MSGBOX_DEFAULT
	applymovement LOCALID_TUFFNOOK_BLACK_BELT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

TuffnookTownInterior_EventScript_ReceivedPowerUpPunch::
	msgbox TuffnookTownInterior_Text_GuysIDontThinkThisGuyIsOK, MSGBOX_DEFAULT
	applymovement LOCALID_TUFFNOOK_BLACK_BELT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

TuffnookTownInterior_EventScript_Drilbur::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRILBUR, CRY_MODE_NORMAL
	msgbox TuffnookTownInterior_Text_Drilbur, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_EventScript_ProfBirch::
	lock
	faceplayer
	msgbox TuffnookTownInterior_Text_BirchHowHaveYouBeen, MSGBOX_DEFAULT
	giveitem ITEM_CATCHING_CHARM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox TuffnookTownInterior_Text_BirchCatchingCharmGift, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, TuffnookTownInterior_EventScript_BirchLeave3
	call_if_eq VAR_FACING, DIR_NORTH, TuffnookTownInterior_EventScript_BirchLeave2
	call_if_eq VAR_FACING, DIR_EAST, TuffnookTownInterior_EventScript_BirchLeave
	call_if_eq VAR_FACING, DIR_WEST, TuffnookTownInterior_EventScript_BirchLeave
	setflag FLAG_BIRCH_TUFFNOOK_TALKED_TO
	removeobject LOCALID_TUFFNOOK_BIRCH
	release
	end

TuffnookTownInterior_EventScript_BirchLeave::
	applymovement LOCALID_PLAYER, TuffnookTownInterior_Movement_PlayerWatchBirchExit
	applymovement LOCALID_TUFFNOOK_BIRCH, TuffnookTownInterior_Movement_BirchLeave
	waitmovement 0
	return

TuffnookTownInterior_EventScript_BirchLeave2::
	applymovement LOCALID_PLAYER, TuffnookTownInterior_Movement_PlayerWatchBirchExit
	applymovement LOCALID_TUFFNOOK_BIRCH, TuffnookTownInterior_Movement_BirchLeave2
	waitmovement 0
	return

TuffnookTownInterior_EventScript_BirchLeave3::
	applymovement LOCALID_TUFFNOOK_BIRCH, TuffnookTownInterior_Movement_BirchLeave
	waitmovement 0
	return

TuffnookTownInterior_Movement_PlayerWatchBirchExit:
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

TuffnookTownInterior_Movement_BirchLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

TuffnookTownInterior_Movement_BirchLeave2:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

TuffnookTownInterior_EventScript_TownSign::
	msgbox TuffnookTownInterior_Text_TownSign, MSGBOX_SIGN
	end

TuffnookTownInterior_EventScript_GavinsGemsSign::
	msgbox TuffnookTownInterior_Text_GavinsGemsSign, MSGBOX_SIGN
	end

TuffnookTownInterior_Text_LiveInACave:
	.string "Living here is an interesting experience.\n"
	.string "There's not many other places you get to\l"
	.string "live in a cave like this!$"

TuffnookTownInterior_Text_YoudBeSurprised:
	.string "You'd be surprised how cool it can be\n"
	.string "in here despite being in the middle\l"
	.string "of a desert.\p"
	.string "We get a lot of travelers stopping by\n"
	.string "to take a break from the desert heat.$"

TuffnookTownInterior_Text_RockPaperScissors:
	.string "We're playing rock-paper-scissors!\p"
	.string "The only problem is that we both keep\n"
	.string "throwing rock every time.\p"
	.string "We've been at this for two hours…$"

TuffnookTownInterior_Text_IWillNotYield:
	.string "I WILL NOT YIELD!$"

TuffnookTownInterior_Text_ScaryCave:
	.string "This cave up ahead is used as a\n"
	.string "mining ground for us.\p"
	.string "Our main export to the rest of the\n"
	.string "region is the rare minerals and gems\l"
	.string "found in the rock here.\p"
	.string "But recently, we stumbled upon some\n"
	.string "POKéMON of terrifying strength.\p"
	.string "Because of that, most people have\n"
	.string "been too scared to enter the cave…$"

TuffnookTownInterior_Text_LivedHereAllMyLife:
	.string "I've lived here all me life!\p"
	.string "Back in my day, the people of the desert\n"
	.string "dug out this cave out of desparation.\p"
	.string "We were caught in a particularly bad\n"
	.string "sandstorm, and people were getting\l"
	.string "hurt by the day!\p"
	.string "Since then, we've further hollowed out\n"
	.string "and fully moved into this cave.\p"
	.string "We've even carved out a niche in some\n"
	.string "mining exports ye can't get anywhere\l"
	.string "else in HOENN!\p"
	.string "Hmm? What was that, young'un?\n"
	.string "Why didn't we just… leave the desert…?\p"
	.string "Gya ha ha! I guess we always were a\n"
	.string "stubborn bunch!$"

TuffnookTownInterior_Text_ThatShopOverThere:
	.string "That shop over there sells some very\n"
	.string "pretty and cleanly cut gemstones.\p"
	.string "Problem is though…\n"
	.string "They are ridiculously expensive!\p"
	.string "I guess gemstones are just expensive…\p"
	.string "But I don't think that man gets very\n"
	.string "much business as a result…$"

TuffnookTownInterior_Text_BaneOfWalls:
	.string "NO WALL CAN WITHSTAND MY MIGHT!\p"
	.string "THE WEAK, SOFT ROCK HERE IS PERFECT\n"
	.string "FOR TRAINING MY FISTS!\p"
	.string "WITH EVERY PUNCH, I BECOME STRONGER!\p"
	.string "TAKE THIS!$"

TuffnookTownInterior_Text_PowerUpPunchExplanation:
	.string "WITH THIS, YOUR POKéMON CAN ALSO\n"
	.string "BECOME STRONGER WITH EVERY PUNCH!$"

TuffnookTownInterior_Text_GuysIDontThinkThisGuyIsOK:
	.string "ORA ORA ORA ORA ORA ORA\n"
	.string "ORA ORA ORA ORA ORA ORA\p"
	.string "I HAVE THE FISTS OF A GOD!!!$"

TuffnookTownInterior_Text_Drilbur:
	.string "DRILBUR: Dri dri!$"

TuffnookTownInterior_Text_BirchHowHaveYouBeen:
	.string "PROF. BIRCH: {PLAYER}{KUN}!\n"
	.string "How have you been doing?\p"
	.string "I had {RIVAL} tell you to find\n"
	.string "me because I have a present for you!$"

TuffnookTownInterior_Text_BirchCatchingCharmGift:
	.string "That there is a CATCHING CHARM.\n"
	.string "Just holding onto one of those will\l"
	.string "make it easier to catch wild POKéMON.\p"
	.string "That should help you fill out your\n"
	.string "POKéDEX even faster than before!\p"
	.string "Well, it's been nice catching up with\n"
	.string "you, but I should be returning to my\l"
	.string "LAB soon.\p"
	.string "Come stop by whenever you want to show\n"
	.string "me how your POKéDEX is coming along!\p"
	.string "I'm assuming you'll be heading back\n"
	.string "to PETALBURG for your father's GYM\l"
	.string "BAADGE soon, so I wish you good luck!$"

TuffnookTownInterior_Text_TownSign:
	.string "TUFFNOOK TOWN\p"
	.string "“A community as solid as stone\n"
	.string "and as hardy as our homes.”$"

TuffnookTownInterior_Text_GavinsGemsSign:
	.string "A crudely carved out sign which\n"
	.string "seems to be for some kind of store.\p"
	.string "You can barely make out the text\n"
	.string "which seems to say “GAVIN'S GEMS”.$"
