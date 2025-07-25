#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokedex_area_screen.h"
#include "region_map.h"
#include "roamer.h"
#include "rtc.h"
#include "sound.h"
#include "string_util.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "pokedex_area_region_map.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "config/pokedex_plus_hgss.h"

// There are two types of indicators for the area screen to show where a Pokémon can occur:
// - Area glows, which highlight any of the maps in MAP_GROUP_TOWNS_AND_ROUTES that have the species.
//   These are a tilemap with colored rectangular areas that blends in and out. The positions of the
//   rectangles is determined by the positions of the matching MAPSEC values on the region map layout.
// - Area markers, which highlight any of the maps in MAP_GROUP_DUNGEONS or MAP_GROUP_SPECIAL_AREA that
//   have the species. These are circular sprites that flash twice. The positions of the sprites is
//   determined by the data for the corresponding MAPSEC in gRegionMapEntries.

// Only maps in the following map groups have their encounters considered for the area screen
#define MAP_GROUP_TOWNS_AND_ROUTES MAP_GROUP(MAP_PETALBURG_CITY)
#define MAP_GROUP_DUNGEONS MAP_GROUP(MAP_METEOR_FALLS_1F_1R)
#define MAP_GROUP_SPECIAL_AREA MAP_GROUP(MAP_SAFARI_ZONE_NORTHWEST)

#define AREA_SCREEN_WIDTH 32
#define AREA_SCREEN_HEIGHT 20

#define GLOW_FULL      0xFFFF
#define GLOW_EDGE_R    (1 << 0)
#define GLOW_EDGE_L    (1 << 1)
#define GLOW_EDGE_B    (1 << 2)
#define GLOW_EDGE_T    (1 << 3)
#define GLOW_CORNER_TL (1 << 4)
#define GLOW_CORNER_BL (1 << 5)
#define GLOW_CORNER_TR (1 << 6)
#define GLOW_CORNER_BR (1 << 7)

#define GLOW_PALETTE 10

#define TAG_AREA_MARKER 2
#define TAG_AREA_UNKNOWN 3

#define MAX_AREA_HIGHLIGHTS 64 // Maximum number of rectangular route highlights
#define MAX_AREA_MARKERS 32 // Maximum number of circular spot highlights

#define LABEL_WINDOW_BG 1
#define NUM_LABEL_WINDOWS 2

enum PokedexAreaLabels
{
    DEX_AREA_LABEL_TIME_OF_DAY,
    DEX_AREA_LABEL_AREA_UNKNOWN
};

struct OverworldArea
{
    u8 mapGroup;
    u8 mapNum;
    u16 regionMapSectionId;
};

struct
{
    /*0x000*/ void (*callback)(void); // unused
    /*0x004*/ MainCallback prev; // unused
    /*0x008*/ MainCallback next; // unused
    /*0x00C*/ u16 state; // unused
    /*0x00E*/ u16 species;
    /*0x010*/ struct OverworldArea overworldAreasWithMons[MAX_AREA_HIGHLIGHTS];
    /*0x110*/ u16 numOverworldAreas;
    /*0x112*/ u16 numSpecialAreas;
    /*0x114*/ u16 drawAreaGlowState;
    /*0x116*/ u16 areaGlowTilemap[AREA_SCREEN_WIDTH * AREA_SCREEN_HEIGHT];
    /*0x616*/ u16 markerTimer;
    /*0x618*/ u16 glowTimer;
    /*0x61A*/ u16 areaShadeBldArgLo;
    /*0x61C*/ u16 areaShadeBldArgHi;
    /*0x61E*/ bool8 showingMarkers;
    /*0x61F*/ u8 markerFlashCounter;
    /*0x620*/ u16 specialAreaRegionMapSectionIds[MAX_AREA_MARKERS];
    /*0x660*/ struct Sprite *areaMarkerSprites[MAX_AREA_MARKERS];
    /*0x6E0*/ u16 numAreaMarkerSprites;
    /*0x6E2*/ u16 alteringCaveCounter;
    /*0x6E4*/ u16 alteringCaveId;
    /*0x6E8*/ u8 *screenSwitchState;
    /*0x6EC*/ struct RegionMap regionMap;
    /*0xF70*/ u8 charBuffer[64];
    /*0xFB0*/ struct Sprite *areaUnknownSprites[3];
    /*0xFBC*/ u8 areaUnknownGraphicsBuffer[0x600];
    /*0xFC0*/ u8 areaScreenLabelIds[NUM_LABEL_WINDOWS];
    /*0xFC8*/ u8 areaState;
} static EWRAM_DATA *sPokedexAreaScreen = NULL;

EWRAM_DATA u8 gAreaTimeOfDay = 0;

static void FindMapsWithMon(u16);
static void BuildAreaGlowTilemap(void);
static void SetAreaHasMon(u16, u16);
static void SetSpecialMapHasMon(u16, u16);
static u16 GetRegionMapSectionId(u8, u8);
static bool8 MapHasSpecies(const struct WildEncounterTypes *, u16);
static bool8 MonListHasSpecies(const struct WildPokemonInfo *, u16, u16);
static void DoAreaGlow(void);
static void Task_ShowPokedexAreaScreen(u8 taskId);
static void Task_UpdatePokedexAreaScreen(u8 taskId);
static void CreateAreaMarkerSprites(void);
static void LoadAreaUnknownGraphics(void);
static void CreateAreaUnknownSprites(void);
static void Task_HandlePokedexAreaScreenInput(u8);
static void ResetPokedexAreaMapBg(void);
static void DestroyAreaScreenSprites(void);
static void AddTimeOfDayLabels(void);
static void ShowEncounterInfoLabel(void);
static void ShowAreaUnknownLabel(void);
static void PrintAreaLabelText(const u8 *text, enum PokedexAreaLabels labelId, int textXPos);
static void ClearAreaWindowLabel(enum PokedexAreaLabels labelId);

