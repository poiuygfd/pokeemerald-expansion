VoidAltar_Route115_MapScripts::
	.byte 0

VoidAltar_Route115_EventScript_Altar::
	lock
	goto_if_set FLAG_USED_VOID_ALTAR_115, VoidAltar_Route115_EventScript_AltarUsed
	msgbox VoidAltar_Text_AStrangeAltar, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VoidAltar_Route115_EventScript_AltarDecline
	msgbox VoidAltar_Text_TouchAltar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ALTAR_115, VoidAltar_Route115_Movement_AltarActivate
	waitmovement 0
	removeobject LOCALID_ALTAR_115
	addvar VAR_VOID_ALTAR_STATE, 1
	release
	end

VoidAltar_Route115_EventScript_AltarDecline::
	msgbox VoidAltar_Text_DontTouchAltar, MSGBOX_DEFAULT
	release
	end

VoidAltar_Route115_EventScript_AltarUsed::
	msgbox VoidAltar_Text_AltarIsActive, MSGBOX_DEFAULT
	release
	end

VoidAltar_Route115_Movement_AltarActivate:
	rock_smash_break
	step_end
