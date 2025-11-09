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
