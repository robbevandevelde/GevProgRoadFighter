//
// Created by thibaut on 20.11.18.
//

#include "../../include/Entities/PassingCar.h"
namespace roadfighter {

    void PassingCar::updateMovement(double dt) {
        MovingObject::updateMovement(dt);
    }

    void PassingCar::updateLogic() {}

    PassingCar::PassingCar(const Location &m_loc1, const Location &m_loc2, double vertSpeed)
            : MovingObject(m_loc1, m_loc2,vertSpeed , 0, 0) {
        MovingObject::setVerticalSpeed(vertSpeed);
    }

    bool PassingCar::mustDelete() const {
        if(!isDelete()) {
            return getLoc1().getY() > 4;
        }
        return true;
    }

    void PassingCar::collideWith(std::shared_ptr<CollisionObject> &collided) {
        collided->crash();

    }

    void PassingCar::crash() {
        setDelete(true);
    }

    void PassingCar::shot() {
        setDelete(true);
    }

    void PassingCar::bonus() {
        setDelete(true);
    }

    void PassingCar::win() {}

}