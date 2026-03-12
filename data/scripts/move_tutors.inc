SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
	lock
	faceplayer
	move_tutor MOVE_SWAGGER, MoveTutor_Text_SwaggerTeach, MoveTutor_Text_SwaggerWhichMon, MoveTutor_EventScript_SwaggerDeclined, MoveTutor_EventScript_SwaggerTaught
	release
	end

MoveTutor_EventScript_SwaggerDeclined::
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SwaggerTaught::
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RolloutTutor::
	lock
	faceplayer
	move_tutor MOVE_ROLLOUT, MoveTutor_Text_RolloutTeach, MoveTutor_Text_RolloutWhichMon, MoveTutor_EventScript_RolloutDeclined, MoveTutor_EventScript_RolloutTaught
	release
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutTaught::
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
	lock
	faceplayer
	move_tutor MOVE_FURY_CUTTER, MoveTutor_Text_FuryCutterTeach, MoveTutor_Text_FuryCutterWhichMon, MoveTutor_EventScript_FuryCutterDeclined, MoveTutor_EventScript_FuryCutterTaught
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterTaught::
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_House_EventScript_MimicTutor::
	lock
	faceplayer
	move_tutor MOVE_MIMIC, MoveTutor_MimicTeach, MoveTutor_Text_MimicWhichMon, MoveTutor_EventScript_MimicDeclined, MoveTutor_EventScript_MimicTaught
	end

MoveTutor_EventScript_MimicDeclined::
	msgbox MoveTutor_MimicDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MimicTaught::
	msgbox MoveTutor_Text_MimicTaught, MSGBOX_DEFAULT
	release
	end

FallarborTown_Mart_EventScript_MetronomeTutor::
	lock
	faceplayer
	move_tutor MOVE_METRONOME, MoveTutor_Text_MetronomeTeach, MoveTutor_Text_MetronomeWhichMon, MoveTutor_EventScript_MetronomeDeclined, MoveTutor_EventScript_MetronomeTaught
	end

MoveTutor_EventScript_MetronomeDeclined::
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MetronomeTaught::
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_SleepTalkTutor::
	lock
	faceplayer
	move_tutor MOVE_SLEEP_TALK, MoveTutor_Text_SleepTalkTeach, MoveTutor_Text_SleepTalkWhichMon, MoveTutor_EventScript_SleepTalkDeclined, MoveTutor_EventScript_SleepTalkTaught
	end

MoveTutor_EventScript_SleepTalkDeclined::
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SleepTalkTaught::
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
	release
	end

@ Note that Substitute is a TM now, and so this likely should be replaced with the Pledge tutor
LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor::
	lock
	faceplayer
	move_tutor MOVE_SUBSTITUTE, MoveTutor_Text_SubstituteTeach, MoveTutor_Text_SubstituteWhichMon, MoveTutor_EventScript_SubstituteDeclined, MoveTutor_EventScript_SubstituteTaught
	end

MoveTutor_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SubstituteTaught::
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DynamicPunchTutor::
	lock
	faceplayer
	move_tutor MOVE_DYNAMIC_PUNCH, MoveTutor_Text_DynamicPunchTeach, MoveTutor_Text_DynamicPunchWhichMon, MoveTutor_EventScript_DynamicPunchDeclined, MoveTutor_EventScript_DynamicPunchTaught
	end

MoveTutor_EventScript_DynamicPunchDeclined::
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DynamicPunchTaught::
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor::
	lock
	faceplayer
	move_tutor MOVE_DOUBLE_EDGE, MoveTutor_Text_DoubleEdgeTeach, MoveTutor_Text_DoubleEdgeWhichMon, MoveTutor_EventScript_DoubleEdgeDeclined, MoveTutor_EventScript_DoubleEdgeTaught
	end

MoveTutor_EventScript_DoubleEdgeDeclined::
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DoubleEdgeTaught::
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
	lock
	faceplayer
	move_tutor MOVE_EXPLOSION, MoveTutor_Text_ExplosionTeach, MoveTutor_Text_ExplosionWhichMon, MoveTutor_EventScript_ExplosionDeclined, MoveTutor_EventScript_ExplosionTaught
	end

MoveTutor_EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ExplosionTaught::
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_DracoMeteorTutor::
	lock
	faceplayer
	move_tutor MOVE_DRACO_METEOR, MoveTutor_Text_DracoMeteorTeach, MoveTutor_Text_DracoMeteorWhichMon, MoveTutor_EventScript_DracoMeteorDeclined, MoveTutor_EventScript_DracoMeteorTaught
	end

