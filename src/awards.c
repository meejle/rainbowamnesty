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


// Set up the number of awards
#define AWARDS_COUNT 151

static const u16 sTheAwards[AWARDS_COUNT] =
{
    AWARD_001,
    AWARD_002,
    AWARD_003,
    AWARD_004,
    AWARD_005,
    AWARD_006,
    AWARD_007,
    AWARD_008,
    AWARD_009,
    AWARD_010,
    AWARD_011,
    AWARD_012,
    AWARD_013,
    AWARD_014,
    AWARD_015,
    AWARD_016,
    AWARD_017,
    AWARD_018,
    AWARD_019,
    AWARD_020,
    AWARD_021,
    AWARD_022,
    AWARD_023,
    AWARD_024,
    AWARD_025,
    AWARD_026,
    AWARD_027,
    AWARD_028,
    AWARD_029,
    AWARD_030,
    AWARD_031,
    AWARD_032,
    AWARD_033,
    AWARD_034,
    AWARD_035,
    AWARD_036,
    AWARD_037,
    AWARD_038,
    AWARD_039,
    AWARD_040,
    AWARD_041,
    AWARD_042,
    AWARD_043,
    AWARD_044,
    AWARD_045,
    AWARD_046,
    AWARD_047,
    AWARD_048,
    AWARD_049,
    AWARD_050,
    AWARD_051,
    AWARD_052,
    AWARD_053,
    AWARD_054,
    AWARD_055,
    AWARD_056,
    AWARD_057,
    AWARD_058,
    AWARD_059,
    AWARD_060,
    AWARD_061,
    AWARD_062,
    AWARD_063,
    AWARD_064,
    AWARD_065,
    AWARD_066,
    AWARD_067,
    AWARD_068,
    AWARD_069,
    AWARD_070,
    AWARD_071,
    AWARD_072,
    AWARD_073,
    AWARD_074,
    AWARD_075,
    AWARD_076,
    AWARD_077,
    AWARD_078,
    AWARD_079,
    AWARD_080,
    AWARD_081,
    AWARD_082,
    AWARD_083,
    AWARD_084,
    AWARD_085,
    AWARD_086,
    AWARD_087,
    AWARD_088,
    AWARD_089,
    AWARD_090,
    AWARD_091,
    AWARD_092,
    AWARD_093,
    AWARD_094,
    AWARD_095,
    AWARD_096,
    AWARD_097,
    AWARD_098,
    AWARD_099,
    AWARD_100,
    AWARD_101,
    AWARD_102,
    AWARD_103,
    AWARD_104,
    AWARD_105,
    AWARD_106,
    AWARD_107,
    AWARD_108,
    AWARD_109,
    AWARD_110,
    AWARD_111,
    AWARD_112,
    AWARD_113,
    AWARD_114,
    AWARD_115,
    AWARD_116,
    AWARD_117,
    AWARD_118,
    AWARD_119,
    AWARD_120,
    AWARD_121,
    AWARD_122,
    AWARD_123,
    AWARD_124,
    AWARD_125,
    AWARD_126,
    AWARD_127,
    AWARD_128,
    AWARD_129,
    AWARD_130,
    AWARD_131,
    AWARD_132,
    AWARD_133,
    AWARD_134,
    AWARD_135,
    AWARD_136,
    AWARD_137,
    AWARD_138,
    AWARD_139,
    AWARD_140,
    AWARD_141,
    AWARD_142,
    AWARD_143,
    AWARD_144,
    AWARD_145,
    AWARD_146,
    AWARD_147,
    AWARD_148,
    AWARD_149,
    AWARD_150,
    AWARD_151
};


// Set up colour palettes for award medals
static const u16 sAwardPal_Unknown_Medal[] = INCBIN_U16("graphics/awards/medals/unknown.gbapal");
static const u16 sAwardPal_Dummy_Medal[] = INCBIN_U16("graphics/awards/medals/dummy.gbapal");


// Set up award text strings and associated medal graphics
// Easy awards

// Unknown Award
static const u32 sAwardGfx_Unknown_Medal[] = INCBIN_U32("graphics/awards/medals/unknown.4bpp.lz");
static const u8  sAwardTxt_Unknown_Title[] = _("Unknown\nAward");
static const u8  sAwardTxt_Unknown_Blurb[] = _("???");

// Dummy Award
static const u32 sAwardGfx_Dummy_Medal[] = INCBIN_U32("graphics/awards/medals/dummy.4bpp.lz");
static const u8  sAwardTxt_Dummy_Title[] = _("Expert\nNegotiator");
static const u8  sAwardTxt_Dummy_Blurb[] = _("Recruit at least\n3 Evil Team Grunts\nto your cause.");

// Award 001 - ???
static const u32 sAwardGfx_Medal001[] = INCBIN_U32("graphics/awards/medals/001.4bpp.lz");
static const u8  sAwardTxt_Title001[] = _("001: ???");
static const u8  sAwardTxt_Blurb001[] = _("???");

// Award 002 - ???
static const u32 sAwardGfx_Medal002[] = INCBIN_U32("graphics/awards/medals/002.4bpp.lz");
static const u8  sAwardTxt_Title002[] = _("002: ???");
static const u8  sAwardTxt_Blurb002[] = _("???");

// Award 003 - ???
static const u32 sAwardGfx_Medal003[] = INCBIN_U32("graphics/awards/medals/003.4bpp.lz");
static const u8  sAwardTxt_Title003[] = _("003: ???");
static const u8  sAwardTxt_Blurb003[] = _("???");

// Award 004 - ???
static const u32 sAwardGfx_Medal004[] = INCBIN_U32("graphics/awards/medals/004.4bpp.lz");
static const u8  sAwardTxt_Title004[] = _("004: ???");
static const u8  sAwardTxt_Blurb004[] = _("???");

// Award 005 - ???
static const u32 sAwardGfx_Medal005[] = INCBIN_U32("graphics/awards/medals/005.4bpp.lz");
static const u8  sAwardTxt_Title005[] = _("005: ???");
static const u8  sAwardTxt_Blurb005[] = _("???");

// Award 006 - ???
static const u32 sAwardGfx_Medal006[] = INCBIN_U32("graphics/awards/medals/006.4bpp.lz");
static const u8  sAwardTxt_Title006[] = _("006: ???");
static const u8  sAwardTxt_Blurb006[] = _("???");

