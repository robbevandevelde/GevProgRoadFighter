#help for making c++ static library found at https://www.youtube.com/watch?v=vwt-qdJFMjM
cmake_minimum_required(VERSION 3.12)
project(GevProgRoadFighter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Werror")

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

#set the path of the gamelogiclibrary ro LOGIC_INCLUDE_DIR
#SET(LOGIC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/GameLogic)
#run cmakelist in GameLogic
add_subdirectory(GameLogic)
#include_directories(${LOGIC_INCLUDE_DIR})

## Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)
#
## The source files to compile
SET(SRC main.cpp)
#
## Add include dirs for SFML
## (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
#
## The program we're compiling with the sources set above
ADD_EXECUTABLE(GevProgRoadFighter ${SRC})

#
##Link the gamelogicLibrary adn make sure it is compiled before making linking to the target
#TARGET_LINK_LIBRARIES(GevProgRoadFighter GameLogic)
#ADD_DEPENDENCIES(GevProgRoadFighter GameLogic)

## Link target to SFML libs
## (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(GevProgRoadFighter ${SFML_LIBRARIES})
#
INSTALL(TARGETS GevProgRoadFighter DESTINATION ${PROJECT_SOURCE_DIR}/bin)
