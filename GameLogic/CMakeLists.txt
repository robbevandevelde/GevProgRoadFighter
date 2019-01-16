cmake_minimum_required(VERSION 3.6)
set(LIB GLL)

#make a source variable conatining all the cpp files
SET(SRC
        Source/Entities/PlayerCar.cpp
        Source/Entities/MovingObject.cpp
        Source/Entities/PassingCar.cpp
        Source/Entities/RacingCar.cpp
        Source/Entities/Bullet.cpp
        Source/Entities/World.cpp
        Source/Entity_Factory_base.cpp
        Source/Location.cpp
        Source/Entities/CollisionObject.cpp
        Source/Observer/Observable.cpp
        Source/Observer/ScoreObserver.cpp
        Source/RoadFighterGame.cpp
        Utility/Random.cpp
        Utility/Clock.cpp
        Source/InputController.cpp
        Source/EntityTransporter.cpp
        Source/Entities/BonusCar.cpp
        Source/GLL_Entity_Factory.cpp
        Source/Entities/End.cpp
        include/parsers/json.hpp
        Source/HighScoreManager.cpp)


#Create a library named GameLogic containing all files of SRC that can be linked staticly
ADD_LIBRARY(${LIB}  ${SRC})

TARGET_INCLUDE_DIRECTORIES(${LIB} PUBLIC include)



