enum
{
    PAGE_TITLE,
    PAGE_DIRECTOR,
    PAGE_ART_DIRECTOR,
    PAGE_WORLD_DIRECTOR,
    PAGE_LEAD_PROGRAMMER,
    PAGE_PROGRAMMERS_1,
    PAGE_PROGRAMMERS_2,
    PAGE_PROGRAMMERS_3,
    PAGE_PROGRAMMERS_4,
    PAGE_GRAPHIC_DESIGNERS_1,
    PAGE_GRAPHIC_DESIGNERS_2,
    PAGE_GRAPHIC_DESIGNERS_3,
    PAGE_MUSIC_COMPOSITION,
    PAGE_SOUND_EFFECTS,
    PAGE_GAME_DESIGNERS_1,
    PAGE_GAME_DESIGNERS_2,
    PAGE_GAME_DESIGNERS_3,
    PAGE_SCENARIO_PLOT,
    PAGE_SCENARIO,
    PAGE_SCRIPT_DESIGNERS,
    PAGE_MAP_DESIGNERS,
    PAGE_BATTLE_FRONTIER_DATA,
    PAGE_PARAMETRIC_DESIGNERS,
    PAGE_POKEDEX_TEXT,
    PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_1,
    PAGE_PKMN_DESIGNERS_1,
    PAGE_PKMN_DESIGNERS_2,
    PAGE_PKMN_DESIGNERS_3,
    PAGE_PKMN_DESIGNERS_4,
    PAGE_SUPPORT_PROGRAMMERS,
    PAGE_NCL_PRODUCT_TESTING,
    PAGE_PACKAGE_AND_MANUAL,
    PAGE_SPECIAL_THANKS_1,
    PAGE_SPECIAL_THANKS_2,
    PAGE_SPECIAL_THANKS_3,
    PAGE_SPECIAL_THANKS_4,
    PAGE_INFORMATION_SUPERVISORS,
    PAGE_ARTWORK_1,
    PAGE_ARTWORK_2,
    PAGE_ARTWORK_3,
    PAGE_COORDINATORS,
    PAGE_ENGLISH_VERSION,
    PAGE_TRANSLATOR,
    PAGE_TEXT_EDITOR,
    PAGE_NCL_COORDINATOR,
    PAGE_PROGRAMMERS_5,
    PAGE_GRAPHIC_DESIGNER,
    PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_2,
    PAGE_NOA_TESTING,
    PAGE_BRAILLE_CODE_CHECK_1,
    PAGE_BRAILLE_CODE_CHECK_2,
    PAGE_SPECIAL_THANKS_5,
    PAGE_TASK_MANAGERS,
    PAGE_PRODUCERS,
    PAGE_EXECUTIVE_DIRECTOR,
    PAGE_EXECUTIVE_PRODUCERS_1,
    PAGE_EXECUTIVE_PRODUCERS_2,
    PAGE_COUNT
};

#define ENTRIES_PER_PAGE 5

static const u8 sCreditsText_EmptyString[] = _("");
static const struct CreditsEntry sCreditsEntry_EmptyString[] = {0, FALSE, sCreditsText_EmptyString};

static const u8 sCreditsText_PkmnRainbowAmnesty[] = _("Pokémon Rainbow Amnesty");
static const struct CreditsEntry sCreditsEntry_PkmnRainbowAmnesty[] = {7, TRUE, sCreditsText_PkmnRainbowAmnesty};
static const u8 sCreditsText_Credits[] = _("Credits");
static const struct CreditsEntry sCreditsEntry_Credits[] = {11, TRUE, sCreditsText_Credits};

static const u8 sCreditsText_CreatedBy[] = _("Created by");
static const struct CreditsEntry sCreditsEntry_CreatedBy[] = {11, TRUE, sCreditsText_CreatedBy};
static const u8 sCreditsText_POKeMIKE[] = _("{FONT_NARROW}meejle");
static const struct CreditsEntry sCreditsEntry_POKeMIKE[] = {11, FALSE, sCreditsText_POKeMIKE};
static const u8 sCreditsText_Scenario[] = _("Scenario");
static const struct CreditsEntry sCreditsEntry_Scenario[] = {11, TRUE, sCreditsText_Scenario};
static const u8 sCreditsText_mattmck[] = _("{FONT_NARROW}{UNDERSCORE}mattmck");
static const struct CreditsEntry sCreditsEntry_mattmck[] = {11, FALSE, sCreditsText_mattmck};

static const u8 sCreditsText_PokemonEmeraldDecomp[] = _("Powered by pokeemerald");
static const struct CreditsEntry sCreditsEntry_PokemonEmeraldDecomp[] = {11, TRUE, sCreditsText_PokemonEmeraldDecomp};
static const u8 sCreditsText_pret[] = _("{FONT_NARROW}Created by pret");
static const struct CreditsEntry sCreditsEntry_pret[] = {11, FALSE, sCreditsText_pret};
static const u8 sCreditsText_pokeemeraldContrib[] = _("{FONT_SMALL}Contributors: https://github.com/pret/\npokeemerald/graphs/contributors");
static const struct CreditsEntry sCreditsEntry_pokeemeraldContrib[] = {11, FALSE, sCreditsText_pokeemeraldContrib};

static const u8 sCreditsText_pokeemeraldExpansion[] = _("Powered by pokeemerald Expansion");
static const struct CreditsEntry sCreditsEntry_pokeemeraldExpansion[] = {11, TRUE, sCreditsText_pokeemeraldExpansion};
static const u8 sCreditsText_DizzyEggg[] = _("{FONT_NARROW}Created by DizzyEggg");
static const struct CreditsEntry sCreditsEntry_DizzyEggg[] = {11, FALSE, sCreditsText_DizzyEggg};
static const u8 sCreditsText_MaintainedBy[] = _("Maintained by");
static const struct CreditsEntry sCreditsEntry_MaintainedBy[] = {11, TRUE, sCreditsText_MaintainedBy};
static const u8 sCreditsText_ExpansionMaintain1[] = _("{FONT_NARROW}UltimaSoul   ghoulslash   AsparagusEduardo");
static const struct CreditsEntry sCreditsEntry_ExpansionMaintain1[] = {11, FALSE, sCreditsText_ExpansionMaintain1};
static const u8 sCreditsText_ExpansionMaintain2[] = _("{FONT_NARROW}ExpoSeed   Pyredrid   MandL127");
static const struct CreditsEntry sCreditsEntry_ExpansionMaintain2[] = {11, FALSE, sCreditsText_ExpansionMaintain2};

