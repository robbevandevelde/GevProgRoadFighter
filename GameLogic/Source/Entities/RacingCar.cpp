//
// Created by thibaut on 20.11.18.
//

#include <Entities/RacingCar.h>
#include <iostream>

#include "../../include/Entities/RacingCar.h"
namespace roadfighter {
    RacingCar::RacingCar(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel) : MovingObject(m_loc1, m_loc2, m_maxVertSpeed, m_vertAccel, m_horAccel) {}

    void RacingCar::updateMovement(double dt){
        if(getStatus()==Driving) {
            MovingObject::accelerate(dt);
        }

        MovingObject::updateMovement(dt);
    }

    void RacingCar::updateLogic() {
        //in this function a random number from 0 to 2 willm4 be generated to denote the next horizontal movement
        decrementTimeOut();
        if(getStatus()==Driving) {
            if(isImmune()&&getTimeOut()==0){
                setImmune(false);
            }
            int rand = Random::getInstance().getRandom(9);
            switch (rand) {
                case 0:
                    MovingObject::setHorizontalSpeed(-MovingObject::getHorAccel());
                    break;

                case 1:
                    MovingObject::setHorizontalSpeed(0);
                    break;

                case 2:
                    MovingObject::setHorizontalSpeed(MovingObject::getHorAccel());
                    break;

                default:
                    break;
            }
        }else{
            //if the car is crashed and the time is zero the car can drive again and gets a 30 tick immunity
            if(getStatus()==Crashed&& getTimeOut()==0){
                setStatus(Driving);
                setTimeOut(30);
                setImmune(true);
            }
        };


    }

    bool RacingCar::mustDelete() const {
        return false;
    }

    void RacingCar::collideWith(std::shared_ptr<CollisionObject> &collided) {
        collided->crash();
    }

    void RacingCar::crash() {
        //if this car crashes the same happens as in theplayercar, immunity is set to true and a 30 tick timer starts
        if(!isImmune()) {
            stop();
            setStatus(Crashed);
            setImmune(true);
            setTimeOut(30);
        }
    }

    void RacingCar::shot() {
        if(!isImmune()) {
            stop();
        }
    }

    void RacingCar::bonus() {
        //todo
    }

    void RacingCar::win() {
        setStatus(Won);
        stop();
    }


}