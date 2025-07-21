TheDepths_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TheDepths_B2F_OnLoad
	.byte 0

TheDepths_B2F_OnLoad:
	call TheDepths_B2F_EventScript_SpawnRuby
	call TheDepths_B2F_EventScript_SpawnSapphire
	end

TheDepths_B2F_EventScript_SpawnRuby::
	random 2
	call_if_eq VAR_RESULT, 0, TheDepths_B2F_EventScript_SpawnRuby1
	call_if_eq VAR_RESULT, 1, TheDepths_B2F_EventScript_SpawnRuby2
	return

TheDepths_B2F_EventScript_SpawnRuby1::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 52, 6, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B2F_RUBY_2, 0, 0
	return

TheDepths_B2F_EventScript_SpawnRuby2::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 36, 45, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B2F_RUBY_1, 0, 0
	return

TheDepths_B2F_EventScript_SpawnSapphire::
	random 2
	call_if_eq VAR_RESULT, 0, TheDepths_B2F_EventScript_SpawnSapphire1
	call_if_eq VAR_RESULT, 1, TheDepths_B2F_EventScript_SpawnSapphire2
	return

TheDepths_B2F_EventScript_SpawnSapphire1::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 8, 7, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B2F_SAPPHIRE_2, 0, 0
	return

TheDepths_B2F_EventScript_SpawnSapphire2::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 53, 37, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B2F_SAPPHIRE_1, 0, 0
	return

TheDepths_B2F_EventScript_RemoveRuby1::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 52, 6, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B2F_EventScript_RemoveRuby2::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 36, 45, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B2F_EventScript_RemoveSapphire1::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 8, 7, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B2F_EventScript_RemoveSapphire2::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 53, 37, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B2F_EventScript_GemSocket::
	lock
	call_if_eq VAR_DEPTHS_STATE, 2, TheDepths_EventScript_GemSocketActive
	call TheDepths_EventScript_GemSocketCheckRuby
	setmetatile 48, 18, METATILE_NavelRock_Floor, FALSE
	setmetatile 49, 18, METATILE_NavelRock_Floor, FALSE
	setmetatile 48, 19, METATILE_NavelRock_Floor, FALSE
	setmetatile 49, 19, METATILE_NavelRock_Floor, FALSE
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_DEPTHS_STATE, 2
	release
	end

TheDepths_B2F_EventScript_StrongPresence::
	lock
	goto_if_set FLAG_DEPTHS_IS_NORMAL, TheDepths_B2F_EventScript_NormalPresence
	goto_if_set FLAG_DEPTHS_IS_EXPERT, TheDepths_B2F_EventScript_ExpertPresence
	goto_if_set FLAG_DEPTHS_IS_MASTER, TheDepths_B2F_EventScript_MasterPresence
	goto TheDepths_B2F_EventScript_NormalPresence	

TheDepths_B2F_EventScript_NormalPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B2F_EventScript_ScraggyBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B2F_EventScript_MedititeBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B2F_EventScript_RioluBattle

TheDepths_B2F_EventScript_ScraggyBattle::
	settotemboost 1, 1, 1, 1, 1, 2
	setbossbattle SPECIES_SCRAGGY, MOVE_CRUNCH, MOVE_BODY_PRESS, MOVE_BODY_SLAM, MOVE_BULK_UP, 2
	dowildbattle
	goto TheDepths_B2F_EventScript_BattleAftermath

TheDepths_B2F_EventScript_MedititeBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setbossbattle SPECIES_MEDITITE, MOVE_HIGH_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_ROCK_SLIDE, MOVE_RECOVER, 0
	dowildbattle
	goto TheDepths_B2F_EventScript_BattleAftermath

TheDepths_B2F_EventScript_RioluBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setbossbattle SPECIES_RIOLU, MOVE_DRAIN_PUNCH, MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_BULK_UP, 2
	dowildbattle
	goto TheDepths_B2F_EventScript_BattleAftermath

TheDepths_B2F_EventScript_ExpertPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B2F_EventScript_AggronBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B2F_EventScript_GolemBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B2F_EventScript_CoalossalBattle

TheDepths_B2F_EventScript_AggronBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setbossbattle SPECIES_AGGRON, MOVE_HEAD_SMASH, MOVE_HEAVY_SLAM, MOVE_BODY_PRESS, MOVE_EARTHQUAKE, 1
	dowildbattle
	goto TheDepths_B2F_EventScript_BattleAftermath

TheDepths_B2F_EventScript_GolemBattle::
	settotemboost 1, 2, 1, 1, 1, 1
	setbossbattle SPECIES_GOLEM, MOVE_ROCK_BLAST, MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_ROCK_POLISH, 1
	dowildbattle
	goto TheDepths_B2F_EventScript_BattleAftermath

TheDepths_B2F_EventScript_CoalossalBattle::
	settotemboost 1, 1, 1, 1, 2, 1
	setbossbattle SPECIES_COALOSSAL, MOVE_POWER_GEM, MOVE_FLAMETHROWER, MOVE_EARTH_POWER, MOVE_METEOR_BEAM, 0
	dowildbattle
	goto TheDepths_B2F_EventScript_BattleAftermath

TheDepths_B2F_EventScript_MasterPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B2F_EventScript_GlimmoraBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B2F_EventScript_NoivernBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B2F_EventScript_ForretressBattle

TheDepths_B2F_EventScript_GlimmoraBattle::
	settotemboost 1, 1, 2, 1, 2, 1
	setbossbattle SPECIES_GLIMMORA, MOVE_POWER_GEM, MOVE_SLUDGE_WAVE, MOVE_MORTAL_SPIN, MOVE_SPIKY_SHIELD, 0
	dowildbattle
	goto TheDepths_B2F_EventScript_BattleAftermath

TheDepths_B2F_EventScript_NoivernBattle::
	settotemboost 1, 1, 1, 2, 2, 1
	setbossbattle SPECIES_NOIVERN, MOVE_DRAGON_PULSE, MOVE_AIR_SLASH, MOVE_BOOMBURST, MOVE_ROOST, 1
	dowildbattle
	goto TheDepths_B2F_EventScript_BattleAftermath

TheDepths_B2F_EventScript_ForretressBattle::
	settotemboost 1, 2, 1, 1, 1, 2
	setbossbattle SPECIES_FORRETRESS, MOVE_HEAVY_SLAM, MOVE_LUNGE, MOVE_CURSE, MOVE_THUNDER_WAVE, 0
	dowildbattle
	goto TheDepths_B2F_EventScript_BattleAftermath

TheDepths_B2F_EventScript_BattleAftermath::
	setvar VAR_DEPTHS_MON_STATE, 2
	goto TheDepths_EventScript_BattleAftermath