static const u8 sCreditsText_MainContributors[] = _("Main contributors");
static const struct CreditsEntry sCreditsEntry_MainContributors[] = {11, TRUE, sCreditsText_MainContributors};
static const u8 sCreditsText_ExpansionCredit1[] = _("{FONT_NARROW}Lunos   ShantyTown   mvit   Doesnt");
static const struct CreditsEntry sCreditsEntry_ExpansionCredit1[] = {11, FALSE, sCreditsText_ExpansionCredit1};
static const u8 sCreditsText_ExpansionCredit2[] = _("{FONT_NARROW}Cancer Fairy   MrDollSteak   Avara   Kurausukun");
static const struct CreditsEntry sCreditsEntry_ExpansionCredit2[] = {11, FALSE, sCreditsText_ExpansionCredit2};
static const u8 sCreditsText_ExpansionCredit3[] = _("{FONT_NARROW}TheLaw   BreadCrumbs   Syreldar");
static const struct CreditsEntry sCreditsEntry_ExpansionCredit3[] = {11, FALSE, sCreditsText_ExpansionCredit3};

static const u8 sCreditsText_pokeemeraldExpansion2[] = _("pokeemerald Expansion");
static const struct CreditsEntry sCreditsEntry_pokeemeraldExpansion2[] = {11, TRUE, sCreditsText_pokeemeraldExpansion2};
static const u8 sCreditsText_ExpansionContrib[] = _("{FONT_SMALL}Contributors: https://github.com/rh-hideout/\npokeemerald-expansion/graphs/contributors");
static const struct CreditsEntry sCreditsEntry_ExpansionContrib[] = {11, FALSE, sCreditsText_ExpansionContrib};

static const u8 sCreditsText_DebuggingSupport[] = _("Support programmers");
static const struct CreditsEntry sCreditsEntry_DebuggingSupport[] = {11, TRUE, sCreditsText_DebuggingSupport};
static const u8 sCreditsText_DebugSupport1[] = _("{FONT_NARROW}Anon822");
static const struct CreditsEntry sCreditsEntry_DebugSupport1[] = {11, FALSE, sCreditsText_DebugSupport1};

static const u8 sCreditsText_AdditionalScripting[] = _("Additional programming");
static const struct CreditsEntry sCreditsEntry_AdditionalScripting[] = {11, TRUE, sCreditsText_AdditionalScripting};
static const u8 sCreditsText_AddScript1[] = _("{FONT_NARROW}aueuaio   Blackforest92   daniilS   Delta231");
static const struct CreditsEntry sCreditsEntry_AddScript1[] = {11, FALSE, sCreditsText_AddScript1};
static const u8 sCreditsText_AddScript2[] = _("{FONT_NARROW}devolov   ellabrella   Faith120   FieryMewtwo");
static const struct CreditsEntry sCreditsEntry_AddScript2[] = {11, FALSE, sCreditsText_AddScript2};

static const u8 sCreditsText_AddScript3[] = _("{FONT_NARROW}hjk321   ipatix   Jaizu   jrz3");
static const struct CreditsEntry sCreditsEntry_AddScript3[] = {11, FALSE, sCreditsText_AddScript3};
static const u8 sCreditsText_AddScript4[] = _("{FONT_NARROW}ketsuban   Kurausukun   LOuroboros   Mkol103");
static const struct CreditsEntry sCreditsEntry_AddScript4[] = {11, FALSE, sCreditsText_AddScript4};

static const u8 sCreditsText_AddScript5[] = _("{FONT_NARROW}NotToDisturb   ProfLeonDiasBackup   Samu   ShinyDragonHunter");
static const struct CreditsEntry sCreditsEntry_AddScript5[] = {11, FALSE, sCreditsText_AddScript5};
static const u8 sCreditsText_AddScript6[] = _("{FONT_NARROW}SonikkuA-DatH   tustin2121   {FONT_NORMAL}{JPN}セケツ");
static const struct CreditsEntry sCreditsEntry_AddScript6[] = {11, FALSE, sCreditsText_AddScript6};

static const u8 sCreditsText_Porymap[] = _("Built using Porymap");
static const struct CreditsEntry sCreditsEntry_Porymap[] = {11, TRUE, sCreditsText_Porymap};
static const u8 sCreditsText_Porymap1[] = _("{FONT_NARROW}Created by huderlem");
static const struct CreditsEntry sCreditsEntry_Porymap1[] = {11, FALSE, sCreditsText_Porymap1};
static const u8 sCreditsText_Porymap2[] = _("{FONT_SMALL}Contributors: https://github.com/huderlem/\nporymap/graphs/contributors");
static const struct CreditsEntry sCreditsEntry_Porymap2[] = {11, FALSE, sCreditsText_Porymap2};

static const u8 sCreditsText_TilemapStudio[] = _("Built using Tilemap Studio");
static const struct CreditsEntry sCreditsEntry_TilemapStudio[] = {11, TRUE, sCreditsText_TilemapStudio};
static const u8 sCreditsText_TilemapStudio1[] = _("{FONT_NARROW}Created by Rangi42");
static const struct CreditsEntry sCreditsEntry_TilemapStudio1[] = {11, FALSE, sCreditsText_TilemapStudio1};
static const u8 sCreditsText_TilemapStudio2[] = _("{FONT_SMALL}https://github.com/Rangi42/tilemap-studio");
static const struct CreditsEntry sCreditsEntry_TilemapStudio2[] = {11, FALSE, sCreditsText_TilemapStudio2};

// Reserved space

static const u8 sCreditsText_PkmnEmeraldVersion[] = _("Pokémon Emerald Version");
static const struct CreditsEntry sCreditsEntry_PkmnEmeraldVersion[] = {11, TRUE, sCreditsText_PkmnEmeraldVersion};
static const u8 sCreditsText_OriginalCredits[] = _("Original credits");
static const struct CreditsEntry sCreditsEntry_OriginalCredits[] = {11, TRUE, sCreditsText_OriginalCredits};

static const u8 sCreditsText_Director[] = _("Director");
static const struct CreditsEntry sCreditsEntry_Director[] = {11, TRUE, sCreditsText_Director};
static const u8 sCreditsText_Director1[] = _("{FONT_NARROW}Shigeki Morimoto");
static const struct CreditsEntry sCreditsEntry_Director1[] = {11, FALSE, sCreditsText_Director1};

