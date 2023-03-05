.set LOCALID_LOOKER, 1
.set LOCALID_MAGNOLIA, 2

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
	removeobject LOCALID_LOOKER
	setflag FLAG_TEMP_5
	setvar VAR_RA_PLAYERSHOUSE_INTRO_STATE, 4
	end

RA_AmnestyHQ_2F_Script_PlayerEnters::
	lockall

	setflag FLAG_SYS_POKEDEX_GET
	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_2F_Move_PlayerEnters
	waitmovement 0
	delay 16
	delay 16

	playse SE_EXIT
	clearflag FLAG_TEMP_5
	addobject LOCALID_LOOKER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, RA_AmnestyHQ_2F_Move_PlayerEnters
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_2F_Move_PlayerFaces
	waitmovement 0

	namebox name_looker
	msgbox RA_AmnestyHQ_2F_Text_LookerMagicHappens, MSGBOX_DEFAULT
	closemessage
	hidenamebox
	delay 16
	delay 16

	applymovement LOCALID_LOOKER, RA_AmnestyHQ_2F_Move_FollowLooker1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_2F_Move_PlayerFaces2
	applymovement LOCALID_LOOKER, RA_AmnestyHQ_2F_Move_FollowLooker2
	waitmovement 0
	applymovement LOCALID_LOOKER, RA_AmnestyHQ_2F_Move_FollowLooker3
	applymovement OBJ_EVENT_ID_PLAYER, RA_AmnestyHQ_2F_Move_FollowLooker4
	waitmovement 0
	call RA_Magnolia_Exclaim_FaceDown
	applymovement LOCALID_MAGNOLIA, RA_AmnestyHQ_2F_Move_MagnoliaMeets
	waitmovement 0
	delay 16
	delay 16

	namebox name_magnolia
	msgbox RA_Lipsum, MSGBOX_DEFAULT
	closemessage
	hidenamebox

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

RA_AmnestyHQ_2F_Move_PlayerFaces2:
	face_right
	step_end

RA_AmnestyHQ_2F_Move_MagnoliaFaces:
	face_down
	step_end

RA_AmnestyHQ_2F_Move_FollowLooker1:
	walk_right
	step_end

RA_AmnestyHQ_2F_Move_FollowLooker2:
	walk_down
	step_end

RA_AmnestyHQ_2F_Move_FollowLooker3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RA_AmnestyHQ_2F_Move_FollowLooker4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

RA_AmnestyHQ_2F_Move_MagnoliaMeets:
	walk_slow_down
	walk_slow_left
	walk_slow_left
	face_down
	step_end

RA_AmnestyHQ_2F_Text_LookerMagicHappens:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}! This is where, so they say,\n"
	.string "the “magic happens”!\p"
	.string "It's more or less business as usual for\n"
	.string "the {COLOR RED}Cargo Service{COLOR DARK_GRAY}, downstairs...\p"
	.string "...which has made it easier to keep our\n"
	.string "little command centre under the radar.\p"
	.string "Ah! Speaking of “command”, the\n"
	.string "{COLOR GREEN}Professor {COLOR DARK_GRAY}has been dying to meet you.\p"
	.string "This way.$"

name_magnolia:
	.string "Magnolia$"














@Defining common scripts to save time

RA_FaceUp:
	face_up
	step_end

RA_FaceRight:
	face_right
	step_end

RA_FaceDown:
	face_down
	step_end

RA_FaceLeft:
	face_left
	step_end

RA_Lipsum:
	.string "Lorem ipsum dolor sit amet, consectetur\n"
	.string "adipiscing elit.\p"
	.string "Nunc et interdum orci... Eget facilisis\n"
	.string "tellus!$"


@Object1 scripts

RA_Object1_FaceUp::
	applymovement 1, RA_FaceUp
	waitmovement 0
	return

RA_Object1_FaceRight::
	applymovement 1, RA_FaceRight
	waitmovement 0
	return

RA_Object1_FaceDown::
	applymovement 1, RA_FaceDown
	waitmovement 0
	return

RA_Object1_FaceLeft::
	applymovement 1, RA_FaceLeft
	waitmovement 0
	return

RA_Object1_Exclaim::
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Exclaim_FaceUp::
	playse SE_PIN
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Exclaim_FaceRight::
	playse SE_PIN
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Exclaim_FaceDown::
	playse SE_PIN
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_DoubleExclaim::
	playse SE_PIN
	applymovement 1, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Question::
	playse SE_RG_HELP_OPEN
	applymovement 1, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement 1, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Heart::
	playse SE_SHINY
	applymovement 1, Common_Movement_Heart
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Heart_FaceUp::
	playse SE_SHINY
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_Heart
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Heart_FaceRight::
	playse SE_SHINY
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_Heart
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Heart_FaceDown::
	playse SE_SHINY
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_Heart
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Heart_FaceLeft::
	playse SE_SHINY
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_Heart
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Dead::
	playse SE_M_STAT_DECREASE
	applymovement 1, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Dizzy::
	playse SE_M_ATTRACT2
	applymovement 1, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Angry::
	playse SE_FAILURE
	applymovement 1, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Angry_FaceUp::
	playse SE_FAILURE
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Angry_FaceRight::
	playse SE_FAILURE
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Angry_FaceDown::
	playse SE_FAILURE
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Sleep::
	playse SE_M_SNORE
	applymovement 1, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Happy::
	playse SE_M_DETECT
	applymovement 1, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_ThreeDots::
	applymovement 1, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_ThreeDots_FaceUp::
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_ThreeDots_FaceRight::
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_ThreeDots_FaceDown::
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_ThreeDots_FaceLeft::
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return


@Object2 scripts

RA_Object2_FaceUp::
	applymovement 2, RA_FaceUp
	waitmovement 0
	return

RA_Object2_FaceRight::
	applymovement 2, RA_FaceRight
	waitmovement 0
	return

RA_Object2_FaceDown::
	applymovement 2, RA_FaceDown
	waitmovement 0
	return

RA_Object2_FaceLeft::
	applymovement 2, RA_FaceLeft
	waitmovement 0
	return

RA_Object2_Exclaim::
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Exclaim_FaceUp::
	playse SE_PIN
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Exclaim_FaceRight::
	playse SE_PIN
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Exclaim_FaceDown::
	playse SE_PIN
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_DoubleExclaim::
	playse SE_PIN
	applymovement 2, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Question::
	playse SE_RG_HELP_OPEN
	applymovement 2, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement 2, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Heart::
	playse SE_SHINY
	applymovement 2, Common_Movement_Heart
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Heart_FaceUp::
	playse SE_SHINY
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_Heart
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Heart_FaceRight::
	playse SE_SHINY
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_Heart
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Heart_FaceDown::
	playse SE_SHINY
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_Heart
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Heart_FaceLeft::
	playse SE_SHINY
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_Heart
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Dead::
	playse SE_M_STAT_DECREASE
	applymovement 2, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Dizzy::
	playse SE_M_ATTRACT2
	applymovement 2, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Angry::
	playse SE_FAILURE
	applymovement 2, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Angry_FaceUp::
	playse SE_FAILURE
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Angry_FaceRight::
	playse SE_FAILURE
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Angry_FaceDown::
	playse SE_FAILURE
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Sleep::
	playse SE_M_SNORE
	applymovement 2, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Happy::
	playse SE_M_DETECT
	applymovement 2, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_ThreeDots::
	applymovement 2, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_ThreeDots_FaceUp::
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_ThreeDots_FaceRight::
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_ThreeDots_FaceDown::
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_ThreeDots_FaceLeft::
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return


