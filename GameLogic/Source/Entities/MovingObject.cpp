/**
 * @file
 * this file contains the implementation of the MovingObject class
 * @author Thibaut Van Goethem
 */

#include <Entities/MovingObject.h>

#include "Entities/MovingObject.h"
namespace roadfighter {

    /**
    * setter for verticalspeed
    * @param m_VerticalSpeed the new verticalspeed
     * @return none
     * @exception none
    */
    void MovingObject::setVerticalSpeed(double m_VerticalSpeed) {
        MovingObject::m_verticalSpeed = m_VerticalSpeed;
        if(m_VerticalSpeed>m_maxVertSpeed){
            MovingObject::m_verticalSpeed =m_maxVertSpeed;
        }
    }

    /**
     * setter for verticalspeed were there is no check if you are above the maxvertspeed
     * @param m_VerticalSpeed the new verticalspeed
     * @return none
     * @excpetion none
     */
    void MovingObject::setVerticalSpeedUnbounded(double m_VerticalSpeed) {
        MovingObject::m_verticalSpeed = m_VerticalSpeed;
    }

    /**
     * setter for horizontalspeed
     * @param m_HorizontalSpeed the new horizontalspeed
     * @return none
     * @exception none
     */
    void MovingObject::setHorizontalSpeed(double HorizontalSpeed) {
        MovingObject::m_horizontalSpeed = HorizontalSpeed;
    }

    /**
    * a function that sets the vertical and horizontal speed to 0
     * @return none
     * @exception none
    */
    void MovingObject::stop() {
        m_verticalSpeed=0;
        m_horizontalSpeed=0;
    }

    /**
     * a function that accelerates the car with the verticalaccel*dt
     * @param dt teh amount of a tick that has passed since previous one
     * @return none
     * @excpetion none
     */
    void MovingObject::accelerate(double dt) {
        m_verticalSpeed+=m_vertAccel*dt;
        //cannot accelerate when the max vertspeed is passed so check for that
        if(m_verticalSpeed>m_maxVertSpeed){
            m_verticalSpeed-=m_vertAccel*dt;
        }
    }

    /**
     * this function updates the logic of a movingobject
     * this only means that the verticalspeed gets changed according to the current acceleration
     * @return none
     * @exception none
     */
    void MovingObject::updateLogic() {
        if(m_verticalSpeed>m_maxVertSpeed){
            m_verticalSpeed=m_verticalSpeed-0.5*m_vertAccel;
            if(m_verticalSpeed<0){
                m_verticalSpeed=0;
            }
        }
    }

    /**
     * setter for the maxvertspeed
     * @param m_maxVertSpeed the new max speed
     * @return none
     * @excpetion none
     */
    void MovingObject::setMaxVertSpeed(double m_maxVertSpeed) {
        MovingObject::m_maxVertSpeed = m_maxVertSpeed;
    }

    /**
     * setter for the current horizontal acceleration
     * @param m_horAccel the new horizontal acceleration
     * @return none
     * @exception none
     *
     */
    void MovingObject::setHorAccel(double m_horAccel) {
        MovingObject::m_horAccel = m_horAccel;
    }


    /**
    * a function that updates the car
    * @param dt the amount of ticks that have passed since the previous one
    * overriden from entity class
     * @return none
     * @exception none
    */
    void MovingObject::updateMovement(double dt) {
        horMove(m_horizontalSpeed*dt);
        vertMove(-m_verticalSpeed*dt);
    }

    /**
     * getter for vertical acceleration
     * @return double
     * @exception none
     */
    double MovingObject::getVertAccel() const {
        return m_vertAccel;
    }

    /**
     * getter for horizontal acceleration
     * @return double
     * @exception none
     */
    double MovingObject::getHorAccel() const {
        return m_horAccel;
    }

    /**
     * constructor where all the parameters are given
     * @param m_loc1 first location
     * @param m_loc2 second location
     * @param m_maxVertSpeed
     * @param m_vertAccel
     * @param m_horAccel
     * @return none
     * @exception none
     */
    MovingObject::MovingObject(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
             double m_horAccel) : CollisionObject(m_loc1, m_loc2), m_maxVertSpeed(m_maxVertSpeed),
                                  m_vertAccel(m_vertAccel), m_horAccel(m_horAccel),m_status(Driving) {
        m_horizontalSpeed=0;
        m_verticalSpeed=0;
        m_status=Driving;
        m_timeOut=0;
        m_immune=false;
    }

    /**
     * getter for the current horizontalspeed
     * @return a double
     * @exception none
     */
    double MovingObject::getHorizontalSpeed() const {
        return m_horizontalSpeed;
    }

    /**
     * getter for current vertical speed
     * @return a double
     * @exception none
     */
    double MovingObject::getVerticalSpeed() const {
        return m_verticalSpeed;
    }

    /**
     * getter for the maximum vertical speed
     * @return the max vertical speed
     * @excpetion none
     */
    double MovingObject::getMaxVertSpeed() const {
        return m_maxVertSpeed;
    }

    /**
    * getter for current status of the moving object
    * @return an EStatus enum
     * @exception none
    */
    EStatus MovingObject::getStatus() const {
        return m_status;
    }

    /**
    * setter for the status
    * @param m_status an EStatus enum
     * @return none
     * @exception none
    */
    void MovingObject::setStatus(EStatus m_status) {
        MovingObject::m_status = m_status;
    }

    /**
     * getter for the current timeOut
     * @return an int
     * @exception none
     */
    int MovingObject::getTimeOut() const {
        return m_timeOut;
    }

    /**
     * setter for the timeout
     * @param m_timeOut an int
     * @return none
     * @exception none
     */
    void MovingObject::setTimeOut(int m_timeOut) {
        MovingObject::m_timeOut = m_timeOut;
    }

    /**
     * a getter for the immunity of the object
     * @return a bool
     * @exception none
     */
    bool MovingObject::isImmune() const {
        return m_immune;
    }

    /**
     * setter for the vertical acceleration
     * @param m_vertAccel the new vertical accelertaion
     * @return none
     * @exception none
     */
    void MovingObject::setVertAccel(double m_vertAccel) {
        MovingObject::m_vertAccel = m_vertAccel;
    }

    /**
     * setter for the immunity of the object
     * @param immune a bool
     * @return none
     * @exception none
     */
    void MovingObject::setImmune(bool immune) {
        MovingObject::m_immune = immune;
    }

    /**
     * a function that subtracts one of the timeout
     * @return none
     * @exception none
     */
    void MovingObject::decrementTimeOut() {
        m_timeOut--;
        if(m_timeOut<0){
            m_timeOut=0;
        }
    }

}