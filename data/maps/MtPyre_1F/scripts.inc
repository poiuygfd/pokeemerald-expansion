MtPyre_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_1F_OnTransition
	.byte 0

MtPyre_1F_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_EventScript_RivalsTrigger0::
	lockall
	setvar VAR_0x8008, 0
	delay 15
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_WALLY, MtPyre_1F_Movement_WallyApproach0
	waitmovement 0
	msgbox MtPyre_1F_Text_WallyWhatBringsYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_PYRE_RIVAL, MtPyre_1F_Movement_RivalApproach0
	waitmovement 0
	goto MtPyre_1F_EventScript_RivalTeamup
	end

MtPyre_1F_EventScript_RivalsTrigger1::
	lockall
	setvar VAR_0x8008, 1
	delay 15
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_WALLY, MtPyre_1F_Movement_WallyApproach1
	waitmovement 0
	msgbox MtPyre_1F_Text_WallyWhatBringsYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_PYRE_RIVAL, MtPyre_1F_Movement_RivalApproach1
	waitmovement 0
	goto MtPyre_1F_EventScript_RivalTeamup
	end

MtPyre_1F_EventScript_RivalsTrigger2::
	lockall
	setvar VAR_0x8008, 2
	delay 15
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_WALLY, MtPyre_1F_Movement_WallyApproach2
	waitmovement 0
	msgbox MtPyre_1F_Text_WallyWhatBringsYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_PYRE_RIVAL, MtPyre_1F_Movement_RivalApproach2
	waitmovement 0
	goto MtPyre_1F_EventScript_RivalTeamup
	end

MtPyre_1F_EventScript_RivalTeamup::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MT_PYRE_WALLY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, MtPyre_1F_EventScript_MayGreetings
	call_if_eq VAR_RESULT, FEMALE, MtPyre_1F_EventScript_BrendanGreetings
	goto_if_eq VAR_0x8008, 0, MtPyre_1F_EventScript_RivalsExit0
	goto_if_eq VAR_0x8008, 1, MtPyre_1F_EventScript_RivalsExit1
	goto_if_eq VAR_0x8008, 2, MtPyre_1F_EventScript_RivalsExit2
	end

MtPyre_1F_EventScript_BrendanGreetings::
	msgbox MtPyre_1F_Text_BrendanNoSignOfMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_PYRE_WALLY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtPyre_1F_Text_WallyLetMeHelp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_PYRE_RIVAL, MtPyre_1F_Movement_RivalWalkUp
	waitmovement 0
	msgbox MtPyre_1F_Text_BrendanLetsSplitUp, MSGBOX_DEFAULT
	closemessage
	return

MtPyre_1F_EventScript_MayGreetings::
	msgbox MtPyre_1F_Text_MayNoSignOfMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_PYRE_WALLY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtPyre_1F_Text_WallyLetMeHelp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_PYRE_RIVAL, MtPyre_1F_Movement_RivalWalkUp
	waitmovement 0
	msgbox MtPyre_1F_Text_MayLetsSplitUp, MSGBOX_DEFAULT
	closemessage
	return

MtPyre_1F_EventScript_RivalsExit0::
	applymovement LOCALID_MT_PYRE_RIVAL, MtPyre_1F_Movement_RivalLeaves0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MT_PYRE_WALLY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MtPyre_1F_Text_WallyDoMyBest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_MT_PYRE_WALLY, MtPyre_1F_Movement_WallyLeaves0
	waitmovement 0
	removeobject LOCALID_MT_PYRE_RIVAL
	removeobject LOCALID_MT_PYRE_WALLY
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_MAGMA
	setvar VAR_MT_PYRE_STATE, 1
	releaseall
	end

MtPyre_1F_EventScript_RivalsExit1::
	applymovement LOCALID_MT_PYRE_RIVAL, MtPyre_1F_Movement_RivalLeaves1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MT_PYRE_WALLY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MtPyre_1F_Text_WallyDoMyBest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_MT_PYRE_WALLY, MtPyre_1F_Movement_WallyLeaves1
	waitmovement 0
	removeobject LOCALID_MT_PYRE_RIVAL
	removeobject LOCALID_MT_PYRE_WALLY
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_MAGMA
	setvar VAR_MT_PYRE_STATE, 1
	releaseall
	end

MtPyre_1F_EventScript_RivalsExit2::
	applymovement LOCALID_MT_PYRE_RIVAL, MtPyre_1F_Movement_RivalLeaves2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MT_PYRE_WALLY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MtPyre_1F_Text_WallyDoMyBest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MtPyre_1F_Movement_PlayerStepAside
	waitmovement 0
	applymovement LOCALID_MT_PYRE_WALLY, MtPyre_1F_Movement_WallyLeaves2
	waitmovement 0
	removeobject LOCALID_MT_PYRE_RIVAL
	removeobject LOCALID_MT_PYRE_WALLY
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_MAGMA
	setvar VAR_MT_PYRE_STATE, 1
	releaseall
	end

