AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventTrigger
	end

AquaHideout_B2F_EventScript_PreventTrigger::
	setobjectxyperm LOCALID_AQUA_HIDEOUT_SHELLY, 23, 19
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_ArchieTrigger0::
	lockall
	applymovement LOCALID_PLAYER, AquaHideout_B2F_Movement_PlayerApproach0
	waitmovement 0
	goto AquaHideout_B2F_EventScript_WallyMultiBattle
	end

AquaHideout_B2F_EventScript_ArchieTrigger1::
	lockall
	applymovement LOCALID_PLAYER, AquaHideout_B2F_Movement_PlayerApproach1
	waitmovement 0
	goto AquaHideout_B2F_EventScript_WallyMultiBattle
	end

AquaHideout_B2F_EventScript_WallyMultiBattle::
	applymovement LOCALID_AQUA_HIDEOUT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox AquaHideout_B2F_Text_ArchieSoYouChasedUsEvenHere, MSGBOX_DEFAULT
	applymovement LOCALID_AQUA_HIDEOUT_SHELLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox AquaHideout_B2F_Text_ShellyBratFromBackThen, MSGBOX_DEFAULT
	applymovement LOCALID_AQUA_HIDEOUT_WALLY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox AquaHideout_B2F_Text_WallyImNotTheSamePerson, MSGBOX_DEFAULT
	closemessage
	goto AquaHideout_B2F_EventScript_ChoosePartyForMultiBattle
	end

AquaHideout_B2F_EventScript_YouCantEscapeThisBattle::
	applymovement LOCALID_AQUA_HIDEOUT_WALLY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox AquaHideout_B2F_Text_WallyLoop, MSGBOX_DEFAULT
	closemessage
	goto AquaHideout_B2F_EventScript_ChoosePartyForMultiBattle
	end

AquaHideout_B2F_EventScript_ChoosePartyForMultiBattle::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, AquaHideout_B2F_EventScript_DoWallyMultiBattle
	special LoadPlayerParty
	goto AquaHideout_B2F_EventScript_YouCantEscapeThisBattle

AquaHideout_B2F_EventScript_DoWallyMultiBattle::
	multi_2_vs_2 TRAINER_ARCHIE_AQUA_HIDEOUT, AquaHideout_B2F_Text_ArchieDefeat, TRAINER_SHELLY_AQUA_HIDEOUT, AquaHideout_B2F_Text_ShellyDefeat, PARTNER_WALLY_AQUA_HIDEOUT
	switch VAR_RESULT
	case 1, AquaHideout_B2F_EventScript_SubmarineEscape
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

AquaHideout_B2F_EventScript_SubmarineEscape::
	applymovement LOCALID_AQUA_HIDEOUT_MATT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattBossLetsGo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_HIDEOUT_MATT, AquaHideout_B2F_Movement_MattJumpInSub
	waitmovement 0
	applymovement LOCALID_AQUA_HIDEOUT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox AquaHideout_B2F_Text_ArchieTooLateNow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_HIDEOUT_ARCHIE, AquaHideout_B2F_Movement_ArchieJumpInSub
	waitmovement 0
	applymovement LOCALID_AQUA_HIDEOUT_SHELLY, AquaHideout_B2F_Movement_ShellyBlocksTheWay
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_AQUA_HIDEOUT_WALLY, Common_Movement_WalkLeft
	waitmovement 0
	msgbox AquaHideout_B2F_Text_ShellyWhereDoYouThinkYoureGoing, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_AQUA_HIDEOUT_SHELLY, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_AQUA_HIDEOUT_SUBMARINE, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	delay 20
	applymovement LOCALID_AQUA_HIDEOUT_SHELLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_ShellySearchTheOcean, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_AQUA_HIDEOUT_WALLY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox AquaHideout_B2F_Text_WallyHappyOrMad, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_HIDEOUT_WALLY, AquaHideout_B2F_Movement_WallyWalkToWarp
	waitmovement 0
	playse SE_WARP_IN
	applymovement LOCALID_AQUA_HIDEOUT_WALLY, AquaHideout_B2F_Movement_WallySpin
	waitmovement 0
	applymovement LOCALID_AQUA_HIDEOUT_WALLY, AquaHideout_B2F_Movement_WallyWarp
	waitmovement 0
	waitse
	removeobject LOCALID_AQUA_HIDEOUT_WALLY
	setvar VAR_TEMP_1, 1
	removeobject LOCALID_AQUA_HIDEOUT_SUBMARINE
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	setflag FLAG_HIDE_AQUA_HIDEOUT_ARCHIE_MATT
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_B2F_EventScript_HideWailmerGrunt
	releaseall
	end

AquaHideout_B2F_EventScript_HideWailmerGrunt::
	setflag FLAG_HIDE_LILYCOVE_WAILMER_GRUNT
	releaseall
	end

AquaHideout_B2F_EventScript_Shelly::
	msgbox AquaHideout_B2F_Text_ShellySearchTheOcean, MSGBOX_NPC
	end

AquaHideout_B2F_Movement_PlayerApproach0:
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

