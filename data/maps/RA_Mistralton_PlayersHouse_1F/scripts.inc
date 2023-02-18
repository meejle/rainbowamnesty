RA_Mistralton_PlayersHouse_1F_MapScripts::
	.byte 0

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
