.set LOCALID_LEAF, 2

ArtisanCave_1F_MapScripts::
	.byte 0

ArtisanCave_1F_EventScript_Leaf::
	lock
	goto_if_set FLAG_DEFEATED_ARTISAN_CAVE_LEAF, ArtisanCave_1F_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_LEAF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LEAF, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LEAF, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ArtisanCave_1F_Text_NiceToMeetYouLetsBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEAF_ARTISAN_CAVE, ArtisanCave_1F_Text_LeafDefeat
	msgbox ArtisanCave_1F_Text_ComeVisitMeLater, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_ARTISAN_CAVE_LEAF
	clearflag FLAG_HIDE_LEAF
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LEAF
	fadescreen FADE_FROM_BLACK
	delay 10
	release
	end

ArtisanCave_1F_EventScript_Defeated::
	applymovement LOCALID_LEAF, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ArtisanCave_1F_Text_ComeVisitMeLater, MSGBOX_DEFAULT
	release
	end

ArtisanCave_1F_Text_NiceToMeetYouLetsBattle:
	.string "Oh! Didn't see you there!\p"
	.string "The name's LEAF! Nice to meetcha!\p"
	.string "Say, do you like POKéMON battles?\n"
	.string "Heh, guess that's a stupid question if\l"
	.string "you've made it to this place.\p"
	.string "In fact, you've gotta be pretty strong\n"
	.string "to be here right now, right?\p"
	.string "That settles it! We're having a battle!\n"
	.string "Right here, right now! Here I come!$"

ArtisanCave_1F_Text_LeafDefeat:
	.string "Yeowzers! You're real strong, huh?$"

ArtisanCave_1F_Text_ComeVisitMeLater:
	.string "Man, I don't think I've been smoked that\n"
	.string "hard since I battled RED!\p"
	.string "Come to think of it, where'd he even go?\p"
	.string "We came to the BATTLE FRONTIER to see\n"
	.string "what it was all about, but I haven't\l"
	.string "seen him since we got here…\p"
	.string "Ah, well, I'm sure he'll show his face\n"
	.string "soon enough! He's probably in some cave\l"
	.string "or on some mountain or some other really\l"
	.string "secluded place brooding or something…\p"
	.string "You should swing by the place we're\n"
	.string "staying at later!\p"
	.string "I'm sure you'll find it if you run around\n"
	.string "the BATTLE FRONTIER a bunch.\p"
	.string "I'll trade you a gift if you come see me!\p"
	.string "Anyways, I'd best be off.\p"
	.string "I'll see you around… Uh, what was your\n"
	.string "name?\p"
	.string "{PLAYER}, huh? I'll see you around,\n"
	.string "{PLAYER}!$"

