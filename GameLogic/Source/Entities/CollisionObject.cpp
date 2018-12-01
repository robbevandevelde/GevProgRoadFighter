//
// Created by thibaut on 25.11.18.
//

#include <Entities/CollisionObject.h>

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


    CollisionObject::~CollisionObject() {}


    void CollisionObject::vertMove(double amount) {
        m_loc1.setY(m_loc1.getY()+amount);
        m_loc2.setY(m_loc2.getY()+amount);
    }

    void CollisionObject::horMove(double amount) {
        m_loc1.setX(m_loc1.getX()+amount);
        m_loc2.setX(m_loc2.getX()+amount);
        if(m_loc1.getX()<-3){
            double moveBack=-3-m_loc1.getX();
            m_loc1.setX(m_loc1.getX()+moveBack);
            m_loc2.setX(m_loc2.getX()+moveBack);
        }
        if(m_loc2.getX()>3){
            double moveBack=m_loc2.getX()-3;
            m_loc1.setX(m_loc1.getX()-moveBack);
            m_loc2.setX(m_loc2.getX()-moveBack);
        }
    }

}
