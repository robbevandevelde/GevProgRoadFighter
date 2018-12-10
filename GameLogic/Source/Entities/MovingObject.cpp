//
// Created by thibaut on 20.11.18.
//

#include <Entities/MovingObject.h>
#include <iostream>
#include "Entities/MovingObject.h"
namespace roadfighter {

    void MovingObject::setVerticalSpeed(double m_VerticalSpeed) {
        MovingObject::m_verticalSpeed = m_VerticalSpeed;
        if(m_VerticalSpeed>m_maxVertSpeed){
            MovingObject::m_verticalSpeed =m_maxVertSpeed;
        }
    }

    void MovingObject::setHorizontalSpeed(double HorizontalSpeed) {
        MovingObject::m_horizontalSpeed = HorizontalSpeed;
    }

    void MovingObject::moveLeft() {
        m_horizontalSpeed-=m_horAccel;
    }

    void MovingObject::stop() {
        m_verticalSpeed=0;
        m_horizontalSpeed=0;
    }


    void MovingObject::moveRight() {
        m_horizontalSpeed=m_horAccel;
    }

    void MovingObject::accelerate(double dt) {

        m_verticalSpeed+=m_vertAccel*dt;
        if(m_verticalSpeed>m_maxVertSpeed){
            m_verticalSpeed=m_maxVertSpeed;
        }
    }

    void MovingObject::decelerate(double dt) {
        m_verticalSpeed-=m_vertAccel*dt;
        if(m_verticalSpeed<0){
            m_verticalSpeed=0;
        }
    }


    void MovingObject::updateMovement(double dt) {
        horMove(m_horizontalSpeed*dt);
        vertMove(-m_verticalSpeed*dt);
    }

    double MovingObject::getVertAccel() const {
        return m_vertAccel;
    }

    double MovingObject::getHorAccel() const {
        return m_horAccel;
    }


    MovingObject::MovingObject(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
             double m_horAccel) : CollisionObject(m_loc1, m_loc2), m_maxVertSpeed(m_maxVertSpeed),
                                  m_vertAccel(m_vertAccel), m_horAccel(m_horAccel),m_status(Driving) {
        m_horizontalSpeed=0;
        m_verticalSpeed=0;
    }

    double MovingObject::getHorizontalSpeed() const {
        return m_horizontalSpeed;
    }

    double MovingObject::getVerticalSpeed() const {
        return m_verticalSpeed;
    }

    EStatus MovingObject::getStatus() const {
        return m_status;
    }

    void MovingObject::setStatus(EStatus m_status) {
        MovingObject::m_status = m_status;
    }

    int MovingObject::getTimeOut() const {
        return m_timeOut;
    }

    void MovingObject::setTimeOut(int m_timeOut) {
        MovingObject::m_timeOut = m_timeOut;
    }

    bool MovingObject::isImmune() const {
        return m_immune;
    }

    void MovingObject::setImmune(bool immune) {
        MovingObject::m_immune = immune;
    }

    void MovingObject::decrementTimeOut() {
        m_timeOut--;
        if(m_timeOut<0){
            m_timeOut=0;
        }
    }

}