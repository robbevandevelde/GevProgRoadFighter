//
// Created by thibaut on 20.11.18.
//

#include "../../include/Entities/Bullet.h"
namespace roadfighter {

    void Bullet::collideWith(std::shared_ptr<CollisionObject> &collided) {
        collided->shot();
    }

    void Bullet::crash() {
        setDelete(true);
    }

    void Bullet::shot() {
        setDelete(true);
    }

    void Bullet::bonus() {
        setDelete(true);
    }

    void Bullet::win() {
        setDelete(true);
    }

    Bullet::Bullet(const Location &m_loc1, const Location &m_loc2, double vertspeed) : MovingObject(m_loc1, m_loc2, vertspeed,0, 0) {
        setVerticalSpeed(vertspeed);
    }

    bool Bullet::mustDelete() const {
        return isDelete();
    }

    void Bullet::updateLogic() {
        if(getLoc1().getY()<-5){
            setDelete(true);
        }
    }

}