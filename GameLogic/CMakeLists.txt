
set( LIB GLL)

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
ADD_LIBRARY(${LIB} STATIC ${SRC})



