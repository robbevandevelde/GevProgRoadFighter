#setting cmake version and project name
cmake_minimum_required(VERSION 3.12)
project(GevProgRoadFighter)

set(CMAKE_CXX_STANDARD 14)
#extra compile flags to make srue code conventions are followed
#set(CMAKE_CXX_FLAGS "-Wall -Werror")

# run cmakelist in GameLogic
add_subdirectory(GameLogic)

#set include dir for gtest
include_directories(gtest/include)
# Set Library dir for gtest
link_directories(gtest/lib)

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC main.cpp
        Utility/Random.cpp
        Utility/Random.h Utility/Clock.cpp Utility/Clock.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(GevProgRoadFighter ${SRC})

#making a debug targer to link gtest to
SET(DEBUG_SRC main.cpp
        Utility/Random.cpp
        Utility/Random.h)

# adding a test executable to test he library
ADD_EXECUTABLE(GevProgRoadFighterTest ${DEBUG_SRC})

#linking ggl and gtest to debug targer
TARGET_LINK_LIBRARIES(GevProgRoadFighterTest  GLL)
TARGET_LINK_LIBRARIES(GevProgRoadFighterTest  gtest)


#Link the gamelogic library to main targer
TARGET_LINK_LIBRARIES(GevProgRoadFighter GLL)

## Link target to SFML libs
## (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(GevProgRoadFighter ${SFML_LIBRARIES})

#defining compile directory
INSTALL(TARGETS GevProgRoadFighter DESTINATION ${PROJECT_SOURCE_DIR}/bin)
