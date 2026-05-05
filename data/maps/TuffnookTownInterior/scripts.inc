TuffnookTownInterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TuffnookTownInterior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TuffnookTownInterior_OnFrame
	.byte 0

TuffnookTownInterior_OnTransition:
	call_if_eq VAR_TUFFNOOK_TOWN_STATE, 3, TuffnookTownInterior_EventScript_MoveProfToCave
	end

TuffnookTownInterior_EventScript_MoveProfToCave::
	setobjectxyperm LOCALID_TUFFNOOK_BIRCH, 20, 4
	setobjectmovementtype LOCALID_TUFFNOOK_BIRCH, MOVEMENT_TYPE_FACE_UP
	return

TuffnookTownInterior_OnFrame:
	map_script_2 VAR_TUFFNOOK_TOWN_STATE, 1, TuffnookTownInterior_EventScript_BirchGiveCatchCharm
	map_script_2 VAR_TUFFNOOK_TOWN_STATE, 3, TuffnookTownInterior_EventScript_BirchSayGoodbye
	.2byte 0

TuffnookTownInterior_EventScript_BirchGiveCatchCharm::
	lockall
	msgbox TuffnookTownInterior_Text_BirchOverHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TuffnookTownInterior_Movement_PlayerApproachBirch
	waitmovement 0
	msgbox TuffnookTownInterior_Text_BirchHowHaveYouBeen, MSGBOX_DEFAULT
	giveitem ITEM_CATCHING_CHARM
	msgbox TuffnookTownInterior_Text_BirchCatchingCharmGift, MSGBOX_DEFAULT
	closemessage
	goto TuffnookTownInterior_EventScript_TeamAquaAppears
	end

TuffnookTownInterior_EventScript_TeamAquaAppears::
	msgbox TuffnookTownInterior_Text_AlrightTeamMoveOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_TUFFNOOK_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_TUFFNOOK_BIRCH, Common_Movement_FaceDown
	playse SE_PIN
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	addobject LOCALID_TUFFNOOK_MATT
	addobject LOCALID_TUFFNOOK_GRUNT_1
	addobject LOCALID_TUFFNOOK_GRUNT_2
	addobject LOCALID_TUFFNOOK_GRUNT_3
	addobject LOCALID_TUFFNOOK_GRUNT_4
	applymovement LOCALID_TUFFNOOK_MATT, TuffnookTownInterior_Movement_AquaEnters1
	applymovement LOCALID_TUFFNOOK_GRUNT_1, TuffnookTownInterior_Movement_AquaEnters2
	applymovement LOCALID_TUFFNOOK_GRUNT_2, TuffnookTownInterior_Movement_AquaEnters3
	applymovement LOCALID_TUFFNOOK_GRUNT_3, TuffnookTownInterior_Movement_AquaEnters4
	applymovement LOCALID_TUFFNOOK_GRUNT_4, TuffnookTownInterior_Movement_AquaEnters5
	waitmovement 0
	removeobject LOCALID_TUFFNOOK_MATT
	removeobject LOCALID_TUFFNOOK_GRUNT_1
	removeobject LOCALID_TUFFNOOK_GRUNT_2
	removeobject LOCALID_TUFFNOOK_GRUNT_3
	removeobject LOCALID_TUFFNOOK_GRUNT_4
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_TUFFNOOK_BIRCH, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	applymovement LOCALID_TUFFNOOK_BIRCH, Common_Movement_FaceDown
	waitmovement 0
	msgbox TuffnookTownInterior_Text_WhatOnEarthWasThat, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	setvar VAR_TUFFNOOK_TOWN_STATE, 2
	release
	end

TuffnookTownInterior_EventScript_Birch::
	msgbox TuffnookTownInterior_Text_GoAfterThem, MSGBOX_NPC
	end

TuffnookTownInterior_Movement_PlayerApproachBirch:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TuffnookTownInterior_Movement_AquaEnters1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

