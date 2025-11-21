Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition: 
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	end

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_YouSavedPeekoDidntYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineSailing
	goto Route104_MrBrineysHouse_EventScript_SettingSail
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	msgbox Route104_MrBrineysHouse_Text_ReadyToSetSail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineSailing
	goto Route104_MrBrineysHouse_EventScript_SettingSail
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SettingSail::
	msgbox Route104_MrBrineysHouse_Text_AnchorsAweigh, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	warp MAP_ROUTE104, 12, 52
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "MR. BRINEY: Hold on, lass!\n"
	.string "Wait up, PEEKO!$"

Route104_MrBrineysHouse_Text_YouSavedPeekoDidntYou:
	.string "Hm? You are…\n"
	.string "Oh! You're {PLAYER}{KUN}, right?\p"
	.string "I heard about you from that young\n"
	.string "man who was digging the tunnel!\p"
	.string "You saved my darling PEEKO!\n"
	.string "We owe so much to you!\p"
	.string "What's that?\n"
	.string "You want to sail with me?\p"
	.string "Quite the busy life you must lead!\p"
	.string "But, certainly, what you're asking is\n"
	.string "no problem at all.\p"
	.string "You've come to the right man!\p"
	.string "If you think you're ready to go then\n"
	.string "we'll set sail right away!$"

Route104_MrBrineysHouse_Text_ReadyToSetSail:
	.string "MR. BRINEY: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Are you ready to set sail, my friend?$"

Route104_MrBrineysHouse_Text_AnchorsAweigh:
	.string "MR. BRINEY: Anchors aweigh!\p"
	.string "PEEKO, we're setting sail, my darling!$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "MR. BRINEY: Is that so?\n"
	.string "Well, PEEKO owes her life to you.\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO: Pii piihyoro!$"