AquaHideout_B2F_Movement_PlayerApproach1:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

AquaHideout_B2F_Movement_MattJumpInSub:
	delay_16
	jump_left
	set_invisible
	step_end

AquaHideout_B2F_Movement_ArchieJumpInSub:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	jump_left
	set_invisible
	step_end

AquaHideout_B2F_Movement_ShellyBlocksTheWay:
	delay_16
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_in_place_faster_right
	step_end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AquaHideout_B2F_Movement_WallyWalkToWarp:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

AquaHideout_B2F_Movement_WallySpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

AquaHideout_B2F_Movement_WallyWarp:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_ArchieSoYouChasedUsEvenHere:
	.string "ARCHIE: So, you chased us even here.\n"
	.string "I suppose I must applaud your tenacity.\p"
	.string "That being said, I think I've had quite\n"
	.string "enough of you meddling with our plans!\p"
	.string "I think it's time to put a stop to you\n"
	.string "once and for all!\p"
	.string "What do you say, SHELLY?$"

AquaHideout_B2F_Text_ShellyBratFromBackThen:
	.string "SHELLY: Ahahahaha!\p"
	.string "Not only is our favourite problem child\n"
	.string "back once again, but the brat from\l"
	.string "VERDANTURF thinks he's strong enough\l"
	.string "to join in too!\p"
	.string "Did you not learn your lesson?\n"
	.string "It seems you need to learn your place!$"

AquaHideout_B2F_Text_WallyImNotTheSamePerson:
	.string "WALLY: I'm not the same person I\n"
	.string "was back then.\p"
	.string "I've grown way stronger during my\n"
	.string "journey, battling against {PLAYER}.\p"
AquaHideout_B2F_Text_WallyLoop:
	.string "I was too weak to stop you before, but\n"
	.string "with my full power, and {PLAYER} by\l"
	.string "my side, I know we can win this!$"

AquaHideout_B2F_Text_ShellyDefeat:
	.string "Tch…\n"
	.string "I guess you've grown since VERDANTURF…$"

AquaHideout_B2F_Text_ArchieDefeat:
	.string "Why?\n"
	.string "Why must you get in our way?$"

AquaHideout_B2F_Text_MattBossLetsGo:
	.string "MATT: BOSS!\n"
	.string "All the preparations are complete!\p"
	.string "Let's get out of here!\p"
	.string "Sorry, brozo, but we were just stalling\n"
	.string "for time.\p"
	.string "I wish we could've battled, but we've\n"
	.string "got a job to do. Later!$"

AquaHideout_B2F_Text_ArchieTooLateNow:
	.string "ARCHIE: Your strength continues to\n"
	.string "defy belief, but it doesn't matter.\p"
	.string "With our preparations complete, there\n"
	.string "is nothing you can do to stop us!\p"
	.string "Now, if you'll excuse me.$"

AquaHideout_B2F_Text_ShellyWhereDoYouThinkYoureGoing:
	.string "SHELLY: Ah ha, where do you think\n"
	.string "you're going?\p"
	.string "Can't have you getting in the way\n"
	.string "now, can we?$"

AquaHideout_B2F_Text_ShellySearchTheOcean:
	.string "If you're going to give chase, you'd\n"
	.string "better search the big, wide sea beyond\l"
	.string "LILYCOVE.\p"
	.string "Ahahahaha!\n"
	.string "You can figure out the rest yourself!$"

AquaHideout_B2F_Text_WallyHappyOrMad:
	.string "WALLY: {PLAYER}…\n"
	.string "I'm not sure whether I'm happy or mad.\p"
	.string "I'm proud of myself for finally having\n"
	.string "the strength to defeat TEAM AQUA…\p"
	.string "But the fact that our victory meant\n"
	.string "nothing in the end really stings…\p"
	.string "No, now isn't the time to lose heart.\n"
	.string "ARCHIE is still out there, plotting\l"
	.string "something sinister.\p"
	.string "The sea beyong LILYCOVE, huh?\n"
	.string "We really have our work cut out for us.\p"
	.string "Well, I guess we better start looking.\n"
	.string "I'll let you know if I find something.\p"
	.string "Best of luck with your own search!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, I grew weary of waiting!\n"
	.string "You owe me a battle, too!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Tired of waiting…\n"
	.string "Lost and dazed…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "BOSS…\n"
	.string "Is this good enough?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Warp panels, the HIDEOUT's pride\n"
	.string "and joy!\p"
	.string "You're clueless about where you are,\n"
	.string "aren't you?\p"
	.string "Fluster and tire out the enemy, then\n"
	.string "lower the boom! That's our plan!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "What's wrong with you?\n"
	.string "You're not tired at all!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "That reminds me… I can't remember\n"
	.string "where I put the MASTER BALL.\p"
	.string "If I fail to guard it, our BOSS will\n"
	.string "chew me out…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "When I joined TEAM AQUA, the first\n"
	.string "thing I had to learn was how these\l"
	.string "warp panels connected.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "I was too occupied thinking about\n"
	.string "the warp panels…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "I'll have to learn about how I can\n"
	.string "battle more effectively…$"
