.set LOCALID_LOOKER, 1

RA_Mistralton_AmnestyHQ_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RA_AmnestyHQ_2F_Script_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RA_AmnestyHQ_2F_Script_OnFrame
	.byte 0

RA_AmnestyHQ_2F_Script_OnTransition:
	goto_if_eq VAR_RA_PLAYERSHOUSE_INTRO_STATE, 3, RA_AmnestyHQ_2F_Script_HideLooker
	end

RA_AmnestyHQ_2F_Script_OnFrame:
	map_script_2 VAR_RA_PLAYERSHOUSE_INTRO_STATE, 4, RA_AmnestyHQ_2F_Script_PlayerEnters
	.2byte 0

RA_AmnestyHQ_2F_Script_HideLooker::
	hideobjectat LOCALID_LOOKER, MAP_RA_MISTRALTON_AMNESTY_HQ_2F
	setflag FLAG_TEMP_5
	setvar VAR_RA_PLAYERSHOUSE_INTRO_STATE, 4
	end

RA_AmnestyHQ_2F_Script_PlayerEnters::
	lockall

	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_2F_Move_PlayerEnters
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0

	playse SE_WARP_IN
	clearflag FLAG_TEMP_5
	showobjectat LOCALID_LOOKER, MAP_RA_MISTRALTON_AMNESTY_HQ_2F
	applymovement LOCALID_LOOKER, RA_AmnestyHQ_2F_Move_PlayerEnters
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_2F_Move_PlayerFaces
	waitmovement 0

	setvar VAR_RA_PLAYERSHOUSE_INTRO_STATE, 5
	releaseall
	end

RA_AmnestyHQ_2F_Move_PlayerEnters:
	walk_down
	walk_down
	step_end

RA_AmnestyHQ_2F_Move_PlayerFaces:
	face_up
	step_end
