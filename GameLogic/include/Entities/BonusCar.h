//
// Created by thibaut on 07.12.18.
//

#ifndef GEVPROGROADFIGHTER_BONUSCAR_H
#define GEVPROGROADFIGHTER_BONUSCAR_H

#include "Car.h"

namespace roadfighter{
    class BonusCar: public Car {
    public:

        /**
         * default constructor for BonusCar
         */
        BonusCar()= default;

        BonusCar(const Location &m_loc1, const Location &m_loc2, double vertSpeed);

        /**
         * copy constructor
         * @param copy the other BonusCar that is being copied
         */
        BonusCar(const BonusCar &copy)= default;

        /**
         * move constructor
         * @param Move the other BonusCar that is being moved in this one
         */
        BonusCar(BonusCar &&move)= default;

        /**
         * copy assigment for BonusCar
         * @param other the BonusCar that is being copied
         * @return a new BonusCar that is equal to the other one
         */
        BonusCar& operator=(BonusCar& other)= default;

        /**
         * move assignment for BonusCar
         * @param other other BonusCar that is being moved
         * @return a BonusCar
         * that contains all the data of the first one
         */
        BonusCar& operator=(BonusCar&& other)= default;

        /**
         * destructor for BonusCar
         */
        ~BonusCar() override = default;

        void updateLogic() override;

        void updateMovement(double dt) override;
    };
}


#endif //GEVPROGROADFIGHTER_BONUSCAR_H