bool32 ShouldShowAreaUnknownLabel(void);

static const u32 sAreaGlow_Pal[] = INCBIN_U32("graphics/pokedex/area_glow.gbapal");
static const u32 sAreaGlow_Gfx[] = INCBIN_U32("graphics/pokedex/area_glow.4bpp.lz");

static const u32 sPokedexPlusHGSS_ScreenSelectBarSubmenu_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/SelectBar.bin.lz");
static void LoadHGSSScreenSelectBarSubmenu(void);

static const u16 sSpeciesHiddenFromAreaScreen[] = { SPECIES_WYNAUT };

static const u16 sMovingRegionMapSections[3] =
{
    MAPSEC_MARINE_CAVE,
    MAPSEC_UNDERWATER_MARINE_CAVE,
    MAPSEC_TERRA_CAVE
};

static const u16 sFeebasData[][3] =
{
    {SPECIES_FEEBAS, MAP_GROUP(MAP_ROUTE119), MAP_NUM(MAP_ROUTE119)},
    {NUM_SPECIES}
};

static const u16 sLandmarkData[][2] =
{
    {MAPSEC_SKY_PILLAR,       FLAG_LANDMARK_SKY_PILLAR},
    {MAPSEC_SEAFLOOR_CAVERN,  FLAG_LANDMARK_SEAFLOOR_CAVERN},
    {MAPSEC_ALTERING_CAVE,    FLAG_LANDMARK_ALTERING_CAVE},
    {MAPSEC_MIRAGE_TOWER,     FLAG_LANDMARK_MIRAGE_TOWER},
    {MAPSEC_DESERT_UNDERPASS, FLAG_LANDMARK_DESERT_UNDERPASS},
    {MAPSEC_ARTISAN_CAVE,     FLAG_LANDMARK_ARTISAN_CAVE},
    {MAPSEC_NAVEL_ROCK,       FLAG_ARRIVED_AT_NAVEL_ROCK},
    {MAPSEC_NONE}
};

#include "data/pokedex_area_glow.h"

static const struct PokedexAreaMapTemplate sPokedexAreaMapTemplate =
{
    .bg = 3,
    .offset = 0,
    .mode = 0,
    .unk = 2,
};

static const u8 sAreaMarkerTiles[];
static const struct SpriteSheet sAreaMarkerSpriteSheet =
{
    .data = sAreaMarkerTiles, .size = 0x80, .tag = TAG_AREA_MARKER
};

static const u16 sAreaMarkerPalette[];
static const struct SpritePalette sAreaMarkerSpritePalette =
{
    .data = sAreaMarkerPalette, .tag = TAG_AREA_MARKER
};

static const struct OamData sAreaMarkerOamData =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1
};

