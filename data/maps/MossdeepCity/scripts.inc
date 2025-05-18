.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16
.set LOCALID_JIRACHI, 19

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MossdeepCity_OnResume
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call_if_eq VAR_WHITE_ROCK_COUNT, 14, MossdeepCity_EventScript_TryShowJirachi
	end

MossdeepCity_EventScript_HideJirachi::
	setflag FLAG_HIDE_JIRACHI
	return

MossdeepCity_EventScript_TryShowJirachi::
	call_if_set FLAG_CAUGHT_JIRACHI, MossdeepCity_EventScript_HideJirachi
	call_if_unset FLAG_CAUGHT_JIRACHI, MossdeepCity_EventScript_ShowJirachi
	return

MossdeepCity_EventScript_ShowJirachi::
	goto_if_set FLAG_DEFEATED_JIRACHI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_JIRACHI
	return

MossdeepCity_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MossdeepCity_EventScript_TryRemoveJirachi
	end

MossdeepCity_EventScript_TryRemoveJirachi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_JIRACHI
	return

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	goto_if_eq VAR_WHITE_ROCK_COUNT, 14, MossdeepCity_EventScript_Woman2
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman2::
	msgbox MossdeepCity_Text_WhatTheFrick, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	goto_if_eq VAR_WHITE_ROCK_COUNT, 0, MossdeepCity_EventScript_WhiteRock1
	goto_if_eq VAR_WHITE_ROCK_COUNT, 1, MossdeepCity_EventScript_WhiteRock2
	goto_if_eq VAR_WHITE_ROCK_COUNT, 2, MossdeepCity_EventScript_WhiteRock3
	goto_if_eq VAR_WHITE_ROCK_COUNT, 3, MossdeepCity_EventScript_WhiteRock4
	goto_if_eq VAR_WHITE_ROCK_COUNT, 4, MossdeepCity_EventScript_WhiteRock5
	goto_if_eq VAR_WHITE_ROCK_COUNT, 5, MossdeepCity_EventScript_WhiteRock6
	goto_if_eq VAR_WHITE_ROCK_COUNT, 6, MossdeepCity_EventScript_WhiteRock7
	goto_if_eq VAR_WHITE_ROCK_COUNT, 7, MossdeepCity_EventScript_WhiteRock8
	goto_if_eq VAR_WHITE_ROCK_COUNT, 8, MossdeepCity_EventScript_WhiteRock9
	goto_if_eq VAR_WHITE_ROCK_COUNT, 9, MossdeepCity_EventScript_WhiteRock10
	goto_if_eq VAR_WHITE_ROCK_COUNT, 10, MossdeepCity_EventScript_WhiteRock11
	goto_if_eq VAR_WHITE_ROCK_COUNT, 11, MossdeepCity_EventScript_WhiteRock12
	goto_if_eq VAR_WHITE_ROCK_COUNT, 12, MossdeepCity_EventScript_WhiteRock13
	goto_if_eq VAR_WHITE_ROCK_COUNT, 13, MossdeepCity_EventScript_WhiteRock14
	goto_if_eq VAR_WHITE_ROCK_COUNT, 14, MossdeepCity_EventScript_WhiteRock15
	end

MossdeepCity_EventScript_WhiteRock1::
	msgbox MossdeepCity_Text_ItsAWhiteRock1, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 1
	end

MossdeepCity_EventScript_WhiteRock2::
	msgbox MossdeepCity_Text_ItsAWhiteRock2, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 2
	end

MossdeepCity_EventScript_WhiteRock3::
	msgbox MossdeepCity_Text_ItsAWhiteRock3, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 3
	end

MossdeepCity_EventScript_WhiteRock4::
	msgbox MossdeepCity_Text_ItsAWhiteRock4, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 4
	end

MossdeepCity_EventScript_WhiteRock5::
	msgbox MossdeepCity_Text_ItsAWhiteRock5, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 5
	end

MossdeepCity_EventScript_WhiteRock6::
	msgbox MossdeepCity_Text_ItsAWhiteRock6, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 6
	end

MossdeepCity_EventScript_WhiteRock7::
	msgbox MossdeepCity_Text_ItsAWhiteRock7, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 7
	end

MossdeepCity_EventScript_WhiteRock8::
	msgbox MossdeepCity_Text_ItsAWhiteRock8, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 8
	end

MossdeepCity_EventScript_WhiteRock9::
	msgbox MossdeepCity_Text_ItsAWhiteRock9, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 9
	end
	
MossdeepCity_EventScript_WhiteRock10::
	msgbox MossdeepCity_Text_ItsAWhiteRock10, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 10
	end

MossdeepCity_EventScript_WhiteRock11::
	msgbox MossdeepCity_Text_ItsAWhiteRock11, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 11
	end

MossdeepCity_EventScript_WhiteRock12::
	msgbox MossdeepCity_Text_ItsAWhiteRock12, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 12
	end

MossdeepCity_EventScript_WhiteRock13::
	msgbox MossdeepCity_Text_ItsAWhiteRock13, MSGBOX_SIGN
	setvar VAR_WHITE_ROCK_COUNT, 13
	end

