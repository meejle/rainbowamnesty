#include "global.h"
#include "blit.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "constants/mugshots.h"

#define MUGSHOT_PALETTE_NUM 13

struct Mugshot{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32* image;
    const u16* palette;
};

void DrawMugshot(void); //VAR_0x8000 = mugshot id
void DrawMugshotAtPos(void); //VAR_0x8000 = mugshot id, VAR_0x8001 = x, VAR_0x8002 = y
void ClearMugshot(void);


// Rank Insignia
static const u32 sMugshotImg_WhiteBand[] = INCBIN_U32("graphics/mugshots/WhiteBand.4bpp.lz");
static const u16 sMugshotPal_WhiteBand[] = INCBIN_U16("graphics/mugshots/WhiteBand.gbapal");
static const u32 sMugshotImg_RedGem[] = INCBIN_U32("graphics/mugshots/RedGem.4bpp.lz");
static const u16 sMugshotPal_RedGem[] = INCBIN_U16("graphics/mugshots/RedGem.gbapal");
static const u32 sMugshotImg_OrangeGem[] = INCBIN_U32("graphics/mugshots/OrangeGem.4bpp.lz");
static const u16 sMugshotPal_OrangeGem[] = INCBIN_U16("graphics/mugshots/OrangeGem.gbapal");
static const u32 sMugshotImg_YellowGem[] = INCBIN_U32("graphics/mugshots/YellowGem.4bpp.lz");
static const u16 sMugshotPal_YellowGem[] = INCBIN_U16("graphics/mugshots/YellowGem.gbapal");
static const u32 sMugshotImg_GreenGem[] = INCBIN_U32("graphics/mugshots/GreenGem.4bpp.lz");
static const u16 sMugshotPal_GreenGem[] = INCBIN_U16("graphics/mugshots/GreenGem.gbapal");
static const u32 sMugshotImg_BlueGem[] = INCBIN_U32("graphics/mugshots/BlueGem.4bpp.lz");
static const u16 sMugshotPal_BlueGem[] = INCBIN_U16("graphics/mugshots/BlueGem.gbapal");
static const u32 sMugshotImg_IndigoGem[] = INCBIN_U32("graphics/mugshots/IndigoGem.4bpp.lz");
static const u16 sMugshotPal_IndigoGem[] = INCBIN_U16("graphics/mugshots/IndigoGem.gbapal");
static const u32 sMugshotImg_VioletGem[] = INCBIN_U32("graphics/mugshots/VioletGem.4bpp.lz");
static const u16 sMugshotPal_VioletGem[] = INCBIN_U16("graphics/mugshots/VioletGem.gbapal");
static const u32 sMugshotImg_GoldRing[] = INCBIN_U32("graphics/mugshots/GoldRing.4bpp.lz");
static const u16 sMugshotPal_GoldRing[] = INCBIN_U16("graphics/mugshots/GoldRing.gbapal");


static const struct Mugshot sMugshots[] = {
    // Rank Insignia
    [MUGSHOT_WHITEBAND] = {.x = 19, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_WhiteBand, .palette = sMugshotPal_WhiteBand},
    [MUGSHOT_REDGEM] = {.x = 19, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_RedGem, .palette = sMugshotPal_RedGem},
    [MUGSHOT_ORANGEGEM] = {.x = 19, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_OrangeGem, .palette = sMugshotPal_OrangeGem},
    [MUGSHOT_YELLOWGEM] = {.x = 19, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_YellowGem, .palette = sMugshotPal_YellowGem},
    [MUGSHOT_GREENGEM] = {.x = 19, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_GreenGem, .palette = sMugshotPal_GreenGem},
    [MUGSHOT_BLUEGEM] = {.x = 19, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_BlueGem, .palette = sMugshotPal_BlueGem},
    [MUGSHOT_INDIGOGEM] = {.x = 19, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_IndigoGem, .palette = sMugshotPal_IndigoGem},
    [MUGSHOT_VIOLETGEM] = {.x = 19, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_VioletGem, .palette = sMugshotPal_VioletGem},
    [MUGSHOT_GOLDRING] = {.x = 19, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_GoldRing, .palette = sMugshotPal_GoldRing},
};


//WindowId + 1, 0 if window is not open
static EWRAM_DATA u8 sMugshotWindow = 0;

void ClearMugshot(void){
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

static void DrawMugshotCore(const struct Mugshot* const mugshot, int x, int y){
    struct WindowTemplate t;
    u16 windowId;
    
    if(sMugshotWindow != 0){
        ClearMugshot();
    }
    
    #if GAME_VERSION==VERSION_EMERALD
    SetWindowTemplateFields(&t, 0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #else
    t = SetWindowTemplateFields(0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #endif
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
    
    LoadPalette(mugshot->palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    CopyToWindowPixelBuffer(windowId, (const void*)mugshot->image, 0, 0);
    PutWindowRectTilemap(windowId, 0, 0, mugshot->width/8, mugshot->height/8);
    CopyWindowToVram(windowId, 3);
}

void DrawMugshot(void){
    const struct Mugshot* const mugshot = sMugshots + VarGet(VAR_0x8000);
    DrawMugshotCore(mugshot, mugshot->x, mugshot->y);
}

void DrawMugshotAtPos(void){
    DrawMugshotCore(sMugshots + VarGet(VAR_0x8000), VarGet(VAR_0x8001), VarGet(VAR_0x8002));
}