MoveTutor_EventScript_DracoMeteorDeclined::
	msgbox MoveTutor_Text_DracoMeteorDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DracoMeteorTaught::
	msgbox MoveTutor_Text_DracoMeteorTaught, MSGBOX_DEFAULT
	release
	end

AbandonedShip_HiddenFloorCorridors_EventScript_SteelBeamTutor::
	lock
	faceplayer
	move_tutor MOVE_STEEL_BEAM, MoveTutor_Text_SteelBeamTeach, MoveTutor_Text_SteelBeamWhichMon, MoveTutor_EventScript_SteelBeamDeclined, MoveTutor_EventScript_SteelBeamTaught
	end

MoveTutor_EventScript_SteelBeamDeclined::
	msgbox MoveTutor_Text_SteelBeamDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SteelBeamTaught::
	msgbox MoveTutor_Text_SteelBeamTaught, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_PledgeTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_PledgeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_PledgeDeclined
	msgbox MoveTutor_Text_PledgeSelect, MSGBOX_DEFAULT
	waitmessage
	goto MoveTutor_EventScript_ChoosePledgeMove
	release
	end

MoveTutor_EventScript_ChoosePledgeMove::
	multichoice 0, 0, MULTI_PLEDGE_MOVES, FALSE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_GrassPledge
	case 1, MoveTutor_EventScript_FirePledge
	case 2, MoveTutor_EventScript_WaterPledge
	case 3, MoveTutor_EventScript_PledgeDeclined
	case MULTI_B_PRESSED, MoveTutor_EventScript_PledgeDeclined
	end

MoveTutor_EventScript_GrassPledge::
	msgbox MoveTutor_Text_PledgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_GRASS_PLEDGE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_PledgeDeclined
	goto MoveTutor_EventScript_PledgeTaught
	end

MoveTutor_EventScript_FirePledge::
	msgbox MoveTutor_Text_PledgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_FIRE_PLEDGE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_PledgeDeclined
	goto MoveTutor_EventScript_PledgeTaught
	end

MoveTutor_EventScript_WaterPledge::
	msgbox MoveTutor_Text_PledgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_WATER_PLEDGE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_PledgeDeclined
	goto MoveTutor_EventScript_PledgeTaught
	end

MoveTutor_EventScript_PledgeDeclined::
	msgbox MoveTutor_Text_PledgeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_PledgeTaught::
	msgbox MoveTutor_Text_PledgeTaught, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_EventScript_UltimateMoveTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_UltimateMoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_UltimateMoveDeclined
	msgbox MoveTutor_Text_UltimateMoveSelect, MSGBOX_DEFAULT
	waitmessage
	goto MoveTutor_EventScript_ChooseUltimateMove
	release
	end

MoveTutor_EventScript_ChooseUltimateMove::
	multichoice 0, 0, MULTI_ULTIMATE_MOVES, FALSE
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_FrenzyPlant
	case 1, MoveTutor_EventScript_BlastBurn
	case 2, MoveTutor_EventScript_HydroCannon
	case 3, MoveTutor_EventScript_UltimateMoveDeclined
	case MULTI_B_PRESSED, MoveTutor_EventScript_UltimateMoveDeclined
	end

MoveTutor_EventScript_FrenzyPlant::
	msgbox MoveTutor_Text_PledgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_FRENZY_PLANT
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_UltimateMoveDeclined
	goto MoveTutor_EventScript_UltimateMoveTaught
	end

MoveTutor_EventScript_BlastBurn::
	msgbox MoveTutor_Text_PledgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_BLAST_BURN
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_UltimateMoveDeclined
	goto MoveTutor_EventScript_UltimateMoveTaught
	end

MoveTutor_EventScript_HydroCannon::
	msgbox MoveTutor_Text_PledgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_HYDRO_CANNON
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_UltimateMoveDeclined
	goto MoveTutor_EventScript_UltimateMoveTaught
	end

MoveTutor_EventScript_UltimateMoveDeclined::
	msgbox MoveTutor_Text_UltimateMoveDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_UltimateMoveTaught::
	msgbox MoveTutor_Text_UltimateMoveTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_OpenBox::
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_CanOnlyBeLearnedOnce::
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	return

MoveTutor_AfterChooseBoxMon::
	waitstate
	special CanTeachMoveBoxMon
	waitstate
	return
