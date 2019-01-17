/**
 * @file
 * this file contains the implementation of the CollisionObject class
 * @author Thibaut Van Goethem
 */

#include <Entities/CollisionObject.h>
namespace roadfighter {

    /**
     * getter for loc1
     * @return a gamelocation
     * @exception none
     */
    const Location &CollisionObject::getLoc1() const {
        return m_loc1;
    }

    /**
     * setter for loc1
     * @param m_loc1  a gamelocation
     * @return none
     * @exception none
     */
    void CollisionObject::setLoc1(const Location &m_loc1) {
        CollisionObject::m_loc1 = m_loc1;
    }

    /**
    * getter for loc2
    * @return  a gamelocation
     * @exception none
    */
    const Location &CollisionObject::getLoc2() const {
        return m_loc2;
    }

    /**
      * setter for loc2
      * @param m_loc2 a gamelocation
      * @return none
      * @exception none
      */
    void CollisionObject::setLoc2(const Location &m_loc2) {
        CollisionObject::m_loc2 = m_loc2;
    }

    /**
     * a non default constructor for collisionObject where both positions are given
     * @param m_loc1 first location
     * @param m_loc2 second location
     * @return none
     * @exception none
     */
    roadfighter::CollisionObject::CollisionObject(const Location &m_loc1, const Location &m_loc2) : m_loc1(m_loc1),
                                                                                                    m_loc2(m_loc2),m_delete(false) {}
    /**
     * this function checks whether 2 collisionobjects collide
     * @param check the collisionobject you are checking with
     * @return a bool that is true if they collide
     * @exception none
     */
    bool CollisionObject::checkCollision(std::shared_ptr<CollisionObject>& check) const {
    //efficient rectangle collision checker found at https://stackoverflow.com/questions/31022269/collision-detection-between-two-rectangles-in-java
    if(check->getLoc1().getX()<=getLoc2().getX()&&check->getLoc2().getX()>= getLoc1().getX()){
        if(check->getLoc1().getY()<=getLoc2().getY()&&check->getLoc2().getY()>=getLoc1().getY()){
            return true;
        }
    }
        return false;
    }

    /**
     * this function moves the object forward/backward by "amount" space
     * @param amount the amount it is moving (negative is forward!!)
     * @return none
     * @exception none
     */
    void CollisionObject::vertMove(double amount) {
        m_loc1.setY(m_loc1.getY()+amount);
        m_loc2.setY(m_loc2.getY()+amount);
    }

    /**
     * function that moves the collisionobject horizontaly
     * @param amount the amount it must forward/backward
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

    /**
     * this function calculates and returns the height of the object
     * @return a double
     * @exception none
     */
    double CollisionObject::getheight() const {
        return m_loc2.getY()-m_loc1.getY();
    }

    /**
     * this function calculates and returns the width of the object
     * @return a double
     * @exception none
     */
    double CollisionObject::getWidth() const {
        return m_loc2.getX()-m_loc1.getX();
    }

    /**
     * equality operator
     * @param rhs object you are comparing to
     * @return bool that says whether they are equal or not
     */
    bool CollisionObject::operator==(const CollisionObject &rhs) const {
        return m_loc1==rhs.m_loc1&&m_loc2==rhs.m_loc2;
    }


    /**
     * unequality operator
     * @param rhs object you are comparing to
     * @return bool that says whether they are not equal or equal
     */
    bool CollisionObject::operator!=(const CollisionObject &rhs) const {
        return !(rhs == *this);
    }

    /**
     * getter for m_delete
     * @return a bool
     * @exception none
     */
    bool CollisionObject::isDelete() const {
        return m_delete;
    }
    /**
     *
     * setter for m_delete
     * @param m_delete a bool
     * @return none
     * @exception none
     */
    void CollisionObject::setDelete(bool m_delete) {
        CollisionObject::m_delete = m_delete;
    }

    /**
     * a function that should be overriden and is used to denote whether an object should be deleted or not
     * @return a bool
     * @exception none
     */
    bool CollisionObject::mustDelete() const {
        return m_delete;
    }

    /**
     * a getter for the immunity of the object
     * @return a bool
     * @exception none
     */
    bool CollisionObject::isImmune() const {
        return m_immune;
    }

    /**
     * setter for the immunity of the object
     * @param immune a bool
     * @return none
     * @exception none
     */
    void CollisionObject::setImmune(bool immune) {
        CollisionObject::m_immune = immune;
    }

}
