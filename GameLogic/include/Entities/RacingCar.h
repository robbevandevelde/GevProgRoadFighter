//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_RACINGCAR_H
#define GEVPROGROADFIGHTER_RACINGCAR_H

#include "Car.h"
namespace roadfighter {
    class RacingCar :public Car{
        /**
       * default constructor for RacingCar
       */
        RacingCar();

        /**
         * copy constructor
         * @param copy the other RacingCar that is being copied
         */
        RacingCar(const RacingCar &copy)= default;

        /**
         * move constructor
         * @param Move the other RacingCar that is being moved in this one
         */
        RacingCar(RacingCar &&move)= default;

        /**
         * copy assigment for RacingCar
         * @param other the RacingCar that is being copied
         * @return a new RacingCar that is equal to the other one
         */
        RacingCar& operator=(RacingCar& other)= default;

        /**
         * move assignment for RacingCar
         * @param other other RacingCar that is being moved
         * @return a RacingCar
         * that contains all the data of the first one
         */
        RacingCar& operator=(RacingCar&& other)= default;


        /**
         * destructor for RacingCar
         */
        virtual ~RacingCar();

    };
}


#endif //GEVPROGROADFIGHTER_RACINGCAR_H
