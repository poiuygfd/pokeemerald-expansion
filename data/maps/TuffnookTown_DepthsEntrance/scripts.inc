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
	checkitem ITEM_BATTLE_PASS
    goto_if_eq VAR_RESULT, FALSE, TuffnookTown_DepthsEntrance_EventScript_ManTrainerHillClosed
	msgbox TuffnookTown_DepthsEntrance_Text_PreparingForNextDive, MSGBOX_NPC
	end

TuffnookTown_DepthsEntrance_EventScript_ManTrainerHillClosed::
	msgbox TuffnookTown_DepthsEntrance_Text_ILoveBigHoles, MSGBOX_NPC
	end

TuffnookTown_DepthsEntrance_EventScript_Picnicker::
	checkitem ITEM_BATTLE_PASS
    goto_if_eq VAR_RESULT, FALSE, TuffnookTown_DepthsEntrance_EventScript_GirlTrainerHillClosed
	msgbox TuffnookTown_DepthsEntrance_Text_ThisPlaceIsTough, MSGBOX_NPC
	end

TuffnookTown_DepthsEntrance_EventScript_GirlTrainerHillClosed::
	msgbox TuffnookTown_DepthsEntrance_Text_NoviceAtCaveDiving, MSGBOX_NPC
	end

TuffnookTown_DepthsEntrance_EventScript_Hiker::
	lockall
	checkitem ITEM_BATTLE_PASS
    goto_if_eq VAR_RESULT, FALSE, TuffnookTown_DepthsEntrance_EventScript_Closed
	goto_if_eq VAR_DEPTHS_MON_STATE, 8, TuffnookTown_DepthsEntrance_EventScript_UnclaimedPrize
	goto_if_eq VAR_TEMP_1, 1, TuffnookTown_DepthsEntrance_EventScript_ChallengeStarted
	setvar VAR_DEPTHS_STATE, 0
	setvar VAR_DEPTHS_MON_STATE, 0
	clearflag FLAG_DEPTHS_USED_HEAL
	clearflag FLAG_B6F_SPAWNED_GEMS
	message TuffnookTown_DepthsEntrance_Text_WelcomeToTheDepths
	waitmessage
	multichoice 0, 0, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TuffnookTown_DepthsEntrance_EventScript_ChooseChallenge
	case 1, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	case 2, TuffnookTown_DepthsEntrance_EventScript_Info
	case MULTI_B_PRESSED, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	end

TuffnookTown_DepthsEntrance_EventScript_Info::
	message TuffnookTown_DepthsEntrance_Text_WhichTopic
	waitmessage
	multichoice 0, 0, MULTI_DEPTHS_EXPLAIN_MODE, FALSE
	switch VAR_RESULT
	case 0, TuffnookTown_DepthsEntrance_EventScript_ExplainTheDepths
	case 1, TuffnookTown_DepthsEntrance_EventScript_ExplainTheDepthsModes
	case 2, TuffnookTown_DepthsEntrance_EventScript_AskAgain
	case MULTI_B_PRESSED, TuffnookTown_DepthsEntrance_EventScript_AskAgain
	end

TuffnookTown_DepthsEntrance_EventScript_ExplainTheDepths::
	msgbox TuffnookTown_DepthsEntrance_Text_ExplainTheDepths, MSGBOX_DEFAULT
	goto TuffnookTown_DepthsEntrance_EventScript_Info
	end

TuffnookTown_DepthsEntrance_EventScript_ExplainTheDepthsModes::
	msgbox TuffnookTown_DepthsEntrance_Text_ExplainTheDepthsModes, MSGBOX_DEFAULT
	goto TuffnookTown_DepthsEntrance_EventScript_Info
	end

TuffnookTown_DepthsEntrance_EventScript_CancelEntry::
	msgbox TuffnookTown_DepthsEntrance_Text_NotGotWhatItTakes, MSGBOX_DEFAULT
	releaseall
	end

TuffnookTown_DepthsEntrance_EventScript_AskAgain::
	message TuffnookTown_DepthsEntrance_Text_GotWhatItTakes
	waitmessage
	multichoice 0, 0, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TuffnookTown_DepthsEntrance_EventScript_ChooseChallenge
	case 1, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	case 2, TuffnookTown_DepthsEntrance_EventScript_Info
	case MULTI_B_PRESSED, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	end

TuffnookTown_DepthsEntrance_EventScript_ChooseChallenge::
	message TuffnookTown_DepthsEntrance_Text_ChooseDifficulty
	waitmessage
	multichoice 0, 0, MULTI_DEPTHS_CHOOSE_MODE, FALSE
	switch VAR_RESULT
	case 0, TuffnookTown_DepthsEntrance_EventScript_NormalMode
	case 1, TuffnookTown_DepthsEntrance_EventScript_ExpertMode
	case 2, TuffnookTown_DepthsEntrance_EventScript_MasterMode
	case 3, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TuffnookTown_DepthsEntrance_EventScript_CancelEntry
	end

TuffnookTown_DepthsEntrance_EventScript_NormalMode::
	setflag FLAG_DEPTHS_IS_NORMAL
	goto TuffnookTown_DepthsEntrance_EventScript_BeginTheDepths
	end

TuffnookTown_DepthsEntrance_EventScript_ExpertMode::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TuffnookTown_DepthsEntrance_EventScript_NoExpert
	setflag FLAG_DEPTHS_IS_EXPERT
	goto TuffnookTown_DepthsEntrance_EventScript_BeginTheDepths
	end