// Award 007 - ???
static const u32 sAwardGfx_Medal007[] = INCBIN_U32("graphics/awards/medals/007.4bpp.lz");
static const u8  sAwardTxt_Title007[] = _("007: ???");
static const u8  sAwardTxt_Blurb007[] = _("???");

// Award 008 - ???
static const u32 sAwardGfx_Medal008[] = INCBIN_U32("graphics/awards/medals/008.4bpp.lz");
static const u8  sAwardTxt_Title008[] = _("008: ???");
static const u8  sAwardTxt_Blurb008[] = _("???");

// Award 009 - ???
static const u32 sAwardGfx_Medal009[] = INCBIN_U32("graphics/awards/medals/009.4bpp.lz");
static const u8  sAwardTxt_Title009[] = _("009: ???");
static const u8  sAwardTxt_Blurb009[] = _("???");

// Award 010 - ???
static const u32 sAwardGfx_Medal010[] = INCBIN_U32("graphics/awards/medals/010.4bpp.lz");
static const u8  sAwardTxt_Title010[] = _("010: ???");
static const u8  sAwardTxt_Blurb010[] = _("???");

// Award 011 - ???
static const u32 sAwardGfx_Medal011[] = INCBIN_U32("graphics/awards/medals/011.4bpp.lz");
static const u8  sAwardTxt_Title011[] = _("011: ???");
static const u8  sAwardTxt_Blurb011[] = _("???");

// Award 012 - ???
static const u32 sAwardGfx_Medal012[] = INCBIN_U32("graphics/awards/medals/012.4bpp.lz");
static const u8  sAwardTxt_Title012[] = _("012: ???");
static const u8  sAwardTxt_Blurb012[] = _("???");

// Award 013 - ???
static const u32 sAwardGfx_Medal013[] = INCBIN_U32("graphics/awards/medals/013.4bpp.lz");
static const u8  sAwardTxt_Title013[] = _("013: ???");
static const u8  sAwardTxt_Blurb013[] = _("???");

// Award 014 - ???
static const u32 sAwardGfx_Medal014[] = INCBIN_U32("graphics/awards/medals/014.4bpp.lz");
static const u8  sAwardTxt_Title014[] = _("014: ???");
static const u8  sAwardTxt_Blurb014[] = _("???");

// Award 015 - ???
static const u32 sAwardGfx_Medal015[] = INCBIN_U32("graphics/awards/medals/015.4bpp.lz");
static const u8  sAwardTxt_Title015[] = _("015: ???");
static const u8  sAwardTxt_Blurb015[] = _("???");

// Award 016 - ???
static const u32 sAwardGfx_Medal016[] = INCBIN_U32("graphics/awards/medals/016.4bpp.lz");
static const u8  sAwardTxt_Title016[] = _("016: ???");
static const u8  sAwardTxt_Blurb016[] = _("???");

// Award 017 - ???
static const u32 sAwardGfx_Medal017[] = INCBIN_U32("graphics/awards/medals/017.4bpp.lz");
static const u8  sAwardTxt_Title017[] = _("017: ???");
static const u8  sAwardTxt_Blurb017[] = _("???");

// Award 018 - ???
static const u32 sAwardGfx_Medal018[] = INCBIN_U32("graphics/awards/medals/018.4bpp.lz");
static const u8  sAwardTxt_Title018[] = _("018: ???");
static const u8  sAwardTxt_Blurb018[] = _("???");

// Award 019 - ???
static const u32 sAwardGfx_Medal019[] = INCBIN_U32("graphics/awards/medals/019.4bpp.lz");
static const u8  sAwardTxt_Title019[] = _("019: ???");
static const u8  sAwardTxt_Blurb019[] = _("???");

// Award 020 - ???
static const u32 sAwardGfx_Medal020[] = INCBIN_U32("graphics/awards/medals/020.4bpp.lz");
static const u8  sAwardTxt_Title020[] = _("020: ???");
static const u8  sAwardTxt_Blurb020[] = _("???");

// Award 021 - ???
static const u32 sAwardGfx_Medal021[] = INCBIN_U32("graphics/awards/medals/021.4bpp.lz");
static const u8  sAwardTxt_Title021[] = _("021: ???");
static const u8  sAwardTxt_Blurb021[] = _("???");

// Award 022 - ???
static const u32 sAwardGfx_Medal022[] = INCBIN_U32("graphics/awards/medals/022.4bpp.lz");
static const u8  sAwardTxt_Title022[] = _("022: ???");
static const u8  sAwardTxt_Blurb022[] = _("???");

// Award 023 - ???
static const u32 sAwardGfx_Medal023[] = INCBIN_U32("graphics/awards/medals/023.4bpp.lz");
static const u8  sAwardTxt_Title023[] = _("023: ???");
static const u8  sAwardTxt_Blurb023[] = _("???");

// Award 024 - ???
static const u32 sAwardGfx_Medal024[] = INCBIN_U32("graphics/awards/medals/024.4bpp.lz");
static const u8  sAwardTxt_Title024[] = _("024: ???");
static const u8  sAwardTxt_Blurb024[] = _("???");

// Award 025 - ???
static const u32 sAwardGfx_Medal025[] = INCBIN_U32("graphics/awards/medals/025.4bpp.lz");
static const u8  sAwardTxt_Title025[] = _("025: ???");
static const u8  sAwardTxt_Blurb025[] = _("???");

// Award 026 - ???
static const u32 sAwardGfx_Medal026[] = INCBIN_U32("graphics/awards/medals/026.4bpp.lz");
static const u8  sAwardTxt_Title026[] = _("026: ???");
static const u8  sAwardTxt_Blurb026[] = _("???");

// Award 027 - ???
static const u32 sAwardGfx_Medal027[] = INCBIN_U32("graphics/awards/medals/027.4bpp.lz");
static const u8  sAwardTxt_Title027[] = _("027: ???");
static const u8  sAwardTxt_Blurb027[] = _("???");

// Award 028 - ???
static const u32 sAwardGfx_Medal028[] = INCBIN_U32("graphics/awards/medals/028.4bpp.lz");
static const u8  sAwardTxt_Title028[] = _("028: ???");
static const u8  sAwardTxt_Blurb028[] = _("???");

// Award 029 - ???
static const u32 sAwardGfx_Medal029[] = INCBIN_U32("graphics/awards/medals/029.4bpp.lz");
static const u8  sAwardTxt_Title029[] = _("029: ???");
static const u8  sAwardTxt_Blurb029[] = _("???");

