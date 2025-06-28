LilycoveCity_DepartmentStore_1F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_1F_EventScript_Greeter::
	msgbox LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special DoLotteryCornerComputerEffect
	special PickLotteryCornerTicket
	delay 220
	special EndLotteryCornerComputerEffect
	delay 10
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, LilycoveCity_DepartmentStore_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, LilycoveCity_DepartmentStore_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FullMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokeBallLotto::
	lock
	faceplayer
	goto_if_ne VAR_POKELOT_BALL_PRIZE, ITEM_NONE, LilycoveCity_DepartmentStore_1F_EventScript_GiveBallFromEarlier
	goto_if_set FLAG_DAILY_PICKED_POKE_BALL, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerPokeBall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_POKE_BALL
	applymovement LOCALID_POKE_BALL_CLERK, Common_Movement_WalkInPlaceDown
	waitmovement 10
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickBall
	waitmessage
	random 26
	goto_if_eq VAR_RESULT, 0, LilycoveCity_DepartmentStore_1F_EventScript_GiveMasterBall
	goto_if_eq VAR_RESULT, 1, LilycoveCity_DepartmentStore_1F_EventScript_GivePokeBall
	goto_if_eq VAR_RESULT, 2, LilycoveCity_DepartmentStore_1F_EventScript_GiveGreatBall
	goto_if_eq VAR_RESULT, 3, LilycoveCity_DepartmentStore_1F_EventScript_GiveUltraBall
	goto_if_eq VAR_RESULT, 4, LilycoveCity_DepartmentStore_1F_EventScript_GivePremierBall
	goto_if_eq VAR_RESULT, 5, LilycoveCity_DepartmentStore_1F_EventScript_GiveHealBall
	goto_if_eq VAR_RESULT, 6, LilycoveCity_DepartmentStore_1F_EventScript_GiveNetBall
	goto_if_eq VAR_RESULT, 7, LilycoveCity_DepartmentStore_1F_EventScript_GiveNestBall
	goto_if_eq VAR_RESULT, 8, LilycoveCity_DepartmentStore_1F_EventScript_GiveDiveBall
	goto_if_eq VAR_RESULT, 9, LilycoveCity_DepartmentStore_1F_EventScript_GiveDuskBall
	goto_if_eq VAR_RESULT, 10, LilycoveCity_DepartmentStore_1F_EventScript_GiveTimerBall
	goto_if_eq VAR_RESULT, 11, LilycoveCity_DepartmentStore_1F_EventScript_GiveQuickBall
	goto_if_eq VAR_RESULT, 12, LilycoveCity_DepartmentStore_1F_EventScript_GiveRepeatBall
	goto_if_eq VAR_RESULT, 13, LilycoveCity_DepartmentStore_1F_EventScript_GiveLuxuryBall
	goto_if_eq VAR_RESULT, 14, LilycoveCity_DepartmentStore_1F_EventScript_GiveLevelBall
	goto_if_eq VAR_RESULT, 15, LilycoveCity_DepartmentStore_1F_EventScript_GiveLureBall
	goto_if_eq VAR_RESULT, 16, LilycoveCity_DepartmentStore_1F_EventScript_GiveMoonBall
	goto_if_eq VAR_RESULT, 17, LilycoveCity_DepartmentStore_1F_EventScript_GiveFriendBall
	goto_if_eq VAR_RESULT, 18, LilycoveCity_DepartmentStore_1F_EventScript_GiveLoveBall
	goto_if_eq VAR_RESULT, 19, LilycoveCity_DepartmentStore_1F_EventScript_GiveFastBall
	goto_if_eq VAR_RESULT, 20, LilycoveCity_DepartmentStore_1F_EventScript_GiveHeavyBall
	goto_if_eq VAR_RESULT, 21, LilycoveCity_DepartmentStore_1F_EventScript_GiveSafariBall
	goto_if_eq VAR_RESULT, 22, LilycoveCity_DepartmentStore_1F_EventScript_GiveParkBall
	goto_if_eq VAR_RESULT, 23, LilycoveCity_DepartmentStore_1F_EventScript_GiveDreamBall
	goto_if_eq VAR_RESULT, 24, LilycoveCity_DepartmentStore_1F_EventScript_GiveCherishBall
	goto_if_eq VAR_RESULT, 25, LilycoveCity_DepartmentStore_1F_EventScript_GiveBeastBall
	goto_if_eq VAR_RESULT, 26, LilycoveCity_DepartmentStore_1F_EventScript_GiveStrangeBall
	goto LilycoveCity_DepartmentStore_1F_EventScript_GivePokeBall
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveMasterBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_MASTER_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GivePokeBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_POKE_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveGreatBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_GREAT_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveUltraBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_ULTRA_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GivePremierBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_PREMIER_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveHealBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_HEAL_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveNetBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_NET_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveNestBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_NEST_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveDiveBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_DIVE_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveDuskBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_DUSK_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveTimerBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_TIMER_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveQuickBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_QUICK_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveRepeatBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_REPEAT_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveLuxuryBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_LUXURY_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveLevelBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_LEVEL_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveLureBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_LURE_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveMoonBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_MOON_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveFriendBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_FRIEND_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveLoveBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_LOVE_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveFastBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_FAST_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveHeavyBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_HEAVY_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveSafariBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_SAFARI_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveParkBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_PARK_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveDreamBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_DREAM_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveCherishBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_CHERISH_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveBeastBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_BEAST_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveStrangeBall::
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_STRANGE_BALL
	goto LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveBallPrize::
	bufferitemname STR_VAR_1, VAR_POKELOT_BALL_PRIZE
	msgbox LilycoveCity_DepartmentStore_1F_Text_PokeBallPrize, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_BALL_PRIZE
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_NONE
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_GiveBallFromEarlier::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_BALL_PRIZE
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	setvar VAR_POKELOT_BALL_PRIZE, ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LittleGirl::
	msgbox LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanM::
	msgbox LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_Whimsicott::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WHIMSICOTT, CRY_MODE_NORMAL
	msgbox LilycoveCity_DepartmentStore_1F_Text_Whimsicott, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_FloorNamesSign::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
	end

LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore:
	.string "Welcome to LILYCOVE DEPARTMENT STORE.$"

LilycoveCity_DepartmentStore_1F_Text_LotteryCornerPokeBall:
	.string "This is the POKé BALL LOTTO CORNER.\p"
	.string "All shoppers can enter this lotto to\n"
	.string "recieve a free kind of POKé BALL.\p"
	.string "The kind of POKé BALL you recieve is\n"
	.string "random, and you may end up finding some\l"
	.string "rare kinds of POKé BALLs.\p"
	.string "Would you like to enter?$"

LilycoveCity_DepartmentStore_1F_Text_PleasePickBall:
	.string "Please put your hand in here.\n"
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"

LilycoveCity_DepartmentStore_1F_Text_PokeBallPrize:
	.string "You've won the {STR_VAR_1}!\p"
	.string "If you would like to try again, please\n"
	.string "come back tomorrow.$"

LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings:
	.string "Whenever I come to the DEPARTMENT\n"
	.string "STORE, I always end up buying all sorts\l"
	.string "of things because it's so fun.$"

LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture:
	.string "Today, my mom is going to buy me some\n"
	.string "nice furniture.$"

LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill:
	.string "I'm buying something for WHIMSICOTT\n"
	.string "as a reward for winning a CONTEST.$"

LilycoveCity_DepartmentStore_1F_Text_Whimsicott:
	.string "WHIMSICOTT: Fweeee!$"

LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign:
	.string "1F: SERVICE COUNTER\n"
	.string "    LOTTERY CORNER\p"
	.string "2F: TRAINER'S ZONE\p"
	.string "3F: BATTLE COLLECTION\p"
	.string "4F: TM CORNER\n"
	.string "    STONE EMPORIUM\p"
	.string "5F: POKé DOLL SHOP\n"
	.string "    DECOR FLOOR\p"
	.string "ROOFTOP: ROOFTOP PLAZA$"

@ Unused
LilycoveCity_DepartmentStore_1F_Text_WirelessCommIsFun:
	.string "Wireless Communication is a\n"
	.string "lot of fun, isn't it?\p"
	.string "I think it lets you do things that\n"
	.string "weren't possible before.\p"
	.string "For instance, you can now trade\n"
	.string "with people you couldn't before.\p"
	.string "I think it's going to be exciting!$"

@ Unused
LilycoveCity_DepartmentStore_1F_Text_SpreadWordAboutWirelessComm:
	.string "I want to spread the word about how\n"
	.string "fun Wireless Communication can be.$"

