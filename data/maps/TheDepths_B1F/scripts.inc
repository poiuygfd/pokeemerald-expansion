TheDepths_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TheDepths_B1F_OnLoad
	.byte 0

TheDepths_B1F_OnLoad:
	call TheDepths_B1F_EventScript_SpawnRuby
	call TheDepths_B1F_EventScript_SpawnSapphire
	end

TheDepths_B1F_EventScript_SpawnRuby::
	clearflag FLAG_HIDE_DEPTHS_RUBY
	setmetatile 50, 15, METATILE_NavelRock_Gemrock_Ruby, TRUE
	return

TheDepths_B1F_EventScript_SpawnSapphire::
	clearflag FLAG_HIDE_DEPTHS_SAPPHIRE
	setmetatile 9, 37, METATILE_NavelRock_Gemrock_Sapphire, TRUE
	return

TheDepths_B1F_EventScript_RemoveRuby::
	lock
	call TheDepths_EventScript_Ruby
	setmetatile 50, 15, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B1F_EventScript_RemoveSapphire::
	lock
	call TheDepths_EventScript_Sapphire
	setmetatile 9, 37, METATILE_NavelRock_Gemrock_Empty, TRUE
	special DrawWholeMapView
	release
	end

TheDepths_B1F_EventScript_GemSocket::
	lock
	call_if_eq VAR_DEPTHS_STATE, 1, TheDepths_EventScript_GemSocketActive
	call TheDepths_EventScript_GemSocketCheckRuby
	setmetatile 36, 24, METATILE_NavelRock_Floor, FALSE
	setmetatile 37, 24, METATILE_NavelRock_Floor, FALSE
	setmetatile 35, 25, METATILE_NavelRock_Floor, FALSE
	setmetatile 36, 25, METATILE_NavelRock_Floor, FALSE
	setmetatile 37, 25, METATILE_NavelRock_Floor, FALSE
	setmetatile 35, 26, METATILE_NavelRock_Floor, FALSE
	setmetatile 36, 26, METATILE_NavelRock_Floor, FALSE
	setmetatile 37, 26, METATILE_NavelRock_Floor, FALSE
	special DrawWholeMapView
	setvar VAR_DEPTHS_STATE, 1
	release
	end

TheDepths_B1F_EventScript_StrongPresence::
	lock
	msgbox TheDepths_Text_StrongPresence
	closemessage
	random 3
	call_if_eq VAR_RESULT, 0, TheDepths_B1F_EventScript_GeodudeBattle
	call_if_eq VAR_RESULT, 1, TheDepths_B1F_EventScript_AronBattle
	call_if_eq VAR_RESULT, 2, TheDepths_B1F_EventScript_RhyhornBattle

TheDepths_B1F_EventScript_GeodudeBattle::
	settotemboost 1, 2, 1, 1, 1, 1
	setwildbattle SPECIES_GEODUDE, 30
	dowildbattle
	setvar VAR_DEPTHS_MON_STATE, 1
	end

TheDepths_B1F_EventScript_AronBattle::
	settotemboost 1, 1, 2, 1, 1, 1
	setwildbattle SPECIES_ARON, 30
	dowildbattle
	setvar VAR_DEPTHS_MON_STATE, 1
	end

TheDepths_B1F_EventScript_RhyhornBattle::
	settotemboost 1, 1, 1, 2, 1, 1
	setwildbattle SPECIES_RHYHORN, 30
	dowildbattle
	setvar VAR_DEPTHS_MON_STATE, 1
	end
