Route133_MapScripts::
	.byte 0

Route133_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN, Route133_Text_FranklinIntro, Route133_Text_FranklinDefeat
	msgbox Route133_Text_FranklinPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA, Route133_Text_DebraIntro, Route133_Text_DebraDefeat
	msgbox Route133_Text_DebraPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Linda::
	trainerbattle_single TRAINER_LINDA, Route133_Text_LindaIntro, Route133_Text_LindaDefeat
	msgbox Route133_Text_LindaPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN, Route133_Text_WarrenIntro, Route133_Text_WarrenDefeat
	msgbox Route133_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Beck::
	trainerbattle_single TRAINER_BECK, Route133_Text_BeckIntro, Route133_Text_BeckDefeat
	msgbox Route133_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Mollie::
	trainerbattle_single TRAINER_MOLLIE, Route133_Text_MollieIntro, Route133_Text_MollieDefeat
	msgbox Route133_Text_MolliePostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Conor::
	trainerbattle_single TRAINER_CONOR, Route133_Text_ConorIntro, Route133_Text_ConorDefeat
	msgbox Route133_Text_ConorPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_RouteMaster::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LIFE_ORB, Route133_EventScript_RouteMasterGivenItem
	goto_if_defeated TRAINER_ROUTE_MASTER_133, Route133_EventScript_RouteMasterDefeated
	goto_if_not_defeated TRAINER_FRANKLIN, Route133_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_DEBRA, Route133_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_LINDA, Route133_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_WARREN, Route133_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_BECK, Route133_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_MOLLIE, Route133_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_CONOR, Route133_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_GILBERT, Route133_EventScript_RouteMasterCleared133
	goto_if_not_defeated TRAINER_DANA, Route133_EventScript_RouteMasterCleared133
	goto_if_not_defeated TRAINER_RONALD, Route133_EventScript_RouteMasterCleared133
	goto_if_not_defeated TRAINER_KIYO, Route133_EventScript_RouteMasterCleared133
	goto_if_not_defeated TRAINER_PAXTON, Route133_EventScript_RouteMasterCleared133
	goto_if_not_defeated TRAINER_DARCY, Route133_EventScript_RouteMasterCleared133
	goto_if_not_defeated TRAINER_JONATHAN, Route133_EventScript_RouteMasterCleared133
	goto_if_not_defeated TRAINER_MAKAYLA, Route133_EventScript_RouteMasterCleared133
	goto_if_not_defeated TRAINER_JACK, Route133_EventScript_RouteMasterCleared132
	goto_if_not_defeated TRAINER_LAUREL, Route133_EventScript_RouteMasterCleared132
	goto_if_not_defeated TRAINER_ALEX, Route133_EventScript_RouteMasterCleared132
	goto_if_not_defeated TRAINER_AARON, Route133_EventScript_RouteMasterCleared132
	goto_if_not_defeated TRAINER_HITOSHI, Route133_EventScript_RouteMasterCleared132
	goto_if_not_defeated TRAINER_HUDSON, Route133_EventScript_RouteMasterCleared132
	goto_if_not_defeated TRAINER_REYNA, Route133_EventScript_RouteMasterCleared132
	goto_if_not_defeated TRAINER_MARLEY, Route133_EventScript_RouteMasterCleared132
	goto_if_not_defeated TRAINER_KELVIN, Route133_EventScript_RouteMasterCleared132
	goto_if_unset FLAG_SPOKEN_TO_133_ROUTE_MASTER, Route133_EventScript_RouteMasterFirstMetCleared
	msgbox Route133_Text_ClearedEveryRoute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route133_EventScript_RouteMasterWillWait
	msgbox Route133_Text_LetUsBegin, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ROUTE_MASTER_133, Route133_Text_RouteMasterDefeat
	goto Route133_EventScript_RouteMasterDefeated
	end

Route133_EventScript_RouteMasterDefeated::
	msgbox Route133_Text_FutureLooksBright, MSGBOX_DEFAULT
	giveitem ITEM_LIFE_ORB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route133_Text_BecomeTheChampion, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LIFE_ORB
	release
	end

Route133_EventScript_RouteMasterNotReady::
	goto_if_unset FLAG_SPOKEN_TO_133_ROUTE_MASTER, Route133_EventScript_RouteMasterFirstMet
	msgbox Route133_Text_StillNeedToClear133, MSGBOX_DEFAULT
	release
	end

Route133_EventScript_RouteMasterCleared133::
	goto_if_unset FLAG_SPOKEN_TO_133_ROUTE_MASTER, Route133_EventScript_RouteMasterFirstMet
	msgbox Route133_Text_StillNeedToClear132, MSGBOX_DEFAULT
	release
	end

Route133_EventScript_RouteMasterCleared132::
	goto_if_unset FLAG_SPOKEN_TO_133_ROUTE_MASTER, Route133_EventScript_RouteMasterFirstMet
	msgbox Route133_Text_StillNeedToClear134, MSGBOX_DEFAULT
	release
	end

