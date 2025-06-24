TuffnookTown_GavinsGems_MapScripts::
	.byte 0

TuffnookTown_GavinsGems_EventScript_Gavin::
	lock
	faceplayer
	goto_if_set FLAG_MET_GAVIN, TuffnookTown_GavinsGems_EventScript_GavinRepeat
	playse SE_PIN
	applymovement LOCALID_TUFFNOOK_GAVIN, Common_Movement_ExclamationMark
	waitmovement 0
	message TuffnookTown_GavinsGems_Text_OhWowACustomer
	waitmessage
	goto_if_set FLAG_IS_CHAMPION, TuffnookTown_GavinsGems_EventScript_PostGameShop
	pokemart TuffnookTown_GavinsGems_Pokemart_TypeGems
	msgbox TuffnookTown_GavinsGems_Text_HaveAGoodOneKid, MSGBOX_DEFAULT
	setflag FLAG_MET_GAVIN
	release
	end

TuffnookTown_GavinsGems_EventScript_GavinRepeat::
	lock
	faceplayer
	message TuffnookTown_GavinsGems_Text_WelcomeBackKid
	waitmessage
	goto_if_set FLAG_IS_CHAMPION, TuffnookTown_GavinsGems_EventScript_PostGameShop
	pokemart TuffnookTown_GavinsGems_Pokemart_TypeGems
	msgbox TuffnookTown_GavinsGems_Text_HaveAGoodOneKid, MSGBOX_DEFAULT
	release
	end

TuffnookTown_GavinsGems_EventScript_PostGameShop::
	pokemart TuffnookTown_GavinsGems_Pokemart_TypeGemsPostGame
	msgbox TuffnookTown_GavinsGems_Text_HaveAGoodOneKid, MSGBOX_DEFAULT
	release
	end

	.align 2
TuffnookTown_GavinsGems_Pokemart_TypeGems:
	.2byte ITEM_NORMAL_GEM
	.2byte ITEM_GRASS_GEM
	.2byte ITEM_FIRE_GEM
	.2byte ITEM_WATER_GEM
	.2byte ITEM_ELECTRIC_GEM
	.2byte ITEM_FLYING_GEM
	.2byte ITEM_BUG_GEM
	.2byte ITEM_FIGHTING_GEM
	.2byte ITEM_PSYCHIC_GEM
	.2byte ITEM_POISON_GEM
	.2byte ITEM_ROCK_GEM
	.2byte ITEM_GROUND_GEM
	.2byte ITEM_GHOST_GEM
	.2byte ITEM_ICE_GEM
	.2byte ITEM_DRAGON_GEM
	.2byte ITEM_DARK_GEM
	.2byte ITEM_STEEL_GEM
	.2byte ITEM_FAIRY_GEM
	pokemartlistend

	.align 2
TuffnookTown_GavinsGems_Pokemart_TypeGemsPostGame:
	.2byte ITEM_DAMP_ROCK
	.2byte ITEM_HEAT_ROCK
	.2byte ITEM_SMOOTH_ROCK
	.2byte ITEM_ICY_ROCK
	.2byte ITEM_NORMAL_GEM
	.2byte ITEM_GRASS_GEM
	.2byte ITEM_FIRE_GEM
	.2byte ITEM_WATER_GEM
	.2byte ITEM_ELECTRIC_GEM
	.2byte ITEM_FLYING_GEM
	.2byte ITEM_BUG_GEM
	.2byte ITEM_FIGHTING_GEM
	.2byte ITEM_PSYCHIC_GEM
	.2byte ITEM_POISON_GEM
	.2byte ITEM_ROCK_GEM
	.2byte ITEM_GROUND_GEM
	.2byte ITEM_GHOST_GEM
	.2byte ITEM_ICE_GEM
	.2byte ITEM_DRAGON_GEM
	.2byte ITEM_DARK_GEM
	.2byte ITEM_STEEL_GEM
	.2byte ITEM_FAIRY_GEM
	pokemartlistend

TuffnookTown_GavinsGems_Text_OhWowACustomer:
	.string "Bloomin' heck!\p"
	.string "Is that a customer?\n"
	.string "A real, genuine, customer?\p"
	.string "It's been a while since I've seen anyone\n"
	.string "not from round these parts!\p"
	.string "Welcome to GAVIN'S GEMS, kid!\n"
	.string "I've got a wide selection of gemstones\l"
	.string "mined from round these parts for sale.\p"
	.string "I mostly sell 'em cause I think they look\n"
	.string "real nice, but I've heard they can be\l"
	.string "used in battle to boost the power of\l"
	.string "a POKéMON's moves, too.\p"
	.string "So, what can I do ya for?$"

TuffnookTown_GavinsGems_Text_HaveAGoodOneKid:
	.string "Have a good one, kid!$"

TuffnookTown_GavinsGems_Text_WelcomeBackKid:
	.string "Good to see you again, kid!\n"
	.string "Have a look at what I've got!$"
