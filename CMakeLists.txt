cmake_minimum_required(VERSION 3.7)

project(JackOLector)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


add_executable(JackOLector 
	main.cpp
	src/button.cpp
	src/scene.cpp
	src/main_menu_scene.cpp
	src/level_select_menu_scene.cpp
	src/game.cpp
	src/entity.cpp
	src/walkingEntity.cpp
	src/guard.cpp
	src/wall.cpp
	src/tile.cpp
	src/level_1.cpp
	src/objective.cpp
	src/game_scene.cpp
	src/level.cpp
	src/game_over_scene.cpp
)

enable_testing()
add_subdirectory(tests)


target_link_libraries(JackOLector ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_include_directories(JackOLector PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

