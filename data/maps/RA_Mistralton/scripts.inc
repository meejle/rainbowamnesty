RA_Mistralton_MapScripts::
	.byte 0

RA_Mistralton_Script_ShutterDown::
	lock
	msgbox RA_Mistralton_Text_ShutterDown, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RA_Mistralton_Move_ReturnSouth
	release
	end

RA_Mistralton_Script_GymDoorSign::
	lock
	msgbox RA_Mistralton_Text_GymDoorSign, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_Script_PlayerDoorSign::
	lock
	msgbox RA_Mistralton_Text_PlayerDoorSign, MSGBOX_DEFAULT
	closemessage
	release
	goto_if_set FLAG_SYS_SAVEREMIND_ON, RA_Mistralton_Script_SaveRemind
	end

RA_Mistralton_Script_SaveRemind::
	lockall
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, RA_Mistralton_Script_SaveFail
	releaseall
	end

RA_Mistralton_Script_SaveFail::
	playse SE_SELECT
	releaseall
	end

RA_Mistralton_Script_PkmnCentreSign::
	lock
	msgbox RA_Mistralton_Text_PkmnCentreSign, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_Script_CheckpointSign::
	lock
	msgbox RA_Mistralton_Text_CheckpointSign, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_Script_DotDotDot::
	faceplayer
	msgbox RA_Mistralton_Text_DotDotDot, MSGBOX_NPC
	closemessage
	end

RA_Mistralton_Script_CitySign::
	lock
	msgbox RA_Mistralton_Text_CitySign, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_Script_CargoSign::
	lock
	msgbox RA_Mistralton_Text_CargoSign, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_Script_GymSign::
	lock
	msgbox RA_Mistralton_Text_GymSign, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_Script_LockedDoor::
	lock
	msgbox RA_Mistralton_Text_LockedDoor, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_Move_ReturnSouth:
	walk_down
	step_end

RA_Mistralton_Text_ShutterDown:
	.string "It's hard to tell, but the shutters are\n"
	.string "down.\p"
	.string "Guess I'll come back later.$"

RA_Mistralton_Text_GymDoorSign:
	.string "There's a sign on the door.\p"
	.string "GYM CLOSED - PRIVATE TRAINING ONLY\n"
	.string "BY ORDER OF {COLOR RED}TEAM RAINBOW ROCKET{COLOR DARK_GRAY}$"

RA_Mistralton_Text_PlayerDoorSign:
	.string "{PLAYER}'s House$"

RA_Mistralton_Text_PkmnCentreSign:
	.string "The door is locked.\p"
	.string "Looks like I need something called a\n"
	.string "{COLOR RED}Poké Pass {COLOR DARK_GRAY}to get in.$"

RA_Mistralton_Text_CheckpointSign:
	.string "CHECKPOINT CLOSED UNTIL FURTHER\n"
	.string "NOTICE\p"
	.string "BY ORDER OF {COLOR RED}TEAM RAINBOW ROCKET{COLOR DARK_GRAY}$"

RA_Mistralton_Text_CitySign:
	.string "{COLOR RED}Mistralton City{COLOR DARK_GRAY}\n"
	.string "Strewn with Windblown Leaves$"

RA_Mistralton_Text_CargoSign:
	.string "{COLOR RED}Mistralton Cargo Service{COLOR DARK_GRAY}\n"
	.string "Our slogan is “Quick and Safe!”$"

RA_Mistralton_Text_GymSign:
	.string "{COLOR RED}Mistralton City Pokémon Gym{COLOR DARK_GRAY}\n"
	.string "Leader: {COLOR GREEN}Skyla{COLOR DARK_GRAY}\l"
	.string "“The High-Flying Girl”$"

RA_Mistralton_Text_LockedDoor:
	.string "The door is locked.$"

RA_Mistralton_Text_DotDotDot:
	.string "...$"
