LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_CharizardFan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARIZARDITE_Z, LilycoveCity_CoveLilyMotel_2F_EventScript_NeedToTrain
	goto_if_set FLAG_DEFEATED_CHARIZARD_FAN, LilycoveCity_CoveLilyMotel_2F_EventScript_RecieveMegaStone
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_TheNo1CharizardFan, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_CoveLilyMotel_2F_EventScript_CharizardFanSaidYes
	call_if_eq VAR_RESULT, NO, LilycoveCity_CoveLilyMotel_2F_EventScript_CharizardFanSaidNo
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_CharizardFanSaidYes::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_KnewYoudAgree, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_CharizardFanSaidNo::
	goto_if_unset FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_2F_EventScript_CharizardFanSaidNoPreLeague
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_Preposterous, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CHARIZARD_FAN_X_MEGA, LilycoveCity_CoveLilyMotel_2F_Text_CharizardFanDefeated1
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MoreWhereThatCameFrom, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CHARIZARD_FAN_Y_MEGA, LilycoveCity_CoveLilyMotel_2F_Text_CharizardFanDefeated2
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_UtterDisbelief, MSGBOX_DEFAULT
	applymovement LOCALID_COVE_LILY_GAME_DESIGNER, LilycoveCity_CoveLilyMotel_2F_Movement_ShockRight
	applymovement LOCALID_COVE_LILY_GRAPHICS_ARTIST, LilycoveCity_CoveLilyMotel_2F_Movement_ShockRight
	applymovement LOCALID_COVE_LILY_WOMAN, LilycoveCity_CoveLilyMotel_2F_Movement_ShockRight
	applymovement LOCALID_COVE_LILY_GAMEBOY_KID, LilycoveCity_CoveLilyMotel_2F_Movement_ShockDown
	applymovement LOCALID_COVE_LILY_PROGRAMMER, LilycoveCity_CoveLilyMotel_2F_Movement_ShockDown
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_CoveLilyMotel_2F_PlayerShockUp
	call_if_eq VAR_FACING, DIR_SOUTH, LilycoveCity_CoveLilyMotel_2F_PlayerShockDown
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_CoveLilyMotel_2F_PlayerShockRight
	playse SE_PIN
	delay 10
	applymovement LOCALID_COVE_LILY_CHARIZARD_FAN, LilycoveCity_CoveLilyMotel_2F_Movement_CharizardFanGamerRage
	playse SE_LEDGE
	delay 20
	playse SE_LEDGE
	waitmovement
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GamerRage, MSGBOX_DEFAULT
	faceplayer
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_YouLeaveMeNoChoice, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CHARIZARD_FAN_Z_MEGA, LilycoveCity_CoveLilyMotel_2F_Text_CharizardFanDefeated3
	setflag FLAG_DEFEATED_CHARIZARD_FAN
	applymovement LOCALID_COVE_LILY_GAME_DESIGNER, Common_Movement_FaceLeft
	applymovement LOCALID_COVE_LILY_WOMAN, Common_Movement_FaceLeft
	applymovement LOCALID_COVE_LILY_PROGRAMMER, Common_Movement_FaceLeft
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AreYouATrueCharizardFan, MSGBOX_DEFAULT
	giveitem ITEM_CHARIZARDITE_Z
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARIZARDITE_Z
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_CharizardFanSaidNoPreLeague::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_Preposterous, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CHARIZARD_FAN_X_MEGA_EARLY, LilycoveCity_CoveLilyMotel_2F_Text_CharizardFanDefeated1
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MoreWhereThatCameFrom, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CHARIZARD_FAN_Y_MEGA_EARLY, LilycoveCity_CoveLilyMotel_2F_Text_CharizardFanDefeated2
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_UtterDisbelief, MSGBOX_DEFAULT
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_CoveLilyMotel_2F_PlayerShockUp
	call_if_eq VAR_FACING, DIR_SOUTH, LilycoveCity_CoveLilyMotel_2F_PlayerShockDown
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_CoveLilyMotel_2F_PlayerShockRight
	playse SE_PIN
	delay 10
	applymovement LOCALID_COVE_LILY_CHARIZARD_FAN, LilycoveCity_CoveLilyMotel_2F_Movement_CharizardFanGamerRage
	playse SE_LEDGE
	delay 20
	playse SE_LEDGE
	waitmovement
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GamerRage, MSGBOX_DEFAULT
	faceplayer
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_YouLeaveMeNoChoice, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CHARIZARD_FAN_Z_MEGA_EARLY, LilycoveCity_CoveLilyMotel_2F_Text_CharizardFanDefeated3
	setflag FLAG_DEFEATED_CHARIZARD_FAN
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AreYouATrueCharizardFan, MSGBOX_DEFAULT
	giveitem ITEM_CHARIZARDITE_Z
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARIZARDITE_Z
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_RecieveMegaStone::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AreYouATrueCharizardFanShort, MSGBOX_DEFAULT
	giveitem ITEM_CHARIZARDITE_Z
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARIZARDITE_Z
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_NeedToTrain::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_WeNeedToTrain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Movement_CharizardFanGamerRage::
	jump_in_place_down
	jump_in_place_down
	step_end