static const struct SpriteTemplate sAreaMarkerSpriteTemplate =
{
    .tileTag = TAG_AREA_MARKER,
    .paletteTag = TAG_AREA_MARKER,
    .oam = &sAreaMarkerOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const u16 sAreaMarkerPalette[] = INCBIN_U16("graphics/pokedex/area_marker.gbapal");
static const u8 sAreaMarkerTiles[] = INCBIN_U8("graphics/pokedex/area_marker.4bpp");

static const struct SpritePalette sAreaUnknownSpritePalette =
{
    .data = gPokedexAreaScreenAreaUnknown_Pal, .tag = TAG_AREA_UNKNOWN
};

static const struct OamData sAreaUnknownOamData =
{
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1
};

static const struct SpriteTemplate sAreaUnknownSpriteTemplate =
{
    .tileTag = TAG_AREA_UNKNOWN,
    .paletteTag = TAG_AREA_UNKNOWN,
    .oam = &sAreaUnknownOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const u8 sFontColor_AreaInfo[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, 5};
static const struct WindowTemplate sTimeOfDayWindowLabelTemplates[] =
{
    [DEX_AREA_LABEL_TIME_OF_DAY] =
    {
        .bg = LABEL_WINDOW_BG,
        .tilemapLeft = 22,
        .tilemapTop = 18,
        .width = 8,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x16C
    },

    [DEX_AREA_LABEL_AREA_UNKNOWN] = 
    {
        .bg = LABEL_WINDOW_BG,
        .tilemapLeft = 12,
        .tilemapTop = 18,
        .width = 10,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x240
    }
};

static void ResetDrawAreaGlowState(void)
{
    sPokedexAreaScreen->drawAreaGlowState = 0;
}

static bool8 DrawAreaGlow(void)
{
    switch (sPokedexAreaScreen->drawAreaGlowState)
    {
    case 0:
        FindMapsWithMon(sPokedexAreaScreen->species);
        break;
    case 1:
        BuildAreaGlowTilemap();
        break;
    case 2:
        DecompressAndCopyTileDataToVram(2, sAreaGlow_Gfx, 0, 0, 0);
        LoadBgTilemap(2, sPokedexAreaScreen->areaGlowTilemap, sizeof(sPokedexAreaScreen->areaGlowTilemap), 0);
        break;
    case 3:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            CpuCopy32(sAreaGlow_Pal, &gPlttBufferUnfaded[BG_PLTT_ID(GLOW_PALETTE)], sizeof(sAreaGlow_Pal));
            sPokedexAreaScreen->drawAreaGlowState++;
        }
        return TRUE;
    case 4:
        ChangeBgY(2, -BG_SCREEN_SIZE, BG_COORD_SET);
        break;
    default:
        return FALSE;
    }

    sPokedexAreaScreen->drawAreaGlowState++;
    return TRUE;
}

static void FindMapsWithMon(u16 species)
{
    u16 i;
    struct Roamer *roamer;

    sPokedexAreaScreen->alteringCaveCounter = 0;
    sPokedexAreaScreen->alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
    if (sPokedexAreaScreen->alteringCaveId >= NUM_ALTERING_CAVE_TABLES)
        sPokedexAreaScreen->alteringCaveId = 0;

    sPokedexAreaScreen->numOverworldAreas = 0;
    sPokedexAreaScreen->numSpecialAreas = 0;

    // Check if this species should be hidden from the area map.
    // This only applies to Wynaut, to hide the encounters on Mirage Island.
    for (i = 0; i < ARRAY_COUNT(sSpeciesHiddenFromAreaScreen); i++)
    {
        if (sSpeciesHiddenFromAreaScreen[i] == species)
            return;
    }

    // Add Pokémon with special encounter circumstances (i.e. not listed
    // in the regular wild encounter table) to the area map.
    // This only applies to Feebas on Route 119, but it was clearly set
    // up to allow handling others.
    for (i = 0; sFeebasData[i][0] != NUM_SPECIES; i++)
    {
        if (species == sFeebasData[i][0])
        {
            switch (sFeebasData[i][1])
            {
            case MAP_GROUP_TOWNS_AND_ROUTES:
                SetAreaHasMon(sFeebasData[i][1], sFeebasData[i][2]);
                break;
            case MAP_GROUP_DUNGEONS:
            case MAP_GROUP_SPECIAL_AREA:
                SetSpecialMapHasMon(sFeebasData[i][1], sFeebasData[i][2]);
                break;
            }
        }
    }

    // Add regular species to the area map
    for (i = 0; gWildMonHeaders[i].mapGroup != MAP_GROUP(MAP_UNDEFINED); i++)
    {
        if (MapHasSpecies(&gWildMonHeaders[i].encounterTypes[gAreaTimeOfDay], species))
        {
            switch (gWildMonHeaders[i].mapGroup)
            {
            case MAP_GROUP_TOWNS_AND_ROUTES:
                SetAreaHasMon(gWildMonHeaders[i].mapGroup, gWildMonHeaders[i].mapNum);
                break;
            case MAP_GROUP_DUNGEONS:
            case MAP_GROUP_SPECIAL_AREA:
                SetSpecialMapHasMon(gWildMonHeaders[i].mapGroup, gWildMonHeaders[i].mapNum);
                break;
            }
        }
    }

    // Add roamers to the area map
    for (i = 0; i < ROAMER_COUNT; i++)
    {
        roamer = &gSaveBlock1Ptr->roamer[i];
        if (species == roamer->species && roamer->active)
        {
            // This is a roamer's species, show where this roamer is currently
            struct OverworldArea *roamerLocation = &sPokedexAreaScreen->overworldAreasWithMons[sPokedexAreaScreen->numOverworldAreas];
            GetRoamerLocation(i, &roamerLocation->mapGroup, &roamerLocation->mapNum);
            roamerLocation->regionMapSectionId = Overworld_GetMapHeaderByGroupAndId(roamerLocation->mapGroup, roamerLocation->mapNum)->regionMapSectionId;
            sPokedexAreaScreen->numOverworldAreas++;
        }
    }
}

static void SetAreaHasMon(u16 mapGroup, u16 mapNum)
{
    if (sPokedexAreaScreen->numOverworldAreas < MAX_AREA_HIGHLIGHTS)
    {
        sPokedexAreaScreen->overworldAreasWithMons[sPokedexAreaScreen->numOverworldAreas].mapGroup = mapGroup;
        sPokedexAreaScreen->overworldAreasWithMons[sPokedexAreaScreen->numOverworldAreas].mapNum = mapNum;
        sPokedexAreaScreen->overworldAreasWithMons[sPokedexAreaScreen->numOverworldAreas].regionMapSectionId = CorrectSpecialMapSecId(Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->regionMapSectionId);
        sPokedexAreaScreen->numOverworldAreas++;
    }
}

static void SetSpecialMapHasMon(u16 mapGroup, u16 mapNum)
{
    int i;

    if (sPokedexAreaScreen->numSpecialAreas < MAX_AREA_MARKERS)
    {
        u16 regionMapSectionId = GetRegionMapSectionId(mapGroup, mapNum);
        if (regionMapSectionId < MAPSEC_NONE)
        {
            // Don't highlight the area if it's a moving area (Marine/Terra Cave)
            for (i = 0; i < ARRAY_COUNT(sMovingRegionMapSections); i++)
            {
                if (regionMapSectionId == sMovingRegionMapSections[i])
                    return;
            }

            // Don't highlight the area if it's an undiscovered landmark (e.g. Sky Pillar)
            for (i = 0; sLandmarkData[i][0] != MAPSEC_NONE; i++)
            {
                if (regionMapSectionId == sLandmarkData[i][0] && !FlagGet(sLandmarkData[i][1]))
                    return;
            }

            // Check if this special area is already being tracked
            for (i = 0; i < sPokedexAreaScreen->numSpecialAreas; i++)
            {
                if (sPokedexAreaScreen->specialAreaRegionMapSectionIds[i] == regionMapSectionId)
                    break;
            }

            if (i == sPokedexAreaScreen->numSpecialAreas)
            {
                // New special area
                sPokedexAreaScreen->specialAreaRegionMapSectionIds[i] = regionMapSectionId;
                sPokedexAreaScreen->numSpecialAreas++;
            }
        }
    }
}

static u16 GetRegionMapSectionId(u8 mapGroup, u8 mapNum)
{
    return Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->regionMapSectionId;
}

static bool8 MapHasSpecies(const struct WildEncounterTypes *info, u16 species)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    u8 currentMapGroup = gWildMonHeaders[headerId].mapGroup;
    u8 currentMapNum = gWildMonHeaders[headerId].mapNum;
    // If this is a header for Altering Cave, skip it if it's not the current Altering Cave encounter set
    if (GetRegionMapSectionId(currentMapGroup, currentMapNum) == MAPSEC_ALTERING_CAVE)
    {
        sPokedexAreaScreen->alteringCaveCounter++;
        if (sPokedexAreaScreen->alteringCaveCounter != sPokedexAreaScreen->alteringCaveId + 1)
            return FALSE;
    }

    if (MonListHasSpecies(info->landMonsInfo, species, LAND_WILD_COUNT))
        return TRUE;
    if (MonListHasSpecies(info->waterMonsInfo, species, WATER_WILD_COUNT))
        return TRUE;
// When searching the fishing encounters, this incorrectly uses the size of the land encounters.
// As a result it's reading out of bounds of the fishing encounters tables.
#ifdef BUGFIX
    if (MonListHasSpecies(info->fishingMonsInfo, species, FISH_WILD_COUNT))
#else
    if (MonListHasSpecies(info->fishingMonsInfo, species, LAND_WILD_COUNT))
#endif
        return TRUE;
    if (MonListHasSpecies(info->rockSmashMonsInfo, species, ROCK_WILD_COUNT))
        return TRUE;
    return FALSE;
}

