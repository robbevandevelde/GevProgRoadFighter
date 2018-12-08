//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_RACINGCAR_H
#define GEVPROGROADFIGHTER_RACINGCAR_H

#include "Car.h"
#include "../../Utility/Random.h"
namespace roadfighter {
    class RacingCar :public Car{
    public:
        /**
       * default constructor for RacingCar
       */
        RacingCar()= default;

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

        RacingCar(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
                  double m_horAccel);

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
        virtual ~RacingCar()= default;

        void updateMovement(double dt) override;

        void updateLogic() override;

    };
}


#endif //GEVPROGROADFIGHTER_RACINGCAR_H
