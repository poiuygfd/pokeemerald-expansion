CouncilChambers_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CouncilChambers_OnLoad
	.byte 0

CouncilChambers_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, CouncilChambers_CheckCouncilConditions
	end

CouncilChambers_CheckCouncilConditions::
	goto_if_set FLAG_AVITORCH_CODE_USED, CouncilChambers_OpenDeeperChambers
	return

CouncilChambers_OpenDeeperChambers::
	setmetatile 5, 0, METATILE_Cave_CouncilChambers_EntranceTop, TRUE
	setmetatile 5, 1, METATILE_Cave_CouncilChambers_EntranceBottom, FALSE
	setobjectxyperm LOCALID_CODE_GIVER, 4, 2
	setobjectxyperm LOCALID_COUNCIL_DUNSPARCE, 6, 2
	setflag FLAG_TEMP_1
	return

CouncilChambers_EventScript_FakemonGiftGiver::
	lockall
	faceplayer
	goto_if_set FLAG_AVITORCH_CODE_USED, CouncilChambers_EventScript_CodeUsed
	msgbox CouncilChambers_Text_DoYaGotTheCode, MSGBOX_DEFAULT
	waitmessage
	special EnterCode
	waitstate
	special GetAvitorchCodeFeedback
	goto_if_eq VAR_RESULT, 1, CouncilChambers_EventScript_CodeSuccessAvitorch
	goto_if_eq VAR_RESULT, 2, CouncilChambers_EventScript_CodeSuccessPartrio
	goto_if_eq VAR_RESULT, 3, CouncilChambers_EventScript_ChooseRandomCode
	goto CouncilChambers_EventScript_CodeFailed
	end

CouncilChambers_EventScript_CodeFailed::
	msgbox CouncilChambers_Text_CodeIncorrect, MSGBOX_DEFAULT
	releaseall
	end

CouncilChambers_EventScript_ChooseRandomCode::
	random 2
	switch VAR_RESULT
	case 0, CouncilChambers_EventScript_CodeSuccessAvitorch
	case 1, CouncilChambers_EventScript_CodeSuccessPartrio
	end

CouncilChambers_EventScript_CodeSuccessAvitorch::
	msgbox CouncilChambers_Text_CodeCorrectAvitorch, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AVITORCH
	givemon SPECIES_AVITORCH, 20, move1=MOVE_BEAN_BEAM
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, CouncilChambers_EventScript_SendAvitorchParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, CouncilChambers_EventScript_SendAvitorchPC
	goto Common_EventScript_NoMoreRoomForPokemon
	releaseall
	end

CouncilChambers_EventScript_SendAvitorchParty::
	call CouncilChambers_EventScript_ReceivedAvitorchFanfare
	call Common_EventScript_GetGiftMonPartySlot
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CouncilChambers_EventScript_EndCodeEvent
	call Common_EventScript_NameReceivedPartyMon
	goto CouncilChambers_EventScript_EndCodeEvent
	end

CouncilChambers_EventScript_SendAvitorchPC::
	call CouncilChambers_EventScript_ReceivedAvitorchFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CouncilChambers_EventScript_AvitorchTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CouncilChambers_EventScript_AvitorchTransferredToPC
	end

CouncilChambers_EventScript_AvitorchTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto CouncilChambers_EventScript_EndCodeEvent
	end

CouncilChambers_EventScript_ReceivedAvitorchFanfare::
	bufferspeciesname STR_VAR_1, SPECIES_AVITORCH
	playfanfare MUS_OBTAIN_ITEM
	message CouncilChambers_Text_ObtainedAvitorch
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AVITORCH
	return

CouncilChambers_EventScript_CodeSuccessPartrio::
	msgbox CouncilChambers_Text_CodeCorrectPartrio, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PARTRIO
	givemon SPECIES_PARTRIO, 20, move1=MOVE_LEADER_SWAP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, CouncilChambers_EventScript_SendPartrioParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, CouncilChambers_EventScript_SendPartrioPC
	goto Common_EventScript_NoMoreRoomForPokemon
	releaseall
	end

CouncilChambers_EventScript_SendPartrioParty::
	call CouncilChambers_EventScript_ReceivedPartrioFanfare
	call Common_EventScript_GetGiftMonPartySlot
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CouncilChambers_EventScript_EndCodeEvent
	call Common_EventScript_NameReceivedPartyMon
	goto CouncilChambers_EventScript_EndCodeEvent
	end

CouncilChambers_EventScript_SendPartrioPC::
	call CouncilChambers_EventScript_ReceivedPartrioFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CouncilChambers_EventScript_PartrioTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CouncilChambers_EventScript_PartrioTransferredToPC
	end

CouncilChambers_EventScript_PartrioTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto CouncilChambers_EventScript_EndCodeEvent
	end

CouncilChambers_EventScript_ReceivedPartrioFanfare::
	bufferspeciesname STR_VAR_1, SPECIES_PARTRIO
	playfanfare MUS_OBTAIN_ITEM
	message CouncilChambers_Text_ObtainedPartrio
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_PARTRIO
	return

CouncilChambers_EventScript_EndCodeEvent::
	setflag FLAG_AVITORCH_CODE_USED
	releaseall
	end

CouncilChambers_EventScript_CodeUsed::
	goto_if_set FLAG_TEMP_1, CouncilChambers_EventScript_DoorOpened
	msgbox CouncilChambers_Text_OnePerPerson, MSGBOX_DEFAULT
	releaseall
	end

CouncilChambers_EventScript_DoorOpened::
	msgbox CouncilChambers_Text_YouMayEnter, MSGBOX_DEFAULT
	releaseall
	end

CouncilChambers_EventScript_Dunsparce::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DUNSPARCE, CRY_MODE_NORMAL
	msgbox CouncilChambers_Text_Dunsparce, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CouncilChambers_Text_DoYaGotTheCode:
	.string "Oi.\p"
	.string "Do ya got the code?$"

CouncilChambers_Text_CodeIncorrect:
	.string "Dat ain't the code.$"

CouncilChambers_Text_CodeCorrectAvitorch:
	.string "Dat's the code, all right.\p"
	.string "Enjoy yer bird.$"

CouncilChambers_Text_CodeCorrectPartrio:
	.string "Dat's the code, all right.\p"
	.string "Enjoy yer guys.$"

CouncilChambers_Text_ObtainedAvitorch:
	.string "{PLAYER} received AVITORCH!$"

CouncilChambers_Text_ObtainedPartrio:
	.string "{PLAYER} received PARTRIO!$"

CouncilChambers_Text_OnePerPerson:
	.string "One code per person.$"

CouncilChambers_Text_YouMayEnter:
	.string "You may enter.$"

CouncilChambers_Text_Dunsparce:
	.string "DUNSPARCE: Duuuun!$"