// Award 030 - ???
static const u32 sAwardGfx_Medal030[] = INCBIN_U32("graphics/awards/medals/030.4bpp.lz");
static const u8  sAwardTxt_Title030[] = _("030: ???");
static const u8  sAwardTxt_Blurb030[] = _("???");

// Award 031 - ???
static const u32 sAwardGfx_Medal031[] = INCBIN_U32("graphics/awards/medals/031.4bpp.lz");
static const u8  sAwardTxt_Title031[] = _("031: ???");
static const u8  sAwardTxt_Blurb031[] = _("???");

// Award 032 - ???
static const u32 sAwardGfx_Medal032[] = INCBIN_U32("graphics/awards/medals/032.4bpp.lz");
static const u8  sAwardTxt_Title032[] = _("032: ???");
static const u8  sAwardTxt_Blurb032[] = _("???");

// Award 033 - ???
static const u32 sAwardGfx_Medal033[] = INCBIN_U32("graphics/awards/medals/033.4bpp.lz");
static const u8  sAwardTxt_Title033[] = _("033: ???");
static const u8  sAwardTxt_Blurb033[] = _("???");

// Award 034 - ???
static const u32 sAwardGfx_Medal034[] = INCBIN_U32("graphics/awards/medals/034.4bpp.lz");
static const u8  sAwardTxt_Title034[] = _("034: ???");
static const u8  sAwardTxt_Blurb034[] = _("???");

// Award 035 - ???
static const u32 sAwardGfx_Medal035[] = INCBIN_U32("graphics/awards/medals/035.4bpp.lz");
static const u8  sAwardTxt_Title035[] = _("035: ???");
static const u8  sAwardTxt_Blurb035[] = _("???");

// Award 036 - ???
static const u32 sAwardGfx_Medal036[] = INCBIN_U32("graphics/awards/medals/036.4bpp.lz");
static const u8  sAwardTxt_Title036[] = _("036: ???");
static const u8  sAwardTxt_Blurb036[] = _("???");

// Award 037 - ???
static const u32 sAwardGfx_Medal037[] = INCBIN_U32("graphics/awards/medals/037.4bpp.lz");
static const u8  sAwardTxt_Title037[] = _("037: ???");
static const u8  sAwardTxt_Blurb037[] = _("???");

// Award 038 - ???
static const u32 sAwardGfx_Medal038[] = INCBIN_U32("graphics/awards/medals/038.4bpp.lz");
static const u8  sAwardTxt_Title038[] = _("038: ???");
static const u8  sAwardTxt_Blurb038[] = _("???");

// Award 039 - ???
static const u32 sAwardGfx_Medal039[] = INCBIN_U32("graphics/awards/medals/039.4bpp.lz");
static const u8  sAwardTxt_Title039[] = _("039: ???");
static const u8  sAwardTxt_Blurb039[] = _("???");

// Award 040 - ???
static const u32 sAwardGfx_Medal040[] = INCBIN_U32("graphics/awards/medals/040.4bpp.lz");
static const u8  sAwardTxt_Title040[] = _("040: ???");
static const u8  sAwardTxt_Blurb040[] = _("???");

// Award 041 - ???
static const u32 sAwardGfx_Medal041[] = INCBIN_U32("graphics/awards/medals/041.4bpp.lz");
static const u8  sAwardTxt_Title041[] = _("041: ???");
static const u8  sAwardTxt_Blurb041[] = _("???");

// Award 042 - ???
static const u32 sAwardGfx_Medal042[] = INCBIN_U32("graphics/awards/medals/042.4bpp.lz");
static const u8  sAwardTxt_Title042[] = _("042: ???");
static const u8  sAwardTxt_Blurb042[] = _("???");

// Award 043 - ???
static const u32 sAwardGfx_Medal043[] = INCBIN_U32("graphics/awards/medals/043.4bpp.lz");
static const u8  sAwardTxt_Title043[] = _("043: ???");
static const u8  sAwardTxt_Blurb043[] = _("???");

// Award 044 - ???
static const u32 sAwardGfx_Medal044[] = INCBIN_U32("graphics/awards/medals/044.4bpp.lz");
static const u8  sAwardTxt_Title044[] = _("044: ???");
static const u8  sAwardTxt_Blurb044[] = _("???");

// Award 045 - ???
static const u32 sAwardGfx_Medal045[] = INCBIN_U32("graphics/awards/medals/045.4bpp.lz");
static const u8  sAwardTxt_Title045[] = _("045: ???");
static const u8  sAwardTxt_Blurb045[] = _("???");

// Award 046 - ???
static const u32 sAwardGfx_Medal046[] = INCBIN_U32("graphics/awards/medals/046.4bpp.lz");
static const u8  sAwardTxt_Title046[] = _("046: ???");
static const u8  sAwardTxt_Blurb046[] = _("???");

// Award 047 - ???
static const u32 sAwardGfx_Medal047[] = INCBIN_U32("graphics/awards/medals/047.4bpp.lz");
static const u8  sAwardTxt_Title047[] = _("047: ???");
static const u8  sAwardTxt_Blurb047[] = _("???");

// Award 048 - ???
static const u32 sAwardGfx_Medal048[] = INCBIN_U32("graphics/awards/medals/048.4bpp.lz");
static const u8  sAwardTxt_Title048[] = _("048: ???");
static const u8  sAwardTxt_Blurb048[] = _("???");

// Award 049 - ???
static const u32 sAwardGfx_Medal049[] = INCBIN_U32("graphics/awards/medals/049.4bpp.lz");
static const u8  sAwardTxt_Title049[] = _("049: ???");
static const u8  sAwardTxt_Blurb049[] = _("???");

// Award 050 - ???
static const u32 sAwardGfx_Medal050[] = INCBIN_U32("graphics/awards/medals/050.4bpp.lz");
static const u8  sAwardTxt_Title050[] = _("050: ???");
static const u8  sAwardTxt_Blurb050[] = _("???");

// Medium awards

// Award 051 - ???
static const u32 sAwardGfx_Medal051[] = INCBIN_U32("graphics/awards/medals/051.4bpp.lz");
static const u8  sAwardTxt_Title051[] = _("051: ???");
static const u8  sAwardTxt_Blurb051[] = _("???");

// Award 052 - ???
static const u32 sAwardGfx_Medal052[] = INCBIN_U32("graphics/awards/medals/052.4bpp.lz");
static const u8  sAwardTxt_Title052[] = _("052: ???");
static const u8  sAwardTxt_Blurb052[] = _("???");