@Object3 scripts

RA_Object3_FaceUp::
	applymovement 3, RA_FaceUp
	waitmovement 0
	return

RA_Object3_FaceRight::
	applymovement 3, RA_FaceRight
	waitmovement 0
	return

RA_Object3_FaceDown::
	applymovement 3, RA_FaceDown
	waitmovement 0
	return

RA_Object3_FaceLeft::
	applymovement 3, RA_FaceLeft
	waitmovement 0
	return

RA_Object3_Exclaim::
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Exclaim_FaceUp::
	playse SE_PIN
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Exclaim_FaceRight::
	playse SE_PIN
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Exclaim_FaceDown::
	playse SE_PIN
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_DoubleExclaim::
	playse SE_PIN
	applymovement 3, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Question::
	playse SE_RG_HELP_OPEN
	applymovement 3, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement 3, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Heart::
	playse SE_SHINY
	applymovement 3, Common_Movement_Heart
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Heart_FaceUp::
	playse SE_SHINY
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_Heart
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Heart_FaceRight::
	playse SE_SHINY
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_Heart
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Heart_FaceDown::
	playse SE_SHINY
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_Heart
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Heart_FaceLeft::
	playse SE_SHINY
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_Heart
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Dead::
	playse SE_M_STAT_DECREASE
	applymovement 3, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Dizzy::
	playse SE_M_ATTRACT2
	applymovement 3, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Angry::
	playse SE_FAILURE
	applymovement 3, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Angry_FaceUp::
	playse SE_FAILURE
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Angry_FaceRight::
	playse SE_FAILURE
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Angry_FaceDown::
	playse SE_FAILURE
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Sleep::
	playse SE_M_SNORE
	applymovement 3, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Happy::
	playse SE_M_DETECT
	applymovement 3, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_ThreeDots::
	applymovement 3, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_ThreeDots_FaceUp::
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_ThreeDots_FaceRight::
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_ThreeDots_FaceDown::
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_ThreeDots_FaceLeft::
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return


@Object4 scripts

RA_Object4_FaceUp::
	applymovement 4, RA_FaceUp
	waitmovement 0
	return

RA_Object4_FaceRight::
	applymovement 4, RA_FaceRight
	waitmovement 0
	return

RA_Object4_FaceDown::
	applymovement 4, RA_FaceDown
	waitmovement 0
	return

RA_Object4_FaceLeft::
	applymovement 4, RA_FaceLeft
	waitmovement 0
	return

RA_Object4_Exclaim::
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Exclaim_FaceUp::
	playse SE_PIN
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Exclaim_FaceRight::
	playse SE_PIN
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Exclaim_FaceDown::
	playse SE_PIN
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_DoubleExclaim::
	playse SE_PIN
	applymovement 4, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Question::
	playse SE_RG_HELP_OPEN
	applymovement 4, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement 4, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Heart::
	playse SE_SHINY
	applymovement 4, Common_Movement_Heart
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Heart_FaceUp::
	playse SE_SHINY
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_Heart
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Heart_FaceRight::
	playse SE_SHINY
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_Heart
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Heart_FaceDown::
	playse SE_SHINY
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_Heart
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Heart_FaceLeft::
	playse SE_SHINY
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_Heart
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Dead::
	playse SE_M_STAT_DECREASE
	applymovement 4, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Dizzy::
	playse SE_M_ATTRACT2
	applymovement 4, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Angry::
	playse SE_FAILURE
	applymovement 4, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Angry_FaceUp::
	playse SE_FAILURE
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Angry_FaceRight::
	playse SE_FAILURE
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Angry_FaceDown::
	playse SE_FAILURE
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Sleep::
	playse SE_M_SNORE
	applymovement 4, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Happy::
	playse SE_M_DETECT
	applymovement 4, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_ThreeDots::
	applymovement 4, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_ThreeDots_FaceUp::
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_ThreeDots_FaceRight::
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_ThreeDots_FaceDown::
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_ThreeDots_FaceLeft::
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return


@Object5 scripts

RA_Object5_FaceUp::
	applymovement 5, RA_FaceUp
	waitmovement 0
	return

RA_Object5_FaceRight::
	applymovement 5, RA_FaceRight
	waitmovement 0
	return

RA_Object5_FaceDown::
	applymovement 5, RA_FaceDown
	waitmovement 0
	return

RA_Object5_FaceLeft::
	applymovement 5, RA_FaceLeft
	waitmovement 0
	return

RA_Object5_Exclaim::
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Exclaim_FaceUp::
	playse SE_PIN
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Exclaim_FaceRight::
	playse SE_PIN
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Exclaim_FaceDown::
	playse SE_PIN
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_DoubleExclaim::
	playse SE_PIN
	applymovement 5, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Question::
	playse SE_RG_HELP_OPEN
	applymovement 5, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement 5, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Heart::
	playse SE_SHINY
	applymovement 5, Common_Movement_Heart
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Heart_FaceUp::
	playse SE_SHINY
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_Heart
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Heart_FaceRight::
	playse SE_SHINY
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_Heart
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Heart_FaceDown::
	playse SE_SHINY
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_Heart
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Heart_FaceLeft::
	playse SE_SHINY
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_Heart
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Dead::
	playse SE_M_STAT_DECREASE
	applymovement 5, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Dizzy::
	playse SE_M_ATTRACT2
	applymovement 5, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Angry::
	playse SE_FAILURE
	applymovement 5, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Angry_FaceUp::
	playse SE_FAILURE
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Angry_FaceRight::
	playse SE_FAILURE
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Angry_FaceDown::
	playse SE_FAILURE
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Sleep::
	playse SE_M_SNORE
	applymovement 5, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Happy::
	playse SE_M_DETECT
	applymovement 5, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_ThreeDots::
	applymovement 5, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_ThreeDots_FaceUp::
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_ThreeDots_FaceRight::
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_ThreeDots_FaceDown::
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_ThreeDots_FaceLeft::
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return


@Object6 scripts

RA_Object6_FaceUp::
	applymovement 6, RA_FaceUp
	waitmovement 0
	return

RA_Object6_FaceRight::
	applymovement 6, RA_FaceRight
	waitmovement 0
	return

RA_Object6_FaceDown::
	applymovement 6, RA_FaceDown
	waitmovement 0
	return

RA_Object6_FaceLeft::
	applymovement 6, RA_FaceLeft
	waitmovement 0
	return

