FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CheckMeteorite
	goto FallarborTown_CozmosHouse_EventScript_GiveReturn
	end

FallarborTown_CozmosHouse_EventScript_GiveReturn::
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ExplainReturn, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CheckMeteorite::
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	goto FallarborTown_CozmosHouse_EventScript_NotPlayerHasMeteorite
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_FoundAnotherOneAnyway, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NotPlayerHasMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyKindTrainer, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. COZMO: Oh! It's you!\p"
	.string "I heard that you followed TEAM MAGMA\n"
	.string "up to MT. CHIMNEY after they stole my\l"
	.string "METEORITE, and even battled against\l"
	.string "their LEADER…\p"
	.string "To think you would go that far for\n"
	.string "someone you just met…\p"
	.string "You're a really kind young TRAINER!\n"
	.string "I want you to have this as thanks.\p"
	.string "This TM, it represents my feeling of\n"
	.string "of gratitude. Please use it!$"

FallarborTown_CozmosHouse_Text_ExplainReturn:
	.string "That TM I just gave you is RETURN.\p"
	.string "It's a move that powers up the stronger\n"
	.string "the bond is betwen you and your POKéMON.$"

FallarborTown_CozmosHouse_Text_ReallyKindTrainer:
	.string "PROF. COZMO: You're both strong and kind…\n"
	.string "If anyone can bring TEAM MAGMA to\l"
	.string "justice, I bet it will be you!$"

FallarborTown_CozmosHouse_Text_FoundAnotherOneAnyway:
	.string "PROF. COZMO: Oh!\n"
	.string "That item…\p"
	.string "Is it the METEORITE that TEAM MAGMA\n"
	.string "took from METEOR FALLS?\p"
	.string "Not only did you chase off TEAM MAGMA\n"
	.string "but you even retrieved the METEORITE!\p"
	.string "That being said, I think you should\n"
	.string "hold onto that METEORITE.\p"
	.string "I managed to find another sample while\n"
	.string "searching through METEOR FALLS anyway!$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "PROF. COZMO went off to METEOR FALLS\n"
	.string "on ROUTE 114 with some people from\l"
	.string "TEAM MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Poor PROF. COZMO…\n"
	.string "He's so depressed… I feel sorry for him.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Look at PROF. COZMO…\n"
	.string "He's so happy! I think it's cute.$"