static const u8 sCreditsText_ArtDirector[] = _("Art director");
static const struct CreditsEntry sCreditsEntry_ArtDirector[] = {11, TRUE, sCreditsText_ArtDirector};
static const u8 sCreditsText_ArtDirector1[] = _("{FONT_NARROW}Ken Sugimori");
static const struct CreditsEntry sCreditsEntry_ArtDirector1[] = {11, FALSE, sCreditsText_ArtDirector1};
static const u8 sCreditsText_WorldDirector[] = _("World director");
static const struct CreditsEntry sCreditsEntry_WorldDirector[] = {11, TRUE, sCreditsText_WorldDirector};
static const u8 sCreditsText_WorldDirector1[] = _("{FONT_NARROW}Junichi Masuda");
static const struct CreditsEntry sCreditsEntry_WorldDirector1[] = {11, FALSE, sCreditsText_WorldDirector1};

static const u8 sCreditsText_Programmers[] = _("Programming");
static const struct CreditsEntry sCreditsEntry_Programmers[] = {11, TRUE, sCreditsText_Programmers};
static const u8 sCreditsText_Programmers1[] = _("{FONT_NARROW}Hisashi Sogabe - Lead");
static const struct CreditsEntry sCreditsEntry_Programmers1[] = {11, FALSE, sCreditsText_Programmers1};
static const u8 sCreditsText_Programmers2[] = _("{FONT_NARROW}Hisashi Sogabe   Tomomichi Ohta");
static const struct CreditsEntry sCreditsEntry_Programmers2[] = {11, FALSE, sCreditsText_Programmers2};
static const u8 sCreditsText_Programmers3[] = _("{FONT_NARROW}Nozomu Saito   Akito Mori");
static const struct CreditsEntry sCreditsEntry_Programmers3[] = {11, FALSE, sCreditsText_Programmers3};
static const u8 sCreditsText_Programmers4[] = _("{FONT_NARROW}Hiroyuki Nakamura   Masao Taya");
static const struct CreditsEntry sCreditsEntry_Programmers4[] = {11, FALSE, sCreditsText_Programmers4};

static const u8 sCreditsText_Programmers5[] = _("{FONT_NARROW}Satoshi Nohara   Miyuki Iwasawa");
static const struct CreditsEntry sCreditsEntry_Programmers5[] = {11, FALSE, sCreditsText_Programmers5};
static const u8 sCreditsText_Programmers6[] = _("{FONT_NARROW}Yoshinori Matsuda   Keita Kagaya");
static const struct CreditsEntry sCreditsEntry_Programmers6[] = {11, FALSE, sCreditsText_Programmers6};
static const u8 sCreditsText_Programmers7[] = _("{FONT_NARROW}Tetsuya Watanabe   Sosuke Tamada");
static const struct CreditsEntry sCreditsEntry_Programmers7[] = {11, FALSE, sCreditsText_Programmers7};
static const u8 sCreditsText_Programmers8[] = _("{FONT_NARROW}Takenori Ohta  Teruki Murakawa");
static const struct CreditsEntry sCreditsEntry_Programmers8[] = {11, FALSE, sCreditsText_Programmers8};

static const u8 sCreditsText_Programmers9[] = _("{FONT_NARROW}Souichi Yamamoto   Yuichiro Ito");
static const struct CreditsEntry sCreditsEntry_Programmers9[] = {11, FALSE, sCreditsText_Programmers9};
static const u8 sCreditsText_Programmers10[] = _("{FONT_NARROW}Akira Kinashi");
static const struct CreditsEntry sCreditsEntry_Programmers10[] = {11, FALSE, sCreditsText_Programmers10};

static const u8 sCreditsText_GraphicArtists[] = _("Graphic designers");
static const struct CreditsEntry sCreditsEntry_GraphicArtists[] = {11, TRUE, sCreditsText_GraphicArtists};
static const u8 sCreditsText_GraphicArtists1[] = _("{FONT_NARROW}Motofumi Fujiwara - Lead");
static const struct CreditsEntry sCreditsEntry_GraphicArtists1[] = {11, FALSE, sCreditsText_GraphicArtists1};
static const u8 sCreditsText_GraphicArtists2[] = _("{FONT_NARROW}Motofumi Fujiwara   Satoshi Ohta");
static const struct CreditsEntry sCreditsEntry_GraphicArtists2[] = {11, FALSE, sCreditsText_GraphicArtists2};
static const u8 sCreditsText_GraphicArtists3[] = _("{FONT_NARROW}Kenkichi Toyama   Asuka Iwashita");
static const struct CreditsEntry sCreditsEntry_GraphicArtists3[] = {11, FALSE, sCreditsText_GraphicArtists3};
static const u8 sCreditsText_GraphicArtists4[] = _("{FONT_NARROW}Takao Unno   Ken Sugimori");
static const struct CreditsEntry sCreditsEntry_GraphicArtists4[] = {11, FALSE, sCreditsText_GraphicArtists4};

static const u8 sCreditsText_GraphicArtists5[] = _("{FONT_NARROW}Hironobu Yoshida   Aimi Tomita");
static const struct CreditsEntry sCreditsEntry_GraphicArtists5[] = {11, FALSE, sCreditsText_GraphicArtists5};
static const u8 sCreditsText_GraphicArtists6[] = _("{FONT_NARROW}Kanako Eo   Akira Kinashi");
static const struct CreditsEntry sCreditsEntry_GraphicArtists6[] = {11, FALSE, sCreditsText_GraphicArtists6};

static const u8 sCreditsText_MusicComposition[] = _("Music composers");
static const struct CreditsEntry sCreditsEntry_MusicComposition[] = {11, TRUE, sCreditsText_MusicComposition};
static const u8 sCreditsText_MusicComposition1[] = _("{FONT_NARROW}Go Ichinose   Junichi Masuda");
static const struct CreditsEntry sCreditsEntry_MusicComposition1[] = {11, FALSE, sCreditsText_MusicComposition1};
static const u8 sCreditsText_MusicComposition2[] = _("{FONT_NARROW}Morikazu Aoki   Hitomi Sato");
static const struct CreditsEntry sCreditsEntry_MusicComposition2[] = {11, FALSE, sCreditsText_MusicComposition2};
static const u8 sCreditsText_SoundEffects[] = _("Sound effects & Pokémon voices");
static const struct CreditsEntry sCreditsEntry_SoundEffects[] = {11, TRUE, sCreditsText_SoundEffects};
static const u8 sCreditsText_SoundEffects1[] = _("{FONT_NARROW}Go Ichinose   Morikazu Aoki");
static const struct CreditsEntry sCreditsEntry_SoundEffects1[] = {11, FALSE, sCreditsText_SoundEffects1};