RA_Object6_Exclaim::
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Exclaim_FaceUp::
	playse SE_PIN
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Exclaim_FaceRight::
	playse SE_PIN
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Exclaim_FaceDown::
	playse SE_PIN
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_DoubleExclaim::
	playse SE_PIN
	applymovement 6, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Question::
	playse SE_RG_HELP_OPEN
	applymovement 6, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement 6, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Heart::
	playse SE_SHINY
	applymovement 6, Common_Movement_Heart
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Heart_FaceUp::
	playse SE_SHINY
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_Heart
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Heart_FaceRight::
	playse SE_SHINY
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_Heart
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Heart_FaceDown::
	playse SE_SHINY
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_Heart
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Heart_FaceLeft::
	playse SE_SHINY
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_Heart
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Dead::
	playse SE_M_STAT_DECREASE
	applymovement 6, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Dizzy::
	playse SE_M_ATTRACT2
	applymovement 6, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Angry::
	playse SE_FAILURE
	applymovement 6, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Angry_FaceUp::
	playse SE_FAILURE
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Angry_FaceRight::
	playse SE_FAILURE
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Angry_FaceDown::
	playse SE_FAILURE
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Sleep::
	playse SE_M_SNORE
	applymovement 6, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Happy::
	playse SE_M_DETECT
	applymovement 6, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_ThreeDots::
	applymovement 6, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_ThreeDots_FaceUp::
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_ThreeDots_FaceRight::
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_ThreeDots_FaceDown::
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_ThreeDots_FaceLeft::
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return


@Object7 scripts

RA_Object7_FaceUp::
	applymovement 7, RA_FaceUp
	waitmovement 0
	return

RA_Object7_FaceRight::
	applymovement 7, RA_FaceRight
	waitmovement 0
	return

RA_Object7_FaceDown::
	applymovement 7, RA_FaceDown
	waitmovement 0
	return

RA_Object7_FaceLeft::
	applymovement 7, RA_FaceLeft
	waitmovement 0
	return

RA_Object7_Exclaim::
	playse SE_PIN
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Exclaim_FaceUp::
	playse SE_PIN
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Exclaim_FaceRight::
	playse SE_PIN
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Exclaim_FaceDown::
	playse SE_PIN
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_DoubleExclaim::
	playse SE_PIN
	applymovement 7, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Question::
	playse SE_RG_HELP_OPEN
	applymovement 7, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement 7, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Heart::
	playse SE_SHINY
	applymovement 7, Common_Movement_Heart
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Heart_FaceUp::
	playse SE_SHINY
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_Heart
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Heart_FaceRight::
	playse SE_SHINY
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_Heart
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Heart_FaceDown::
	playse SE_SHINY
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_Heart
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Heart_FaceLeft::
	playse SE_SHINY
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_Heart
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Dead::
	playse SE_M_STAT_DECREASE
	applymovement 7, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Dizzy::
	playse SE_M_ATTRACT2
	applymovement 7, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Angry::
	playse SE_FAILURE
	applymovement 7, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Angry_FaceUp::
	playse SE_FAILURE
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Angry_FaceRight::
	playse SE_FAILURE
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Angry_FaceDown::
	playse SE_FAILURE
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Sleep::
	playse SE_M_SNORE
	applymovement 7, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Happy::
	playse SE_M_DETECT
	applymovement 7, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_ThreeDots::
	applymovement 7, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_ThreeDots_FaceUp::
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_ThreeDots_FaceRight::
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_ThreeDots_FaceDown::
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_ThreeDots_FaceLeft::
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return


@Object8 scripts

RA_Object8_FaceUp::
	applymovement 8, RA_FaceUp
	waitmovement 0
	return

RA_Object8_FaceRight::
	applymovement 8, RA_FaceRight
	waitmovement 0
	return

RA_Object8_FaceDown::
	applymovement 8, RA_FaceDown
	waitmovement 0
	return

RA_Object8_FaceLeft::
	applymovement 8, RA_FaceLeft
	waitmovement 0
	return

RA_Object8_Exclaim::
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Exclaim_FaceUp::
	playse SE_PIN
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Exclaim_FaceRight::
	playse SE_PIN
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Exclaim_FaceDown::
	playse SE_PIN
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_DoubleExclaim::
	playse SE_PIN
	applymovement 8, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Question::
	playse SE_RG_HELP_OPEN
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement 8, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Heart::
	playse SE_SHINY
	applymovement 8, Common_Movement_Heart
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Heart_FaceUp::
	playse SE_SHINY
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_Heart
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Heart_FaceRight::
	playse SE_SHINY
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_Heart
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Heart_FaceDown::
	playse SE_SHINY
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_Heart
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Heart_FaceLeft::
	playse SE_SHINY
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_Heart
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Dead::
	playse SE_M_STAT_DECREASE
	applymovement 8, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Dizzy::
	playse SE_M_ATTRACT2
	applymovement 8, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Angry::
	playse SE_FAILURE
	applymovement 8, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Angry_FaceUp::
	playse SE_FAILURE
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Angry_FaceRight::
	playse SE_FAILURE
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Angry_FaceDown::
	playse SE_FAILURE
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Sleep::
	playse SE_M_SNORE
	applymovement 8, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Happy::
	playse SE_M_DETECT
	applymovement 8, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_ThreeDots::
	applymovement 8, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_ThreeDots_FaceUp::
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_ThreeDots_FaceRight::
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_ThreeDots_FaceDown::
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_ThreeDots_FaceLeft::
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return


@Object9 scripts

RA_Object9_FaceUp::
	applymovement 9, RA_FaceUp
	waitmovement 0
	return

RA_Object9_FaceRight::
	applymovement 9, RA_FaceRight
	waitmovement 0
	return

RA_Object9_FaceDown::
	applymovement 9, RA_FaceDown
	waitmovement 0
	return

RA_Object9_FaceLeft::
	applymovement 9, RA_FaceLeft
	waitmovement 0
	return

RA_Object9_Exclaim::
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Exclaim_FaceUp::
	playse SE_PIN
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Exclaim_FaceRight::
	playse SE_PIN
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Exclaim_FaceDown::
	playse SE_PIN
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_DoubleExclaim::
	playse SE_PIN
	applymovement 9, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Question::
	playse SE_RG_HELP_OPEN
	applymovement 9, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement 9, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Heart::
	playse SE_SHINY
	applymovement 9, Common_Movement_Heart
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Heart_FaceUp::
	playse SE_SHINY
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_Heart
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Heart_FaceRight::
	playse SE_SHINY
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_Heart
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Heart_FaceDown::
	playse SE_SHINY
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_Heart
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Heart_FaceLeft::
	playse SE_SHINY
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_Heart
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Dead::
	playse SE_M_STAT_DECREASE
	applymovement 9, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Dizzy::
	playse SE_M_ATTRACT2
	applymovement 9, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Angry::
	playse SE_FAILURE
	applymovement 9, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Angry_FaceUp::
	playse SE_FAILURE
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Angry_FaceRight::
	playse SE_FAILURE
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Angry_FaceDown::
	playse SE_FAILURE
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Sleep::
	playse SE_M_SNORE
	applymovement 9, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Happy::
	playse SE_M_DETECT
	applymovement 9, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_ThreeDots::
	applymovement 9, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_ThreeDots_FaceUp::
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_ThreeDots_FaceRight::
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_ThreeDots_FaceDown::
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_ThreeDots_FaceLeft::
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return


