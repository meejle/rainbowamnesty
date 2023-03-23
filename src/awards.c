#include "global.h"
#include "awards.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"

struct Medal {
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32* image;
    const u16* palette;
};


// Set up colour palettes for award medals


// Set up award text strings and associated medal graphics
static const u32 sAwardGfx_Unknown_Medal[] = INCBIN_U32("graphics/awards/medals/unknown.4bpp.lz");
static const u16 sAwardPal_Unknown_Medal[] = INCBIN_U16("graphics/awards/medals/unknown.gbapal");
static const u8  sAwardTxt_Unknown_Title[] = _("Unknown\nAward");
static const u8  sAwardTxt_Unknown_Blurb[] = _("???");

static const u32 sAwardGfx_Dummy_Medal[] = INCBIN_U32("graphics/awards/medals/dummy.4bpp.lz");
static const u16 sAwardPal_Dummy_Medal[] = INCBIN_U16("graphics/awards/medals/dummy.gbapal");
static const u8  sAwardTxt_Dummy_Title[] = _("Expert\nNegotiator");
static const u8  sAwardTxt_Dummy_Blurb[] = _("Recruit at least\n3 Evil Team Grunts\nto your cause.");


// Set up the medal graphics again, because GBA development is funnnnnnn~
// They also need to be #defined in include/awards.h
static const struct Medal sAwardGfx_Medals[] = {
    [MEDAL_UNKNOWN] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Unknown_Medal, .palette = sAwardPal_Unknown_Medal},
    [MEDAL_DUMMY] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Dummy_Medal, .palette = sAwardPal_Dummy_Medal}
};


// Set up other misc. text strings
static const u8 sButtonTxt[] = _("{DPAD_NONE} Select   {B_BUTTON} Exit");
static const u8 sProgressTxt_Dummy[] = _("0 of 151 earned");


// Set up suffixes
static const u8 sSuffix_ed[] = _("ed");
static const u8 sSuffix_d[] = _("d");
static const u8 sSuffix_ve[] = _("ve");
static const u8 sSuffix_ught[] = _("ught");
static const u8 sSuffix_tch[] = _("tch");
static const u8 sSuffix_ind[] = _("ind");
static const u8 sSuffix_ound[] = _("ound");
static const u8 sSuffix_ome[] = _("ome");
static const u8 sSuffix_ame[] = _("ame");


// Set up scrollbars and cursor
static void SpriteCB_ScrollBar(struct Sprite *sprite);
static void SpriteCB_Cursor(struct Sprite *sprite);
#define TAG_AWARDS_UI 4096 // Tile and pal tag used for all UI sprites
static const u16 sPal_Ui[] = INCBIN_U16("graphics/awards/bgui.gbapal");
const u32 gGfx_Ui[] = INCBIN_U32("graphics/awards/ui.4bpp.lz");
static u8 spriteId;
static const struct OamData sOamData_ScrollBar =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};
static const struct OamData sOamData_Cursor =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sSpriteAnim_ScrollBar[] =
{
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_Cursor[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_JUMP(0)
};
static const union AnimCmd *const sSpriteAnimTable_ScrollBar[] =
{
    sSpriteAnim_ScrollBar
};
static const union AnimCmd *const sSpriteAnimTable_Cursor[] =
{
    sSpriteAnim_Cursor
};
static const struct CompressedSpriteSheet sSpriteSheet_ScrollBar[] =
{
    {
        .data = gGfx_Ui,
        .size = 0x0800,
        .tag = TAG_AWARDS_UI
    },
    {}
};
static const struct CompressedSpriteSheet sSpriteSheet_Cursor[] =
{
    {
        .data = gGfx_Ui,
        .size = 0x0800,
        .tag = TAG_AWARDS_UI
    },
    {}
};
static const struct SpritePalette sSpritePalettes_ScrollBar[] =
{
    {
        .data = sPal_Ui,
        .tag = TAG_AWARDS_UI
    },
    {},
};
static const struct SpritePalette sSpritePalettes_Cursor[] =
{
    {
        .data = sPal_Ui,
        .tag = TAG_AWARDS_UI
    },
    {},
};
static const struct SpriteTemplate sSpriteTemplate_ScrollBar =
{
    .tileTag = TAG_AWARDS_UI,
    .paletteTag = TAG_AWARDS_UI,
    .oam = &sOamData_ScrollBar,
    .anims = sSpriteAnimTable_ScrollBar,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ScrollBar
};
static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = TAG_AWARDS_UI,
    .paletteTag = TAG_AWARDS_UI,
    .oam = &sOamData_Cursor,
    .anims = sSpriteAnimTable_Cursor,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Cursor
};


struct AwardsResources
{
    MainCallback savedCallback;
    u8 gfxLoadState;
};

enum WindowIds
{
    WINDOW_BUTTON,
    WINDOW_SELECTED,
    WINDOW_PROGRESS,
    WINDOW_MEDALS
};

