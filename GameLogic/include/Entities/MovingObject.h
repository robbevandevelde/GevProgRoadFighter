/**
 * @file
 * this file is the declaration of the class MovingObject and all it members
 * @author Thibaut Van Goethem
 */
#ifndef GEVPROGROADFIGHTER_CAR_H
#define GEVPROGROADFIGHTER_CAR_H

#include "Entity.h"
#include "CollisionObject.h"
#include "Observer/Observable.h"
enum EStatus{Driving,Crashed,Won};
namespace roadfighter {
    class MovingObject : public CollisionObject, public Observable {
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

        //constructor where all variables are given
        MovingObject(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
            double m_horAccel);

        /**
         * copy assigment for Car
         * @param other the Car that is being copied
         * @return a new Car that is equal to the other one
         */
        MovingObject& operator=(const MovingObject& other)= default;

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

        //stops all movement of this object
        virtual void stop();

        //accelerates the object by the vertaccel*dt
        virtual void accelerate(double dt);

        //setter for the vertical speed
        void setVerticalSpeed(double m_VerticalSpeed);

        //setter the vertical speed without the maximum vertical speed check
        void setVerticalSpeedUnbounded(double m_VerticalSpeed);

        //setter for the horizontal speed
        void setHorizontalSpeed(double HorizontalSpeed);

        //updates the movement
        void updateMovement(double dt) override;

        //getter for the horizontal speed
        double getHorizontalSpeed() const;

        //getter fot he vertical speed
        double getVerticalSpeed() const;

        //getter for the vertical acceleration
        double getVertAccel() const;

        //getter for the horizontal acceleration
        double getHorAccel() const;

        //gets the current status of this object (Driving/Crashed/Won)
        EStatus getStatus() const;

        //setter for the status
        void setStatus(EStatus m_status);

        //getter for the current timeOut of this object
        int getTimeOut() const;

        //setter for the timeOut
        void setTimeOut(int m_timeOut);

        //function that decrements the timeOut with 1
        void decrementTimeOut();



        //updates the logic of the object
        void updateLogic() override;

        //setter for the maximum speed
        void setMaxVertSpeed(double m_maxVertSpeed);

        //setter for the horizontal acceleration
        void setHorAccel(double m_horAccel);

        //setter for the vertical acceleration
        void setVertAccel(double m_vertAccel);

        //getter for the maximumspeed
        double getMaxVertSpeed() const;

    private:
        double m_verticalSpeed;
        double m_horizontalSpeed;

        double m_maxVertSpeed;

        double m_vertAccel;
        double m_horAccel;

        EStatus m_status;

        int m_timeOut;
    };
}


#endif //GEVPROGROADFIGHTER_CAR_H
