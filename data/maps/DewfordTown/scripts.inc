DewfordTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DewfordTown_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	.byte 0

DewfordTown_OnTransition:
	setflag FLAG_VISITED_DEWFORD_TOWN
	call_if_eq VAR_BOARD_BRINEY_BOAT_STATE, 1, DewfordTown_EventScript_SetBrineyPos
	call_if_eq VAR_DEWFORD_TOWN_STATE, 0, DewfordTown_EventScript_CheckArrivalState
	end

DewfordTown_EventScript_SetBrineyPos:
	setobjectxyperm LOCALID_DEWFORD_BRINEY, 13, 9
	return

DewfordTown_EventScript_CheckArrivalState:
	call_if_set FLAG_HIDE_DEWFORD_TOWN_TENTACOOL, DewfordTown_EventScript_SetArrivalPostTentacool
	call_if_unset FLAG_BRINEY_STEERING_BOAT, DewfordTown_EventScript_SetArrivalState
	return

DewfordTown_EventScript_SetArrivalState:
	setvar VAR_DEWFORD_TOWN_STATE, 1
	return

DewfordTown_EventScript_SetArrivalPostTentacool:
	setvar VAR_DEWFORD_TOWN_STATE, 2
	return

DewfordTown_OnFrame:
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, DewfordTown_EventScript_StartSailing
	map_script_2 VAR_DEWFORD_TOWN_STATE, 1, DewfordTown_EventScript_BrineyFirstTimeLand
	.2byte 0

DewfordTown_EventScript_StartSailing::
	lockall
	goto DewfordTown_EventScript_Sailing
	end

DewfordTown_EventScript_BrineyFirstTimeLand::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox DewfordTown_Text_TentacoolInTheWay, MSGBOX_DEFAULT
	setvar VAR_DEWFORD_TOWN_STATE, 2
	release
	end

DewfordTown_EventScript_Briney::
	lock
	faceplayer
	msgbox DewfordTown_Text_ReadyToSetSail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_DeclineSailing
	goto DewfordTown_EventScript_SettingSail
	end

DewfordTown_EventScript_DeclineSailing::
	msgbox DewfordTown_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SettingSail::
	msgbox DewfordTown_Text_AnchorsAweigh, MSGBOX_DEFAULT
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	warp MAP_DEWFORD_TOWN, 12, 9
	waitstate
	releaseall
	end

DewfordTown_EventScript_Sailing::
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
	setflag FLAG_IS_PLAYER_BOATING
	setflag FLAG_BRINEY_STEERING_BOAT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	dofieldeffect FLDEFF_USE_SURF
	waitstate
	releaseall
	end

DewfordTown_EventScript_WantToLand::
	lock
	msgbox DewfordTown_Text_WantToLandHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_GetOffBoat
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 2
	release
	end

DewfordTown_EventScript_DidNotLand::
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
	end

DewfordTown_EventScript_GetOffBoat::
	clearflag FLAG_BRINEY_STEERING_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	warp MAP_DEWFORD_TOWN, 11, 9
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	waitstate
	release
	end

DewfordTown_EventScript_Woman::
	msgbox DewfordTown_Text_TinyIslandCommunity, MSGBOX_NPC
	end

DewfordTown_EventScript_TownSign::
	msgbox DewfordTown_Text_TownSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_GymSign::
	msgbox DewfordTown_Text_GymSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_HallSign::
	msgbox DewfordTown_Text_HallSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_HowsFishing
	msgbox DewfordTown_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_NotGettingItchToFish
	end

DewfordTown_EventScript_GiveOldRod::
	msgbox DewfordTown_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox DewfordTown_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_NotGettingItchToFish::
	msgbox DewfordTown_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_HowsFishing::
	message DewfordTown_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, DewfordTown_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, DewfordTown_EventScript_FishingNotSoGood
	end

DewfordTown_EventScript_FishingExcellent::
	msgbox DewfordTown_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_FishingNotSoGood::
	msgbox DewfordTown_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_ScaredySpelunker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ESCAPE_ROPE, DewfordTown_EventScript_GiftedRope
	msgbox DewfordTown_Text_SpelunkerScared, MSGBOX_DEFAULT
	giveitem ITEM_ESCAPE_ROPE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_ESCAPE_ROPE
	msgbox DewfordTown_Text_ReceivedEscapeRope, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_GiftedRope::
	msgbox DewfordTown_Text_ReceivedEscapeRope, MSGBOX_NPC
	release
	end

