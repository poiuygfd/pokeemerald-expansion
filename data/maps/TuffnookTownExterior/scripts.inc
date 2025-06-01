TuffnookTownExterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TuffnookTownExterior_OnTransition
	.byte 0

TuffnookTownExterior_OnTransition:
	setflag FLAG_VISITED_TUFFNOOK_TOWN
	end
