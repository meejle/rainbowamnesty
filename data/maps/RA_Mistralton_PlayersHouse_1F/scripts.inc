RA_Mistralton_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RA_PlayersHouse_1F_Script_OnTransition
	.byte 0

RA_PlayersHouse_1F_Script_OnTransition:
	clearflag FLAG_RA_WATCHING_CREDITS
	end

RA_PlayersHouse_1F_Script_ShouldIFridge::
	lockall
	msgbox RA_PlayersHouse_1F_Text_ShouldIFridge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RA_PlayersHouse_1F_Script_FoundBadgeInFridge
	goto_if_eq VAR_RESULT, NO, RA_PlayersHouse_1F_Script_DontPlayCredits
	end

RA_PlayersHouse_1F_Script_FoundBadgeInFridge::
	goto_if_set FLAG_BADGE08_GET, RA_PlayersHouse_1F_Script_FridgeIsEmpty
	msgbox RA_PlayersHouse_1F_Text_FridgeLetter, MSGBOX_DEFAULT
	call RA_Player_Gain_Rank
	call_if_unset FLAG_BADGE00_GET, RA_Player_Gain_PokePass
	call RA_Player_Gain_Badge
	releaseall
	end

RA_PlayersHouse_1F_Script_FridgeIsEmpty::
	call RA_Player_ThreeDots
	msgbox RA_PlayersHouse_1F_Text_FridgeIsEmpty, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_ShouldISink::
	lockall
	msgbox RA_PlayersHouse_1F_Text_ShouldISink, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RA_PlayersHouse_1F_Script_UsedTheSink
	goto_if_eq VAR_RESULT, NO, RA_PlayersHouse_1F_Script_DontPlayCredits
	end

RA_PlayersHouse_1F_Script_UsedTheSink::
	goto_if_set FLAG_BADGE08_GET, RA_PlayersHouse_1F_Script_UsedTheSink_Rank8
	goto_if_set FLAG_BADGE07_GET, RA_PlayersHouse_1F_Script_UsedTheSink_Rank7
	goto_if_set FLAG_BADGE06_GET, RA_PlayersHouse_1F_Script_UsedTheSink_Rank6
	goto_if_set FLAG_BADGE05_GET, RA_PlayersHouse_1F_Script_UsedTheSink_Rank5
	goto_if_set FLAG_BADGE04_GET, RA_PlayersHouse_1F_Script_UsedTheSink_Rank4
	goto_if_set FLAG_BADGE03_GET, RA_PlayersHouse_1F_Script_UsedTheSink_Rank3
	goto_if_set FLAG_BADGE02_GET, RA_PlayersHouse_1F_Script_UsedTheSink_Rank2
	goto_if_set FLAG_BADGE01_GET, RA_PlayersHouse_1F_Script_UsedTheSink_Rank1
	goto_if_set FLAG_BADGE00_GET, RA_PlayersHouse_1F_Script_UsedTheSink_Rank0
	goto_if_unset FLAG_BADGE00_GET, RA_PlayersHouse_1F_Script_Sink_Unavailable
	end

