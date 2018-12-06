//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_CAR_H
#define GEVPROGROADFIGHTER_CAR_H

#include "Entity.h"
#include "CollisionObject.h"

namespace roadfighter {
    class Car : public CollisionObject {
    public:
        /**
         * default constructor for Car
         */
        Car();

        /**
         * copy constructor
         * @param copy the other Car that is being copied
         */
        Car(const Car &copy)= default;

        /**
         * move constructor
         * @param Move the other Car that is being moved in this one
         */
        Car(Car &&move)= default;

        Car(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
            double m_horAccel);

        /**
         * copy assigment for Car
         * @param other the Car that is being copied
         * @return a new Car that is equal to the other one
         */
        Car& operator=(Car& other)= default;

        /**
         * move assignment for Car
         * @param other other Car that is being moved
         * @return a Car
         * that contains all the data of the first one
         */
        Car& operator=(Car&& other)= default;


        /**
         * destructor for Car
         */
        virtual ~Car();

        virtual void stop();

        virtual void moveLeft();

        virtual void moveRight();

        virtual void accelerate();

        virtual void decelerate();

        void setVerticalSpeed(double m_VerticalSpeed);

        void setHorizontalSpeed(double m_HorizontalSpeed);

        void update() override;

        double getHorizontalSpeed() const;

        double getVertAccel() const;

        double getHorAccel() const;

    private:
        double m_verticalSpeed;
        double m_horizontalSpeed;

        double m_maxVertSpeed;

        double m_vertAccel;
        double m_horAccel;
    };
}


#endif //GEVPROGROADFIGHTER_CAR_H
