#include "constants/abilities.h"
#include "species_info/shared_dex_text.h"
#include "species_info/shared_front_pic_anims.h"

// Macros for ease of use.

#define EVOLUTION(...) (const struct Evolution[]) { __VA_ARGS__, { EVOLUTIONS_END }, }
#define CONDITIONS(...) ((const struct EvolutionParam[]) { __VA_ARGS__, {CONDITIONS_END} })

#define ANIM_FRAMES(...) (const union AnimCmd *const[]) { sAnim_GeneralFrame0, (const union AnimCmd[]) { __VA_ARGS__ ANIMCMD_END, }, }

#if P_FOOTPRINTS
#define FOOTPRINT(sprite) .footprint = gMonFootprint_## sprite,
#else
#define FOOTPRINT(sprite)
#endif

#if B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE
#define SHADOW(x, y, size)  .enemyShadowXOffset = x, .enemyShadowYOffset = y, .enemyShadowSize = size,
#define NO_SHADOW           .suppressEnemyShadow = TRUE,
#else
#define SHADOW(x, y, size)  .enemyShadowXOffset = 0, .enemyShadowYOffset = 0, .enemyShadowSize = 0,
#define NO_SHADOW           .suppressEnemyShadow = FALSE,
#endif

#define SIZE_32x32 1
#define SIZE_64x64 0

// Set .compressed = OW_GFX_COMPRESS
#define COMP OW_GFX_COMPRESS

#if OW_POKEMON_OBJECT_EVENTS
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
#define OVERWORLD_PAL(...)                                  \
    .overworldPalette = DEFAULT(NULL, __VA_ARGS__),         \
    .overworldShinyPalette = DEFAULT_2(NULL, __VA_ARGS__),
#if P_GENDER_DIFFERENCES
#define OVERWORLD_PAL_FEMALE(...)                                 \
    .overworldPaletteFemale = DEFAULT(NULL, __VA_ARGS__),         \
    .overworldShinyPaletteFemale = DEFAULT_2(NULL, __VA_ARGS__),
#else
#define OVERWORLD_PAL_FEMALE(...)
#endif //P_GENDER_DIFFERENCES
#else
#define OVERWORLD_PAL(...)
#define OVERWORLD_PAL_FEMALE(...)
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE

#define OVERWORLD_DATA(picTable, _size, shadow, _tracks, _anims)                                                                     \
{                                                                                                                                       \
    .tileTag = TAG_NONE,                                                                                                                \
    .paletteTag = OBJ_EVENT_PAL_TAG_DYNAMIC,                                                                                            \
    .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,                                                                                     \
    .size = (_size == SIZE_32x32 ? 512 : 2048),                                                                                         \
    .width = (_size == SIZE_32x32 ? 32 : 64),                                                                                           \
    .height = (_size == SIZE_32x32 ? 32 : 64),                                                                                          \
    .paletteSlot = PALSLOT_NPC_1,                                                                                                       \
    .shadowSize = shadow,                                                                                                               \
    .inanimate = FALSE,                                                                                                                 \
    .compressed = COMP,                                                                                                                 \
    .tracks = _tracks,                                                                                                                  \
    .oam = (_size == SIZE_32x32 ? &gObjectEventBaseOam_32x32 : &gObjectEventBaseOam_64x64),                                             \
    .subspriteTables = (_size == SIZE_32x32 ? sOamTables_32x32 : sOamTables_64x64),                                                     \
    .anims = _anims,                                                                                                                    \
    .images = picTable,                                                                                                                 \
    .affineAnims = gDummySpriteAffineAnimTable,                                                                                         \
}

#define OVERWORLD(objEventPic, _size, shadow, _tracks, _anims, ...)                                 \
    .overworldData = OVERWORLD_DATA(objEventPic, _size, shadow, _tracks, _anims),                   \
    OVERWORLD_PAL(__VA_ARGS__)

#if P_GENDER_DIFFERENCES
#define OVERWORLD_FEMALE(objEventPic, _size, shadow, _tracks, _anims, ...)                          \
    .overworldDataFemale = OVERWORLD_DATA(objEventPic, _size, shadow, _tracks, _anims),             \
    OVERWORLD_PAL_FEMALE(__VA_ARGS__)
