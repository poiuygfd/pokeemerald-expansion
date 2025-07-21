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
	playse SE_BANG
	setvar VAR_DEPTHS_STATE, 7
	release
	end

TheDepths_B7F_EventScript_StrongPresence::
	lock
	goto_if_set FLAG_DEPTHS_IS_NORMAL, TheDepths_B7F_EventScript_NormalPresence
	goto_if_set FLAG_DEPTHS_IS_EXPERT, TheDepths_B7F_EventScript_ExpertPresence
	goto_if_set FLAG_DEPTHS_IS_MASTER, TheDepths_B7F_EventScript_MasterPresence
	goto TheDepths_B7F_EventScript_NormalPresence

TheDepths_B7F_EventScript_NormalPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B7F_EventScript_CrobatBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B7F_EventScript_ExploudBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B7F_EventScript_MachampBattle

TheDepths_B7F_EventScript_CrobatBattle::
	settotemboost 1, 2, 1, 1, 1, 1
	setbossbattle SPECIES_CROBAT, MOVE_CROSS_POISON, MOVE_DUAL_WINGBEAT, MOVE_LEECH_LIFE, MOVE_MEAN_LOOK, 0
	dowildbattle
	goto TheDepths_B7F_EventScript_BattleAftermath

TheDepths_B7F_EventScript_ExploudBattle::
	settotemboost 1, 1, 1, 1, 2, 1
	setbossbattle SPECIES_EXPLOUD, MOVE_HYPER_VOICE, MOVE_ICE_BEAM, MOVE_SHOCK_WAVE, MOVE_FIRE_BLAST, 2
	dowildbattle
	goto TheDepths_B7F_EventScript_BattleAftermath

TheDepths_B7F_EventScript_MachampBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setbossbattle SPECIES_MACHAMP, MOVE_CROSS_CHOP, MOVE_MEGA_KICK, MOVE_DUAL_CHOP, MOVE_FOCUS_ENERGY, 1
	dowildbattle
	goto TheDepths_B7F_EventScript_BattleAftermath

TheDepths_B7F_EventScript_ExpertPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B7F_EventScript_VolcaronaBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B7F_EventScript_UrsalunaBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B7F_EventScript_GholdengoBattle

TheDepths_B7F_EventScript_VolcaronaBattle::
	settotemboost 1, 1, 1, 1, 2, 1
	setbossbattle SPECIES_VOLCARONA, MOVE_FIERY_DANCE, MOVE_BUG_BUZZ, MOVE_PSYCHIC, MOVE_QUIVER_DANCE, 0
	dowildbattle
	goto TheDepths_B7F_EventScript_BattleAftermath

TheDepths_B7F_EventScript_UrsalunaBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setbossbattle SPECIES_URSALUNA_BLOODMOON, MOVE_BLOOD_MOON, MOVE_EARTH_POWER, MOVE_HYPER_VOICE, MOVE_CALM_MIND, 0
	dowildbattle
	goto TheDepths_B7F_EventScript_BattleAftermath

TheDepths_B7F_EventScript_GholdengoBattle::
	settotemboost 1, 1, 1, 1, 2, 1
	setbossbattle SPECIES_GHOLDENGO, MOVE_MAKE_IT_RAIN, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_NASTY_PLOT, 0
	dowildbattle
	goto TheDepths_B7F_EventScript_BattleAftermath

TheDepths_B7F_EventScript_MasterPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B7F_EventScript_RegirockBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B7F_EventScript_RegiceBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B7F_EventScript_RegisteelBattle

TheDepths_B7F_EventScript_RegirockBattle::
	settotemboost 1, 2, 1, 1, 1, 2
	setbossbattle SPECIES_REGIROCK, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB, MOVE_CURSE, 0
	dowildbattle
	goto TheDepths_B7F_EventScript_BattleAftermath

TheDepths_B7F_EventScript_RegiceBattle::
	settotemboost 1, 1, 2, 1, 2, 1
	setbossbattle SPECIES_REGICE, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_ICY_WIND, MOVE_CHARGE_BEAM, 0
	dowildbattle
	goto TheDepths_B7F_EventScript_BattleAftermath

TheDepths_B7F_EventScript_RegisteelBattle::
	settotemboost 1, 2, 1, 2, 1, 1
	setbossbattle SPECIES_REGISTEEL, MOVE_IRON_HEAD, MOVE_BODY_PRESS, MOVE_IRON_DEFENSE, MOVE_AMNESIA, 0
	dowildbattle
	goto TheDepths_B7F_EventScript_BattleAftermath

TheDepths_B7F_EventScript_BattleAftermath::
	setvar VAR_DEPTHS_MON_STATE, 7
	goto TheDepths_EventScript_BattleAftermath
