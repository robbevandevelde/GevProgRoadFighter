//
// Created by thibaut on 25.11.18.
//

#include <Entities/CollisionObject.h>
namespace roadfighter {

    const Location &CollisionObject::getLoc1() const {
        return m_loc1;
    }

    void CollisionObject::setLoc1(const Location &m_loc1) {
        CollisionObject::m_loc1 = m_loc1;
    }

    const Location &CollisionObject::getLoc2() const {
        return m_loc2;
    }

    void CollisionObject::setLoc2(const Location &m_loc2) {
        CollisionObject::m_loc2 = m_loc2;
    }


    roadfighter::CollisionObject::CollisionObject(const Location &m_loc1, const Location &m_loc2) : m_loc1(m_loc1),
                                                                                                    m_loc2(m_loc2),m_delete(false) {}

    bool CollisionObject::checkCollision(std::shared_ptr<CollisionObject>& check) const {
    //efficient rectangle collision checker found at https://stackoverflow.com/questions/31022269/collision-detection-between-two-rectangles-in-java
    if(check->getLoc1().getX()<=getLoc2().getX()&&check->getLoc2().getX()>= getLoc1().getX()){
        if(check->getLoc1().getY()<=getLoc2().getY()&&check->getLoc2().getY()>getLoc1().getY()){
            return true;
        }
    }
        return false;
    }


    void CollisionObject::vertMove(double amount) {
        m_loc1.setY(m_loc1.getY()+amount);
        m_loc2.setY(m_loc2.getY()+amount);
    }

    /**
     * function that moces the collisionobject horizonatly
     * @param amount the amount it must forwar/backward
     * @return none
     * @exception GllException
     */
    void CollisionObject::horMove(double amount) {
        //first add the amount then chack if the location does not exceed the -3 3 barrier
        m_loc1.setX(m_loc1.getX()+amount);
        m_loc2.setX(m_loc2.getX()+amount);
        if(m_loc1.getX()<-3){
            double moveBack=-3-m_loc1.getX();
            m_loc1.setX(m_loc1.getX()+moveBack);
            m_loc2.setX(m_loc2.getX()+moveBack);
        }
        if(m_loc2.getX()>3) {
            double moveBack = m_loc2.getX() - 3;
            m_loc1.setX(m_loc1.getX() - moveBack);
            m_loc2.setX(m_loc2.getX() - moveBack);
        }
        if(m_loc1.getX()<-3||m_loc2.getX()>3){
            throw GllException("error happened at horizontal move of a collisionobject, after movement the object was out of bounds");
        }
    }


    double CollisionObject::getheight() const {
        return m_loc2.getY()-m_loc1.getY();
    }

    double CollisionObject::getWidth() const {
        return m_loc2.getX()-m_loc1.getX();
    }

    bool CollisionObject::operator==(const CollisionObject &rhs) const {
        return m_loc1==rhs.m_loc1&&m_loc2==rhs.m_loc2;
    }

    bool CollisionObject::operator!=(const CollisionObject &rhs) const {
        return !(rhs == *this);
    }

    bool CollisionObject::isDelete() const {
        return m_delete;
    }

    void CollisionObject::setDelete(bool m_delete) {
        CollisionObject::m_delete = m_delete;
    }

    bool CollisionObject::mustDelete() const {
        return m_delete;
    }

}