static bool8 MonListHasSpecies(const struct WildPokemonInfo *info, u16 species, u16 size)
{
    u16 i;
    if (info != NULL)
    {
        for (i = 0; i < size; i++)
        {
            if (info->wildPokemon[i].species == species)
                return TRUE;
        }
    }
    return FALSE;
}

static void BuildAreaGlowTilemap(void)
{
    u16 i, y, x, j;

    // Reset tilemap
    for (i = 0; i < ARRAY_COUNT(sPokedexAreaScreen->areaGlowTilemap); i++)
        sPokedexAreaScreen->areaGlowTilemap[i] = 0;

    // For each area with this species, scan the region map layout and find any locations that have a matching mapsec.
    // Add a "full glow" indicator for these matching spaces.
    for (i = 0; i < sPokedexAreaScreen->numOverworldAreas; i++)
    {
        j = 0;
        for (y = 0; y < AREA_SCREEN_HEIGHT; y++)
        {
            for (x = 0; x < AREA_SCREEN_WIDTH; x++)
            {
                if (GetRegionMapSecIdAt(x, y) == sPokedexAreaScreen->overworldAreasWithMons[i].regionMapSectionId)
                    sPokedexAreaScreen->areaGlowTilemap[j] = GLOW_FULL;
                j++;
            }
        }
    }

    // Scan the tilemap. For every "full glow" indicator added above, fill in its edges and corners.
    j = 0;
    for (y = 0; y < AREA_SCREEN_HEIGHT; y++)
    {
        for (x = 0; x < AREA_SCREEN_WIDTH; x++)
        {
            if (sPokedexAreaScreen->areaGlowTilemap[j] == GLOW_FULL)
            {
                // The "tile != GLOW_FULL" check is pointless in all of these conditionals,
                // since there's no harm in OR'ing 0xFFFF with anything else.

                // Edges
                if (x != 0 && sPokedexAreaScreen->areaGlowTilemap[j - 1] != GLOW_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j - 1] |= GLOW_EDGE_L;
                if (x != AREA_SCREEN_WIDTH - 1 && sPokedexAreaScreen->areaGlowTilemap[j + 1] != GLOW_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j + 1] |= GLOW_EDGE_R;
                if (y != 0 && sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH] != GLOW_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH] |= GLOW_EDGE_T;
                if (y != AREA_SCREEN_HEIGHT - 1 && sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH] != GLOW_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH] |= GLOW_EDGE_B;

                // Corners
                if (x != 0 && y != 0 && sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH - 1] != GLOW_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH - 1] |= GLOW_CORNER_TL;
                if (x != AREA_SCREEN_WIDTH - 1 && y != 0 && sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH + 1] != GLOW_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j - AREA_SCREEN_WIDTH + 1] |= GLOW_CORNER_TR;
                if (x != 0 && y != AREA_SCREEN_HEIGHT - 1 && sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH - 1] != GLOW_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH - 1] |= GLOW_CORNER_BL;
                if (x != AREA_SCREEN_WIDTH - 1 && y != AREA_SCREEN_HEIGHT - 1 && sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH + 1] != GLOW_FULL)
                    sPokedexAreaScreen->areaGlowTilemap[j + AREA_SCREEN_WIDTH + 1] |= GLOW_CORNER_BR;
            }

            j++;
        }
    }

    // Scan the tilemap again. Replace the "full tile" indicators with the actual tile id,
    // and remove corner flags when they're overlapped by an edge.
    for (i = 0; i < ARRAY_COUNT(sPokedexAreaScreen->areaGlowTilemap); i++)
    {
        if (sPokedexAreaScreen->areaGlowTilemap[i] == GLOW_FULL)
        {
            sPokedexAreaScreen->areaGlowTilemap[i] = GLOW_TILE_FULL;
            sPokedexAreaScreen->areaGlowTilemap[i] |= (GLOW_PALETTE << 12);
        }
        else if (sPokedexAreaScreen->areaGlowTilemap[i])
        {
            // Get rid of overlapping flags.
            // This is pointless, as sAreaGlowTilemapMapping can handle overlaps.
            if (sPokedexAreaScreen->areaGlowTilemap[i] & GLOW_EDGE_L)
                sPokedexAreaScreen->areaGlowTilemap[i] &= ~(GLOW_CORNER_TL | GLOW_CORNER_BL);
            if (sPokedexAreaScreen->areaGlowTilemap[i] & GLOW_EDGE_R)
                sPokedexAreaScreen->areaGlowTilemap[i] &= ~(GLOW_CORNER_TR | GLOW_CORNER_BR);
            if (sPokedexAreaScreen->areaGlowTilemap[i] & GLOW_EDGE_T)
                sPokedexAreaScreen->areaGlowTilemap[i] &= ~(GLOW_CORNER_TR | GLOW_CORNER_TL);
            if (sPokedexAreaScreen->areaGlowTilemap[i] & GLOW_EDGE_B)
                sPokedexAreaScreen->areaGlowTilemap[i] &= ~(GLOW_CORNER_BR | GLOW_CORNER_BL);

            // Assign tile id
            sPokedexAreaScreen->areaGlowTilemap[i] = sAreaGlowTilemapMapping[sPokedexAreaScreen->areaGlowTilemap[i]];
            sPokedexAreaScreen->areaGlowTilemap[i] |= (GLOW_PALETTE << 12);
        }
    }
}

