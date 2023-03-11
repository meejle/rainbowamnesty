.set LOCALID_RIVAL, 12

RA_Mistralton_MapScripts::
	.byte 0

RA_Mistralton_Script_Debug_ChooseStarter::
	lock
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	setflag FLAG_SYS_POKEMON_GET
	end

RA_Mistralton_Script_NameTheRival::
	lock
	faceplayer

	playse SE_FAILURE
	applymovement 12, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 12, Common_Movement_Delay48
	waitmovement 0
	applymovement 12, Common_Movement_Delay48
	waitmovement 0

	namebox name_unknown
	msgbox RA_Mistralton_Text_NameTheRival1, MSGBOX_DEFAULT
	hidenamebox
	msgbox RA_Mistralton_Text_NameTheRival2, MSGBOX_DEFAULT
	namebox name_unknown
	msgbox RA_Mistralton_Text_NameTheRival3, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special NameRival
	waitstate
	namebox name_rival
	msgbox RA_Mistralton_Text_NameTheRival4, MSGBOX_DEFAULT
	hidenamebox
	closemessage
	setvar VAR_MUGSHOT_ID, MUGSHOT_RIVAL
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
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
	msgbox RA_Mistralton_Text_PlayerDoorSign_2, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, RA_Mistralton_Move_Debug_Camera_1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, RA_Mistralton_Move_Debug_Camera_2
	waitmovement 0
	special RemoveCameraObject
	call RA_Player_Heart
	msgbox RA_Mistralton_Text_PlayerDoorSign_3, MSGBOX_DEFAULT
	closemessage
	release
	goto_if_set FLAG_SYS_SAVEREMIND_ON, RA_Mistralton_Script_SaveRemind
	end

RA_Mistralton_Move_Debug_Camera_1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

RA_Mistralton_Move_Debug_Camera_2:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

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
	namebox name_confused_lady
	msgbox RA_Lipsum, MSGBOX_DEFAULT
	closemessage
	hidenamebox
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

RA_Mistralton_Script_DontForgetToSave::
	lock
	faceplayer
	namebox name_confused_lady
	msgbox RA_Mistralton_Text_DontForgetToSave, MSGBOX_DEFAULT
	closemessage
	hidenamebox
	release
	end

RA_Mistralton_Script_TechIsAmazing::
	lock
	faceplayer
	namebox name_tech_enthusiast
	message RA_Mistralton_Text_TechIsAmazing
	waitmessage
	playse SE_WIN_OPEN
	multichoice2 20, 8, RA_Mistralton_Options_TechIsAmazing
	goto_if_eq VAR_RESULT, 0, RA_Mistralton_Script_AgreeTech
	msgbox RA_Mistralton_Text_DisagreeTech, MSGBOX_DEFAULT
	closemessage
	hidenamebox
	release
	end

RA_Mistralton_Script_AgreeTech::
	msgbox RA_Mistralton_Text_AgreeTech, MSGBOX_DEFAULT
	closemessage
	hidenamebox
	release
	end

RA_Mistralton_Options_TechIsAmazing:
	.string "{FONT 13}Tell me more!$"
	.string "{FONT 13}I'm a bit busy...$"
	.string "$"

RA_Mistralton_Move_ReturnSouth:
	walk_down
	step_end

RA_Mistralton_Text_NameTheRival1:
	.string "Hmph.$"

RA_Mistralton_Text_NameTheRival2:
	.string "> An unfriendly-looking girl is looking\n"
	.string "you up and down.$"

RA_Mistralton_Text_NameTheRival3:
	.string "So, what? You think you're special\n"
	.string "because the granny and gramps have\l"
	.string "taken an interest in you, is that it?\p"
	.string "I give it a week before they drop you...\p"
	.string "And, guess what? I don't need a dumb\n"
	.string "“{COLOR RED}Institute{COLOR DARK_GRAY}” to take down the\l"
	.string "{COLOR RED}Rainbow Rockets{COLOR DARK_GRAY}.\p"
	.string "I'm doing to do it on my own.\p"
	.string "Sorry to rain on your parade and all.\p"
	.string "My name's...$"

RA_Mistralton_Text_NameTheRival4:
	.string "My name's {COLOR GREEN}{RIVAL}{COLOR DARK_GRAY}, and you'd better\n"
	.string "not forget it.\p"
	.string "Here, maybe this will help you\n"
	.string "remember.$"

RA_Mistralton_Text_TechIsAmazing:
	.string "I overheard some scientist dudes\n"
	.string "talking about something interesting...{PAUSE 15}$"

RA_Mistralton_Text_AgreeTech:
	.string "Apparently the {COLOR RED}Cargo Service {COLOR DARK_GRAY}has a new\n"
	.string "device called a “{COLOR RED}ReEngine{COLOR DARK_GRAY}”.\p"
	.string "It allows near-instantaneous travel\n"
	.string "between regions, and it doesn't even\l"
	.string "show up on radar!\p"
	.string "Technology is incredible!\p"
	.string "Sadly, they won't let me see it...$"

RA_Mistralton_Text_DisagreeTech:
	.string "Haha, suit yourself!$"

RA_Mistralton_Text_DontForgetToSave:
	.string "Don't forget to save your progress\n"
	.string "regularly.\p"
	.string "I forgot to save once, and now I can't\n"
	.string "remember where I live.\p"
	.string "I just stand around outside all day.\p"
	.string "...\p"
	.string "...Oh, to save, just press {FONT 14}RS{FONT 11}.\p"
	.string "...$"

RA_Mistralton_Text_GymDoorSign:
	.string "> There's a sign on the door.\p"
	.string "GYM CLOSED - PRIVATE TRAINING ONLY\n"
	.string "BY ORDER OF {COLOR RED}TEAM RAINBOW ROCKET{COLOR DARK_GRAY}$"

RA_Mistralton_Text_PlayerDoorSign:
	.string "{COLOR GREEN}{PLAYER}'s{COLOR DARK_GRAY} house$"
	.string "> ...\p"
	.string "> You decided to experiment with the\n"
	.string "in-game camera.$"

RA_Mistralton_Text_PlayerDoorSign_2:
	.string "> ...\p"
	.string "> You decided to experiment with the\n"
	.string "in-game camera.$"

RA_Mistralton_Text_PlayerDoorSign_3:
	.string "> Nice.$"

RA_Mistralton_Text_PkmnCentreSign:
	.string "> The door won't open.\p"
	.string "> It looks like you need something\n"
	.string "called a {COLOR RED}Poké Pass {COLOR DARK_GRAY}to get in.$"

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
	.string "> The door is locked.$"

name_confused_lady:
	.string "Confused-looking woman$"

name_tech_enthusiast:
	.string "Tech enthusiast$"
