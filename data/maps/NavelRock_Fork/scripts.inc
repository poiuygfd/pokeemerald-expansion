NavelRock_Fork_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Fork_OnTransition
	.byte 0

NavelRock_Fork_OnTransition:
	call_if_set FLAG_NAVEL_ROCK_GUARDIAN_MOVED, NavelRock_Fork_EventScript_GuardianHasMoved
	end

NavelRock_Fork_EventScript_GuardianHasMoved::
	setobjectxyperm LOCALID_NAVEL_ROCK_GUARDIAN, 12, 9
	return

NavelRock_Fork_EventScript_Guardian::
	lock
	faceplayer
	goto_if_set FLAG_NAVEL_ROCK_GUARDIAN_MOVED, NavelRock_Fork_EventScript_GuardianMoved
	goto_if_set FLAG_IS_CHAMPION, NavelRock_Fork_EventScript_GuardianMove
	msgbox NavelRock_Fork_Text_TooDangerous, MSGBOX_DEFAULT
	release
	end

NavelRock_Fork_EventScript_GuardianMoved::
	msgbox NavelRock_Fork_Text_GoodLuck, MSGBOX_DEFAULT
	release
	end

NavelRock_Fork_EventScript_GuardianMove::
	msgbox NavelRock_Fork_Text_YouShouldBeStrongEnough, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_NAVEL_ROCK_GUARDIAN, NavelRock_Fork_Movement_MoveGuardian
	waitmovement 0
	setflag FLAG_NAVEL_ROCK_GUARDIAN_MOVED
	release
	end

NavelRock_Fork_Movement_MoveGuardian:
	walk_left
	walk_in_place_down
	step_end

NavelRock_Fork_EventScript_MattTrigger::
	lock
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox NavelRock_Fork_Text_WhereIsLugia, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, NavelRock_Fork_Movement_PlayerWalkUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_NAVEL_ROCK_MATT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_NAVEL_ROCK_MATT, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox NavelRock_Fork_Text_SoYoureThatKid, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MATT_NAVEL_ROCK, NavelRock_Fork_Text_MattDefeat
	msgbox NavelRock_Fork_Text_LeaveForNow, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	removeobject LOCALID_NAVEL_ROCK_MATT
	removeobject LOCALID_NAVEL_ROCK_GRUNT_M
	removeobject LOCALID_NAVEL_ROCK_GRUNT_F
	setflag FLAG_HIDE_NAVEL_ROCK_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 30
	applymovement LOCALID_NAVEL_ROCK_GUARDIAN, NavelRock_Fork_Movement_GuardianWalkDown
	waitmovement 0
	msgbox NavelRock_Fork_Text_ThankYouForChasingOff, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	msgbox NavelRock_Fork_Text_MaybeOneDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_NAVEL_ROCK_GUARDIAN, NavelRock_Fork_Movement_GuardianWalkUp
	waitmovement 0
	setvar VAR_TUFFNOOK_TOWN_STATE, 3
	release
	end

NavelRock_Fork_Movement_PlayerWalkUp:
	walk_up
	step_end

NavelRock_Fork_Movement_GuardianWalkDown:
	walk_down
	walk_down
	step_end

NavelRock_Fork_Movement_GuardianWalkUp:
	walk_up
	walk_up
	face_down
	step_end

NavelRock_Fork_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_NAVEL_ROCK_3, NavelRock_Fork_Text_Grunt3Intro, NavelRock_Fork_Text_Grunt3Defeat
	msgbox NavelRock_Fork_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

NavelRock_Fork_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_NAVEL_ROCK_4, NavelRock_Fork_Text_Grunt4Intro, NavelRock_Fork_Text_Grunt4Defeat
	msgbox NavelRock_Fork_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

NavelRock_Fork_Text_TooDangerous:
	.string "I am afraid that going any further\n"
	.string "is not permitted for just anyone.\p"
	.string "There have been reports from the\n"
	.string "people of TUFFNOOK that some very\l"
	.string "powerful and dangerous POKéMON\l"
	.string "reside further up ahead.\p"
	.string "I don't think I could let anyone\n"
	.string "who isn't as strong as a CHAMPION\l"
	.string "pass through here.$"

