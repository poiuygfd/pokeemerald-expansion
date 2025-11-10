Route119_MrMegasStones_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_MrMegasStones_OnTransition
	.byte 0

Route119_MrMegasStones_OnTransition:
	call_if_unset FLAG_MET_MR_MEGA, Route119_MrMegasStones_EventScript_FaceMrMegaAway
	end

Route119_MrMegasStones_EventScript_FaceMrMegaAway::
	setobjectmovementtype LOCALID_ROUTE119_MR_MEGA, MOVEMENT_TYPE_FACE_UP
	return

Route119_MrMegasStones_EventScript_MrMega::
	lock
	faceplayer
	goto_if_set FLAG_MET_MR_MEGA, Route119_MrMegasStones_EventScript_MrMegaShop
	delay 10
	playse SE_PIN
	applymovement LOCALID_ROUTE119_MR_MEGA, Common_Movement_ExclamationMark
	applymovement LOCALID_ROUTE119_MR_MEGA, Common_Movement_WalkInPlaceFasterDown
	waitmovement
	msgbox Route119_MrMegasStones_Text_MrMegaIntroduction, MSGBOX_DEFAULT
	setflag FLAG_MET_MR_MEGA
	release
	end

Route119_MrMegasStones_EventScript_MrMegaShop::
	message Route119_MrMegasStones_Text_BrowseMyWares
	waitmessage
	pokemart Route119_MrMegasStones_Mart_MegaStoneMart
	msgbox Route119_MrMegasStones_Text_ComeBackAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Route119_MrMegasStones_Mart_MegaStoneMart:
	.2byte ITEM_ABSOLITE
	.2byte ITEM_HERACRONITE
	@ .2byte ITEM_SCRAFTINITE
	.2byte ITEM_AMPHAROSITE
	@ .2byte ITEM_BARBARACITE
	.2byte ITEM_LUCARIONITE
	.2byte ITEM_MANECTITE
	@ .2byte ITEM_PYROARITE
	.2byte ITEM_KANGASKHANITE
	@ .2byte ITEM_SKARMORITE
	.2byte ITEM_SLOWBRONITE
	.2byte ITEM_GYARADOSITE
	.2byte ITEM_SCEPTILITE
	.2byte ITEM_BLAZIKENITE
	.2byte ITEM_SWAMPERTITE
	@ .2byte ITEM_CHESNAUGHTITE
	@ .2byte ITEM_DELPHOXITE
	@ .2byte ITEM_GRENINJITE
	.2byte ITEM_SALAMENCITE
	.2byte ITEM_METAGROSSITE
	.2byte ITEM_LATIASITE
	.2byte ITEM_LATIOSITE
	.2byte ITEM_DIANCITE
	.2byte ITEM_NONE
	release
	end

Route119_MrMegasStones_EventScript_BoxesOfStuff::
	msgbox Route119_MrMegasStones_Text_BoxesOfStuff, MSGBOX_SIGN
	end

Route119_MrMegasStones_EventScript_Toolbox::
	msgbox Route119_MrMegasStones_Text_Toolbox, MSGBOX_SIGN
	end

Route119_MrMegasStones_EventScript_VariousBooks::
	msgbox Route119_MrMegasStones_Text_VariousBooks, MSGBOX_SIGN
	end

Route119_MrMegasStones_EventScript_StrangeMachine::
	msgbox Route119_MrMegasStones_Text_StrangeMachine, MSGBOX_SIGN
	end

Route119_MrMegasStones_EventScript_ResearchMachine::
	msgbox Route119_MrMegasStones_Text_ResearchMachine, MSGBOX_SIGN
	end

Route119_MrMegasStones_EventScript_MrMegasNotebook::
	lock
	msgbox Route119_MrMegasStones_Text_MrMegasNotebook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route119_MrMegasStones_EventScript_ChoosePage
	release
	end

Route119_MrMegasStones_EventScript_ChoosePage::
	msgbox Route119_MrMegasStones_Text_WhichPage, MSGBOX_DEFAULT
	release
	end

Route119_MrMegasStones_Text_MrMegaIntroduction:
	.string "Oho?\n"
	.string "Could it be? Could it be?!?\p"
	.string "Are you a customer?!\n"
	.string "A real, genuine, customer?!\p"
	.string "Wait, I can't get my hopes up too high.\n"
	.string "Nothing I have would be of use to one\l"
	.string "who doesn't even have a MEGA RING…\p"
	.string "What's that?!\n"
	.string "You DO have a MEGA RING?!\p"
	.string "Oh, excellent! Truly excellent!\p"
	.string "Ahem!\n"
	.string "Sorry, I'm getting ahead of myself.\p"
	.string "My name, ah…\n"
	.string "You can call me MR. MEGA.\p"
	.string "MEGA EVOLUTION is a phenomenon first\n"
	.string "discovered in the KALOS region that\l"
	.string "allows POKéMON to surpass themselves.\p"
	.string "I'm sure you already knew that, though.\p"
	.string "I conduct research on MEGA EVOLUTION.\n"
	.string "There's still so many unknowns, like\l"
	.string "where MEGA STONES come from, why they\l"
	.string "react with KEY STONES, and so on.\p"
	.string "But along with my research on MEGA\n"
	.string "EVOLUTION, I also sell any excess\l"
	.string "MEGA STONES I have to TRAINERS like\l"
	.string "you who are capable of wielding the\l"
	.string "power of MEGA EVOLUTION.\p"
	.string "After all, the more TRAINERS there are\n"
	.string "using MEGA EVOLUTION, the more we are\l"
	.string "bound to learn about it!\p"
	.string "If you would like to browse my wares\n"
	.string "then let me know.\p"
	.string "As I find more stones, I will have more\n"
	.string "to sell as time goes on, so be sure to\l"
	.string "keep checking in with me every so often!$"

Route119_MrMegasStones_Text_BrowseMyWares:
	.string "Hello there!\n"
	.string "Have a look at what I've got in currently!$"

Route119_MrMegasStones_Text_ComeBackAgain:
	.string "Please come back again some time!$"

Route119_MrMegasStones_Text_BoxesOfStuff:
	.string "This box is full of random parts\n"
	.string "and various MEGA STONES.$"

Route119_MrMegasStones_Text_Toolbox:
	.string "A toolbox with various tools you\n"
	.string "don't recognise.\p"
	.string "Must be science stuff.$"

Route119_MrMegasStones_Text_VariousBooks:
	.string "Various textbooks and research papers\n"
	.string "books line the shelves.\p"
	.string "Many of them have been imported from\n"
	.string "the KALOS region.$"

Route119_MrMegasStones_Text_StrangeMachine:
	.string "You have no idea what this machine does.\n"
	.string "Better not touch it!$"

Route119_MrMegasStones_Text_ResearchMachine:
	.string "This machine appears to be used with\n"
	.string "MEGA STONES for some unknown purpose.\p"
	.string "You can see an assortment of various\n"
	.string "different STONES lined up inside.$"

Route119_MrMegasStones_Text_MrMegasNotebook:
	.string "A notebook written by MR. MEGA.\n"
	.string "It seems to document his findings\p"
	.string "Read further?$"

Route119_MrMegasStones_Text_WhichPage:
	.string "nope.$"
