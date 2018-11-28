//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_CAR_H
#define GEVPROGROADFIGHTER_CAR_H

#include "Entity.h"
#include "CollisionObject.h"

namespace roadfighter {
    class Car : public CollisionObject,Entity {
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
    private:
        double m_VerticalSpeed;
        double m_HorizontalSpeed;
    };
}


#endif //GEVPROGROADFIGHTER_CAR_H
