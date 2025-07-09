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
	goto_if_eq VAR_DEPTHS_STATE, 8, TheDepths_B8F_EventScript_ClaimedPrize
	goto_if_eq VAR_DEPTHS_MON_STATE, 8, TheDepths_B8F_EventScript_CantClaimPrize
	msgbox TheDepths_B8F_Text_CongratsOnMakingIt, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_PATCH
	goto_if_eq VAR_RESULT, FALSE, TheDepths_B8F_EventScript_CantClaimPrize
	setvar VAR_DEPTHS_STATE, 8
	release
	end

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
