TheVoid_MapScripts::
	.byte 0

TheVoid_EventScript_MagikarpCry::
	lockall
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_PLAYER, TheVoid_Movement_PlayerConfused
	waitmovement 0
	addobject LOCALID_MAGIKARP_CUTSCENE
	setvar VAR_TEMP_1, 1
	releaseall
	end

TheVoid_Movement_PlayerConfused:
	emote_question_mark
	walk_in_place_left
	delay_16
	delay_8
	walk_in_place_right
	delay_16
	delay_8
	walk_in_place_up
	step_end

TheVoid_EventScript_MagikarpFlee::
	lockall
	applymovement LOCALID_MAGIKARP_CUTSCENE, TheVoid_Movement_MagikarpRunAway
	waitmovement 0
	removeobject LOCALID_MAGIKARP_CUTSCENE
	setvar VAR_TEMP_1, 2
	releaseall
	end

TheVoid_Movement_MagikarpRunAway:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TheVoid_EventScript_Magikarp::
	lockall
	setflag FLAG_PREVENT_CATCHING
    setflag FLAG_PREVENT_RUNNING
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	waitmoncry
	settotemboost 1, 1, 1, 1, 1, 1
	setbossbattle SPECIES_MAGIKARP_DARK, MOVE_ABYSSAL_RUSH, MOVE_DEPTH_CRUSHER, MOVE_SUFFER_STRIKE, MOVE_VENGEANCE, 0
	special BattleSetup_StartLegendaryBattle
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MAGIKARP_BATTLE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_PREVENT_CATCHING
    clearflag FLAG_PREVENT_RUNNING
	clearflag FLAG_ITEM_MAUVILLE_ABYSS_STONE
	setflag FLAG_HIDE_MAUVILLE_VOID_RIFT
	setvar VAR_VOID_ALTAR_STATE, 6
	releaseall
	end

TheVoid_EventScript_MauvilleWarpTrigger::
	lock
	warp MAP_MAUVILLE_CITY, 16, 7
	waitstate
	release
	end
