//
// Created by thibaut on 20.11.18.
//

#include <Entities/Car.h>

#include "../../include/Entities/Car.h"
namespace roadfighter {
    Car::Car() {

    }

    Car::~Car() {

    }

    void Car::setVerticalSpeed(double m_VerticalSpeed) {
        Car::m_verticalSpeed = m_VerticalSpeed;
    }

    void Car::setHorizontalSpeed(double m_HorizontalSpeed) {
        Car::m_horizontalSpeed = m_HorizontalSpeed;
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

    void Car::accelerate() {
        m_verticalSpeed+=m_vertAccel;
        if(m_verticalSpeed>m_maxVertSpeed){
            m_verticalSpeed=m_maxVertSpeed;
        }
    }

    void Car::decelerate() {
        m_verticalSpeed-=m_vertAccel;
        if(m_verticalSpeed<0){
            m_verticalSpeed=0;
        }
    }


    void Car::update() {
        horMove(m_horizontalSpeed);
        m_horizontalSpeed=0;
        vertMove(m_verticalSpeed);

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

}