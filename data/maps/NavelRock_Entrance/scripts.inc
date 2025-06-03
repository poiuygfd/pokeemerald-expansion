NavelRock_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Entrance_OnTransition
	.byte 0

NavelRock_Entrance_OnTransition:
	setflag FLAG_ARRIVED_AT_NAVEL_ROCK
	end
