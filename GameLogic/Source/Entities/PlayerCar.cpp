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
        if(m_moveController->getNextVertMove()==v_accel){
            Car::setVerticalSpeed(Car::getVerticalSpeed()+(Car::getVertAccel()*dt));
        }else if(m_moveController->getNextVertMove()==v_decel){
            Car::setVerticalSpeed(Car::getVerticalSpeed()-(Car::getVertAccel()*dt));
        }
        Car::update(dt);
    }

    PlayerCar::PlayerCar(double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel,std::shared_ptr<MoveController> controller, int fuel)
                         :m_moveController(std::move(controller)),m_fuel(fuel),Car(Location(-0.25,-0.25),Location(0.25,0.25),
                                 m_maxVertSpeed, m_vertAccel, m_horAccel) {}


    PlayerCar::PlayerCar(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel, double m_fuel, const std::shared_ptr<MoveController> &m_moveController)
            : Car(m_loc1, m_loc2, m_maxVertSpeed, m_vertAccel, m_horAccel), m_fuel(m_fuel),
              m_moveController(m_moveController) {}
}