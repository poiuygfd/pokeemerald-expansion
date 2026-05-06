SouthernIsland_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Exterior_OnTransition
	.byte 0

SouthernIsland_Exterior_OnTransition:
	setflag FLAG_LANDMARK_SOUTHERN_ISLAND
	end

SouthernIsland_Exterior_EventScript_Sailor::
	lock
	faceplayer
	msgbox EventTicket_Text_SouthernIslandSailBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SouthernIsland_Exterior_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SOUTHERN_ISLAND_SAILOR, MAP_SOUTHERN_ISLAND_EXTERIOR
	setvar VAR_0x8004, LOCALID_SOUTHERN_ISLAND_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SouthernIsland_Exterior_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

SouthernIsland_Exterior_EventScript_Latios::
	lock
	msgbox SouthernIsland_Exterior_Text_FlyToRoute118, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SouthernIsland_Exterior_EventScript_FlyToRoute
	closemessage
	release
	end

SouthernIsland_Exterior_EventScript_FlyToRoute::
	playmoncry SPECIES_LATIOS, CRY_MODE_ENCOUNTER
	warp MAP_ROUTE118, 52, 10
	waitstate
	release
	end

SouthernIsland_Exterior_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SOUTHERN_ISLAND_1, SouthernIsland_Exterior_Text_Grunt1Intro, SouthernIsland_Exterior_Text_Grunt1Defeat
	msgbox SouthernIsland_Exterior_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SouthernIsland_Exterior_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SOUTHERN_ISLAND_2, SouthernIsland_Exterior_Text_Grunt2Intro, SouthernIsland_Exterior_Text_Grunt2Defeat
	msgbox SouthernIsland_Exterior_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Ferry_EventScript_DepartIslandSouth::
	applymovement LOCALID_PLAYER, Ferry_Movement_DepartIslandBoardSouth
	waitmovement 0
	return

Ferry_EventScript_DepartIslandWest::
	applymovement LOCALID_PLAYER, Ferry_Movement_DepartIslandBoardWest
	waitmovement 0
	return

Ferry_Movement_DepartIslandBoardSouth:
	walk_down
	step_end

Ferry_Movement_DepartIslandBoardWest:
	walk_left
	walk_in_place_faster_down
	step_end

SouthernIsland_Exterior_EventScript_Sign::
	msgbox SouthernIsland_Exterior_Text_Sign, MSGBOX_SIGN
	end

SouthernIsland_Exterior_Text_FlyToRoute118:
	.string "Would you like LATIOS to fly you back\n"
	.string "to ROUTE 118?$"

SouthernIsland_Exterior_Text_Grunt1Intro:
	.string "Yikes! Look at all that water!\n"
	.string "This place is terrifying for TEAM MAGMA!\p"
	.string "I hope we don't have to stick around\n"
	.string "for too long here!$"

SouthernIsland_Exterior_Text_Grunt1Defeat:
	.string "A scary TRAINER on a scary island!$"

SouthernIsland_Exterior_Text_Grunt1PostBattle:
	.string "I hope this ends soon…\n"
	.string "I could really go for a hike…$"

SouthernIsland_Exterior_Text_Grunt2Intro:
	.string "Gosh, COURTNEY is just so cute!\n"
	.string "The way she speaks is so funny!\l"
	.string "I mean in an endearing way, of course!$"

SouthernIsland_Exterior_Text_Grunt2Defeat:
	.string "I'm sorry, COURTNEY!\n"
	.string "I've let you down…$"

SouthernIsland_Exterior_Text_Grunt2PostBattle:
	.string "I may be a weak TRAINER, but I will\n"
	.string "always be the number one COURTNEY fan!$"