TuffnookTown_DepthsEntrance_EventScript_MasterMode::
	goto_if_unset FLAG_SYS_DEPTHS_EXPERT_WIN, TuffnookTown_DepthsEntrance_EventScript_NoMaster
	setflag FLAG_DEPTHS_IS_MASTER
	goto TuffnookTown_DepthsEntrance_EventScript_BeginTheDepths
	end

TuffnookTown_DepthsEntrance_EventScript_BeginTheDepths::
	msgbox TuffnookTown_DepthsEntrance_Text_GoodLuckDownThere, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 1
	closemessage
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	applymovement LOCALID_DEPTHS_ENTRANCE_HIKER, TuffnookTown_DepthsEntrance_Movement_HikerMove
	waitmovement 0
	releaseall
	end

TuffnookTown_DepthsEntrance_EventScript_ChallengeStarted::
	msgbox TuffnookTown_DepthsEntrance_Text_BestOfLuck, MSGBOX_NPC
	releaseall
	end

TuffnookTown_DepthsEntrance_EventScript_NoExpert::
	msgbox TuffnookTown_DepthsEntrance_Text_ExpertDifficultyIsLocked, MSGBOX_DEFAULT
	goto TuffnookTown_DepthsEntrance_EventScript_ChooseChallenge
	end

TuffnookTown_DepthsEntrance_EventScript_NoMaster::
	msgbox TuffnookTown_DepthsEntrance_Text_MasterDifficultyIsLocked, MSGBOX_DEFAULT
	goto TuffnookTown_DepthsEntrance_EventScript_ChooseChallenge
	end

TuffnookTown_DepthsEntrance_EventScript_UnclaimedPrize::
	goto_if_unset FLAG_DEPTHS_USED_HEAL, TuffnookTown_DepthsEntrance_EventScript_NoHealPrize
	msgbox TuffnookTown_DepthsEntrance_Text_ClaimPrize, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_CAPSULE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_DEPTHS_MON_STATE, 0
	releaseall
	end

TuffnookTown_DepthsEntrance_EventScript_NoHealPrize::
	msgbox TuffnookTown_DepthsEntrance_Text_ClaimPrize, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_PATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_DEPTHS_MON_STATE, 0
	releaseall
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

TuffnookTown_DepthsEntrance_Text_ILoveBigHoles:
	.string "I can't wait for this place to open\n"
	.string "to the public.\p"
	.string "If there's two things in life I love\n"
	.string "its tough battles and big ol' holes!$"

TuffnookTown_DepthsEntrance_Text_PreparingForNextDive:
	.string "I'm just preparing for my next dive\n"
	.string "into THE DEPTHS.\p"
	.string "For a COOLTRAINER like me, this will\n"
	.string "surely be a breeze!$"

TuffnookTown_DepthsEntrance_Text_NoviceAtCaveDiving:
	.string "I've come to get a bit stronger at\n"
	.string "this place when it opens.\p"
	.string "I'm a bit of a novice at cave diving\n"
	.string "though, so I'm a bit worried…$"

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

TuffnookTown_DepthsEntrance_Text_ChooseDifficulty:
	.string "What difficulty were you hoping\n"
	.string "to try yer hand at today then?$"

TuffnookTown_DepthsEntrance_Text_ExpertDifficultyIsLocked:
	.string "Sorry kid, can't let you do that.\n"
	.string "EXPERT MODE seems a bit beyond you.\p"
	.string "Try coming back when you enter\n"
	.string "the HALL OF FAME.$"

TuffnookTown_DepthsEntrance_Text_MasterDifficultyIsLocked:
	.string "Sorry kid, can't let you do that.\n"
	.string "MASTER MODE seems a bit beyond you.\p"
	.string "Try coming back when you've beat\n"
	.string "EXPERT MODE.$"

TuffnookTown_DepthsEntrance_Text_SaveYourGame:
	.string "Just before you head down there,\n"
	.string "you'll need to save your game.$"

TuffnookTown_DepthsEntrance_Text_GoodLuckDownThere:
	.string "Alright then, good luck down there.\p"
	.string "If you want to call it quits early,\n"
	.string "you can climb back up the ladder.\p"
	.string "Otherwise, I will see you on the\n"
	.string "other side!$"

TuffnookTown_DepthsEntrance_Text_BestOfLuck:
	.string "Best of luck, kid.$"

TuffnookTown_DepthsEntrance_Text_WhichTopic:
	.string "Which topic would you like?$"

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

TuffnookTown_DepthsEntrance_Text_ExplainTheDepthsModes:
	.string "There are three difficulty modes\n"
	.string "you can find in THE DEPTHS.\p"
	.string "NORMAL MODE is your standard mode\n"
	.string "anyone can try.\p"
	.string "Don't let that fool you though,\n"
	.string "it's still tough as nails!\p"
	.string "EXPERT MODE is a challenging time\n"
	.string "only those who enter the HALL OF FAME\l"
	.string "can give a go.\p"
	.string "And for the real nutjobs who beat\n"
	.string "EXPERT MODE, we have MASTER MODE.\p"
	.string "This mode will really push you to\n"
	.string "your absolute limits!$"

TuffnookTown_DepthsEntrance_Text_BetterLuckNextTime:
	.string "Better luck next time, kid.\p"
	.string "If you wish to challenge THE DEPTHS\n"
    .string "again, come back anytime!$"

TuffnookTown_DepthsEntrance_Text_ClaimPrize:
	.string "Looks like you have an unclaimed\n"
	.string "prize here.\p"
	.string "Here you go!$"

TuffnookTown_DepthsEntrance_Text_StillGettingReady:
	.string "Sorry, kid, we're still getting ready\n"
	.string "here. Come back later if you want to\l"
	.string "challenge THE DEPTHS!$"