static EWRAM_DATA struct AwardsResources *sAwardsDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static void Awards_RunSetup(void);
static bool8 Awards_DoGfxSetup(void);
static bool8 Awards_InitBgs(void);
static void Awards_FadeAndBail(void);
static bool8 Awards_LoadGraphics(void);
static void Awards_InitWindows(void);
static void CreateUISprites(void);
static void PrintToButtonWindow(u8 windowId, u8 colorIdx);
static void PrintToSelectedWindow(u8 windowId, u8 colorIdx);
static void PrintToProgressWindow(u8 windowId, u8 colorIdx);
static void PrintToMedalsWindow(u8 windowId, u8 colorIdx);
static void Task_AwardsWaitFadeIn(u8 taskId);
static void Task_AwardsMain(u8 taskId);

static const struct BgTemplate sAwardsBgTemplates[] =
{
    {
        // Windows and UI
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }, 
    {
        // Background
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .priority = 0
    }
};

static const struct WindowTemplate sAwardsWindowTemplates[] = 
{
    [WINDOW_BUTTON] = 
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 18,
        .width = 15,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [WINDOW_SELECTED] = 
    {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 7,
        .width = 11,
        .height = 9,
        .paletteNum = 15,
        .baseBlock = 50
    },
    [WINDOW_PROGRESS] = 
    {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 18,
        .width = 11,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 150
    },
    [WINDOW_MEDALS] = 
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 5,
        .width = 13,
        .height = 13,
        .paletteNum = 15,
        .baseBlock = 200
    }
};

static const u32 sAwardsBgTiles[] = INCBIN_U32("graphics/awards/bg.4bpp.lz");
static const u32 sAwardsBgTilemap[] = INCBIN_U32("graphics/awards/bg.bin.lz");
static const u16 sAwardsBgUiPalette[] = INCBIN_U16("graphics/awards/bgui.gbapal");

enum Colors
{
    FONT_WHITE_WITH_SHADOW,
    FONT_WHITE_WITHOUT_SHADOW,
    FONT_ORANGE_WITH_SHADOW
};
static const u8 sAwardsWindowFontColors[][3] = 
{
    [FONT_WHITE_WITH_SHADOW]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,     TEXT_COLOR_DARK_GRAY},
    [FONT_WHITE_WITHOUT_SHADOW] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,     TEXT_COLOR_TRANSPARENT},
    [FONT_ORANGE_WITH_SHADOW]   = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_DARK_GRAY}
};