DewfordTown_EventScript_TrendyPhraseBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Text_XIsTheBiggestHappeningThingRight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_ConfirmTrendyPhrase
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_RejectTrendyPhrase
	end

DewfordTown_EventScript_ConfirmTrendyPhrase::
	msgbox DewfordTown_Text_YeahDefinitionOfInRightNow, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_RejectTrendyPhrase::
	msgbox DewfordTown_Text_TellMeWhatsNewAndIn, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_EventScript_GiveNewTrendyPhrase
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_EventScript_CancelNewTrendyPhrase
	end

DewfordTown_EventScript_GiveNewTrendyPhrase::
	incrementgamestat GAME_STAT_STARTED_TRENDS
	goto_if_eq VAR_0x8004, FALSE, DewfordTown_EventScript_PhraseNotTrendyEnough
	msgbox DewfordTown_Text_OfCourseIKnowAboutThat, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_CancelNewTrendyPhrase::
	msgbox DewfordTown_Text_HearOfAnyTrendsComeShareWithMe, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_PhraseNotTrendyEnough::
	msgbox DewfordTown_Text_XHuhIThinkYIsCool, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_AbraMan::
	lock
	faceplayer
	msgbox DewfordTown_Text_DoYouWishToTeleport, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_TeleportToMauville
	msgbox DewfordTown_Text_LetMeKnowIfYouChangeYourMind, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_TeleportToMauville::
	msgbox DewfordTown_Text_OffWeGo, MSGBOX_DEFAULT
	warp MAP_MAUVILLE_CITY, 26, 8
	waitstate
	release
	end

DewfordTown_EventScript_Abra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	msgbox DewfordTown_Text_Abra, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_EventScript_Tentacool::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACOOL, CRY_MODE_NORMAL
	msgbox DewfordTown_Text_Tentacool, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_Text_TinyIslandCommunity:
	.string "DEWFORD is a tiny island community.\n"
	.string "If something gets trendy here,\l"
	.string "everyone picks up on it right away.$"

DewfordTown_Text_TownSign:
	.string "DEWFORD TOWN\n"
	.string "“A tiny island in the blue sea.”$"

DewfordTown_Text_GymSign:
	.string "DEWFORD TOWN POKéMON GYM\n"
	.string "LEADER: BRAWLY\l"
	.string "“A big wave in fighting!”$"

DewfordTown_Text_HallSign:
	.string "DEWFORD HALL\n"
	.string "“Everyone's information exchange!”$"

DewfordTown_Text_BrineyLandedInDewford:
	.string "MR. BRINEY: Ahoy!\n"
	.string "We've hit land in DEWFORD!\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail again!$"

DewfordTown_Text_ReadyToSetSail:
	.string "MR. BRINEY: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Are you ready to set sail, my friend?$"

DewfordTown_Text_AnchorsAweigh:
	.string "MR. BRINEY: Anchors aweigh!\p"
	.string "PEEKO, we're setting sail, my darling!$"

DewfordTown_Text_JustTellMeWhenYouNeedToSetSail:
	.string "MR. BRINEY: You just tell me whenever\n"
	.string "you need to set sail again!$"

DewfordTown_Text_WantToLandHere:
	.string "MR. BRINEY: Did you want to\n"
	.string "land near DEWFORD?$"

DewfordTown_Text_TentacoolInTheWay:
	.string "MR. BRINEY: Hmm…\n"
	.string "This group of TENTACOOL is blocking\l"
	.string "the way forward.\p"
	.string "It seems we can't sail to SLATEPORT\n"
	.string "just yet.\p"
	.string "Perhaps a strong TRAINER such as\n"
	.string "yourself could take on the DEWFORD\l"
	.string "GYM in the mean time?$"

DewfordTown_Text_GettingItchToFish:
	.string "This is a renowned fishing spot.\n"
	.string "Are you getting the itch to fish?$"

DewfordTown_Text_GiveYouOneOfMyRods:
	.string "I hear you, and I like what\n"
	.string "you're saying!\p"
	.string "I'll give you one of my fishing RODS.$"

DewfordTown_Text_ThrowInFishingAdvice:
	.string "And, as an added bonus, I'll even throw\n"
	.string "in a little fishing advice!\p"
	.string "First, you want to face the water,\n"
	.string "then use the ROD.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull on the ROD.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your ROD\l"
	.string "to haul them in.$"

DewfordTown_Text_ThatsTooBadThen:
	.string "Oh, is that so?\n"
	.string "That's too bad, then.$"

