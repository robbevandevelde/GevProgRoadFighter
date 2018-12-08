//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_PLAYERCAR_H
#define GEVPROGROADFIGHTER_PLAYERCAR_H

#include <memory>
#include "Car.h"
#include "MoveController.h"

namespace roadfighter {
    class PlayerCar:public Car {
    public:
        /**
       * default constructor for PlayerCar
       */
        PlayerCar();

        /**
         * constructor with arguments for playerCar
         * @param controller a shared pointer to the move controller the car will use
         * @param fuel the amount of fuel the car will use (default at 100)
         */
        PlayerCar(double m_maxVertSpeed, double m_vertAccel,
                  double m_horAccel,std::shared_ptr<MoveController> controller,int fuel=100);

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
                  double m_horAccel, double m_fuel, const std::shared_ptr<MoveController> &m_moveController);

        /**
         * copy assigment for PlayerCar
         * @param other the PlayerCar that is being copied
         * @return a new PlayerCar that is equal to the other one
         */
        PlayerCar& operator=(PlayerCar& other)= default;

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

        void decreasFuel(const double &amount);

        void increaseFuel(const double &amount);

        void updateMovement(double dt) override;

        void updateLogic() override;


    private:
        double m_fuel;

        std::shared_ptr<MoveController> m_moveController;

    };
}


#endif //GEVPROGROADFIGHTER_PLAYERCAR_H
