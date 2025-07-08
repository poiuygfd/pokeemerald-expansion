TheDepths_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TheDepths_B3F_OnLoad
	.byte 0

TheDepths_B3F_OnLoad:
	call TheDepths_B3F_EventScript_SpawnRuby
	call TheDepths_B3F_EventScript_SpawnSapphire
	end

TheDepths_B3F_EventScript_SpawnRuby::
	random 2
	call_if_eq VAR_RESULT, 0, TheDepths_B3F_EventScript_SpawnRuby1
	call_if_eq VAR_RESULT, 1, TheDepths_B3F_EventScript_SpawnRuby2
	return

TheDepths_B3F_EventScript_SpawnRuby1::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 11, 49, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B3F_RUBY_2, 0, 0
	return

TheDepths_B3F_EventScript_SpawnRuby2::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 48, 16, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B3F_RUBY_1, 0, 0
	return

TheDepths_B3F_EventScript_SpawnSapphire::
	random 2
	call_if_eq VAR_RESULT, 0, TheDepths_B3F_EventScript_SpawnSapphire1
	call_if_eq VAR_RESULT, 1, TheDepths_B3F_EventScript_SpawnSapphire2
	return

TheDepths_B3F_EventScript_SpawnSapphire1::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 7, 18, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B3F_SAPPHIRE_2, 0, 0
	return

TheDepths_B3F_EventScript_SpawnSapphire2::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 49, 49, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B3F_SAPPHIRE_1, 0, 0
	return

TheDepths_B3F_EventScript_RemoveRuby1::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 11, 49, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B3F_EventScript_RemoveRuby2::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 48, 16, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B3F_EventScript_RemoveSapphire1::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 7, 18, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B3F_EventScript_RemoveSapphire2::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 49, 49, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B3F_EventScript_GemSocket::
	lock
	call_if_eq VAR_DEPTHS_STATE, 3, TheDepths_EventScript_GemSocketActive
	call TheDepths_EventScript_GemSocketCheckRuby
	setmetatile 29, 16, METATILE_NavelRock_Floor, FALSE
	setmetatile 30, 16, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 16, METATILE_NavelRock_Floor, FALSE
	setmetatile 29, 17, METATILE_NavelRock_Floor, FALSE
	setmetatile 30, 17, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 17, METATILE_NavelRock_Floor, FALSE
	special DrawWholeMapView
	setvar VAR_DEPTHS_STATE, 3
	release
	end

TheDepths_B3F_EventScript_StrongPresence::
	lock
	copyvar VAR_TEMP_1, VAR_LEVEL_CAP
	setvar VAR_LEVEL_CAP, 1
	setflag FLAG_PREVENT_BAG_USE
	setflag FLAG_PREVENT_CATCHING
	msgbox TheDepths_Text_StrongPresence
	closemessage
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B3F_EventScript_MawileBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B3F_EventScript_SableyeBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B3F_EventScript_CarbinkBattle

TheDepths_B3F_EventScript_MawileBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setbossbattle SPECIES_MAWILE, MOVE_IRON_HEAD, MOVE_PLAY_ROUGH, MOVE_SUCKER_PUNCH, MOVE_FLAMETHROWER, 2
	dowildbattle
	goto TheDepths_B3F_EventScript_BattleAftermath

TheDepths_B3F_EventScript_SableyeBattle::
	settotemboost 1, 1, 1, 1, 1, 2
	setbossbattle SPECIES_SABLEYE, MOVE_NIGHT_SHADE, MOVE_KNOCK_OFF, MOVE_WILL_O_WISP, MOVE_RECOVER, 2
	dowildbattle
	goto TheDepths_B3F_EventScript_BattleAftermath

TheDepths_B3F_EventScript_CarbinkBattle::
	settotemboost 1, 1, 1, 1, 2, 1
	setbossbattle SPECIES_CARBINK, MOVE_POWER_GEM, MOVE_DAZZLING_GLEAM, MOVE_REFLECT, MOVE_LIGHT_SCREEN, 0
	dowildbattle
	goto TheDepths_B3F_EventScript_BattleAftermath

TheDepths_B3F_EventScript_BattleAftermath::
	setvar VAR_DEPTHS_MON_STATE, 3
	copyvar VAR_LEVEL_CAP, VAR_TEMP_1
	clearflag FLAG_PREVENT_BAG_USE
	clearflag FLAG_PREVENT_CATCHING
	msgbox TheDepths_Text_StrongPresenceLeaves
	closemessage
	end