static const u8 sCreditsText_GameDesigners[] = _("Game designers");
static const struct CreditsEntry sCreditsEntry_GameDesigners[] = {11, TRUE, sCreditsText_GameDesigners};
static const u8 sCreditsText_GameDesigners1[] = _("{FONT_NARROW}Shigeki Morimoto   Teruyuki Shimoyamada");
static const struct CreditsEntry sCreditsEntry_GameDesigners1[] = {11, FALSE, sCreditsText_GameDesigners1};
static const u8 sCreditsText_GameDesigners2[] = _("{FONT_NARROW}Takeshi Kawachimaru   Akihito Tomisawa");
static const struct CreditsEntry sCreditsEntry_GameDesigners2[] = {11, FALSE, sCreditsText_GameDesigners2};
static const u8 sCreditsText_GameDesigners3[] = _("{FONT_NARROW}Suguru Nakatsui   Tetsuji Ohta");
static const struct CreditsEntry sCreditsEntry_GameDesigners3[] = {11, FALSE, sCreditsText_GameDesigners3};
static const u8 sCreditsText_GameDesigners4[] = _("{FONT_NARROW}Hitomi Sato   Kenji Matsushima");
static const struct CreditsEntry sCreditsEntry_GameDesigners4[] = {11, FALSE, sCreditsText_GameDesigners4};

static const u8 sCreditsText_GameDesigners5[] = _("{FONT_NARROW}Junichi Masuda   Koji Nishino");
static const struct CreditsEntry sCreditsEntry_GameDesigners5[] = {11, FALSE, sCreditsText_GameDesigners5};
static const u8 sCreditsText_GameDesigners6[] = _("{FONT_NARROW}Shigeru Ohmori   Tadashi Takahashi");
static const struct CreditsEntry sCreditsEntry_GameDesigners6[] = {11, FALSE, sCreditsText_GameDesigners6};

static const u8 sCreditsText_Scenario1[] = _("{FONT_NARROW}Akihito Tomisawa   Junichi Masuda");
static const struct CreditsEntry sCreditsEntry_Scenario1[] = {11, FALSE, sCreditsText_Scenario1};
static const u8 sCreditsText_Scenario2[] = _("{FONT_NARROW}Koji Nishino   Akihito Tomisawa");
static const struct CreditsEntry sCreditsEntry_Scenario2[] = {11, FALSE, sCreditsText_Scenario2};
static const u8 sCreditsText_Scenario3[] = _("{FONT_NARROW}Hitomi Sato   Toshinobu Matsumiya");
static const struct CreditsEntry sCreditsEntry_Scenario3[] = {11, FALSE, sCreditsText_Scenario3};

static const u8 sCreditsText_Scripting[] = _("Script designers");
static const struct CreditsEntry sCreditsEntry_Scripting[] = {11, TRUE, sCreditsText_Scripting};
static const u8 sCreditsText_Scripting1[] = _("{FONT_NARROW}Tomomichi Ohta   Satoshi Nohara");
static const struct CreditsEntry sCreditsEntry_Scripting1[] = {11, FALSE, sCreditsText_Scripting1};
static const u8 sCreditsText_MapDesign[] = _("Map designers");
static const struct CreditsEntry sCreditsEntry_MapDesign[] = {11, TRUE, sCreditsText_MapDesign};
static const u8 sCreditsText_MapDesign1[] = _("{FONT_NARROW}Suguru Nakatsui   Teruyuki Shimoyamada");
static const struct CreditsEntry sCreditsEntry_MapDesign1[] = {11, FALSE, sCreditsText_MapDesign1};
static const u8 sCreditsText_MapDesign2[] = _("{FONT_NARROW}Shigeru Ohmori   Tetsuji Ohta");
static const struct CreditsEntry sCreditsEntry_MapDesign2[] = {11, FALSE, sCreditsText_MapDesign2};

static const u8 sCreditsText_BFData[] = _("Battle Frontier data");
static const struct CreditsEntry sCreditsEntry_BFData[] = {11, TRUE, sCreditsText_BFData};
static const u8 sCreditsText_BFData1[] = _("{FONT_NARROW}Tetsuji Ohta");
static const struct CreditsEntry sCreditsEntry_BFData1[] = {11, FALSE, sCreditsText_BFData1};
static const u8 sCreditsText_Parametrics[] = _("Parametric designers");
static const struct CreditsEntry sCreditsEntry_Parametrics[] = {11, TRUE, sCreditsText_Parametrics};
static const u8 sCreditsText_Parametrics1[] = _("{FONT_NARROW}Teruyuki Shimoyamada   Shigeki Morimoto");
static const struct CreditsEntry sCreditsEntry_Parametrics1[] = {11, FALSE, sCreditsText_Parametrics1};
static const u8 sCreditsText_Parametrics2[] = _("{FONT_NARROW}Tetsuji Ohta   Koji Nishino");
static const struct CreditsEntry sCreditsEntry_Parametrics2[] = {11, FALSE, sCreditsText_Parametrics2};

static const u8 sCreditsText_DexText[] = _("Pokédex text");
static const struct CreditsEntry sCreditsEntry_DexText[] = {11, TRUE, sCreditsText_DexText};
static const u8 sCreditsText_DexText1[] = _("{FONT_NARROW}Kenji Matsushima");
static const struct CreditsEntry sCreditsEntry_DexText1[] = {11, FALSE, sCreditsText_DexText1};
static const u8 sCreditsText_ToolProg[] = _("Environment & tool programming");
static const struct CreditsEntry sCreditsEntry_ToolProg[] = {11, TRUE, sCreditsText_ToolProg};
static const u8 sCreditsText_ToolProg1[] = _("{FONT_NARROW}Hisashi Sogabe   Sosuke Tamada");
static const struct CreditsEntry sCreditsEntry_ToolProg1[] = {11, FALSE, sCreditsText_ToolProg1};
static const u8 sCreditsText_ToolProg2[] = _("{FONT_NARROW}Hiroyuki Nakamura   Akito Mori");
static const struct CreditsEntry sCreditsEntry_ToolProg2[] = {11, FALSE, sCreditsText_ToolProg2};

static const u8 sCreditsText_ToolProg3[] = _("{FONT_NARROW}Teruki Murakawa   Souichi Yamamoto");
static const struct CreditsEntry sCreditsEntry_ToolProg3[] = {11, FALSE, sCreditsText_ToolProg3};
static const u8 sCreditsText_ToolProg4[] = _("{FONT_NARROW}Kimiko Nakamichi");
static const struct CreditsEntry sCreditsEntry_ToolProg4[] = {11, FALSE, sCreditsText_ToolProg4};

