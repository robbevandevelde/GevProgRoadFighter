//
// Created by thibaut on 20.11.18.
//

#include <Entities/RacingCar.h>
#include <iostream>

#include "../../include/Entities/RacingCar.h"
namespace roadfighter {
    RacingCar::RacingCar(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel) : Car(m_loc1, m_loc2, m_maxVertSpeed, m_vertAccel, m_horAccel) {}

    void RacingCar::updateMovement(double dt){
        Car::accelerate(dt);

        Car::updateMovement(dt);
    }

    void RacingCar::updateLogic() {
        int rand=Random::getInstance().getRandom(9);
        switch(rand){
            case 0:Car::setHorizontalSpeed(-Car::getHorAccel());
                break;

            case 1:Car::setHorizontalSpeed(0);
                break;

            case 2:Car::setHorizontalSpeed(Car::getHorAccel());
                break;

            default:
                break;
        }

    }

    bool RacingCar::mustDelete() const {
        return false;
    }


}