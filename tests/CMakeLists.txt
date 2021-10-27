add_executable( game_test 
	game_test.cpp
)

add_test(NAME Game_logic_test COMMAND $<TARGET_FILE:game_test>)


target_include_directories(JackOLector PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
