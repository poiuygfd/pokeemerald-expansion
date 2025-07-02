TuffnookTown_DepthsEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TuffnookTown_DepthsEntrance_OnWarp
	.byte 0

TuffnookTown_DepthsEntrance_OnWarp:
	map_script_2 VAR_DEPTHS_STATE, 9, TuffnookTown_DepthsEntrance_EventScript_TurnPlayerNorth
	.2byte 0

TuffnookTown_DepthsEntrance_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_DEPTHS_STATE, 0
	setvar VAR_DEPTHS_MON_STATE, 0 @ move these to the hiker when the hiker is made since currently these won't reset if player whites out
    end

TuffnookTown_DepthsEntrance_EventScript_Cooltrainer::
	msgbox TuffnookTown_DepthsEntrance_Text_PreparingForNextDive, MSGBOX_NPC
	end

TuffnookTown_DepthsEntrance_EventScript_Picnicker::
	msgbox TuffnookTown_DepthsEntrance_Text_ThisPlaceIsTough, MSGBOX_NPC
	end

TuffnookTown_DepthsEntrance_Text_PreparingForNextDive:
	.string "I'm just preparing for my next dive\n"
	.string "into THE DEPTHS.\p"
	.string "For a COOLTRAINER like me, this will\n"
	.string "surely be a breeze!$"

TuffnookTown_DepthsEntrance_Text_ThisPlaceIsTough:
	.string "This place is tough…\n"
	.string "Those boss POKéMON are way too strong!\p"
	.string "How did they even get that strong on\n"
	.string "their own in the first place?$"

TuffnookTown_DepthsEntrance_Text_BetterLuckNextTime:
	.string "Better luck next time, kid.\p"
	.string "If you wish to challenge THE DEPTHS\n"
    .string "again, come back anytime!$"
