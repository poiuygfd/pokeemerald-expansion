SeafloorCavern_Room3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafloorCavern_Room3_OnTransition
	.byte 0

SeafloorCavern_Room3_OnTransition:
	call_if_ge VAR_SEAFLOOR_CAVERN_STATE, 1, SeafloorCavern_Room3_EventScript_MoveMatt
	call_if_ge VAR_SEAFLOOR_CAVERN_STATE, 2, SeafloorCavern_Room3_EventScript_MoveCarl
	end

SeafloorCavern_Room3_EventScript_MoveMatt::
	setobjectxyperm LOCALID_SEAFLOOR_CAVERN_MATT, 3, 13
	setobjectmovementtype LOCALID_SEAFLOOR_CAVERN_MATT, MOVEMENT_TYPE_FACE_DOWN
	return

SeafloorCavern_Room3_EventScript_MoveCarl::
	setobjectxyperm LOCALID_SEAFLOOR_CAVERN_MATT, 8, 4
	setobjectmovementtype LOCALID_SEAFLOOR_CAVERN_MATT, MOVEMENT_TYPE_FACE_DOWN
	return

SeafloorCavern_Room3_EventScript_MattTrigger0::
	lock
	setvar VAR_0x8008, 1
	goto SeafloorCavern_Room3_EventScript_MattBattle
	end

SeafloorCavern_Room3_EventScript_MattTrigger1::
	lock
	setvar VAR_0x8008, 2
	goto SeafloorCavern_Room3_EventScript_MattBattle
	end

SeafloorCavern_Room3_EventScript_MattTrigger2::
	lock
	setvar VAR_0x8008, 3
	goto SeafloorCavern_Room3_EventScript_MattBattle
	end

SeafloorCavern_Room3_EventScript_MattTrigger3::
	lock
	setvar VAR_0x8008, 4
	goto SeafloorCavern_Room3_EventScript_MattBattle
	end

SeafloorCavern_Room3_EventScript_MattTrigger4::
	lock
	setvar VAR_0x8008, 5
	goto SeafloorCavern_Room3_EventScript_MattBattle
	end

SeafloorCavern_Room3_EventScript_MattBattle::
	msgbox SeafloorCavern_Room3_Text_MattTheMusclehead, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	playse SE_PIN
	applymovement LOCALID_SEAFLOOR_CAVERN_MATT, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SEAFLOOR_CAVERN_MATT, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	delay 10
	call_if_eq VAR_0x8008, 1, SeafloorCavern_Room3_EventScript_MoveMattToPlayer0
	call_if_eq VAR_0x8008, 2, SeafloorCavern_Room3_EventScript_MoveMattToPlayer1
	call_if_eq VAR_0x8008, 3, SeafloorCavern_Room3_EventScript_MoveMattToPlayer2
	call_if_eq VAR_0x8008, 4, SeafloorCavern_Room3_EventScript_MoveMattToPlayer3
	call_if_eq VAR_0x8008, 5, SeafloorCavern_Room3_EventScript_MoveMattToPlayer4
	msgbox SeafloorCavern_Room3_Text_MattItsTheBrozo, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MATT_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_MattDefeat
	msgbox SeafloorCavern_Room3_Text_MattWasSupposedToStopYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	release
	end

SeafloorCavern_Room3_EventScript_MoveMattToPlayer0::
	applymovement LOCALID_SEAFLOOR_CAVERN_MATT, SeafloorCavern_Room3_Movement_MattApproachPlayer0
	waitmovement 0
	return

SeafloorCavern_Room3_EventScript_MoveMattToPlayer1::
	applymovement LOCALID_SEAFLOOR_CAVERN_MATT, SeafloorCavern_Room3_Movement_MattApproachPlayer1
	waitmovement 0
	return

SeafloorCavern_Room3_EventScript_MoveMattToPlayer2::
	applymovement LOCALID_SEAFLOOR_CAVERN_MATT, SeafloorCavern_Room3_Movement_MattApproachPlayer2
	waitmovement 0
	return

SeafloorCavern_Room3_EventScript_MoveMattToPlayer3::
	applymovement LOCALID_SEAFLOOR_CAVERN_MATT, Common_Movement_WalkDown
	waitmovement 0
	return

SeafloorCavern_Room3_EventScript_MoveMattToPlayer4::
	applymovement LOCALID_SEAFLOOR_CAVERN_MATT, SeafloorCavern_Room3_Movement_MattApproachPlayer4
	waitmovement 0
	return

SeafloorCavern_Room3_EventScript_Matt::
	msgbox SeafloorCavern_Room3_Text_MattMeetWithBoss, MSGBOX_NPC
	end

SeafloorCavern_Room3_Movement_MattApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

SeafloorCavern_Room3_Movement_MattApproachPlayer1:
	walk_left
	walk_left
	walk_down
	step_end

SeafloorCavern_Room3_Movement_MattApproachPlayer2:
	walk_left
	walk_down
	step_end

SeafloorCavern_Room3_Movement_MattApproachPlayer4:
	walk_right
	walk_down
	step_end

SeafloorCavern_Room3_EventScript_CarlTrigger0::
	lock
	applymovement LOCALID_PLAYER, SeafloorCavern_Room3_Movement_PlayerApproachCarl0
	waitmovement 0
	goto SeafloorCavern_Room3_EventScript_CarlBattle
	end

SeafloorCavern_Room3_EventScript_CarlTrigger1::
	lock
	applymovement LOCALID_PLAYER, SeafloorCavern_Room3_Movement_PlayerApproachCarl1
	waitmovement 0
	goto SeafloorCavern_Room3_EventScript_CarlBattle
	end

