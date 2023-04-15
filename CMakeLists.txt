cmake_minimum_required(VERSION 3.24)
project(ClassProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CURSES_INCLUDE_DIR})

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable(ClassProject main.cpp)
target_link_libraries(ClassProject sfml-graphics)
target_link_libraries(ClassProject sfml-audio)
target_link_libraries(ClassProject ${CURSES_LIBRARIES})
