RA_Mistralton_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RA_PlayersHouse_2F_Script_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RA_PlayersHouse_2F_Script_OnFrame
	.byte 0

RA_PlayersHouse_2F_Script_OnTransition:
	goto_if_gt VAR_RA_PLAYERSHOUSE_INTRO_STATE, 1, RA_PlayersHouse_2F_Script_Return
	setflag FLAG_SYS_PREVENT_MAP_FADE
	setflag FLAG_SYS_PREVENT_MAP_MUSIC
	end

RA_PlayersHouse_2F_Script_OnFrame:
	map_script_2 VAR_RA_PLAYERSHOUSE_INTRO_STATE, 0, RA_PlayersHouse_2F_Script_GetEmail
	.2byte 0

RA_PlayersHouse_2F_Script_Return::
	return

RA_PlayersHouse_2F_Script_GetEmail::
	lockall
	delay 96
	msgbox RA_PlayersHouse_2F_Text_2WeeksLater, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 48
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	playse SE_M_SNORE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ZeeZeeZee
	waitmovement 0
	delay 192
	playse MUS_LEVEL_UP
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoIntroPCTurnOnEffect
	delay 48
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 96
	msgbox RA_PlayersHouse_2F_Text_GotEmail, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_PALLET TRUE
	setvar VAR_RA_PLAYERSHOUSE_INTRO_STATE, 1
	releaseall
	end

RA_PlayersHouse_2F_Script_NotTimeForBed::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox RA_PlayersHouse_2F_Text_NotTimeForBed, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_PlayersHouse_2F_Script_ApproachFromWest::
	setvar VAR_RA_DIRECTION_OF_APPROACH, 4
	end

RA_PlayersHouse_2F_Script_ApproachFromEast::
	setvar VAR_RA_DIRECTION_OF_APPROACH, 2
	end

RA_PlayersHouse_2F_Script_ApproachFromSouth::
	setvar VAR_RA_DIRECTION_OF_APPROACH, 3
	end

RA_PlayersHouse_2F_Script_ShouldReadEmailFirst::
	lock
	msgbox RA_PlayersHouse_2F_Text_ShouldReadEmailFirst, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_RA_DIRECTION_OF_APPROACH, 2, RA_PlayersHouse_2F_Script_ReturnToEast
	goto_if_eq VAR_RA_DIRECTION_OF_APPROACH, 3, RA_PlayersHouse_2F_Script_ReturnToSouth
	goto_if_eq VAR_RA_DIRECTION_OF_APPROACH, 4, RA_PlayersHouse_2F_Script_ReturnToWest
	end

RA_PlayersHouse_2F_Script_ReturnToEast::
	setvar VAR_RA_DIRECTION_OF_APPROACH, 2
	applymovement OBJ_EVENT_ID_PLAYER, RA_PlayersHouse_2F_Move_ReturnToEast
	waitmovement 0
	release
	end

RA_PlayersHouse_2F_Script_ReturnToSouth::
	setvar VAR_RA_DIRECTION_OF_APPROACH, 3
	applymovement OBJ_EVENT_ID_PLAYER, RA_PlayersHouse_2F_Move_ReturnToSouth
	waitmovement 0
	release
	end

RA_PlayersHouse_2F_Script_ReturnToWest::
	setvar VAR_RA_DIRECTION_OF_APPROACH, 4
	applymovement OBJ_EVENT_ID_PLAYER, RA_PlayersHouse_2F_Move_ReturnToWest
	waitmovement 0
	release
	end

RA_PlayersHouse_2F_Script_ResetApproach::
	setvar VAR_RA_DIRECTION_OF_APPROACH, 0
	end

RA_PlayersHouse_2F_Script_ReadEmail::
	goto_if_eq VAR_RA_PLAYERSHOUSE_INTRO_STATE, 2, RA_PlayersHouse_2F_Script_ReadEmailAgain
	lock
	setvar VAR_RA_PLAYERSHOUSE_INTRO_STATE, 2
	setvar VAR_RA_DIRECTION_OF_APPROACH, 5
	msgbox RA_PlayersHouse_2F_Text_LookerEmail, MSGBOX_DEFAULT
	closemessage
	namebox name_looker
	playse SE_SELECT
	msgbox RA_PlayersHouse_2F_Text_LookerEmail2, MSGBOX_DEFAULT
	closemessage
	hidenamebox
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	release
	end

RA_PlayersHouse_2F_Script_ReadEmailAgain::
	lock
	playse SE_PC_LOGIN
	special DoPCTurnOnEffect
	delay 32
	msgbox RA_PlayersHouse_2F_Text_LookerEmail, MSGBOX_DEFAULT
	closemessage
	namebox name_looker
	playse SE_SELECT
	msgbox RA_PlayersHouse_2F_Text_LookerEmail2, MSGBOX_DEFAULT
	closemessage
	hidenamebox
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	release
	end

