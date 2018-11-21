cmake_minimum_required(VERSION 3.12)
#Set the name and version for the gamelogic library
project(RoadFighterLogicLib VERSION 1.0.0 DESCRIPTION "this is the logic library for a roadfighterGame")

set(CMAKE_CXX_STANDARD 14)
#extra flags to make sure code convetions are followed
set(CMAKE_CXX_FLAGS "-Wall -Werror")

#include all the headers that are found in the include directory
include_directories(include)

#make a source variable conatining all the cpp files
SET(SRC
        Source/Entities/Entity.cpp
        Source/Entities/PlayerCar.cpp
        Source/Entities/Car.cpp
        Source/Entities/PassingCar.cpp
        Source/Entities/RacingCar.cpp
        Source/Entities/Bullet.cpp
        Source/Entities/World.cpp
        Source/RoadFighterGame.cpp
        Source/Entity_Factory.cpp
        Source/Location.cpp include/Location.h)

#Create a library named GameLogic containing all files of SRC that can be linked staticly
ADD_LIBRARY(GameLogic STATIC ${SRC})



