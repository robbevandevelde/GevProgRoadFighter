/**
 * @file
 * this file is the declaration of the class PassingCar and all it members
 * @author Thibaut Van Goethem
 */
#ifndef GEVPROGROADFIGHTER_PASSINGCAR_H
#define GEVPROGROADFIGHTER_PASSINGCAR_H

#include "MovingObject.h"
#include "Observer/Observable.h"
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

        //updates the logic of the car
        void updateLogic() override;

        //updates the movement of the car
        void updateMovement(double dt) override;

        //a function that says if this car must be deleted
        bool mustDelete() const override;

        //function that handles what happens if a car was to collide with this one
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        //handles the crashing of this car
        void crash() override;

        //function that handles everything when this car gets shot
        void shot() override;

        //handles this car getting a bonus
        void bonus() override;

        //handles this car getting a win
        void win() override;
    };
}


#endif //GEVPROGROADFIGHTER_PASSINGCAR_H