#else
#define OVERWORLD_FEMALE(...)
#endif //P_GENDER_DIFFERENCES

#else
#define OVERWORLD(...)
#define OVERWORLD_FEMALE(...)
#define OVERWORLD_PAL(...)
#define OVERWORLD_PAL_FEMALE(...)
#endif //OW_POKEMON_OBJECT_EVENTS

// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.
// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.
#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))

#define MON_TYPES(type1, ...) { type1, DEFAULT(type1, __VA_ARGS__) }
#define MON_EGG_GROUPS(group1, ...) { group1, DEFAULT(group1, __VA_ARGS__) }

#define FLIP    0
#define NO_FLIP 1

const struct SpeciesInfo gSpeciesInfo[] =
{
    [SPECIES_NONE] =
    {
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = gFallbackPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(QuestionMark)
        SHADOW(-1, 0, SHADOW_SIZE_M)
    #if OW_POKEMON_OBJECT_EVENTS
        .overworldData = {
            .tileTag = TAG_NONE,
            .paletteTag = OBJ_EVENT_PAL_TAG_SUBSTITUTE,
            .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,
            .size = 512,
            .width = 32,
            .height = 32,
            .paletteSlot = PALSLOT_NPC_1,
            .shadowSize = SHADOW_SIZE_M,
            .inanimate = FALSE,
            .compressed = COMP,
            .tracks = TRACKS_FOOT,
            .oam = &gObjectEventBaseOam_32x32,
            .subspriteTables = sOamTables_32x32,
            .anims = sAnimTable_Following,
            .images = sPicTable_Substitute,
            .affineAnims = gDummySpriteAffineAnimTable,
        },
    #endif
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .eggMoveLearnset = sNoneEggMoveLearnset,
    },

    #include "species_info/gen_1_families.h"
    #include "species_info/gen_2_families.h"
    #include "species_info/gen_3_families.h"
    #include "species_info/gen_4_families.h"
    #include "species_info/gen_5_families.h"
    #include "species_info/gen_6_families.h"
    #include "species_info/gen_7_families.h"
    #include "species_info/gen_8_families.h"
    #include "species_info/gen_9_families.h"

    [SPECIES_EGG] =
    {
        .frontPic = gMonFrontPic_Egg,
        .frontPicSize = MON_COORDS_SIZE(24, 24),
        .frontPicYOffset = 20,
        .backPic = gMonFrontPic_Egg,
        .backPicSize = MON_COORDS_SIZE(24, 24),
        .backPicYOffset = 20,
        .palette = gMonPalette_Egg,
        .shinyPalette = gMonPalette_Egg,
        .iconSprite = gMonIcon_Egg,
        .iconPalIndex = 1,
    },

    /* You may add any custom species below this point based on the following structure: */

    [SPECIES_MARIN] =
    { 
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 75,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER, TYPE_FAIRY),
        .catchRate = 75,
        .expYield = 148,
        .evYield_Speed  = 1,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_FRIEND_GUARD, ABILITY_WATER_BUBBLE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Marin"),
        .cryId = CRY_MARIN,
        .natDexNum = NATIONAL_DEX_MARIN,
        .categoryName = _("Magical"),
        .height = 4,
        .weight = 50,
        .description = COMPOUND_STRING(
            "Marin are known for their kind, friendly\n"
            "demeanour. They aren't very good battlers,\n"
            "but they can grant their allies enhanced\n"
            "strength by cheering them on."),
        .pokemonScale = 457,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Marin,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Marin,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SPRING,
        .palette = gMonPalette_Marin,
        .shinyPalette = gMonShinyPalette_Marin,
        .iconSprite = gMonIcon_Marin,
        .iconPalIndex = 0,
        SHADOW(-1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Marin)
        OVERWORLD(
            sPicTable_Marin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Marin,
            gShinyOverworldPalette_Marin
        )
        .levelUpLearnset = sMarinLevelUpLearnset,
        .teachableLearnset = sMarinTeachableLearnset,
        .eggMoveLearnset = sMarinEggMoveLearnset,
    },

    [SPECIES_MISSINGNO] =
    { 
        .baseHP        = 33,
        .baseAttack    = 136,
        .baseDefense   = 0,
        .baseSpeed     = 29,
        .baseSpAttack  = 6,
        .baseSpDefense = 255,
        .types = MON_TYPES(TYPE_FLYING, TYPE_NORMAL),
        .catchRate = 30,
        .expYield = 164,
        .evYield_Attack  = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_ANTIVIRUS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("MissingNo."),
        .cryId = CRY_MISSINGNO,
        .natDexNum = NATIONAL_DEX_MISSINGNO,
        .categoryName = _("Error"),
        .height = 10,
        .weight = 100,
        .description = COMPOUND_STRING("Error 404: Entry not found."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MissingNo,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_MissingNo,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_MissingNo,
        .shinyPalette = gMonShinyPalette_MissingNo,
        .iconSprite = gMonIcon_MissingNo,
        .iconPalIndex = 4,
        SHADOW(0, 18, SHADOW_SIZE_S)
        FOOTPRINT(MissingNo)
        OVERWORLD(
            sPicTable_MissingNo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_MissingNo,
            gShinyOverworldPalette_MissingNo
        )
        .levelUpLearnset = sMissingNoLevelUpLearnset,
        .teachableLearnset = sMissingNoTeachableLearnset,
        .eggMoveLearnset = sMissingNoEggMoveLearnset,
    },

    [SPECIES_AVITORCH_CALM] =
    {
        .baseHP        = 120,
        .baseAttack    = 56,
        .baseDefense   = 64,
        .baseSpeed     = 69,
        .baseSpAttack  = 56,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 171,
        .evYield_HP  = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_PUNISHER, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Avitorch"),
        .cryId = CRY_AVITORCH,
        .natDexNum = NATIONAL_DEX_AVITORCH,
        .categoryName = _("Friendship"),
        .height = 3,
        .weight = 18,
        .description = COMPOUND_STRING(
            "Avitorch are very rare to find in the wild.\n"
            "It is said that those lucky enough to meet\n"
            "this Pokémon are blessed with everlasting\n"
            "bonds with their closest friends."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AvitorchCalm,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_AvitorchCalm,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SPRING,
        .palette = gMonPalette_AvitorchCalm,
        .shinyPalette = gMonShinyPalette_AvitorchCalm,
        .iconSprite = gMonIcon_AvitorchCalm,
        .iconPalIndex = 0,
        SHADOW(0, 12, SHADOW_SIZE_S)
        FOOTPRINT(Avitorch)
        OVERWORLD(
            sPicTable_Avitorch,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Avitorch,
            gShinyOverworldPalette_Avitorch
        )
        .levelUpLearnset = sAvitorchLevelUpLearnset,
        .teachableLearnset = sAvitorchTeachableLearnset,
        .eggMoveLearnset = sAvitorchEggMoveLearnset,
        .formSpeciesIdTable = sAvitorchFormSpeciesIdTable,
        .formChangeTable = sAvitorchFormChangeTable,
    },

    [SPECIES_AVITORCH_ENRAGED] =
    {
        .baseHP        = 120,
        .baseAttack    = 156,
        .baseDefense   = 64,
        .baseSpeed     = 69,
        .baseSpAttack  = 156,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 171,
        .evYield_HP  = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_PUNISHER, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Avitorch"),
        .cryId = CRY_AVITORCH,
        .natDexNum = NATIONAL_DEX_AVITORCH,
        .categoryName = _("Punishment"),
        .height = 3,
        .weight = 18,
        .description = COMPOUND_STRING(
            "Typically, Avitorch are seen as a serene\n"
            "and peaceful Pokémon said to bless people.\n"
            "If ever enraged, however, a terrifyingly\n"
            "strong, vengeful power awakens."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AvitorchEnraged,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_AvitorchEnraged,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_AvitorchEnraged,
        .shinyPalette = gMonShinyPalette_AvitorchEnraged,
        .iconSprite = gMonIcon_AvitorchEnraged,
        .iconPalIndex = 0,
        SHADOW(0, 12, SHADOW_SIZE_S)
        FOOTPRINT(Avitorch)
        .levelUpLearnset = sAvitorchLevelUpLearnset,
        .teachableLearnset = sAvitorchTeachableLearnset,
        .eggMoveLearnset = sAvitorchEggMoveLearnset,
        .formSpeciesIdTable = sAvitorchFormSpeciesIdTable,
        .formChangeTable = sAvitorchFormChangeTable,
    },

    [SPECIES_REGITUBE] =
    { 
        .baseHP        = 80,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 50,
        .baseSpAttack  = 150,
        .baseSpDefense = 150,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 3,
        .expYield = 290,
        .evYield_SpAttack  = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_BUOYANT_POWER, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Regitube"),
        .cryId = CRY_REGITUBE,
        .natDexNum = NATIONAL_DEX_REGITUBE,
        .categoryName = _("Inner Tube"),
        .height = 20,
        .weight = 25,
        .description = COMPOUND_STRING(
            "Not a single scientist can figure out why\n"
            "Regigigas decided to create its newest\n"
            "titan of terrifying aquatic power out of\n"
            "a pile of average beach inflatable tubes."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 493,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Regitube,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Regitube,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Regitube,
        .shinyPalette = gMonShinyPalette_Regitube,
        .iconSprite = gMonIcon_Regitube,
        .iconPalIndex = 0,
        SHADOW(2, 7, SHADOW_SIZE_L)
        FOOTPRINT(Regitube)
        OVERWORLD(
            sPicTable_Regitube,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Regitube,
            gShinyOverworldPalette_Regitube
        )
        .isLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRegitubeLevelUpLearnset,
        .teachableLearnset = sRegitubeTeachableLearnset,
    },

    [SPECIES_SLOWBRO_MEGA_G] =
    {
        .baseHP        = 95,
        .baseAttack    = 100,
        .baseDefense   = 95,
        .baseSpeed     = 30,
        .baseSpAttack  = 180,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_POISON, TYPE_PSYCHIC),
        .catchRate = 75,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_REACTIVE_FIRE, ABILITY_REACTIVE_FIRE, ABILITY_REACTIVE_FIRE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Slowbro"),
        .cryId = CRY_SLOWBRO_MEGA,
        .natDexNum = NATIONAL_DEX_SLOWBRO,
        .categoryName = _("Hermit Crab"),
        .height = 20,
        .weight = 865,
        .description = COMPOUND_STRING(
            "A recently discovered Mega Evolution when\n"
            "a Slowbro from Galar found a Slowbronite.\n"
            "The force of poisonous shots fired from\n"
            "its cannon can pierce through cargo ships."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 326,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_SlowbroMegaG,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SlowbroMegaG,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SlowbroMegaG,
        .shinyPalette = gMonShinyPalette_SlowbroMegaG,
        .iconSprite = gMonIcon_SlowbroMegaG,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 9, SHADOW_SIZE_L)
        FOOTPRINT(Slowbro)
        .isGalarianForm = TRUE,
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sSlowbroGalarLevelUpLearnset,
        .teachableLearnset = sSlowbroGalarTeachableLearnset,
        .formSpeciesIdTable = sSlowbroFormSpeciesIdTable,
        .formChangeTable = sSlowbroGalarFormChangeTable,
    },

    [SPECIES_CASTFORM_MEGA] =
    {
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 80,
        .baseSpeed     = 110,
        .baseSpAttack  = 120,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 145,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WEATHERMAN, ABILITY_WEATHERMAN, ABILITY_WEATHERMAN },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Castform"),
        .cryId = CRY_CASTFORM_MEGA,
        .natDexNum = NATIONAL_DEX_CASTFORM,
        .categoryName = _("Weather"),
        .height = 8,
        .weight = 12,
        .description = COMPOUND_STRING(
            "An experiment by an ex-Weather Institute\n"
            "employee to grant Castform the power he\n"
            "believes it should have. Mega Castform\n"
            "has complete control over weather."),
        .pokemonScale = 328,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CastformMega,
        .frontPicSize = MON_COORDS_SIZE(24, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 17,
        .backPic = gMonBackPic_CastformMega,
        .backPicSize = MON_COORDS_SIZE(32, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_CastformMega,
        .shinyPalette = gMonShinyPalette_CastformMega,
        .iconSprite = gMonIcon_CastformMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Castform)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sCastformLevelUpLearnset,
        .teachableLearnset = sCastformTeachableLearnset,
        .eggMoveLearnset = sCastformEggMoveLearnset,
        .formSpeciesIdTable = sCastformFormSpeciesIdTable,
        .formChangeTable = sCastformMegaFormChangeTable,
    },

    [SPECIES_CASTFORM_MEGA_SUNNY] =
    {
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 80,
        .baseSpeed     = 110,
        .baseSpAttack  = 120,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 145,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WEATHERMAN, ABILITY_WEATHERMAN, ABILITY_WEATHERMAN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Castform"),
        .cryId = CRY_CASTFORM_MEGA,
        .natDexNum = NATIONAL_DEX_CASTFORM,
        .categoryName = _("Weather"),
        .height = 8,
        .weight = 12,
        .description = COMPOUND_STRING(
            "When Mega Evolved, Sunny Form Castform's\n"
            "overwhelming heat causes everyone nearby\n"
            "to start sweating profusely as if it were\n"
            "a hot Summer day, even during Winter."),
        .pokemonScale = 328,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CastformMegaSunny,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_CastformMegaSunny,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_CastformMegaSunny,
        .shinyPalette = gMonShinyPalette_CastformMegaSunny,
        .iconSprite = gMonIcon_CastformMegaSunny,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_M)
        FOOTPRINT(Castform)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sCastformLevelUpLearnset,
        .teachableLearnset = sCastformTeachableLearnset,
        .eggMoveLearnset = sCastformEggMoveLearnset,
        .formSpeciesIdTable = sCastformFormSpeciesIdTable,
        .formChangeTable = sCastformMegaFormChangeTable,
    },

    [SPECIES_CASTFORM_MEGA_RAINY] =
    {
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 80,
        .baseSpeed     = 110,
        .baseSpAttack  = 120,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 145,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WEATHERMAN, ABILITY_WEATHERMAN, ABILITY_WEATHERMAN },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Castform"),
        .cryId = CRY_CASTFORM_MEGA,
        .natDexNum = NATIONAL_DEX_CASTFORM,
        .categoryName = _("Weather"),
        .height = 8,
        .weight = 12,
        .description = COMPOUND_STRING(
            "When Mega Evolved, Rainy Form Castform's\n"
            "immense rainstorms make those nearby feel\n"
            "like they are in the middle of a typhoon\n"
            "even if the sky was dry moments earlier."),
        .pokemonScale = 328,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CastformMegaRainy,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_CastformMegaRainy,
        .backPicSize = MON_COORDS_SIZE(40, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_CastformMegaRainy,
        .shinyPalette = gMonShinyPalette_CastformMegaRainy,
        .iconSprite = gMonIcon_CastformMegaRainy,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 9, SHADOW_SIZE_M)
        FOOTPRINT(Castform)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sCastformLevelUpLearnset,
        .teachableLearnset = sCastformTeachableLearnset,
        .eggMoveLearnset = sCastformEggMoveLearnset,
        .formSpeciesIdTable = sCastformFormSpeciesIdTable,
        .formChangeTable = sCastformMegaFormChangeTable,
    },

    [SPECIES_CASTFORM_MEGA_SNOWY] =
    {
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 80,
        .baseSpeed     = 110,
        .baseSpAttack  = 120,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 145,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WEATHERMAN, ABILITY_WEATHERMAN, ABILITY_WEATHERMAN },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Castform"),
        .cryId = CRY_CASTFORM_MEGA,
        .natDexNum = NATIONAL_DEX_CASTFORM,
        .categoryName = _("Weather"),
        .height = 8,
        .weight = 12,
        .description = COMPOUND_STRING(
            "When Mega Evolved, Snowy Form Castform's\n"
            "intense chills make those around it feel as\n"
            "if they were caught in a ferocious blizzard\n"
            "even on a hot Summer day."),
        .pokemonScale = 328,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CastformMegaSnowy,
        .frontPicSize = MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_CastformMegaSnowy,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_CastformMegaSnowy,
        .shinyPalette = gMonShinyPalette_CastformMegaSnowy,
        .iconSprite = gMonIcon_CastformMegaSnowy,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_M)
        FOOTPRINT(Castform)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sCastformLevelUpLearnset,
        .teachableLearnset = sCastformTeachableLearnset,
        .eggMoveLearnset = sCastformEggMoveLearnset,
        .formSpeciesIdTable = sCastformFormSpeciesIdTable,
        .formChangeTable = sCastformMegaFormChangeTable,
    },

    [SPECIES_CHARIZARD_MEGA_Z] =
    {
        .baseHP        = 78,
        .baseAttack    = 126,
        .baseDefense   = 88,
        .baseSpeed     = 126,
        .baseSpAttack  = 126,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GROUND),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 317 : 285,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_NEPOTISM, ABILITY_NEPOTISM, ABILITY_NEPOTISM },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Charizard"),
        .cryId = CRY_CHARIZARD_MEGA_Z,
        .natDexNum = NATIONAL_DEX_CHARIZARD,
        .categoryName = _("Flame"),
        .height = 17,
        .weight = 725,
        .description = COMPOUND_STRING(
            "\n"
            "How many Mega Evolutions does\n"
            "   Charizard even need???"),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_CharizardMegaZ,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CharizardMegaZ,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_CharizardMegaZ,
        .shinyPalette = gMonShinyPalette_CharizardMegaZ,
        .iconSprite = gMonIcon_CharizardMegaZ,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 5, SHADOW_SIZE_L)
        FOOTPRINT(Charizard)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sCharizardLevelUpLearnset,
        .teachableLearnset = sCharizardTeachableLearnset,
        .formSpeciesIdTable = sCharizardFormSpeciesIdTable,
        .formChangeTable = sCharizardMegaZFormChangeTable,
    },

    [SPECIES_CHARIZARD_OMEGA_Z] =
    {
        .baseHP        = 218,
        .baseAttack    = 126,
        .baseDefense   = 88,
        .baseSpeed     = 106,
        .baseSpAttack  = 126,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GROUND),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 317 : 285,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_NEPOTISM, ABILITY_NEPOTISM, ABILITY_NEPOTISM },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Charizard"),
        .cryId = CRY_CHARIZARD_OMEGA_Z,
        .natDexNum = NATIONAL_DEX_CHARIZARD,
        .categoryName = _("Flame"),
        .height = 17,
        .weight = 725,
        .description = COMPOUND_STRING(
            "\n"
            "Okay now this is just\n"
            " getting ridiculous."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_CharizardOmegaZ,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CharizardOmegaZ,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        .palette = gMonPalette_CharizardOmegaZ,
        .shinyPalette = gMonShinyPalette_CharizardOmegaZ,
        .iconSprite = gMonIcon_CharizardOmegaZ,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 5, SHADOW_SIZE_L)
        FOOTPRINT(Charizard)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sCharizardLevelUpLearnset,
        .teachableLearnset = sCharizardTeachableLearnset,
        .formSpeciesIdTable = sCharizardFormSpeciesIdTable,
        .formChangeTable = sCharizardFormChangeTable,
    },

    /*
    [SPECIES_NONE] =
    {
        .baseHP        = 1,
        .baseAttack    = 1,
        .baseDefense   = 1,
        .baseSpeed     = 1,
        .baseSpAttack  = 1,
        .baseSpDefense = 1,
        .types = MON_TYPES(TYPE_MYSTERY),
        .catchRate = 255,
        .expYield = 67,
        .evYield_HP = 1,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_NONE, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_None,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_CircledQuestionMark,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_CircledQuestionMarkF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .paletteFemale = gMonPalette_CircledQuestionMarkF,
        .shinyPaletteFemale = gMonShinyPalette_CircledQuestionMarkF,
        .iconSpriteFemale = gMonIcon_QuestionMarkF,
        .iconPalIndexFemale = 1,
#endif //P_GENDER_DIFFERENCES
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        FOOTPRINT(QuestionMark)
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 100, SPECIES_NONE},
                                {EVO_ITEM, ITEM_MOOMOO_MILK, SPECIES_NONE}),
        //.formSpeciesIdTable = sNoneFormSpeciesIdTable,
        //.formChangeTable = sNoneFormChangeTable,
        //.perfectIVCount = NUM_STATS,
    },
    */
};