static void StartAreaGlow(void)
{
    if (sPokedexAreaScreen->numSpecialAreas && sPokedexAreaScreen->numOverworldAreas == 0)
        sPokedexAreaScreen->showingMarkers = TRUE;
    else
        sPokedexAreaScreen->showingMarkers = FALSE;

    sPokedexAreaScreen->markerTimer = 0;
    sPokedexAreaScreen->glowTimer = 0;
    sPokedexAreaScreen->areaShadeBldArgLo = 0;
    sPokedexAreaScreen->areaShadeBldArgHi = 64;
    sPokedexAreaScreen->markerFlashCounter = 1;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    DoAreaGlow();
}

static void DoAreaGlow(void)
{
    u16 x, y;
    u16 i;

    if (!sPokedexAreaScreen->showingMarkers)
    {
        // Showing area glow
        if (sPokedexAreaScreen->markerTimer == 0)
        {
            sPokedexAreaScreen->glowTimer++;
            if (sPokedexAreaScreen->glowTimer & 1)
                sPokedexAreaScreen->areaShadeBldArgLo = (sPokedexAreaScreen->areaShadeBldArgLo + 4) & 0x7f;
            else
                sPokedexAreaScreen->areaShadeBldArgHi = (sPokedexAreaScreen->areaShadeBldArgHi + 4) & 0x7f;

            x = gSineTable[sPokedexAreaScreen->areaShadeBldArgLo] >> 4;
            y = gSineTable[sPokedexAreaScreen->areaShadeBldArgHi] >> 4;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(x, y));
            sPokedexAreaScreen->markerTimer = 0;
            if (sPokedexAreaScreen->glowTimer == 64)
            {
                // Done glowing, reset and try to switch to the special area markers
                sPokedexAreaScreen->glowTimer = 0;
                if (sPokedexAreaScreen->numSpecialAreas != 0)
                    sPokedexAreaScreen->showingMarkers = TRUE;
            }
        }
        else
            sPokedexAreaScreen->markerTimer--;
    }
    else
    {
        // Showing special area markers
        sPokedexAreaScreen->markerTimer++;
        if (sPokedexAreaScreen->markerTimer > 12)
        {
            sPokedexAreaScreen->markerTimer = 0;

            // Flash the marker
            // With a max of 4, the marker will disappear twice
            sPokedexAreaScreen->markerFlashCounter++;
            for (i = 0; i < sPokedexAreaScreen->numSpecialAreas; i++)
                sPokedexAreaScreen->areaMarkerSprites[i]->invisible = sPokedexAreaScreen->markerFlashCounter & 1;

            if (sPokedexAreaScreen->markerFlashCounter > 4)
            {
                // Done flashing, reset and try to switch to the area glow
                sPokedexAreaScreen->markerFlashCounter = 1;
                if (sPokedexAreaScreen->numOverworldAreas != 0)
                    sPokedexAreaScreen->showingMarkers = FALSE;
            }
        }
    }
}

