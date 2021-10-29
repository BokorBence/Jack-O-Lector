add_executable( game_test 
	game_test.cpp
	../src/guard.cpp
	../src/entity.cpp
	../src/walkingentity.cpp
	../src/game.cpp
)

add_test(NAME Game_logic_test COMMAND $<TARGET_FILE:game_test>)


target_include_directories(JackOLector PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
