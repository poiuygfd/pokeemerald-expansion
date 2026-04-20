MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MeteorFalls_1F_1R_OnTransition
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_METEOR_FALLS_STATE, 1, MeteorFalls_1F_1R_EventScript_MoveRivalToCozmo
	end

MeteorFalls_1F_1R_EventScript_MoveRivalToCozmo::
	setobjectxyperm LOCALID_METEOR_FALLS_RIVAL, 12, 23
	setobjectmovementtype LOCALID_METEOR_FALLS_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MeteorFalls_1F_1R_Movement_PlayerApproachTabitha
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_TABITHA_METEOR_FALLS, MeteorFalls_1F_1R_Text_TabithaDefeat
	msgbox MeteorFalls_1F_1R_Text_WontStopOurPlans, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_METEOR_FALLS_ARCHIE
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_TabithaExit
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGruntExit
	waitmovement 0
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_2
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_METEOR_FALLS_ARCHIE
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_MayWasntStrongEnough
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BrendanWasntStrongEnough
	applymovement LOCALID_METEOR_FALLS_RIVAL, MeteorFalls_1F_1R_Movement_RivalMoveToCozmo
	waitmovement 0
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

Route119_EventScript_MayWasntStrongEnough:
	msgbox MeteorFalls_1F_1R_Text_IWasTooWeak, MSGBOX_DEFAULT
	closemessage
	return

Route119_EventScript_BrendanWasntStrongEnough:
	msgbox MeteorFalls_1F_1R_Text_ThoughtIWasStronger, MSGBOX_DEFAULT
	closemessage
	return

MeteorFalls_1F_1R_Movement_PlayerApproachTabitha:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_TabithaExit:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGruntExit:
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	delay_16
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	delay_16
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_RivalMoveToCozmo:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_MayGoAfterTeamMagma
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BrendanGoAfterTeamMagma
	release
	end

Route119_EventScript_MayGoAfterTeamMagma::
	msgbox MeteorFalls_1F_1R_Text_MayChaseTeamMagma, MSGBOX_DEFAULT
	return

Route119_EventScript_BrendanGoAfterTeamMagma::
	msgbox MeteorFalls_1F_1R_Text_BrendanChaseTeamMagma, MSGBOX_DEFAULT
	return

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "TABITHA: Hehehe!\p"
	.string "That wasn't a bad show, kid, but you'll\n"
	.string "need more than that to beat TEAM MAGMA!\p"
	.string "Now, if you'll excuse us, we have a\n"
	.string "METEORITE to deliver to our boss!\p"
	.string "With this METEORITE, that thing in\n"
	.string "MT. CHIMNEY will…$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "Heh?\p"
	.string "I don't know who you are, but if you get\n"
	.string "in the way of TEAM MAGMA, don't\l"
	.string "expect any mercy!$"

MeteorFalls_1F_1R_Text_TabithaDefeat:
	.string "Hehehe…\n"
	.string "You're stronger than you look…$"

MeteorFalls_1F_1R_Text_WontStopOurPlans:
	.string "TABITHA: Heh…\p"
	.string "Wasn't expecting to lose here…\n"
	.string "Not that it makes any difference.\p"
	.string "Once our boss has his hand on this\n"
	.string "METEORITE…\p"
	.string "Hehehe…$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "Hold it right there, TEAM MAGMA!\p"
	.string "You're badly mistaken if you think you\n"
	.string "can have your way with the world!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "Hehehe!\n"
	.string "Even TEAM AQUA joins us!\p"
	.string "But it's too much trouble to deal with\n"
	.string "you all…\p"
	.string "Heh, it doesn't matter!\p"
	.string "We've got the METEORITE, so off to\n"
	.string "MT. CHIMNEY we go!\p"
	.string "Hehehe! Be seeing you, you TEAM\n"
	.string "AQUA dingbats!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "ARCHIE: Didn't I see you before?\n"
	.string "At SLATEPORT's MUSEUM?\p"
	.string "Ah, so your name is {PLAYER}.\p"
	.string "At the time, I thought you were one\n"
	.string "of TEAM MAGMA's goons.\p"
	.string "Humph…\n"
	.string "You're one odd kid.\p"
	.string "TEAM MAGMA is a dangerous group of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "to expand the land mass.\p"
	.string "They are the rivals to us,\n"
	.string "the sea-loving TEAM AQUA!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "BOSS, we should give chase to\n"
	.string "TEAM MAGMA…$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "ARCHIE: Yes, yes, we must!\n"
	.string "We've got to hurry.\p"
	.string "There's no telling what TEAM MAGMA\n"
	.string "will do at MT. CHIMNEY!$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "ARCHIE: {PLAYER}, you should keep\n"
	.string "an eye out for TEAM MAGMA, too.\p"
	.string "Farewell!$"

MeteorFalls_1F_1R_Text_IWasTooWeak:
	.string "MAY: {PLAYER}{KUN}…\p"
	.string "I tried to stop TEAM MAGMA from\n"
	.string "stealing the METEORITE…\p"
	.string "But I was too weak…\n"
	.string "I never stood a chance…\p"
	.string "I hate to say it, but I think you\n"
	.string "are the only one who can stop them.\p"
	.string "I'll stay here and look after\n"
	.string "PROFESSOR COZMO.\p"
	.string "You should go after TEAM MAGMA.\n"
	.string "There's no telling what they'll do…$"

MeteorFalls_1F_1R_Text_ThoughtIWasStronger:
	.string "BRENDAN: {PLAYER}…\p"
	.string "I thought I was stronger than that…\p"
	.string "I thought I could stand up to those\n"
	.string "TEAM MAGMA goons…\p"
	.string "But that ADMIN thrashed me good…\p"
	.string "I really hate to admit it, but I\n"
	.string "think you're stronger than me.\p"
	.string "You have to stop TEAM MAGMA!\n"
	.string "Who knows what they're planning?\p"
	.string "I'll stay here and protect PROF.\n"
	.string "COZMO instead.$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "I… I'm COZMO…\n"
	.string "I'm a PROFESSOR…\p"
	.string "TEAM MAGMA asked me to guide them\n"
	.string "to METEOR FALLS…\p"
	.string "But they tricked me.\n"
	.string "They even took my METEORITE away…\p"
	.string "And then another similar bunch,\n"
	.string "TEAM AQUA showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "PROF. COZMO: But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

MeteorFalls_1F_1R_Text_MayChaseTeamMagma:
	.string "MAY: You should go after TEAM MAGMA.\n"
	.string "There's no telling what they'll do…$"

MeteorFalls_1F_1R_Text_BrendanChaseTeamMagma:
	.string "BRENDAN: You have to stop TEAM MAGMA!\n"
	.string "Who knows what they're planning?$"
