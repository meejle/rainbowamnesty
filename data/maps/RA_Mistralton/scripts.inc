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

	smallnamebox name_unknown
	msgbox RA_Mistralton_Text_NameTheRival1, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special NameRival
	waitstate
	smallnamebox name_rival
	msgbox RA_Mistralton_Text_NameTheRival4, MSGBOX_DEFAULT
	hidesmallnamebox
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
	smallnamebox name_unknown
	msgbox RA_Lipsum, MSGBOX_DEFAULT
	closemessage
	hidesmallnamebox
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

RA_Mistralton_Script_Poryphone_Debug_Lady::
	playse MUS_LEVEL_UP
	lock
	faceplayer
	msgbox RA_Mistralton_Text_Add_Debug_Lady, MSGBOX_POKENAV
	closemessage
	playse SE_POKENAV_OFF
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	playse SE_POKENAV_CALL
	msgbox RA_Mistralton_Text_Answer_Debug_Lady, MSGBOX_POKENAV
	playse SE_POKENAV_ON
	msgbox RA_Mistralton_Text_Answer_Debug_Lady_Ramble, MSGBOX_POKENAV
	closemessage
	playse SE_POKENAV_HANG_UP
	release
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	end

RA_Mistralton_Text_Add_Debug_Lady:
	.string "Saved the {COLOR GREEN}{SHADOW LIGHT_GREEN}Debug Lady{CIRCLE_5}\n"
	.string "{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}number to the {COLOR RED}{SHADOW LIGHT_RED}Poryphone{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}.$"

RA_Mistralton_Text_Answer_Debug_Lady:
	.string "Incoming {COLOR RED}{SHADOW LIGHT_RED}Poryphone {SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}call\n"
	.string "from the {COLOR GREEN}{SHADOW LIGHT_GREEN}Debug Lady{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}…$"

RA_Mistralton_Text_Answer_Debug_Lady_Ramble:
	.string "Hello? {COLOR GREEN}{SHADOW LIGHT_GREEN}{PLAYER}{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}?\p"
	.string "It{CIRCLE_5} so good to speak to\n"
	.string "you again!\p"
	.string "I battled a really big\n"
	.string "Metapod on {COLOR RED}{SHADOW LIGHT_RED}Route U12{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}!\p"
	.string "But, it got away before\n"
	.string "I could catch it…\p"
	.string "Oh, well!\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}{PLAYER}{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}, I{CIRCLE_2}l call you\n"
	.string "again next time I find\l"
	.string "an interesting Pokémon!\p"
	.string "OK, bye!$"

RA_Mistralton_Script_TechIsAmazing::
	lock
	faceplayer
	smallnamebox name_tech_enthusiast
	message RA_Mistralton_Text_TechIsAmazing
	waitmessage
	multichoice2 20, 8, RA_Mistralton_Options_TechIsAmazing
	goto_if_eq VAR_RESULT, 0, RA_Mistralton_Script_AgreeTech
	msgbox RA_Mistralton_Text_DisagreeTech, MSGBOX_DEFAULT
	closemessage
	hidesmallnamebox
	release
	end

RA_Mistralton_Script_AgreeTech::
	call RA_Player_Chatter
	msgbox RA_Mistralton_Text_AgreeTech, MSGBOX_DEFAULT
	closemessage
	hidesmallnamebox
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
	.string "Hmph...\p"
	.string "So, what? You think you're special\n"
	.string "because the granny and gramps have\l"
	.string "taken an interest in you, is that it?\p"
	.string "I give it a week before they drop you...\p"
	.string "And, guess what? I don't need a dumb\n"
	.string "“{COLOR RED}{SHADOW LIGHT_RED}Institute{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}” to take down\l"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Team Rainbow Rocket{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}.\p"
	.string "I'm going to do it on my own.\p"
	.string "Sorry to rain on your parade and all.\p"
	.string "My name's...$"

RA_Mistralton_Text_NameTheRival4:
	.string "My name's {COLOR GREEN}{SHADOW LIGHT_GREEN}{RIVAL}{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}, and you'd better\n"
	.string "not forget it.\p"
	.string "Here, maybe this will help you\n"
	.string "remember.$"

RA_Mistralton_Text_TechIsAmazing:
	.string "I overheard some scientist dudes\n"
	.string "talking about something interesting...{PAUSE_UNTIL_PRESS}$"

