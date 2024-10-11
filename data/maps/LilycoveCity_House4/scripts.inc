LilycoveCity_House4_MapScripts::
	.byte 0

LilycoveCity_House4_EventScript_Man1::
	msgbox LilycoveCity_House4_Text_MysteriesAtBottomOfSea, MSGBOX_NPC
	end

LilycoveCity_House4_EventScript_Man2::
	msgbox LilycoveCity_House4_Text_UnderwaterTrenchMossdeepSootopolis, MSGBOX_NPC
	end

LilycoveCity_House4_EventScript_GameboyKid::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LINKING_CORD, LilycoveCity_House4_EventScript_ReceivedLinkingCord
	msgbox LilycoveCity_House4_Text_LinkingToTheOcean, MSGBOX_DEFAULT
	giveitem ITEM_LINKING_CORD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_LINKING_CORD
	release
	end

LilycoveCity_House4_EventScript_ReceivedLinkingCord::
	msgbox LilycoveCity_House4_Text_IWantToSeeTheDeep, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House4_Text_LinkingToTheOcean:
	.string "I wonder just how deep the ocean is…\p"
	.string "I wonder, could I LINK CABLE with\n"
	.string "someone at the bottom of the ocean?\p"
	.string "Haha, probably not.\p"
	.string "If you want to give it a try though\n"
	.string "then don't let me stop you.$"

LilycoveCity_House4_Text_IWantToSeeTheDeep:
	.string "Someday it might be fun to see\n"
	.string "what it's like deep down in the sea.\p"
	.string "Imagine playing games at the botoom\n"
	.string "of an ocean trench!$"

LilycoveCity_House4_Text_MysteriesAtBottomOfSea:
	.string "This planet's biggest mysteries are\n"
	.string "at the bottom of the sea.\p"
	.string "Somebody said that, but I don't know…$"

LilycoveCity_House4_Text_UnderwaterTrenchMossdeepSootopolis:
	.string "There's a deep underwater trench\n"
	.string "between MOSSDEEP and SOOTOPOLIS.\p"
	.string "That's what someone told me, anyway.$"

