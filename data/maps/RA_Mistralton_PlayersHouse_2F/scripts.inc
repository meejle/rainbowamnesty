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
	setflag FLAG_SYS_B_DASH
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
	msgbox RA_PlayersHouse_2F_Text_LookerEmail3, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, RA_PlayersHouse_2F_Script_DontReadEmailAgain
	playse SE_PC_LOGIN
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	delay 32
	namebox name_looker
	playse SE_SELECT
	msgbox RA_PlayersHouse_2F_Text_LookerEmail2, MSGBOX_DEFAULT
	closemessage
	hidenamebox
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	release
	end

RA_PlayersHouse_2F_Script_DontReadEmailAgain::
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
	goto_if_set FLAG_SET_WALL_CLOCK, RA_PlayersHouse_2F_Script_TwoStepCheck1
	msgbox RA_PlayersHouse_2F_Text_LookAtBook, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_PlayersHouse_2F_Script_TwoStepCheck1::
	msgbox RA_PlayersHouse_2F_Text_LookAtBookRTC, MSGBOX_DEFAULT
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
	setflag FLAG_SYS_FIRST_SAVE_SINCE_RTC_SET
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
	.string "{COLOR BLUE}Two weeks later\n"
	.string "Mistralton City - {PLAYER}'s house$"

RA_PlayersHouse_2F_Text_GotEmail:
	.string "Sounds like I've got a new email...$"

RA_PlayersHouse_2F_Text_NotTimeForBed:
	.string "It's tempting, but now isn't the time to\n"
	.string "be going back to bed!$"

RA_PlayersHouse_2F_Text_ShouldReadEmailFirst:
	.string "I should check my email before I do\n"
	.string "anything else...$"

RA_PlayersHouse_2F_Text_LookerEmail:
	.string "It's an email from {COLOR GREEN}Agent Looker{COLOR DARK_GRAY}.$"

RA_PlayersHouse_2F_Text_LookerEmail2:
	.string "My young friend,\p"
	.string "The time, it has finally come!\p"
	.string "That is to say, it is time for you to\n"
	.string "start your training at the {COLOR RED}Institute{COLOR DARK_GRAY}!\p"
	.string "Do not worry! We plan to -- ah, how to\n"
	.string "put this -- “go easy on you”, at first.\p"
	.string "When you read this, head for the\n"
	.string "building of {COLOR RED}Mistralton Cargo Service{COLOR DARK_GRAY}.\p"
	.string "Make haste, you understand, but not\n"
	.string "speed! If you need to go anywhere else\l"
	.string "in town first, that is OK with me.\p"
	.string "Young {COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}, I look forward to the\n"
	.string "making of your acquaintance!\p"
	.string "Best wishes! :-)\n"
	.string "{COLOR GREEN}Looker{COLOR DARK_GRAY}$"

RA_PlayersHouse_2F_Text_LookerEmail3:
	.string "Should I read {COLOR GREEN}Looker's {COLOR DARK_GRAY}email again?$"

RA_PlayersHouse_2F_Text_LookAtGCN:
	.string "It's a {COLOR RED}Retroid Pocket 3+{COLOR DARK_GRAY}!\p"
	.string "A mini HDMI cable and a {COLOR RED}Nintendo Switch\n"
	.string "Pro Controller{COLOR DARK_GRAY} are connected, so I can\l"
	.string "play ROM hacks on the big screen!$"

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
	.string "for new recruits.\p"
	.string "Lesson number 1:\n"
	.string "Use  {START_BUTTON}  to open the Menu.\p"
	.string "Lesson number 2:\n"
	.string "Update your {COLOR RED}Mission Log{COLOR DARK_GRAY} with Save.\p"
	.string "Lesson number 3:\n"
	.string "Hold  {B_BUTTON}  to use your {COLOR RED}Running Shoes{COLOR DARK_GRAY}.\p"
	.string "The rest is too technical for me to\n"
	.string "understand...$"

RA_PlayersHouse_2F_Text_LookAtBookRTC:
	.string "It's the {COLOR RED}Amnesty Institute's {COLOR DARK_GRAY}manual\n"
	.string "for new recruits.\p"
	.string "Lesson number 1:\n"
	.string "Use  {START_BUTTON}  to open the Menu.\p"
	.string "Lesson number 2:\n"
	.string "Update your {COLOR RED}Mission Log{COLOR DARK_GRAY} with Save.\p"
	.string "Lesson number 3:\n"
	.string "Hold  {B_BUTTON}  to use your {COLOR RED}Running Shoes{COLOR DARK_GRAY}.\p"
	.string "Lesson number 4:\n"
	.string "Adjust your {COLOR RED}clock {COLOR DARK_GRAY}by pressing\l"
	.string "{DPAD_LEFT}{FONT 10} Left{FONT 11}  +  {SELECT_BUTTON}  +  {B_BUTTON}  together\lon the title screen.\p"
	.string "The rest is too technical for me to\n"
	.string "understand...$"

RA_PlayersHouse_2F_Text_LookAtClock:
	.string "The {COLOR RED}clock {COLOR DARK_GRAY}is stopped...\p"
	.string "Better set it and start it!$"

name_looker:
	.string "Looker$"
