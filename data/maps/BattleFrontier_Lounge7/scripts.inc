BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_DreamEater
	case 2, BattleFrontier_Lounge7_EventScript_Swift
	case 3, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 4, BattleFrontier_Lounge7_EventScript_Wish
	case 5, BattleFrontier_Lounge7_EventScript_Counter
	case 6, BattleFrontier_Lounge7_EventScript_StealthRock
	case 7, BattleFrontier_Lounge7_EventScript_GyroBall
	case 8, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 9, BattleFrontier_Lounge7_EventScript_MegaKick
	case 10, BattleFrontier_Lounge7_EventScript_IcePunch
	case 11, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 12, BattleFrontier_Lounge7_EventScript_FirePunch
	case 13, BattleFrontier_Lounge7_EventScript_IcyWind
	case 14, BattleFrontier_Lounge7_EventScript_Roost
	case 15, BattleFrontier_Lounge7_EventScript_PollenPuff
	case 16, BattleFrontier_Lounge7_EventScript_NastyPlot
	case 17, BattleFrontier_Lounge7_EventScript_WillOWisp
	case 18, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_DreamEater
	case 2, BattleFrontier_Lounge7_EventScript_Swift
	case 3, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 4, BattleFrontier_Lounge7_EventScript_Wish
	case 5, BattleFrontier_Lounge7_EventScript_Counter
	case 6, BattleFrontier_Lounge7_EventScript_StealthRock
	case 7, BattleFrontier_Lounge7_EventScript_GyroBall
	case 8, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 9, BattleFrontier_Lounge7_EventScript_MegaKick
	case 10, BattleFrontier_Lounge7_EventScript_IcePunch
	case 11, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 12, BattleFrontier_Lounge7_EventScript_FirePunch
	case 13, BattleFrontier_Lounge7_EventScript_IcyWind
	case 14, BattleFrontier_Lounge7_EventScript_Roost
	case 15, BattleFrontier_Lounge7_EventScript_PollenPuff
	case 16, BattleFrontier_Lounge7_EventScript_NastyPlot
	case 17, BattleFrontier_Lounge7_EventScript_WillOWisp
	case 18, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_DREAM_EATER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_SWIFT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Wish::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_WISH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_COUNTER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_StealthRock::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_STEALTH_ROCK
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_GyroBall::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_GYRO_BALL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MEGA_KICK
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Roost::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_ROOST
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PollenPuff::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_POLLEN_PUFF
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_NastyPlot::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_NASTY_PLOT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_WillOWisp::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_WILL_O_WISP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Snore
	case 1, BattleFrontier_Lounge7_EventScript_MudSlap
	case 2, BattleFrontier_Lounge7_EventScript_Endure
	case 3, BattleFrontier_Lounge7_EventScript_IceFang
	case 4, BattleFrontier_Lounge7_EventScript_ThunderFang
	case 5, BattleFrontier_Lounge7_EventScript_FireFang
	case 6, BattleFrontier_Lounge7_EventScript_SignalBeam
	case 7, BattleFrontier_Lounge7_EventScript_PsychUp
	case 8, BattleFrontier_Lounge7_EventScript_AuroraVeil
	case 9, BattleFrontier_Lounge7_EventScript_Bulldoze
	case 10, BattleFrontier_Lounge7_EventScript_Softboiled
	case 11, BattleFrontier_Lounge7_EventScript_BodySlam
	case 12, BattleFrontier_Lounge7_EventScript_RockSlide
	case 13, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 14, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 15, BattleFrontier_Lounge7_EventScript_Liquidation
	case 16, BattleFrontier_Lounge7_EventScript_MeteorBeam
	case 17, BattleFrontier_Lounge7_EventScript_TripleAxel
	case 18, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Snore
	case 1, BattleFrontier_Lounge7_EventScript_MudSlap
	case 2, BattleFrontier_Lounge7_EventScript_Endure
	case 3, BattleFrontier_Lounge7_EventScript_IceFang
	case 4, BattleFrontier_Lounge7_EventScript_ThunderFang
	case 5, BattleFrontier_Lounge7_EventScript_FireFang
	case 6, BattleFrontier_Lounge7_EventScript_SignalBeam
	case 7, BattleFrontier_Lounge7_EventScript_PsychUp
	case 8, BattleFrontier_Lounge7_EventScript_AuroraVeil
	case 9, BattleFrontier_Lounge7_EventScript_Bulldoze
	case 10, BattleFrontier_Lounge7_EventScript_Softboiled
	case 11, BattleFrontier_Lounge7_EventScript_BodySlam
	case 12, BattleFrontier_Lounge7_EventScript_RockSlide
	case 13, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 14, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 15, BattleFrontier_Lounge7_EventScript_Liquidation
	case 16, BattleFrontier_Lounge7_EventScript_MeteorBeam
	case 17, BattleFrontier_Lounge7_EventScript_TripleAxel
	case 18, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_SNORE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_MUD_SLAP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_ENDURE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IceFang::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_ICE_FANG
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderFang::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_THUNDER_FANG
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FireFang::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_FIRE_FANG
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SignalBeam::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SIGNAL_BEAM
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_PSYCH_UP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_AuroraVeil::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_AURORA_VEIL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Bulldoze::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_BULLDOZE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_SOFT_BOILED
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_BODY_SLAM
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Liquidation::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_LIQUIDATION
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MeteorBeam::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_METEOR_BEAM
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_TripleAxel::
	setvar VAR_0x8008, 32
	setvar VAR_0x8005, MOVE_TRIPLE_AXEL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "You couldn't tell it from looking now,\n"
	.string "but I used to be one tough TRAINER.\p"
	.string "I had a reputation as the toughest\n"
	.string "BEAUTY around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What is it now?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that blowhard woman over\n"
	.string "there. I'm actually talented!\p"
	.string "Let me prove it to you.\n"
	.string "I can teach your POKéMON special and\l"
	.string "yet cute moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Are you back to learn special and\n"
	.string "yet cute POKéMON moves?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Fine, fine, look here!\n"
	.string "Which move should I teach?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "The move {STR_VAR_1}, is it?\n"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Fine, fine, now pick the POKéMON\n"
	.string "I should teach the move to.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "What the…\n"
	.string "You haven't got enough Battle Points!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Do you see how skilled I am now?\n"
	.string "I'll take your Battle Points, thanks!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "What's that?\n"
	.string "You don't want to…\p"
	.string "If you want to see how skilled I am,\n"
	.string "you come see me anytime!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "I know it's hard to see now, but I used\n"
	.string "to be one fantastic TRAINER.\p"
	.string "I had a reputation as the most\n"
	.string "invincible SWIMMER around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What's wrong?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that buffoonish woman over\n"
	.string "there. I'm actually experienced!\p"
	.string "I can prove it to you.\n"
	.string "I can teach your POKéMON hard and\l"
	.string "yet pretty moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Have you come to learn hard and\n"
	.string "yet pretty POKéMON moves?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Those ladies, the way they bad-mouth\n"
	.string "each other, you probably think that\l"
	.string "they don't get along.\p"
	.string "But if that were true, they wouldn't\n"
	.string "stay out here together, would they?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "When I was just a wee YOUNGSTER,\n"
	.string "those ladies were strong and beautiful.\p"
	.string "They were idols among us TRAINERS.\p"
	.string "Even now, age hasn't dulled their\n"
	.string "abilities.\p"
	.string "In fact, their POKéMON moves have\n"
	.string "grown even more polished.\p"
	.string "But… For some reason, I can't help\n"
	.string "but feel this…\p"
	.string "Time is so cruel…$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Curls up to con-\n"
	.string "ceal weak spots\n"
	.string "and raise DEFENSE.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Recovers half the\n"
	.string "damage inflicted\n"
	.string "on a sleeping foe.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Sprays star-\n"
	.string "shaped rays\n"
	.string "that never miss.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Inflicts damage\n"
	.string "identical to the\n"
	.string "user's level.$"