@Object10 scripts

RA_Object10_FaceUp::
	applymovement 10, RA_FaceUp
	waitmovement 0
	return

RA_Object10_FaceRight::
	applymovement 10, RA_FaceRight
	waitmovement 0
	return

RA_Object10_FaceDown::
	applymovement 10, RA_FaceDown
	waitmovement 0
	return

RA_Object10_FaceLeft::
	applymovement 10, RA_FaceLeft
	waitmovement 0
	return

RA_Object10_Exclaim::
	playse SE_PIN
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Exclaim_FaceUp::
	playse SE_PIN
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Exclaim_FaceRight::
	playse SE_PIN
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Exclaim_FaceDown::
	playse SE_PIN
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_DoubleExclaim::
	playse SE_PIN
	applymovement 10, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Question::
	playse SE_RG_HELP_OPEN
	applymovement 10, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement 10, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Heart::
	playse SE_SHINY
	applymovement 10, Common_Movement_Heart
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Heart_FaceUp::
	playse SE_SHINY
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_Heart
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Heart_FaceRight::
	playse SE_SHINY
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_Heart
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Heart_FaceDown::
	playse SE_SHINY
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_Heart
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Heart_FaceLeft::
	playse SE_SHINY
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_Heart
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Dead::
	playse SE_M_STAT_DECREASE
	applymovement 10, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_CrossEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Dizzy::
	playse SE_M_ATTRACT2
	applymovement 10, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Angry::
	playse SE_FAILURE
	applymovement 10, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Angry_FaceUp::
	playse SE_FAILURE
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Angry_FaceRight::
	playse SE_FAILURE
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Angry_FaceDown::
	playse SE_FAILURE
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_AngryEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Sleep::
	playse SE_M_SNORE
	applymovement 10, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Happy::
	playse SE_M_DETECT
	applymovement 10, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_ThreeDots::
	applymovement 10, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_ThreeDots_FaceUp::
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_ThreeDots_FaceRight::
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_ThreeDots_FaceDown::
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_ThreeDots_FaceLeft::
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_DotDotDot
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return


@Player scripts

RA_Player_FaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	return

RA_Player_FaceRight::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	return

RA_Player_FaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	return

RA_Player_FaceLeft::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	return

RA_Player_Exclaim::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Exclaim_FaceUp::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Exclaim_FaceRight::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Exclaim_FaceDown::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_DoubleExclaim::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Question::
	playse SE_RG_HELP_OPEN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Heart::
	playse SE_SHINY
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Heart
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Heart_FaceUp::
	playse SE_SHINY
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Heart
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Heart_FaceRight::
	playse SE_SHINY
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Heart
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Heart_FaceDown::
	playse SE_SHINY
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Heart
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Heart_FaceLeft::
	playse SE_SHINY
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Heart
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Dead::
	playse SE_M_STAT_DECREASE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_CrossEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_CrossEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_CrossEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_CrossEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_CrossEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Dizzy::
	playse SE_M_ATTRACT2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Angry::
	playse SE_FAILURE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_AngryEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Angry_FaceUp::
	playse SE_FAILURE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_AngryEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Angry_FaceRight::
	playse SE_FAILURE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_AngryEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Angry_FaceDown::
	playse SE_FAILURE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_AngryEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_AngryEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Sleep::
	playse SE_M_SNORE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Happy::
	playse SE_M_DETECT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_ThreeDots::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DotDotDot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_ThreeDots_FaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DotDotDot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_ThreeDots_FaceRight::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DotDotDot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_ThreeDots_FaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DotDotDot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_ThreeDots_FaceLeft::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_DotDotDot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return


@Looker scripts

RA_Looker_FaceUp::
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	return

RA_Looker_FaceRight::
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	return

RA_Looker_FaceDown::
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	return

RA_Looker_FaceLeft::
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	return

RA_Looker_Exclaim::
	playse SE_PIN
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Exclaim_FaceUp::
	playse SE_PIN
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Exclaim_FaceRight::
	playse SE_PIN
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Exclaim_FaceDown::
	playse SE_PIN
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_DoubleExclaim::
	playse SE_PIN
	applymovement LOCALID_LOOKER, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Question::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_LOOKER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_LOOKER, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Heart::
	playse SE_SHINY
	applymovement LOCALID_LOOKER, Common_Movement_Heart
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Heart_FaceUp::
	playse SE_SHINY
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Heart
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Heart_FaceRight::
	playse SE_SHINY
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Heart
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Heart_FaceDown::
	playse SE_SHINY
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Heart
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Heart_FaceLeft::
	playse SE_SHINY
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Heart
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Dead::
	playse SE_M_STAT_DECREASE
	applymovement LOCALID_LOOKER, Common_Movement_CrossEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_CrossEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_CrossEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_CrossEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_CrossEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Dizzy::
	playse SE_M_ATTRACT2
	applymovement LOCALID_LOOKER, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Angry::
	playse SE_FAILURE
	applymovement LOCALID_LOOKER, Common_Movement_AngryEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Angry_FaceUp::
	playse SE_FAILURE
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_AngryEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Angry_FaceRight::
	playse SE_FAILURE
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_AngryEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Angry_FaceDown::
	playse SE_FAILURE
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_AngryEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_AngryEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Sleep::
	playse SE_M_SNORE
	applymovement LOCALID_LOOKER, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Happy::
	playse SE_M_DETECT
	applymovement LOCALID_LOOKER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_ThreeDots::
	applymovement LOCALID_LOOKER, Common_Movement_DotDotDot
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_ThreeDots_FaceUp::
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DotDotDot
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_ThreeDots_FaceRight::
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DotDotDot
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_ThreeDots_FaceDown::
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DotDotDot
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_ThreeDots_FaceLeft::
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_DotDotDot
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return


@Magnolia scripts

RA_Magnolia_FaceUp::
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	return

RA_Magnolia_FaceRight::
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	return

RA_Magnolia_FaceDown::
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	return

RA_Magnolia_FaceLeft::
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	return