void Task_OpenAwardsFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        Awards_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// Main initialization function to call the Awards screen from elsewhere
void Awards_Init(MainCallback callback)
{
    if ((sAwardsDataPtr = AllocZeroed(sizeof(struct AwardsResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    // initialize stuff
    sAwardsDataPtr->gfxLoadState = 0;
    sAwardsDataPtr->savedCallback = callback;
    
    SetMainCallback2(Awards_RunSetup);
}

static void Awards_RunSetup(void)
{
    while (1)
    {
        if (Awards_DoGfxSetup() == TRUE)
            break;
    }
}

static void Awards_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Awards_VBlankCB(void)
{
    AnimateSprites();
    BuildOamBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 Awards_DoGfxSetup(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (Awards_InitBgs())
        {
            sAwardsDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            Awards_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (Awards_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        LoadMessageBoxAndBorderGfx();
        Awards_InitWindows();
        gMain.state++;
        break;
    case 5:
        PrintToButtonWindow(WINDOW_BUTTON, FONT_WHITE_WITHOUT_SHADOW);
        PrintToSelectedWindow(WINDOW_SELECTED, FONT_ORANGE_WITH_SHADOW);
        PrintToProgressWindow(WINDOW_PROGRESS, FONT_WHITE_WITH_SHADOW);
        PrintToMedalsWindow(WINDOW_MEDALS, FONT_WHITE_WITHOUT_SHADOW);
        taskId = CreateTask(Task_AwardsWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(Awards_VBlankCB);
        SetMainCallback2(Awards_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Awards_FreeResources(void)
{
    try_free(sAwardsDataPtr);
    try_free(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
}


static void Task_AwardsWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sAwardsDataPtr->savedCallback);
        Awards_FreeResources();
        DestroyTask(taskId);
    }
}

static void Awards_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_AwardsWaitFadeAndBail, 0);
    SetVBlankCallback(Awards_VBlankCB);
    SetMainCallback2(Awards_MainCB);
}

static bool8 Awards_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;
    
    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sAwardsBgTemplates, NELEMS(sAwardsBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 Awards_LoadGraphics(void)
{
    switch (sAwardsDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sAwardsBgTiles, 0, 0, 0);
        sAwardsDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sAwardsBgTilemap, sBg1TilemapBuffer);
            sAwardsDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sAwardsBgUiPalette, 0, 32);
        sAwardsDataPtr->gfxLoadState++;
        break;
    default:
        sAwardsDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void Awards_InitWindows(void)
{
    u32 i;

    InitWindows(sAwardsWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);

    FillWindowPixelBuffer(WINDOW_BUTTON, 0);
    LoadUserWindowBorderGfx(WINDOW_BUTTON, 720, 14 * 16);
    PutWindowTilemap(WINDOW_BUTTON);
    CopyWindowToVram(WINDOW_BUTTON, 3);

    FillWindowPixelBuffer(WINDOW_SELECTED, 0);
    LoadUserWindowBorderGfx(WINDOW_SELECTED, 720, 14 * 16);
    PutWindowTilemap(WINDOW_SELECTED);
    CopyWindowToVram(WINDOW_SELECTED, 3);

    FillWindowPixelBuffer(WINDOW_PROGRESS, 0);
    LoadUserWindowBorderGfx(WINDOW_PROGRESS, 720, 14 * 16);
    PutWindowTilemap(WINDOW_PROGRESS);
    CopyWindowToVram(WINDOW_PROGRESS, 3);

    FillWindowPixelBuffer(WINDOW_MEDALS, 0);
    LoadUserWindowBorderGfx(WINDOW_MEDALS, 720, 14 * 16);
    PutWindowTilemap(WINDOW_MEDALS);
    CopyWindowToVram(WINDOW_MEDALS, 3);

//  Unsure if I'll ever need this, but it "corrupts" the background tilemap somehow...    
//  ScheduleBgCopyTilemapToVram(2);
}

static void CreateUISprites(void)
{
    LoadCompressedSpriteSheet(&sSpriteSheet_ScrollBar[0]);
    LoadSpritePalettes(sSpritePalettes_ScrollBar);
    spriteId = CreateSprite(&sSpriteTemplate_ScrollBar, 134, 44, 2);

    LoadCompressedSpriteSheet(&sSpriteSheet_Cursor[0]);
    LoadSpritePalettes(sSpritePalettes_Cursor);
    spriteId = CreateSprite(&sSpriteTemplate_Cursor, 45, 58, 2);
}

static void SpriteCB_ScrollBar(struct Sprite *sprite)
{
    // Doesn't do anything yet
}

static void SpriteCB_Cursor(struct Sprite *sprite)
{
    // Doesn't do anything yet
}

static void PrintToButtonWindow(u8 windowId, u8 colorIdx)
{
    // Offset the text printer (relative to the window edge)
    u8 x = 19;
    u8 y = 1;
    
    FillWindowPixelBuffer(WINDOW_BUTTON, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WINDOW_BUTTON, 10, x, y, 0, 0, sAwardsWindowFontColors[colorIdx], 0xFF, sButtonTxt);
    PutWindowTilemap(WINDOW_BUTTON);
    CopyWindowToVram(WINDOW_BUTTON, 3);
}

static void PrintToSelectedWindow(u8 windowId, u8 colorIdx)
{
    // Offset the text printer (relative to the window edge)
    u8 x = 6;
    u8 y = 5;
    
    FillWindowPixelBuffer(WINDOW_SELECTED, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WINDOW_SELECTED, 0, x, y, 0, 0, sAwardsWindowFontColors[colorIdx], 0xFF, sAwardTxt_Unknown_Title);
    AddTextPrinterParameterized4(WINDOW_SELECTED, 0, x, y + 26, 0, 0, sAwardsWindowFontColors[FONT_WHITE_WITH_SHADOW], 0xFF, sAwardTxt_Unknown_Blurb);
    PutWindowTilemap(WINDOW_SELECTED);
    CopyWindowToVram(WINDOW_SELECTED, 3);
}

static void PrintToProgressWindow(u8 windowId, u8 colorIdx)
{
    // Offset the text printer (relative to the window edge)
    u8 x = 6;
    u8 y = 1;
    
    FillWindowPixelBuffer(WINDOW_PROGRESS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WINDOW_PROGRESS, 0, x, y, 0, 0, sAwardsWindowFontColors[colorIdx], 0xFF, sProgressTxt_Dummy);
    PutWindowTilemap(WINDOW_PROGRESS);
    CopyWindowToVram(WINDOW_PROGRESS, 3);
}

static void PrintToMedalsWindow(u8 windowId, u8 colorIdx)
{
    FillWindowPixelBuffer(WINDOW_MEDALS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    CreateUISprites();
    PutWindowTilemap(WINDOW_MEDALS);
    CopyWindowToVram(WINDOW_MEDALS, 3);
}

static void Task_AwardsWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_AwardsMain;
}

static void Task_AwardsTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sAwardsDataPtr->savedCallback);
        Awards_FreeResources();
        DestroyTask(taskId);
    }
}


/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_AwardsMain(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_AwardsTurnOff;
    }
}