static const u8 sCreditsText_PkmnDesign[] = _("Pokémon design");
static const struct CreditsEntry sCreditsEntry_PkmnDesign[] = {11, TRUE, sCreditsText_PkmnDesign};
static const u8 sCreditsText_PkmnDesign1[] = _("{FONT_NARROW}Ken Sugimori   Motofumi Fujiwara");
static const struct CreditsEntry sCreditsEntry_PkmnDesign1[] = {11, FALSE, sCreditsText_PkmnDesign1};
static const u8 sCreditsText_PkmnDesign2[] = _("{FONT_NARROW}Shigeki Morimoto   Hironobu Yoshida");
static const struct CreditsEntry sCreditsEntry_PkmnDesign2[] = {11, FALSE, sCreditsText_PkmnDesign2};
static const u8 sCreditsText_PkmnDesign3[] = _("{FONT_NARROW}Satoshi Ohta   Asuka Iwashita");
static const struct CreditsEntry sCreditsEntry_PkmnDesign3[] = {11, FALSE, sCreditsText_PkmnDesign3};
static const u8 sCreditsText_PkmnDesign4[] = _("{FONT_NARROW}Takao Unno   Kanako Eo");
static const struct CreditsEntry sCreditsEntry_PkmnDesign4[] = {11, FALSE, sCreditsText_PkmnDesign4};

static const u8 sCreditsText_PkmnDesign5[] = _("{FONT_NARROW}Aimi Tomita   Atsuko Nishida");
static const struct CreditsEntry sCreditsEntry_PkmnDesign5[] = {11, FALSE, sCreditsText_PkmnDesign5};
static const u8 sCreditsText_PkmnDesign6[] = _("{FONT_NARROW}Muneo Saito   Rena Yoshikawa");
static const struct CreditsEntry sCreditsEntry_PkmnDesign6[] = {11, FALSE, sCreditsText_PkmnDesign6};
static const u8 sCreditsText_PkmnDesign7[] = _("{FONT_NARROW}Jun Okutani");
static const struct CreditsEntry sCreditsEntry_PkmnDesign7[] = {11, FALSE, sCreditsText_PkmnDesign7};

static const u8 sCreditsText_ProgSupport1[] = _("{FONT_NARROW}Satoshi Mitsuhara  Daisuke Hoshino");
static const struct CreditsEntry sCreditsEntry_ProgSupport1[] = {11, FALSE, sCreditsText_ProgSupport1};
static const u8 sCreditsText_NCLTesting[] = _("NCL product testers");
static const struct CreditsEntry sCreditsEntry_NCLTesting[] = {11, TRUE, sCreditsText_NCLTesting};
static const u8 sCreditsText_NCLTesting1[] = _("{FONT_NARROW}NCL Super Mario Club");
static const struct CreditsEntry sCreditsEntry_NCLTesting1[] = {11, FALSE, sCreditsText_NCLTesting1};

static const u8 sCreditsText_Manual[] = _("Package & manual illustrator");
static const struct CreditsEntry sCreditsEntry_Manual[] = {11, TRUE, sCreditsText_Manual};
static const u8 sCreditsText_Manual1[] = _("{FONT_NARROW}Ken Sugimori");
static const struct CreditsEntry sCreditsEntry_Manual1[] = {11, FALSE, sCreditsText_Manual1};
static const u8 sCreditsText_SpecialThanks[] = _("Special thanks");
static const struct CreditsEntry sCreditsEntry_SpecialThanks[] = {11, TRUE, sCreditsText_SpecialThanks};
static const u8 sCreditsText_SpecialThanks1[] = _("{FONT_NARROW}Kenji Tominaga   Hiroki Enomoto");
static const struct CreditsEntry sCreditsEntry_SpecialThanks1[] = {11, FALSE, sCreditsText_SpecialThanks1};
static const u8 sCreditsText_SpecialThanks2[] = _("{FONT_NARROW}Kazuya Suyama   Kenjiro Ito");
static const struct CreditsEntry sCreditsEntry_SpecialThanks2[] = {11, FALSE, sCreditsText_SpecialThanks2};

static const u8 sCreditsText_SpecialThanks3[] = _("{FONT_NARROW}Michiko Takizawa   Makiko Takada");
static const struct CreditsEntry sCreditsEntry_SpecialThanks3[] = {11, FALSE, sCreditsText_SpecialThanks3};
static const u8 sCreditsText_SpecialThanks4[] = _("{FONT_NARROW}Mikiko Ohhashi   Takanao Kondo");
static const struct CreditsEntry sCreditsEntry_SpecialThanks4[] = {11, FALSE, sCreditsText_SpecialThanks4};
static const u8 sCreditsText_SpecialThanks5[] = _("{FONT_NARROW}Rui Kawaguchi   Takahiro Ohnishi");
static const struct CreditsEntry sCreditsEntry_SpecialThanks5[] = {11, FALSE, sCreditsText_SpecialThanks5};
static const u8 sCreditsText_SpecialThanks6[] = _("{FONT_NARROW}Norihide Okamura   Shunsuke Kohori");
static const struct CreditsEntry sCreditsEntry_SpecialThanks6[] = {11, FALSE, sCreditsText_SpecialThanks6};

static const u8 sCreditsText_SpecialThanks7[] = _("{FONT_NARROW}Hiroyuki Uesugi   Motoyasu Tojima");
static const struct CreditsEntry sCreditsEntry_SpecialThanks7[] = {11, FALSE, sCreditsText_SpecialThanks7};
static const u8 sCreditsText_SpecialThanks8[] = _("{FONT_NARROW}Nicola Pratt-Barlow   Shellie Dow");
static const struct CreditsEntry sCreditsEntry_SpecialThanks8[] = {11, FALSE, sCreditsText_SpecialThanks8};

static const u8 sCreditsText_InfoSpv[] = _("Information supervisors");
static const struct CreditsEntry sCreditsEntry_InfoSpv[] = {11, TRUE, sCreditsText_InfoSpv};
static const u8 sCreditsText_InfoSpv1[] = _("{FONT_NARROW}Kazuyuki Terada   Yuri Sakurai");
static const struct CreditsEntry sCreditsEntry_InfoSpv1[] = {11, FALSE, sCreditsText_InfoSpv1};
static const u8 sCreditsText_InfoSpv2[] = _("{FONT_NARROW}Yumi Funasaka   Naoko Yanase");
static const struct CreditsEntry sCreditsEntry_InfoSpv2[] = {11, FALSE, sCreditsText_InfoSpv2};
static const u8 sCreditsText_Artwork[] = _("Artists");
static const struct CreditsEntry sCreditsEntry_Artwork[] = {11, TRUE, sCreditsText_Artwork};
static const u8 sCreditsText_Artwork1[] = _("{FONT_NARROW}Sachiko Nakamichi   Fujiko Nomura");
static const struct CreditsEntry sCreditsEntry_Artwork1[] = {11, FALSE, sCreditsText_Artwork1};