RA_Magnolia_Exclaim::
	playse SE_PIN
	applymovement LOCALID_MAGNOLIA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Exclaim_FaceUp::
	playse SE_PIN
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Exclaim_FaceRight::
	playse SE_PIN
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Exclaim_FaceDown::
	playse SE_PIN
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Exclaim_FaceLeft::
	playse SE_PIN
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_DoubleExclaim::
	playse SE_PIN
	applymovement LOCALID_MAGNOLIA, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_DoubleExclaim_FaceUp::
	playse SE_PIN
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_DoubleExclaim_FaceRight::
	playse SE_PIN
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_DoubleExclaim_FaceDown::
	playse SE_PIN
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_DoubleExclaim_FaceLeft::
	playse SE_PIN
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DoubleExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Question::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_MAGNOLIA, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Question_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Question_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Question_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Question_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_ExclaimQuestion::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_MAGNOLIA, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_ExclaimQuestion_FaceUp::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_ExclaimQuestion_FaceRight::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_ExclaimQuestion_FaceDown::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_ExclaimQuestion_FaceLeft::
	playse SE_RG_HELP_OPEN
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DoubleQuestionMark
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Heart::
	playse SE_SHINY
	applymovement LOCALID_MAGNOLIA, Common_Movement_Heart
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Heart_FaceUp::
	playse SE_SHINY
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Heart
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Heart_FaceRight::
	playse SE_SHINY
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Heart
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Heart_FaceDown::
	playse SE_SHINY
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Heart
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Heart_FaceLeft::
	playse SE_SHINY
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Heart
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Dead::
	playse SE_M_STAT_DECREASE
	applymovement LOCALID_MAGNOLIA, Common_Movement_CrossEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Dead_FaceUp::
	playse SE_M_STAT_DECREASE
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_CrossEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Dead_FaceRight::
	playse SE_M_STAT_DECREASE
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_CrossEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Dead_FaceDown::
	playse SE_M_STAT_DECREASE
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_CrossEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Dead_FaceLeft::
	playse SE_M_STAT_DECREASE
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_CrossEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Dizzy::
	playse SE_M_ATTRACT2
	applymovement LOCALID_MAGNOLIA, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Dizzy_FaceUp::
	playse SE_M_ATTRACT2
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Dizzy_FaceRight::
	playse SE_M_ATTRACT2
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Dizzy_FaceDown::
	playse SE_M_ATTRACT2
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Dizzy_FaceLeft::
	playse SE_M_ATTRACT2
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DizzySpiral
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Angry::
	playse SE_FAILURE
	applymovement LOCALID_MAGNOLIA, Common_Movement_AngryEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Angry_FaceUp::
	playse SE_FAILURE
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_AngryEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Angry_FaceRight::
	playse SE_FAILURE
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_AngryEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Angry_FaceDown::
	playse SE_FAILURE
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_AngryEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Angry_FaceLeft::
	playse SE_FAILURE
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_AngryEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Sleep::
	playse SE_M_SNORE
	applymovement LOCALID_MAGNOLIA, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Sleep_FaceUp::
	playse SE_M_SNORE
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Sleep_FaceRight::
	playse SE_M_SNORE
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Sleep_FaceDown::
	playse SE_M_SNORE
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Sleep_FaceLeft::
	playse SE_M_SNORE
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ZeeZeeZee
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Happy::
	playse SE_M_DETECT
	applymovement LOCALID_MAGNOLIA, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Happy_FaceUp::
	playse SE_M_DETECT
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Happy_FaceRight::
	playse SE_M_DETECT
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Happy_FaceDown::
	playse SE_M_DETECT
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Happy_FaceLeft::
	playse SE_M_DETECT
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_AnimeEyes
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_ThreeDots::
	applymovement LOCALID_MAGNOLIA, Common_Movement_DotDotDot
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_ThreeDots_FaceUp::
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DotDotDot
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_ThreeDots_FaceRight::
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DotDotDot
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_ThreeDots_FaceDown::
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DotDotDot
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_ThreeDots_FaceLeft::
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_DotDotDot
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Text_Gain_Rank0:
	.string "The {COLOR RED}Amnesty Institute{COLOR DARK_GRAY} took me on as a\n"
	.string "{COLOR RED}Trainee{COLOR DARK_GRAY}! My journey starts here!$"

RA_Player_Text_Gain_PokePass:
	.string "I finally got my own {COLOR RED}Poké Pass{COLOR DARK_GRAY}!$"

RA_Player_Text_Gain_Badge0:
	.string "I got the {COLOR RED}White Band{COLOR DARK_GRAY}, and carefully\n"
	.string "attached it to my {COLOR RED}Poké Pass{COLOR DARK_GRAY}.$"

RA_Player_Text_Explain_Badge0:
	.string "{COLOR BLUE}The White Band is your first\n"
	.string "{COLOR BLUE}Rank Insignia.\p"
	.string "{COLOR BLUE}You'll gain more Insignia as you rise\n"
	.string "{COLOR BLUE}through the Amnesty Institute's ranks.\p"
	.string "{COLOR BLUE}Press  {START_BUTTON}  at any time to check your\n"
	.string "{COLOR BLUE}Poké Pass and admire your Insignia!\p"
	.string "{COLOR BLUE}With the White Band, you can catch and\n"
	.string "{COLOR BLUE}train Pokémon, as long as you're not in\l"
	.string "{COLOR BLUE}a Restricted Zone.\p"
	.string "{COLOR BLUE}And, you now have access to\n"
	.string "{COLOR BLUE}Pokémon Centres.\p"
	.string "{COLOR BLUE}As for the White Band itself...\p"
	.string "{COLOR BLUE}It's an understated lapel pin made here\n"
	.string "{COLOR BLUE}in Unova. It's warm to the touch.{COLOR DARK_GRAY}$"

RA_Player_Text_Gain_Rank1:
	.string "The {COLOR RED}Amnesty Institute{COLOR DARK_GRAY} promoted me to\n"
	.string "{COLOR RED}Recruit{COLOR DARK_GRAY}!$"

RA_Player_Text_Gain_Badge1:
	.string "I got the {COLOR RED}Red Gem{COLOR DARK_GRAY}, and carefully\n"
	.string "attached it to my {COLOR RED}Poké Pass{COLOR DARK_GRAY}.$"

RA_Player_Text_Explain_Badge1:
	.string "{COLOR BLUE}With the Red Gem, Pokémon\n"
	.string "{COLOR BLUE}up to Lv. 20 will follow your commands.\p"
	.string "{COLOR BLUE}Your team's Attack\n"
	.string "{COLOR BLUE}stats also rose a bit.\p"
	.string "{COLOR BLUE}And, you now have access to\n"
	.string "{COLOR BLUE}Battle Clubs, including the one here in\l"
	.string "{COLOR BLUE}Mistralton City.\p"
	.string "{COLOR BLUE}As for the Red Gem itself...\p"
	.string "{COLOR BLUE}It formed underground in Hoenn, due\n"
	.string "{COLOR BLUE}to immense heat. It resembles a ruby.{COLOR DARK_GRAY}$"

RA_Player_Text_Gain_Rank2:
	.string "The {COLOR RED}Amnesty Institute{COLOR DARK_GRAY} promoted me to\n"
	.string "{COLOR RED}Officer{COLOR DARK_GRAY}!$"

RA_Player_Text_Gain_Badge2:
	.string "I got the {COLOR RED}Orange Gem{COLOR DARK_GRAY}, and carefully\n"
	.string "attached it to my {COLOR RED}Poké Pass{COLOR DARK_GRAY}.$"

RA_Player_Text_Explain_Badge2:
	.string "{COLOR BLUE}With the Orange Gem, Pokémon\n"
	.string "{COLOR BLUE}up to Lv. 30 will follow your commands.\p"
	.string "{COLOR BLUE}As for the Orange Gem itself...\p"
	.string "{COLOR BLUE}It washed up on a beach in the Alola\n"
	.string "{COLOR BLUE}region. It reflects the sun beautifully.{COLOR DARK_GRAY}$"

