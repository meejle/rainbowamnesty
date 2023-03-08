.set LOCALID_RIVAL, 12

RA_Mistralton_MapScripts::
	.byte 0

RA_Mistralton_Script_Debug_ChooseStarter::
	lock
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
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
	msgbox RA_Lipsum, MSGBOX_NPC
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

RA_Mistralton_Text_NameTheRival1:
	.string "Hmph.$"

RA_Mistralton_Text_NameTheRival2:
	.string "> An unfriendly-looking girl is looking\n"
	.string "you up and down.$"

RA_Mistralton_Text_NameTheRival3:
	.string "So, what? You think you're special\n"
	.string "because the granny and gramps have\l"
	.string "taken an interest in you, is that it?\p"
	.string "As if you even need a dumb “{COLOR RED}Institute{COLOR DARK_GRAY}”\n"
	.string "to take down the {COLOR RED}Rainbow Rockets{COLOR DARK_GRAY}...\p"
	.string "Well guess what? I'm going to do it on\n"
	.string "my own.\p"
	.string "Sorry to rain on your parade and all.\p"
	.string "My name's...$"

RA_Mistralton_Text_NameTheRival4:
	.string "My name's {COLOR GREEN}{RIVAL}{COLOR DARK_GRAY}, and you'd better\n"
	.string "not forget it.\p"
	.string "Here, maybe this will help you\n"
	.string "remember...$"

RA_Mistralton_Text_GymDoorSign:
	.string "> There's a sign on the door.\p"
	.string "GYM CLOSED - PRIVATE TRAINING ONLY\n"
	.string "BY ORDER OF {COLOR RED}TEAM RAINBOW ROCKET{COLOR DARK_GRAY}$"

RA_Mistralton_Text_PlayerDoorSign:
	.string "{COLOR GREEN}{PLAYER}'s{COLOR DARK_GRAY} house$"

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