RA_Mistralton_Text_AgreeTech:
	.string "Apparently the {COLOR RED}{SHADOW LIGHT_RED}Cargo Service {SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}has a new\n"
	.string "device called a “{COLOR RED}{SHADOW LIGHT_RED}ReEngine{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}”.\p"
	.string "It allows near-instantaneous travel\n"
	.string "between regions, and it doesn't even\l"
	.string "show up on radar!\p"
	.string "Technology is incredible!\p"
	.string "Sadly, no matter how enthusiastic I am,\n"
	.string "they still won't let me see it...$"

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
	.string "There's a sign on the door.\p"
	.string "GYM CLOSED - PRIVATE TRAINING ONLY\n"
	.string "BY ORDER OF {COLOR RED}{SHADOW LIGHT_RED}TEAM RAINBOW ROCKET{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}$"

RA_Mistralton_Text_PlayerDoorSign:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}{PLAYER}'s{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY} house$"
	.string "...\p"
	.string "You decided to experiment with the\n"
	.string "in-game camera.$"

RA_Mistralton_Text_PlayerDoorSign_2:
	.string "...\p"
	.string "You decided to experiment with the\n"
	.string "in-game camera.$"

RA_Mistralton_Text_PlayerDoorSign_3:
	.string "Nice.$"

RA_Mistralton_Text_PkmnCentreSign:
	.string "The door won't open.\p"
	.string "It looks like you need something called\n"
	.string "a {COLOR RED}{SHADOW LIGHT_RED}Poké Pass {SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}to get in.$"

RA_Mistralton_Text_CheckpointSign:
	.string "CHECKPOINT CLOSED UNTIL FURTHER\n"
	.string "NOTICE\p"
	.string "BY ORDER OF {COLOR RED}{SHADOW LIGHT_RED}TEAM RAINBOW ROCKET{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}$"

RA_Mistralton_Text_CitySign:
	.string "{COLOR RED}{SHADOW LIGHT_RED}Mistralton City{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}\n"
	.string "Strewn with Windblown Leaves$"

RA_Mistralton_Text_CargoSign:
	.string "{COLOR RED}{SHADOW LIGHT_RED}Mistralton Cargo Service{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}\n"
	.string "Our slogan is “Quick and Safe!”$"

RA_Mistralton_Text_GymSign:
	.string "{COLOR RED}{SHADOW LIGHT_RED}Mistralton City Pokémon Gym{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}\n"
	.string "Leader: {COLOR GREEN}{SHADOW LIGHT_GREEN}Skyla{SHADOW LIGHT_GRAY}{COLOR DARK_GRAY}\l"
	.string "“The High-Flying Girl”$"

RA_Mistralton_Text_LockedDoor:
	.string "The door is locked.$"

name_confused_lady:
	.string "Confused-looking woman$"

name_tech_enthusiast:
	.string "Science fan$"




RA_Mistralton_Text_Transition_Defeat:
	.string "Wasn't that a cool transition?$"

RA_Mistralton_Text_Transition_01:
	.string "Transition test No. 1 of 37:\n"
	.string "“Blur”$"

RA_Mistralton_Script_Transition_01::
	lock
	msgbox RA_Mistralton_Text_Transition_01, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_01::
	trainerbattle_no_intro TRAINER_ANDRES_4, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_02:
	.string "Transition test No. 2 of 37:\n"
	.string "“Swirl”$"

RA_Mistralton_Script_Transition_02::
	lock
	msgbox RA_Mistralton_Text_Transition_02, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_02::
	trainerbattle_no_intro TRAINER_ANDRES_5, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_03:
	.string "Transition test No. 3 of 37:\n"
	.string "“Shuffle”$"

RA_Mistralton_Script_Transition_03::
	lock
	msgbox RA_Mistralton_Text_Transition_03, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_03::
	trainerbattle_no_intro TRAINER_CORY_2, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_04:
	.string "Transition test No. 4 of 37:\n"
	.string "“Big Poké Ball”$"

RA_Mistralton_Script_Transition_04::
	lock
	msgbox RA_Mistralton_Text_Transition_04, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_04::
	trainerbattle_no_intro TRAINER_CORY_3, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_05:
	.string "Transition test No. 5 of 37:\n"
	.string "“Poké Balls Trail”$"

RA_Mistralton_Script_Transition_05::
	lock
	msgbox RA_Mistralton_Text_Transition_05, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_05::
	trainerbattle_no_intro TRAINER_CORY_4, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_06:
	.string "Transition test No. 6 of 37:\n"
	.string "“Clockwise Wipe”$"

RA_Mistralton_Script_Transition_06::
	lock
	msgbox RA_Mistralton_Text_Transition_06, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_06::
	trainerbattle_no_intro TRAINER_CORY_5, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_07:
	.string "Transition test No. 7 of 37:\n"
	.string "“Ripple”$"

RA_Mistralton_Script_Transition_07::
	lock
	msgbox RA_Mistralton_Text_Transition_07, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_07::
	trainerbattle_no_intro TRAINER_PABLO_2, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_08:
	.string "Transition test No. 8 of 37:\n"
	.string "“Wave”$"

