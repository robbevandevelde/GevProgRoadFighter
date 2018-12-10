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

    Bullet::Bullet(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
                   double m_horAccel) : MovingObject(m_loc1, m_loc2, m_maxVertSpeed, m_vertAccel, m_horAccel) {}

}