LilycoveCity_CoveLilyMotel_2F_Movement_ShockRight::
	emote_exclamation_mark
	face_right
	step_end

LilycoveCity_CoveLilyMotel_2F_Movement_ShockDown::
	emote_exclamation_mark
	face_down
	step_end

LilycoveCity_CoveLilyMotel_2F_Movement_ShockUp::
	emote_exclamation_mark
	face_down
	step_end

LilycoveCity_CoveLilyMotel_2F_PlayerShockUp::
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_2F_Movement_ShockUp
	applymovement OBJ_EVENT_ID_FOLLOWER, LilycoveCity_CoveLilyMotel_2F_Movement_ShockUp
	return

LilycoveCity_CoveLilyMotel_2F_PlayerShockDown::
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_2F_Movement_ShockDown
	applymovement OBJ_EVENT_ID_FOLLOWER, LilycoveCity_CoveLilyMotel_2F_Movement_ShockDown
	return

LilycoveCity_CoveLilyMotel_2F_PlayerShockRight::
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_2F_Movement_ShockRight
	applymovement OBJ_EVENT_ID_FOLLOWER, LilycoveCity_CoveLilyMotel_2F_Movement_ShockRight
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "I'm the GAME DESIGNER.\p"
	.string "Oh, is that right?\n"
	.string "You're working on a POKéDEX?\p"
	.string "It's tough trying to complete it,\n"
	.string "but don't give up.\p"
	.string "If you do complete it, please come\n"
	.string "show me.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wow! That's awesome!\n"
	.string "Yep, it's totally awesome!\p"
	.string "This POKéDEX is completely filled!\n"
	.string "You really must love POKéMON!\p"
	.string "I'm so impressed!\p"
	.string "Let me give you something in\n"
	.string "recognition of your feat!$"

LilycoveCity_CoveLilyMotel_2F_Text_TheNo1CharizardFan:
	.string "I'm the number one CHARIZARD fan!\p"
	.string "Don't you just love CHARIZARD?\n"
	.string "Everyone loves CHARIZARD!\p"
	.string "That's why we gave CHARIZARD two MEGA\n"
	.string "EVOLUTIONS instead of one!\p"
	.string "Don't you agree?$"

LilycoveCity_CoveLilyMotel_2F_Text_KnewYoudAgree:
	.string "I knew you'd agree!\p"
	.string "You seem like someone who knows what\n"
	.string "is what!\p"
	.string "Still, you'll never be as big a CHARIZARD\n"
	.string "fan as me! Maybe I'll let you have\l"
	.string "second place though! Hohoho!$"

LilycoveCity_CoveLilyMotel_2F_Text_Preposterous:
	.string "What? It's unfair that CHARIZARD gets\n"
	.string "two MEGAS when VENUSAUR and BLASTOISE\l"
	.string "only get one each?\p"
	.string "That's preposterous!\n"
	.string "Why, you! I ought to teach you a lesson!$"

LilycoveCity_CoveLilyMotel_2F_Text_MoreWhereThatCameFrom:
	.string "N-no way!\p"
	.string "How did you beat the might of my\n"
	.string "unstoppable CHARIZARD…?\p"
	.string "…Tch, it doesn't matter!\n"
	.string "Didn't I just tell you CHARIZARD has\l"
	.string "two MEGA EVOLUTIONS?\p"
	.string "Now that you've been tired out and\n"
	.string "whittled down by my first CHARIZARD…\p"
	.string "Face the wrath of my SECOND CHARIZARD!!$"

