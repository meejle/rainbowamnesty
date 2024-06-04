.set LOCALID_BARRIER, 1
.set LOCALID_LOOKER, 2

RA_Mistralton_AmnestyHQ_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RA_AmnestyHQ_1F_Script_OnFrame
	.byte 0

RA_AmnestyHQ_1F_Script_OnFrame:
	map_script_2 VAR_RA_PLAYERSHOUSE_INTRO_STATE, 2, RA_AmnestyHQ_1F_Script_WalkToLooker
	.2byte 0

RA_AmnestyHQ_1F_Script_WalkToLooker::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_1F_Move_WalkToLooker
	waitmovement 0

	playse SE_M_DETECT
	applymovement LOCALID_LOOKER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0

	smallnamebox name_looker
	msgbox RA_AmnestyHQ_1F_Text_LookerGreets, MSGBOX_DEFAULT
	closemessage
	hidesmallnamebox

	applymovement LOCALID_LOOKER, RA_AmnestyHQ_1F_Move_LookerFakeOut
	waitmovement 0

	playse SE_PIN
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0

	smallnamebox name_looker
	msgbox RA_AmnestyHQ_1F_Text_LookerFakeout, MSGBOX_DEFAULT
	closemessage
	hidesmallnamebox

	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_1F_Move_PlayerWaits
	waitmovement 0

	applymovement LOCALID_LOOKER, RA_AmnestyHQ_1F_Move_LookerOpens
	waitmovement 0

	playse SE_SWITCH
	hideobjectat LOCALID_BARRIER, MAP_RA_MISTRALTON_AMNESTY_HQ_1F
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0

	applymovement LOCALID_LOOKER, RA_AmnestyHQ_1F_Move_LookerWaits
	waitmovement 0

	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_1F_Move_PlayerHalfEnters
	waitmovement 0

	applymovement LOCALID_LOOKER, RA_AmnestyHQ_1F_Move_LookerCloses
	waitmovement 0

	playse SE_SWITCH
	showobjectat LOCALID_BARRIER, MAP_RA_MISTRALTON_AMNESTY_HQ_1F
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0

	applymovement LOCALID_LOOKER, RA_AmnestyHQ_1F_Move_LookerFaces
	waitmovement 0

	smallnamebox name_looker
	msgbox RA_AmnestyHQ_1F_Text_AllonsY, MSGBOX_DEFAULT
	closemessage
	hidesmallnamebox

	setvar VAR_RA_PLAYERSHOUSE_INTRO_STATE, 3
	releaseall
	end

RA_AmnestyHQ_1F_Script_LookerInteract::
	lock
	faceplayer
	smallnamebox name_looker
	msgbox RA_AmnestyHQ_1F_Text_AllonsY, MSGBOX_DEFAULT
	closemessage
	hidesmallnamebox
	release
	end

RA_AmnestyHQ_1F_Move_WalkToLooker:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

RA_AmnestyHQ_1F_Move_LookerFakeOut:
	walk_right
	walk_up
	delay_16
	delay_16
	face_down
	step_end

RA_AmnestyHQ_1F_Move_PlayerWaits:
	walk_right
	face_up
	step_end

RA_AmnestyHQ_1F_Move_LookerOpens:
	walk_down
	step_end

RA_AmnestyHQ_1F_Move_LookerWaits:
	walk_left
	face_right
	step_end

RA_AmnestyHQ_1F_Move_PlayerHalfEnters:
	walk_up
	walk_up
	walk_right
	face_left
	step_end

RA_AmnestyHQ_1F_Move_LookerCloses:
	walk_right
	face_down
	step_end

RA_AmnestyHQ_1F_Move_LookerFaces:
	face_right
	step_end

RA_AmnestyHQ_1F_Text_LookerGreets:
	.string "Well, if it isn't my young friend\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}{PLAYER}{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}!\p"
	.string "Much, we have to discuss.\nBut not here!\p"
	.string "Follow me upstairs, so we can talk away\n"
	.string "from prying... erm, ears.$"

RA_AmnestyHQ_1F_Text_LookerFakeout:
	.string "Ah, you don't have a {COLOR RED}{SHADOW LIGHT_RED}Poké Pass{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY} yet,\n"
	.string "do you?\p"
	.string "Here, I'll open the barrier for you.$"

RA_AmnestyHQ_1F_Text_AllonsY:
	.string "Well then... after you, {COLOR GREEN}{SHADOW LIGHT_GREEN}{PLAYER}{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}!\n"
	.string "Andiamo!$"