RA_Player_Text_Gain_Rank3:
	.string "The {COLOR RED}Amnesty Institute{COLOR DARK_GRAY} promoted me to\n"
	.string "{COLOR RED}Sergeant{COLOR DARK_GRAY}!$"

RA_Player_Text_Gain_Badge3:
	.string "I got the {COLOR RED}Yellow Gem{COLOR DARK_GRAY}, and carefully\n"
	.string "attached it to my {COLOR RED}Poké Pass{COLOR DARK_GRAY}.$"

RA_Player_Text_Explain_Badge3:
	.string "{COLOR BLUE}With the Yellow Gem, Pokémon\n"
	.string "{COLOR BLUE}up to Lv. 40 will follow your commands.\p"
	.string "{COLOR BLUE}Your team's Speed\n"
	.string "{COLOR BLUE}stats also rose a bit.\p"
	.string "{COLOR BLUE}As for the Yellow Gem itself...\p"
	.string "{COLOR BLUE}It holds a faint electrical charge.\n"
	.string "{COLOR BLUE}It was found in Kanto's Power Plant.{COLOR DARK_GRAY}$"

RA_Player_Text_Gain_Rank4:
	.string "The {COLOR RED}Amnesty Institute{COLOR DARK_GRAY} promoted me to\n"
	.string "{COLOR RED}Detective{COLOR DARK_GRAY}!$"

RA_Player_Text_Gain_Badge4:
	.string "I got the {COLOR RED}Green Gem{COLOR DARK_GRAY}, and carefully\n"
	.string "attached it to my {COLOR RED}Poké Pass{COLOR DARK_GRAY}.$"

RA_Player_Text_Explain_Badge4:
	.string "{COLOR BLUE}With the Green Gem, Pokémon\n"
	.string "{COLOR BLUE}up to Lv. 50 will follow your commands.\p"
	.string "{COLOR BLUE}And, you now have access to\n"
	.string "{COLOR BLUE}any Research Hubs you come across.\p"
	.string "{COLOR BLUE}As for the Green Gem itself...\p"
	.string "{COLOR BLUE}Researchers in Kalos say it contains\n"
	.string "{COLOR BLUE}living cells from a legendary Pokémon.{COLOR DARK_GRAY}$"

RA_Player_Text_Gain_Rank5:
	.string "The {COLOR RED}Amnesty Institute{COLOR DARK_GRAY} promoted me to\n"
	.string "{COLOR RED}Lieutenant{COLOR DARK_GRAY}!$"

RA_Player_Text_Gain_Badge5:
	.string "I got the {COLOR RED}Blue Gem{COLOR DARK_GRAY}, and carefully\n"
	.string "attached it to my {COLOR RED}Poké Pass{COLOR DARK_GRAY}.$"

RA_Player_Text_Explain_Badge5:
	.string "{COLOR BLUE}With the Blue Gem, Pokémon\n"
	.string "{COLOR BLUE}up to Lv. 60 will follow your commands.\p"
	.string "{COLOR BLUE}Your team's Defence\n"
	.string "{COLOR BLUE}stats also rose a bit.\p"
	.string "{COLOR BLUE}As for the Blue Gem itself...\p"
	.string "{COLOR BLUE}It's actually a rare, blue-tinted type\n"
	.string "{COLOR BLUE}of diamond found only in Sinnoh.{COLOR DARK_GRAY}$"

RA_Player_Text_Gain_Rank6:
	.string "The {COLOR RED}Amnesty Institute{COLOR DARK_GRAY} promoted me to\n"
	.string "{COLOR RED}Captain{COLOR DARK_GRAY}!$"

RA_Player_Text_Gain_Badge6:
	.string "I got the {COLOR RED}Indigo Gem{COLOR DARK_GRAY}, and carefully\n"
	.string "attached it to my {COLOR RED}Poké Pass{COLOR DARK_GRAY}.$"

RA_Player_Text_Explain_Badge6:
	.string "{COLOR BLUE}With the Indigo Gem, Pokémon\n"
	.string "{COLOR BLUE}up to Lv. 70 will follow your commands.\p"
	.string "{COLOR BLUE}As for the Indigo Gem itself...\p"
	.string "{COLOR BLUE}Made from fallen Galarian Wishing Stars,\n"
	.string "{COLOR BLUE}up close it has a reddish-blue hue.{COLOR DARK_GRAY}$"

RA_Player_Text_Gain_Rank7:
	.string "The {COLOR RED}Amnesty Institute{COLOR DARK_GRAY} promoted me to\n"
	.string "{COLOR RED}Commander{COLOR DARK_GRAY}!$"

RA_Player_Text_Gain_Badge7:
	.string "I got the {COLOR RED}Violet Gem{COLOR DARK_GRAY}, and carefully\n"
	.string "attached it to my {COLOR RED}Poké Pass{COLOR DARK_GRAY}.$"

RA_Player_Text_Explain_Badge7:
	.string "{COLOR BLUE}With the Violet Gem, Pokémon\n"
	.string "{COLOR BLUE}up to Lv. 80 will follow your commands.\p"
	.string "{COLOR BLUE}Your team's Special Attack and\n"
	.string "{COLOR BLUE}Special Defence stats also rose a bit.\p"
	.string "{COLOR BLUE}As for the Violet Gem itself...\p"
	.string "{COLOR BLUE}It's only found in the Paldea region.\n"
	.string "{COLOR BLUE}Its traditional name is “Uva Violeta”.{COLOR DARK_GRAY}$"

RA_Player_Text_Gain_Rank8:
	.string "The {COLOR RED}Amnesty Institute{COLOR DARK_GRAY} promoted me to\n"
	.string "{COLOR RED}Chief{COLOR DARK_GRAY}! I'm done climbing the ladder!$"

RA_Player_Text_Gain_Badge8:
	.string "I got the {COLOR RED}Gold Ring{COLOR DARK_GRAY}, and carefully\n"
	.string "attached it to my {COLOR RED}Poké Pass{COLOR DARK_GRAY}.$"

RA_Player_Text_Explain_Badge8:
	.string "{COLOR BLUE}With the Gold Ring, all Pokémon\n"
	.string "{COLOR BLUE}will follow your commands.\p"
	.string "{COLOR BLUE}And, you can now take part in\n"
	.string "{COLOR BLUE}the Pokémon League!\p"
	.string "{COLOR BLUE}As for the Gold Ring itself...\p"
	.string "{COLOR BLUE}The gold was mined in Johto, and it\n"
	.string "{COLOR BLUE}looks right at home among the rainbow.{COLOR DARK_GRAY}$"

RA_Player_Gain_Rank::
	goto_if_set FLAG_BADGE00_GET, RA_Player_Gain_Rank1
	message RA_Player_Text_Gain_Rank0
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	return

RA_Player_Gain_PokePass::
	message RA_Player_Text_Gain_PokePass
	waitmessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	waitfanfare
	return

