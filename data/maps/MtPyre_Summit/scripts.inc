MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamMagmaTrigger0::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_MoveRight
	waitmovement 0
	goto MtPyre_Summit_EventScript_TeamMagmaExits
	end

MtPyre_Summit_EventScript_TeamMagmaTrigger1::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto MtPyre_Summit_EventScript_TeamMagmaExits
	end

MtPyre_Summit_EventScript_TeamMagmaTrigger2::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_MoveLeft
	waitmovement 0
	goto MtPyre_Summit_EventScript_TeamMagmaExits
	end

MtPyre_Summit_EventScript_TeamMagmaExits::
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	msgbox MtPyre_Summit_Text_MaxieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_MAGMA
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	applymovement LOCALID_MT_PYRE_TABITHA, MtPyre_Summit_Movement_TabithaWalkPlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtPyre_Summit_Text_TabithaLetsFight, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TABITHA_MT_PYRE, MtPyre_Summit_Text_TabithaDefeat
	msgbox MtPyre_Summit_Text_TabithaGoodbye, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_TABITHA
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TABITHA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer
	waitmovement 0
	msgbox MtPyre_Summit_Text_BothOrbsTaken, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_MT_PYRE_SUMMIT_RIVAL
	addobject LOCALID_MT_PYRE_SUMMIT_WALLY
	applymovement LOCALID_MT_PYRE_SUMMIT_RIVAL, MtPyre_Summit_Movement_RivalsMoveUp
	applymovement LOCALID_MT_PYRE_SUMMIT_WALLY, MtPyre_Summit_Movement_RivalsMoveUp
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MT_PYRE_SUMMIT_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_MT_PYRE_SUMMIT_WALLY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, MtPyre_Summit_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, MtPyre_Summit_EventScript_Brendan
	end

MtPyre_Summit_EventScript_May::
	msgbox MtPyre_Summit_Text_MayAnyLuck, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MT_PYRE_SUMMIT_RIVAL, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MT_PYRE_SUMMIT_WALLY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox MtPyre_Summit_Text_MagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	msgbox MtPyre_Summit_Text_MayThankYou, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MT_PYRE_SUMMIT_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_MT_PYRE_SUMMIT_WALLY, Common_Movement_WalkInPlaceFasterLeft
	msgbox MtPyre_Summit_Text_MaySearch, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_PYRE_SUMMIT_RIVAL, MtPyre_Summit_Movement_RivalsLeave
	waitmovement 0
	goto MtPyre_Summit_EventScript_Wally
	end

MtPyre_Summit_EventScript_Brendan::
	msgbox MtPyre_Summit_Text_BrendanAnyLuck, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MT_PYRE_SUMMIT_RIVAL, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MT_PYRE_SUMMIT_WALLY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox MtPyre_Summit_Text_MagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	msgbox MtPyre_Summit_Text_BrendanThankYou, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MT_PYRE_SUMMIT_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_MT_PYRE_SUMMIT_WALLY, Common_Movement_WalkInPlaceFasterLeft
	msgbox MtPyre_Summit_Text_BrendanSearch, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_PYRE_SUMMIT_RIVAL, MtPyre_Summit_Movement_RivalsLeave
	waitmovement 0
	goto MtPyre_Summit_EventScript_Wally
	end

MtPyre_Summit_EventScript_Wally::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_MT_PYRE_SUMMIT_WALLY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtPyre_Summit_Text_WallyNoLuck, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MT_PYRE_SUMMIT_WALLY, Common_Movement_WalkInPlaceFasterUp
	msgbox MtPyre_Summit_Text_WallyDidYouHearAnything, MSGBOX_DEFAULT
	closemessage
	msgbox MtPyre_Summit_Text_TheyWentToSlateport, MSGBOX_DEFAULT
	closemessage
	msgbox MtPyre_Summit_Text_WallyThankYou, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_MT_PYRE_SUMMIT_WALLY, Common_Movement_WalkInPlaceFasterLeft
	msgbox MtPyre_Summit_Text_WallySearch, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MT_PYRE_SUMMIT_WALLY, MtPyre_Summit_Movement_RivalsLeave
	waitmovement 0
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	clearflag FLAG_HIDE_JAGGED_PASS_RIVAL
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	clearflag FLAG_HIDE_SLATEPORT_CITY_WALLY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	removeobject LOCALID_MT_PYRE_SUMMIT_RIVAL
	removeobject LOCALID_MT_PYRE_SUMMIT_WALLY
	releaseall
	end

