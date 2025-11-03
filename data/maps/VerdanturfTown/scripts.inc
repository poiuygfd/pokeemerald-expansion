VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_TeamAquaMeanie, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyBustedThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_AquaTrigger1::
	lockall
	call VerdanturfTown_EventScript_TeamAquaEvent
	playse SE_WALL_HIT
	applymovement LOCALID_VERDANTURF_GRUNT, VerdanturfTown_Movement_GruntPushed
	applymovement LOCALID_VERDANTURF_SHELLY, VerdanturfTown_Movement_ShellyWalk1
	waitmovement 0
	applymovement LOCALID_VERDANTURF_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	msgbox VerdanturfTown_Text_TimeToCrushAnotherBrat, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SHELLY_VERDANTURF, VerdanturfTown_Text_ShellyDefeat
	call VerdanturfTown_EventScript_TeamAquaDefeated
	applymovement LOCALID_VERDANTURF_WALLY, VerdanturfTown_Movement_WallyWalk1
	waitmovement 0
	call VerdanturfTown_EventScript_WallyLost
	playse SE_EXIT
	addobject LOCALID_VERDANTURF_WANDAS_BF
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFWalkDown
	waitmovement 0
	playse SE_EXIT
	addobject LOCALID_VERDANTURF_DEVON_EMPLOYEE
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFWalk1
	applymovement LOCALID_VERDANTURF_DEVON_EMPLOYEE, VerdanturfTown_Movement_DevonWalk1
	waitmovement 0
	goto VerdanturfTown_EventScript_WandaBFAndDevonEmployee
	end

VerdanturfTown_EventScript_AquaTrigger2::
	lockall
	call VerdanturfTown_EventScript_TeamAquaEvent
	playse SE_WALL_HIT
	applymovement LOCALID_VERDANTURF_GRUNT, VerdanturfTown_Movement_GruntPushed
	applymovement LOCALID_VERDANTURF_SHELLY, VerdanturfTown_Movement_ShellyWalk2
	waitmovement 0
	applymovement LOCALID_VERDANTURF_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	msgbox VerdanturfTown_Text_TimeToCrushAnotherBrat, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SHELLY_VERDANTURF, VerdanturfTown_Text_ShellyDefeat
	call VerdanturfTown_EventScript_TeamAquaDefeated
	applymovement LOCALID_VERDANTURF_WALLY, VerdanturfTown_Movement_WallyWalk2
	waitmovement 0
	call VerdanturfTown_EventScript_WallyLostAlt
	playse SE_EXIT
	addobject LOCALID_VERDANTURF_WANDAS_BF
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFWalkDown
	waitmovement 0
	playse SE_EXIT
	addobject LOCALID_VERDANTURF_DEVON_EMPLOYEE
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFWalk2
	applymovement LOCALID_VERDANTURF_DEVON_EMPLOYEE, VerdanturfTown_Movement_DevonWalk2
	waitmovement 0
	goto VerdanturfTown_EventScript_WandaBFAndDevonEmployee
	end

VerdanturfTown_EventScript_AquaTrigger3::
	lockall
	call VerdanturfTown_EventScript_TeamAquaEvent
	playse SE_WALL_HIT
	applymovement LOCALID_VERDANTURF_GRUNT, VerdanturfTown_Movement_GruntPushed
	applymovement LOCALID_VERDANTURF_SHELLY, VerdanturfTown_Movement_ShellyWalk3
	waitmovement 0
	applymovement LOCALID_VERDANTURF_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	msgbox VerdanturfTown_Text_TimeToCrushAnotherBrat, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SHELLY_VERDANTURF, VerdanturfTown_Text_ShellyDefeat
	call VerdanturfTown_EventScript_TeamAquaDefeated
	applymovement LOCALID_VERDANTURF_WALLY, VerdanturfTown_Movement_WallyWalk3
	waitmovement 0
	call VerdanturfTown_EventScript_WallyLost
	playse SE_EXIT
	addobject LOCALID_VERDANTURF_WANDAS_BF
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFWalkDown
	waitmovement 0
	playse SE_EXIT
	addobject LOCALID_VERDANTURF_DEVON_EMPLOYEE
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFWalk3
	applymovement LOCALID_VERDANTURF_DEVON_EMPLOYEE, VerdanturfTown_Movement_DevonWalk3
	waitmovement 0
	goto VerdanturfTown_EventScript_WandaBFAndDevonEmployee
	end

