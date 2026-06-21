VoidAltar_Route133_MapScripts::
	.byte 0

VoidAltar_Route133_EventScript_Altar::
	lock
	goto_if_set FLAG_USED_VOID_ALTAR_133, VoidAltar_Route133_EventScript_AltarUsed
	msgbox VoidAltar_Text_AStrangeAltar, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VoidAltar_Route133_EventScript_AltarDecline
	msgbox VoidAltar_Text_TouchAltar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ALTAR_133, VoidAltar_Route133_Movement_AltarActivate
	waitmovement 0
	removeobject LOCALID_ALTAR_133
	addvar VAR_VOID_ALTAR_STATE, 1
	release
	end

VoidAltar_Route133_EventScript_AltarDecline::
	msgbox VoidAltar_Text_DontTouchAltar, MSGBOX_DEFAULT
	release
	end

VoidAltar_Route133_EventScript_AltarUsed::
	msgbox VoidAltar_Text_AltarIsActive, MSGBOX_DEFAULT
	release
	end

VoidAltar_Route133_Movement_AltarActivate:
	rock_smash_break
	step_end
