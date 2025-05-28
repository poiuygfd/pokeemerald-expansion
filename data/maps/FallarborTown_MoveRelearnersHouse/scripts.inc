FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_AvitorchGiftGiver::
	lockall
	faceplayer
	goto_if_set FLAG_AVITORCH_CODE_USED, FallarborTown_MoveRelearnersHouse_EventScript_AvitorchCodeUsed
	msgbox FallarborTown_MoveRelearnersHouse_Text_AvitorchGift, MSGBOX_DEFAULT
	waitmessage
	special EnterAvitorchCode
	waitstate
	special GetAvitorchCodeFeedback
	goto_if_eq VAR_RESULT, 1, FallarborTown_MoveRelearnersHouse_EventScript_CodeSuccess
	goto FallarborTown_MoveRelearnersHouse_EventScript_CodeFailed
	end

FallarborTown_MoveRelearnersHouse_EventScript_CodeFailed::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CodeIncorrect, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_CodeSuccess::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CodeCorrect, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AVITORCH
	givemon SPECIES_AVITORCH, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, FallarborTown_MoveRelearnersHouse_EventScript_SendAvitorchParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, FallarborTown_MoveRelearnersHouse_EventScript_SendAvitorchPC
	goto Common_EventScript_NoMoreRoomForPokemon
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_SendAvitorchParty::
	call FallarborTown_MoveRelearnersHouse_EventScript_ReceivedAvitorchFanfare
	call Common_EventScript_GetGiftMonPartySlot
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FallarborTown_MoveRelearnersHouse_EventScript_EndAvitorchEvent
	call Common_EventScript_NameReceivedPartyMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_EndAvitorchEvent
	end

FallarborTown_MoveRelearnersHouse_EventScript_SendAvitorchPC::
	call FallarborTown_MoveRelearnersHouse_EventScript_ReceivedAvitorchFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FallarborTown_MoveRelearnersHouse_EventScript_AvitorchTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_AvitorchTransferredToPC
	end

FallarborTown_MoveRelearnersHouse_EventScript_AvitorchTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto FallarborTown_MoveRelearnersHouse_EventScript_EndAvitorchEvent
	end

FallarborTown_MoveRelearnersHouse_EventScript_ReceivedAvitorchFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_AVITORCH
	playfanfare MUS_OBTAIN_ITEM
	message FallarborTown_MoveRelearnersHouse_Text_ObtainedAvitorch
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AVITORCH
	return

FallarborTown_MoveRelearnersHouse_EventScript_EndAvitorchEvent::
	setflag FLAG_AVITORCH_CODE_USED
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_AvitorchCodeUsed::
	msgbox FallarborTown_MoveRelearnersHouse_Text_OnePerPerson, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_Dunsparce::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DUNSPARCE, CRY_MODE_NORMAL
	msgbox FallarborTown_MoveRelearnersHouse_Text_Dunsparce, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_AvitorchGift:
	.string "Oi.\p"
	.string "Do ya got the code?$"

FallarborTown_MoveRelearnersHouse_Text_CodeIncorrect:
	.string "Dat ain't the code.$"

FallarborTown_MoveRelearnersHouse_Text_CodeCorrect:
	.string "Dat's the code, all right.\p"
	.string "Enjoy yer bird.$"

FallarborTown_MoveRelearnersHouse_Text_ObtainedAvitorch:
	.string "{PLAYER} received AVITORCH!$"

FallarborTown_MoveRelearnersHouse_Text_OnePerPerson:
	.string "One bird per person.$"

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "I'm the MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for a HEART SCALE.\n"
	.string "I'm collecting those now.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness HEART SCALE!\p"
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Which move should I teach?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "If your POKéMON need to learn a move,\n"
	.string "come back with a HEART SCALE.$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an EGG.$"

FallarborTown_MoveRelearnersHouse_Text_Dunsparce:
	.string "DUNSPARCE: Duuuun!$"
