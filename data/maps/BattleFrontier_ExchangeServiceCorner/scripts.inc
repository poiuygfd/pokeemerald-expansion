BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

.macro setitemandprice item:req, price:req
	setvar VAR_0x8009, \item
	setvar VAR_0x8008, \price
.endm

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_EVOLUTION_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseEvolutionItem
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_MEGA_STONE_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMegaStone
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_EVOLUTION_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseEvolutionItem
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_MEGA_STONE_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMegaStone
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_AirBalloon
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_ShellBell
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_AbilityShield
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_ExpertBelt
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_FlameOrb
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ToxicOrb
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_WeaknessPolicy
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_BlunderPolicy
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_FocusSash
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_ThroatSpray
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_LightClay
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_TerrainExtender
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_Eviolite
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_HeavyDutyBoots
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_LoadedDice
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceSpecs
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceScarf
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 21, BattleFrontier_ExchangeServiceCorner_EventScript_LifeOrb
	case 22, BattleFrontier_ExchangeServiceCorner_EventScript_ClearAmulet
	case 23, BattleFrontier_ExchangeServiceCorner_EventScript_CovertCloak
	case 24, BattleFrontier_ExchangeServiceCorner_EventScript_RockyHelmet
	case 25, BattleFrontier_ExchangeServiceCorner_EventScript_AssaultVest
	case 26, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_AirBalloon::
	setitemandprice ITEM_AIR_BALLOON, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ShellBell::
	setitemandprice ITEM_SHELL_BELL, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_AbilityShield::
	setitemandprice ITEM_ABILITY_SHIELD, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	setitemandprice ITEM_SCOPE_LENS, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ExpertBelt::
	setitemandprice ITEM_EXPERT_BELT, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_FlameOrb::
	setitemandprice ITEM_FLAME_ORB, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ToxicOrb::
	setitemandprice ITEM_TOXIC_ORB, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_WeaknessPolicy::
	setitemandprice ITEM_WEAKNESS_POLICY, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_BlunderPolicy::
	setitemandprice ITEM_BLUNDER_POLICY, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	setitemandprice ITEM_FOCUS_BAND, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_FocusSash::
	setitemandprice ITEM_FOCUS_SASH, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ThroatSpray::
	setitemandprice ITEM_THROAT_SPRAY, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_LightClay::
	setitemandprice ITEM_LIGHT_CLAY, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_TerrainExtender::
	setitemandprice ITEM_TERRAIN_EXTENDER, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_Eviolite::
	setitemandprice ITEM_EVIOLITE, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_HeavyDutyBoots::
	setitemandprice ITEM_HEAVY_DUTY_BOOTS, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_LoadedDice::
	setitemandprice ITEM_LOADED_DICE, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	setitemandprice ITEM_CHOICE_BAND, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceSpecs::
	setitemandprice ITEM_CHOICE_SPECS, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceScarf::
	setitemandprice ITEM_CHOICE_SCARF, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	setitemandprice ITEM_LEFTOVERS, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_LifeOrb::
	setitemandprice ITEM_LIFE_ORB, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ClearAmulet::
	setitemandprice ITEM_CLEAR_AMULET, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_CovertCloak::
	setitemandprice ITEM_COVERT_CLOAK, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_RockyHelmet::
	setitemandprice ITEM_ROCKY_HELMET, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_AssaultVest::
	setitemandprice ITEM_ASSAULT_VEST, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_LotadDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_SeedotDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_RegirockDoll
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_RegiceDoll
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_RegisteelDoll
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor::
	bufferdecorationname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
	setitemandprice DECOR_KISS_POSTER, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
	setitemandprice DECOR_KISS_CUSHION, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll::
	setitemandprice DECOR_SMOOCHUM_DOLL, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
	setitemandprice DECOR_TOGEPI_DOLL, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
	setitemandprice DECOR_MEOWTH_DOLL, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
	setitemandprice DECOR_CLEFAIRY_DOLL, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
	setitemandprice DECOR_DITTO_DOLL, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_LotadDoll::
	setitemandprice DECOR_LOTAD_DOLL, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_SeedotDoll::
	setitemandprice DECOR_SEEDOT_DOLL, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	setitemandprice DECOR_CYNDAQUIL_DOLL, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	setitemandprice DECOR_CHIKORITA_DOLL, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
	setitemandprice DECOR_TOTODILE_DOLL, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
	setitemandprice DECOR_LAPRAS_DOLL, 40
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	setitemandprice DECOR_SNORLAX_DOLL, 40
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
	setitemandprice DECOR_VENUSAUR_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
	setitemandprice DECOR_CHARIZARD_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	setitemandprice DECOR_BLASTOISE_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_RegirockDoll::
	setitemandprice DECOR_REGIROCK_DOLL, 56
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_RegiceDoll::
	setitemandprice DECOR_REGICE_DOLL, 56
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_RegisteelDoll::
	setitemandprice DECOR_REGISTEEL_DOLL, 56
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor

