//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_RACINGCAR_H
#define GEVPROGROADFIGHTER_RACINGCAR_H

#include "MovingObject.h"
#include "../../Utility/Random.h"
namespace roadfighter {
    class RacingCar :public MovingObject{
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
        RacingCar& operator=(const RacingCar& other)= default;

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
        ~RacingCar() override = default;

        /**
         * this function will update the postion of the car by dt ticks
         * @param dt the amount of a tick the car will be moved forwar
         */
        void updateMovement(double dt) override;

        /**
         * this function will update the logic of the racing car
         * here it also can cahnge the direction
         */
        void updateLogic() override;

        /*
         * this function denotes whether the car can be removed or not
         */
        bool mustDelete() const override;

        /**
         * this function will handle what happens when the car wins
         */
        void win() override;

        /**
         * this function handles what happens when another object collides with the playercar
         * @param collided the object that collides with the playercar
         */
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        /**
         * this function will handle what happens when the car gets crashes
         */
        void crash() override;

        /**
         * this function will handle what happens when the car gets shot
         */
        void shot() override;

        /**
         * this function will handle what happens when the car gets a bonus
         */
        void bonus() override;
    };
}


#endif //GEVPROGROADFIGHTER_RACINGCAR_H