RA_Player_Gain_Badge::
	goto_if_set FLAG_BADGE00_GET, RA_Player_Gain_Badge1
	setvar VAR_0x8000, MUGSHOT_WHITEBAND
	callnative DrawMugshot
	message RA_Player_Text_Gain_Badge0
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RA_Player_Text_Explain_Badge0, MSGBOX_DEFAULT
	closemessage
	callnative ClearMugshot
	setflag FLAG_BADGE00_GET
	return

RA_Player_Gain_Rank1::
	goto_if_set FLAG_BADGE01_GET, RA_Player_Gain_Rank2
	message RA_Player_Text_Gain_Rank1
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	return

RA_Player_Gain_Badge1::
	goto_if_set FLAG_BADGE01_GET, RA_Player_Gain_Badge2
	setvar VAR_0x8000, MUGSHOT_REDGEM
	callnative DrawMugshot
	message RA_Player_Text_Gain_Badge1
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RA_Player_Text_Explain_Badge1, MSGBOX_DEFAULT
	closemessage
	callnative ClearMugshot
	setflag FLAG_BADGE01_GET
	return

RA_Player_Gain_Rank2::
	goto_if_set FLAG_BADGE02_GET, RA_Player_Gain_Rank3
	message RA_Player_Text_Gain_Rank2
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	return

RA_Player_Gain_Badge2::
	goto_if_set FLAG_BADGE02_GET, RA_Player_Gain_Badge3
	setvar VAR_0x8000, MUGSHOT_ORANGEGEM
	callnative DrawMugshot
	message RA_Player_Text_Gain_Badge2
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RA_Player_Text_Explain_Badge2, MSGBOX_DEFAULT
	closemessage
	callnative ClearMugshot
	setflag FLAG_BADGE02_GET
	return

RA_Player_Gain_Rank3::
	goto_if_set FLAG_BADGE03_GET, RA_Player_Gain_Rank4
	message RA_Player_Text_Gain_Rank3
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	return

RA_Player_Gain_Badge3::
	goto_if_set FLAG_BADGE03_GET, RA_Player_Gain_Badge4
	setvar VAR_0x8000, MUGSHOT_YELLOWGEM
	callnative DrawMugshot
	message RA_Player_Text_Gain_Badge3
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RA_Player_Text_Explain_Badge3, MSGBOX_DEFAULT
	closemessage
	callnative ClearMugshot
	setflag FLAG_BADGE03_GET
	return

RA_Player_Gain_Rank4::
	goto_if_set FLAG_BADGE04_GET, RA_Player_Gain_Rank5
	message RA_Player_Text_Gain_Rank4
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	return

RA_Player_Gain_Badge4::
	goto_if_set FLAG_BADGE04_GET, RA_Player_Gain_Badge5
	setvar VAR_0x8000, MUGSHOT_GREENGEM
	callnative DrawMugshot
	message RA_Player_Text_Gain_Badge4
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RA_Player_Text_Explain_Badge4, MSGBOX_DEFAULT
	closemessage
	callnative ClearMugshot
	setflag FLAG_BADGE04_GET
	return

RA_Player_Gain_Rank5::
	goto_if_set FLAG_BADGE05_GET, RA_Player_Gain_Rank6
	message RA_Player_Text_Gain_Rank5
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	return

RA_Player_Gain_Badge5::
	goto_if_set FLAG_BADGE05_GET, RA_Player_Gain_Badge6
	setvar VAR_0x8000, MUGSHOT_BLUEGEM
	callnative DrawMugshot
	message RA_Player_Text_Gain_Badge5
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RA_Player_Text_Explain_Badge5, MSGBOX_DEFAULT
	closemessage
	callnative ClearMugshot
	setflag FLAG_BADGE05_GET
	return

RA_Player_Gain_Rank6::
	goto_if_set FLAG_BADGE06_GET, RA_Player_Gain_Rank7
	message RA_Player_Text_Gain_Rank6
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	return

RA_Player_Gain_Badge6::
	goto_if_set FLAG_BADGE06_GET, RA_Player_Gain_Badge7
	setvar VAR_0x8000, MUGSHOT_INDIGOGEM
	callnative DrawMugshot
	message RA_Player_Text_Gain_Badge6
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RA_Player_Text_Explain_Badge6, MSGBOX_DEFAULT
	closemessage
	callnative ClearMugshot
	setflag FLAG_BADGE06_GET
	return

RA_Player_Gain_Rank7::
	goto_if_set FLAG_BADGE07_GET, RA_Player_Gain_Rank8
	message RA_Player_Text_Gain_Rank7
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	return

RA_Player_Gain_Badge7::
	goto_if_set FLAG_BADGE07_GET, RA_Player_Gain_Badge8
	setvar VAR_0x8000, MUGSHOT_VIOLETGEM
	callnative DrawMugshot
	message RA_Player_Text_Gain_Badge7
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RA_Player_Text_Explain_Badge7, MSGBOX_DEFAULT
	closemessage
	callnative ClearMugshot
	setflag FLAG_BADGE07_GET
	return

RA_Player_Gain_Rank8::
	message RA_Player_Text_Gain_Rank8
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	return

RA_Player_Gain_Badge8::
	setvar VAR_0x8000, MUGSHOT_GOLDRING
	callnative DrawMugshot
	message RA_Player_Text_Gain_Badge8
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RA_Player_Text_Explain_Badge8, MSGBOX_DEFAULT
	closemessage
	callnative ClearMugshot
	setflag FLAG_BADGE08_GET
	return