RA_Mistralton_Script_Transition_08::
	lock
	msgbox RA_Mistralton_Text_Transition_08, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_08::
	trainerbattle_no_intro TRAINER_PABLO_3, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_09:
	.string "Transition test No. 9 of 37:\n"
	.string "“Slice”$"

RA_Mistralton_Script_Transition_09::
	lock
	msgbox RA_Mistralton_Text_Transition_09, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_09::
	trainerbattle_no_intro TRAINER_PABLO_4, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_10:
	.string "Transition test No. 10 of 37:\n"
	.string "“White Bars Fade”$"

RA_Mistralton_Script_Transition_10::
	lock
	msgbox RA_Mistralton_Text_Transition_10, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_10::
	trainerbattle_no_intro TRAINER_PABLO_5, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_11:
	.string "Transition test No. 11 of 37:\n"
	.string "“Grid Squares”$"

RA_Mistralton_Script_Transition_11::
	lock
	msgbox RA_Mistralton_Text_Transition_11, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_11::
	trainerbattle_no_intro TRAINER_KOJI_2, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_12:
	.string "Transition test No. 12 of 37:\n"
	.string "“Angled Wipes”$"

RA_Mistralton_Script_Transition_12::
	lock
	msgbox RA_Mistralton_Text_Transition_12, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_12::
	trainerbattle_no_intro TRAINER_KOJI_3, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_13:
	.string "Transition test No. 13 of 37:\n"
	.string "“Aqua”$"

RA_Mistralton_Script_Transition_13::
	lock
	msgbox RA_Mistralton_Text_Transition_13, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_13::
	trainerbattle_no_intro TRAINER_KOJI_4, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_14:
	.string "Transition test No. 14 of 37:\n"
	.string "“Magma”$"

RA_Mistralton_Script_Transition_14::
	lock
	msgbox RA_Mistralton_Text_Transition_14, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_14::
	trainerbattle_no_intro TRAINER_KOJI_5, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_15:
	.string "Transition test No. 15 of 37:\n"
	.string "“Regice”$"

RA_Mistralton_Script_Transition_15::
	lock
	msgbox RA_Mistralton_Text_Transition_15, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_15::
	trainerbattle_no_intro TRAINER_CRISTIN_2, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_16:
	.string "Transition test No. 16 of 37:\n"
	.string "“Registeel”$"

RA_Mistralton_Script_Transition_16::
	lock
	msgbox RA_Mistralton_Text_Transition_16, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_16::
	trainerbattle_no_intro TRAINER_CRISTIN_3, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_17:
	.string "Transition test No. 17 of 37:\n"
	.string "“Regirock”$"

RA_Mistralton_Script_Transition_17::
	lock
	msgbox RA_Mistralton_Text_Transition_17, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_17::
	trainerbattle_no_intro TRAINER_CRISTIN_4, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_18:
	.string "Transition test No. 18 of 37:\n"
	.string "“Kyogre”$"

RA_Mistralton_Script_Transition_18::
	lock
	msgbox RA_Mistralton_Text_Transition_18, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_18::
	trainerbattle_no_intro TRAINER_CRISTIN_5, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_19:
	.string "Transition test No. 19 of 37:\n"
	.string "“Groudon”$"

RA_Mistralton_Script_Transition_19::
	lock
	msgbox RA_Mistralton_Text_Transition_19, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_19::
	trainerbattle_no_intro TRAINER_FERNANDO_2, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_20:
	.string "Transition test No. 20 of 37:\n"
	.string "“Rayquaza”$"

RA_Mistralton_Script_Transition_20::
	lock
	msgbox RA_Mistralton_Text_Transition_20, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_20::
	trainerbattle_no_intro TRAINER_FERNANDO_3, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_21:
	.string "Transition test No. 21 of 37:\n"
	.string "“Shred Split”$"

RA_Mistralton_Script_Transition_21::
	lock
	msgbox RA_Mistralton_Text_Transition_21, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_21::
	trainerbattle_no_intro TRAINER_FERNANDO_4, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_22:
	.string "Transition test No. 22 of 37:\n"
	.string "“Black Hole”$"

RA_Mistralton_Script_Transition_22::
	lock
	msgbox RA_Mistralton_Text_Transition_22, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_22::

	trainerbattle_no_intro TRAINER_FERNANDO_5, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_23:
	.string "Transition test No. 23 of 37:\n"
	.string "“Black Hole Pulsate”$"

RA_Mistralton_Script_Transition_23::
	lock
	msgbox RA_Mistralton_Text_Transition_23, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_23::
	trainerbattle_no_intro TRAINER_SAWYER_2, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_24:
	.string "Transition test No. 24 of 37:\n"
	.string "“Rectangular Spiral”$"