TuffnookTownInterior_Movement_AquaEnters2:
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

TuffnookTownInterior_Movement_AquaEnters3:
	delay_8
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

TuffnookTownInterior_Movement_AquaEnters4:
	delay_8
	delay_8
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

TuffnookTownInterior_Movement_AquaEnters5:
	delay_8
	delay_8
	delay_8
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

TuffnookTownInterior_EventScript_BirchSayGoodbye::
	lock
	msgbox TuffnookTownInterior_Text_TakeCarePlayer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TUFFNOOK_BIRCH, TuffnookTownInterior_Movement_BirchLeave
	waitmovement 0
	removeobject LOCALID_TUFFNOOK_BIRCH
	setvar VAR_TUFFNOOK_TOWN_STATE, 4
	release
	end

TuffnookTownInterior_Movement_BirchLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

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
	goto_if_unset FLAG_HIDE_NAVEL_ROCK_TEAM_AQUA, TuffnookTownInterior_EventScript_WhoWasThat
	msgbox TuffnookTownInterior_Text_ScaryCave, MSGBOX_NPC
	end

TuffnookTownInterior_EventScript_WhoWasThat::
	msgbox TuffnookTownInterior_Text_WeirdPirates, MSGBOX_NPC
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

TuffnookTownInterior_Text_WeirdPirates:
	.string "Who were those guys?\n"
	.string "They were dressed like weird pirates!\p"
	.string "Don't they know that there have been\n"
	.string "reports of some terrifyingly dangerous\l"
	.string "POKéMON found in that cave?$"

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

TuffnookTownInterior_Text_BirchOverHere:
	.string "{PLAYER}! Over here!$"

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
	.string "I'll see you around…$"

TuffnookTownInterior_Text_AlrightTeamMoveOut:
	.string "Alright, team!\n"
	.string "Move out!$"

TuffnookTownInterior_Text_WhatOnEarthWasThat:
	.string "PROF. BIRCH: What on earth was that?\n"
	.string "Was that TEAM AQUA who stormed past?\p"
	.string "I don't know what TEAM AQUA is up to\n"
	.string "here of all places, but I have a bad\l"
	.string "feeling about this.\p"
	.string "Sorry to ask, {PLAYER}, but could you\n"
	.string "go after them?\p"
	.string "I'm not really a TRAINER, so I don't\n"
	.string "think I could do much to stop them.\p"
	.string "If it looks dangerous, though, then\n"
	.string "please don't get in over your head!$"

TuffnookTownInterior_Text_GoAfterThem:
	.string "PROF. BIRCH: Could you go after\n"
	.string "them, {PLAYER}?\p"
	.string "I'm not really a TRAINER, so I don't\n"
	.string "think I could do much to stop them.\p"
	.string "If it looks dangerous, though, then\n"
	.string "please don't get in over your head!$"

TuffnookTownInterior_Text_TakeCarePlayer:
	.string "PROF. BIRCH: I just saw TEAM AQUA\n"
	.string "storm past, did everything go okay?\p"
	.string "Ah, you managed to chase them off!\n"
	.string "That's very impressive, {PLAYER}!\l"
	.string "You're really getting strong!\p"
	.string "With strength like that, you might\n"
	.string "even be able to take on your DAD\l"
	.string "back in PETALBURG!\p"
	.string "If you decide to go for it, then I\n"
	.string "shall wish you the best of luck!\p"
	.string "For now though, I should be off.\n"
	.string "Until next time!$"

TuffnookTownInterior_Text_TownSign:
	.string "TUFFNOOK TOWN\p"
	.string "“A community as solid as stone\n"
	.string "and as hardy as our homes.”$"

TuffnookTownInterior_Text_GavinsGemsSign:
	.string "A crudely carved out sign which\n"
	.string "seems to be for some kind of store.\p"
	.string "You can barely make out the text\n"
	.string "which seems to say “GAVIN'S GEMS”.$"
