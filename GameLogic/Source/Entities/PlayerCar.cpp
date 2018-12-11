#include <utility>

//
// Created by thibaut on 20.11.18.
//

#include <Entities/PlayerCar.h>
#include <iostream>
namespace roadfighter {

    void PlayerCar::decreasFuel(const double &amount) {
        m_fuel-=amount;
        if(m_fuel<0){
            m_fuel=0;
        }
    }

    void PlayerCar::increaseFuel(const double &amount) {
        m_fuel+=amount;
    }

    void PlayerCar::updateMovement(double dt) {
        //movement only updatet when the car is driving
        if(getStatus()==Driving) {
            if (m_moveController->getNextHorMove() == h_left) {
                MovingObject::setHorizontalSpeed(-MovingObject::getHorAccel());
            } else if (m_moveController->getNextHorMove() == h_right) {
                MovingObject::setHorizontalSpeed(MovingObject::getHorAccel());
            } else {
                MovingObject::setHorizontalSpeed(0);
            }
            if (m_moveController->getNextVertMove() == v_accel) {
                MovingObject::setVerticalSpeed(MovingObject::getVerticalSpeed() + (MovingObject::getVertAccel() * dt));
            } else if (m_moveController->getNextVertMove() == v_decel) {
                MovingObject::setVerticalSpeed(MovingObject::getVerticalSpeed() - (MovingObject::getVertAccel() * dt));
                if (MovingObject::getVerticalSpeed() < 0) {
                    MovingObject::setVerticalSpeed(0);
                }
            }
        }
        MovingObject::updateMovement(dt);
    }

    void PlayerCar::updateLogic() {
        decrementTimeOut();
        //if its drivin and the timer is 0 then the immunity has run out
        if(isImmune()&&getTimeOut()==0&&getStatus()==Driving){
            setImmune(false);
        }
        //after the 30 ticks crash timer has run out set another one so you get a 30 tick immunty to get started again
        if(getStatus()==Crashed){
            if(getTimeOut()==0){
                setStatus(Driving);
                setTimeOut(30);
            }
        }
    }

    PlayerCar::PlayerCar(double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel,std::shared_ptr<MoveController> controller, int fuel)
                         :m_moveController(std::move(controller)),m_fuel(fuel),MovingObject(Location(-0.25,-0.25),Location(0.25,0.25),
                                 m_maxVertSpeed, m_vertAccel, m_horAccel) {}


    PlayerCar::PlayerCar(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel, double m_fuel, const std::shared_ptr<MoveController> &m_moveController)
            : MovingObject(m_loc1, m_loc2, m_maxVertSpeed, m_vertAccel, m_horAccel), m_fuel(m_fuel),
              m_moveController(m_moveController) {}

    bool PlayerCar::mustDelete() const {
        return false;
    }

    void PlayerCar::collideWith(std::shared_ptr<CollisionObject> &collided) {
        collided->crash();
    }

    void PlayerCar::crash() {
        //when crashed the car will be immune and then it will wait for 30 logicticks
        //this immunity is so that when another car crashes into this one it wont reset the timer
        if(!isImmune()) {
            setImmune(true);
            stop();
            setStatus(Crashed);
            setTimeOut(30);
        }
    }

    void PlayerCar::shot() {
        if(!isImmune()) {
            stop();
        }
    }

    void PlayerCar::bonus() {
        //todo
    }

    void PlayerCar::win() {
        setStatus(Won);
        stop();
    }
}