// Award 053 - ???
static const u32 sAwardGfx_Medal053[] = INCBIN_U32("graphics/awards/medals/053.4bpp.lz");
static const u8  sAwardTxt_Title053[] = _("053: ???");
static const u8  sAwardTxt_Blurb053[] = _("???");

// Award 054 - ???
static const u32 sAwardGfx_Medal054[] = INCBIN_U32("graphics/awards/medals/054.4bpp.lz");
static const u8  sAwardTxt_Title054[] = _("054: ???");
static const u8  sAwardTxt_Blurb054[] = _("???");

// Award 055 - ???
static const u32 sAwardGfx_Medal055[] = INCBIN_U32("graphics/awards/medals/055.4bpp.lz");
static const u8  sAwardTxt_Title055[] = _("055: ???");
static const u8  sAwardTxt_Blurb055[] = _("???");

// Award 056 - ???
static const u32 sAwardGfx_Medal056[] = INCBIN_U32("graphics/awards/medals/056.4bpp.lz");
static const u8  sAwardTxt_Title056[] = _("056: ???");
static const u8  sAwardTxt_Blurb056[] = _("???");

// Award 057 - ???
static const u32 sAwardGfx_Medal057[] = INCBIN_U32("graphics/awards/medals/057.4bpp.lz");
static const u8  sAwardTxt_Title057[] = _("057: ???");
static const u8  sAwardTxt_Blurb057[] = _("???");

// Award 058 - ???
static const u32 sAwardGfx_Medal058[] = INCBIN_U32("graphics/awards/medals/058.4bpp.lz");
static const u8  sAwardTxt_Title058[] = _("058: ???");
static const u8  sAwardTxt_Blurb058[] = _("???");

// Award 059 - ???
static const u32 sAwardGfx_Medal059[] = INCBIN_U32("graphics/awards/medals/059.4bpp.lz");
static const u8  sAwardTxt_Title059[] = _("059: ???");
static const u8  sAwardTxt_Blurb059[] = _("???");

// Award 060 - ???
static const u32 sAwardGfx_Medal060[] = INCBIN_U32("graphics/awards/medals/060.4bpp.lz");
static const u8  sAwardTxt_Title060[] = _("060: ???");
static const u8  sAwardTxt_Blurb060[] = _("???");

// Award 061 - ???
static const u32 sAwardGfx_Medal061[] = INCBIN_U32("graphics/awards/medals/061.4bpp.lz");
static const u8  sAwardTxt_Title061[] = _("061: ???");
static const u8  sAwardTxt_Blurb061[] = _("???");

// Award 062 - ???
static const u32 sAwardGfx_Medal062[] = INCBIN_U32("graphics/awards/medals/062.4bpp.lz");
static const u8  sAwardTxt_Title062[] = _("062: ???");
static const u8  sAwardTxt_Blurb062[] = _("???");

// Award 063 - ???
static const u32 sAwardGfx_Medal063[] = INCBIN_U32("graphics/awards/medals/063.4bpp.lz");
static const u8  sAwardTxt_Title063[] = _("063: ???");
static const u8  sAwardTxt_Blurb063[] = _("???");

// Award 064 - ???
static const u32 sAwardGfx_Medal064[] = INCBIN_U32("graphics/awards/medals/064.4bpp.lz");
static const u8  sAwardTxt_Title064[] = _("064: ???");
static const u8  sAwardTxt_Blurb064[] = _("???");

// Award 065 - ???
static const u32 sAwardGfx_Medal065[] = INCBIN_U32("graphics/awards/medals/065.4bpp.lz");
static const u8  sAwardTxt_Title065[] = _("065: ???");
static const u8  sAwardTxt_Blurb065[] = _("???");

// Award 066 - ???
static const u32 sAwardGfx_Medal066[] = INCBIN_U32("graphics/awards/medals/066.4bpp.lz");
static const u8  sAwardTxt_Title066[] = _("066: ???");
static const u8  sAwardTxt_Blurb066[] = _("???");

// Award 067 - ???
static const u32 sAwardGfx_Medal067[] = INCBIN_U32("graphics/awards/medals/067.4bpp.lz");
static const u8  sAwardTxt_Title067[] = _("067: ???");
static const u8  sAwardTxt_Blurb067[] = _("???");

// Award 068 - ???
static const u32 sAwardGfx_Medal068[] = INCBIN_U32("graphics/awards/medals/068.4bpp.lz");
static const u8  sAwardTxt_Title068[] = _("068: ???");
static const u8  sAwardTxt_Blurb068[] = _("???");

// Award 069 - ???
static const u32 sAwardGfx_Medal069[] = INCBIN_U32("graphics/awards/medals/069.4bpp.lz");
static const u8  sAwardTxt_Title069[] = _("069: ???");
static const u8  sAwardTxt_Blurb069[] = _("???");

// Award 070 - ???
static const u32 sAwardGfx_Medal070[] = INCBIN_U32("graphics/awards/medals/070.4bpp.lz");
static const u8  sAwardTxt_Title070[] = _("070: ???");
static const u8  sAwardTxt_Blurb070[] = _("???");

// Award 071 - ???
static const u32 sAwardGfx_Medal071[] = INCBIN_U32("graphics/awards/medals/071.4bpp.lz");
static const u8  sAwardTxt_Title071[] = _("071: ???");
static const u8  sAwardTxt_Blurb071[] = _("???");

// Award 072 - ???
static const u32 sAwardGfx_Medal072[] = INCBIN_U32("graphics/awards/medals/072.4bpp.lz");
static const u8  sAwardTxt_Title072[] = _("072: ???");
static const u8  sAwardTxt_Blurb072[] = _("???");

// Award 073 - ???
static const u32 sAwardGfx_Medal073[] = INCBIN_U32("graphics/awards/medals/073.4bpp.lz");
static const u8  sAwardTxt_Title073[] = _("073: ???");
static const u8  sAwardTxt_Blurb073[] = _("???");

// Award 074 - ???
static const u32 sAwardGfx_Medal074[] = INCBIN_U32("graphics/awards/medals/074.4bpp.lz");
static const u8  sAwardTxt_Title074[] = _("074: ???");
static const u8  sAwardTxt_Blurb074[] = _("???");

// Award 075 - ???
static const u32 sAwardGfx_Medal075[] = INCBIN_U32("graphics/awards/medals/075.4bpp.lz");
static const u8  sAwardTxt_Title075[] = _("075: ???");
static const u8  sAwardTxt_Blurb075[] = _("???");

