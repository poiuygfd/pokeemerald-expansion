VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE08_GET, VerdanturfTown_Mart_EventScript_PokemartBadge8
	goto_if_set FLAG_BADGE07_GET, VerdanturfTown_Mart_EventScript_PokemartBadge7
	goto_if_set FLAG_BADGE06_GET, VerdanturfTown_Mart_EventScript_PokemartBadge6
	goto_if_set FLAG_BADGE05_GET, VerdanturfTown_Mart_EventScript_PokemartBadge5
	goto_if_set FLAG_BADGE04_GET, VerdanturfTown_Mart_EventScript_PokemartBadge4
	goto_if_set FLAG_BADGE03_GET, VerdanturfTown_Mart_EventScript_PokemartBadge3
	goto VerdanturfTown_Mart_EventScript_PokemartBadge2
	end

VerdanturfTown_Mart_EventScript_PokemartBadge2::
	pokemart VerdanturfTown_Mart_Pokemart_Badge2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_Mart_EventScript_PokemartBadge3::
	pokemart VerdanturfTown_Mart_Pokemart_Badge3
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_Mart_EventScript_PokemartBadge4::
	pokemart VerdanturfTown_Mart_Pokemart_Badge4
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_Mart_EventScript_PokemartBadge5::
	pokemart VerdanturfTown_Mart_Pokemart_Badge5
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_Mart_EventScript_PokemartBadge6::
	pokemart VerdanturfTown_Mart_Pokemart_Badge6
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_Mart_EventScript_PokemartBadge7::
	pokemart VerdanturfTown_Mart_Pokemart_Badge7
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_Mart_EventScript_PokemartBadge8::
	pokemart VerdanturfTown_Mart_Pokemart_Badge8
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart_Badge2:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart_Badge3:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart_Badge4:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
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
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart_Badge5:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NEST_BALL
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
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart_Badge6:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NEST_BALL
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
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart_Badge7:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NEST_BALL
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
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart_Badge8:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NEST_BALL
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
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE
	release
	end

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "For any POKéMON match, X SPECIAL\n"
	.string "is crucial.\p"
	.string "It jacks up the power of some moves\n"
	.string "even though it's only for one battle.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "They don't seem to sell any winning\n"
	.string "strategy guides for the BATTLE TENT…\p"
	.string "It seems one must rely on one's\n"
	.string "own wits after all…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "The NEST BALL works better on\n"
	.string "weakened POKéMON.\p"
	.string "VERDANTURF is the only place you can\n"
	.string "buy it.$"

