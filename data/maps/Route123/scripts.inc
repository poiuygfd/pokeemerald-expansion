Route123_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
	.byte 0

Route123_OnTransition:
	special SetRoute123Weather
	end

Route123_EventScript_GigaDrainGirl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_GIGA_DRAIN, Route123_EventScript_ReceivedGigaDrain
	msgbox Route123_Text_LoveGrassMonsHaveAny, MSGBOX_DEFAULT
	special IsGrassTypeInParty
	goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGrassMons
	msgbox Route123_Text_YouLikeGrassMonsTooHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_GIGA_DRAIN
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_NoGrassMons::
	release
	end

Route123_EventScript_ReceivedGigaDrain::
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RouteSign::
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
	end

Route123_EventScript_RouteSignMtPyre::
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
	end

Route123_EventScript_BerryMastersHouseSign::
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
	end

Route123_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY, Route123_Text_WendyIntro, Route123_Text_WendyDefeat
	msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Braxton::
	trainerbattle_single TRAINER_BRAXTON, Route123_Text_BraxtonIntro, Route123_Text_BraxtonDefeat
	msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Violet::
	trainerbattle_single TRAINER_VIOLET, Route123_Text_VioletIntro, Route123_Text_VioletDefeat
	msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Route123_EventScript_RegisterCameron
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchCameron
	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterCameron::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CAMERON_1
	release
	end

Route123_EventScript_RematchCameron::
	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jacki::
	trainerbattle_single TRAINER_JACKI_1, Route123_Text_JackiIntro, Route123_Text_JackiDefeat, Route123_EventScript_RegisterJacki
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchJacki
	msgbox Route123_Text_JackiPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterJacki::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_JackiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKI_1
	release
	end

Route123_EventScript_RematchJacki::
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_JackiRematchIntro, Route123_Text_JackiRematchDefeat
	msgbox Route123_Text_JackiPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Miu::
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_MiuIntro, Route123_Text_MiuDefeat, Route123_Text_MiuNotEnoughMons
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Yuki::
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_YukiIntro, Route123_Text_YukiDefeat, Route123_Text_YukiNotEnoughMons
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Kindra::
	trainerbattle_single TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Frederick::
	trainerbattle_single TRAINER_FREDRICK, Route123_Text_FrederickIntro, Route123_Text_FrederickDefeat
	msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Alberto::
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Ed::
	trainerbattle_single TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Kayley::
	trainerbattle_single TRAINER_KAYLEY, Route123_Text_KayleyIntro, Route123_Text_KayleyDefeat
	msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jonas::
	trainerbattle_single TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jazmyn::
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Davis::
	trainerbattle_single TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Fernando::
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Route123_EventScript_RegisterFernando
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchFernando
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterFernando::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_FERNANDO_1
	release
	end

Route123_EventScript_RematchFernando::
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_RouteMaster::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FOCUS_SASH, Route123_EventScript_RouteMasterGivenItem
	goto_if_defeated TRAINER_ROUTE_MASTER_123, Route123_EventScript_RouteMasterDefeated
	goto_if_not_defeated TRAINER_WENDY, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_BRAXTON, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_VIOLET, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_CAMERON_1, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_JACKI_1, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_MIU_AND_YUKI, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_KINDRA, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_FREDRICK, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_ALBERTO, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_ED, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_KAYLEY, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_JONAS, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_JAZMYN, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_DAVIS, Route123_EventScript_RouteMasterNotReady
	goto_if_not_defeated TRAINER_FERNANDO_1, Route123_EventScript_RouteMasterNotReady
	msgbox Route123_Text_ILoveDramaticFinishes, MSGBOX_DEFAULT
	msgbox Route123_Text_YouMightBeTheOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route123_EventScript_RouteMasterWillWait
	msgbox Route123_Text_BattleOfALifetime, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ROUTE_MASTER_123, Route123_Text_RouteMasterDefeat
	goto Route123_EventScript_RouteMasterDefeated
	end