// Award 076 - ???
static const u32 sAwardGfx_Medal076[] = INCBIN_U32("graphics/awards/medals/076.4bpp.lz");
static const u8  sAwardTxt_Title076[] = _("076: ???");
static const u8  sAwardTxt_Blurb076[] = _("???");

// Award 077 - ???
static const u32 sAwardGfx_Medal077[] = INCBIN_U32("graphics/awards/medals/077.4bpp.lz");
static const u8  sAwardTxt_Title077[] = _("077: ???");
static const u8  sAwardTxt_Blurb077[] = _("???");

// Award 078 - ???
static const u32 sAwardGfx_Medal078[] = INCBIN_U32("graphics/awards/medals/078.4bpp.lz");
static const u8  sAwardTxt_Title078[] = _("078: ???");
static const u8  sAwardTxt_Blurb078[] = _("???");

// Award 079 - ???
static const u32 sAwardGfx_Medal079[] = INCBIN_U32("graphics/awards/medals/079.4bpp.lz");
static const u8  sAwardTxt_Title079[] = _("079: ???");
static const u8  sAwardTxt_Blurb079[] = _("???");

// Award 080 - ???
static const u32 sAwardGfx_Medal080[] = INCBIN_U32("graphics/awards/medals/080.4bpp.lz");
static const u8  sAwardTxt_Title080[] = _("080: ???");
static const u8  sAwardTxt_Blurb080[] = _("???");

// Award 081 - ???
static const u32 sAwardGfx_Medal081[] = INCBIN_U32("graphics/awards/medals/081.4bpp.lz");
static const u8  sAwardTxt_Title081[] = _("081: ???");
static const u8  sAwardTxt_Blurb081[] = _("???");

// Award 082 - ???
static const u32 sAwardGfx_Medal082[] = INCBIN_U32("graphics/awards/medals/082.4bpp.lz");
static const u8  sAwardTxt_Title082[] = _("082: ???");
static const u8  sAwardTxt_Blurb082[] = _("???");

// Award 083 - ???
static const u32 sAwardGfx_Medal083[] = INCBIN_U32("graphics/awards/medals/083.4bpp.lz");
static const u8  sAwardTxt_Title083[] = _("083: ???");
static const u8  sAwardTxt_Blurb083[] = _("???");

// Award 084 - ???
static const u32 sAwardGfx_Medal084[] = INCBIN_U32("graphics/awards/medals/084.4bpp.lz");
static const u8  sAwardTxt_Title084[] = _("084: ???");
static const u8  sAwardTxt_Blurb084[] = _("???");

// Award 085 - ???
static const u32 sAwardGfx_Medal085[] = INCBIN_U32("graphics/awards/medals/085.4bpp.lz");
static const u8  sAwardTxt_Title085[] = _("085: ???");
static const u8  sAwardTxt_Blurb085[] = _("???");

// Award 086 - ???
static const u32 sAwardGfx_Medal086[] = INCBIN_U32("graphics/awards/medals/086.4bpp.lz");
static const u8  sAwardTxt_Title086[] = _("086: ???");
static const u8  sAwardTxt_Blurb086[] = _("???");

// Award 087 - ???
static const u32 sAwardGfx_Medal087[] = INCBIN_U32("graphics/awards/medals/087.4bpp.lz");
static const u8  sAwardTxt_Title087[] = _("087: ???");
static const u8  sAwardTxt_Blurb087[] = _("???");

// Award 088 - ???
static const u32 sAwardGfx_Medal088[] = INCBIN_U32("graphics/awards/medals/088.4bpp.lz");
static const u8  sAwardTxt_Title088[] = _("088: ???");
static const u8  sAwardTxt_Blurb088[] = _("???");

// Award 089 - ???
static const u32 sAwardGfx_Medal089[] = INCBIN_U32("graphics/awards/medals/089.4bpp.lz");
static const u8  sAwardTxt_Title089[] = _("089: ???");
static const u8  sAwardTxt_Blurb089[] = _("???");

// Award 090 - ???
static const u32 sAwardGfx_Medal090[] = INCBIN_U32("graphics/awards/medals/090.4bpp.lz");
static const u8  sAwardTxt_Title090[] = _("090: ???");
static const u8  sAwardTxt_Blurb090[] = _("???");

// Award 091 - ???
static const u32 sAwardGfx_Medal091[] = INCBIN_U32("graphics/awards/medals/091.4bpp.lz");
static const u8  sAwardTxt_Title091[] = _("091: ???");
static const u8  sAwardTxt_Blurb091[] = _("???");

// Award 092 - ???
static const u32 sAwardGfx_Medal092[] = INCBIN_U32("graphics/awards/medals/092.4bpp.lz");
static const u8  sAwardTxt_Title092[] = _("092: ???");
static const u8  sAwardTxt_Blurb092[] = _("???");

// Award 093 - ???
static const u32 sAwardGfx_Medal093[] = INCBIN_U32("graphics/awards/medals/093.4bpp.lz");
static const u8  sAwardTxt_Title093[] = _("093: ???");
static const u8  sAwardTxt_Blurb093[] = _("???");

// Award 094 - ???
static const u32 sAwardGfx_Medal094[] = INCBIN_U32("graphics/awards/medals/094.4bpp.lz");
static const u8  sAwardTxt_Title094[] = _("094: ???");
static const u8  sAwardTxt_Blurb094[] = _("???");

// Award 095 - ???
static const u32 sAwardGfx_Medal095[] = INCBIN_U32("graphics/awards/medals/095.4bpp.lz");
static const u8  sAwardTxt_Title095[] = _("095: ???");
static const u8  sAwardTxt_Blurb095[] = _("???");

// Award 096 - ???
static const u32 sAwardGfx_Medal096[] = INCBIN_U32("graphics/awards/medals/096.4bpp.lz");
static const u8  sAwardTxt_Title096[] = _("096: ???");
static const u8  sAwardTxt_Blurb096[] = _("???");

// Award 097 - ???
static const u32 sAwardGfx_Medal097[] = INCBIN_U32("graphics/awards/medals/097.4bpp.lz");
static const u8  sAwardTxt_Title097[] = _("097: ???");
static const u8  sAwardTxt_Blurb097[] = _("???");

// Award 098 - ???
static const u32 sAwardGfx_Medal098[] = INCBIN_U32("graphics/awards/medals/098.4bpp.lz");
static const u8  sAwardTxt_Title098[] = _("098: ???");
static const u8  sAwardTxt_Blurb098[] = _("???");

