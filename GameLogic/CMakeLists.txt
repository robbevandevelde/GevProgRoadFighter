
cmake_minimum_required(VERSION 3.12)
set( LIB GLL)

#make a source variable conatining all the cpp files
SET(SRC
        Source/Entities/Entity.cpp
        include/Entities/Entity.h
        Source/Entities/PlayerCar.cpp
        include/Entities/PlayerCar.h
        Source/Entities/Car.cpp
        include/Entities/Car.h
        Source/Entities/PassingCar.cpp
        include/Entities/PassingCar.h
        Source/Entities/RacingCar.cpp
        include/Entities/RacingCar.h
        Source/Entities/Bullet.cpp
        include/Entities/Bullet.h
        Source/Entities/World.cpp
        include/Entities/World.h
        Source/RoadFighterGame.cpp
        include/RoadFighterGame.h
        Source/Entity_Factory.cpp
        include/Entity_Factory.h
        Source/Location.cpp
        include/Location.h
        Source/Entities/CollisionObject.cpp
        include/Entities/CollisionObject.h)

#Create a library named GameLogic containing all files of SRC that can be linked staticly
ADD_LIBRARY(${LIB} STATIC ${SRC})