MossdeepCity_EventScript_WhiteRock14::
	lockall
	msgbox MossdeepCity_Text_ItsAWhiteRock14, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_JIRACHI, 30
	setvar VAR_WHITE_ROCK_COUNT, 14
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MossdeepCity_EventScript_DefeatedJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MossdeepCity_EventScript_RanFromJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MossdeepCity_EventScript_RanFromJirachi
	setflag FLAG_DEFEATED_JIRACHI
	releaseall
	end

MossdeepCity_EventScript_Jirachi::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MossdeepCity_EventScript_DefeatedJirachiStatic
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MossdeepCity_EventScript_RanFromJirachiStatic
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MossdeepCity_EventScript_RanFromJirachiStatic
	setflag FLAG_CAUGHT_JIRACHI
	release
	end

MossdeepCity_EventScript_WhiteRock15::
	msgbox MossdeepCity_Text_ItsAWhiteRock15, MSGBOX_SIGN
	end

MossdeepCity_EventScript_DefeatedJirachiStatic::
	setflag FLAG_DEFEATED_JIRACHI
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto Common_EventScript_LegendaryFlewAway
	end

MossdeepCity_EventScript_RanFromJirachiStatic::
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto Common_EventScript_LegendaryFlewAway
	end

MossdeepCity_EventScript_DefeatedJirachi::
	setflag FLAG_DEFEATED_JIRACHI
	setvar VAR_0x8004, SPECIES_JIRACHI
	fadescreenswapbuffers FADE_TO_BLACK
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_RanFromJirachi::
	setvar VAR_0x8004, SPECIES_JIRACHI
	fadescreenswapbuffers FADE_TO_BLACK
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_SLOWBRONITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_GalaricaGirl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GALARICA, MossdeepCity_EventScript_ReceivedGalarica
	msgbox MossdeepCity_Text_TouristFromGalar, MSGBOX_DEFAULT
	waitmessage
	goto MossdeepCity_EventScript_ChooseGalaricaItem
	release
	end

MossdeepCity_EventScript_ChooseGalaricaItem::
	multichoice 0, 0, MULTI_GALARICA_ITEM, FALSE
	switch VAR_RESULT
	case 0, MossdeepCity_EventScript_GalaricaCuff
	case 1, MossdeepCity_EventScript_GalaricaWreath
	case 2, MossdeepCity_EventScript_Decline
	case MULTI_B_PRESSED, MossdeepCity_EventScript_Decline
	end

MossdeepCity_EventScript_GalaricaCuff::
	msgbox MossdeepCity_Text_GetGalaricaCuff, MSGBOX_DEFAULT
	giveitem ITEM_GALARICA_CUFF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_GALARICA
	goto MossdeepCity_EventScript_ReceivedGalarica
	end

MossdeepCity_EventScript_GalaricaWreath::
	msgbox MossdeepCity_Text_GetGalaricaWreath, MSGBOX_DEFAULT
	giveitem ITEM_GALARICA_WREATH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_GALARICA
	goto MossdeepCity_EventScript_ReceivedGalarica
	end

MossdeepCity_EventScript_Decline::
	msgbox MossdeepCity_Text_LetMeKnowWhenYouDecide, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_ReceivedGalarica::
	lock
	faceplayer
	msgbox MossdeepCity_Text_EnjoyYourSouvenier, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "I got this weird rock from STEVEN, but\n"
	.string "I don't know what it's good for.\p"
	.string "Do you want it?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Why would you want it?\n"
	.string "You're weird.\p"
	.string "You can keep it, but keep it a secret\n"
	.string "from STEVEN.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "STEVEN's house is right over there!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Yeah, you think so, too! What are you\n"
	.string "supposed to do with some weird rock?$"

MossdeepCity_Text_TouristFromGalar:
	.string "Hi there!\n"
	.string "I'm a tourist from the GALAR region!\p"
	.string "I came to HOENN to enjoy the tropical\n"
	.string "climate and see the sights.\p"
	.string "Say, would you like a souvenier from\n"
	.string "the GALAR region?\p"
	.string "You can have either this here GALARICA\n"
	.string "CUFF or GALARICA WREATH.$"

MossdeepCity_Text_GetGalaricaCuff:
	.string "So, you chose the GALARICA CUFF…\n"
	.string "Good choice!\p"
	.string "Not that either of them were wrong\n"
	.string "choices…\p"
	.string "Anyway, here you go!$"

MossdeepCity_Text_GetGalaricaWreath:
	.string "So, you chose the GALARICA WREATH…\n"
	.string "Good choice!\p"
	.string "Not that either of them were wrong\n"
	.string "choices…\p"
	.string "Anyway, here you go!$"

MossdeepCity_Text_LetMeKnowWhenYouDecide:
	.string "Need some time to make a desicion?\n"
	.string "That's fine, you know where to find\l"
	.string "me when you've made up your mind.$"

