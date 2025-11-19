#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "test_runner.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "line_break.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"
#include "trainer_slide.h"
#include "battle_message.h"

static u32 BattlerHPPercentage(u32 battler, u32 operation, u32 threshold);
static u32 GetEnemyMonCount(u32 firstId, u32 lastId, bool32 onlyAlive);
static bool32 DoesTrainerHaveSlideMessage(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstCriticalHit(enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(u32 battler, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstSTABMove(u32 firstId, u32 lastId, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstDown(u32 firstId, u32 lastId);
static bool32 ShouldRunTrainerSlideEnemyMonUnaffected(u32 firstId, u32 lastId, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlideLastSwitchIn(u32 battler);
static bool32 ShouldRunTrainerSlideLastHalfHP(u32 firstId, u32 lastId, u32 battler);
static bool32 ShouldRunTrainerSlideLastLowHp(u32 firstId, u32 lastId, u32 battler);
static void SetTrainerSlideParamters(u32 battler, u32* firstId, u32* lastId, u32* trainerId, u32* retValue);
static bool32 IsSlideInitalizedOrPlayed(enum TrainerSlideType slideId);

static const u8* const sTrainerSlides[DIFFICULTY_COUNT][TRAINERS_COUNT][TRAINER_SLIDE_COUNT] =
{
    [DIFFICULTY_NORMAL] =
    {
        // Gym Leaders
        [TRAINER_ROXANNE_1] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Right in our weak spot!\nYou clearly know your type matchups!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("You've got me on the ropes!\nYou must have studied well!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_BRAWLY_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("I'm down to my last POKéMON?\nThat's gnarly!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_BRAWLY_2] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("I'm down to my last POKéMON?\nThat's gnarly!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_WATTSON_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Wahahahah!\nYou really are amusing!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_WATTSON_2] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Wahahahah!\nYou really are amusing!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_FLANNERY_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Uh oh…\nThis is looking bad!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_NORMAN_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("To think my own child has\npushed me this far…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Watch and learn, {PLAYER}!\nFeel the power of MEGA EVOLUTION!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_WINONA_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Our winds are faltering…\nBut I feel our second wind!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Come, SKARMORY!\nThe winds blow our way!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_TATE_AND_LIZA_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Our combination…\nIs being beaten…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("It's up to you, SLOWBRO…\nIt's up to you, SLOWBRO…{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_JUAN_1] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("It seems our dance is coming\nto a close.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("I won't give up yet!\nNow face our final illusion!{PAUSE_UNTIL_PRESS}"),
        },
        // Elite Four
        [TRAINER_SIDNEY] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("I can tell that you\nare the real deal!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("This is the last trick\nI've got up my sleeve!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_PHOEBE] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("I can feel the power of\nthe bonds you've cultivated.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Feel our bonds take form!\nSABLEYE, time to MEGA EVOLVE!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_GLACIA] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("The burning fire inside you\nis almost overwhelming…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Time to freeze you solid!\nIt's time, GLALIE!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_DRAKE] =
        {
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Even with my many years of\nexperience, you push through.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Our true power lies yet untouched!\nHave a taste of it now!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_STEVEN] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("That's the way!\nHit me with everything you have!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("I can't remember the last time\nsomeone had me on the ropes!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("METAGROSS! MEGA EVOLVE!\nLet's show why we're the CHAMPION!{PAUSE_UNTIL_PRESS}"),
        }
    },
};

static const u8* const sFrontierTrainerSlides[DIFFICULTY_COUNT][FRONTIER_TRAINERS_COUNT][TRAINER_SLIDE_COUNT] =
{
    [DIFFICULTY_NORMAL] =
    {
    },
};

static const u8* const sTestTrainerSlides[DIFFICULTY_COUNT][TRAINERS_COUNT][TRAINER_SLIDE_COUNT] =
{
#include "../test/battle/trainer_slides.h"
};

static u32 BattlerHPPercentage(u32 battler, u32 operation, u32 threshold)
{
    switch (operation)
    {
        case LESS_THAN:
            return gBattleMons[battler].hp < (gBattleMons[battler].maxHP / threshold);
        case EQUAL:
            return gBattleMons[battler].hp == (gBattleMons[battler].maxHP / threshold);
        case GREATER_THAN:
            return gBattleMons[battler].hp > (gBattleMons[battler].maxHP / threshold);
        case LESS_THAN_OR_EQUAL:
            return gBattleMons[battler].hp <= (gBattleMons[battler].maxHP / threshold);
        case GREATER_THAN_OR_EQUAL:
            return gBattleMons[battler].hp >= (gBattleMons[battler].maxHP / threshold);
        case NOT_EQUAL:
        default:
            return gBattleMons[battler].hp != (gBattleMons[battler].maxHP / threshold);
    }
}

static u32 GetEnemyMonCount(u32 firstId, u32 lastId, bool32 onlyAlive)
{
    u32 i, count = 0;

    for (i = firstId; i < lastId; i++)
    {
        u32 species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG, NULL);
        if (species != SPECIES_NONE
                && species != SPECIES_EGG
                && (!onlyAlive || GetMonData(&gEnemyParty[i], MON_DATA_HP, NULL)))
            count++;
    }

    return count;
}

static const u8* const *GetTrainerSlideArray(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId)
{
    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        return sFrontierTrainerSlides[difficulty][trainerId];
    else if (TESTING)
        return sTestTrainerSlides[difficulty][trainerId];
    else
        return sTrainerSlides[difficulty][trainerId];
}

static bool32 DoesTrainerHaveSlideMessage(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId)
{
    const u8* const *trainerSlides = GetTrainerSlideArray(difficulty, trainerId, slideId);
    const u8* const *trainerSlidesNormal = GetTrainerSlideArray(DIFFICULTY_NORMAL, trainerId, slideId);

    if (trainerSlides[slideId] == NULL)
        return (trainerSlidesNormal[slideId] != NULL);
    else
        return TRUE;
}

void SetTrainerSlideMessage(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId)
{
    const u8* const *trainerSlides = GetTrainerSlideArray(difficulty, trainerId, slideId);
    const u8* const *trainerSlidesNormal = GetTrainerSlideArray(DIFFICULTY_NORMAL, trainerId, slideId);

    if (trainerSlides[slideId] != NULL)
        gBattleStruct->trainerSlideMsg = trainerSlides[slideId];
    else
        gBattleStruct->trainerSlideMsg = trainerSlidesNormal[slideId];
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstCriticalHit(enum TrainerSlideType slideId)
{
    return IsTrainerSlideInitialized(slideId);
}

static bool32 ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(enum TrainerSlideType slideId)
{
    return IsTrainerSlideInitialized(slideId);
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(u32 battler, enum TrainerSlideType slideId)
{
    if (!IsTrainerSlideInitialized(slideId))
        return FALSE;

    if (!IsBattlerAlive(battler))
        return FALSE;

    return TRUE;
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstSTABMove(u32 firstId, u32 lastId, enum TrainerSlideType slideId)
{
    if (!IsTrainerSlideInitialized(slideId))
        return FALSE;

    if (GetEnemyMonCount(firstId, lastId, TRUE) != GetEnemyMonCount(firstId, lastId, FALSE))
        return FALSE;

    return TRUE;
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstDown(u32 firstId, u32 lastId)
{
    return ((GetEnemyMonCount(firstId, lastId, TRUE) == (GetEnemyMonCount(firstId, lastId, FALSE) - 1)));
}

static bool32 ShouldRunTrainerSlideEnemyMonUnaffected(u32 firstId, u32 lastId, enum TrainerSlideType slideId)
{
    if (!IsTrainerSlideInitialized(slideId))
        return FALSE;

    return (GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE));
}

static bool32 ShouldRunTrainerSlideLastSwitchIn(u32 battler)
{
    return !CanBattlerSwitch(battler);
}

static bool32 ShouldRunTrainerSlideLastHalfHP(u32 firstId, u32 lastId, u32 battler)
{
    if (GetEnemyMonCount(firstId, lastId, TRUE) != 1)
        return FALSE;

    if (BattlerHPPercentage(battler, GREATER_THAN, 2))
        return FALSE;

    return (BattlerHPPercentage(battler, GREATER_THAN, 4));
}

static bool32 ShouldRunTrainerSlideLastLowHp(u32 firstId, u32 lastId, u32 battler)
{
    if (GetEnemyMonCount(firstId, lastId, TRUE) != 1)
        return FALSE;

    return (BattlerHPPercentage(battler, LESS_THAN_OR_EQUAL, 4));
}

static void SetTrainerSlideParamters(u32 battler, u32* firstId, u32* lastId, u32* trainerId, u32* retValue)
{
    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        if (gBattlerPartyIndexes[battler] >= MULTI_PARTY_SIZE)
        {
            *firstId = MULTI_PARTY_SIZE;
            *lastId = PARTY_SIZE;
            *trainerId = SanitizeTrainerId(TRAINER_BATTLE_PARAM.opponentB);
            *retValue = TRAINER_SLIDE_TARGET_TRAINER_B;
        }
        else
        {
            *firstId = 0;
            *lastId = MULTI_PARTY_SIZE;
            *trainerId = SanitizeTrainerId(TRAINER_BATTLE_PARAM.opponentA);
        }
    }
    else
    {
        *firstId = 0;
        *lastId = PARTY_SIZE;
        *trainerId = SanitizeTrainerId(TRAINER_BATTLE_PARAM.opponentA);
    }
}

enum TrainerSlideTargets ShouldDoTrainerSlide(u32 battler, enum TrainerSlideType slideId)
{
    u32 firstId, lastId, trainerId;
    u32 retValue = TRAINER_SLIDE_TARGET_TRAINER_A;
    bool32 shouldRun = FALSE;

    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || IsOnPlayerSide(battler))
        return TRAINER_SLIDE_TARGET_NONE;

    SetTrainerSlideParamters(battler, &firstId, &lastId, &trainerId, &retValue);
    enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();

    gBattleScripting.battler = battler;

    if (IsTrainerSlidePlayed(slideId))
        return TRAINER_SLIDE_TARGET_NONE;

    if (!DoesTrainerHaveSlideMessage(difficulty,trainerId,slideId))
        return TRAINER_SLIDE_TARGET_NONE;

    switch (slideId)
    {
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstCriticalHit(slideId);
            break;
        case TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT:
            shouldRun = ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(slideId);
            break;
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(battler, slideId);
            break;
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstSTABMove(firstId, lastId, slideId);
            break;
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstDown(firstId, lastId);
            break;
        case TRAINER_SLIDE_ENEMY_MON_UNAFFECTED:
            shouldRun = ShouldRunTrainerSlideEnemyMonUnaffected(firstId, lastId, slideId);
            break;
        case TRAINER_SLIDE_LAST_SWITCHIN:
            shouldRun = ShouldRunTrainerSlideLastSwitchIn(battler);
            break;
        case TRAINER_SLIDE_LAST_HALF_HP:
            shouldRun = ShouldRunTrainerSlideLastHalfHP(firstId, lastId, battler);
            break;
        case TRAINER_SLIDE_LAST_LOW_HP:
            shouldRun = ShouldRunTrainerSlideLastLowHp(firstId, lastId, battler);
            break;
        case TRAINER_SLIDE_BEFORE_FIRST_TURN:
        case TRAINER_SLIDE_MEGA_EVOLUTION:
        case TRAINER_SLIDE_Z_MOVE:
        case TRAINER_SLIDE_DYNAMAX:
            shouldRun = TRUE;
            break;
        default:
            return TRAINER_SLIDE_TARGET_NONE;
    }

    if (shouldRun == FALSE)
        return TRAINER_SLIDE_TARGET_NONE;

    MarkTrainerSlideAsPlayed(slideId);
    SetTrainerSlideMessage(difficulty,trainerId,slideId);
    return retValue;
}

static bool32 IsSlideInitalizedOrPlayed(enum TrainerSlideType slideId)
{
    if (IsTrainerSlideInitialized(slideId))
        return TRUE;

    if (IsTrainerSlidePlayed(slideId))
        return TRUE;

    return FALSE;
}

void TryInitializeFirstSTABMoveTrainerSlide(u32 battlerDef, u32 battlerAtk, u32 moveType)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE;

    if (IsSlideInitalizedOrPlayed(slideId))
        return;

    if ((IsOnPlayerSide(battlerDef)))
        return;

    if (IS_BATTLER_OF_TYPE(battlerAtk, moveType) == FALSE)
        return;

    InitalizeTrainerSlide(slideId);
}

void TryInitializeTrainerSlidePlayerLandsFirstCriticalHit(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT;

    if (IsSlideInitalizedOrPlayed(slideId))
        return;

    if (IsOnPlayerSide(target))
        return;

    InitalizeTrainerSlide(slideId);
}

void TryInitializeTrainerSlideEnemyLandsFirstCriticalHit(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT;

    if (IsSlideInitalizedOrPlayed(slideId))
        return;

    if (!IsOnPlayerSide(target))
        return;

    InitalizeTrainerSlide(slideId);
}

void TryInitializeTrainerSlidePlayerLandsFirstSuperEffectiveHit(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT;

    if (IsSlideInitalizedOrPlayed(slideId))
        return;

    if (IsOnPlayerSide(target))
        return;

    InitalizeTrainerSlide(slideId);
}

void TryInitializeTrainerSlideEnemyMonUnaffected(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_ENEMY_MON_UNAFFECTED;

    if (IsSlideInitalizedOrPlayed(slideId))
        return;

    if (IsOnPlayerSide(target))
        return;

    InitalizeTrainerSlide(slideId);
}

bool32 IsTrainerSlideInitialized(enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    return (gBattleStruct->slideMessageStatus.messageInitalized[arrayIndex] & (1 << bitPosition)) != 0;
}

bool32 IsTrainerSlidePlayed(enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    return (gBattleStruct->slideMessageStatus.messagePlayed[arrayIndex] & (1 << bitPosition)) != 0;
}

void InitalizeTrainerSlide(enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    gBattleStruct->slideMessageStatus.messageInitalized[arrayIndex] |= (1 << bitPosition);
}

void MarkTrainerSlideAsPlayed(enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    gBattleStruct->slideMessageStatus.messagePlayed[arrayIndex] |= (1 << bitPosition);
}