// Award 099 - ???
static const u32 sAwardGfx_Medal099[] = INCBIN_U32("graphics/awards/medals/099.4bpp.lz");
static const u8  sAwardTxt_Title099[] = _("099: ???");
static const u8  sAwardTxt_Blurb099[] = _("???");

// Award 100 - ???
static const u32 sAwardGfx_Medal100[] = INCBIN_U32("graphics/awards/medals/100.4bpp.lz");
static const u8  sAwardTxt_Title100[] = _("100: ???");
static const u8  sAwardTxt_Blurb100[] = _("???");

// Hard awards

// Award 101 - ???
static const u32 sAwardGfx_Medal101[] = INCBIN_U32("graphics/awards/medals/101.4bpp.lz");
static const u8  sAwardTxt_Title101[] = _("101: ???");
static const u8  sAwardTxt_Blurb101[] = _("???");

// Award 102 - ???
static const u32 sAwardGfx_Medal102[] = INCBIN_U32("graphics/awards/medals/102.4bpp.lz");
static const u8  sAwardTxt_Title102[] = _("102: ???");
static const u8  sAwardTxt_Blurb102[] = _("???");

// Award 103 - ???
static const u32 sAwardGfx_Medal103[] = INCBIN_U32("graphics/awards/medals/103.4bpp.lz");
static const u8  sAwardTxt_Title103[] = _("103: ???");
static const u8  sAwardTxt_Blurb103[] = _("???");

// Award 104 - ???
static const u32 sAwardGfx_Medal104[] = INCBIN_U32("graphics/awards/medals/104.4bpp.lz");
static const u8  sAwardTxt_Title104[] = _("104: ???");
static const u8  sAwardTxt_Blurb104[] = _("???");

// Award 105 - ???
static const u32 sAwardGfx_Medal105[] = INCBIN_U32("graphics/awards/medals/105.4bpp.lz");
static const u8  sAwardTxt_Title105[] = _("105: ???");
static const u8  sAwardTxt_Blurb105[] = _("???");

// Award 106 - ???
static const u32 sAwardGfx_Medal106[] = INCBIN_U32("graphics/awards/medals/106.4bpp.lz");
static const u8  sAwardTxt_Title106[] = _("106: ???");
static const u8  sAwardTxt_Blurb106[] = _("???");

// Award 107 - ???
static const u32 sAwardGfx_Medal107[] = INCBIN_U32("graphics/awards/medals/107.4bpp.lz");
static const u8  sAwardTxt_Title107[] = _("107: ???");
static const u8  sAwardTxt_Blurb107[] = _("???");

// Award 108 - ???
static const u32 sAwardGfx_Medal108[] = INCBIN_U32("graphics/awards/medals/108.4bpp.lz");
static const u8  sAwardTxt_Title108[] = _("108: ???");
static const u8  sAwardTxt_Blurb108[] = _("???");

// Award 109 - ???
static const u32 sAwardGfx_Medal109[] = INCBIN_U32("graphics/awards/medals/109.4bpp.lz");
static const u8  sAwardTxt_Title109[] = _("109: ???");
static const u8  sAwardTxt_Blurb109[] = _("???");

// Award 110 - ???
static const u32 sAwardGfx_Medal110[] = INCBIN_U32("graphics/awards/medals/110.4bpp.lz");
static const u8  sAwardTxt_Title110[] = _("110: ???");
static const u8  sAwardTxt_Blurb110[] = _("???");

// Award 111 - ???
static const u32 sAwardGfx_Medal111[] = INCBIN_U32("graphics/awards/medals/111.4bpp.lz");
static const u8  sAwardTxt_Title111[] = _("111: ???");
static const u8  sAwardTxt_Blurb111[] = _("???");

// Award 112 - ???
static const u32 sAwardGfx_Medal112[] = INCBIN_U32("graphics/awards/medals/112.4bpp.lz");
static const u8  sAwardTxt_Title112[] = _("112: ???");
static const u8  sAwardTxt_Blurb112[] = _("???");

// Award 113 - ???
static const u32 sAwardGfx_Medal113[] = INCBIN_U32("graphics/awards/medals/113.4bpp.lz");
static const u8  sAwardTxt_Title113[] = _("113: ???");
static const u8  sAwardTxt_Blurb113[] = _("???");

// Award 114 - ???
static const u32 sAwardGfx_Medal114[] = INCBIN_U32("graphics/awards/medals/114.4bpp.lz");
static const u8  sAwardTxt_Title114[] = _("114: ???");
static const u8  sAwardTxt_Blurb114[] = _("???");

// Award 115 - ???
static const u32 sAwardGfx_Medal115[] = INCBIN_U32("graphics/awards/medals/115.4bpp.lz");
static const u8  sAwardTxt_Title115[] = _("115: ???");
static const u8  sAwardTxt_Blurb115[] = _("???");

// Award 116 - ???
static const u32 sAwardGfx_Medal116[] = INCBIN_U32("graphics/awards/medals/116.4bpp.lz");
static const u8  sAwardTxt_Title116[] = _("116: ???");
static const u8  sAwardTxt_Blurb116[] = _("???");

// Award 117 - ???
static const u32 sAwardGfx_Medal117[] = INCBIN_U32("graphics/awards/medals/117.4bpp.lz");
static const u8  sAwardTxt_Title117[] = _("117: ???");
static const u8  sAwardTxt_Blurb117[] = _("???");

// Award 118 - ???
static const u32 sAwardGfx_Medal118[] = INCBIN_U32("graphics/awards/medals/118.4bpp.lz");
static const u8  sAwardTxt_Title118[] = _("118: ???");
static const u8  sAwardTxt_Blurb118[] = _("???");

// Award 119 - ???
static const u32 sAwardGfx_Medal119[] = INCBIN_U32("graphics/awards/medals/119.4bpp.lz");
static const u8  sAwardTxt_Title119[] = _("119: ???");
static const u8  sAwardTxt_Blurb119[] = _("???");

// Award 120 - ???
static const u32 sAwardGfx_Medal120[] = INCBIN_U32("graphics/awards/medals/120.4bpp.lz");
static const u8  sAwardTxt_Title120[] = _("120: ???");
static const u8  sAwardTxt_Blurb120[] = _("???");

// Award 121 - ???
static const u32 sAwardGfx_Medal121[] = INCBIN_U32("graphics/awards/medals/121.4bpp.lz");
static const u8  sAwardTxt_Title121[] = _("121: ???");
static const u8  sAwardTxt_Blurb121[] = _("???");

