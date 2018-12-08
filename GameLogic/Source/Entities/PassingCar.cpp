//
// Created by thibaut on 20.11.18.
//

#include <Entities/PassingCar.h>

#include "../../include/Entities/PassingCar.h"
namespace roadfighter {

    void PassingCar::updateMovement(double dt) {
        Car::updateMovement(dt);
    }

    void PassingCar::updateLogic() {}

    PassingCar::PassingCar(const Location &m_loc1, const Location &m_loc2, double vertSpeed)
            : Car(m_loc1, m_loc2,vertSpeed , 0, 0) {
        Car::setVerticalSpeed(vertSpeed);
    }

    bool PassingCar::mustDelete() const {
        return getM_loc1().getY()>4;
    }

}