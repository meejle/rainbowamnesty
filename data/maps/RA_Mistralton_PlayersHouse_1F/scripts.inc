RA_Mistralton_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RA_PlayersHouse_1F_Script_OnTransition
	.byte 0

RA_PlayersHouse_1F_Script_OnTransition:
	clearflag FLAG_RA_WATCHING_CREDITS
	end

RA_PlayersHouse_1F_Script_FoundBadgeInFridge::
	goto_if_eq VAR_PETALBURG_GYM_STATE, 7, RA_PlayersHouse_1F_Script_FridgeIsEmpty
	lock
	message RA_PlayersHouse_1F_Text_FoundBadgeInFridge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RA_PlayersHouse_1F_Text_FoundBadgeInFridge2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_BADGE05_GET
	release
	end

RA_PlayersHouse_1F_Script_FridgeIsEmpty::
	lock
	msgbox RA_PlayersHouse_1F_Text_FridgeIsEmpty, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_PlayersHouse_1F_Script_WantToWatchCredits::
	lockall
	msgbox RA_PlayersHouse_1F_Text_WantToWatchCredits, MSGBOX_YESNO
	closemessage
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

RA_PlayersHouse_1F_Text_WantToWatchCredits:
	.string "Do you want to {COLOR BLUE}watch the credits{COLOR DARK_GRAY}?\p"
	.string "You {COLOR BLUE}won't be able to skip them{COLOR DARK_GRAY}, so we'll\n"
	.string "save your adventure first.$"

RA_PlayersHouse_1F_Text_FoundBadgeInFridge:
	.string "You found an {COLOR RED}Institute Badge {COLOR DARK_GRAY}in the\n"
	.string "fridge! Your rank increased to {COLOR BLUE}Recruit{COLOR DARK_GRAY}!$"

RA_PlayersHouse_1F_Text_FoundBadgeInFridge2:
	.string "That was a nice surprise.$"

RA_PlayersHouse_1F_Text_FridgeIsEmpty:
	.string "The fridge is now empty. That's not\n"
	.string "such a nice surprise...$"

RA_PlayersHouse_1F_Text_LookAtBoxes:
	.string "I should really get around to unpacking\n"
	.string "the rest of my stuff...\p"
	.string "But not now!$"