LilycoveCity_CoveLilyMotel_2F_Text_UtterDisbelief:
	.string "That… That wasn't enough?\n"
	.string "But… How?\p"
	.string "I threw everything I had at you!\n"
	.string "And yet you're still standing?$"

LilycoveCity_CoveLilyMotel_2F_Text_GamerRage:
	.string "No… NO!!\n"
	.string "I can't let it end like this!!$"

LilycoveCity_CoveLilyMotel_2F_Text_YouLeaveMeNoChoice:
	.string "You leave me no choice.\p"
	.string "Nobody was supposed to know about this.\n"
	.string "Nobody but me…\p"
	.string "But I just can't let it end like this!\n"
	.string "I hope you've said your prayers!\p"
	.string "Because you're about to see something\n"
	.string "so terrifying, so powerful…\p"
	.string "That you'll never be able to look at\n"
	.string "CHARIZARD the same again!\p"
	.string "Have at thee!$"

LilycoveCity_CoveLilyMotel_2F_Text_CharizardFanDefeated1:
	.string "Impossible!\n"
	.string "How did you best my CHARIZARD's might?$"

LilycoveCity_CoveLilyMotel_2F_Text_CharizardFanDefeated2:
	.string "Incomprehensible!\n"
	.string "How do you keep getting away with this?$"

LilycoveCity_CoveLilyMotel_2F_Text_CharizardFanDefeated3:
	.string "Words cannot describe my bewilderment!\n"
	.string "I threw everything I had, and failed…$"

LilycoveCity_CoveLilyMotel_2F_Text_AreYouATrueCharizardFan:
	.string "I can't believe it!\n"
	.string "The X MEGA didn't work, nor the Y MEGA…\p"
	.string "And even after showing the forbidden\n"
	.string "Z MEGA, I still couldn't win…\p"
	.string "Could it be…\p"
	.string "That you are a true CHARIZARD fan\n"
	.string "after all?\p"
	.string "To know CHARIZARD's weak points\n"
	.string "so thoroughly in order to best me…\p"
	.string "You must know CHARIZARD in and out!\n"
	.string "There's no other explanation!\l"
	.string "You're a fan!\p"
	.string "Here, I think that CHARIZARD's true\n"
	.string "potential has been hidden from the\l"
	.string "world long enough.\p"
	.string "Take this MEGA STONE, and harness the\n"
	.string "power of MEGA CHARIZARD Z yourself!$"

LilycoveCity_CoveLilyMotel_2F_Text_AreYouATrueCharizardFanShort:
	.string "Here, I think that CHARIZARD's true\n"
	.string "potential has been hidden from the\l"
	.string "world long enough.\p"
	.string "Take this MEGA STONE, and harness the\n"
	.string "power of the forbidden MEGA CHARIZARD Z\l"
	.string "for yourself!$"

LilycoveCity_CoveLilyMotel_2F_Text_WeNeedToTrain:
	.string "Me and my CHARIZARDS are going to need\n"
	.string "to do a lot of training.\p"
	.string "We're going to become so strong, we'll\n"
	.string "never lose to anyone ever again!\p"
	.string "When that happens, I demand a rematch!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Me? You're talking to me?\n"
	.string "I'm the PROGRAMMER.\p"
	.string "I wonder what the SLOTS are\n"
	.string "like here.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
	.string "POKéMON of HOENN interesting?$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "The sea breeze tickles my heart.\n"
	.string "It feels wonderful here!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "You never know when and where\n"
	.string "people will challenge you.\p"
	.string "That's why I never leave home without\n"
	.string "my GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Huh?!\n"
	.string "Oh, sorry, sorry! I was snoozing!\p"
	.string "I decided to check out that POKéMON\n"
	.string "CONTEST thing.\p"
	.string "I have to admit, it does look quite\n"
	.string "entertaining, but…\p"
	.string "Consider me a purist--I still prefer\n"
	.string "battles and tough TRAINERS.\p"
	.string "But that's just me.\p"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
	.string "like the GYMS, CONTESTS, BATTLE TENTS,\l"
	.string "and so on, the whole works!\p"
	.string "And be sure to check out THE DEPTHS and\n"
	.string "the TRAINER HILL with that BATTLE PASS!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: I think it does take strategy\n"
	.string "to win a CONTEST.\p"
	.string "Devising CONTEST strategies is one way\n"
	.string "of becoming a better TRAINER, I'd say.$"

