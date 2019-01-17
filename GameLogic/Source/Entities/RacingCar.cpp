/**
 * @file
 * this file contains the implementation of the RacingCar class
 * @author Thibaut Van Goethem
 */

#include "../../include/Entities/RacingCar.h"
namespace roadfighter {
    /**
     * constructor with all the variables given
     * @param m_loc1
     * @param m_loc2
     * @param m_maxVertSpeed maximum vertical speed
     * @param m_vertAccel vertical acceleration
     * @param m_horAccel horizontal acceleration
     * @return none
     * @exception none
     */
    RacingCar::RacingCar(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel) : MovingObject(m_loc1, m_loc2, m_maxVertSpeed, m_vertAccel, m_horAccel) {}

    /**
    * this function will update the position of the car by dt ticks
    * @param dt the amount of a tick the car will be moved forward
     *@return none
     * @exception none
    */
    void RacingCar::updateMovement(double dt){
        if(getStatus()==Driving) {
            MovingObject::accelerate(dt);
        }

        MovingObject::updateMovement(dt);
    }

    /**
    * this function will update the logic of the racing car
    * here it also can change the direction
     * @return none
     * @exception none
    */
    void RacingCar::updateLogic() {
        MovingObject::updateLogic();
        //in this function a random number from 0 to 2 will be generated to denote the next horizontal movement
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
            //if the car is crashed and the time is zero the car can drive again and gets a 90 tick immunity
            if(getStatus()==Crashed&& getTimeOut()==0){
                setStatus(Driving);
                setTimeOut(90);
                setImmune(true);
            }
        };
    }

    /*
     * this function denotes whether the car can be removed or not
     * @return it will always return false
     * @exception none
     */
    bool RacingCar::mustDelete() const {
        return false;
    }

    /**
     * this function handles what happens when another object collides with the playercar
     * @param collided the object that collides with the playercar
     * @return none
     * @idlexcept none
     */
    void RacingCar::collideWith(std::shared_ptr<CollisionObject> &collided) {
        collided->crash();
    }

    /**
     * this function will handle what happens when the car gets crashes
     * @return none
     * @exception none
     */
    void RacingCar::crash() {
        //if this car crashes the same happens as in theplayercar, immunity is set to true and a 30 tick timer starts
        if(!isImmune()&&getStatus()==Driving) {
            stop();
            setStatus(Crashed);
            setTimeOut(90);
        }
    }
    /**
     * this function will handle what happens when the car gets shot
     * @return none
     * @exception none
     */
    void RacingCar::shot() {
        if(!isImmune()) {
            stop();
            notify(200);
        }
    }
    /**
    * this function will handle what happens when the car gets a bonus
     * @return none
     * @exception none
    */
    void RacingCar::bonus() {
        setVerticalSpeedUnbounded(getVerticalSpeed()*1.2);
    }
    /**
     * this function will handle what happens when the car wins
     * @return none
     * @exception none
     */
    void RacingCar::win() {
        setStatus(Won);
        setMaxVertSpeed(0);
        setHorAccel(0);
        setHorizontalSpeed(0);
        notify(-1000);
    }


}