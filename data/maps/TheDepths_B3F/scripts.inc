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
	playse SE_BANG
	setvar VAR_DEPTHS_STATE, 3
	release
	end

TheDepths_B3F_EventScript_StrongPresence::
	lock
	goto_if_set FLAG_DEPTHS_IS_NORMAL, TheDepths_B3F_EventScript_NormalPresence
	goto_if_set FLAG_DEPTHS_IS_EXPERT, TheDepths_B3F_EventScript_ExpertPresence
	goto_if_set FLAG_DEPTHS_IS_MASTER, TheDepths_B3F_EventScript_MasterPresence
	goto TheDepths_B3F_EventScript_NormalPresence

TheDepths_B3F_EventScript_NormalPresence::
	call TheDepths_EventScript_StrongPresence
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

TheDepths_B3F_EventScript_ExpertPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B3F_EventScript_CrobatBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B3F_EventScript_ExploudBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B3F_EventScript_MachampBattle

TheDepths_B3F_EventScript_CrobatBattle::
	settotemboost 1, 2, 1, 1, 1, 1
	setbossbattle SPECIES_CROBAT, MOVE_CROSS_POISON, MOVE_DUAL_WINGBEAT, MOVE_LEECH_LIFE, MOVE_MEAN_LOOK, 0
	dowildbattle
	goto TheDepths_B3F_EventScript_BattleAftermath

TheDepths_B3F_EventScript_ExploudBattle::
	settotemboost 1, 1, 1, 1, 2, 1
	setbossbattle SPECIES_EXPLOUD, MOVE_HYPER_VOICE, MOVE_ICE_BEAM, MOVE_SURF, MOVE_FIRE_BLAST, 2
	dowildbattle
	goto TheDepths_B3F_EventScript_BattleAftermath

TheDepths_B3F_EventScript_MachampBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setbossbattle SPECIES_MACHAMP, MOVE_CROSS_CHOP, MOVE_MEGA_KICK, MOVE_STONE_EDGE, MOVE_FOCUS_ENERGY, 1
	dowildbattle
	goto TheDepths_B3F_EventScript_BattleAftermath

TheDepths_B3F_EventScript_MasterPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B3F_EventScript_VolcaronaBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B3F_EventScript_UrsalunaBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B3F_EventScript_GholdengoBattle

TheDepths_B3F_EventScript_VolcaronaBattle::
	settotemboost 1, 1, 2, 1, 2, 1
	setbossbattle SPECIES_VOLCARONA, MOVE_FIERY_DANCE, MOVE_BUG_BUZZ, MOVE_MORNING_SUN, MOVE_QUIVER_DANCE, 0
	dowildbattle
	goto TheDepths_B3F_EventScript_BattleAftermath

TheDepths_B3F_EventScript_UrsalunaBattle::
	settotemboost 1, 1, 2, 2, 1, 1
	setbossbattle SPECIES_URSALUNA_BLOODMOON, MOVE_BLOOD_MOON, MOVE_EARTH_POWER, MOVE_MOONLIGHT, MOVE_CALM_MIND, 0
	dowildbattle
	goto TheDepths_B3F_EventScript_BattleAftermath

TheDepths_B3F_EventScript_GholdengoBattle::
	settotemboost 1, 1, 2, 1, 2, 1
	setbossbattle SPECIES_GHOLDENGO, MOVE_MAKE_IT_RAIN, MOVE_SHADOW_BALL, MOVE_RECOVER, MOVE_NASTY_PLOT, 0
	dowildbattle
	goto TheDepths_B3F_EventScript_BattleAftermath

TheDepths_B3F_EventScript_BattleAftermath::
	setvar VAR_DEPTHS_MON_STATE, 3
	goto TheDepths_EventScript_BattleAftermath
