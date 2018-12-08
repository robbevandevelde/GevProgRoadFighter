//
// Created by thibaut on 07.12.18.
//

#include <Entities/BonusCar.h>

#include "Entities/BonusCar.h"
#include <iostream>
namespace roadfighter{

    void BonusCar::updateLogic() {}

    void BonusCar::updateMovement(double dt) {
        Car::updateMovement(dt);
    }

    BonusCar::BonusCar(const Location &m_loc1, const Location &m_loc2, double vertSpeed)
    : Car(m_loc1, m_loc2,100 , 0, 0) {
        Car::setVerticalSpeed(vertSpeed);
    }

    bool BonusCar::mustDelete() const {
        return getM_loc1().getY()>4;
    }
}