VerdanturfTown_EventScript_AquaTrigger4::
	lockall
	call VerdanturfTown_EventScript_TeamAquaEvent
	playse SE_WALL_HIT
	applymovement LOCALID_VERDANTURF_GRUNT, VerdanturfTown_Movement_GruntPushed
	applymovement LOCALID_VERDANTURF_SHELLY, VerdanturfTown_Movement_ShellyWalk4
	waitmovement 0
	applymovement LOCALID_VERDANTURF_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	msgbox VerdanturfTown_Text_TimeToCrushAnotherBrat, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SHELLY_VERDANTURF, VerdanturfTown_Text_ShellyDefeat
	call VerdanturfTown_EventScript_TeamAquaDefeated
	applymovement LOCALID_VERDANTURF_WALLY, VerdanturfTown_Movement_WallyWalk4
	waitmovement 0
	call VerdanturfTown_EventScript_WallyLost
	playse SE_EXIT
	addobject LOCALID_VERDANTURF_WANDAS_BF
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFWalkDown
	waitmovement 0
	playse SE_EXIT
	addobject LOCALID_VERDANTURF_DEVON_EMPLOYEE
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFWalk4
	applymovement LOCALID_VERDANTURF_DEVON_EMPLOYEE, VerdanturfTown_Movement_DevonWalk4
	waitmovement 0
	goto VerdanturfTown_EventScript_WandaBFAndDevonEmployeeAlt
	end

VerdanturfTown_EventScript_AquaTrigger5::
	lockall
	call VerdanturfTown_EventScript_TeamAquaEvent
	playse SE_WALL_HIT
	applymovement LOCALID_VERDANTURF_GRUNT, VerdanturfTown_Movement_GruntPushed
	applymovement LOCALID_VERDANTURF_SHELLY, VerdanturfTown_Movement_ShellyWalk5
	waitmovement 0
	applymovement LOCALID_VERDANTURF_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	msgbox VerdanturfTown_Text_TimeToCrushAnotherBrat, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SHELLY_VERDANTURF, VerdanturfTown_Text_ShellyDefeat
	call VerdanturfTown_EventScript_TeamAquaDefeated
	applymovement LOCALID_VERDANTURF_WALLY, VerdanturfTown_Movement_WallyWalk5
	waitmovement 0
	call VerdanturfTown_EventScript_WallyLost
	playse SE_EXIT
	addobject LOCALID_VERDANTURF_WANDAS_BF
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFWalkDown
	waitmovement 0
	playse SE_EXIT
	addobject LOCALID_VERDANTURF_DEVON_EMPLOYEE
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFWalk5
	applymovement LOCALID_VERDANTURF_DEVON_EMPLOYEE, VerdanturfTown_Movement_DevonWalk5
	waitmovement 0
	goto VerdanturfTown_EventScript_WandaBFAndDevonEmployeeAlt
	end

VerdanturfTown_EventScript_TeamAquaEvent::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox VerdanturfTown_Text_ThatsHilarious, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_SHELLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox VerdanturfTown_Text_AlmostAsHilarious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VERDANTURF_WALLY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 20
	applymovement LOCALID_VERDANTURF_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_VERDANTURF_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox VerdanturfTown_Text_ItsThatKid, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_GRUNT, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_VERDANTURF_SHELLY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox VerdanturfTown_Text_YouLostToAChild, MSGBOX_DEFAULT
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	closemessage
	return

VerdanturfTown_EventScript_TeamAquaDefeated::
	msgbox VerdanturfTown_Text_TakeItBack, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_PARTS
	msgbox VerdanturfTown_Text_LetsRetreat, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	removeobject LOCALID_VERDANTURF_GRUNT
	removeobject LOCALID_VERDANTURF_SHELLY
	delay 10
	fadescreen FADE_FROM_BLACK
	delay 30
	return

VerdanturfTown_Movement_GruntPushed:
	face_down
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

VerdanturfTown_Movement_ShellyWalk1:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	face_left
	step_end

VerdanturfTown_Movement_ShellyWalk2:
	walk_left
	walk_left
	walk_left
	walk_up
	face_left
	step_end

VerdanturfTown_Movement_ShellyWalk3:
	walk_left
	walk_left
	walk_left
	step_end

VerdanturfTown_Movement_ShellyWalk4:
	walk_left
	walk_left
	walk_left
	walk_down
	face_left
	step_end

VerdanturfTown_Movement_ShellyWalk5:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	face_left
	step_end

VerdanturfTown_EventScript_WallyLost::
	msgbox VerdanturfTown_Text_ITriedToStopThem, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VERDANTURF_WALLY, VerdanturfTown_Movement_WallyWalkAway
	waitmovement 0
	removeobject LOCALID_VERDANTURF_WALLY
	setflag FLAG_HIDE_VERDANTURF_TOWN_TEAM_AQUA
	setvar VAR_VERDANTURF_TOWN_STATE, 1
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_CITY_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	return