Route123_EventScript_RouteMasterDefeated::
	msgbox Route123_Text_WasntDramaticAtAll, MSGBOX_DEFAULT
	giveitem ITEM_FOCUS_SASH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route123_Text_HangOnByAThread, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_FOCUS_SASH
	release
	end

Route123_EventScript_RouteMasterNotReady::
	msgbox Route123_Text_ILoveDramaticFinishes, MSGBOX_DEFAULT
	msgbox Route123_Text_CantPushMeToTheBrink, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RouteMasterWillWait::
	msgbox Route123_Text_YouToyWithMe, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RouteMasterGivenItem::
	msgbox Route123_Text_HangOnByAThread, MSGBOX_DEFAULT
	release
	end

Route123_Text_LoveGrassMonsHaveAny:
	.string "I love GRASS-type POKéMON!\p"
	.string "Do you have any GRASS-type POKéMON?$"

Route123_Text_YouLikeGrassMonsTooHaveThis:
	.string "Oh?\p"
	.string "You like GRASS-type POKéMON, too,\n"
	.string "don't you?\p"
	.string "I'm so happy, you can have this!\n"
	.string "It's a token of our friendship.$"

Route123_Text_CheckTreesWithMyGrassMon:
	.string "I check trees with my GRASS-type\n"
	.string "POKéMON. I'm like a tree doctor.$"

Route123_Text_ILoveDramaticFinishes:
	.string "I love battles with a dramatic finish!\p"
	.string "Ones where your opponent hangs on by\n"
	.string "a thread, only to turn the tides and\l"
	.string "clutch victory from the jaws of defeat…\p"
	.string "Oh, I yearn for battles like that!$"

Route123_Text_CantPushMeToTheBrink:
	.string "But for that, I need a TRAINER who\n"
	.string "is strong enough to push me to the\l"
	.string "absolute brink!\p"
	.string "If you can prove your strength by\n"
	.string "defeating every TRAINER on this\l"
	.string "ROUTE, then I'd love to battle you!$"

Route123_Text_YouMightBeTheOne:
	.string "I think you might just have the\n"
	.string "strength to push me to the brink!\p"
	.string "A dramatic, heart-throbbing battle…\n"
	.string "Won't you please indulge me with the\l"
	.string "battle of a lifetime?$"

Route123_Text_YouToyWithMe:
	.string "Ack, you toy with me!\p"
	.string "Please, prepare yourself and hurry\n"
	.string "back as fast as possible!$"

Route123_Text_BattleOfALifetime:
	.string "Oh, thank you!\n"
	.string "Let's have the battle for the ages!$"

Route123_Text_RouteMasterDefeat:
	.string "Wait, you were too strong!\n"
	.string "I wasn't supposed to actually lose!$"

Route123_Text_WasntDramaticAtAll:
	.string "That wasn't dramatic at all!\p"
	.string "And yet…\n"
	.string "That got my heart throbbing in its\l"
	.string "own kind of way…\p"
	.string "That was a thrilling expereince!\n"
	.string "This is my way of saying thanks!$"

Route123_Text_HangOnByAThread:
	.string "The FOCUS SASH will let you hang\n"
	.string "on by a thread if an attack would\l"
	.string "have knocked you out from full HP.\p"
	.string "It is truly an item that can swing\n"
	.string "the tide of battle!\p"
	.string "That's what I call a dramatic finish!$"

Route123_Text_RouteSign:
	.string "{RIGHT_ARROW} ROUTE 123\n"
	.string "{LEFT_ARROW} ROUTE 118$"

Route123_Text_RouteSignMtPyre:
	.string "{UP_ARROW} MT. PYRE\n"
	.string "“Forbidden to the faint of heart.”$"

Route123_Text_BerryMastersHouse:
	.string "BERRY MASTER'S HOUSE$"