MtPyre_1F_Movement_WallyApproach0:
	emote_exclamation_mark
	walk_in_place_faster_down
	delay_16
	walk_down
	walk_left
	walk_in_place_down
	step_end

MtPyre_1F_Movement_WallyApproach1:
	emote_exclamation_mark
	walk_in_place_faster_down
	delay_16
	walk_down
	step_end

MtPyre_1F_Movement_WallyApproach2:
	emote_exclamation_mark
	walk_in_place_faster_down
	delay_16
	walk_down
	walk_right
	walk_in_place_down
	step_end

MtPyre_1F_Movement_RivalApproach0:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

MtPyre_1F_Movement_RivalApproach1:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

MtPyre_1F_Movement_RivalApproach2:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

MtPyre_1F_Movement_RivalWalkUp:
	walk_up
	walk_in_place_right
	step_end

MtPyre_1F_Movement_RivalLeaves0:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MtPyre_1F_Movement_RivalLeaves1:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MtPyre_1F_Movement_RivalLeaves2:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MtPyre_1F_Movement_WallyLeaves0:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_1F_Movement_WallyLeaves1:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_1F_Movement_WallyLeaves2:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_1F_Movement_PlayerStepAside:
	walk_left
	walk_in_place_right
	step_end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "All sorts of beings wander the slopes\n"
	.string "of MT. PYRE…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Have a POKéMON hold that\n"
	.string "CLEANSE TAG.\p"
	.string "It will help ward off wild POKéMON.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed POKéMON?\p"
	.string "You must care for your POKéMON a lot.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "This is the final resting place of my\n"
	.string "ZIGZAGOON. I cherished it…$"

MtPyre_1F_Text_WallyWhatBringsYouHere:
	.string "WALLY: Is that you, {PLAYER}?\n"
	.string "What brings you here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "What?\p"
	.string "TEAM AQUA and TEAM MAGMA are up\n"
	.string "to something?\p"
	.string "I was too focused to even notice\n"
	.string "them pass through!\p"
	.string "We have to do something!$"

MtPyre_1F_Text_BrendanNoSignOfMagma:
	.string "BRENDAN: Tch…\n"
	.string "No sign of TEAM MAGMA here…\p"
	.string "Oh?\n"
	.string "Is this a friend of yours, {PLAYER}?$"

MtPyre_1F_Text_MayNoSignOfMagma:
	.string "MAY: Hm…\n"
	.string "I can't see any sign of TEAM MAGMA…\p"
	.string "Oh?\n"
	.string "Do you know this boy, {PLAYER}{KUN}?$"

MtPyre_1F_Text_WallyLetMeHelp:
	.string "WALLY: My name is WALLY.\n"
	.string "{PLAYER} filled me in on what happened.\p"
	.string "If you plan on taking on TEAM AQUA and\n"
	.string "TEAM MAGMA, please let me help!\p"
	.string "TEAM AQUA, particularly, I have some\n"
	.string "personal business with.$"

MtPyre_1F_Text_BrendanLetsSplitUp:
	.string "BRENDAN: The name's BRENDAN.\n"
	.string "I have business with TEAM MAGMA.\p"
	.string "If {PLAYER} thinks you're up to it\n"
	.string "then I've got no issues.\p"
	.string "I'll check up those stairs, see if\n"
	.string "TEAM MAGMA is up there.\p"
	.string "WALLY, you head outside and check the\n"
	.string "surrounding area for TEAM AQUA.\p"
	.string "And {PLAYER}, you should head through\n"
	.string "that exit to the left and see if TEAM\l"
	.string "MAGMA has headed up the mountain.\p"
	.string "Let's try our best to put a stop to this!$"

MtPyre_1F_Text_MayLetsSplitUp:
	.string "MAY: My name is MAY.\n"
	.string "I feel the same about TEAM MAGMA.\p"
	.string "A friend of {PLAYER}{KUN} is a friend of mine.\n"
	.string "I'd be happy if you could help us out!\p"
	.string "I'm going to check upstairs for TEAM\n"
	.string "MAGMA myself.\p"
	.string "Could you look around outside for\n"
	.string "any sign of TEAM AQUA, WALLY?\p"
	.string "And {PLAYER}{KUN}, could you check up\n"
	.string "the mountain, to the left?\p"
	.string "TEAM MAGMA might have went that way\n"
	.string "instead.\p"
	.string "Let's all do our best!$"

MtPyre_1F_Text_WallyDoMyBest:
	.string "WALLY: I'll do my best!\n"
	.string "You take care, too, {PLAYER}!$"

