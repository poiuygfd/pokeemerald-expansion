MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_ExTeamPlasma::
	lock
	faceplayer
	goto_if_eq VAR_GENESECT_DRIVE_STATE, 1, MtPyre_6F_EventScript_ShockDrive
	goto_if_eq VAR_GENESECT_DRIVE_STATE, 2, MtPyre_6F_EventScript_BurnDrive
	goto_if_eq VAR_GENESECT_DRIVE_STATE, 3, MtPyre_6F_EventScript_ChillDrive
	goto_if_eq VAR_GENESECT_DRIVE_STATE, 4, MtPyre_6F_EventScript_DouseDrive
	goto_if_set FLAG_RECEIVED_GENESECT, MtPyre_6F_EventScript_ReceivedGenesect
	goto_if_set FLAG_SYS_HILL_MASTER_WIN, MtPyre_6F_EventScript_YouAreTrustworthyHill
	goto_if_set FLAG_SYS_DEPTHS_MASTER_WIN, MtPyre_6F_EventScript_YouAreTrustworthyDepths
	goto_if_set FLAG_SYS_GAME_CLEAR, MtPyre_6F_EventScript_AlmostTrustworthy
	msgbox MtPyre_6F_Text_NotTrustworthy, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_YouAreTrustworthyHill::
	goto_if_set FLAG_SYS_DEPTHS_MASTER_WIN, MtPyre_6F_EventScript_YouAreTrustworthyBoth
	msgbox MtPyre_6F_Text_HillTrustworthy, MSGBOX_DEFAULT
	applymovement LOCALID_MT_PYRE_EX_TEAM_PLASMA_GRUNT, Common_Movement_FaceUp
	waitmovement 0
	msgbox MtPyre_6F_Text_IWasInTeamPlasma, MSGBOX_DEFAULT
	faceplayer
	waitmovement 0
	msgbox MtPyre_6F_Text_BeenLookingForATrainer, MSGBOX_DEFAULT
	goto MtPyre_6F_EventScript_ReceiveGenesect
	end

MtPyre_6F_EventScript_YouAreTrustworthyDepths::
	msgbox MtPyre_6F_Text_DepthsTrustworthy, MSGBOX_DEFAULT
	applymovement LOCALID_MT_PYRE_EX_TEAM_PLASMA_GRUNT, Common_Movement_FaceUp
	waitmovement 0
	msgbox MtPyre_6F_Text_IWasInTeamPlasma, MSGBOX_DEFAULT
	faceplayer
	waitmovement 0
	msgbox MtPyre_6F_Text_BeenLookingForATrainer, MSGBOX_DEFAULT
	goto MtPyre_6F_EventScript_ReceiveGenesect
	end

MtPyre_6F_EventScript_YouAreTrustworthyBoth::
	msgbox MtPyre_6F_Text_TrulyTrustworthy, MSGBOX_DEFAULT
	applymovement LOCALID_MT_PYRE_EX_TEAM_PLASMA_GRUNT, Common_Movement_FaceUp
	waitmovement 0
	msgbox MtPyre_6F_Text_IWasInTeamPlasma, MSGBOX_DEFAULT
	faceplayer
	waitmovement 0
	msgbox MtPyre_6F_Text_BeenLookingForATrainer, MSGBOX_DEFAULT
	goto MtPyre_6F_EventScript_ReceiveGenesect
	end

MtPyre_6F_EventScript_AlmostTrustworthy::
	msgbox MtPyre_6F_Text_AlmostTrustworthy, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_ReceiveGenesect::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GENESECT
	givemon SPECIES_GENESECT, 50
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MtPyre_6F_EventScript_ReceiveGenesectParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MtPyre_6F_EventScript_ReceiveGenesectPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MtPyre_6F_EventScript_ReceiveGenesectParty::
	call MtPyre_6F_EventScript_ReceivedGenesectFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtPyre_6F_EventScript_ReceivedGenesect
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	setflag FLAG_RECEIVED_GENESECT
	goto MtPyre_6F_EventScript_ReceivedGenesect
	end

MtPyre_6F_EventScript_ReceiveGenesectPC::
	call MtPyre_6F_EventScript_ReceivedGenesectFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtPyre_6F_EventScript_SendGenesectToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MtPyre_6F_EventScript_SendGenesectToPC
	end

MtPyre_6F_EventScript_SendGenesectToPC::
	call Common_EventScript_TransferredToPC
	setflag FLAG_RECEIVED_GENESECT
	goto MtPyre_6F_EventScript_ReceivedGenesect
	end

MtPyre_6F_EventScript_ReceivedGenesectFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message MtPyre_6F_Text_PlayerReceivedGenesect
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_GENESECT
	return

MtPyre_6F_EventScript_ShockDrive::
	msgbox MtPyre_6F_Text_AlsoTakeThese, MSGBOX_DEFAULT
	setvar VAR_GENESECT_DRIVE_STATE, 1
	giveitem ITEM_SHOCK_DRIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GENESECT_DRIVE_STATE, 2
	giveitem ITEM_BURN_DRIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GENESECT_DRIVE_STATE, 3
	giveitem ITEM_CHILL_DRIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GENESECT_DRIVE_STATE, 4
	giveitem ITEM_DOUSE_DRIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GENESECT_DRIVE_STATE, 5
	release
	end

MtPyre_6F_EventScript_BurnDrive::
	msgbox MtPyre_6F_Text_AlsoTakeThese, MSGBOX_DEFAULT
	setvar VAR_GENESECT_DRIVE_STATE, 2
	giveitem ITEM_BURN_DRIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GENESECT_DRIVE_STATE, 3
	giveitem ITEM_CHILL_DRIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GENESECT_DRIVE_STATE, 4
	giveitem ITEM_DOUSE_DRIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GENESECT_DRIVE_STATE, 5
	release
	end