RA_Mistralton_Script_Transition_24::
	lock
	msgbox RA_Mistralton_Text_Transition_24, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_24::
	trainerbattle_no_intro TRAINER_SAWYER_3, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_25:
	.string "Transition test No. 25 of 37:\n"
	.string "“Frontier Logo Wiggle”$"

RA_Mistralton_Script_Transition_25::
	lock
	msgbox RA_Mistralton_Text_Transition_25, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_25::
	trainerbattle_no_intro TRAINER_SAWYER_4, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_26:
	.string "Transition test No. 26 of 37:\n"
	.string "“Frontier Logo Wave”$"

RA_Mistralton_Script_Transition_26::
	lock
	msgbox RA_Mistralton_Text_Transition_26, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_26::
	trainerbattle_no_intro TRAINER_SAWYER_5, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_27:
	.string "Transition test No. 27 of 37:\n"
	.string "“Frontier Squares”$"

RA_Mistralton_Script_Transition_27::
	lock
	msgbox RA_Mistralton_Text_Transition_27, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_27::
	trainerbattle_no_intro TRAINER_GABRIELLE_2, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_28:
	.string "Transition test No. 28 of 37:\n"
	.string "“Frontier Squares Scroll”$"

RA_Mistralton_Script_Transition_28::
	lock
	msgbox RA_Mistralton_Text_Transition_28, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_28::
	trainerbattle_no_intro TRAINER_GABRIELLE_3, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_29:
	.string "Transition test No. 29 of 37:\n"
	.string "“Frontier Squares Spiral”$"

RA_Mistralton_Script_Transition_29::
	lock
	msgbox RA_Mistralton_Text_Transition_29, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_29::
	trainerbattle_no_intro TRAINER_GABRIELLE_4, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_30:
	.string "Transition test No. 30 of 37:\n"
	.string "“Frontier Circles Meet”$"

RA_Mistralton_Script_Transition_30::
	lock
	msgbox RA_Mistralton_Text_Transition_30, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_30::
	trainerbattle_no_intro TRAINER_GABRIELLE_5, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_31:
	.string "Transition test No. 31 of 37:\n"
	.string "“Frontier Circles Cross”$"

RA_Mistralton_Script_Transition_31::
	lock
	msgbox RA_Mistralton_Text_Transition_31, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_31::
	trainerbattle_no_intro TRAINER_THALIA_2, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_32:
	.string "Transition test No. 32 of 37:\n"
	.string "“Frontier Circles Asymmetric Spiral”$"

RA_Mistralton_Script_Transition_32::
	lock
	msgbox RA_Mistralton_Text_Transition_32, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_32::
	trainerbattle_no_intro TRAINER_THALIA_3, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_33:
	.string "Transition test No. 33 of 37:\n"
	.string "“Frontier Circles Symmetric Spiral”$"

RA_Mistralton_Script_Transition_33::
	lock
	msgbox RA_Mistralton_Text_Transition_33, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_33::
	trainerbattle_no_intro TRAINER_THALIA_4, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_34:
	.string "Transition test No. 34 of 37:\n"
	.string "“Frontier Circles Meet in Sequence”$"

RA_Mistralton_Script_Transition_34::
	lock
	msgbox RA_Mistralton_Text_Transition_34, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_34::
	trainerbattle_no_intro TRAINER_THALIA_5, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_35:
	.string "Transition test No. 35 of 37:\n"
	.string "“Frontier Circles Cross in Sequence”$"

RA_Mistralton_Script_Transition_35::
	lock
	msgbox RA_Mistralton_Text_Transition_35, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_35::
	trainerbattle_no_intro TRAINER_MARIELA, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_36:
	.string "Transition test No. 36 of 37:\n"
	.string "“Frontier Circles Asymmetric Spiral in\l"
	.string "Sequence”$"

RA_Mistralton_Script_Transition_36::
	lock
	msgbox RA_Mistralton_Text_Transition_36, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_36::
	trainerbattle_no_intro TRAINER_ALVARO, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end

RA_Mistralton_Text_Transition_37:
	.string "Transition test No. 37 of 37:\n"
	.string "“Frontier Circles Symmetric Spiral in\l"
	.string "Sequence”$"

RA_Mistralton_Script_Transition_37::
	lock
	msgbox RA_Mistralton_Text_Transition_37, MSGBOX_DEFAULT
	closemessage
	release
	end

RA_Mistralton_EventScript_Transition_37::
	trainerbattle_no_intro TRAINER_EVERETT, RA_Mistralton_Text_Transition_Defeat
	msgbox RA_Mistralton_Text_Transition_Defeat, MSGBOX_AUTOCLOSE
	end
