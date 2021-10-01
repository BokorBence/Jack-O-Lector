cmake_minimum_required(VERSION 3.7)

project(JackOLector)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})



add_executable(JackOLector 
	main.cpp
)

target_link_libraries(JackOLector ${SDL2_LIBRARIES})
target_include_directories(JackOLector PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

