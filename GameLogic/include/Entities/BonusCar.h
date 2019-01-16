/**
 * @file
 * this file is the declaration of the class bonus car and all it members
 */
#ifndef GEVPROGROADFIGHTER_BONUSCAR_H
#define GEVPROGROADFIGHTER_BONUSCAR_H

#include <Observer/Observable.h>
#include "MovingObject.h"

namespace roadfighter{
    class BonusCar: public MovingObject {
    public:

        //default constructor
        BonusCar()= default;

        //constructor where all values are given
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
         * copy assignment for BonusCar
         * @param other the BonusCar that is being copied
         * @return a new BonusCar that is equal to the other one
         */
        BonusCar& operator=(const BonusCar& other)= default;

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

        // updates the logic of the bonus car
        void updateLogic() override;

        //updates the movement of the bonuscar
        void updateMovement(double dt) override;

        //says whether the car must be deleted or not
        bool mustDelete()const override;

        //handles the collision with this bonus car
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        //this function handles the crashing of the bonuscar
        void crash() override;

        //this function handles the being shot of the bonuscar
        void shot() override;

        //this function handles the bonus actions of this car
        void bonus() override;

        //this function handles the win condition for this car
        void win() override;


    };


}


#endif //GEVPROGROADFIGHTER_BONUSCAR_H
