TuffnookTown_DepthsEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TuffnookTown_DepthsEntrance_OnWarp
	.byte 0

TuffnookTown_DepthsEntrance_OnWarp:
	map_script_2 VAR_DEPTHS_STATE, 9, TuffnookTown_DepthsEntrance_EventScript_TurnPlayerNorth
	.2byte 0

TuffnookTown_DepthsEntrance_EventScript_TurnPlayerNorth::
	clearflag FLAG_DISABLE_BAG
	turnobject LOCALID_PLAYER, DIR_NORTH
    end

TuffnookTown_DepthsEntrance_EventScript_Cooltrainer::
	msgbox TuffnookTown_DepthsEntrance_Text_PreparingForNextDive, MSGBOX_NPC
	end

TuffnookTown_DepthsEntrance_EventScript_Picnicker::
	msgbox TuffnookTown_DepthsEntrance_Text_ThisPlaceIsTough, MSGBOX_NPC
	end

TuffnookTown_DepthsEntrance_EventScript_Hiker::
	lockall
	checkitem ITEM_BATTLE_PASS
    goto_if_eq VAR_RESULT, FALSE, TuffnookTown_DepthsEntrance_EventScript_Closed
	setvar VAR_DEPTHS_STATE, 0
	setvar VAR_DEPTHS_MON_STATE, 0
	clearflag FLAG_DEPTHS_USED_HEAL
	clearflag FLAG_B6F_SPAWNED_GEMS
	message TuffnookTown_DepthsEntrance_Text_WelcomeToTheDepths
	waitmessage
	multichoice 22, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TuffnookTown_DepthsEntrance_EventScript_ChooseChallenge
	case 1, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	case 2, TuffnookTown_DepthsEntrance_EventScript_Info
	case MULTI_B_PRESSED, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	end

TuffnookTown_DepthsEntrance_EventScript_Info::
	msgbox TuffnookTown_DepthsEntrance_Text_ExplainTheDepths, MSGBOX_DEFAULT
	goto TuffnookTown_DepthsEntrance_EventScript_AskAgain
	end

TuffnookTown_DepthsEntrance_EventScript_CancelEntry::
	msgbox TuffnookTown_DepthsEntrance_Text_NotGotWhatItTakes, MSGBOX_DEFAULT
	releaseall
	end

TuffnookTown_DepthsEntrance_EventScript_AskAgain::
	message TuffnookTown_DepthsEntrance_Text_GotWhatItTakes
	waitmessage
	multichoice 22, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TuffnookTown_DepthsEntrance_EventScript_ChooseChallenge
	case 1, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	case 2, TuffnookTown_DepthsEntrance_EventScript_Info
	case MULTI_B_PRESSED, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	end

TuffnookTown_DepthsEntrance_EventScript_ChooseChallenge::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TuffnookTown_DepthsEntrance_EventScript_NotChampion
	message TuffnookTown_DepthsEntrance_Text_ChooseDifficulty
	waitmessage
	multichoice 17, 6, MULTI_DEPTHS_NORMAL_EXPERT, FALSE
	switch VAR_RESULT
	case 0, TuffnookTown_DepthsEntrance_EventScript_NormalMode
	case 1, TuffnookTown_DepthsEntrance_EventScript_ExpertMode
	case 2, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	end

TuffnookTown_DepthsEntrance_EventScript_NotChampion::
	message TuffnookTown_DepthsEntrance_Text_CantChooseDifficulty
	waitmessage
	multichoice 17, 8, MULTI_DEPTHS_NORMAL_ONLY, FALSE
	switch VAR_RESULT
	case 0, TuffnookTown_DepthsEntrance_EventScript_NormalMode
	case 1, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	end

TuffnookTown_DepthsEntrance_EventScript_NormalMode::
	msgbox TuffnookTown_DepthsEntrance_Text_GoodLuckDownThere, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	applymovement LOCALID_DEPTHS_ENTRANCE_HIKER, TuffnookTown_DepthsEntrance_Movement_HikerMove
	waitmovement 0
	releaseall
	end

TuffnookTown_DepthsEntrance_EventScript_ExpertMode::
	goto TuffnookTown_DepthsEntrance_EventScript_NormalMode
	end

