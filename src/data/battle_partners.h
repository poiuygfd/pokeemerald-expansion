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
#line 84
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_FRONTIER_MUDKIP] =
    {
#line 85
        .trainerName = _("BRENDAN"),
#line 86
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 87
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 89
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 91
            .species = SPECIES_CENTISKORCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 93
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 92
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 94
            .species = SPECIES_GASTRODON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 96
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 95
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 97
            .species = SPECIES_SCEPTILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 99
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 98
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 100
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_FRONTIER_TREECKO] =
    {
#line 101
        .trainerName = _("BRENDAN"),
#line 102
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 103
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 105
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 107
            .species = SPECIES_GASTRODON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 109
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 108
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 110
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 112
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 111
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 113
            .species = SPECIES_BLAZIKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 115
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 114
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 116
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_FRONTIER_TORCHIC] =
    {
#line 117
        .trainerName = _("BRENDAN"),
#line 118
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 119
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 121
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 123
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 125
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 124
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 126
            .species = SPECIES_CENTISKORCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 128
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 127
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 129
            .species = SPECIES_SWAMPERT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 131
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 130
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 132
    [DIFFICULTY_NORMAL][PARTNER_MAY_FRONTIER_MUDKIP] =
    {
#line 133
        .trainerName = _("MAY"),
#line 134
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 135
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender =
#line 136
F_TRAINER_FEMALE | 
#line 137
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 139
            .species = SPECIES_CENTISKORCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 141
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 140
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 142
            .species = SPECIES_GASTRODON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 144
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 143
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 145
            .species = SPECIES_SCEPTILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 147
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 146
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 148
    [DIFFICULTY_NORMAL][PARTNER_MAY_FRONTIER_TREECKO] =
    {
#line 149
        .trainerName = _("MAY"),
#line 150
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 151
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender =
#line 152
F_TRAINER_FEMALE | 
#line 153
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 155
            .species = SPECIES_GASTRODON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 157
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 156
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 158
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 160
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 159
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 161
            .species = SPECIES_BLAZIKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 163
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 162
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 164
    [DIFFICULTY_NORMAL][PARTNER_MAY_FRONTIER_TORCHIC] =
    {
#line 165
        .trainerName = _("MAY"),
#line 166
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 167
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender =
#line 168
F_TRAINER_FEMALE | 
#line 169
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 171
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 173
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 172
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 174
            .species = SPECIES_CENTISKORCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 176
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 175
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 177
            .species = SPECIES_SWAMPERT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 179
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 178
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 180
    [DIFFICULTY_NORMAL][PARTNER_WALLY_FRONTIER] =
    {
#line 181
        .trainerName = _("WALLY"),
#line 182
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 183
        .trainerPic = TRAINER_BACK_PIC_WALLY,
        .encounterMusic_gender =
#line 185
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 187
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 189
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 188
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 190
            .species = SPECIES_MAGNEZONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 192
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 191
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 193
            .species = SPECIES_GALLADE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 195
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 194
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 196
    [DIFFICULTY_NORMAL][PARTNER_STEVEN_FRONTIER] =
    {
#line 197
        .trainerName = _("STEVEN"),
#line 198
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 199
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 201
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 203
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 205
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 204
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 206
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 208
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 207
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 209
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 211
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 210
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 212
    [DIFFICULTY_NORMAL][PARTNER_RED_FRONTIER] =
    {
#line 213
        .trainerName = _("RED"),
#line 214
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 215
        .trainerPic = TRAINER_BACK_PIC_RED,
        .encounterMusic_gender =
#line 217
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 219
            .species = SPECIES_SNORLAX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 221
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 220
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 222
            .species = SPECIES_PIKACHU_STARTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 224
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 223
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 225
            .species = SPECIES_CHARIZARD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 227
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 226
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
#line 228
    [DIFFICULTY_NORMAL][PARTNER_LEAF_FRONTIER] =
    {
#line 229
        .trainerName = _("LEAF"),
#line 230
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 231
        .trainerPic = TRAINER_BACK_PIC_LEAF,
        .encounterMusic_gender =
#line 232
F_TRAINER_FEMALE | 
#line 233
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 235
            .species = SPECIES_GOODRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 237
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 236
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 238
            .species = SPECIES_EEVEE_STARTER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 240
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 239
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
#line 241
            .species = SPECIES_VENUSAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 243
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 242
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
