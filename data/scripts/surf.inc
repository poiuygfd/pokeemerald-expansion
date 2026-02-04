EventScript_UseSurf::
	checkfieldmove FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckForBrineysKeys
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	clearflag FLAG_IS_PLAYER_BOATING
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end

EventScript_CheckForBrineysKeys::
	checkitem ITEM_BRINEYS_KEYS
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndUseSurf
EventScript_WantToUseBrineysKeys::
	lockall
	msgbox gText_WantToUseBrineysKeys, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
EventScript_UseBrineysKeys::
	msgbox gText_PlayerUsedBrineysKeys, MSGBOX_DEFAULT
	setflag FLAG_IS_PLAYER_BOATING
	dofieldeffect FLDEFF_USE_SURF
	goto EventScript_ReleaseUseSurf
	end

EventScript_MoveBrineyRoute104::
	lock
	delay 16
	applymovement LOCALID_ROUTE104_BRINEY, Movement_BrineyBoard104
	waitmovement 0
	removeobject LOCALID_ROUTE104_BRINEY
	delay 16
	goto EventScript_BrineyIsSteering
EventScript_MoveBrineyDewfordTown::
	lock
	delay 16
	applymovement LOCALID_DEWFORD_BRINEY, Movement_BrineyBoardDewford
	waitmovement 0
	removeobject LOCALID_DEWFORD_BRINEY
	delay 16
	goto EventScript_BrineyIsSteering
EventScript_MoveBrineyRoute109::
	lock
	delay 16
	applymovement LOCALID_ROUTE109_BRINEY, Movement_BrineyBoard109
	waitmovement 0
	removeobject LOCALID_ROUTE109_BRINEY
	delay 16
	goto EventScript_BrineyIsSteering
EventScript_BrineyIsSteering::
	msgbox Text_BrineyOffWeGo, MSGBOX_DEFAULT
	closemessage
	release
	return

Movement_BrineyBoard104:
	walk_down
	walk_down
	step_end
Movement_BrineyBoardDewford:
	walk_left
	walk_up
	step_end
Movement_BrineyBoard109:
	walk_down
	walk_down
	step_end

Text_BrineyOffWeGo:
	.string "MR. BRINEY: Alright, PEEKO, {PLAYER}{KUN}!\n"
	.string "We're setting sail!$"
