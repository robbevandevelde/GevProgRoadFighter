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

        /**
         * constructor with arguments for playerCar
         * @param controller a shared pointer to the move controller the car will use
         * @param fuel the amount of fuel the car will use (default at 100)
         */
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

        /**
         * this function decreases the fuel by the given amount
         * @param amount
         */
        void decreasFuel(const double &amount);

        /**
         * this function increases the fuel by the given amount
         * @param amount
         */
        void increaseFuel(const double &amount);

        /**
         * this function updates the movement by dt ticks, it is also capable of changing the direction
         * @param dt the amount of a tick the car will move forward
         */
        void updateMovement(double dt) override;

        /**
         * this funtion updates the logic of the player car
         */
        void updateLogic() override;

        /**
         * this function well say wether the car can be deletet or not
         * @return playercar can never be deletet so it will always be false
         */
        bool mustDelete() const override;

        /**
         * this function says what the car will do when it wins
         */
        void win() override;

        /**
         * this function will handle the logic about what will happen if another object crashes into it
         * @param collided the object that crashes into the playercar
         */
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        /**
         * this function says what will happen if the car crashes
         */
        void crash() override;

        /**
         * this function says what will happen if the car gets shot
         */
        void shot() override;

        /**
         * this function says what will happen if the car gets a bonus
         */
        void bonus() override;

        /**
         * getter for the fual of the car
         * @return a double depicting the fuel
         */
        double getFuel() const;

        void decreasefireCountdown();

        void shoot();
    private:
        double m_fuel;

        int m_fireCountdown;

        std::shared_ptr<InputController> m_moveController;

        std::shared_ptr<EntityTransporter> m_transporter;

        std::shared_ptr<Entity_Factory_base> m_factory;

    };
}


#endif //GEVPROGROADFIGHTER_PLAYERCAR_H