TuffnookTown_DepthsEntrance_EventScript_SaveFailed::
	goto TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	end

TuffnookTown_DepthsEntrance_EventScript_Closed::
	msgbox TuffnookTown_DepthsEntrance_Text_StillGettingReady, MSGBOX_DEFAULT
	releaseall
	end

TuffnookTown_DepthsEntrance_Movement_HikerMove:
	walk_up
	walk_left
	face_down
	step_end

TuffnookTown_DepthsEntrance_Text_PreparingForNextDive:
	.string "I'm just preparing for my next dive\n"
	.string "into THE DEPTHS.\p"
	.string "For a COOLTRAINER like me, this will\n"
	.string "surely be a breeze!$"

TuffnookTown_DepthsEntrance_Text_ThisPlaceIsTough:
	.string "This place is tough…\n"
	.string "Those BOSS POKéMON are way too strong!\p"
	.string "How did they even get that strong on\n"
	.string "their own in the first place?$"

TuffnookTown_DepthsEntrance_Text_WelcomeToTheDepths:
	.string "Hey there, kid!\n"
	.string "Welcome to THE DEPTHS!\p"
	.string "You think you got what it takes?$"

TuffnookTown_DepthsEntrance_Text_GotWhatItTakes:
	.string "So? Think you got what it takes?$"

TuffnookTown_DepthsEntrance_Text_NotGotWhatItTakes:
	.string "Oh, you don't got what it takes?\n"
	.string "That's fine, not everyone is brave\l"
	.string "enough to face THE DEPTHS.$"

TuffnookTown_DepthsEntrance_Text_CantChooseDifficulty:
	.string "For someone of your skill level\n"
	.string "the only option available to you\l"
	.string "is the NORMAL difficulty.\p"
	.string "Come back when you've entered the\n"
	.string "HALL OF FAME if you wanna see the\l"
	.string "true terror of THE DEPTHS.$"

TuffnookTown_DepthsEntrance_Text_ChooseDifficulty:
	.string "For someone of your skill level\n"
	.string "you might be able to take on our\l"
	.string "EXPERT difficulty.\p"
	.string "Feel free to take on whatever\n"
	.string "takes your fancy though.$"

TuffnookTown_DepthsEntrance_Text_SaveYourGame:
	.string "Just before you head down there,\n"
	.string "you'll need to save your game.\p"

TuffnookTown_DepthsEntrance_Text_GoodLuckDownThere:
	.string "If you want to call it quits early,\n"
	.string "you can climb back up the ladder.\p"
	.string "Alright then, good luck down there.\n"
	.string "You're gonna need it!$"

TuffnookTown_DepthsEntrance_Text_ExplainTheDepths:
	.string "In THE DEPTHS, your aim is to make\n"
	.string "it to the bottom floor.\p"
	.string "Sounds simple, right?\p"
	.string "To unlock the path to each floor,\n"
	.string "you will need to find a RUBY and\l"
	.string "a SAPPHIRE.\p"
	.string "At the end of each floor though,\n"
	.string "a powerful BOSS POKéMON awaits you.\p"
	.string "The real challenge though is that\n"
	.string "you won't have access to your BAG\l"
	.string "in THE DEPTHS, so any damage you\l"
	.string "take, you're stuck with.\p"
	.string "You can find a healing station about\n"
	.string "halfway down, but that's it.\p"
	.string "There will be 6 BOSS floors total,\n"
	.string "make it through those and you'll\l"
	.string "earn yourself a prize!\p"
	.string "Oh, and you won't earn any Exp.\n"
	.string "Points while you're in THE DEPTHS.$"

TuffnookTown_DepthsEntrance_Text_BetterLuckNextTime:
	.string "Better luck next time, kid.\p"
	.string "If you wish to challenge THE DEPTHS\n"
    .string "again, come back anytime!$"

TuffnookTown_DepthsEntrance_Text_StillGettingReady:
	.string "Sorry, kid, we're still getting ready\n"
	.string "here. Come back later if you want to\l"
	.string "challenge THE DEPTHS!$"
