.set LOCALID_LOOKER, 2

RA_Mistralton_AmnestyHQ_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RA_AmnestyHQ_1F_Script_OnFrame
	.byte 0

RA_AmnestyHQ_1F_Script_OnFrame:
	map_script_2 VAR_RA_PLAYERSHOUSE_INTRO_STATE, 2, RA_AmnestyHQ_1F_Script_MeetLooker
	.2byte 0

RA_AmnestyHQ_1F_Script_MeetLooker::
	end