BattleFrontier_ExchangeServiceCorner_EventScript_EvolutionClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_EVOLUTION_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseEvolutionItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseEvolutionItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_EVOLUTION_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Everstone
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_LinkingCord
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Upgrade
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_DubiousDisc
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_AuspiciousArmor
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_MaliciousArmor
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_RazorFang
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_WhippedDream
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_PrismScale
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ReaperCloth
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_GalaricaCuff
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_GalaricaWreath
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_Protector
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_DeepSeaTooth
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_DeepSeaScale
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_DragonScale
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_LeadersCrest
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_MetalCoat
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_BlackAugurite
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_PeatBlock
	case 21, BattleFrontier_ExchangeServiceCorner_EventScript_MetalAlloy
	case 22, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseEvolutionItem
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Everstone::
	setitemandprice ITEM_EVERSTONE, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_LinkingCord::
	setitemandprice ITEM_LINKING_CORD, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_Upgrade::
	setitemandprice ITEM_UPGRADE, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_DubiousDisc::
	setitemandprice ITEM_DUBIOUS_DISC, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_AuspiciousArmor::
	setitemandprice ITEM_AUSPICIOUS_ARMOR, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_MaliciousArmor::
	setitemandprice ITEM_MALICIOUS_ARMOR, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_RazorFang::
	setitemandprice ITEM_RAZOR_FANG, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_WhippedDream::
	setitemandprice ITEM_WHIPPED_DREAM, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_PrismScale::
	setitemandprice ITEM_PRISM_SCALE, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_ReaperCloth::
	setitemandprice ITEM_REAPER_CLOTH, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	setitemandprice ITEM_KINGS_ROCK, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_GalaricaCuff::
	setitemandprice ITEM_GALARICA_CUFF, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_GalaricaWreath::
	setitemandprice ITEM_GALARICA_WREATH, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_Protector::
	setitemandprice ITEM_PROTECTOR, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_DeepSeaTooth::
	setitemandprice ITEM_DEEP_SEA_TOOTH, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_DeepSeaScale::
	setitemandprice ITEM_DEEP_SEA_SCALE, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_DragonScale::
	setitemandprice ITEM_DRAGON_SCALE, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_LeadersCrest::
	setitemandprice ITEM_LEADERS_CREST, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_MetalCoat::
	setitemandprice ITEM_METAL_COAT, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_BlackAugurite::
	setitemandprice ITEM_BLACK_AUGURITE, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_PeatBlock::
	setitemandprice ITEM_PEAT_BLOCK, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_MetalAlloy::
	setitemandprice ITEM_METAL_ALLOY, 24
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseEvolutionItem

BattleFrontier_ExchangeServiceCorner_EventScript_MegaStoneClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_MEGA_STONE_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMegaStone
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMegaStone::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_MEGA_STONE_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Venusaurite
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_CharizarditeX
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_CharizarditeY
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Blastoisinite
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Meganiumite
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_Feraligite
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_Emboarite
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_Pinsirite
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_Heracronite
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_Alakazite
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_Starminite
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_Slowbronite
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_Gardevoirite
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_Galladite
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_Chandelurite
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_Lucarionite
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_LucarioniteZ
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_Glimmoranite
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_RaichuniteX
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_RaichuniteY
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_Golisopite
	case 21, BattleFrontier_ExchangeServiceCorner_EventScript_Emboarite
	case 22, BattleFrontier_ExchangeServiceCorner_EventScript_Pinsirite
	case 23, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMegaStone
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Venusaurite::
	setitemandprice ITEM_VENUSAURITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_CharizarditeX::
	setitemandprice ITEM_CHARIZARDITE_X, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_CharizarditeY::
	setitemandprice ITEM_CHARIZARDITE_Y, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Blastoisinite::
	setitemandprice ITEM_BLASTOISINITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Meganiumite::
	setitemandprice ITEM_MEGANIUMITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Feraligite::
	setitemandprice ITEM_FERALIGITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Emboarite::
	setitemandprice ITEM_EMBOARITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Pinsirite::
	setitemandprice ITEM_PINSIRITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Heracronite::
	setitemandprice ITEM_HERACRONITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Alakazite::
	setitemandprice ITEM_ALAKAZITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Starminite::
	setitemandprice ITEM_STARMINITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Slowbronite::
	setitemandprice ITEM_SLOWBRONITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Gardevoirite::
	setitemandprice ITEM_GARDEVOIRITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Galladite::
	setitemandprice ITEM_GALLADITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Chandelurite::
	setitemandprice ITEM_CHANDELURITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Lucarionite::
	setitemandprice ITEM_LUCARIONITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_LucarioniteZ::
	setitemandprice ITEM_LUCARIONITE_Z, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Glimmoranite::
	setitemandprice ITEM_GLIMMORANITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_RaichuniteX::
	setitemandprice ITEM_RAICHUNITE_X, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_RaichuniteY::
	setitemandprice ITEM_RAICHUNITE_Y, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Golisopite::
	setitemandprice ITEM_GOLISOPITE, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_MewtwoniteX::
	setitemandprice ITEM_MEWTWONITE_X, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_MewtwoniteY::
	setitemandprice ITEM_MEWTWONITE_Y, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseMegaStone

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "Please choose a prize from this list.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase:
	.string "You've chosen the {STR_VAR_1}.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Here is your prize!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, SMOOCHUM?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_AirBalloonDesc::
	.string "A hold item that protects the user\n"
	.string "from GROUND-TYPE moves until popped.$"

