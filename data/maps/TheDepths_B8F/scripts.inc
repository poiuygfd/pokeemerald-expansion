TheDepths_B8F_MapScripts::
	.byte 0

TheDepths_B8F_EventScript_ExitDepths::
	lock
	goto_if_eq VAR_DEPTHS_STATE, 8, TheDepths_EventScript_WarpToStart
	goto_if_eq VAR_DEPTHS_MON_STATE, 8, TheDepths_EventScript_WarpToStart
	msgbox TheDepths_B8F_Text_HaventClaimedPrize, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, TheDepths_Movement_WalkDown
	waitmovement 0
	release
	end

TheDepths_B8F_EventScript_PrizeGiver::
	lock
	faceplayer
	call TheDepths_B8F_EventScript_CheckModeWin
	goto_if_eq VAR_DEPTHS_STATE, 8, TheDepths_B8F_EventScript_ClaimedPrize
	goto_if_eq VAR_DEPTHS_MON_STATE, 8, TheDepths_B8F_EventScript_CantClaimPrize
	goto_if_unset FLAG_DEPTHS_USED_HEAL, TheDepths_B8F_EventScript_NoHealPrize
	msgbox TheDepths_B8F_Text_CongratsOnMakingIt, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_CAPSULE
	goto_if_eq VAR_RESULT, FALSE, TheDepths_B8F_EventScript_CantClaimPrize
	setvar VAR_DEPTHS_STATE, 8
	msgbox TheDepths_B8F_Text_HeadOnOut, MSGBOX_DEFAULT
	release
	end

TheDepths_B8F_EventScript_NoHealPrize::
	msgbox TheDepths_B8F_Text_CongratsOnMakingItNoHeal, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_PATCH
	goto_if_eq VAR_RESULT, FALSE, TheDepths_B8F_EventScript_CantClaimPrize
	setvar VAR_DEPTHS_STATE, 8
	msgbox TheDepths_B8F_Text_HeadOnOut, MSGBOX_DEFAULT
	release
	end

TheDepths_B8F_EventScript_CheckModeWin::
	call_if_set FLAG_DEPTHS_IS_NORMAL, TheDepths_B8F_EventScript_SetNormalWin
	call_if_set FLAG_DEPTHS_IS_EXPERT, TheDepths_B8F_EventScript_SetExpertWin
	call_if_set FLAG_DEPTHS_IS_MASTER, TheDepths_B8F_EventScript_SetMasterWin
	return

TheDepths_B8F_EventScript_SetNormalWin::
	setflag FLAG_SYS_DEPTHS_NORMAL_WIN
	clearflag FLAG_DEPTHS_IS_NORMAL
	return

TheDepths_B8F_EventScript_SetExpertWin::
	setflag FLAG_SYS_DEPTHS_EXPERT_WIN
	clearflag FLAG_DEPTHS_IS_EXPERT
	return

TheDepths_B8F_EventScript_SetMasterWin::
	setflag FLAG_SYS_DEPTHS_MASTER_WIN
	clearflag FLAG_DEPTHS_IS_MASTER
	return

TheDepths_B8F_EventScript_ClaimedPrize::
	msgbox TheDepths_B8F_Text_HeadOnOut, MSGBOX_DEFAULT
	release
	end

TheDepths_B8F_EventScript_CantClaimPrize::
	msgbox TheDepths_B8F_Text_NoRoomForPrize, MSGBOX_DEFAULT
	setvar VAR_DEPTHS_MON_STATE, 8
	release
	end

TheDepths_B8F_Text_HaventClaimedPrize:
	.string "You haven't claimed your prize!$"

TheDepths_B8F_Text_CongratsOnMakingIt:
	.string "Congrats, kid!\n"
	.string "You made it to the bottom!\p"
	.string "That's no easy feat, you know.\n"
	.string "I think you've earned yourself\l"
	.string "a little prize!$"

TheDepths_B8F_Text_CongratsOnMakingItNoHeal:
	.string "Congrats, kid!\n"
	.string "You made it to the bottom!\p"
	.string "Not only that, but I've been\n"
	.string "informed you didn't even heal\l"
	.string "your POKéMON.\p"
	.string "Making it all the way down here\n"
	.string "without even needing to heal…\p"
	.string "You've got some serious guts, kid!\n"
	.string "Here, a special prize, just for you!$"

TheDepths_B8F_Text_HeadOnOut:
	.string "You can head on out through the\n"
	.string "ladder you came down from.\p"
	.string "Feel free to come back and give\n"
	.string "THE DEPTHS another challenge\l"
	.string "whenever you feel like it!$"

TheDepths_B8F_Text_NoRoomForPrize:
	.string "Looks like you don't have any\n"
	.string "room for this prize.\p"
	.string "I'll hold onto this for you then,\n"
	.string "so come pick it up from me at the\l"
	.string "entrance later when you make room.$"
