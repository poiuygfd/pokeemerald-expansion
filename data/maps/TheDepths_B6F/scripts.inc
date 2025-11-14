TheDepths_B6F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TheDepths_B6F_OnLoad
	.byte 0

TheDepths_B6F_OnLoad:
	call_if_unset FLAG_B6F_SPAWNED_GEMS, TheDepths_B6F_EventScript_SpawnGems
	call_if_set FLAG_B6F_SPAWNED_GEMS, TheDepths_B6F_EventScript_LoadGems
	end

TheDepths_B6F_EventScript_SpawnGems::
	setflag FLAG_B6F_SPAWNED_GEMS
	call TheDepths_B6F_EventScript_SpawnRuby
	call TheDepths_B6F_EventScript_SpawnSapphire
	return

TheDepths_B6F_EventScript_LoadGems::
	call_if_eq VAR_B6F_SPAWNED_RUBY, 1, TheDepths_B6F_EventScript_SpawnRuby1
	call_if_eq VAR_B6F_SPAWNED_RUBY, 2, TheDepths_B6F_EventScript_SpawnRuby2
	call_if_eq VAR_B6F_SPAWNED_RUBY, 3, TheDepths_B6F_EventScript_SpawnRuby3
	call_if_eq VAR_B6F_SPAWNED_SAPPHIRE, 1, TheDepths_B6F_EventScript_SpawnSapphire1
	call_if_eq VAR_B6F_SPAWNED_SAPPHIRE, 2, TheDepths_B6F_EventScript_SpawnSapphire2
	call_if_eq VAR_B6F_SPAWNED_SAPPHIRE, 3, TheDepths_B6F_EventScript_SpawnSapphire3
	return

TheDepths_B6F_EventScript_SpawnRuby::
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B6F_EventScript_SpawnRuby1
	call_if_eq VAR_RESULT, 1, TheDepths_B6F_EventScript_SpawnRuby2
	call_if_eq VAR_RESULT, 2, TheDepths_B6F_EventScript_SpawnRuby3
	return

TheDepths_B6F_EventScript_SpawnRuby1::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setvar VAR_B6F_SPAWNED_RUBY, 1
	setmetatile 49, 24, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_RUBY_2, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_RUBY_3, 0, 0
	return

TheDepths_B6F_EventScript_SpawnRuby2::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setvar VAR_B6F_SPAWNED_RUBY, 2
	setmetatile 13, 38, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_RUBY_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_RUBY_3, 0, 0
	return

TheDepths_B6F_EventScript_SpawnRuby3::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setvar VAR_B6F_SPAWNED_RUBY, 3
	setmetatile 50, 54, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_RUBY_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_RUBY_2, 0, 0
	return

TheDepths_B6F_EventScript_SpawnSapphire::
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B6F_EventScript_SpawnSapphire1
	call_if_eq VAR_RESULT, 1, TheDepths_B6F_EventScript_SpawnSapphire2
	call_if_eq VAR_RESULT, 2, TheDepths_B6F_EventScript_SpawnSapphire3
	return

TheDepths_B6F_EventScript_SpawnSapphire1::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setvar VAR_B6F_SPAWNED_SAPPHIRE, 1
	setmetatile 44, 7, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_SAPPHIRE_2, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_SAPPHIRE_3, 0, 0
	return

TheDepths_B6F_EventScript_SpawnSapphire2::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setvar VAR_B6F_SPAWNED_SAPPHIRE, 2
	setmetatile 40, 40, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_SAPPHIRE_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_SAPPHIRE_3, 0, 0
	return

TheDepths_B6F_EventScript_SpawnSapphire3::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setvar VAR_B6F_SPAWNED_SAPPHIRE, 3
	setmetatile 17, 54, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_SAPPHIRE_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B6F_SAPPHIRE_2, 0, 0
	return

TheDepths_B6F_EventScript_RemoveRuby1::
	lock
	call TheDepths_EventScript_Ruby
	setvar VAR_B6F_SPAWNED_RUBY, 0
	setmetatile 49, 24, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B6F_EventScript_RemoveRuby2::
	lock
	call TheDepths_EventScript_Ruby
	setvar VAR_B6F_SPAWNED_RUBY, 0
	setmetatile 13, 38, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B6F_EventScript_RemoveRuby3::
	lock
	call TheDepths_EventScript_Ruby
	setvar VAR_B6F_SPAWNED_RUBY, 0
	setmetatile 50, 54, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B6F_EventScript_RemoveSapphire1::
	lock
	call TheDepths_EventScript_Sapphire
	setvar VAR_B6F_SPAWNED_SAPPHIRE, 0
	setmetatile 44, 7, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B6F_EventScript_RemoveSapphire2::
	lock
	call TheDepths_EventScript_Sapphire
	setvar VAR_B6F_SPAWNED_SAPPHIRE, 0
	setmetatile 40, 40, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B6F_EventScript_RemoveSapphire3::
	lock
	call TheDepths_EventScript_Sapphire
	setvar VAR_B6F_SPAWNED_SAPPHIRE, 0
	setmetatile 17, 54, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B6F_EventScript_GemSocket::
	lock
	call_if_eq VAR_DEPTHS_STATE, 6, TheDepths_EventScript_GemSocketActive
	call TheDepths_EventScript_GemSocketCheckRuby
	setmetatile 21, 15, METATILE_NavelRock_Floor, FALSE
	setmetatile 22, 15, METATILE_NavelRock_Floor, FALSE
	setmetatile 23, 15, METATILE_NavelRock_Floor, FALSE
	setmetatile 24, 15, METATILE_NavelRock_Floor, FALSE
	setmetatile 25, 15, METATILE_NavelRock_Floor, FALSE
	setmetatile 26, 15, METATILE_NavelRock_Floor, FALSE
	setmetatile 21, 16, METATILE_NavelRock_Floor, FALSE
	setmetatile 22, 16, METATILE_NavelRock_Floor, FALSE
	setmetatile 23, 16, METATILE_NavelRock_Floor, FALSE
	setmetatile 24, 16, METATILE_NavelRock_Floor, FALSE
	setmetatile 25, 16, METATILE_NavelRock_Floor, FALSE
	setmetatile 26, 16, METATILE_NavelRock_Floor, FALSE
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_DEPTHS_STATE, 6
	release
	end

