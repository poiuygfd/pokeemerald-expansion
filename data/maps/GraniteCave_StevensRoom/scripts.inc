GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	goto_if_set FLAG_KANTO_STARTERS, GraniteCave_StevensRoom_EventScript_GiveKantoStones
	goto_if_set FLAG_KALOS_STARTERS, GraniteCave_StevensRoom_EventScript_GiveKalosStones
	goto_if_set FLAG_ZA_STARTERS, GraniteCave_StevensRoom_EventScript_GiveZAStones
	goto_if_eq VAR_STARTER_MON, 0, GraniteCave_StevensRoom_EventScript_GetSceptileStone
	goto_if_eq VAR_STARTER_MON, 1, GraniteCave_StevensRoom_EventScript_GetBlazikenStone
	goto_if_eq VAR_STARTER_MON, 2, GraniteCave_StevensRoom_EventScript_GetSwampertStone
	release
	return

GraniteCave_StevensRoom_EventScript_GiveKantoStones::
	goto_if_eq VAR_STARTER_MON, 0, GraniteCave_StevensRoom_EventScript_GetVenusaurStone
	goto_if_eq VAR_STARTER_MON, 1, GraniteCave_StevensRoom_EventScript_GetCharizardStones
	goto_if_eq VAR_STARTER_MON, 2, GraniteCave_StevensRoom_EventScript_GetBlastoiseStone
	release
	return

GraniteCave_StevensRoom_EventScript_GiveKalosStones::
	goto_if_eq VAR_STARTER_MON, 0, GraniteCave_StevensRoom_EventScript_GetChesnaughtStone
	goto_if_eq VAR_STARTER_MON, 1, GraniteCave_StevensRoom_EventScript_GetDelphoxStone
	goto_if_eq VAR_STARTER_MON, 2, GraniteCave_StevensRoom_EventScript_GetGreninjaStone
	release
	return

GraniteCave_StevensRoom_EventScript_GiveZAStones::
	goto_if_eq VAR_STARTER_MON, 0, GraniteCave_StevensRoom_EventScript_GetMeganiumStone
	goto_if_eq VAR_STARTER_MON, 1, GraniteCave_StevensRoom_EventScript_GetEmboarStone
	goto_if_eq VAR_STARTER_MON, 2, GraniteCave_StevensRoom_EventScript_GetFeraligatrStone
	release
	return

GraniteCave_StevensRoom_EventScript_MatchCallSteven::
	msgbox GraniteCave_StevensRoom_Text_PokemonQuiteCapableLetsBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_STEVEN_GRANITE_CAVE, GraniteCave_StevensRoom_Text_ThatWasRatherImpressive
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	setvar VAR_GRANITE_CAVE_STATE, 1
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_EventScript_GetSceptileStone:
	giveitem ITEM_SCEPTILITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetBlazikenStone:
	giveitem ITEM_BLAZIKENITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetSwampertStone:
	giveitem ITEM_SWAMPERTITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetVenusaurStone:
	giveitem ITEM_VENUSAURITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetCharizardStones:
	giveitem ITEM_CHARIZARDITE_X
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	giveitem ITEM_CHARIZARDITE_Y
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	clearflag FLAG_HIDE_CHARIZARD_FAN
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetBlastoiseStone:
	giveitem ITEM_BLASTOISINITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetChesnaughtStone:
	giveitem ITEM_CHESNAUGHTITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetDelphoxStone:
	giveitem ITEM_DELPHOXITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetGreninjaStone:
	giveitem ITEM_GRENINJITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetMeganiumStone:
	giveitem ITEM_MEGANIUMITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetEmboarStone:
	giveitem ITEM_EMBOARITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_EventScript_GetFeraligatrStone:
	giveitem ITEM_FERALIGITE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	goto GraniteCave_StevensRoom_EventScript_MatchCallSteven

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "My name is STEVEN.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "STEVEN: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "Hmm… So that's the starter you chose…\p"
	.string "In that case, I believe you may be\n"
	.string "able to eventually make use of this.$"

GraniteCave_StevensRoom_Text_PokemonQuiteCapableLetsBattle:
	.string "STEVEN: Your POKéMON appear quite\n"
	.string "capable.\p"
	.string "You certainly strike me as quite an\n"
	.string "intriguing TRAINER.\p"
	.string "I believe the best way to get to know\n"
	.string "each other is through battle.\p"
	.string "Let's have a quick bout. I want you to\n"
	.string "Show me the kind of TRAINER you are.$"

GraniteCave_StevensRoom_Text_ThatWasRatherImpressive:
	.string "That was rather impressive, I must say.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "STEVEN: A marvelous display of\n"
	.string "strength.\p"
	.string "If you keep training, you could even\n"
	.string "become the CHAMPION of the POKéMON\l"
	.string "LEAGUE one day. That's what I think.\p"
	.string "I know, since we've gotten to know each\n"
	.string "other, let's register one another in\l"
	.string "our POKéNAVS.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Registered STEVEN\n"
	.string "in the POKéNAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Now, I've got to hurry along.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"