// Award 122 - ???
static const u32 sAwardGfx_Medal122[] = INCBIN_U32("graphics/awards/medals/122.4bpp.lz");
static const u8  sAwardTxt_Title122[] = _("122: ???");
static const u8  sAwardTxt_Blurb122[] = _("???");

// Award 123 - ???
static const u32 sAwardGfx_Medal123[] = INCBIN_U32("graphics/awards/medals/123.4bpp.lz");
static const u8  sAwardTxt_Title123[] = _("123: ???");
static const u8  sAwardTxt_Blurb123[] = _("???");

// Award 124 - ???
static const u32 sAwardGfx_Medal124[] = INCBIN_U32("graphics/awards/medals/124.4bpp.lz");
static const u8  sAwardTxt_Title124[] = _("124: ???");
static const u8  sAwardTxt_Blurb124[] = _("???");

// Award 125 - ???
static const u32 sAwardGfx_Medal125[] = INCBIN_U32("graphics/awards/medals/125.4bpp.lz");
static const u8  sAwardTxt_Title125[] = _("125: ???");
static const u8  sAwardTxt_Blurb125[] = _("???");

// Award 126 - ???
static const u32 sAwardGfx_Medal126[] = INCBIN_U32("graphics/awards/medals/126.4bpp.lz");
static const u8  sAwardTxt_Title126[] = _("126: ???");
static const u8  sAwardTxt_Blurb126[] = _("???");

// Award 127 - ???
static const u32 sAwardGfx_Medal127[] = INCBIN_U32("graphics/awards/medals/127.4bpp.lz");
static const u8  sAwardTxt_Title127[] = _("127: ???");
static const u8  sAwardTxt_Blurb127[] = _("???");

// Award 128 - ???
static const u32 sAwardGfx_Medal128[] = INCBIN_U32("graphics/awards/medals/128.4bpp.lz");
static const u8  sAwardTxt_Title128[] = _("128: ???");
static const u8  sAwardTxt_Blurb128[] = _("???");

// Award 129 - ???
static const u32 sAwardGfx_Medal129[] = INCBIN_U32("graphics/awards/medals/129.4bpp.lz");
static const u8  sAwardTxt_Title129[] = _("129: ???");
static const u8  sAwardTxt_Blurb129[] = _("???");

// Award 130 - ???
static const u32 sAwardGfx_Medal130[] = INCBIN_U32("graphics/awards/medals/130.4bpp.lz");
static const u8  sAwardTxt_Title130[] = _("130: ???");
static const u8  sAwardTxt_Blurb130[] = _("???");

// Award 131 - ???
static const u32 sAwardGfx_Medal131[] = INCBIN_U32("graphics/awards/medals/131.4bpp.lz");
static const u8  sAwardTxt_Title131[] = _("131: ???");
static const u8  sAwardTxt_Blurb131[] = _("???");

// Award 132 - ???
static const u32 sAwardGfx_Medal132[] = INCBIN_U32("graphics/awards/medals/132.4bpp.lz");
static const u8  sAwardTxt_Title132[] = _("132: ???");
static const u8  sAwardTxt_Blurb132[] = _("???");

// Award 133 - ???
static const u32 sAwardGfx_Medal133[] = INCBIN_U32("graphics/awards/medals/133.4bpp.lz");
static const u8  sAwardTxt_Title133[] = _("133: ???");
static const u8  sAwardTxt_Blurb133[] = _("???");

// Award 134 - ???
static const u32 sAwardGfx_Medal134[] = INCBIN_U32("graphics/awards/medals/134.4bpp.lz");
static const u8  sAwardTxt_Title134[] = _("134: ???");
static const u8  sAwardTxt_Blurb134[] = _("???");

// Award 135 - ???
static const u32 sAwardGfx_Medal135[] = INCBIN_U32("graphics/awards/medals/135.4bpp.lz");
static const u8  sAwardTxt_Title135[] = _("135: ???");
static const u8  sAwardTxt_Blurb135[] = _("???");

// Award 136 - ???
static const u32 sAwardGfx_Medal136[] = INCBIN_U32("graphics/awards/medals/136.4bpp.lz");
static const u8  sAwardTxt_Title136[] = _("136: ???");
static const u8  sAwardTxt_Blurb136[] = _("???");

// Award 137 - ???
static const u32 sAwardGfx_Medal137[] = INCBIN_U32("graphics/awards/medals/137.4bpp.lz");
static const u8  sAwardTxt_Title137[] = _("137: ???");
static const u8  sAwardTxt_Blurb137[] = _("???");

// Award 138 - ???
static const u32 sAwardGfx_Medal138[] = INCBIN_U32("graphics/awards/medals/138.4bpp.lz");
static const u8  sAwardTxt_Title138[] = _("138: ???");
static const u8  sAwardTxt_Blurb138[] = _("???");

// Award 139 - ???
static const u32 sAwardGfx_Medal139[] = INCBIN_U32("graphics/awards/medals/139.4bpp.lz");
static const u8  sAwardTxt_Title139[] = _("139: ???");
static const u8  sAwardTxt_Blurb139[] = _("???");

// Award 140 - ???
static const u32 sAwardGfx_Medal140[] = INCBIN_U32("graphics/awards/medals/140.4bpp.lz");
static const u8  sAwardTxt_Title140[] = _("140: ???");
static const u8  sAwardTxt_Blurb140[] = _("???");

// Award 141 - ???
static const u32 sAwardGfx_Medal141[] = INCBIN_U32("graphics/awards/medals/141.4bpp.lz");
static const u8  sAwardTxt_Title141[] = _("141: ???");
static const u8  sAwardTxt_Blurb141[] = _("???");

// Award 142 - ???
static const u32 sAwardGfx_Medal142[] = INCBIN_U32("graphics/awards/medals/142.4bpp.lz");
static const u8  sAwardTxt_Title142[] = _("142: ???");
static const u8  sAwardTxt_Blurb142[] = _("???");

// Award 143 - ???
static const u32 sAwardGfx_Medal143[] = INCBIN_U32("graphics/awards/medals/143.4bpp.lz");
static const u8  sAwardTxt_Title143[] = _("143: ???");
static const u8  sAwardTxt_Blurb143[] = _("???");

// Award 144 - ???
static const u32 sAwardGfx_Medal144[] = INCBIN_U32("graphics/awards/medals/144.4bpp.lz");
static const u8  sAwardTxt_Title144[] = _("144: ???");
static const u8  sAwardTxt_Blurb144[] = _("???");

