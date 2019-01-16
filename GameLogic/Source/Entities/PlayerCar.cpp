#include <utility>

//
// Created by thibaut on 20.11.18.
//
#include <iostream>
#include <Entities/PlayerCar.h>
namespace roadfighter {

    /**
    * this function decreases the fuel by the given amount
    * @param amount
    * @return none
    * @exception GllException
    *
    */
    void PlayerCar::decreasFuel(const double &amount) {
        if(getStatus()!=Won) {
            m_fuel -= amount;
            if (m_fuel < 0) {
                m_fuel = 0;
            }
        }
        if(m_fuel<0){
            throw GllException("fuel of playercar dropped below 0");
        }
    }

    /**
     * this function updates the movement by dt ticks, it is also capable of changing the direction
     * @param dt the amount of a tick the car will move forward
     * @return none
     * @exception GllException
     */
    void PlayerCar::updateMovement(double dt) {
        //movement only updated when the car is driving
        if(getStatus()==Driving) {
            if (m_moveController->getNextHorMove() == h_left) {
                MovingObject::setHorizontalSpeed(-MovingObject::getHorAccel());
            } else if (m_moveController->getNextHorMove() == h_right) {
                MovingObject::setHorizontalSpeed(MovingObject::getHorAccel());
            } else if(m_moveController->getNextHorMove()==h_none){
                MovingObject::setHorizontalSpeed(0);
            }else{
                throw GllException("unknown horizontal move for playercar");
            }
            if (m_moveController->getNextVertMove() == v_accel) {
                //if the car is out of fuel it cant accelerate anymore
                if(m_fuel>0&&getVerticalSpeed()<getMaxVertSpeed()) {
                    MovingObject::setVerticalSpeed(MovingObject::getVerticalSpeed() + (MovingObject::getVertAccel() * dt));
                }
            } else if (m_moveController->getNextVertMove() == v_decel) {
                MovingObject::setVerticalSpeedUnbounded(MovingObject::getVerticalSpeed() - (MovingObject::getVertAccel() * dt));
                if (MovingObject::getVerticalSpeed() < 0) {
                    MovingObject::setVerticalSpeed(0);
                }
            } else if(m_moveController->getNextVertMove() != v_none){
                throw GllException("unknown vertical move for playercar");
            }
            if(m_moveController->mustShoot()){
                shoot();
            }
        }
        MovingObject::updateMovement(dt);
    }

    /**
    * this funtion updates the logic of the player car
     * @return none
     * @expception none
    */
    void PlayerCar::updateLogic() {
        MovingObject::updateLogic();
        decrementTimeOut();
        //if its driving and the timer is 0 then the immunity has run out
        if(isImmune()&&getTimeOut()==0&&getStatus()==Driving){
            setImmune(false);
        }
        //after the 30 ticks crash timer has run out set another one so you get a 30 tick immunty to get started again
        if(getStatus()==Crashed){
            if(getTimeOut()==0){
                setStatus(Driving);
                setTimeOut(90);
                setImmune(true);
            }
        }
        decreasefireCountdown();
        decreasFuel(0.1);
    }

    /**
    * constructor with arguments for playerCar
    * @param controller a shared pointer to the move controller the car will use
    * @param fuel the amount of fuel the car will use (default at 100)
     * @return none
     * @exception none
    */
    PlayerCar::PlayerCar(double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel,std::shared_ptr<InputController> controller, int fuel)
                         :m_moveController(std::move(controller)),m_fuel(fuel),m_fireCountdown(0),MovingObject(Location(-0.25,-0.25),Location(0.25,0.25),
                                 m_maxVertSpeed, m_vertAccel, m_horAccel) {}

    /**
     * constructor with all the arguments given
     * @param m_loc1 first location
     * @param m_loc2 second location
     * @param m_maxVertSpeed
     * @param m_vertAccel
     * @param m_horAccel
     * @param m_fuel amount of starting fuel
     * @param m_moveController the movecontroller that is used to see if any movement must be made
     * @param transporter enitty transporter that is used to transport bullet from the car to the world
     * @param factory an antity factory used to create bullets
     * @return none
     * @excpetion none
     */
    PlayerCar::PlayerCar(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
                         double m_horAccel, double m_fuel, const std::shared_ptr<InputController> &m_moveController,
                         const std::shared_ptr<EntityTransporter> & transporter,const std::shared_ptr<Entity_Factory_base>& factory)
            : MovingObject(m_loc1, m_loc2, m_maxVertSpeed, m_vertAccel, m_horAccel), m_fuel(m_fuel),
              m_moveController(m_moveController),m_transporter(transporter),m_factory(factory),m_fireCountdown(0) {}

    /**
     * this function well say wether the car can be deletet or not
     * @return playercar can never be deletet so it will always be false
     * @exception none
     */
    bool PlayerCar::mustDelete() const {
        return false;
    }

    /**
     * this function will handle the logic about what will happen if another object crashes into it
     * @param collided the object that crashes into the playercar
     * @return none
     * @exception none
     */
    void PlayerCar::collideWith(std::shared_ptr<CollisionObject> &collided) {
        collided->crash();
    }

    /**
    * this function says what will happen if the car crashes
     * @return none
     * @exception none
    */
    void PlayerCar::crash() {
        //when crashed the car will be immune and then it will wait for 30 logicticks
        //this immunity is so that when another car crashes into this one it wont reset the timer
        if(!isImmune()&&getStatus()==Driving) {
            stop();
            setStatus(Crashed);
            setTimeOut(90);
            decreasFuel(5);
            notify(-500);
        }
    }

    /**
     * this function says what will happen if the car gets shot
     * @return none
     * @exception none
     */
    void PlayerCar::shot() {
        if(!isImmune()) {
            stop();
        }
    }

    /**
    * this function says what will happen if the car gets a bonus
     * @return none
     * @exception none
    */
    void PlayerCar::bonus() {
        m_fuel+=10;
        setVerticalSpeedUnbounded(getVerticalSpeed()*1.2);
        notify(500);
    }

    /**
     * this function says what the car will do when it wins
     * @return none
     * @exception none
     */

    void PlayerCar::win() {
        if(getStatus()!=Won) {
            setStatus(Won);
            setMaxVertSpeed(0);
            setHorizontalSpeed(0);
            notify(5000);
            notify((int) (m_fuel * 100));
        }
    }

    /**
     * getter for the fual of the car
     * @return a double depicting the fuel
     * @exception none
     */
    double PlayerCar::getFuel() const {
        return m_fuel;
    }

    /**
     * this function decreases the fire countdown int that is used to see how many ticks till next possible shot
     * @return none
     * @excpetion none
     */
    void PlayerCar::decreasefireCountdown() {
        m_fireCountdown--;
        if(m_fireCountdown<0){
            m_fireCountdown=0;
        }

    }

    /**
     * this function shoots a bullet at the location of the car
     * @return none
     * @exception none
     */
    void PlayerCar::shoot() {
        if(m_factory== nullptr){
            throw GllException("tried accessing entity factory in playercar but none found");
        }
        if(m_transporter== nullptr){
            throw GllException("tried accessing entity transporter in car but none found");
        }
        if(m_fireCountdown==0){
            m_fireCountdown=15;
            std::shared_ptr<Entity> bullet= m_factory->createBullet((getLoc1().getX()+getLoc2().getX())/2,getLoc1().getY()-0.1,getVerticalSpeed()+0.5                       );
            m_transporter->addEntity(bullet);
        }
    }

}