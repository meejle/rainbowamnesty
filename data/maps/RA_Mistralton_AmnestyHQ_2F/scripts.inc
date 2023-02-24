.set LOCALID_LOOKER, 1

RA_Mistralton_AmnestyHQ_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RA_AmnestyHQ_2F_Script_OnFrame
	.byte 0

RA_AmnestyHQ_2F_Script_OnFrame:
	map_script_2 VAR_RA_PLAYERSHOUSE_INTRO_STATE, 3, RA_AmnestyHQ_2F_Script_PlayerEnters
	.2byte 0

RA_AmnestyHQ_2F_Script_PlayerEnters::
	lockall

	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_2F_Move_PlayerEnters
	waitmovement 0

	playse SE_WARP_IN
	setobjectxy LOCALID_LOOKER, 13, 9
	applymovement LOCALID_LOOKER, RA_AmnestyHQ_2F_Move_LookerEnters
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_2F_Move_PlayerFaces
	waitmovement 0

	setvar VAR_RA_PLAYERSHOUSE_INTRO_STATE, 4
	releaseall
	end

RA_AmnestyHQ_2F_Move_PlayerEnters:
	walk_down
	walk_down
	step_end

RA_AmnestyHQ_2F_Move_LookerEnters:
	walk_down
	walk_down
	step_end

RA_AmnestyHQ_2F_Move_PlayerFaces:
	face_up
	step_end
