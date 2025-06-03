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