static const u8 sCreditsText_Artwork2[] = _("{FONT_NARROW}Hideyuki Nakajima   Hidenori Saeki");
static const struct CreditsEntry sCreditsEntry_Artwork2[] = {11, FALSE, sCreditsText_Artwork2};
static const u8 sCreditsText_Artwork3[] = _("{FONT_NARROW}Yoko Watanabe   Sakae Kimura");
static const struct CreditsEntry sCreditsEntry_Artwork3[] = {11, FALSE, sCreditsText_Artwork3};
static const u8 sCreditsText_Artwork4[] = _("{FONT_NARROW}Chiaki Shinkai");
static const struct CreditsEntry sCreditsEntry_Artwork4[] = {11, FALSE, sCreditsText_Artwork4};

static const u8 sCreditsText_Coordination[] = _("Coordinators");
static const struct CreditsEntry sCreditsEntry_Coordination[] = {11, TRUE, sCreditsText_Coordination};
static const u8 sCreditsText_Coordination1[] = _("{FONT_NARROW}Kazuki Yoshihara   Akira Kinashi");
static const struct CreditsEntry sCreditsEntry_Coordination1[] = {11, FALSE, sCreditsText_Coordination1};
static const u8 sCreditsText_Coordination2[] = _("{FONT_NARROW}Retsuji Nomoto");
static const struct CreditsEntry sCreditsEntry_Coordination2[] = {11, FALSE, sCreditsText_Coordination2};
static const u8 sCreditsText_Coordination3[] = _("English version coordinators");
static const struct CreditsEntry sCreditsEntry_Coordination3[] = {11, TRUE, sCreditsText_Coordination3};
static const u8 sCreditsText_Coordination4[] = _("{FONT_NARROW}Hiro Nakamura   Seth McMahill");
static const struct CreditsEntry sCreditsEntry_Coordination4[] = {11, FALSE, sCreditsText_Coordination4};

static const u8 sCreditsText_Translation[] = _("Translator");
static const struct CreditsEntry sCreditsEntry_Translation[] = {11, TRUE, sCreditsText_Translation};
static const u8 sCreditsText_Translation1[] = _("{FONT_NARROW}Nob Ogasawara");
static const struct CreditsEntry sCreditsEntry_Translation1[] = {11, FALSE, sCreditsText_Translation1};
static const u8 sCreditsText_TextEdit[] = _("Text editor");
static const struct CreditsEntry sCreditsEntry_TextEdit[] = {11, TRUE, sCreditsText_TextEdit};
static const u8 sCreditsText_TextEdit1[] = _("{FONT_NARROW}Teresa Lillygren");
static const struct CreditsEntry sCreditsEntry_TextEdit1[] = {11, FALSE, sCreditsText_TextEdit1};

static const u8 sCreditsText_NCLcoord[] = _("NCL coordinator");
static const struct CreditsEntry sCreditsEntry_NCLcoord[] = {11, TRUE, sCreditsText_NCLcoord};
static const u8 sCreditsText_NCLcoord1[] = _("{FONT_NARROW}Kimiko Nakamichi");
static const struct CreditsEntry sCreditsEntry_NCLcoord1[] = {11, FALSE, sCreditsText_NCLcoord1};
static const u8 sCreditsText_NOAtest[] = _("NOA product testers");
static const struct CreditsEntry sCreditsEntry_NOAtest[] = {11, TRUE, sCreditsText_NOAtest};
static const u8 sCreditsText_NOAtest1[] = _("{FONT_NARROW}Thomas Hertzog   Erik Johnson");
static const struct CreditsEntry sCreditsEntry_NOAtest1[] = {11, FALSE, sCreditsText_NOAtest1};
static const u8 sCreditsText_NOAtest2[] = _("{FONT_NARROW}Mika Kurosawa");
static const struct CreditsEntry sCreditsEntry_NOAtest2[] = {11, FALSE, sCreditsText_NOAtest2};

static const u8 sCreditsText_Braille[] = _("Braille code checkers");
static const struct CreditsEntry sCreditsEntry_Braille[] = {11, TRUE, sCreditsText_Braille};
static const u8 sCreditsText_Braille1[] = _("{FONT_NARROW}National Federation of the Blind");
static const struct CreditsEntry sCreditsEntry_Braille1[] = {11, FALSE, sCreditsText_Braille1};
static const u8 sCreditsText_Braille1b[] = _("{FONT_NARROW}Patricia A. Maurer");
static const struct CreditsEntry sCreditsEntry_Braille1b[] = {11, FALSE, sCreditsText_Braille1b};
static const u8 sCreditsText_Braille2[] = _("{FONT_NARROW}Japan Braille Library");
static const struct CreditsEntry sCreditsEntry_Braille2[] = {11, FALSE, sCreditsText_Braille2};
static const u8 sCreditsText_Braille3[] = _("{FONT_NARROW}European Blind Union");
static const struct CreditsEntry sCreditsEntry_Braille3[] = {11, FALSE, sCreditsText_Braille3};

static const u8 sCreditsText_Braille4[] = _("{FONT_NARROW}Australian Braille Authority");
static const struct CreditsEntry sCreditsEntry_Braille4[] = {11, FALSE, sCreditsText_Braille4};
static const u8 sCreditsText_Braille5[] = _("{FONT_NARROW}Blind Low Vision NZ");
static const struct CreditsEntry sCreditsEntry_Braille5[] = {11, FALSE, sCreditsText_Braille5};

static const u8 sCreditsText_Taskmgr[] = _("Task managers");
static const struct CreditsEntry sCreditsEntry_Taskmgr[] = {11, TRUE, sCreditsText_Taskmgr};
static const u8 sCreditsText_Taskmgr1[] = _("{FONT_NARROW}Azusa Tajima   Shusaku Egami");
static const struct CreditsEntry sCreditsEntry_Taskmgr1[] = {11, FALSE, sCreditsText_Taskmgr1};
static const u8 sCreditsText_Producers[] = _("Producers");
static const struct CreditsEntry sCreditsEntry_Producers[] = {11, TRUE, sCreditsText_Producers};
static const u8 sCreditsText_Producers1[] = _("{FONT_NARROW}Hiroyuki Jinnai   Hitoshi Yamagami");
static const struct CreditsEntry sCreditsEntry_Producers1[] = {11, FALSE, sCreditsText_Producers1};
static const u8 sCreditsText_Producers2[] = _("{FONT_NARROW}Gakuji Nomoto   Hiroaki Tsuru");
static const struct CreditsEntry sCreditsEntry_Producers2[] = {11, FALSE, sCreditsText_Producers2};

