//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_PASSINGCAR_H
#define GEVPROGROADFIGHTER_PASSINGCAR_H

#include "Car.h"
namespace roadfighter {
    class PassingCar: public Car {
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
        PassingCar& operator=(PassingCar& other)= default;

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

        void updateLogic() override;

        void updateMovement(double dt) override;

        bool mustDelete() const override;

    };
}


#endif //GEVPROGROADFIGHTER_PASSINGCAR_H
