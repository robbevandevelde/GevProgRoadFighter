//
// Created by thibaut on 20.11.18.
//

#include <Entities/PlayerCar.h>

#include "../../include/Entities/PlayerCar.h"
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

    void PlayerCar::update() {
        Car::update();
    }

    PlayerCar::PlayerCar(double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel) : Car(Location(-0.5,-0.5),Location(0.5,0.5), m_maxVertSpeed, m_vertAccel, m_horAccel) {
        m_fuel=100;
    }
}