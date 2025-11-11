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
	pokemartlistend

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
	message Route119_MrMegasStones_Text_WhichPage
	waitmessage
	multichoice 0, 0, MULTI_NOTEBOOK_PAGES, FALSE
	switch VAR_RESULT
	case 0, Route119_MrMegasStones_EventScript_Entry1
	case 1, Route119_MrMegasStones_EventScript_Entry2
	case 2, Route119_MrMegasStones_EventScript_Entry3
	case 3, Route119_MrMegasStones_EventScript_Entry4
	release
	end

Route119_MrMegasStones_EventScript_Entry1::
	msgbox Route119_MrMegasStones_Text_Entry1, MSGBOX_DEFAULT
	goto Route119_MrMegasStones_EventScript_ChoosePage
	end

Route119_MrMegasStones_EventScript_Entry2::
	msgbox Route119_MrMegasStones_Text_Entry2, MSGBOX_DEFAULT
	goto Route119_MrMegasStones_EventScript_ChoosePage
	end

Route119_MrMegasStones_EventScript_Entry3::
	msgbox Route119_MrMegasStones_Text_Entry3, MSGBOX_DEFAULT
	goto Route119_MrMegasStones_EventScript_ChoosePage
	end

Route119_MrMegasStones_EventScript_Entry4::
	msgbox Route119_MrMegasStones_Text_Entry4, MSGBOX_DEFAULT
	goto Route119_MrMegasStones_EventScript_ChoosePage
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
	.string "It seems to document his findings.\p"
	.string "Read further?$"

Route119_MrMegasStones_Text_WhichPage:
	.string "Which entry would you like to read?$"

Route119_MrMegasStones_Text_Entry1:
	.string "It all happened not long after I\n"
	.string "first moved to the HOENN region.\p"
	.string "I went to watch a promotional battle\n"
	.string "between the CHAMPION of HOENN and\l"
	.string "the CHAMPION of KALOS.\p"
	.string "I'd just went with a friend out of\n"
	.string "obligation at first.\p"
	.string "But that match was my first time ever\n"
	.string "witnessing MEGA EVOLUTION.\p"
	.string "It entranced me, and my mind was full\n"
	.string "of questions.\p"
	.string "What is the relationship between the\n"
	.string "KEY STONE and MEGA STONE?\p"
	.string "Why do these stones resonate with\n"
	.string "some POKéMON but not others?\p"
	.string "And is a strong bond really required\n"
	.string "to achieve MEGA EVOLUTION?\p"
	.string "I will be using this notebook to\n"
	.string "document all my findings.$"

Route119_MrMegasStones_Text_Entry2:
	.string "The first thing I wanted to know was\n"
	.string "about the origins of MEGA EVOLUTION.\p"
	.string "In the SINNOH region that I called\n"
	.string "once called home, there was simply\l"
	.string "no such concept as MEGA EVOLUTION.\p"
	.string "My findings led me to believe that\n"
	.string "KALOS and HOENN are the regions that\l"
	.string "have the strongest ties to MEGA\l"
	.string "EVOLUTION.\p"
	.string "However, further digging also shows that\n"
	.string "the phenomenon has also been observed\l"
	.string "in the KANTO and ALOLA regions before.\p"
	.string "What is it about the HOENN and KALOS\n"
	.string "regions that allowed for this to occur?\p"
	.string "My research into this topic will continue\n"
	.string "later, but for now I wish to know more\l"
	.string "about the process itself.$"

Route119_MrMegasStones_Text_Entry3:
	.string "The thing that I have stumbled across\n"
	.string "the most during my research is that to\l"
	.string "achieve MEGA EVOLUTION, three things\l"
	.string "are absolutely required.\p"
	.string "A KEY STONE, for the TRAINER.\p"
	.string "A MEGA STONE, for the POKéMON.\p"
	.string "And a strong bond between TRAINER\n"
	.string "and POKéMON.\p"
	.string "With these three things, MEGA EVOLUTION\n"
	.string "is made possible.\p"
	.string "My current hypothesis is that the main\n"
	.string "culprit, however, for the phenomenon of\l"
	.string "MEGA EVOLUTION lies within MEGA STONES.\p"
	.string "Cases are very scant, and I had to do a\n"
	.string "lot of digging to find them, but cases\l"
	.string "of POKéMON MEGA EVOLVING on their own\l"
	.string "without a bond or KEY STONE exist.\p"
	.string "However, these instances seem to be\n"
	.string "caused by an external force, and the\l"
	.string "POKéMON are noted as being in pain.\p"
	.string "This leads me to believe that MEGA\n"
	.string "EVOLUTION is a painful process for\l"
	.string "the POKéMON, and that the existence\l"
	.string "of the KEY STONE and a strong bond\l"
	.string "makes the process less stressful on\l"
	.string "the POKéMON's bodies.\p"
	.string "This hypothesis has yet to be confirmed\n"
	.string "of course, but it is what makes the\l"
	.string "most sense to me currently.$"

Route119_MrMegasStones_Text_Entry4:
	.string "One aspect that I find strange about\n"
	.string "MEGA EVOLUTION is the existence of\l"
	.string "POKéMON that possess multiple.\p"
	.string "It was to my understanding that the\n"
	.string "power of MEGA EVOLUTION could draw\l"
	.string "out the true latent powers of a\l"
	.string "POKéMON, allowing them access to\l"
	.string "their true strength temporarily.\p"
	.string "And yet, it appears that the POKéMON\n"
	.string "CHARIZARD and RAICHU possess multiple\l"
	.string "kinds of MEGA EVOLUTION.\p"
	.string "It is also rumoured that the LEGENDARY\n"
	.string "POKéMON MEWTWO also has two MEGAS.\p"
	.string "If this process draws out a POKéMON's\n"
	.string "true form, then how can a POKéMON\l"
	.string "possess multiple?\p"
	.string "It feels like the more I dive into\n"
	.string "my research, the more questions I find.\p"
	.string "That being said, this topic intrigues\n"
	.string "me to no end.\p"
	.string "I will eventually answer every question\n"
	.string "I have about MEGA EVOLUTION!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "All the pages after this one are blank.\n"
	.string "It appears this is all MR. MEGA has\l"
	.string "written for now.$"
