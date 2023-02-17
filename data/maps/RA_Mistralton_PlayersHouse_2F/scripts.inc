RA_Mistralton_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RA_PlayersHouse_2F_Script_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RA_PlayersHouse_2F_Script_OnFrame
	.byte 0

RA_PlayersHouse_2F_Script_OnTransition:
	setflag FLAG_SYS_PREVENT_MAP_FADE
	end

RA_PlayersHouse_2F_Script_OnFrame:
	map_script_2 VAR_RA_PLAYERSHOUSE_INTRO_STATE, 0, RA_PlayersHouse_2F_Script_GetEmail
	.2byte 0

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
	addvar VAR_RA_PLAYERSHOUSE_INTRO_STATE, 1
	releaseall
	end

RA_PlayersHouse_2F_Script_ReadEmail::
	lock
	msgbox RA_PlayersHouse_2F_Text_LookerEmail, MSGBOX_DEFAULT
	closemessage
	namebox name_looker
	playse SE_SELECT
	msgbox RA_PlayersHouse_2F_Text_LookerEmail2, MSGBOX_DEFAULT
	closemessage
	hidenamebox
	release
	end

RA_PlayersHouse_2F_Text_2WeeksLater:
	.string "{COLOR GREEN}Two weeks later\n"
	.string "Mistralton City - {PLAYER}'s house$"

RA_PlayersHouse_2F_Text_GotEmail:
	.string "Sounds like I've got a new email...$"

RA_PlayersHouse_2F_Text_LookerEmail:
	.string "It's an email from {COLOR RED}Agent Looker{COLOR DARK_GRAY}.$"

RA_PlayersHouse_2F_Text_LookerEmail2:
	.string "It's an email from {COLOR RED}Agent Looker{COLOR DARK_GRAY}.$"

name_looker:
	.string "Looker$"