RA_PlayersHouse_1F_Script_UsedTheSink_Rank8::
	playse SE_FAINT
	clearflag FLAG_BADGE08_GET
	msgbox RA_PlayersHouse_1F_Text_Sink_Rank8, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_UsedTheSink_Rank7::
	playse SE_FAINT
	clearflag FLAG_BADGE07_GET
	msgbox RA_PlayersHouse_1F_Text_Sink_Rank7, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_UsedTheSink_Rank6::
	playse SE_FAINT
	clearflag FLAG_BADGE06_GET
	msgbox RA_PlayersHouse_1F_Text_Sink_Rank6, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_UsedTheSink_Rank5::
	playse SE_FAINT
	clearflag FLAG_BADGE05_GET
	msgbox RA_PlayersHouse_1F_Text_Sink_Rank5, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_UsedTheSink_Rank4::
	playse SE_FAINT
	clearflag FLAG_BADGE04_GET
	msgbox RA_PlayersHouse_1F_Text_Sink_Rank4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_UsedTheSink_Rank3::
	playse SE_FAINT
	clearflag FLAG_BADGE03_GET
	msgbox RA_PlayersHouse_1F_Text_Sink_Rank3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_UsedTheSink_Rank2::
	playse SE_FAINT
	clearflag FLAG_BADGE02_GET
	msgbox RA_PlayersHouse_1F_Text_Sink_Rank2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_UsedTheSink_Rank1::
	playse SE_FAINT
	clearflag FLAG_BADGE01_GET
	msgbox RA_PlayersHouse_1F_Text_Sink_Rank1, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_UsedTheSink_Rank0::
	playse SE_FAINT
	clearflag FLAG_BADGE00_GET
	msgbox RA_PlayersHouse_1F_Text_Sink_Rank0, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_Sink_Unavailable::
	call RA_Player_ThreeDots
	msgbox RA_PlayersHouse_1F_Text_Sink_Unavailable, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RA_PlayersHouse_1F_Script_WantToWatchCredits::
	lockall
	msgbox RA_PlayersHouse_1F_Text_WantToWatchCredits, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RA_PlayersHouse_1F_Script_PlayCredits
	goto_if_eq VAR_RESULT, NO, RA_PlayersHouse_1F_Script_DontPlayCredits
	end

RA_PlayersHouse_1F_Script_PlayCredits::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, RA_PlayersHouse_1F_Script_CreditsSaveIssue
	setflag FLAG_RA_WATCHING_CREDITS
	setrespawn HEAL_LOCATION_RA_PLAYERSHOUSE_1F
	fadescreenspeed FADE_TO_BLACK, 24
	FadeOutBGM 2
	delay 96
	special GameClear
	waitstate
	releaseall
	end

RA_PlayersHouse_1F_Script_LookAtBoxes::
	lock
	msgbox RA_PlayersHouse_1F_Text_LookAtBoxes, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_PlayersHouse_1F_Script_DontPlayCredits::
	releaseall
	end

RA_PlayersHouse_1F_Script_CreditsSaveIssue::
	playse SE_SELECT
	releaseall
	end

RA_PlayersHouse_1F_Text_FridgeLetter:
	.string "There's a {COLOR RED}letter {COLOR DARK_GRAY}under my {COLOR RED}Moomoo Milk{COLOR DARK_GRAY}!\n"
	.string "Let's see...$"

RA_PlayersHouse_1F_Text_WantToWatchCredits:
	.string "{COLOR BLUE}> Do you want to watch the credits?\p"
	.string "{COLOR BLUE}> You won't be able to skip them, so you'll\n"
	.string "{COLOR BLUE}have to save your progress first.{COLOR DARK_GRAY}$"

RA_PlayersHouse_1F_Text_FridgeIsEmpty:
	.string "The {COLOR RED}Fridge of Blessings{COLOR DARK_GRAY} has\n"
	.string "no more gifts to bestow...$"

RA_PlayersHouse_1F_Text_ShouldIFridge:
	.string "It's the {COLOR RED}Fridge of Blessings{COLOR DARK_GRAY}.\n"
	.string "Should I open it?$"

RA_PlayersHouse_1F_Text_ShouldISink:
	.string "It's the {COLOR RED}Sink of Despair{COLOR DARK_GRAY}.\n"
	.string "Should I turn on the tap?$"

RA_PlayersHouse_1F_Text_Sink_Rank8:
	.string "My {COLOR RED}Gold Ring {COLOR DARK_GRAY}fell down the plughole!\n"
	.string "Guess I'm just a {COLOR RED}Commander{COLOR DARK_GRAY} again...\p"
	.string "The {COLOR RED}Fridge {COLOR DARK_GRAY}giveth, and the {COLOR RED}Sink\n"
	.string "{COLOR DARK_GRAY}taketh away.$"