TheDepths_B6F_EventScript_StrongPresence::
	lock
	goto_if_set FLAG_DEPTHS_IS_NORMAL, TheDepths_B6F_EventScript_NormalPresence
	goto_if_set FLAG_DEPTHS_IS_EXPERT, TheDepths_B6F_EventScript_ExpertPresence
	goto_if_set FLAG_DEPTHS_IS_MASTER, TheDepths_B6F_EventScript_MasterPresence
	goto TheDepths_B6F_EventScript_NormalPresence

TheDepths_B6F_EventScript_NormalPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B6F_EventScript_SandslashBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B6F_EventScript_SandacondaBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B6F_EventScript_ExcadrillBattle

TheDepths_B6F_EventScript_SandslashBattle::
	settotemboost 1, 2, 1, 1, 1, 1
	setbossbattle SPECIES_SANDSLASH, MOVE_DIG, MOVE_BRICK_BREAK, MOVE_SHADOW_CLAW, MOVE_SANDSTORM, 2
	dowildbattle
	goto TheDepths_B6F_EventScript_BattleAftermath

TheDepths_B6F_EventScript_SandacondaBattle::
	settotemboost 1, 1, 2, 1, 1, 1
	setbossbattle SPECIES_SANDACONDA, MOVE_DIG, MOVE_BODY_PRESS, MOVE_HEADBUTT, MOVE_GLARE, 0
	dowildbattle
	goto TheDepths_B6F_EventScript_BattleAftermath

TheDepths_B6F_EventScript_ExcadrillBattle::
	settotemboost 1, 1, 1, 1, 1, 2
	setbossbattle SPECIES_EXCADRILL, MOVE_BULLDOZE, MOVE_METAL_CLAW, MOVE_CRUSH_CLAW, MOVE_HONE_CLAWS, 2
	dowildbattle
	goto TheDepths_B6F_EventScript_BattleAftermath

TheDepths_B6F_EventScript_ExpertPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B6F_EventScript_FlygonBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B6F_EventScript_KrookodileBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B6F_EventScript_HaxorusBattle

TheDepths_B6F_EventScript_FlygonBattle::
	settotemboost 1, 2, 1, 1, 1, 1
	setbossbattle SPECIES_FLYGON, MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_DRAGON_TAIL, MOVE_DRAGON_DANCE, 0
	dowildbattle
	goto TheDepths_B6F_EventScript_BattleAftermath

TheDepths_B6F_EventScript_KrookodileBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setbossbattle SPECIES_KROOKODILE, MOVE_POWER_TRIP, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_HONE_CLAWS, 1
	dowildbattle
	goto TheDepths_B6F_EventScript_BattleAftermath

TheDepths_B6F_EventScript_HaxorusBattle::
	settotemboost 1, 2, 1, 1, 1, 1
	setbossbattle SPECIES_HAXORUS, MOVE_DRAGON_CLAW, MOVE_IRON_HEAD, MOVE_TRAILBLAZE, MOVE_SWORDS_DANCE, 1
	dowildbattle
	goto TheDepths_B6F_EventScript_BattleAftermath

TheDepths_B6F_EventScript_MasterPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B6F_EventScript_GoodraBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B6F_EventScript_MetagrossBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B6F_EventScript_ArchaludonBattle

TheDepths_B6F_EventScript_GoodraBattle::
	settotemboost 1, 1, 2, 2, 1, 1
	setbossbattle SPECIES_GOODRA, MOVE_DRAGON_PULSE, MOVE_MUDDY_WATER, MOVE_THUNDERBOLT, MOVE_POWER_WHIP, 2
	dowildbattle
	goto TheDepths_B6F_EventScript_BattleAftermath

TheDepths_B6F_EventScript_MetagrossBattle::
	settotemboost 1, 2, 2, 1, 1, 1
	setbossbattle SPECIES_METAGROSS, MOVE_METEOR_MASH, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH, 0
	dowildbattle
	goto TheDepths_B6F_EventScript_BattleAftermath

TheDepths_B6F_EventScript_ArchaludonBattle::
	settotemboost 1, 1, 1, 1, 2, 2
	setbossbattle SPECIES_ARCHALUDON, MOVE_FLASH_CANNON, MOVE_DRAGON_PULSE, MOVE_BODY_PRESS, MOVE_ELECTRO_SHOT, 0
	dowildbattle
	goto TheDepths_B6F_EventScript_BattleAftermath

TheDepths_B6F_EventScript_BattleAftermath::
	setvar VAR_DEPTHS_MON_STATE, 6
	goto TheDepths_EventScript_BattleAftermath