SeafloorCavern_Room3_EventScript_CarlTrigger2::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto SeafloorCavern_Room3_EventScript_CarlBattle
	end

SeafloorCavern_Room3_EventScript_CarlBattle::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	playse SE_PIN
	applymovement LOCALID_SEAFLOOR_CAVERN_CARL, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SEAFLOOR_CAVERN_CARL, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	delay 10
	msgbox SeafloorCavern_Room3_Text_GruntCarlYOU, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SEAFLOOR_CAVERN_CARL, Common_Movement_WalkDown
	waitmovement 0
	msgbox SeafloorCavern_Room3_Text_GruntCarlCrashesOut, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_CARL_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_GruntCarlDefeat
	msgbox SeafloorCavern_Room3_Text_GruntCarlNewJob, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SEAFLOOR_CAVERN_STATE, 2
	release
	end

SeafloorCavern_Room3_EventScript_GruntCarl::
	msgbox SeafloorCavern_Room3_Text_GruntCarlNewJob, MSGBOX_NPC
	end

SeafloorCavern_Room3_Movement_PlayerApproachCarl0:
	walk_right
	walk_right
	walk_up
	step_end

SeafloorCavern_Room3_Movement_PlayerApproachCarl1:
	walk_right
	walk_up
	step_end

SeafloorCavern_Room3_Text_MattTheMusclehead:
	.string "MATT: Uhhh…\n"
	.string "How do I get past the boulders again?\p"
	.string "Man, I'm not cut out for these kind\n"
	.string "of puzzles and stuff.\p"
	.string "Welp, I hope the GRUNT stuck back\n"
	.string "there knows how to get out!$"

SeafloorCavern_Room3_Text_MattItsTheBrozo:
	.string "Woah, it's the brozo!\n"
	.string "You seriously followed us here?\p"
	.string "And you did it without a submarine?\n"
	.string "Now that is seriously impressive!\p"
	.string "Honestly, I was hoping you would make\n"
	.string "it down here.\p"
	.string "I've been itching for a rematch for\n"
	.string "a while, and not getting to battle\l"
	.string "you at our HIDEOUT didn't help.\p"
	.string "But now, we can throw down with\n"
	.string "everything we've got!\p"
	.string "I'm burning brighter than ever!\n"
	.string "Hit me with everything you've got!$"

SeafloorCavern_Room3_Text_MattDefeat:
	.string "Man, that was an absolute blast!\n"
	.string "You've got serious grit!$"

SeafloorCavern_Room3_Text_MattWasSupposedToStopYou:
	.string "Oh, wait.\n"
	.string "I was supposed to stop you, huh.\p"
	.string "I got so caught up in our battle that\n"
	.string "I completely forgot why you were here.\p"
	.string "Well, maybe it's for the best that you\n"
	.string "and the BOSS throw down.\p"
	.string "I don't think the BOSS would be content\n"
	.string "unless he gets to crush you personally!\p"
SeafloorCavern_Room3_Text_MattMeetWithBoss:
	.string "Go ahead, go meet with the BOSS.\n"
	.string "He's just past these boulders.\p"
	.string "I can't wait to hear about how badly\n"
	.string "he beats you! Hah hah!$"

SeafloorCavern_Room3_Text_GruntCarlYOU:
	.string "YOU.$"

SeafloorCavern_Room3_Text_GruntCarlCrashesOut:
	.string "Of all the people to run into under the\n"
	.string "LITERAL ocean, of course it's YOU!\p"
	.string "I bet you don't even remember me!\n"
	.string "I can see the confusion on your face!\p"
	.string "After you thwarted me in the PETALBURG\n"
	.string "WOODS, and then stole the parts from me\l"
	.string "in RUSTURF TUNNEL, I thought I was over!\p"
	.string "The only reason I wasn't fired on the\n"
	.string "spot was because you beat SHELLY,\l"
	.string "which proved my loss wasn't my fault!\p"
	.string "That didn't stop them from giving me all\n"
	.string "the bottom rung jobs going forward!\p"
	.string "Do you even KNOW how many floors I've\n"
	.string "had to scrub since then?\p"
	.string "How many clothes I've had to wash?\n"
	.string "How many TOILETS I've had to clean?!\p"
	.string "Trust me, it is NOT fun cleaning toilets\n"
	.string "used by an ENTIRE ORGANISATION!\p"
	.string "And now, I've FINALLY been trusted with\n"
	.string "a mission of actual importance.\p"
	.string "AND YOU JUST HAD TO SHOW UP TO RUIN IT!\p"
	.string "I know I'm going to lose.\n"
	.string "And you know what? I don't care!\p"
	.string "I'm going to hit you with absolutely\n"
	.string "EVERYTHING I've got!\p"
	.string "If I can cause you even the SLIGHTEST\n"
	.string "of inconveniences, then I'll do it!\p"
	.string "So prepare yourself!\n"
	.string "Prepare to feel the wrath of CARL!!$"

SeafloorCavern_Room3_Text_GruntCarlDefeat:
	.string "Did I do anything?\n"
	.string "Did I so much as make you sweat?$"

SeafloorCavern_Room3_Text_GruntCarlNewJob:
	.string "Haaaaahh…\p"
	.string "You know what? I think I actually feel\n"
	.string "a little bit better after that.\p"
	.string "After this is all said and done, I think\n"
	.string "I'm just going to quit TEAM AQUA.\p"
	.string "I'm just not cut out for a life of crime.\n"
	.string "I'll just go get a job at the POKé MART…$"