static const u8 *GetTimeOfDayTextWithButton(enum TimeOfDay timeOfDay)
{
    static const u8 gText_Morning[] = _("{DPAD_UPDOWN} MORNING");
    static const u8 gText_Day[] = _("{DPAD_UPDOWN} DAY");
    static const u8 gText_Evening[] = _("{DPAD_UPDOWN} EVENING");
    static const u8 gText_Night[] = _("{DPAD_UPDOWN} NIGHT");

    switch (gAreaTimeOfDay)
    {
    case TIME_MORNING:
        return gText_Morning;
    case TIME_EVENING:
        return gText_Evening;
    case TIME_NIGHT:
        return gText_Night;
    case TIME_DAY:
    default:
        return gText_Day;
    }
}

static void AddTimeOfDayLabels(void)
{
    u32 i;

    // clear the background before adding any more windows
    RemoveAllWindowsOnBg(LABEL_WINDOW_BG);

    for (i = 0; i < NUM_LABEL_WINDOWS; i ++)
    {
        sPokedexAreaScreen->areaScreenLabelIds[i] = AddWindow(&sTimeOfDayWindowLabelTemplates[i]);
        FillWindowPixelBuffer(sPokedexAreaScreen->areaScreenLabelIds[i], PIXEL_FILL(0));
    }
}

static void ShowEncounterInfoLabel(void)
{
    const u8 *gText_TimeOfDay = GetTimeOfDayTextWithButton(gAreaTimeOfDay);
    int stringXPos = GetStringCenterAlignXOffset(FONT_NORMAL, gText_TimeOfDay, 64);

    PrintAreaLabelText(gText_TimeOfDay, DEX_AREA_LABEL_TIME_OF_DAY, stringXPos);
}

static void ShowAreaUnknownLabel(void)
{
    static const u8 gText_AreaUnknown[] = _("AREA UNKNOWN");
    int stringXPos = GetStringCenterAlignXOffset(FONT_NORMAL, gText_AreaUnknown, 80);

    PrintAreaLabelText(gText_AreaUnknown, DEX_AREA_LABEL_AREA_UNKNOWN, stringXPos);
}

static void ClearAreaWindowLabel(enum PokedexAreaLabels labelId)
{
    FillWindowPixelBuffer(sPokedexAreaScreen->areaScreenLabelIds[labelId], PIXEL_FILL(0));
    ClearWindowTilemap(sPokedexAreaScreen->areaScreenLabelIds[labelId]);
    ScheduleBgCopyTilemapToVram(0);
}

static void PrintAreaLabelText(const u8 *text, enum PokedexAreaLabels labelId, int textXPos)
{
    ClearAreaWindowLabel(labelId);

    PutWindowTilemap(sPokedexAreaScreen->areaScreenLabelIds[labelId]);
    FillWindowPixelBuffer(sPokedexAreaScreen->areaScreenLabelIds[labelId], PIXEL_FILL(7));

    AddTextPrinterParameterized4(sPokedexAreaScreen->areaScreenLabelIds[labelId], FONT_NORMAL, textXPos, 0, 0, 0, sFontColor_AreaInfo, TEXT_SKIP_DRAW, text);
    CopyWindowToVram(sPokedexAreaScreen->areaScreenLabelIds[labelId], COPYWIN_FULL);
}

bool32 ShouldShowAreaUnknownLabel(void)
{
    return !sPokedexAreaScreen->numOverworldAreas && !sPokedexAreaScreen->numSpecialAreas;
}

#define tState data[0]

void DisplayPokedexAreaScreen(u16 species, u8 *screenSwitchState, enum TimeOfDay timeOfDay, enum PokedexAreaScreenState areaState)
{
    u8 taskId;

    sPokedexAreaScreen = AllocZeroed(sizeof(*sPokedexAreaScreen));
    sPokedexAreaScreen->species = species;
    sPokedexAreaScreen->screenSwitchState = screenSwitchState;
    sPokedexAreaScreen->areaState = areaState;
    gAreaTimeOfDay = timeOfDay;
    screenSwitchState[0] = 0;

    if (sPokedexAreaScreen->areaState == DEX_UPDATE_AREA_SCREEN)
        taskId = CreateTask(Task_UpdatePokedexAreaScreen, 0);
    else
        taskId = CreateTask(Task_ShowPokedexAreaScreen, 0);

    gTasks[taskId].tState = 0;
}