RA_Object1_SweatDrop::
	applymovement 1, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_SweatDrop_FaceUp::
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_SweatDrop_FaceRight::
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_SweatDrop_FaceDown::
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_SweatDrop_FaceLeft::
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Chatter::
	applymovement 1, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Chatter_FaceUp::
	applymovement 1, RA_FaceUp
	waitmovement 0
	applymovement 1, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Chatter_FaceRight::
	applymovement 1, RA_FaceRight
	waitmovement 0
	applymovement 1, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Chatter_FaceDown::
	applymovement 1, RA_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object1_Chatter_FaceLeft::
	applymovement 1, RA_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_SweatDrop::
	applymovement 2, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_SweatDrop_FaceUp::
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_SweatDrop_FaceRight::
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_SweatDrop_FaceDown::
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_SweatDrop_FaceLeft::
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Chatter::
	applymovement 2, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Chatter_FaceUp::
	applymovement 2, RA_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Chatter_FaceRight::
	applymovement 2, RA_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Chatter_FaceDown::
	applymovement 2, RA_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object2_Chatter_FaceLeft::
	applymovement 2, RA_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_SweatDrop::
	applymovement 3, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_SweatDrop_FaceUp::
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_SweatDrop_FaceRight::
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_SweatDrop_FaceDown::
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_SweatDrop_FaceLeft::
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Chatter::
	applymovement 3, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Chatter_FaceUp::
	applymovement 3, RA_FaceUp
	waitmovement 0
	applymovement 3, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Chatter_FaceRight::
	applymovement 3, RA_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Chatter_FaceDown::
	applymovement 3, RA_FaceDown
	waitmovement 0
	applymovement 3, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object3_Chatter_FaceLeft::
	applymovement 3, RA_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_SweatDrop::
	applymovement 4, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_SweatDrop_FaceUp::
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_SweatDrop_FaceRight::
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_SweatDrop_FaceDown::
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_SweatDrop_FaceLeft::
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Chatter::
	applymovement 4, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Chatter_FaceUp::
	applymovement 4, RA_FaceUp
	waitmovement 0
	applymovement 4, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Chatter_FaceRight::
	applymovement 4, RA_FaceRight
	waitmovement 0
	applymovement 4, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Chatter_FaceDown::
	applymovement 4, RA_FaceDown
	waitmovement 0
	applymovement 4, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object4_Chatter_FaceLeft::
	applymovement 4, RA_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_SweatDrop::
	applymovement 5, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_SweatDrop_FaceUp::
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_SweatDrop_FaceRight::
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_SweatDrop_FaceDown::
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_SweatDrop_FaceLeft::
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Chatter::
	applymovement 5, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Chatter_FaceUp::
	applymovement 5, RA_FaceUp
	waitmovement 0
	applymovement 5, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Chatter_FaceRight::
	applymovement 5, RA_FaceRight
	waitmovement 0
	applymovement 5, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Chatter_FaceDown::
	applymovement 5, RA_FaceDown
	waitmovement 0
	applymovement 5, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object5_Chatter_FaceLeft::
	applymovement 5, RA_FaceLeft
	waitmovement 0
	applymovement 5, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_SweatDrop::
	applymovement 6, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_SweatDrop_FaceUp::
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_SweatDrop_FaceRight::
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_SweatDrop_FaceDown::
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_SweatDrop_FaceLeft::
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Chatter::
	applymovement 6, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Chatter_FaceUp::
	applymovement 6, RA_FaceUp
	waitmovement 0
	applymovement 6, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Chatter_FaceRight::
	applymovement 6, RA_FaceRight
	waitmovement 0
	applymovement 6, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Chatter_FaceDown::
	applymovement 6, RA_FaceDown
	waitmovement 0
	applymovement 6, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object6_Chatter_FaceLeft::
	applymovement 6, RA_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	applymovement 6, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_SweatDrop::
	applymovement 7, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_SweatDrop_FaceUp::
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_SweatDrop_FaceRight::
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_SweatDrop_FaceDown::
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_SweatDrop_FaceLeft::
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Chatter::
	applymovement 7, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Chatter_FaceUp::
	applymovement 7, RA_FaceUp
	waitmovement 0
	applymovement 7, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Chatter_FaceRight::
	applymovement 7, RA_FaceRight
	waitmovement 0
	applymovement 7, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Chatter_FaceDown::
	applymovement 7, RA_FaceDown
	waitmovement 0
	applymovement 7, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object7_Chatter_FaceLeft::
	applymovement 7, RA_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_SweatDrop::
	applymovement 8, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_SweatDrop_FaceUp::
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_SweatDrop_FaceRight::
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_SweatDrop_FaceDown::
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_SweatDrop_FaceLeft::
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Chatter::
	applymovement 8, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Chatter_FaceUp::
	applymovement 8, RA_FaceUp
	waitmovement 0
	applymovement 8, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Chatter_FaceRight::
	applymovement 8, RA_FaceRight
	waitmovement 0
	applymovement 8, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Chatter_FaceDown::
	applymovement 8, RA_FaceDown
	waitmovement 0
	applymovement 8, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object8_Chatter_FaceLeft::
	applymovement 8, RA_FaceLeft
	waitmovement 0
	applymovement 8, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_SweatDrop::
	applymovement 9, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_SweatDrop_FaceUp::
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_SweatDrop_FaceRight::
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_SweatDrop_FaceDown::
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_SweatDrop_FaceLeft::
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Chatter::
	applymovement 9, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Chatter_FaceUp::
	applymovement 9, RA_FaceUp
	waitmovement 0
	applymovement 9, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Chatter_FaceRight::
	applymovement 9, RA_FaceRight
	waitmovement 0
	applymovement 9, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Chatter_FaceDown::
	applymovement 9, RA_FaceDown
	waitmovement 0
	applymovement 9, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object9_Chatter_FaceLeft::
	applymovement 9, RA_FaceLeft
	waitmovement 0
	applymovement 9, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_SweatDrop::
	applymovement 10, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_SweatDrop_FaceUp::
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_SweatDrop_FaceRight::
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_SweatDrop_FaceDown::
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_SweatDrop_FaceLeft::
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_SweatDrop
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Chatter::
	applymovement 10, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Chatter_FaceUp::
	applymovement 10, RA_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Chatter_FaceRight::
	applymovement 10, RA_FaceRight
	waitmovement 0
	applymovement 10, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Chatter_FaceDown::
	applymovement 10, RA_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Object10_Chatter_FaceLeft::
	applymovement 10, RA_FaceLeft
	waitmovement 0
	applymovement 10, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_SweatDrop::
	applymovement LOCALID_LOOKER, Common_Movement_SweatDrop
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_SweatDrop_FaceUp::
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_SweatDrop
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_SweatDrop_FaceRight::
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_SweatDrop
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_SweatDrop_FaceDown::
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_SweatDrop
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_SweatDrop_FaceLeft::
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_SweatDrop
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Chatter::
	applymovement LOCALID_LOOKER, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Chatter_FaceUp::
	applymovement LOCALID_LOOKER, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Chatter_FaceRight::
	applymovement LOCALID_LOOKER, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Chatter_FaceDown::
	applymovement LOCALID_LOOKER, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Looker_Chatter_FaceLeft::
	applymovement LOCALID_LOOKER, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_LOOKER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_SweatDrop::
	applymovement LOCALID_MAGNOLIA, Common_Movement_SweatDrop
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_SweatDrop_FaceUp::
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_SweatDrop
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_SweatDrop_FaceRight::
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_SweatDrop
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_SweatDrop_FaceDown::
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_SweatDrop
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_SweatDrop_FaceLeft::
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_SweatDrop
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Chatter::
	applymovement LOCALID_MAGNOLIA, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Chatter_FaceUp::
	applymovement LOCALID_MAGNOLIA, RA_FaceUp
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Chatter_FaceRight::
	applymovement LOCALID_MAGNOLIA, RA_FaceRight
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Chatter_FaceDown::
	applymovement LOCALID_MAGNOLIA, RA_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Magnolia_Chatter_FaceLeft::
	applymovement LOCALID_MAGNOLIA, RA_FaceLeft
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGNOLIA, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_SweatDrop::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_SweatDrop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_SweatDrop_FaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_SweatDrop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_SweatDrop_FaceRight::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_SweatDrop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_SweatDrop_FaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_SweatDrop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_SweatDrop_FaceLeft::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_SweatDrop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Chatter::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Chatter_FaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Chatter_FaceRight::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Chatter_FaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return

RA_Player_Chatter_FaceLeft::
	applymovement OBJ_EVENT_ID_PLAYER, RA_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ChatterChatter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	return