VerdanturfTown_EventScript_WallyLostAlt::
	msgbox VerdanturfTown_Text_ITriedToStopThem, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VERDANTURF_WALLY, VerdanturfTown_Movement_WallyWalkAway2
	waitmovement 0
	removeobject LOCALID_VERDANTURF_WALLY
	setflag FLAG_HIDE_VERDANTURF_TOWN_TEAM_AQUA
	setvar VAR_VERDANTURF_TOWN_STATE, 1
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_CITY_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	return

VerdanturfTown_Movement_WallyWalk1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	face_left
	step_end

VerdanturfTown_Movement_WallyWalk2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_left
	step_end

VerdanturfTown_Movement_WallyWalk3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

VerdanturfTown_Movement_WallyWalk4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_left
	step_end

VerdanturfTown_Movement_WallyWalk5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	face_left
	step_end

VerdanturfTown_Movement_WallyWalkAway:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VerdanturfTown_Movement_WallyWalkAway2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VerdanturfTown_EventScript_WandaBFAndDevonEmployee::
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	msgbox VerdanturfTown_Text_WayToGoKid, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFLeave1
	waitmovement 0
	removeobject LOCALID_VERDANTURF_WANDAS_BF
	applymovement LOCALID_VERDANTURF_DEVON_EMPLOYEE, VerdanturfTown_Movement_DevonMove1
	waitmovement 0
	msgbox VerdanturfTown_Text_YouGotItThankYou, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	msgbox VerdanturfTown_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
	setflag FLAG_RUSTURF_TUNNEL_OPENED
	setvar VAR_RUSTBORO_CITY_STATE, 5
	delay 30
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
	waitstate
	releaseall
	end

VerdanturfTown_EventScript_WandaBFAndDevonEmployeeAlt::
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	msgbox VerdanturfTown_Text_WayToGoKid, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VERDANTURF_WANDAS_BF, VerdanturfTown_Movement_WandaBFLeave2
	waitmovement 0
	removeobject LOCALID_VERDANTURF_WANDAS_BF
	applymovement LOCALID_VERDANTURF_DEVON_EMPLOYEE, VerdanturfTown_Movement_DevonMove2
	waitmovement 0
	msgbox VerdanturfTown_Text_YouGotItThankYou, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	msgbox VerdanturfTown_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
	setflag FLAG_RUSTURF_TUNNEL_OPENED
	setvar VAR_RUSTBORO_CITY_STATE, 5
	delay 30
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
	waitstate
	releaseall
	end

VerdanturfTown_Movement_WandaBFWalkDown:
	walk_down
	step_end

VerdanturfTown_Movement_WandaBFWalk1:
	walk_down
	walk_down
	walk_right
	step_end

VerdanturfTown_Movement_DevonWalk1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VerdanturfTown_Movement_WandaBFWalk2:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VerdanturfTown_Movement_DevonWalk2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VerdanturfTown_Movement_WandaBFWalk3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VerdanturfTown_Movement_DevonWalk3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VerdanturfTown_Movement_WandaBFWalk4:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VerdanturfTown_Movement_DevonWalk4:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VerdanturfTown_Movement_WandaBFWalk5:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VerdanturfTown_Movement_DevonWalk5:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VerdanturfTown_Movement_WandaBFLeave1:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VerdanturfTown_Movement_WandaBFLeave2:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VerdanturfTown_Movement_DevonMove1:
	walk_up
	face_right
	step_end

VerdanturfTown_Movement_DevonMove2:
	walk_down
	face_right
	step_end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_TeamAquaMeanie:
	.string "Waaaaaah!\p"
	.string "That TEAM AQUA meanie just pushed me\n" 
	.string "out of the way!\p"
	.string "How did he even get out of the cave?\p"
	.string "They stopped the big tunnel project\n"
	.string "for the timid POKéMON that live there!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "This cave is full of timid POKéMON\n"
	.string "that get scared easily.\p"
	.string "They're super cute, though!$"

VerdanturfTown_Text_AirCleanHere:
	.string "The way the winds blow, volcanic ash\n"
	.string "is never blown in this direction.\p"
	.string "The air is clean and delicious here.\n"
	.string "Living here should do wonders for even\l"
	.string "frail and sickly people.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "My POKéMON and I, we've been riding\n"
	.string "a hot winning streak.\p"
	.string "So I decided to make my BATTLE TENT\n"
	.string "debut in this town.$"