NavelRock_Fork_Text_YouShouldBeStrongEnough:
	.string "Hmm… That look in your eyes…\n"
	.string "You might just be strong enough…\p"
	.string "Very well!\n"
	.string "I will permit you to proceed onwards.\p"
	.string "Please exercise great caution.$"

NavelRock_Fork_Text_GoodLuck:
	.string "I wish you luck, young TRAINER.$"

NavelRock_Fork_Text_WhereIsLugia:
	.string "MATT: So, you aren't gonna let me\n"
	.string "through, no matter what?\l"
	.string "For my own safety, even?\p"
	.string "Bahahaha! That all but comfirms the\n"
	.string "rumour claiming LUGIA has been found\l"
	.string "down there was right on the money!\p"
	.string "Sorry, old man, but you're gonna need to\n"
	.string "get out the way, and I'm not asking!$"

NavelRock_Fork_Text_SoYoureThatKid:
	.string "So, judging by your appearance, you're\n"
	.string "that kid that ARCHIE was talking about.\p"
	.string "Heard you gave both the BOSS and even\n"
	.string "that MAXIE from TEAM MAGMA a beating!\p"
	.string "After hearing something like that, I\n"
	.string "couldn't wait to battle you myself!\p"
	.string "Hahaha! I'm all fired up!\n"
	.string "Let's do this!$"

NavelRock_Fork_Text_MattDefeat:
	.string "Hahahaha!\n"
	.string "I'm burning up!$"

NavelRock_Fork_Text_LeaveForNow:
	.string "You really are as strong as they say!\n"
	.string "Alright, I'll leave for now!\p"
	.string "As tempting as LUGIA is, we already have\n"
	.string "a different LEGENDARY POKéMON in mind!\p"
	.string "One that'll make our dream a cake walk!\p"
	.string "Try and stop us if you can!\n"
	.string "TEAM, we're retreating for now!$"

NavelRock_Fork_Text_ThankYouForChasingOff:
	.string "Thank you for chasing those ruffians\n"
	.string "off there, young one.\p"
	.string "I don't know where he heard that rumour\n"
	.string "from, but if he had forced his way in\l"
	.string "there, it could have ended badly.\p"
	.string "Take this as a token of my gratitude.$"

NavelRock_Fork_Text_MaybeOneDay:
	.string "For a TRAINER like you, maybe one day\n"
	.string "I could let you pass on further.\p"
	.string "I think you will need to get a little\n"
	.string "stronger than you are now, though.\p"
	.string "But should you, say, ever become strong\n"
	.string "enough to become a CHAMPION, I might\l"
	.string "feel safe in letting you through.$"

NavelRock_Fork_Text_Grunt3Intro:
	.string "Sorry, but I've been ordered to not let\n"
	.string "a single person get past me!\p"
	.string "Unlucky for you that you had to run into\n"
	.string "me, TEAM AQUA's secret weapon!$"

NavelRock_Fork_Text_Grunt3Defeat:
	.string "Okay, maybe I gave myself that title.\n"
	.string "Can't a guy dream a little?$"

NavelRock_Fork_Text_Grunt3PostBattle:
	.string "Okay, I know I'm not that strong, but\n"
	.string "I really wanted to try saying that.$"

NavelRock_Fork_Text_Grunt4Intro:
	.string "We've heard a rumour that a powerful\n"
	.string "POKéMON called the guardian of the sea\l"
	.string "was found deep, deep down in this cave.\p"
	.string "Since it's just a rumour, ARCHIE has sent\n"
	.string "MATT instead of coming himself.\p"
	.string "But if that rumour turns out to be true…$"

NavelRock_Fork_Text_Grunt4Defeat:
	.string "Wait, why did I tell you all that?\n"
	.string "MATT would end me if he found out!$"

NavelRock_Fork_Text_Grunt4PostBattle:
	.string "Can we keep the fact that I blabbed\n"
	.string "between us?\p"
	.string "I mean, I gave you some pretty useful\n"
	.string "info, so fair is fair, right?$"

