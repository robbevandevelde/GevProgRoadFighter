//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_CAR_H
#define GEVPROGROADFIGHTER_CAR_H

#include "Entity.h"
#include "CollisionObject.h"
enum EStatus{Driving,Crashed,Won};
namespace roadfighter {
    class MovingObject : public CollisionObject {
    public:
        /**
         * default constructor for Car
         */
        MovingObject()=default;

        /**
         * copy constructor
         * @param copy the other Car that is being copied
         */
        MovingObject(const MovingObject &copy)= default;

        /**
         * move constructor
         * @param Move the other Car that is being moved in this one
         */
        MovingObject(MovingObject &&move)= default;

        MovingObject(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
            double m_horAccel);

        /**
         * copy assigment for Car
         * @param other the Car that is being copied
         * @return a new Car that is equal to the other one
         */
        MovingObject& operator=(MovingObject& other)= default;

        /**
         * move assignment for Car
         * @param other other Car that is being moved
         * @return a Car
         * that contains all the data of the first one
         */
        MovingObject& operator=(MovingObject&& other)= default;


        /**
         * destructor for Car
         */
        ~MovingObject() override = default;

        /**
         * a function that sets the vertical and horizontal speed to 0
         */
        virtual void stop();

        /**
         * a function that substracts the horizontalaccel from the horizontalspeed
         */
        virtual void moveLeft();

        /**
         * a function that add the horizontalaccel from the horizontalspeed
         */
        virtual void moveRight();

        /**
         * a function that accelrates the car with the verticalaccel*dt
         * @param dt teh amount of a tick that has passed since previous one
         */
        virtual void accelerate(double dt);

        /**
        * a function that decelerates the car with the verticalaccel*dt
        * @param dt teh amount of a tick that has passed since previous one
        */
        virtual void decelerate(double dt);

        /**
         * setter for vertivalspeed
         * @param m_VerticalSpeed the new verticalspeed
         */
        void setVerticalSpeed(double m_VerticalSpeed);

        /**
         * setter for horizontalspeed
         * @param m_HorizontalSpeed the new horizontalspeed
         */
        void setHorizontalSpeed(double HorizontalSpeed);

        /**
         * a function that updates the car
         * @param dt the amount of ticks that have passed since the previous one
         * overrided form entity class
         */
        void updateMovement(double dt) override;

        double getHorizontalSpeed() const;

        double getVerticalSpeed() const;

        double getVertAccel() const;

        double getHorAccel() const;


        EStatus getStatus() const;

        void setStatus(EStatus m_status);

        int getTimeOut() const;

        void setTimeOut(int m_timeOut);

        void decrementTimeOut();

        bool isImmune() const;

        void setImmune(bool immune);

    private:
        double m_verticalSpeed;
        double m_horizontalSpeed;

        double m_maxVertSpeed;

        double m_vertAccel;
        double m_horAccel;

        bool m_immune;

        EStatus m_status;

        int m_timeOut;
    };
}


#endif //GEVPROGROADFIGHTER_CAR_H