RA_PlayersHouse_1F_Text_Sink_Rank7:
	.string "My {COLOR RED}Violet Gem {COLOR DARK_GRAY}fell down the plughole!\n"
	.string "Guess I'm just a {COLOR RED}Captain{COLOR DARK_GRAY} again...\p"
	.string "The {COLOR RED}Fridge {COLOR DARK_GRAY}giveth, and the {COLOR RED}Sink\n"
	.string "{COLOR DARK_GRAY}taketh away.$"

RA_PlayersHouse_1F_Text_Sink_Rank6:
	.string "My {COLOR RED}Indigo Gem {COLOR DARK_GRAY}fell down the plughole!\n"
	.string "Guess I'm just a {COLOR RED}Lieutenant{COLOR DARK_GRAY} again...\p"
	.string "The {COLOR RED}Fridge {COLOR DARK_GRAY}giveth, and the {COLOR RED}Sink\n"
	.string "{COLOR DARK_GRAY}taketh away.$"

RA_PlayersHouse_1F_Text_Sink_Rank5:
	.string "My {COLOR RED}Blue Gem {COLOR DARK_GRAY}fell down the plughole!\n"
	.string "Guess I'm just a {COLOR RED}Detective{COLOR DARK_GRAY} again...\p"
	.string "The {COLOR RED}Fridge {COLOR DARK_GRAY}giveth, and the {COLOR RED}Sink\n"
	.string "{COLOR DARK_GRAY}taketh away.$"

RA_PlayersHouse_1F_Text_Sink_Rank4:
	.string "My {COLOR RED}Green Gem {COLOR DARK_GRAY}fell down the plughole!\n"
	.string "Guess I'm just a {COLOR RED}Sergeant{COLOR DARK_GRAY} again...\p"
	.string "The {COLOR RED}Fridge {COLOR DARK_GRAY}giveth, and the {COLOR RED}Sink\n"
	.string "{COLOR DARK_GRAY}taketh away.$"

RA_PlayersHouse_1F_Text_Sink_Rank3:
	.string "My {COLOR RED}Yellow Gem {COLOR DARK_GRAY}fell down the plughole!\n"
	.string "Guess I'm just a {COLOR RED}Officer{COLOR DARK_GRAY} again...\p"
	.string "The {COLOR RED}Fridge {COLOR DARK_GRAY}giveth, and the {COLOR RED}Sink\n"
	.string "{COLOR DARK_GRAY}taketh away.$"

RA_PlayersHouse_1F_Text_Sink_Rank2:
	.string "My {COLOR RED}Orange Gem {COLOR DARK_GRAY}fell down the plughole!\n"
	.string "Guess I'm just a {COLOR RED}Recruit{COLOR DARK_GRAY} again...\p"
	.string "The {COLOR RED}Fridge {COLOR DARK_GRAY}giveth, and the {COLOR RED}Sink\n"
	.string "{COLOR DARK_GRAY}taketh away.$"

RA_PlayersHouse_1F_Text_Sink_Rank1:
	.string "My {COLOR RED}Red Gem {COLOR DARK_GRAY}fell down the plughole!\n"
	.string "Guess I'm just a {COLOR RED}Trainee{COLOR DARK_GRAY} again...\p"
	.string "The {COLOR RED}Fridge {COLOR DARK_GRAY}giveth, and the {COLOR RED}Sink\n"
	.string "{COLOR DARK_GRAY}taketh away.$"

RA_PlayersHouse_1F_Text_Sink_Rank0:
	.string "My {COLOR RED}White Band {COLOR DARK_GRAY}fell down the plughole!\p"
	.string "Guess I'm not part of the\n"
	.string "{COLOR RED}Amnesty Institute{COLOR DARK_GRAY} any more...\p"
	.string "The {COLOR RED}Fridge {COLOR DARK_GRAY}giveth, and the {COLOR RED}Sink\n"
	.string "{COLOR DARK_GRAY}taketh away.$"

RA_PlayersHouse_1F_Text_Sink_Unavailable:
	.string "Nothing happened...$"

RA_PlayersHouse_1F_Text_LookAtBoxes:
	.string "I should really get around to unpacking\n"
	.string "the rest of my stuff...\p"
	.string "But not now!$"
