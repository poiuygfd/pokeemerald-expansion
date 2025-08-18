LilycoveCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
LilycoveCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

LilycoveCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

LilycoveCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

LilycoveCity_PokemonCenter_2F_EventScript_MrCap::
	buffernumberstring STR_VAR_1, VAR_LEVEL_CAP
	msgbox LilycoveCity_PokemonCenter_2F_Text_YourCurrentLevelCap, MSGBOX_NPC
	end

LilycoveCity_PokemonCenter_2F_Text_YourCurrentLevelCap::
	.string "Hello there! I'm MR. CAP!\n"
	.string "I can tell you the current level cap!\p"
	.string "Your current level cap is {STR_VAR_1}.$"
