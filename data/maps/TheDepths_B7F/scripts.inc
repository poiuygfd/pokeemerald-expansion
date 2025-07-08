TheDepths_B7F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TheDepths_B7F_OnLoad
	.byte 0

TheDepths_B7F_OnLoad:
	call TheDepths_B7F_EventScript_SpawnRuby
	call TheDepths_B7F_EventScript_SpawnSapphire
	end

TheDepths_B7F_EventScript_SpawnRuby::
	random 4
	call_if_eq VAR_RESULT, 0, TheDepths_B7F_EventScript_SpawnRuby1
	call_if_eq VAR_RESULT, 1, TheDepths_B7F_EventScript_SpawnRuby2
	call_if_eq VAR_RESULT, 2, TheDepths_B7F_EventScript_SpawnRuby3
	call_if_eq VAR_RESULT, 3, TheDepths_B7F_EventScript_SpawnRuby4
	return

TheDepths_B7F_EventScript_SpawnRuby1::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 19, 12, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_2, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_3, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_4, 0, 0
	return

TheDepths_B7F_EventScript_SpawnRuby2::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 38, 9, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_3, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_4, 0, 0
	return

TheDepths_B7F_EventScript_SpawnRuby3::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 8, 43, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_2, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_4, 0, 0
	return

TheDepths_B7F_EventScript_SpawnRuby4::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 55, 50, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_2, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_RUBY_3, 0, 0
	return

TheDepths_B7F_EventScript_SpawnSapphire::
	random 4
	call_if_eq VAR_RESULT, 0, TheDepths_B7F_EventScript_SpawnSapphire1
	call_if_eq VAR_RESULT, 1, TheDepths_B7F_EventScript_SpawnSapphire2
	call_if_eq VAR_RESULT, 2, TheDepths_B7F_EventScript_SpawnSapphire3
	call_if_eq VAR_RESULT, 3, TheDepths_B7F_EventScript_SpawnSapphire4
	return

TheDepths_B7F_EventScript_SpawnSapphire1::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 4, 13, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_2, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_3, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_4, 0, 0
	return

TheDepths_B7F_EventScript_SpawnSapphire2::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 56, 13, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_3, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_4, 0, 0
	return

TheDepths_B7F_EventScript_SpawnSapphire3::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 24, 43, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_2, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_4, 0, 0
	return

TheDepths_B7F_EventScript_SpawnSapphire4::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 42, 47, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_2, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B7F_SAPPHIRE_3, 0, 0
	return

TheDepths_B7F_EventScript_RemoveRuby1::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 19, 12, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B7F_EventScript_RemoveRuby2::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 38, 9, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B7F_EventScript_RemoveRuby3::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 8, 43, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B7F_EventScript_RemoveRuby4::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 55, 50, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B7F_EventScript_RemoveSapphire1::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 4, 13, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B7F_EventScript_RemoveSapphire2::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 56, 13, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B7F_EventScript_RemoveSapphire3::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 24, 43, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B7F_EventScript_RemoveSapphire4::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 42, 47, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B7F_EventScript_GemSocket::
	lock
	call_if_eq VAR_DEPTHS_STATE, 7, TheDepths_EventScript_GemSocketActive
	call TheDepths_EventScript_GemSocketCheckRuby
	setmetatile 28, 27, METATILE_NavelRock_Floor, FALSE
	setmetatile 29, 27, METATILE_NavelRock_Floor, FALSE
	setmetatile 30, 27, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 27, METATILE_NavelRock_Floor, FALSE
	setmetatile 32, 27, METATILE_NavelRock_Floor, FALSE
	setmetatile 28, 28, METATILE_NavelRock_Floor, FALSE
	setmetatile 29, 28, METATILE_NavelRock_Floor, FALSE
	setmetatile 30, 28, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 28, METATILE_NavelRock_Floor, FALSE
	setmetatile 32, 28, METATILE_NavelRock_Floor, FALSE
	special DrawWholeMapView
	setvar VAR_DEPTHS_STATE, 7
	release
	end