VerdanturfTown_Text_GuyBustedThroughCave:
	.string "Did you see that guy barrel out of\n"
	.string "RUSTURF TUNNEL just now?\p"
	.string "The way out was supposed to be blocked\n"
	.string "by some boulders though…\p"
	.string "Did he just like…\n"
	.string "Charge through them?$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "That cave next to the POKéMON MART\n"
	.string "is now a tunnel to the other side.\p"
	.string "It's great--it's easy to go shop for\n"
	.string "new DEVON products in RUSTBORO now.$"

VerdanturfTown_Text_ThatsHilarious:
	.string "???: Ahahahahaha!\n"
	.string "You seriously charged straight through\l"
	.string "the boulders that were in the way?\p"
	.string "That's disgustingly hilarious!$"

VerdanturfTown_Text_AlmostAsHilarious:
	.string "Almost as hilarious as this little\n"
	.string "kid who thought he could take on\l"
	.string "an ADMIN of the mighty TEAM AQUA!\p"
	.string "Let this be a reminder to you to\n"
	.string "never mess with TEAM AQUA again, brat!$"

VerdanturfTown_Text_ItsThatKid:
	.string "Aiyeee!\n"
	.string "Watch out, SHELLY!\p"
	.string "That's the kid who thrashed me just now!$"

VerdanturfTown_Text_YouLostToAChild:
	.string "SHELLY: Oh?\n"
	.string "You lost to a mere child?\p"
	.string "And here I was, almost impressed by\n"
	.string "you for your crazy stunt earlier…\p"
	.string "Must I always clean up after the messes\n"
	.string "of you incompetent GRUNTS?$"

VerdanturfTown_Text_TimeToCrushAnotherBrat:
	.string "SHELLY: Listen, kid.\p"
	.string "I've already crushed one brat today\n"
	.string "and I don't mind adding a second one\l"
	.string "to that list.\p"
	.string "I'll make you regret messing with\n"
	.string "TEAM AQUA!$"

VerdanturfTown_Text_ShellyDefeat:
	.string "Ahahahaha!\n"
	.string "How disgusting!$"

VerdanturfTown_Text_TakeItBack:
	.string "SHELLY: Ahahahaha!\n"
	.string "I can see how you lost to this kid!\p"
	.string "You're disgustingly strong.\n"
	.string "I like that!\p"
	.string "You want these DEVON PARTS back so\n"
	.string "badly, you can have them.$"

VerdanturfTown_Text_LetsRetreat:
	.string "SHELLY: Just know that the next time\n"
	.string "you cross TEAM AQUA, you won't get\l"
	.string "away so easily!$"

VerdanturfTown_Text_ITriedToStopThem:
	.string "WALLY: I'm glad you were here, {PLAYER}…\p"
	.string "I heard those people talking about some\n"
	.string "PARTS they stole, so I tried to help.\p"
	.string "But she was just too strong for me…\n"
	.string "Me and RALTS didn't stand a chance.\p"
	.string "This is so frustrating…\n"
	.string "I don't want to lose to people like that!\p"
	.string "I'm feeling fired up now!\n"
	.string "I want to become a cool TRAINER, just\l"
	.string "like you, who can stop any bad guys like\l"
	.string "that from hurting any more people!\p"
	.string "I'm going to go train right now!\n"
	.string "I'll catch you later, {PLAYER}!$"

VerdanturfTown_Text_WayToGoKid:
	.string "Way to go, kid!\p"
	.string "Looks like you managed to handle\n"
	.string "things here just fine!\p"
	.string "While it wasn't in an ideal way, now\n"
	.string "that the tunnel has been cleared…\p"
	.string "I can visit my girlfriend whenever\n"
	.string "I want to!\p"
	.string "I'll see you around, kid!$"

VerdanturfTown_Text_YouGotItThankYou:
	.string "I was getting worried, so I came\n"
	.string "to come find you.\p"
	.string "So? How did it go?\n"
	.string "The DEVON GOODS?\p"
	.string "You did it!\n"
	.string "You got them back!\p"
	.string "You really are a great TRAINER!\p"
	.string "I know! As my thanks, I'll give you\n"
	.string "this EXP. Share! We developed this\l"
	.string "to help with training up POKéMON!$"

VerdanturfTown_Text_PleaseComeWithMe:
	.string "Excuse me, please!\n"
	.string "Please come with me!$"

VerdanturfTown_Text_TownSign:
	.string "VERDANTURF TOWN\p"
	.string "“The windswept highlands with the\n"
	.string "sweet fragrance of grass.”$"

VerdanturfTown_Text_WandasHouse:
	.string "WANDA'S HOUSE$"

VerdanturfTown_Text_BattleTentSign:
	.string "BATTLE TENT VERDANTURF SITE\n"
	.string "“Feast Your Eyes on Battles!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "RUSTURF TUNNEL\n"
	.string "“Linking RUSTBORO and VERDANTURF\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