Route133_EventScript_RouteMasterFirstMet::
	setflag FLAG_SPOKEN_TO_133_ROUTE_MASTER
	msgbox Route133_Text_DoYouKnowTheLifeOrb, MSGBOX_DEFAULT
	msgbox Route133_Text_ComeCheckYourProgress, MSGBOX_DEFAULT
	release
	end

Route133_EventScript_RouteMasterFirstMetCleared::
	setflag FLAG_SPOKEN_TO_133_ROUTE_MASTER
	msgbox Route133_Text_DoYouKnowTheLifeOrb, MSGBOX_DEFAULT
	msgbox Route133_Text_AlreadyDoneIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route133_EventScript_RouteMasterWillWait
	msgbox Route133_Text_LetUsBegin, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ROUTE_MASTER_133, Route133_Text_RouteMasterDefeat
	goto Route133_EventScript_RouteMasterDefeated
	end

Route133_EventScript_RouteMasterWillWait::
	msgbox Route133_Text_PreparationIsImportant, MSGBOX_DEFAULT
	release
	end

Route133_EventScript_RouteMasterGivenItem::
	msgbox Route133_Text_BecomeTheChampion, MSGBOX_DEFAULT
	release
	end

Route133_Text_DoYouKnowTheLifeOrb:
	.string "For one as young as you to make it\n"
	.string "all the way out here…\p"
	.string "You must be one impressive TRAINER.\p"
	.string "Do you know of the item LIFE ORB?\n"
	.string "It is a very strong item that grants\l"
	.string "immense power to the holder.\p"
	.string "However, such power comes at a cost.\n"
	.string "You will lose health every time you\l"
	.string "use an attack.\p"
	.string "Any TRAINER who can use this item to\n"
	.string "its fullest potential will achieve\l"
	.string "true greatness.\p"
	.string "I'm not going to just hand you this\n"
	.string "item for free, however.\p"
	.string "I'm sure you've met numerous TRAINERS\n"
	.string "up to this point who have asked you\l"
	.string "to defeat every TRAINER on a ROUTE\l"
	.string "before allowing you to challenge them.\p"
	.string "I think you know what comes next then.\p"
	.string "I'm going to ask a little more from\n"
	.string "you than that, though!\p"
	.string "I want you to defeat every TRAINER on\n"
	.string "ROUTES 132, 133 and 134!\p"
	.string "By the end of this you will surely be\n"
	.string "a master of the currents!$"

Route133_Text_ComeCheckYourProgress:
	.string "You can come back here to check your\n"
	.string "progress with me any time.\p"
	.string "I'll be here waiting!$"

Route133_Text_AlreadyDoneIt:
	.string "Wait, you have done that already?\p"
	.string "You seriously defeated every TRAINER\n"
	.string "before you even spoke to me?\p"
	.string "Very impressive, young one!\n"
	.string "In that case, shall we begin our battle?$"

Route133_Text_StillNeedToClear133:
	.string "Hello, again, young one.\n"
	.string "Back to check your progress?\p"
	.string "Hm…\p"
	.string "Looks like there are still TRAINERS on\n"
	.string "this ROUTE that you need to defeat.\p"
	.string "This ROUTE being ROUTE 133, that is.$"

Route133_Text_StillNeedToClear132:
	.string "Hello, again, young one.\n"
	.string "Back to check your progress?\p"
	.string "Hm…\p"
	.string "Looks like there are still TRAINERS on\n"
	.string "ROUTE 132 that you need to defeat.\p"
	.string "That being the ROUTE near PACIFIDLOG.$"

Route133_Text_StillNeedToClear134:
	.string "Hello, again, young one.\n"
	.string "Back to check your progress?\p"
	.string "Hm…\p"
	.string "Looks like there are still TRAINERS on\n"
	.string "ROUTE 134 that you need to defeat.\p"
	.string "That being the ROUTE down the currents.$"

Route133_Text_ClearedEveryRoute:
	.string "Hello, again, young one.\n"
	.string "Back to check your progress?\p"
	.string "Hm…\p"
	.string "Looks like you have defeated each and\n"
	.string "every TRAINER on all three ROUTES!\p"
	.string "Good work, young one!\n"
	.string "In that case, shall we begin our battle?$"

Route133_Text_PreparationIsImportant:
	.string "Preparation is important.\n"
	.string "You should make sure you are ready.$"

Route133_Text_LetUsBegin:
	.string "Then let us begin!\p"
	.string "Allow me to show you the terrifying\n"
	.string "power that comes from the LIFE ORB!$"

Route133_Text_RouteMasterDefeat:
	.string "A decisive victory!\n"
	.string "I applaud your strength, young one!$"

Route133_Text_FutureLooksBright:
	.string "The future looks bright if we have\n"
	.string "youngsters like you around.\p"
	.string "Here, you've earned this LIFE ORB.$"

Route133_Text_BecomeTheChampion:
	.string "With strength like yours, I feel\n"
	.string "you could even become the CHAMPION.\p"
	.string "Whichever path life takes you down,\n"
	.string "I'm sure you'll do just fine.$"
