GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end

GraniteCave_B1F_EventScript_Dave::
	trainerbattle_single TRAINER_DAVE, GraniteCave_B1F_Text_KnowWhereTheWayOutIs, GraniteCave_B1F_Text_DidntWantToBattle
	msgbox GraniteCave_B1F_Text_NowLostAndStuck, MSGBOX_AUTOCLOSE
	end

GraniteCave_B1F_EventScript_Paddy::
	trainerbattle_single TRAINER_PADDY, GraniteCave_B1F_Text_UnbelievablyRugged, GraniteCave_B1F_Text_HowdYouBreakPast
	msgbox GraniteCave_B1F_Text_YoureAlsoPrettyRugged, MSGBOX_AUTOCLOSE
	end

GraniteCave_B1F_Text_KnowWhereTheWayOutIs:
	.string "Hey there!\p"
	.string "I don't suppose you know where\n"
	.string "they way out is?$"

GraniteCave_B1F_Text_DidntWantToBattle:
	.string "I didn't want to battle!\n"
	.string "I just wanted the way out!$"

GraniteCave_B1F_Text_NowLostAndStuck:
	.string "Great!\p"
	.string "Now I'm lost AND all my\n"
	.string "POKéMON have fainted!\p"
	.string "Thanks for nothing!$"

GraniteCave_B1F_Text_UnbelievablyRugged:
	.string "My body is unbelievably rugged.\n"
	.string "Just like my POKéMON, too!$"

GraniteCave_B1F_Text_HowdYouBreakPast:
	.string "How'd you break past my\n"
	.string "rugged POKéMON's defenses?$"

GraniteCave_B1F_Text_YoureAlsoPrettyRugged:
	.string "You and your POKéMON are also\n"
	.string "pretty rugged, it turns out!$"
