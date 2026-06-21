VoidAltar_Route102_MapScripts::
	.byte 0

VoidAltar_Route102_EventScript_Altar::
	lock
	goto_if_set FLAG_USED_VOID_ALTAR_102, VoidAltar_Route102_EventScript_AltarUsed
	msgbox VoidAltar_Text_AStrangeAltar, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VoidAltar_Route102_EventScript_AltarDecline
	msgbox VoidAltar_Text_TouchAltar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ALTAR_102, VoidAltar_Route102_Movement_AltarActivate
	waitmovement 0
	removeobject LOCALID_ALTAR_102
	addvar VAR_VOID_ALTAR_STATE, 1
	release
	end

VoidAltar_Route102_EventScript_AltarDecline::
	msgbox VoidAltar_Text_DontTouchAltar, MSGBOX_DEFAULT
	release
	end

VoidAltar_Route102_EventScript_AltarUsed::
	msgbox VoidAltar_Text_AltarIsActive, MSGBOX_DEFAULT
	release
	end

VoidAltar_Route102_Movement_AltarActivate:
	rock_smash_break
	step_end

VoidAltar_EventScript_Sign::
	goto_if_set FLAG_DEFEATED_DARK_MAGIKARP, VoidAltar_EventScript_SignMagikarpDefeated
	goto_if_eq VAR_VOID_ALTAR_STATE, 1, VoidAltar_EventScript_SignOneAltar
	goto_if_eq VAR_VOID_ALTAR_STATE, 2, VoidAltar_EventScript_SignTwoAltars
	goto_if_eq VAR_VOID_ALTAR_STATE, 3, VoidAltar_EventScript_SignThreeAltars
	goto_if_eq VAR_VOID_ALTAR_STATE, 4, VoidAltar_EventScript_SignFourAltars
	goto_if_eq VAR_VOID_ALTAR_STATE, 5, VoidAltar_EventScript_SignAllAltars
	msgbox VoidAltar_Text_FiveLeft, MSGBOX_DEFAULT
	release
	end

VoidAltar_EventScript_SignOneAltar::
	msgbox VoidAltar_Text_FourLeft, MSGBOX_DEFAULT
	release
	end

VoidAltar_EventScript_SignTwoAltars::
	msgbox VoidAltar_Text_ThreeLeft, MSGBOX_DEFAULT
	release
	end

VoidAltar_EventScript_SignThreeAltars::
	msgbox VoidAltar_Text_TwoLeft, MSGBOX_DEFAULT
	release
	end

VoidAltar_EventScript_SignFourAltars::
	msgbox VoidAltar_Text_OneLeft, MSGBOX_DEFAULT
	release
	end

VoidAltar_EventScript_SignAllAltars::
	msgbox VoidAltar_Text_ZeroLeft, MSGBOX_DEFAULT
	release
	end

VoidAltar_EventScript_SignMagikarpDefeated::
	msgbox VoidAltar_Text_SignIsBlank, MSGBOX_DEFAULT
	release
	end

VoidAltar_Text_AStrangeAltar:
	.string "A strange altar lies in front\n"
	.string "of you…\p"
	.string "It feels as if though it beckons\n"
	.string "for your touch…\p"
	.string "Will you touch the altar?$"

VoidAltar_Text_TouchAltar:
	.string "You touch the altar.\p"
	.string "Your body is overwhelmed with pain as\n"
	.string "incoherent mutterings flood your head.\p"
	.string "You probably shouldn't have done that…$"

VoidAltar_Text_DontTouchAltar:
	.string "Common sense tells you that touching\n"
	.string "this would be a terrible idea.\p"
	.string "You leave the altar alone.$"

VoidAltar_Text_AltarIsActive:
	.string "The altar glows with an ominous red.$"

VoidAltar_Text_FiveLeft:
	.string "The sign is written in an ancient\n"
	.string "language you don't recognise.\p"
	.string "Yet, despite this, for some reason\n"
	.string "you can read it perfectly.\p"
	.string "“Five altars remain inactive.”\p"
	.string "“Place your hand on the altar.\n"
	.string "Trust in us as we trust in you.”$"

VoidAltar_Text_FourLeft:
	.string "The sign is written in an ancient\n"
	.string "language you don't recognise.\p"
	.string "Yet, despite this, for some reason\n"
	.string "you can read it perfectly.\p"
	.string "“Four altars remain inactive.”\p"
	.string "“Find them beyond the boundaries of\n"
	.string "this world.”$"

VoidAltar_Text_ThreeLeft:
	.string "“Three altars remain inactive.”\p"
	.string "“Find them beyond the boundaries of\n"
	.string "this world.”$"

VoidAltar_Text_TwoLeft:
	.string "“Two altars remain inactive.”\p"
	.string "“Your progress is admirable.\n"
	.string "Do not stop here.”$"

VoidAltar_Text_OneLeft:
	.string "“One altar remains inactive.”\p"
	.string "“You are so close now.\n"
	.string "We are waiting.”$"

VoidAltar_Text_ZeroLeft:
	.string "“No more altars remain inactive.”\p"
	.string "“Find us where all paths intersect.\n"
	.string "We will see you soon…”$"

VoidAltar_Text_SignIsBlank:
	.string "The sign appears to be blank.$"