MossdeepCity_Text_EnjoyYourSouvenier:
	.string "Enjoy your souvenier!\n"
	.string "You should visit the GALAR region\l"
	.string "sometime, if you don't mind the cold.$"

MossdeepCity_Text_WailmerWatching:
	.string "Around MOSSDEEP, you can see wild\n"
	.string "WAILMER.\p"
	.string "It's called, uh…\n"
	.string "What was it now…\p"
	.string "WAI, WAI, WAI…\p"
	.string "WAILMER watching!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.\p"
	.string "There's been some kind of an uproar\n"
	.string "over a letter they received recently.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "I heard from a SAILOR buddy that\n"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
	.string "I also heard that someone came along\n"
	.string "and wiped the floor with them!\p"
	.string "But MOSSDEEP here's been targeted\n"
	.string "by that TEAM MAGMA.\p"
	.string "If you want to know what they're up to,\n"
	.string "go visit the SPACE CENTER.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "I'm a SAILOR, so the sea's obviously\n"
	.string "more important to me.\p"
	.string "But you know? When I get back on land\n"
	.string "after a long voyage, I do feel relief!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Wouldn't it be nice?\p"
	.string "If the whole world was covered in\n"
	.string "plants and flowers like this island?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "All life needs the sea to live, even\n"
	.string "though it makes its home on the land.\p"
	.string "Life, having run its course, becomes\n"
	.string "soil and returns to the land.\p"
	.string "And the sea is always connected to\n"
	.string "the land.\p"
	.string "Yes, like the very shoreline here.$"

MossdeepCity_Text_SurfExhilarating:
	.string "A voyage on a ship is fine.\p"
	.string "But crossing the sea with POKéMON\n"
	.string "using SURF…\p"
	.string "Now that's an exhilarating trip!\n"
	.string "Wouldn't you agree, youngster?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "This rock has a special meaning to\n"
	.string "the people at the SPACE CENTER.\p"
	.string "They put it here as their wish for\n"
	.string "their rockets to fly safely.\p"
	.string "When you make a wish, what do you use?\n"
	.string "Do you wish upon a star?\p"
	.string "I use a wish tag to make it happen.\n"
	.string "That's what I do.$"

MossdeepCity_Text_WhatTheFrick:
	.string "what the frick.$"

MossdeepCity_Text_ItsAWhiteRock1:
	.string "It's a white rock.$"

MossdeepCity_Text_ItsAWhiteRock2:
	.string "It's still a white rock.$"

MossdeepCity_Text_ItsAWhiteRock3:
	.string "It's a rock that appears to be white.$"

MossdeepCity_Text_ItsAWhiteRock4:
	.string "Is it really just a white rock…?$"

MossdeepCity_Text_ItsAWhiteRock5:
	.string "Yeah, I'm pretty sure it's literally\n"
	.string "just a white rock.$"

MossdeepCity_Text_ItsAWhiteRock6:
	.string "But what if it's more than just a\n"
	.string "measly white rock?$"

MossdeepCity_Text_ItsAWhiteRock7:
	.string "What if it is actually a JIRACHI?$"

MossdeepCity_Text_ItsAWhiteRock8:
	.string "Nah, that would be stupid.\n"
	.string "It's just a white rock.$"

MossdeepCity_Text_ItsAWhiteRock9:
	.string "But could you imagine if a random\n"
	.string "mythical was just sitting here?$"

MossdeepCity_Text_ItsAWhiteRock10:
	.string "A shame it's just a white rock.$"

MossdeepCity_Text_ItsAWhiteRock11:
	.string "Hold on, did something move just now?$"

MossdeepCity_Text_ItsAWhiteRock12:
	.string "Sorry, it was just my imagination.$"

MossdeepCity_Text_ItsAWhiteRock13:
	.string "After all, it's just a white rock.$"

MossdeepCity_Text_ItsAWhiteRock14:
	.string "Huh?$"

MossdeepCity_Text_ItsAWhiteRock15:
	.string "It's a white rock.$"

MossdeepCity_Text_GymSign:
	.string "MOSSDEEP CITY POKéMON GYM\n"
	.string "LEADERS: LIZA & TATE\p"
	.string "“The mystic combination!”$"

MossdeepCity_Text_CitySign:
	.string "MOSSDEEP CITY\n"
	.string "“Our slogan: Cherish POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "MOSSDEEP SPACE CENTER\n"
	.string "“The closest place to space.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
	.string "I'm doing great!\p"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
	.string "pretty strong, so I decided to come\l"
	.string "take a look-see for myself.\p"
	.string "But there's something wrong about\n"
	.string "this town.\p"
	.string "People are going on about a warning\n"
	.string "letter and the SPACE CENTER…\p"
	.string "I don't think it concerns me in any\n"
	.string "way, though.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… It feels great letting the waves\n"
	.string "wash over my feet…\p"
	.string "Speaking of the waves, you know that\n"
	.string "island city SOOTOPOLIS?\p"
	.string "I think the GYM there had a new\n"
	.string "LEADER come in.\p"
	.string "People tell me the new LEADER once\n"
	.string "mentored WALLACE.$"

