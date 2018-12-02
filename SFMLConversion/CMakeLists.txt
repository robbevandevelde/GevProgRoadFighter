#setting cmake version and project name
cmake_minimum_required(VERSION 3.12)
project(GevProgRoadFighter)

set(CMAKE_CXX_STANDARD 14)
#extra compile flags to make srue code conventions are followed
#set(CMAKE_CXX_FLAGS "-Wall -Werror")

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/../cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC main.cpp
        Source/SFMLRoadFighter.cpp
        Include/SFMLRoadFighter.h Source/entities/SFMLPlayerCar.cpp Include/Entities/SFMLPlayerCar.h Source/entities/SFMLEntity.cpp Include/Entities/SFMLEntity.h Source/Transformation.cpp Include/Transformation.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(GevProgRoadFighter ${SRC})

#Link the gamelogic library to main targer
TARGET_LINK_LIBRARIES(GevProgRoadFighter LINK_PUBLIC GLL ${SFML_LIBRARIES})

## Link target to SFML libs
## (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
#TARGET_LINK_LIBRARIES(GevProgRoadFighter  ${SFML_LIBRARIES})

#defining compile directory
INSTALL(TARGETS GevProgRoadFighter DESTINATION ${PROJECT_SOURCE_DIR}/bin)
