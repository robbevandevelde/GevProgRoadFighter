
cmake_minimum_required(VERSION 3.12)
set(LIB GLL)

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
        Source/Entity_Factory_base.cpp
        include/Entity_Factory_base.h
        Source/Location.cpp
        include/Location.h
        Source/Entities/CollisionObject.cpp
        include/Entities/CollisionObject.h
        Source/Observer/Observable.cpp
        include/Observer/Observable.h
        Source/Observer/ObserverBase.cpp
        include/Observer/ObserverBase.h
        Source/Observer/ScoreObserver.cpp
        include/Observer/ScoreObserver.h
        Source/RoadFighterGame.cpp
        include/RoadFighterGame.h
        Utility/Random.cpp
        Utility/Random.h
        Utility/Clock.cpp
        Utility/Clock.h ../Test/mainTest.cpp)


#Create a library named GameLogic containing all files of SRC that can be linked staticly
ADD_LIBRARY(${LIB}  ${SRC})

TARGET_INCLUDE_DIRECTORIES(${LIB} PUBLIC include)