BattleFrontier_Lounge7_Text_WishDesc::
	.string "A wish that\n"
	.string "restores HP on\n"
	.string "the next turn.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Retaliates any\n"
	.string "physical hit with\n"
	.string "double the power.$"

BattleFrontier_Lounge7_Text_StealthRockDesc::
	.string "Pointy rocks that\n"
	.string "hurt POKéMON when\n"
	.string "they switch in.$"

BattleFrontier_Lounge7_Text_GyroBallDesc::
	.string "Spinning attack\n"
	.string "that hits harder\n"
	.string "the slower user is.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "A strong punch\n"
	.string "thrown with\n"
	.string "incredible power.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "An extremely\n"
	.string "powerful kick with\n"
	.string "intense force.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "An icy punch\n"
	.string "that may\n"
	.string "freeze the foe.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "An electrified\n"
	.string "punch that may\n"
	.string "paralyze the foe.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "A fiery punch\n"
	.string "that may burn\n"
	.string "the foe.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "A chilling attack\n"
	.string "that lowers the\n"
	.string "foe's SPEED.$"

BattleFrontier_Lounge7_Text_RoostDesc::
	.string "The user lands to\n"
	.string "rest their wings\n"
	.string "and restore HP.$"

BattleFrontier_Lounge7_Text_PollenPuffDesc::
	.string "A polleny puff\n"
	.string "that heals an ally\n"
	.string "or damages a foe.$"

