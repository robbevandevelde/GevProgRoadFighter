/**
 * @file
 * this file is the declaration of the class Player Car and all it members
 * @author Thibaut Van Goethem
 */
#ifndef GEVPROGROADFIGHTER_PLAYERCAR_H
#define GEVPROGROADFIGHTER_PLAYERCAR_H

#include <memory>
#include <Observer/Observable.h>
#include "Entity_Factory_base.h"
#include "InputController.h"
#include "MovingObject.h"
#include "EntityTransporter.h"
namespace roadfighter {
    class PlayerCar:public MovingObject {
    public:
        /**
       * default constructor for PlayerCar
       */
        PlayerCar()= default;

        //constructor where all variables are given
        PlayerCar(double m_maxVertSpeed, double m_vertAccel,
                  double m_horAccel,std::shared_ptr<InputController> controller,int fuel=100);

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

        PlayerCar(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
                  double m_horAccel, double m_fuel, const std::shared_ptr<InputController> &m_moveController,
                  const std::shared_ptr<EntityTransporter> & transporter,const std::shared_ptr<Entity_Factory_base>& factory);

        /**
         * copy assigment for PlayerCar
         * @param other the PlayerCar that is being copied
         * @return a new PlayerCar that is equal to the other one
         */
        PlayerCar& operator=(const PlayerCar& other)= default;

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
        ~PlayerCar() override = default ;

        //decrease the fuel of this car with "amount"
        void decreaseFuel(const double &amount);

        //updates the position of this car with dt time, here is also checked if there is new input
        void updateMovement(double dt) override;

        //updates the logic of the car
        void updateLogic() override;

        //function that says if this car must be deleted (will always be false here)
        bool mustDelete() const override;

        //handles this car getting a win
        void win() override;

        //handles what happens if an object was tho collide with this one
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        //handles the crashing of this car
        void crash() override;

        //handles this car getting shot
        void shot() override;

        //handles this car getting a bonus
        void bonus() override;

        //getter for the fuel
        double getFuel() const;

        //decrease the firecoundown which says how many ticks need to pass till you can shoot again
        void decreasefireCountdown();

        //function that shoots if the firecountdown is 0
        void shoot();
    private:
        double m_fuel{};

        int m_fireCountdown{};

        std::shared_ptr<InputController> m_moveController;

        std::shared_ptr<EntityTransporter> m_transporter;

        std::shared_ptr<Entity_Factory_base> m_factory;

    };
}


#endif //GEVPROGROADFIGHTER_PLAYERCAR_H
