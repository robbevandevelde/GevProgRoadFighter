//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_PLAYERCAR_H
#define GEVPROGROADFIGHTER_PLAYERCAR_H

#include "Car.h"

namespace roadfighter {
    class PlayerCar:public Car {
        /**
       * default constructor for PlayerCar
       */
        PlayerCar();

        /**
         * copy constructor
         * @param copy the other PlayerCar that is being copied
         */
        PlayerCar(const PlayerCar &copy)= default;

        /**
         * move constructor
         * @param Move the other PlayerCar that is being moved in this one
         */
        PlayerCar(PlayerCar &&move)= default;

        /**
         * copy assigment for PlayerCar
         * @param other the PlayerCar that is being copied
         * @return a new PlayerCar that is equal to the other one
         */
        PlayerCar& operator=(PlayerCar& other)= default;

        /**
         * move assignment for PlayerCar
         * @param other other PlayerCar that is being moved
         * @return a PlayerCar
         * that contains all the data of the first one
         */
        PlayerCar& operator=(PlayerCar&& other)= default;


        /**
         * destructor for PlayerCar
         */
        virtual ~PlayerCar();
    };
}


#endif //GEVPROGROADFIGHTER_PLAYERCAR_H
