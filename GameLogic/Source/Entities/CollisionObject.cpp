//
// Created by thibaut on 25.11.18.
//

#include "../../include/Entities/CollisionObject.h"
namespace roadfighter {

    const Location &CollisionObject::getM_loc1() const {
        return m_loc1;
    }

    void CollisionObject::setM_loc1(const Location &m_loc1) {
        CollisionObject::m_loc1 = m_loc1;
    }

    const Location &CollisionObject::getM_loc2() const {
        return m_loc2;
    }

    void CollisionObject::setM_loc2(const Location &m_loc2) {
        CollisionObject::m_loc2 = m_loc2;
    }


    roadfighter::CollisionObject::CollisionObject(const Location &m_loc1, const Location &m_loc2) : m_loc1(m_loc1),
                                                                                                    m_loc2(m_loc2) {}

    bool CollisionObject::checkCollision(const CollisionObject &check) const {
        //TODO
        return false;
    }



}
