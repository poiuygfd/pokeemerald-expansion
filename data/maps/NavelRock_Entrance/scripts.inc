NavelRock_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Entrance_OnTransition
	.byte 0

NavelRock_Entrance_OnTransition:
	setflag FLAG_ARRIVED_AT_NAVEL_ROCK
	end

NavelRock_Entrance_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_NAVEL_ROCK_1, NavelRock_Entrance_Text_Grunt1Intro, NavelRock_Entrance_Text_Grunt1Defeat
	msgbox NavelRock_Entrance_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

NavelRock_Entrance_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_NAVEL_ROCK_2, NavelRock_Entrance_Text_Grunt2Intro, NavelRock_Entrance_Text_Grunt2Defeat
	msgbox NavelRock_Entrance_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

NavelRock_Entrance_Text_Grunt1Intro:
	.string "Coming to a dry, desolate desert like\n"
	.string "this place is a nightmare for TEAM AQUA!\p"
	.string "Whatever we're here for, it better be\n"
	.string "worth the effort!$"

NavelRock_Entrance_Text_Grunt1Defeat:
	.string "Now I'm even more irritated!$"

NavelRock_Entrance_Text_Grunt1PostBattle:
	.string "I hope this ends soon…\n"
	.string "I could really go for a swim…$"

NavelRock_Entrance_Text_Grunt2Intro:
	.string "I wish I could be as big and strong\n"
	.string "as ADMIN MATT is.\p"
	.string "His manliness levels are off the charts!$"

NavelRock_Entrance_Text_Grunt2Defeat:
	.string "MATT would never lose to a pipsqueak\n"
	.string "like you…$"

NavelRock_Entrance_Text_Grunt2PostBattle:
	.string "I still have a long way to go, but my\n"
	.string "goal will remain the same regardless!$"