// Award 145 - ???
static const u32 sAwardGfx_Medal145[] = INCBIN_U32("graphics/awards/medals/145.4bpp.lz");
static const u8  sAwardTxt_Title145[] = _("145: ???");
static const u8  sAwardTxt_Blurb145[] = _("???");

// Award 146 - ???
static const u32 sAwardGfx_Medal146[] = INCBIN_U32("graphics/awards/medals/146.4bpp.lz");
static const u8  sAwardTxt_Title146[] = _("146: ???");
static const u8  sAwardTxt_Blurb146[] = _("???");

// Award 147 - ???
static const u32 sAwardGfx_Medal147[] = INCBIN_U32("graphics/awards/medals/147.4bpp.lz");
static const u8  sAwardTxt_Title147[] = _("147: ???");
static const u8  sAwardTxt_Blurb147[] = _("???");

// Award 148 - ???
static const u32 sAwardGfx_Medal148[] = INCBIN_U32("graphics/awards/medals/148.4bpp.lz");
static const u8  sAwardTxt_Title148[] = _("148: ???");
static const u8  sAwardTxt_Blurb148[] = _("???");

// Award 149 - ???
static const u32 sAwardGfx_Medal149[] = INCBIN_U32("graphics/awards/medals/149.4bpp.lz");
static const u8  sAwardTxt_Title149[] = _("149: ???");
static const u8  sAwardTxt_Blurb149[] = _("???");

// Award 150 - ???
static const u32 sAwardGfx_Medal150[] = INCBIN_U32("graphics/awards/medals/150.4bpp.lz");
static const u8  sAwardTxt_Title150[] = _("150: ???");
static const u8  sAwardTxt_Blurb150[] = _("???");

// "Platinum" award

// Award 151 - ???
static const u32 sAwardGfx_Medal151[] = INCBIN_U32("graphics/awards/medals/151.4bpp.lz");
static const u8  sAwardTxt_Title151[] = _("151: ???");
static const u8  sAwardTxt_Blurb151[] = _("???");


// Set up the medal graphics again, because GBA development is funnnnnnn~
// They also need to be #defined in include/awards.h
static const struct Medal sAwardGfx_Medals[] = {
    [MEDAL_UNKNOWN] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Unknown_Medal, .palette = sAwardPal_Unknown_Medal},
    [MEDAL_DUMMY] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Dummy_Medal, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_001] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal001, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_002] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal002, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_003] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal003, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_004] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal004, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_005] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal005, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_006] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal006, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_007] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal007, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_008] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal008, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_009] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal009, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_010] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal010, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_011] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal011, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_012] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal012, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_013] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal013, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_014] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal014, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_015] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal015, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_016] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal016, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_017] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal017, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_018] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal018, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_019] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal019, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_020] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal020, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_021] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal021, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_022] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal022, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_023] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal023, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_024] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal024, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_025] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal025, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_026] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal026, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_027] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal027, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_028] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal028, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_029] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal029, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_030] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal030, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_031] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal031, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_032] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal032, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_033] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal033, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_034] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal034, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_035] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal035, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_036] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal036, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_037] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal037, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_038] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal038, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_039] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal039, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_040] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal040, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_041] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal041, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_042] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal042, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_043] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal043, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_044] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal044, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_045] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal045, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_046] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal046, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_047] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal047, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_048] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal048, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_049] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal049, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_050] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal050, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_051] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal051, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_052] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal052, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_053] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal053, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_054] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal054, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_055] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal055, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_056] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal056, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_057] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal057, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_058] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal058, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_059] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal059, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_060] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal060, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_061] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal061, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_062] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal062, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_063] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal063, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_064] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal064, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_065] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal065, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_066] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal066, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_067] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal067, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_068] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal068, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_069] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal069, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_070] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal070, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_071] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal071, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_072] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal072, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_073] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal073, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_074] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal074, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_075] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal075, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_076] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal076, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_077] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal077, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_078] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal078, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_079] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal079, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_080] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal080, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_081] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal081, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_082] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal082, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_083] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal083, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_084] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal084, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_085] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal085, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_086] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal086, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_087] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal087, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_088] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal088, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_089] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal089, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_090] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal090, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_091] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal091, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_092] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal092, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_093] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal093, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_094] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal094, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_095] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal095, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_096] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal096, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_097] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal097, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_098] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal098, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_099] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal099, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_100] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal100, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_101] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal101, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_102] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal102, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_103] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal103, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_104] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal104, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_105] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal105, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_106] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal106, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_107] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal107, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_108] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal108, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_109] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal109, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_110] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal110, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_111] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal111, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_112] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal112, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_113] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal113, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_114] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal114, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_115] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal115, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_116] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal116, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_117] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal117, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_118] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal118, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_119] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal119, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_120] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal120, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_121] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal121, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_122] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal122, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_123] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal123, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_124] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal124, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_125] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal125, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_126] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal126, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_127] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal127, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_128] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal128, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_129] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal129, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_130] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal130, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_131] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal131, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_132] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal132, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_133] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal133, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_134] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal134, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_135] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal135, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_136] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal136, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_137] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal137, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_138] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal138, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_139] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal139, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_140] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal140, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_141] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal141, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_142] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal142, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_143] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal143, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_144] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal144, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_145] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal145, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_146] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal146, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_147] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal147, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_148] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal148, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_149] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal149, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_150] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal150, .palette = sAwardPal_Dummy_Medal},
    [MEDAL_151] = {.x = 0, .y = 0, .width = 32, .height = 32, .image = sAwardGfx_Medal151, .palette = sAwardPal_Dummy_Medal},
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
static const u8 sCursorCoords[][8] =
{
    {45, 58},  // Top row,    left medal
    {78, 58},  // Top row,    middle medal
    {111, 58}, // Top row,    right medal
    {45, 90},  // Middle row, left medal
    {78, 90},  // Middle row, middle medal
    {111, 90}, // Middle row, right medal
    {45, 122}, // Bottom row, left medal
    {78, 122}, // Bottom row, middle medal
    {111, 122} // Bottom row, right medal
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


// Setup .text
u16 GetTheAward(u16 selectedAwardId)
{
    if (selectedAwardId > AWARDS_COUNT)
        selectedAwardId = 0;
    return sTheAwards[selectedAwardId];
}


// Set up data for Task_AwardSelect
#define tAwardSelection data[0]
#define tMedalSpriteId  data[1]


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