BattleFrontier_ExchangeServiceCorner_Text_ShellBellDesc::
	.string "A hold item that restores a little\n"
	.string "HP when dealing damage.$"

BattleFrontier_ExchangeServiceCorner_Text_AbilityShieldDesc::
	.string "A hold item that prevents abilities\n"
	.string "from being altered or negated.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"

BattleFrontier_ExchangeServiceCorner_Text_ExpertBeltDesc::
	.string "A hold item that boosts damage\n"
	.string "from super-effective moves.$"

BattleFrontier_ExchangeServiceCorner_Text_FlameOrbDesc::
	.string "A hold item that burns the holder.$"

BattleFrontier_ExchangeServiceCorner_Text_ToxicOrbDesc::
	.string "A hold item that poisons the holder.$"

BattleFrontier_ExchangeServiceCorner_Text_WeaknessPolicyDesc::
	.string "A hold item that raises ATTACK and\n"
	.string "SP. ATK when hit by super-effective.$"

BattleFrontier_ExchangeServiceCorner_Text_BlunderPolicyDesc::
	.string "A hold item that raises SPEED\n"
	.string "when missing a move.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusSashDesc::
	.string "A hold item that prevents fainting\n"
	.string "from full HP once.$"

BattleFrontier_ExchangeServiceCorner_Text_ThroatSprayDesc::
	.string "A hold item that raises SP. ATK\n"
	.string "once when using a sound move.$"

BattleFrontier_ExchangeServiceCorner_Text_LightClayDesc::
	.string "A hold item that extends the duration\n"
	.string "of REFLECT and LIGHT SCREEN.$"

BattleFrontier_ExchangeServiceCorner_Text_TerrainExtenderDesc::
	.string "A hold item that extends the duration\n"
	.string "of any TERRAIN move.$"

BattleFrontier_ExchangeServiceCorner_Text_EvioliteDesc::
	.string "A hold item that raises DEFENSE and\n"
	.string "SP. DEF for unevolved POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_HeavyDutyBootsDesc::
	.string "A hold item that protects the user\n"
	.string "from entry hazards.$"

BattleFrontier_ExchangeServiceCorner_Text_LoadedDiceDesc::
	.string "A hold item that causes multihit\n"
	.string "attacks to hit 4 or 5 times.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Raises ATTACK, but permits the use\n"
	.string "of only one move.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceSpecsDesc::
	.string "Raises SP. ATK, but permits the use\n"
	.string "of only one move.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceScarfDesc::
	.string "Raises SPEED, but permits the use\n"
	.string "of only one move.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"

BattleFrontier_ExchangeServiceCorner_Text_LifeOrbDesc::
	.string "A hold item that boosts power in\n"
	.string "exchange for HP.$"

BattleFrontier_ExchangeServiceCorner_Text_ClearAmuletDesc::
	.string "A hold item that protects the user\n"
	.string "from stat drops.$"

BattleFrontier_ExchangeServiceCorner_Text_CovertCloakDesc::
	.string "A hold item that protects the user\n"
	.string "from the secondary effect of moves.$"

BattleFrontier_ExchangeServiceCorner_Text_RockyHelmetDesc::
	.string "A hold item that deals damage to\n"
	.string "the foe if they make contact.$"

BattleFrontier_ExchangeServiceCorner_Text_AssaultVestDesc::
	.string "Raises SP. DEF, but permits the use\n"
	.string "of only attacking moves.$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "A large poster with a SMOOCHUM print.$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "A SMOOCHUM cushion.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "A SMOOCHUM DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "A TOGEPI DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "A MEOWTH DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "A CLEFAIRY DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "A DITTO DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_LotadDollDesc::
	.string "A LOTAD DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_SeedotDollDesc::
	.string "A SEEDOT DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "A CYNDAQUIL DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "A CHIKORITA DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "A TOTODILE DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_LaprasDollDesc::
	.string "A large LAPRAS DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_SnorlaxDollDesc::
	.string "A large SNORLAX DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_VenusaurDollDesc::
	.string "A large VENUSAUR DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_CharizardDollDesc::
	.string "A large CHARIZARD DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_BlastoiseDollDesc::
	.string "A large BLASTOISE DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_RegirockDollDesc::
	.string "A large REGIROCK DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_RegiceDollDesc::
	.string "A large REGICE DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_RegisteelDollDesc::
	.string "A large REGISTEEL DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_EverstoneDesc::
	.string "An item that prevents a POKéMON from\n"
	.string "being able to evolve when held.$"

BattleFrontier_ExchangeServiceCorner_Text_EvoItemDesc::
	.string "An item that allows certain species\n"
	.string "of POKéMON to evolve.$"

BattleFrontier_ExchangeServiceCorner_Text_MegaStoneDesc::
	.string "A hold item that allows certain species\n"
	.string "of POKéMON to MEGA EVOLVE.$"
