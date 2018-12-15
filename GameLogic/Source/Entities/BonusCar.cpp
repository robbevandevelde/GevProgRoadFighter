//
// Created by thibaut on 07.12.18.
//

#include "Entities/BonusCar.h"

namespace roadfighter{

    void BonusCar::updateMovement(double dt) {
        MovingObject::updateMovement(dt);
    }

    BonusCar::BonusCar(const Location &m_loc1, const Location &m_loc2, double vertSpeed)
    : MovingObject(m_loc1, m_loc2,100 , 0, 0) {
        MovingObject::setVerticalSpeed(vertSpeed);
    }

    bool BonusCar::mustDelete() const {
        if(!isDelete()){
            return getLoc1().getY()>4;
        }
        return isDelete();

    }

    void BonusCar::collideWith(std::shared_ptr<CollisionObject> &collided) {
        collided->bonus();
    }

    void BonusCar::crash() {
        setDelete(true);
    }

    void BonusCar::shot() {
        setDelete(true);
    }

    void BonusCar::bonus() {
        setDelete(true);
    }

    void BonusCar::win() {}

    void BonusCar::updateLogic() {}
}