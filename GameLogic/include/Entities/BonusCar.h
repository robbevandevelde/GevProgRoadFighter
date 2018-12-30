#ifndef GEVPROGROADFIGHTER_BONUSCAR_H
#define GEVPROGROADFIGHTER_BONUSCAR_H

#include <Observer/Observable.h>
#include "MovingObject.h"

namespace roadfighter{
    class BonusCar: public MovingObject {
    public:

        /**
         * default constructor for BonusCar
         */
        BonusCar()= default;

        /**
         * constructor where location and speed is given
         * @param m_loc1 first location
         * @param m_loc2 second location
         * @param vertSpeed
         * @return none
         * @exception none
         */
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

        /**
         * updates the logic of the bonus car
         */
        void updateLogic() override;

        /**
         * updates the movement of the bonus car with dt ticks
         * @param dt the amount of a tick the car should move forward
         */
        void updateMovement(double dt) override;

        /**
         * a function that will return true if the car should be removed from the game
         * @return a bool
         */
        bool mustDelete()const override;

        /**
         * overidden function from collisionobject that handles what should happen must this car collide with another object
         * for the bonus car it means the the collided function gets the bonus function called on them
         * @param collided another object this car collided with
         */
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        /**
         * this function handles the crashing of the bonuscar
         */
        void crash() override;

        /**
         * this function handles the being shot of the bonuscar
         */
        void shot() override;

        /**
         * this function handles the bonus actions of this car
         */
        void bonus() override;

        /**
         * this function handles the win condition for this car
         */
        void win() override;


    };


}


#endif //GEVPROGROADFIGHTER_BONUSCAR_H
