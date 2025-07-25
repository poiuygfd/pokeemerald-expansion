TheDepths_B5F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TheDepths_B5F_OnLoad
	.byte 0

TheDepths_B5F_OnLoad:
	call TheDepths_B5F_EventScript_SpawnRuby
	call TheDepths_B5F_EventScript_SpawnSapphire
	end

TheDepths_B5F_EventScript_SpawnRuby::
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B5F_EventScript_SpawnRuby1
	call_if_eq VAR_RESULT, 1, TheDepths_B5F_EventScript_SpawnRuby2
	call_if_eq VAR_RESULT, 2, TheDepths_B5F_EventScript_SpawnRuby3
	return

TheDepths_B5F_EventScript_SpawnRuby1::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 42, 8, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_RUBY_2, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_RUBY_3, 0, 0
	return

TheDepths_B5F_EventScript_SpawnRuby2::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 6, 20, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_RUBY_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_RUBY_3, 0, 0
	return

TheDepths_B5F_EventScript_SpawnRuby3::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 8, 41, METATILE_NavelRock_Gemrock_Ruby, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_RUBY_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_RUBY_2, 0, 0
	return

TheDepths_B5F_EventScript_SpawnSapphire::
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B5F_EventScript_SpawnSapphire1
	call_if_eq VAR_RESULT, 1, TheDepths_B5F_EventScript_SpawnSapphire2
	call_if_eq VAR_RESULT, 2, TheDepths_B5F_EventScript_SpawnSapphire3
	return

TheDepths_B5F_EventScript_SpawnSapphire1::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 18, 9, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_SAPPHIRE_2, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_SAPPHIRE_3, 0, 0
	return

TheDepths_B5F_EventScript_SpawnSapphire2::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 53, 21, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_SAPPHIRE_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_SAPPHIRE_3, 0, 0
	return

TheDepths_B5F_EventScript_SpawnSapphire3::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 51, 39, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_SAPPHIRE_1, 0, 0
	setobjectxyperm LOCALID_THE_DEPTHS_B5F_SAPPHIRE_2, 0, 0
	return

TheDepths_B5F_EventScript_RemoveRuby1::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 42, 8, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B5F_EventScript_RemoveRuby2::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 6, 20, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B5F_EventScript_RemoveRuby3::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 8, 41, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B5F_EventScript_RemoveSapphire1::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 18, 9, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B5F_EventScript_RemoveSapphire2::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 53, 21, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B5F_EventScript_RemoveSapphire3::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 51, 39, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B5F_EventScript_GemSocket::
	lock
	call_if_eq VAR_DEPTHS_STATE, 5, TheDepths_EventScript_GemSocketActive
	call TheDepths_EventScript_GemSocketCheckRuby
	setmetatile 26, 25, METATILE_NavelRock_Floor, FALSE
	setmetatile 27, 25, METATILE_NavelRock_Floor, FALSE
	setmetatile 28, 25, METATILE_NavelRock_Floor, FALSE
	setmetatile 29, 25, METATILE_NavelRock_Floor, FALSE
	setmetatile 30, 25, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 25, METATILE_NavelRock_Floor, FALSE
	setmetatile 32, 25, METATILE_NavelRock_Floor, FALSE
	setmetatile 26, 26, METATILE_NavelRock_Floor, FALSE
	setmetatile 27, 26, METATILE_NavelRock_Floor, FALSE
	setmetatile 28, 26, METATILE_NavelRock_Floor, FALSE
	setmetatile 29, 26, METATILE_NavelRock_Floor, FALSE
	setmetatile 30, 26, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 26, METATILE_NavelRock_Floor, FALSE
	setmetatile 32, 26, METATILE_NavelRock_Floor, FALSE
	setmetatile 26, 27, METATILE_NavelRock_Floor, FALSE
	setmetatile 27, 27, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 27, METATILE_NavelRock_Floor, FALSE
	setmetatile 32, 27, METATILE_NavelRock_Floor, FALSE
	setmetatile 26, 28, METATILE_NavelRock_Floor, FALSE
	setmetatile 27, 28, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 28, METATILE_NavelRock_Floor, FALSE
	setmetatile 32, 28, METATILE_NavelRock_Floor, FALSE
	setmetatile 26, 29, METATILE_NavelRock_Floor, FALSE
	setmetatile 27, 29, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 29, METATILE_NavelRock_Floor, FALSE
	setmetatile 32, 29, METATILE_NavelRock_Floor, FALSE
	setmetatile 26, 30, METATILE_NavelRock_Floor, FALSE
	setmetatile 27, 30, METATILE_NavelRock_Floor, FALSE
	setmetatile 28, 30, METATILE_NavelRock_Floor, FALSE
	setmetatile 29, 30, METATILE_NavelRock_Floor, FALSE
	setmetatile 30, 30, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 30, METATILE_NavelRock_Floor, FALSE
	setmetatile 32, 30, METATILE_NavelRock_Floor, FALSE
	setmetatile 26, 31, METATILE_NavelRock_Floor, FALSE
	setmetatile 27, 31, METATILE_NavelRock_Floor, FALSE
	setmetatile 28, 31, METATILE_NavelRock_Floor, FALSE
	setmetatile 29, 31, METATILE_NavelRock_Floor, FALSE
	setmetatile 30, 31, METATILE_NavelRock_Floor, FALSE
	setmetatile 31, 31, METATILE_NavelRock_Floor, FALSE
	setmetatile 32, 31, METATILE_NavelRock_Floor, FALSE
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_DEPTHS_STATE, 5
	release
	end