RA_PlayersHouse_2F_Script_LookAtBoxes::
	lock
	msgbox RA_PlayersHouse_2F_Text_LookAtBoxes, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_PlayersHouse_2F_Script_LookAtTV::
	lock
	msgbox RA_PlayersHouse_2F_Text_LookAtTV, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_PlayersHouse_2F_Script_LookAtGCN::
	lock
	msgbox RA_PlayersHouse_2F_Text_LookAtGCN, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_PlayersHouse_2F_Script_LookAtBook::
	lock
	msgbox RA_PlayersHouse_2F_Text_LookAtBook, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_PlayersHouse_2F_Script_LookAtClock::
	lockall
	goto_if_set FLAG_SET_WALL_CLOCK, RA_PlayersHouse_2F_Script_ShowTheRTC
	msgbox RA_PlayersHouse_2F_Text_LookAtClock, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	setflag FLAG_SET_WALL_CLOCK
	releaseall
	end

RA_PlayersHouse_2F_Script_ShowTheRTC::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

RA_PlayersHouse_2F_Script_SetClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return

RA_PlayersHouse_2F_Move_ReturnToEast:
	walk_right
	step_end

RA_PlayersHouse_2F_Move_ReturnToSouth:
	walk_down
	step_end

RA_PlayersHouse_2F_Move_ReturnToWest:
	walk_left
	step_end

RA_PlayersHouse_2F_Text_2WeeksLater:
	.string "{COLOR GREEN}Two weeks later\n"
	.string "Mistralton City - {PLAYER}'s house$"

RA_PlayersHouse_2F_Text_GotEmail:
	.string "Sounds like I've got a {COLOR BLUE}new email{COLOR DARK_GRAY}...$"

RA_PlayersHouse_2F_Text_NotTimeForBed:
	.string "It's tempting, but now isn't the time to\n"
	.string "be going back to bed!$"

RA_PlayersHouse_2F_Text_ShouldReadEmailFirst:
	.string "I should {COLOR BLUE}check my email{COLOR DARK_GRAY} before I do\n"
	.string "anything else...$"

RA_PlayersHouse_2F_Text_LookerEmail:
	.string "It's an email from {COLOR RED}Agent Looker{COLOR DARK_GRAY}.$"

RA_PlayersHouse_2F_Text_LookerEmail2:
	.string "Lorem ipsum dolor sit amet, consectetur\n"
	.string "adipiscing elit.\p"
	.string "Mauris accumsan eu eros eu sodales!\p"
	.string "Mauris sed metus tempus, iaculis nunc\n"
	.string "vel, gravida dui. Cras vel tempor felis.$"

RA_PlayersHouse_2F_Text_LookAtGCN:
	.string "It's a {COLOR RED}Retroid Pocket 3+{COLOR DARK_GRAY}!\p"
	.string "A {COLOR RED}Mini HDMI cable{COLOR DARK_GRAY} and a {COLOR RED}Nintendo Switch\n"
	.string "Pro Controller{COLOR DARK_GRAY} are connected, so I can\l"
	.string "play {COLOR RED}ROM hacks{COLOR DARK_GRAY} on the big screen!$"

RA_PlayersHouse_2F_Text_LookAtTV:
	.string "The {COLOR RED}Amnesty Institute's {COLOR DARK_GRAY}accommodation\n"
	.string "came with a TV, but it doesn't pick up\l"
	.string "any channels...\p"
	.string "Thank goodness for gaming!$"

RA_PlayersHouse_2F_Text_LookAtBoxes:
	.string "I should really get around to unpacking\n"
	.string "the rest of my stuff...\p"
	.string "But not now!$"

RA_PlayersHouse_2F_Text_LookAtBook:
	.string "It's the {COLOR RED}Amnesty Institute's {COLOR DARK_GRAY}manual\n"
	.string "for new recruits...\p"
	.string "Lesson number 1:\n"
	.string "{COLOR BLUE}Open the menu {COLOR DARK_GRAY}with {COLOR RED}Start{COLOR DARK_GRAY}.\p"
	.string "Lesson number 2:\n"
	.string "{COLOR BLUE}Record your progress{COLOR DARK_GRAY} with {COLOR RED}Save{COLOR DARK_GRAY}.\p"
	.string "The rest is too technical for me to\n"
	.string "understand.$"

RA_PlayersHouse_2F_Text_LookAtClock:
	.string "Hmm...\p"
	.string "It's probably about time I {COLOR BLUE}set the\n"
	.string "clock {COLOR DARK_GRAY}in my room...$"

name_looker:
	.string "Looker$"
