SomewhereElse_MapScripts::
	.byte 0

SomewhereElse_EventScript_TheTree::
	lock
	goto_if_set FLAG_OBTAINED_EGG, SomewhereElse_EventScript_VacantTree
	msgbox SomewhereElse_Text_HeIsBehind, MSGBOX_DEFAULT
	release
	end

SomewhereElse_EventScript_VacantTree::
	msgbox SomewhereElse_Text_ItIsATree, MSGBOX_DEFAULT
	release
	end

SomewhereElse_EventScript_TheMan::
	lock
	goto_if_set FLAG_OBTAINED_EGG, SomewhereElse_EventScript_NotAMan
	msgbox SomewhereElse_Text_ThereIsAMan, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SomewhereElse_EventScript_TheEgg
	release
	end

SomewhereElse_EventScript_TheEgg::
	giveitem ITEM_LUCKY_EGG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OBTAINED_EGG
	release
	end

SomewhereElse_EventScript_NotAMan::
	msgbox SomewhereElse_Text_ThereIsNotAMan, MSGBOX_DEFAULT
	release
	end

SomewhereElse_Text_HeIsBehind:
	.string "(He is behind the tree.)$"

SomewhereElse_Text_ItIsATree:
	.string "(It is a tree.)$"

SomewhereElse_Text_ThereIsAMan:
	.string "(Well, there is a man here.)\p"
	.string "(He offered you something.)$"

SomewhereElse_Text_ThereIsNotAMan:
	.string "(Well, there is not a man here.)$"