TheDepths_B5F_EventScript_StrongPresence::
	lock
	goto_if_set FLAG_DEPTHS_IS_NORMAL, TheDepths_B5F_EventScript_NormalPresence
	goto_if_set FLAG_DEPTHS_IS_EXPERT, TheDepths_B5F_EventScript_ExpertPresence
	goto_if_set FLAG_DEPTHS_IS_MASTER, TheDepths_B5F_EventScript_MasterPresence
	goto TheDepths_B5F_EventScript_NormalPresence

TheDepths_B5F_EventScript_NormalPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B5F_EventScript_VibravaBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B5F_EventScript_KrokorokBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B5F_EventScript_FraxureBattle

TheDepths_B5F_EventScript_VibravaBattle::
	settotemboost 1, 1, 1, 1, 2, 1
	setbossbattle SPECIES_VIBRAVA, MOVE_EARTH_POWER, MOVE_DRAGON_PULSE, MOVE_BOOMBURST, MOVE_FISSURE, 0
	dowildbattle
	goto TheDepths_B5F_EventScript_BattleAftermath

TheDepths_B5F_EventScript_KrokorokBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setbossbattle SPECIES_KROKOROK, MOVE_POWER_TRIP, MOVE_EARTHQUAKE, MOVE_DIG, MOVE_SWAGGER, 1
	dowildbattle
	goto TheDepths_B5F_EventScript_BattleAftermath

TheDepths_B5F_EventScript_FraxureBattle::
	settotemboost 1, 2, 1, 1, 1, 1
	setbossbattle SPECIES_FRAXURE, MOVE_DRAGON_CLAW, MOVE_BREAKING_SWIPE, MOVE_CRUNCH, MOVE_SCARY_FACE, 1
	dowildbattle
	goto TheDepths_B5F_EventScript_BattleAftermath

TheDepths_B5F_EventScript_ExpertPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B5F_EventScript_ConkeldurrBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B5F_EventScript_MienshaoBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B5F_EventScript_MedichamBattle

TheDepths_B5F_EventScript_ConkeldurrBattle::
	settotemboost 1, 1, 1, 1, 1, 2
	setbossbattle SPECIES_CONKELDURR, MOVE_DRAIN_PUNCH, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_MACH_PUNCH, 0
	dowildbattle
	goto TheDepths_B5F_EventScript_BattleAftermath

TheDepths_B5F_EventScript_MienshaoBattle::
	settotemboost 1, 2, 1, 1, 1, 1
	setbossbattle SPECIES_MIENSHAO, MOVE_BRICK_BREAK, MOVE_TRIPLE_AXEL, MOVE_ACROBATICS, MOVE_REVERSAL, 0
	dowildbattle
	goto TheDepths_B5F_EventScript_BattleAftermath

TheDepths_B5F_EventScript_MedichamBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setbossbattle SPECIES_MEDICHAM, MOVE_HIGH_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_ICE_PUNCH, MOVE_RECOVER, 0
	dowildbattle
	goto TheDepths_B5F_EventScript_BattleAftermath

TheDepths_B5F_EventScript_MasterPresence::
	call TheDepths_EventScript_StrongPresence
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B5F_EventScript_ChandelureBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B5F_EventScript_GengarBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B5F_EventScript_AegislashBattle

TheDepths_B5F_EventScript_ChandelureBattle::
	settotemboost 1, 1, 1, 2, 2, 1
	setbossbattle SPECIES_CHANDELURE, MOVE_FLAMETHROWER, MOVE_SHADOW_BALL, MOVE_ENERGY_BALL, MOVE_CALM_MIND, 1
	dowildbattle
	goto TheDepths_B5F_EventScript_BattleAftermath

TheDepths_B5F_EventScript_GengarBattle::
	settotemboost 1, 1, 1, 2, 2, 1
	setbossbattle SPECIES_GENGAR, MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB, MOVE_HYPNOSIS, MOVE_DESTINY_BOND, 0
	dowildbattle
	goto TheDepths_B5F_EventScript_BattleAftermath

TheDepths_B5F_EventScript_AegislashBattle::
	settotemboost 1, 2, 1, 2, 1, 1
	setbossbattle SPECIES_AEGISLASH, MOVE_IRON_HEAD, MOVE_SACRED_SWORD, MOVE_SWORDS_DANCE, MOVE_KINGS_SHIELD, 0
	dowildbattle
	goto TheDepths_B5F_EventScript_BattleAftermath

TheDepths_B5F_EventScript_BattleAftermath::
	setvar VAR_DEPTHS_MON_STATE, 5
	goto TheDepths_EventScript_BattleAftermath
