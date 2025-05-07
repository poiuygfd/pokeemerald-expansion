//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
#line 14
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("STEVEN"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 16
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 20
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 19
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 18
            .lvl = 42,
#line 17
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 21
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 26
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 30
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 29
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 28
            .lvl = 43,
#line 27
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 31
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 36
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 40
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 39
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 38
            .lvl = 44,
#line 37
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 41
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
        },
    },
#line 46
#line 52
    [DIFFICULTY_NORMAL][PARTNER_STEVEN_SOUTHERN_ISLAND] =
    {
#line 47
        .trainerName = _("STEVEN"),
#line 48
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 49
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 51
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 54
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 58
            .ev = TRAINER_PARTY_EVS(0, 150, 150, 0, 0, 0),
#line 57
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 56
            .lvl = 30,
#line 55
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 59
                MOVE_CONFUSION,
                MOVE_METAL_CLAW,
                MOVE_IRON_DEFENSE,
                MOVE_AGILITY,
            },
            },
            {
#line 64
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 68
            .ev = TRAINER_PARTY_EVS(150, 0, 0, 0, 0, 150),
#line 67
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 66
            .lvl = 29,
#line 65
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 69
                MOVE_AERIAL_ACE,
                MOVE_STEEL_WING,
                MOVE_ROOST,
                MOVE_SAND_ATTACK,
            },
            },
            {
#line 74
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 78
            .ev = TRAINER_PARTY_EVS(150, 150, 0, 0, 0, 0),
#line 77
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 76
            .lvl = 31,
#line 75
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 79
                MOVE_METAL_CLAW,
                MOVE_ROCK_TOMB,
                MOVE_ROAR,
                MOVE_PROTECT,
            },
            },
        },
    },