BattleFrontier_Lounge7_Text_NastyPlotDesc::
	.string "Bad thoughts that\n"
	.string "raise the user's\n"
	.string "SPECIAL ATTACK.$"

BattleFrontier_Lounge7_Text_WillOWispDesc::
	.string "Ghostly flames\n"
	.string "that inflict a\n"
	.string "burn on the foe.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "A loud attack\n"
	.string "that can be used\n"
	.string "only while asleep.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Hurls mud in the\n"
	.string "foe's face to re-\n"
	.string "duce its accuracy.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Endures any at-\n"
	.string "tack for 1 turn,\n"
	.string "leaving 1HP.$"

BattleFrontier_Lounge7_Text_IceFangDesc::
	.string "An icy bite\n"
	.string "that may\n"
	.string "freeze the foe.$"

BattleFrontier_Lounge7_Text_ThunderFangDesc::
	.string "An electrified\n"
	.string "bite that may\n"
	.string "paralyze the foe.$"

BattleFrontier_Lounge7_Text_FireFangDesc::
	.string "A fiery bite\n"
	.string "that may burn\n"
	.string "the foe.$"

BattleFrontier_Lounge7_Text_SignalBeamDesc::
	.string "A flashing beam\n"
	.string "attack that may\n"
	.string "confuse the foe.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copies the foe's\n"
	.string "effect(s) and\n"
	.string "gives to the user.$"

BattleFrontier_Lounge7_Text_AuroraVeilDesc::
	.string "Reduces damage\n"
	.string "from any attack\n"
	.string "in the snow.$"

BattleFrontier_Lounge7_Text_BulldozeDesc::
	.string "Stomping attack\n"
	.string "that lowers the\n"
	.string "speed of all.$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Recovers up to\n"
	.string "half the user's\n"
	.string "maximum HP.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "A full-body slam\n"
	.string "that may cause\n"
	.string "paralysis.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Large boulders\n"
	.string "are hurled. May\n"
	.string "cause flinching.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "A weak jolt of\n"
	.string "electricity that\n"
	.string "paralyzes the foe.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "A fighting dance\n"
	.string "that sharply\n"
	.string "raises ATTACK.$"

BattleFrontier_Lounge7_Text_LiquidationDesc::
	.string "Full-force water\n"
	.string "attack that may\n"
	.string "lower DEFENSE.$"

BattleFrontier_Lounge7_Text_MeteorBeamDesc::
	.string "2-turn attack\n"
	.string "that also raises\n"
	.string "SP. ATTACK stat.$"

BattleFrontier_Lounge7_Text_TripleAxelDesc::
	.string "A consecutive 3-\n"
	.string "hit attack that\n"
	.string "raises in power.$"

BattleFrontier_Lounge7_Text_SplishySplashDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_FloatyFallDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_BouncyBubbleDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_BuzzyBuzzDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_DescSizzlySlide::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_GlitzyGlowDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_BaddyBadDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_ZippyZapDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_VoltTackleDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_PikaKapowDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_SappySeedDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_FreezyFrostDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_SparklySwirlDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

BattleFrontier_Lounge7_Text_VeeveeVolleyDesc::
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER\n"
	.string "PLACEHOLDER.$"