DewfordTown_Text_HowsYourFishing:
	.string "Yo!\n"
	.string "How's your fishing?$"

DewfordTown_Text_GreatHaulInSomeBigOnes:
	.string "Is that right! That's great!\n"
	.string "Haul in some big ones!$"

DewfordTown_Text_FishingAdvice:
	.string "Oh, hey, don't get down on yourself!\n"
	.string "I'll give you a little fishing advice.\p"
	.string "First, you want to face the water,\n"
	.string "then use the ROD.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull the ROD.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your ROD\l"
	.string "to haul them in.$"

DewfordTown_Text_SpelunkerScared:
	.string "Aiiiiyyeeeeee!!!\p"
	.string "Uwoh… Sorry about that…\n"
	.string "I was just spelunking in GRANITE CAVE…\p"
	.string "But part-way through exploring, I ran\n"
	.string "into this freaky little guy with gems\l"
	.string "for eyes! Scared the life out of me!\p"
	.string "I used my ESCAPE ROPE to get out of\n"
	.string "there as fast as I could!\p"
	.string "My heart can't take any more scares like\n"
	.string "that…\p"
	.string "My days as a spelunker are over!\n"
	.string "You'll get more use out of this than me!$"

DewfordTown_Text_ReceivedEscapeRope:
	.string "I still feel sick…\n"
	.string "I'm just gonna stick to mountains…$"

DewfordTown_Text_XIsTheBiggestHappeningThingRight:
	.string "I like what's hip, happening, and trendy.\n"
	.string "I'm always checking it out.\p"
	.string "Listen, have you heard about this new\n"
	.string "“{STR_VAR_1}”?\p"
	.string "That's right!\n"
	.string "Of course you know!\p"
	.string "I mean, sheesh,\n"
	.string "“{STR_VAR_1}”…\l"
	.string "It's the hottest thing in cool!\p"
	.string "Wherever you're from,\n"
	.string "“{STR_VAR_1}”\l"
	.string "is the biggest happening thing, right?$"

DewfordTown_Text_TellMeWhatsNewAndIn:
	.string "Hunh?\n"
	.string "It's not the hip and happening thing?\p"
	.string "Well, hey, you have to tell me,\n"
	.string "what's new and what's “in”?$"

DewfordTown_Text_OfCourseIKnowAboutThat:
	.string "Hunh?\n"
	.string "“{STR_VAR_2}”?\p"
	.string "… …\p"
	.string "…Uh… Yeah! That's right!\n"
	.string "Yeah, I knew that! Knew it all along!\p"
	.string "Of course I know about that!\n"
	.string "“{STR_VAR_2},” right?\p"
	.string "Yeah, that's it, it's there!\n"
	.string "Isn't “{STR_VAR_2}”\l"
	.string "the coolest, or what?\p"
	.string "It's the hippest thing in hip.\n"
	.string "You think I'd not know about it?\p"
	.string "“{STR_VAR_1}”…\n"
	.string "It's, like, so five minutes ago.\p"
	.string "Now, “{STR_VAR_2}” is\n"
	.string "what's vital and in tune with the times!$"

DewfordTown_Text_XHuhIThinkYIsCool:
	.string "Hmm…\n"
	.string "“{STR_VAR_2},” huh?\p"
	.string "But personally, I think\n"
	.string "“{STR_VAR_1}”\l"
	.string "is what's real in cool.$"

DewfordTown_Text_HearOfAnyTrendsComeShareWithMe:
	.string "Well, if you hear of any happening new\n"
	.string "trends, come share them with me, okay?$"

DewfordTown_Text_YeahDefinitionOfInRightNow:
	.string "Yeah, absolutely right!\p"
	.string "“{STR_VAR_1}” is the\n"
	.string "definition of “in” right now.$"

DewfordTown_Text_DoYouWishToTeleport:
	.string "Looking to get off this island?\n"
	.string "Me and ABRA can take you to MAUVILLE.$"

DewfordTown_Text_OffWeGo:
	.string "Alright then!\n"
	.string "Off we go!$"

DewfordTown_Text_LetMeKnowIfYouChangeYourMind:
	.string "Want to stick around a bit longer, eh?\n"
	.string "We're here if you change your mind.$"

DewfordTown_Text_Abra:
	.string "ABRA: Braaaa…$"

DewfordTown_Text_Tentacool:
	.string "TENTACOOL: Coooool!$"