static const u8 sCreditsText_Execdir[] = _("Executive director");
static const struct CreditsEntry sCreditsEntry_Execdir[] = {11, TRUE, sCreditsText_Execdir};
static const u8 sCreditsText_Execdir1[] = _("{FONT_NARROW}Satoshi Tajiri");
static const struct CreditsEntry sCreditsEntry_Execdir1[] = {11, FALSE, sCreditsText_Execdir1};
static const u8 sCreditsText_Execprod[] = _("Executive producers");
static const struct CreditsEntry sCreditsEntry_Execprod[] = {11, TRUE, sCreditsText_Execprod};
static const u8 sCreditsText_Execprod1[] = _("{FONT_NARROW}Satoru Iwata");
static const struct CreditsEntry sCreditsEntry_Execprod1[] = {11, FALSE, sCreditsText_Execprod1};
static const u8 sCreditsText_Execprod2[] = _("{FONT_NARROW}Tsunekaz Ishihara");
static const struct CreditsEntry sCreditsEntry_Execprod2[] = {11, FALSE, sCreditsText_Execprod2};

static const u8 sCreditsText_DevelopedBy[] = _("Developed by");
static const struct CreditsEntry sCreditsEntry_DevelopedBy[] = {11, TRUE, sCreditsText_DevelopedBy};
static const u8 sCreditsText_DevelopedBy1[] = _("{FONT_NARROW}GAME FREAK inc.");
static const struct CreditsEntry sCreditsEntry_DevelopedBy1[] = {11, FALSE, sCreditsText_DevelopedBy1};

static const u8 sCreditsText_Reserved[] = _("- Page reserved -");
static const struct CreditsEntry sCreditsEntry_Reserved[] = {11, TRUE, sCreditsText_Reserved};