MtPyre_Summit_Movement_MoveRight:
	walk_right
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_MoveLeft:
	walk_left
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_TabithaWalkPlayer:
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer:
	walk_down
	step_end

MtPyre_Summit_Movement_RivalsMoveUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MtPyre_Summit_Movement_RivalsLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	goto_if_set FLAG_RETURNED_FIRST_ORB, MtPyre_Summit_EventScript_OldLadyOrbsReturned2
	call_if_ge VAR_MT_PYRE_STATE, 4, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	giveitem ITEM_RED_ORB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RETURNED_FIRST_ORB
	goto MtPyre_Summit_EventScript_OldLadyOrbsReturned2

MtPyre_Summit_EventScript_OldLadyOrbsReturned2::
	msgbox MtPyre_Summit_Text_ThisOneAsWell, MSGBOX_DEFAULT
	giveitem ITEM_BLUE_ORB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MtPyre_Summit_Text_TakeCareOfOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 4
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "No! Those TEAM AQUA goons got\n"
	.string "here ahead of us!\p"
	.string "We can't fall behind!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "I thought you were one of the AQUAS\n"
	.string "who happened to come back…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Yeah, so you are strong…\n"
	.string "But there're a lot of us!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah!\n"
	.string "Too bad for you!\p"
	.string "If you came earlier, you only would've\n"
	.string "had to battle the wimpy TEAM AQUA.\p"
	.string "But since you arrived now, you have\n"
	.string "to take on us toughies!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh… I should've let you take on\n"
	.string "TEAM AQUA first…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "You don't know anything!\n"
	.string "So why are you messing with us?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "You…\n"
	.string "We saw you at MT. CHIMNEY.\p"
	.string "You don't belong to either TEAM,\n"
	.string "so why would you be here?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "If you're going to mess with anyone,\n"
	.string "let it be TEAM AQUA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, it doesn't matter!\n"
	.string "We bought ourselves some time!\p"
	.string "The BOSS should have snatched what\n"
	.string "he was after!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, I know!\n"
	.string "You tried to join TEAM AQUA,\l"
	.string "but they wouldn't have you!\p"
	.string "Well, don't think that we'll let you\n"
	.string "join our TEAM MAGMA!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "If you want to join TEAM MAGMA that\n"
	.string "badly, we can consider it…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "We have a great combination going\n"
	.string "with us members and our leader.$"

MtPyre_Summit_Text_MaxieWeGotTheOrbLetsGo:
	.string "MAXIE: TEAM AQUA's ARCHIE got ahead\n"
	.string "of us, but we also got what we wanted.\p"
	.string "The BLUE ORB preserved at MT. PYRE…\n"
	.string "I, MAXIE, now have it in my possession!\p"
	.string "With that, we can now bring our ultimate\n"
	.string "objective to fruition!\p"
	.string "TABITHA! Why don't you show our guest\n"
	.string "here some hospitality?\p"
	.string "Move out, TEAM!\n"
	.string "Our goal is within our reach!$"

MtPyre_Summit_Text_TabithaLetsFight:
	.string "TABITHA: Hehehehe!\n"
	.string "So, we meet again!\p"
	.string "I heard you gave COURTNEY a thrashing\n"
	.string "over on SOUTHERN ISLAND!\p"
	.string "I think it's about due time that you be\n"
	.string "the one on the recieving end!\p"
	.string "If you think this will go the same way\n"
	.string "as METEOR FALLS, you're in for a shock!$"

MtPyre_Summit_Text_TabithaDefeat:
	.string "Heh… Heheh…\n"
	.string "I was the one in for a shock…$"