static void Task_ShowPokedexAreaScreen(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        ResetSpriteData();
        FreeAllSpritePalettes();
        HideBg(3);
        HideBg(2);
        HideBg(0);
        break;
    case 1:
        SetBgAttribute(3, BG_ATTR_CHARBASEINDEX, 3);
        LoadPokedexAreaMapGfx(&sPokedexAreaMapTemplate);
        StringFill(sPokedexAreaScreen->charBuffer, CHAR_SPACE, 16);
        break;
    case 2:
        if (TryShowPokedexAreaMap() == TRUE)
            return;
        PokedexAreaMapChangeBgY(-8);
        break;
    case 3:
        ResetDrawAreaGlowState();
        break;
    case 4:
        if (DrawAreaGlow())
            return;
        break;
    case 5:
        ShowRegionMapForPokedexAreaScreen(&sPokedexAreaScreen->regionMap);
        CreateRegionMapPlayerIcon(1, 1);
        PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(0, -8);
        break;
    case 6:
        CreateAreaMarkerSprites();
        break;
    case 7:
        if(!OW_TIME_OF_DAY_ENCOUNTERS)
            LoadAreaUnknownGraphics();
        break;
    case 8:
        if(!OW_TIME_OF_DAY_ENCOUNTERS)
            CreateAreaUnknownSprites();
        break;
    case 9:
        BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 16, 0, RGB_BLACK);
        break;
    case 10:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_ALL);
        StartAreaGlow();
        if (OW_TIME_OF_DAY_ENCOUNTERS)
        {
            AddTimeOfDayLabels();
            ShowEncounterInfoLabel();
            if (ShouldShowAreaUnknownLabel())
                ShowAreaUnknownLabel();
            DoScheduledBgTilemapCopiesToVram();
        }
        if (POKEDEX_PLUS_HGSS)
            LoadHGSSScreenSelectBarSubmenu();
        ShowBg(2);
        ShowBg(3); // TryShowPokedexAreaMap will have done this already
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON);
        break;
    case 11:
        gTasks[taskId].func = Task_HandlePokedexAreaScreenInput;
        gTasks[taskId].tState = 0;
        return;
    }

    gTasks[taskId].tState++;
}

static void Task_UpdatePokedexAreaScreen(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        ClearAreaWindowLabel(DEX_AREA_LABEL_TIME_OF_DAY);
        ClearAreaWindowLabel(DEX_AREA_LABEL_AREA_UNKNOWN);
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetDrawAreaGlowState();
        HideBg(2);
        HideBg(0);
        break;
    case 1:
        SetBgAttribute(3, BG_ATTR_CHARBASEINDEX, 3);
        LoadPokedexAreaMapGfx(&sPokedexAreaMapTemplate);
        PokedexAreaMapChangeBgY(-8);
        StringFill(sPokedexAreaScreen->charBuffer, CHAR_SPACE, 16);
        break;
    case 2:
        if (TryShowPokedexAreaMap() == TRUE)
            return;
        break;
    case 3:
        if (DrawAreaGlow())
            return;
        break;
    case 4:
        ShowRegionMapForPokedexAreaScreen(&sPokedexAreaScreen->regionMap);
        CreateRegionMapPlayerIcon(1, 1);
        PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(0, -8);
        CreateAreaMarkerSprites();
        break;
    case 5:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_ALL);
        StartAreaGlow();
        AddTimeOfDayLabels();
        ShowEncounterInfoLabel();
        if (ShouldShowAreaUnknownLabel())
            ShowAreaUnknownLabel();
        ShowBg(2);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON);
        break;
    case 6:
        gTasks[taskId].func = Task_HandlePokedexAreaScreenInput;
        gTasks[taskId].tState = 0;
        return;
    }

    gTasks[taskId].tState++;
}

