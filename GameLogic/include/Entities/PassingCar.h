//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_PASSINGCAR_H
#define GEVPROGROADFIGHTER_PASSINGCAR_H

#include "MovingObject.h"
namespace roadfighter {
    class PassingCar: public MovingObject {
    public:
        /**
         * default constructor for PassingCar
         */
        PassingCar()= default;

        PassingCar(const Location &m_loc1, const Location &m_loc2, double vertSpeed);

        /**
         * copy constructor
         * @param copy the other PassingCar that is being copied
         */
        PassingCar(const PassingCar &copy)= default;

        /**
         * move constructor
         * @param Move the other PassingCar that is being moved in this one
         */
        PassingCar(PassingCar &&move)= default;

        /**
         * copy assigment for PassingCar
         * @param other the PassingCar that is being copied
         * @return a new PassingCar that is equal to the other one
         */
        PassingCar& operator=(const PassingCar& other)= default;

        /**
         * move assignment for PassingCar
         * @param other other PassingCar that is being moved
         * @return a PassingCar
         * that contains all the data of the first one
         */
        PassingCar& operator=(PassingCar&& other)= default;

        /**
         * destructor for PassingCar
         */
        ~PassingCar() override = default;

        /**
         * update the logic of the passing car
         */
        void updateLogic() override;

        /**
         * update the movement of the passing car with dt ticks
         * @param dt the amount of a tick we need to move the car
         */
        void updateMovement(double dt) override;

        /**
         * a function that say whether the car needs to be removed from the game
         * @returna bool that is true if the car needs to be deletet
         */
        bool mustDelete() const override;

        /**
         * a function that will handle what will happen when a object collides with this one
         * @param collided the object this ones collides with
         */
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        /**
         * function that handles what happens when this car crashes
         */
        void crash() override;

        /**
         * function that handles what happens when this car get shot
         */
        void shot() override;

        /**
         * function that handles what happens when this car gets a bonus
         */
        void bonus() override;

        /**
         * function that handles what happens when this car wins
         */
        void win() override;
    };
}


#endif //GEVPROGROADFIGHTER_PASSINGCAR_H
