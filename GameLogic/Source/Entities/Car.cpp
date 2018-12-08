//
// Created by thibaut on 20.11.18.
//

#include <Entities/Car.h>
#include <iostream>
#include "../../include/Entities/Car.h"
namespace roadfighter {

    void Car::setVerticalSpeed(double m_VerticalSpeed) {
        Car::m_verticalSpeed = m_VerticalSpeed;
        if(m_VerticalSpeed>m_maxVertSpeed){
            Car::m_verticalSpeed =m_maxVertSpeed;
        }
    }

    void Car::setHorizontalSpeed(double HorizontalSpeed) {
        Car::m_horizontalSpeed = HorizontalSpeed;
    }

    void Car::moveLeft() {
        m_horizontalSpeed-=m_horAccel;
    }

    void Car::stop() {
        m_verticalSpeed=0;
        m_maxVertSpeed=0;
    }


    void Car::moveRight() {
        m_horizontalSpeed=m_horAccel;
    }

    void Car::accelerate(double dt) {

        m_verticalSpeed+=m_vertAccel*dt;
        if(m_verticalSpeed>m_maxVertSpeed){
            m_verticalSpeed=m_maxVertSpeed;
        }
    }

    void Car::decelerate(double dt) {
        m_verticalSpeed-=m_vertAccel*dt;
        if(m_verticalSpeed<0){
            m_verticalSpeed=0;
        }
    }


    void Car::updateMovement(double dt) {
        horMove(m_horizontalSpeed*dt);
        vertMove(-m_verticalSpeed*dt);
    }

    double Car::getVertAccel() const {
        return m_vertAccel;
    }

    double Car::getHorAccel() const {
        return m_horAccel;
    }


    Car::Car(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
             double m_horAccel) : CollisionObject(m_loc1, m_loc2), m_maxVertSpeed(m_maxVertSpeed),
                                  m_vertAccel(m_vertAccel), m_horAccel(m_horAccel) {
        m_horizontalSpeed=0;
        m_verticalSpeed=0;
    }

    double Car::getHorizontalSpeed() const {
        return m_horizontalSpeed;
    }

    double Car::getVerticalSpeed() const {
        return m_verticalSpeed;
    }

}