static void Task_HandlePokedexAreaScreenInput(u8 taskId)
{
    DoAreaGlow();
    switch (gTasks[taskId].tState)
    {
    default:
        gTasks[taskId].tState = 0;
        // fall through
    case 0:
        if (gPaletteFade.active)
            return;
        break;
    case 1:
        if (JOY_NEW(B_BUTTON))
        {
            gTasks[taskId].data[1] = 1;
            PlaySE(SE_DEX_PAGE);
        }
        else if (JOY_NEW(DPAD_LEFT) || (JOY_NEW(L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            gTasks[taskId].data[1] = 1;
            PlaySE(SE_DEX_PAGE);
        }
        else if (JOY_NEW(DPAD_RIGHT) || (JOY_NEW(R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(sPokedexAreaScreen->species), FLAG_GET_CAUGHT))
            {
                PlaySE(SE_FAILURE);
                return;
            }
            gTasks[taskId].data[1] = 2;
            PlaySE(SE_DEX_PAGE);
        }
        else if (JOY_NEW(DPAD_UP) && OW_TIME_OF_DAY_ENCOUNTERS == TRUE)
        {
            gTasks[taskId].data[1] = 3;
            gAreaTimeOfDay = TryDecrementTimeOfDay(gAreaTimeOfDay);
            sPokedexAreaScreen->areaState = DEX_UPDATE_AREA_SCREEN;
            PlaySE(SE_DEX_PAGE);
        }
        else if (JOY_NEW(DPAD_DOWN) && OW_TIME_OF_DAY_ENCOUNTERS == TRUE)
        {
            gTasks[taskId].data[1] = 3;
            gAreaTimeOfDay = TryIncrementTimeOfDay(gAreaTimeOfDay);
            sPokedexAreaScreen->areaState = DEX_UPDATE_AREA_SCREEN;
            PlaySE(SE_DEX_PAGE);
        }
        else
        {
            // screen needs to fade if its doing anything except updating the area screen
            sPokedexAreaScreen->areaState = DEX_SHOW_AREA_SCREEN;
            return;
        }
        break;
    case 2:
        if (sPokedexAreaScreen->areaState != DEX_UPDATE_AREA_SCREEN)
            BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0, 16, RGB_BLACK);
        break;
    case 3:
        if (gPaletteFade.active)
            return;
        DestroyAreaScreenSprites();
        if (OW_TIME_OF_DAY_ENCOUNTERS)
        {
            ClearAreaWindowLabel(DEX_AREA_LABEL_TIME_OF_DAY);
            ClearAreaWindowLabel(DEX_AREA_LABEL_AREA_UNKNOWN);
            RemoveAllWindowsOnBg(LABEL_WINDOW_BG);
        }

        sPokedexAreaScreen->screenSwitchState[0] = gTasks[taskId].data[1];
        ResetPokedexAreaMapBg();
        DestroyTask(taskId);
        FreePokedexAreaMapBgNum();
        FREE_AND_SET_NULL(sPokedexAreaScreen);
        return;
    }

    gTasks[taskId].tState++;
}

static void ResetPokedexAreaMapBg(void)
{
    SetBgAttribute(3, BG_ATTR_CHARBASEINDEX, 0);
    SetBgAttribute(3, BG_ATTR_PALETTEMODE, 0);
}

// Creates the circular sprites to highlight special areas (like caves) where a Pokémon can be found
static void CreateAreaMarkerSprites(void)
{
    u8 spriteId;
    s16 x;
    s16 y;
    s16 i;
    s16 mapSecId;
    s16 numSprites;

    LoadSpriteSheet(&sAreaMarkerSpriteSheet);
    LoadSpritePalette(&sAreaMarkerSpritePalette);
    numSprites = 0;
    for (i = 0; i < sPokedexAreaScreen->numSpecialAreas; i++)
    {
        mapSecId = sPokedexAreaScreen->specialAreaRegionMapSectionIds[i];
        x = 8 * (gRegionMapEntries[mapSecId].x + 1) + 4;
        y = 8 * (gRegionMapEntries[mapSecId].y) + 28;
        x += 4 * (gRegionMapEntries[mapSecId].width - 1);
        y += 4 * (gRegionMapEntries[mapSecId].height - 1);
        spriteId = CreateSprite(&sAreaMarkerSpriteTemplate, x, y, 0);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].invisible = TRUE;
            sPokedexAreaScreen->areaMarkerSprites[numSprites++] = &gSprites[spriteId];
        }
    }

    sPokedexAreaScreen->numAreaMarkerSprites = numSprites;
}

static void DestroyAreaScreenSprites(void)
{
    u16 i;

    // Destroy area marker sprites
    FreeSpriteTilesByTag(TAG_AREA_MARKER);
    FreeSpritePaletteByTag(TAG_AREA_MARKER);
    for (i = 0; i < sPokedexAreaScreen->numAreaMarkerSprites; i++)
        DestroySprite(sPokedexAreaScreen->areaMarkerSprites[i]);

    if (!OW_TIME_OF_DAY_ENCOUNTERS)
    {
        // Destroy "Area Unknown" sprites
        FreeSpriteTilesByTag(TAG_AREA_UNKNOWN);
        FreeSpritePaletteByTag(TAG_AREA_UNKNOWN);
        for (i = 0; i < ARRAY_COUNT(sPokedexAreaScreen->areaUnknownSprites); i++)
        {
            if (sPokedexAreaScreen->areaUnknownSprites[i])
                DestroySprite(sPokedexAreaScreen->areaUnknownSprites[i]);
        }
    }
}

static void LoadAreaUnknownGraphics(void)
{
    struct SpriteSheet spriteSheet = {
        .data = sPokedexAreaScreen->areaUnknownGraphicsBuffer,
        .size = sizeof(sPokedexAreaScreen->areaUnknownGraphicsBuffer),
        .tag = TAG_AREA_UNKNOWN,
    };
    LZ77UnCompWram(gPokedexAreaScreenAreaUnknown_Gfx, sPokedexAreaScreen->areaUnknownGraphicsBuffer);
    LoadSpriteSheet(&spriteSheet);
    LoadSpritePalette(&sAreaUnknownSpritePalette);
}

static void CreateAreaUnknownSprites(void)
{
    u16 i;

    if (sPokedexAreaScreen->numOverworldAreas || sPokedexAreaScreen->numSpecialAreas)
    {
        // The current species is present on the map, don't create any "Area Unknown" sprites
        for (i = 0; i < ARRAY_COUNT(sPokedexAreaScreen->areaUnknownSprites); i++)
            sPokedexAreaScreen->areaUnknownSprites[i] = NULL;
    }
    else
    {
        // The current species is absent on the map, try to create "Area Unknown" sprites
        for (i = 0; i < ARRAY_COUNT(sPokedexAreaScreen->areaUnknownSprites); i++)
        {
            u8 spriteId = CreateSprite(&sAreaUnknownSpriteTemplate, i * 32 + 160, 140, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].oam.tileNum += i * 16;
                sPokedexAreaScreen->areaUnknownSprites[i] = &gSprites[spriteId];
            }
            else
            {
                // Failed to create sprite
                sPokedexAreaScreen->areaUnknownSprites[i] = NULL;
            }
        }
    }
}

static void LoadHGSSScreenSelectBarSubmenu(void)
{
    CopyToBgTilemapBuffer(1, sPokedexPlusHGSS_ScreenSelectBarSubmenu_Tilemap, 0, 0);
    CopyBgTilemapBufferToVram(1);
}
