TheDepths_EventScript_ForfeitChallenge::
    lock
	msgbox TheDepths_Text_ForfeitChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheDepths_EventScript_WarpToStart
    applymovement LOCALID_PLAYER, TheDepths_Movement_WalkDown
    waitmovement 0
	release
	end

TheDepths_Movement_WalkDown:
    walk_down
	step_end

TheDepths_EventScript_WarpToStart::
    setvar VAR_DEPTHS_STATE, 9
    removeitem ITEM_RUBY
    removeitem ITEM_SAPPHIRE
    removeitem ITEM_RUBY
    warp MAP_TUFFNOOK_TOWN_DEPTHS_ENTRANCE, 8, 6
	waitstate
    end

TheDepths_EventScript_Ruby::
    msgbox TheDepths_Text_ItsARuby, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheDepths_EventScript_TakeRuby
    release
    end

TheDepths_EventScript_TakeRuby::
    giveitem ITEM_RUBY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
    removeobject VAR_LAST_TALKED
    setflag FLAG_HIDE_DEPTHS_RUBY
    return

TheDepths_EventScript_Sapphire::
    msgbox TheDepths_Text_ItsASapphire, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheDepths_EventScript_TakeSapphire
    release
    end

TheDepths_EventScript_TakeSapphire::
    giveitem ITEM_SAPPHIRE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
    removeobject VAR_LAST_TALKED
    setflag FLAG_HIDE_DEPTHS_SAPPHIRE
    return

TheDepths_EventScript_GemSocketCheckRuby::
    checkitem ITEM_RUBY
    goto_if_eq VAR_RESULT, TRUE, TheDepths_EventScript_GemSocketCheckSapphire
    msgbox TheDepths_Text_TwoSlots, MSGBOX_DEFAULT
    release
    end

TheDepths_EventScript_GemSocketCheckSapphire::
    checkitem ITEM_SAPPHIRE
    goto_if_eq VAR_RESULT, TRUE, TheDepths_EventScript_GemSocketPlacedGems
    msgbox TheDepths_Text_TwoSlots, MSGBOX_DEFAULT
    release
    end

TheDepths_EventScript_GemSocketPlacedGems::
    msgbox TheDepths_Text_PlacedGems, MSGBOX_DEFAULT
    removeitem ITEM_RUBY
    removeitem ITEM_SAPPHIRE
    removeitem ITEM_RUBY
    return

TheDepths_EventScript_GemSocketActive::
    msgbox TheDepths_Text_AlreadyActive, MSGBOX_DEFAULT
    release
    end

TheDepths_EventScript_StrongPresence::
	copyvar VAR_TEMP_LEVEL_CAP, VAR_LEVEL_CAP
	setvar VAR_LEVEL_CAP, 1
	setflag FLAG_PREVENT_BAG_USE
	setflag FLAG_PREVENT_CATCHING
	msgbox TheDepths_Text_StrongPresence
	closemessage
    return

TheDepths_EventScript_BattleAftermath::
    copyvar VAR_LEVEL_CAP, VAR_TEMP_LEVEL_CAP
	setvar VAR_TEMP_LEVEL_CAP, 0
	clearflag FLAG_PREVENT_BAG_USE
	clearflag FLAG_PREVENT_CATCHING
	msgbox TheDepths_Text_StrongPresenceLeaves
	closemessage
    end

TheDepths_Text_ForfeitChallenge:
	.string "Would you like to forfeit this dive\n"
	.string "and return to the surface?$"

TheDepths_Text_ItsARuby:
	.string "It's a shining RUBY…\n"
	.string "Take it?$"

TheDepths_Text_ItsASapphire:
	.string "It's a shining SAPPHIRE…\n"
	.string "Take it?$"

TheDepths_Text_TwoSlots:
    .string "There appears to be two slots in this\n"
    .string "wall, as well as some inscribed text.\p"
    .string "“Bring forth the gems of red and blue\n"
    .string "to clear the path to adventures new.”$"

TheDepths_Text_PlacedGems:
    .string "You placed the RUBY and SAPPHIRE into\n"
    .string "the slots on the wall.\p"
    .string "The dark rock erodes away before\n"
    .string "your very eyes!$"

TheDepths_Text_AlreadyActive:
    .string "The RUBY and SAPPHIRE shine brightly.\n"
    .string "They refuse to come out of their slots.$"

TheDepths_Text_StrongPresence:
    .string "You feel a strong presence nearby…\p"
    .string "The strong presence attacked!$"

TheDepths_Text_StrongPresenceLeaves:
    .string "The strong presence has left…$"