MtPyre_Summit_Text_TabithaGoodbye:
	.string "TABITHA: I can't believe how strong you\n"
	.string "are for just being some kid…\p"
	.string "Well, not that it matters really.\n"
	.string "My job was just to stall for time.\p"
	.string "And with that job complete, I shall be\n"
	.string "taking my leave!\p"
	.string "Good luck finding us now!\n"
	.string "Hehehehe!$"

MtPyre_Summit_Text_BothOrbsTaken:
	.string "Oh, no…\n"
	.string "This cannot happen…\p"
	.string "Not only the BLUE ORB, but even\n"
	.string "the RED ORB has been taken…\p"
	.string "The BLUE ORB and RED ORB must never\n"
	.string "be separated. They belong together.\p"
	.string "What are those men trying to do with\n"
	.string "the two ORBS?$"

MtPyre_Summit_Text_BrendanAnyLuck:
	.string "BRENDAN: {PLAYER}!\p"
	.string "I couldn't find any trace of TEAM\n"
	.string "MAGMA inside of MT. PYRE.\p"
	.string "Any luck up here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "We were too late?\n"
	.string "Drat! We need to find them quickly!\p"
	.string "I have no idea what they are planning\n"
	.string "to do with that orb, but I can't shake\l"
	.string "this feeling of dread…$"

MtPyre_Summit_Text_MayAnyLuck:
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "There was no sign of TEAM MAGMA\n"
	.string "inside of MT. PYRE.\p"
	.string "Did you find anything of note here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "TEAM MAGMA just left?\n"
	.string "Oh no, we were too late…\p"
	.string "I couldn't even guess what they plan\n"
	.string "to do with that orb, but I have a\l"
	.string "dreadful feeling about this…$"

MtPyre_Summit_Text_MagmaLeftThis:
	.string "Oh, yes. TEAM MAGMA, in their haste\n"
	.string "to leave, left this behind.\p"
	.string "I couldn't imagine what exactly it\n"
	.string "could be.\p"
	.string "I would like you to have it.\n"
	.string "Perhaps it will be useful in some way.$"

MtPyre_Summit_Text_BrendanThankYou:
	.string "BRENDAN: Oh, thanks!\n"
	.string "Right, it's too early to give up!\p"
	.string "Whatever TEAM MAGMA is planning, we\n"
	.string "just need to stop them first!\p"
	.string "The question now becomes, where did\n"
	.string "TEAM MAGMA run off to?\p"
	.string "Hm…$"

MtPyre_Summit_Text_BrendanSearch:
	.string "I think I'll start searching near\n"
	.string "MT. CHIMNEY.\p"
	.string "I remember running into a suspicious\n"
	.string "GRUNT around that area.\p"
	.string "I'll see you over there, {PLAYER}.$"

MtPyre_Summit_Text_MayThankYou:
	.string "MAY: Oh, thank you!\n"
	.string "Sorry, I shouldn't be giving up now!\p"
	.string "We just need to find and stop TEAM\n"
	.string "MAGMA before they do anything!\p"
	.string "Now, where did TEAM MAGMA go?\n"
	.string "They have to be hiding somewhere…\p"
	.string "Hm…$"

MtPyre_Summit_Text_MaySearch:
	.string "I think I'll start searching near\n"
	.string "MT. CHIMNEY.\p"
	.string "I remember running into a suspicious\n"
	.string "GRUNT around that area.\p"
	.string "I'll meet you there, {PLAYER}{KUN}.$"

MtPyre_Summit_Text_WallyNoLuck:
	.string "WALLY: Sorry, {PLAYER}.\n"
	.string "I had no luck either.\p"
	.string "It seems like TEAM AQUA cleared out\n"
	.string "before we even got here.$"

MtPyre_Summit_Text_WallyDidYouHearAnything:
	.string "Um, excuse me.\p"
	.string "Did you hear anything from TEAM AQUA\n"
	.string "about where they went?$"

MtPyre_Summit_Text_TheyWentToSlateport:
	.string "Ah, yes.\n"
	.string "I believe I heard that lot say they\l"
	.string "were headed to SLATEPORT CITY.\p"
	.string "If you want to find them, that is\n"
	.string "where I would start.$"

MtPyre_Summit_Text_WallyThankYou:
	.string "WALLY: Thank you.\n"
	.string "Seems like our goal is clear.$"

