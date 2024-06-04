#include "global.h"
#include "palette.h"
#include "string_util.h"
#include "window.h"
#include "decompress.h"
#include "task.h"
#include "text.h"
#include "field_small_name_box.h"

#define SMALLNAMEBOX_TAG 0x4E45

//  Usage:
//  smallnamebox <text>  ->  displays the namebox with the given text
//  hidesmallnamebox     ->  hides the namebox

static void LoadSmallNameboxWindow(const struct WindowTemplate *window);
static void LoadSmallNameboxTilemap();
static void CreateTask_DisplaySmallNamebox();
static void Task_DisplaySmallNamebox(u8 taskId);
static void LoadSmallNameboxSprite(s8 x, s8 y);
static void LoadSmallNameboxSprite2(s8 x, s8 y);
static void AddTextPrinterForSmallName();
static void ClearSmallNameboxTiles();

static EWRAM_DATA u8 sSmallNameboxWindowId = 0;
static EWRAM_DATA u8 sSmallNameboxGfxId = 0;
static EWRAM_DATA u8 sSmallNameboxGfxId2 = 0;

static const u32 sSmallNamebox_Gfx[] = INCBIN_U32("graphics/text_window/small_name_box.4bpp.lz");
static const u16 sSmallNamebox_Pal[] = INCBIN_U16("graphics/text_window/name_box.gbapal");

static const struct OamData sOam_SmallNamebox =
{
    .x = 0,
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .tileNum = 1,
    .priority = 1,
    .paletteNum = 0,
};

static const struct OamData sOam_SmallNamebox2 =
{
    .x = 0,
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .tileNum = 1,
    .priority = 1,
    .paletteNum = 0,
};


static const struct CompressedSpriteSheet sSpriteSheet_SmallNamebox = {
    .data = sSmallNamebox_Gfx,
    .size = 2048,
    .tag = SMALLNAMEBOX_TAG,
};

static const union AnimCmd sSpriteAnim_SmallNamebox[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_SmallNamebox2[] = {
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_SmallNamebox[] = {
    sSpriteAnim_SmallNamebox,
};

static const union AnimCmd *const sSpriteAnimTable_SmallNamebox2[] = {
    sSpriteAnim_SmallNamebox2,
};

static const struct SpriteTemplate sSpriteTemplate_SmallNamebox = {
    .tileTag = SMALLNAMEBOX_TAG,
    .paletteTag = SMALLNAMEBOX_TAG,
    .oam = &sOam_SmallNamebox,
    .anims = sSpriteAnimTable_SmallNamebox,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_SmallNamebox2 = {
    .tileTag = SMALLNAMEBOX_TAG,
    .paletteTag = SMALLNAMEBOX_TAG,
    .oam = &sOam_SmallNamebox2,
    .anims = sSpriteAnimTable_SmallNamebox2,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpritePalette sSpritePalette_SmallNamebox = {
    .data = sSmallNamebox_Pal, 
    .tag = SMALLNAMEBOX_TAG,
};

static const struct WindowTemplate sSmallNamebox_WindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 0, 
    .tilemapTop = 12,
    .width = 16, 
    .height = 2,                //required to be at least two
    .paletteNum = 15,
    .baseBlock = 0x174          //placed before the msgbox tiles
};


void ShowFieldSmallName(const u8 *str) {
    if(IsSmallNameboxDisplayed())
            ClearSmallNamebox();
            
    LoadSmallNameboxWindow(&sSmallNamebox_WindowTemplate);
    StringExpandPlaceholders(gStringVar3, str);
    AddTextPrinterForSmallName();
    CreateTask_DisplaySmallNamebox();
}

bool8 IsSmallNameboxDisplayed() {
    if(sSmallNameboxWindowId == 0)
        return FALSE;
    return TRUE;
}

void ClearSmallNamebox() {
    ClearSmallNameboxTiles();
    RemoveWindow(sSmallNameboxWindowId);
    sSmallNameboxWindowId = 0;
    DestroySpriteAndFreeResources(&gSprites[sSmallNameboxGfxId]);
    DestroySpriteAndFreeResources(&gSprites[sSmallNameboxGfxId2]);
}


#define tTimer data[0]

static void CreateTask_DisplaySmallNamebox() {
    u8 taskId = CreateTask(Task_DisplaySmallNamebox, 0x50);
    gTasks[taskId].tTimer = 0x1;
}

static void Task_DisplaySmallNamebox(u8 taskId) {
    struct Task *task = &gTasks[taskId];
    
    if (gTasks[taskId].tTimer) 
        gTasks[taskId].tTimer--;
    else{
        LoadSmallNameboxTilemap();
        LoadSmallNameboxSprite(32, 111);
        LoadSmallNameboxSprite2(96, 111);
        
        DestroyTask(taskId);
    }
}

#undef tTimer


static void LoadSmallNameboxWindow(const struct WindowTemplate *window) {
    sSmallNameboxWindowId = AddWindow(window);
    
    CopyWindowToVram(sSmallNameboxWindowId, 3);
}

static void LoadSmallNameboxTilemap() {
    PutWindowTilemap(sSmallNameboxWindowId);
    LoadCompressedSpriteSheet(&sSpriteSheet_SmallNamebox);
    LoadSpritePalette(&sSpritePalette_SmallNamebox);
}

static void LoadSmallNameboxSprite(s8 x, s8 y) {
    u8 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_SmallNamebox, x, y, 0);
    if (sSmallNameboxGfxId == MAX_SPRITES)
        return;
    else
        sSmallNameboxGfxId = spriteId;
}

static void LoadSmallNameboxSprite2(s8 x, s8 y) {
    u8 spriteId2;

    spriteId2 = CreateSprite(&sSpriteTemplate_SmallNamebox2, x, y, 0);
    if (sSmallNameboxGfxId2 == MAX_SPRITES)
        return;
    else
        sSmallNameboxGfxId2 = spriteId2;
}

static void AddTextPrinterForSmallName() {
    struct TextPrinterTemplate printer;
    
    printer.currentChar = gStringVar3;
    printer.windowId = sSmallNameboxWindowId;
    printer.fontId = FONT_SMALL_SUBPIXEL; // Can use FONT_NARROW, etc, here.
    printer.x = 7; 
    printer.y = 4;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.fgColor = TEXT_COLOR_WHITE;
    printer.bgColor = TEXT_COLOR_TRANSPARENT;
    printer.shadowColor = TEXT_COLOR_TRANSPARENT;
    printer.unk = GetFontAttribute(1, FONTATTR_UNKNOWN);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;

    AddTextPrinter(&printer, 0xFF, NULL);
}

static void ClearSmallNameboxTiles(){
    ClearWindowTilemap(sSmallNameboxWindowId);
    FillWindowPixelBuffer(sSmallNameboxWindowId, PIXEL_FILL(0));
    CopyWindowToVram(sSmallNameboxWindowId, 3);
}