MtPyre_6F_EventScript_ChillDrive::
	msgbox MtPyre_6F_Text_AlsoTakeThese, MSGBOX_DEFAULT
	setvar VAR_GENESECT_DRIVE_STATE, 3
	giveitem ITEM_CHILL_DRIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GENESECT_DRIVE_STATE, 4
	giveitem ITEM_DOUSE_DRIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GENESECT_DRIVE_STATE, 5
	release
	end

MtPyre_6F_EventScript_DouseDrive::
	msgbox MtPyre_6F_Text_AlsoTakeThese, MSGBOX_DEFAULT
	setvar VAR_GENESECT_DRIVE_STATE, 4
	giveitem ITEM_DOUSE_DRIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GENESECT_DRIVE_STATE, 5
	release
	end

MtPyre_6F_EventScript_ReceivedGenesect::
	msgbox MtPyre_6F_Text_FinallyGoHome, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_NotTrustworthy:
	.string "Hm, you must be pretty strong\n"
	.string "to make it all the way here…\p"
	.string "Still, I'm looking for a TRAINER\n"
	.string "with exceptional strength.$"

MtPyre_6F_Text_AlmostTrustworthy:
	.string "You managed to defeat the\n"
	.string "POKéMON LEAGUE?\p"
	.string "You must be pretty strong then!\n"
	.string "But wait… N was still able to…\p"
	.string "Sorry, I still don't think I\n"
	.string "can fully trust you yet…\p"
	.string "If you become even stronger though\n"
	.string "then just maybe…\p"
	.string "I've heard that areas known as\n"
	.string "TRAINER HILL and THE DEPTHS recently\l"
	.string "opened up and have difficulty modes\l"
	.string "that push you to your limits.\p"
	.string "If you could beat the highest\n"
	.string "difficulty of either of those…$"

MtPyre_6F_Text_HillTrustworthy:
	.string "Is it true?!\n"
	.string "You were able to overcome the highest\l"
	.string "level of difficulty in TRAINER HILL?\p"
	.string "I think…\n"
	.string "I think I can trust you with this.$"

MtPyre_6F_Text_DepthsTrustworthy:
	.string "Is it true?!\n"
	.string "You were able to overcome the highest\l"
	.string "level of difficulty in THE DEPTHS?\p"
	.string "I think…\n"
	.string "I think I can trust you with this.$"

MtPyre_6F_Text_TrulyTrustworthy:
	.string "Is it true?!\n"
	.string "You were able to overcome the highest\l"
	.string "level of difficulty in both TRAINER\l"
	.string "HILL and THE DEPTHS?!\p"
	.string "I'm sure I can trust you with this!$"

MtPyre_6F_Text_IWasInTeamPlasma:
	.string "You see…\n"
	.string "Back in the UNOVA region, I used to\l"
	.string "be a member of a group known as\l"
	.string "TEAM PLASMA.\p"
	.string "Our group started out as one to\n"
	.string "liberate POKéMON from TRAINERS in\l"
	.string "order to protect them.\p"
	.string "However, in reality, our goals were…\n"
	.string "misguided… and we were being controlled\l"
	.string "by a man known as GHETSIS.\p"
	.string "GHETSIS merely wanted total domination\n"
	.string "over the UNOVA region.\p"
	.string "As part of his true goals, he secretly\n"
	.string "had work done to create a POKéMON using\l"
	.string "a modified fossil from millions of years\l"
	.string "ago to create an unstoppable weapon.\p"
	.string "However, when I became aware of this\n"
	.string "plan, I secretly stole this POKéMON and\l"
	.string "fled the region.$"

MtPyre_6F_Text_BeenLookingForATrainer:
	.string "I've been looking for a TRAINER I can\n"
	.string "entrust to look after this POKéMON for\l"
	.string "the forseeable future.\p"
	.string "And this is where you come in.\p"
	.string "You became the CHAMPION and overcame\n"
	.string "even tougher trials since then.\p"
	.string "I believe you can be trusted with this.\n"
	.string "Please take care of this GENESECT!$"

MtPyre_6F_Text_AlsoTakeThese:
	.string "Oh, you should also take these.\p"
	.string "Giving one of these to GENESECT will\n"
	.string "change the type of its TECHNO BLAST.$"

MtPyre_6F_Text_FinallyGoHome:
	.string "Now that I have found a TRAINER to look\n"
	.string "after GENESECT for me, maybe I can\l"
	.string "finally fly home knowing that GHETSIS\l"
	.string "can't get his hands on GENESECT.$"

MtPyre_6F_Text_PlayerReceivedGenesect:
	.string "{PLAYER} received GENESECT!$"

MtPyre_6F_Text_ValerieIntro:
	.string "When I'm here…\n"
	.string "A curious power flows into me…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "The power is ebbing away…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Perhaps the power is from the spirits\n"
	.string "of POKéMON in fitful sleep here…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… I lost the match, but…\n"
	.string "I have this little ability…\p"
	.string "Without ever laying my hands on\n"
	.string "your POKéNAV… Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Behind you…\n"
	.string "What is it…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Something faded away…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "The POKéMON at rest here…\n"
	.string "Sometimes, they play…$"

MtPyre_6F_Text_CedricIntro:
	.string "Have you lost your bearings?\n"
	.string "Have no fear for I am here!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Weren't you lost?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "I had this feeling that a lost TRAINER\n"
	.string "would be panicked and easy to beat.\p"
	.string "It's dirty and I won't try it again…$"

