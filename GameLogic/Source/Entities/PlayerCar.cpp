#include <utility>

//
// Created by thibaut on 20.11.18.
//

#include <Entities/PlayerCar.h>
#include <iostream>
namespace roadfighter {

    PlayerCar::PlayerCar() {}

    PlayerCar::~PlayerCar() {}

    void PlayerCar::decreasFuel(const double &amount) {
        m_fuel-=amount;
        if(m_fuel<0){
            m_fuel=0;
        }
    }

    void PlayerCar::increaseFuel(const double &amount) {
        m_fuel+=amount;
    }

    void PlayerCar::update(double dt) {
        if(m_moveController->getNextHorMove()==h_left){
            Car::setHorizontalSpeed(-Car::getHorAccel());
        }else if(m_moveController->getNextHorMove()==h_right){
            Car::setHorizontalSpeed(Car::getHorAccel());
        }else{
            Car::setHorizontalSpeed(0);
        }
        Car::update(dt);
    }

    PlayerCar::PlayerCar(double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel,std::shared_ptr<MoveController> controller, int fuel)
                         :m_moveController(std::move(controller)),m_fuel(fuel),Car(Location(-0.5,-0.5),Location(0.5,0.5),
                                 m_maxVertSpeed, m_vertAccel, m_horAccel) {}

}