FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE08_GET, FortreeCity_Mart_EventScript_PokemartBadge8
	goto_if_set FLAG_BADGE07_GET, FortreeCity_Mart_EventScript_PokemartBadge7
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Mart_EventScript_PokemartBadge6
	goto FortreeCity_Mart_EventScript_PokemartBadge5
	end

FortreeCity_Mart_EventScript_PokemartBadge5::
	pokemart FortreeCity_Mart_Pokemart_Badge5
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

FortreeCity_Mart_EventScript_PokemartBadge6::
	pokemart FortreeCity_Mart_Pokemart_Badge6
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

FortreeCity_Mart_EventScript_PokemartBadge7::
	pokemart FortreeCity_Mart_Pokemart_Badge7
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

FortreeCity_Mart_EventScript_PokemartBadge8::
	pokemart FortreeCity_Mart_Pokemart_Badge8
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart_Badge5:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE
	release
	end

	.align 2
FortreeCity_Mart_Pokemart_Badge6:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_MAX_LURE
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE
	release
	end

	.align 2
FortreeCity_Mart_Pokemart_Badge7:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_MAX_LURE
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE
	release
	end

	.align 2
FortreeCity_Mart_Pokemart_Badge8:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_MAX_ELIXIR
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_MAX_LURE
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_WOOD_MAIL
	pokemartlistend

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "SUPER REPEL lasts a long time,\n"
	.string "and it gets the job done.\p"
	.string "It's much better than an ordinary\n"
	.string "REPEL.$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "I always stock up on more items than\n"
	.string "I'm sure I'll need.\p"
	.string "You never know what might happen.\n"
	.string "Better to be safe than sorry!$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "A RARE CANDY makes a POKéMON grow\n"
	.string "immediately by one level.$"

