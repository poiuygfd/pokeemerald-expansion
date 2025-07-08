TheDepths_B4F_MapScripts::
	.byte 0

TheDepths_B4F_EventScript_LeftHealTrigger::
	lock
	applymovement LOCALID_DEPTHS_HEALER, TheDepths_B4F_Movement_HealManLeft
	waitmovement 0
	setvar VAR_DEPTHS_STATE, 4
	setvar VAR_DEPTHS_MON_STATE, 4
	goto TheDepths_B4F_EventScript_GetHealed

TheDepths_B4F_Movement_HealManLeft:
	walk_left
	walk_down
	step_end

TheDepths_B4F_EventScript_CenterHealTrigger::
	lock
	applymovement LOCALID_DEPTHS_HEALER, TheDepths_B4F_Movement_HealManCenter
	waitmovement 0
	setvar VAR_DEPTHS_STATE, 4
	setvar VAR_DEPTHS_MON_STATE, 4
	goto TheDepths_B4F_EventScript_GetHealed

TheDepths_B4F_Movement_HealManCenter:
	walk_down
	step_end

TheDepths_B4F_EventScript_RightHealTrigger::
	lock
	applymovement LOCALID_DEPTHS_HEALER, TheDepths_B4F_Movement_HealManRight
	waitmovement 0
	setvar VAR_DEPTHS_STATE, 4
	setvar VAR_DEPTHS_MON_STATE, 4
	goto TheDepths_B4F_EventScript_GetHealed

TheDepths_B4F_Movement_HealManRight:
	walk_right
	walk_down
	step_end

TheDepths_B4F_EventScript_HealingMan::
	lock
	faceplayer
	goto TheDepths_B4F_EventScript_GetHealed

TheDepths_B4F_EventScript_GetHealed::
	goto_if_set FLAG_DEPTHS_USED_HEAL, TheDepths_EventScript_AlreadyHealed
	msgbox TheDepths_B4F_Text_WellDoneOnMakingItThisFar, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TheDepths_EventScript_RefuseHeal
	setflag FLAG_DEPTHS_USED_HEAL
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox TheDepths_B4F_Text_WishYouBestOfLuck, MSGBOX_DEFAULT
	release
	end

TheDepths_EventScript_RefuseHeal::
	msgbox TheDepths_B4F_Text_Why, MSGBOX_DEFAULT
	release
	end

TheDepths_EventScript_AlreadyHealed::
	msgbox TheDepths_B4F_Text_WishYouBestOfLuck, MSGBOX_DEFAULT
	release
	end

TheDepths_B4F_Text_WellDoneOnMakingItThisFar:
	.string "Well done on making it this far!\p"
	.string "If you'd like, I can heal your\n"
	.string "team before you head further on.\p"
	.string "This is your only opportunity to\n"
	.string "heal, so I would make the most\l"
	.string "of it while you can!$"

TheDepths_B4F_Text_WishYouBestOfLuck:
	.string "I wish you the best of luck with\n"
	.string "the rest of your challenge!$"

TheDepths_B4F_Text_Why:
	.string "You… don't want the heal…?\n"
	.string "Why…?\p"
	.string "I suppose… I suppose I will\n"
	.string "respect your… determination?\p"
	.string "If you change your mind, uh,\n"
	.string "just… let me know…$"