#define _ sCreditsEntry_EmptyString
static const struct CreditsEntry *const sCreditsEntryPointerTable[PAGE_COUNT][ENTRIES_PER_PAGE] =
{
    [PAGE_TITLE] = {
        _,
        sCreditsEntry_PkmnRainbowAmnesty,
        sCreditsEntry_Credits,
        _,
        _,
    },
    [PAGE_DIRECTOR] = {
        sCreditsEntry_CreatedBy,
        sCreditsEntry_POKeMIKE,
        sCreditsEntry_Scenario,
        sCreditsEntry_mattmck,
        _,
    },
    [PAGE_ART_DIRECTOR] = {
        sCreditsEntry_PokemonEmeraldDecomp,
        sCreditsEntry_pret,
        _,
        sCreditsEntry_pokeemeraldContrib,
        _,
    },
    [PAGE_WORLD_DIRECTOR] = {
        sCreditsEntry_pokeemeraldExpansion,
        sCreditsEntry_DizzyEggg,
        sCreditsEntry_MaintainedBy,
        sCreditsEntry_ExpansionMaintain1,
        sCreditsEntry_ExpansionMaintain2,
    },
    [PAGE_LEAD_PROGRAMMER] = {
        sCreditsEntry_pokeemeraldExpansion2,
        sCreditsEntry_MainContributors,
        sCreditsEntry_ExpansionCredit1,
        sCreditsEntry_ExpansionCredit2,
        sCreditsEntry_ExpansionCredit3,
    },
    [PAGE_PROGRAMMERS_1] = {
        sCreditsEntry_pokeemeraldExpansion2,
        _,
        sCreditsEntry_ExpansionContrib,
        _,
        _,
    },
    [PAGE_PROGRAMMERS_2] = {
        _,
        sCreditsEntry_PkmnRainbowAmnesty,
        sCreditsEntry_DebuggingSupport,
        sCreditsEntry_DebugSupport1,
        _,
    },
    [PAGE_PROGRAMMERS_3] = {
        sCreditsEntry_AdditionalScripting,
        sCreditsEntry_AddScript1,
        sCreditsEntry_AddScript2,
        sCreditsEntry_AddScript3,
        sCreditsEntry_AddScript4,
    },
    [PAGE_PROGRAMMERS_4] = {
        sCreditsEntry_AdditionalScripting,
        sCreditsEntry_AddScript5,
        sCreditsEntry_AddScript6,
        _,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_1] = {
        sCreditsEntry_Porymap,
        sCreditsEntry_Porymap1,
        _,
        sCreditsEntry_Porymap2,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_2] = {
        sCreditsEntry_TilemapStudio,
        sCreditsEntry_TilemapStudio1,
        _,
        sCreditsEntry_TilemapStudio2,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_3] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_MUSIC_COMPOSITION] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_SOUND_EFFECTS] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_GAME_DESIGNERS_1] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_GAME_DESIGNERS_2] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_GAME_DESIGNERS_3] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_SCENARIO_PLOT] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_SCENARIO] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_SCRIPT_DESIGNERS] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_MAP_DESIGNERS] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_BATTLE_FRONTIER_DATA] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_PARAMETRIC_DESIGNERS] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_POKEDEX_TEXT] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_1] = {
        _,
        sCreditsEntry_Reserved,
        _,
        _,
        _,
    },
    [PAGE_PKMN_DESIGNERS_1] = {
        _,
        sCreditsEntry_PkmnEmeraldVersion,
        sCreditsEntry_OriginalCredits,
        _,
        _,
    },
    [PAGE_PKMN_DESIGNERS_2] = {
        _,
        sCreditsEntry_Director,
        sCreditsEntry_Director1,
        _,
        _,
    },
    [PAGE_PKMN_DESIGNERS_3] = {
        sCreditsEntry_ArtDirector,
        sCreditsEntry_ArtDirector1,
        sCreditsEntry_WorldDirector,
        sCreditsEntry_WorldDirector1,
        _,
    },
    [PAGE_PKMN_DESIGNERS_4] = {
        sCreditsEntry_Programmers,
        sCreditsEntry_Programmers1,
        sCreditsEntry_Programmers2,
        sCreditsEntry_Programmers3,
        sCreditsEntry_Programmers4,
    },
    [PAGE_SUPPORT_PROGRAMMERS] = {
        sCreditsEntry_Programmers,
        sCreditsEntry_Programmers5,
        sCreditsEntry_Programmers6,
        sCreditsEntry_Programmers7,
        sCreditsEntry_Programmers8,
    },
    [PAGE_NCL_PRODUCT_TESTING] = {
        sCreditsEntry_Programmers,
        sCreditsEntry_Programmers9,
        sCreditsEntry_Programmers10,
        _,
        _,
    },
    [PAGE_PACKAGE_AND_MANUAL] = {
        sCreditsEntry_GraphicArtists,
        sCreditsEntry_GraphicArtists1,
        sCreditsEntry_GraphicArtists2,
        sCreditsEntry_GraphicArtists3,
        sCreditsEntry_GraphicArtists4,
    },
    [PAGE_SPECIAL_THANKS_1] = {
        sCreditsEntry_GraphicArtists,
        sCreditsEntry_GraphicArtists5,
        sCreditsEntry_GraphicArtists6,
        _,
        _,
    },
    [PAGE_SPECIAL_THANKS_2] = {
        sCreditsEntry_MusicComposition,
        sCreditsEntry_MusicComposition1,
        sCreditsEntry_MusicComposition2,
        sCreditsEntry_SoundEffects,
        sCreditsEntry_SoundEffects1,
    },
    [PAGE_SPECIAL_THANKS_3] = {
        sCreditsEntry_GameDesigners,
        sCreditsEntry_GameDesigners1,
        sCreditsEntry_GameDesigners2,
        sCreditsEntry_GameDesigners3,
        sCreditsEntry_GameDesigners4,
    },
    [PAGE_SPECIAL_THANKS_4] = {
        sCreditsEntry_GameDesigners,
        sCreditsEntry_GameDesigners5,
        sCreditsEntry_GameDesigners6,
        _,
        _,
    },
    [PAGE_INFORMATION_SUPERVISORS] = {
        sCreditsEntry_Scenario,
        sCreditsEntry_Scenario1,
        sCreditsEntry_Scenario2,
        sCreditsEntry_Scenario3,
        _,
    },
    [PAGE_ARTWORK_1] = {
        sCreditsEntry_Scripting,
        sCreditsEntry_Scripting1,
        sCreditsEntry_MapDesign,
        sCreditsEntry_MapDesign1,
        sCreditsEntry_MapDesign2,
    },
    [PAGE_ARTWORK_2] = {
        sCreditsEntry_BFData,
        sCreditsEntry_BFData1,
        sCreditsEntry_Parametrics,
        sCreditsEntry_Parametrics1,
        sCreditsEntry_Parametrics2,
    },
    [PAGE_ARTWORK_3] = {
        sCreditsEntry_DexText,
        sCreditsEntry_DexText1,
        sCreditsEntry_ToolProg,
        sCreditsEntry_ToolProg1,
        sCreditsEntry_ToolProg2,
    },
    [PAGE_COORDINATORS] = {
        sCreditsEntry_ToolProg,
        sCreditsEntry_ToolProg3,
        sCreditsEntry_ToolProg4,
        _,
        _,
    },
    [PAGE_ENGLISH_VERSION] = {
        sCreditsEntry_PkmnDesign,
        sCreditsEntry_PkmnDesign1,
        sCreditsEntry_PkmnDesign2,
        sCreditsEntry_PkmnDesign3,
        sCreditsEntry_PkmnDesign4,
    },
    [PAGE_TRANSLATOR] = {
        sCreditsEntry_PkmnDesign,
        sCreditsEntry_PkmnDesign5,
        sCreditsEntry_PkmnDesign6,
        sCreditsEntry_PkmnDesign7,
        _,
    },
    [PAGE_TEXT_EDITOR] = {
        sCreditsEntry_DebuggingSupport,
        sCreditsEntry_ProgSupport1,
        sCreditsEntry_NCLTesting,
        sCreditsEntry_NCLTesting1,
        _,
    },
    [PAGE_NCL_COORDINATOR] = {
        sCreditsEntry_Manual,
        sCreditsEntry_Manual1,
        sCreditsEntry_SpecialThanks,
        sCreditsEntry_SpecialThanks1,
        sCreditsEntry_SpecialThanks2,
    },
    [PAGE_PROGRAMMERS_5] = {
        sCreditsEntry_SpecialThanks,
        sCreditsEntry_SpecialThanks3,
        sCreditsEntry_SpecialThanks4,
        sCreditsEntry_SpecialThanks5,
        sCreditsEntry_SpecialThanks6,
    },
    [PAGE_GRAPHIC_DESIGNER] = {
        sCreditsEntry_SpecialThanks,
        sCreditsEntry_SpecialThanks7,
        sCreditsEntry_SpecialThanks8,
        _,
        _,
    },
    [PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_2] = {
        sCreditsEntry_InfoSpv,
        sCreditsEntry_InfoSpv1,
        sCreditsEntry_InfoSpv2,
        sCreditsEntry_Artwork,
        sCreditsEntry_Artwork1,
    },
    [PAGE_NOA_TESTING] = {
        sCreditsEntry_Artwork,
        sCreditsEntry_Artwork2,
        sCreditsEntry_Artwork3,
        sCreditsEntry_Artwork4,
        _,
    },
    [PAGE_BRAILLE_CODE_CHECK_1] = {
        sCreditsEntry_Coordination,
        sCreditsEntry_Coordination1,
        sCreditsEntry_Coordination2,
        sCreditsEntry_Coordination3,
        sCreditsEntry_Coordination4,
    },
    [PAGE_BRAILLE_CODE_CHECK_2] = {
        sCreditsEntry_Translation,
        sCreditsEntry_Translation1,
        sCreditsEntry_TextEdit,
        sCreditsEntry_TextEdit1,
        _,
    },
    [PAGE_SPECIAL_THANKS_5] = {
        sCreditsEntry_NCLcoord,
        sCreditsEntry_NCLcoord1,
        sCreditsEntry_NOAtest,
        sCreditsEntry_NOAtest1,
        sCreditsEntry_NOAtest2,
    },
    [PAGE_TASK_MANAGERS] = {
        sCreditsEntry_Braille,
        sCreditsEntry_Braille1,
        sCreditsEntry_Braille1b,
        sCreditsEntry_Braille2,
        sCreditsEntry_Braille3,
    },
    [PAGE_PRODUCERS] = {
        sCreditsEntry_Braille,
        sCreditsEntry_Braille4,
        sCreditsEntry_Braille5,
        _,
        _,
    },
    [PAGE_EXECUTIVE_DIRECTOR] = {
        sCreditsEntry_Taskmgr,
        sCreditsEntry_Taskmgr1,
        sCreditsEntry_Producers,
        sCreditsEntry_Producers1,
        sCreditsEntry_Producers2,
    },
    [PAGE_EXECUTIVE_PRODUCERS_1] = {
        sCreditsEntry_Execdir,
        sCreditsEntry_Execdir1,
        sCreditsEntry_Execprod,
        sCreditsEntry_Execprod1,
        sCreditsEntry_Execprod2,
    },
    [PAGE_EXECUTIVE_PRODUCERS_2] = {
        _,
        sCreditsEntry_DevelopedBy,
        sCreditsEntry_DevelopedBy1,
        _,
        _,
    },
};
#undef _