MtPyre_Summit_Text_WallySearch:
	.string "I'm off to SLATEPORT CITY then.\n"
	.string "I'll meet you there, {PLAYER}.\p"
	.string "Oh, but if you want to go after TEAM\n"
	.string "MAGMA first, then that is fine too.\p"
	.string "Either way, I'll see you later.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "The BLUE ORB and RED ORB taken by\n"
	.string "those sinister men…\p"
	.string "They must never be apart…\n"
	.string "I fear something terrible will happen…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Oh, my goodness…\p"
	.string "You say that both GROUDON and KYOGRE\n"
	.string "have been awakened?\p"
	.string "It is said that the BLUE ORB and\n"
	.string "the RED ORB quelled the rage of\l"
	.string "the two POKéMON…\p"
	.string "It is also said that the true owner\n"
	.string "of the ORBS still exists.\p"
	.string "However, no one knows who, or what\n"
	.string "exactly, the ORBS belong to.\p"
	.string "It could be a human, or perhaps\n"
	.string "a POKéMON, but no one knows.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "The two men who took the ORBS came\n"
	.string "back to return them on their own.\p"
	.string "Those men…\n"
	.string "Perhaps they are not so evil after all…\p"
	.string "You there, child.\n"
	.string "If I am not mistaken, you are the one\l"
	.string "who brought this calamity to an end.\p"
	.string "I wish to entrust you with the two\n"
	.string "orbs those men just returned.\p"
	.string "For a trainer as strong as you, I\n"
	.string "believe they will be safest in your\l"
	.string "hands, as it matters not where the\l"
	.string "orbs are kept so long as they are\l"
	.string "kept together.$"

MtPyre_Summit_Text_ThisOneAsWell:
	.string "And this one as well.$"

MtPyre_Summit_Text_TakeCareOfOrbs:
	.string "I hope that in your hands, these orbs\n"
	.string "will not be misused by the hands of\l"
	.string "those misguided by their goals.$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "The embodiments of the land, sea,\n"
	.string "and the sky…\p"
	.string "That is said to be the identities of\n"
	.string "the super-ancient POKéMON…\p"
	.string "In the same way that we humans and\n"
	.string "POKéMON have life, our world, too,\l"
	.string "is alive…\p"
	.string "The super-ancient POKéMON have\n"
	.string "taught us that…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "MT. PYRE is where we calm the spirits\n"
	.string "of POKéMON that have passed on…\p"
	.string "This is a high place where one can\n"
	.string "see all of HOENN…\p"
	.string "The disembodied spirits of POKéMON\n"
	.string "must find solace here…\p"
	.string "Is it coincidence that you are here…\p"
	.string "Will you hear out my tale? A tale long\n"
	.string "told in the HOENN region?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the POKéMON of the land\l"
	.string "and the POKéMON of the sea…\p"
	.string "The POKéMON of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The POKéMON of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "infernos and vicious storms.\p"
	.string "The BLUE ORB and the RED ORB brought\n"
	.string "an end to the calamity.\p"
	.string "Light poured from the two ORBS and\n"
	.string "becalmed the enraged adversaries.\p"
	.string "The pair, made docile, dove deep into\n"
	.string "the sea where eventually they\l"
	.string "disappeared…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "I see…\n"
	.string "Well, that, too, is fine…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "It is my role to pass on the legends\n"
	.string "of HOENN to future generations.\p"
	.string "And the crisis that just ended in\n"
	.string "SOOTOPOLIS rewrote a legend…\p"
	.string "Have you the time to hear the new\n"
	.string "legend of HOENN?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the POKéMON of the land\l"
	.string "and the POKéMON of the sea…\p"
	.string "The POKéMON of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The POKéMON of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "fires and vicious storms.\p"
	.string "It was then that the POKéMON of\n"
	.string "the sky descended from a storm.\p"
	.string "The POKéMON, shining a vivid green,\n"
	.string "becalmed the two enraged POKéMON.\p"
	.string "Then, its duty done, the green POKéMON\n"
	.string "flew off into the wild blue yonder…$"

