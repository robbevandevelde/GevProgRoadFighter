/**
 * @file
 * this file contains the implementation of the bonus car class
 * @author Thibaut Van Goethem
 */
#include "Entities/BonusCar.h"

namespace roadfighter{

    /**
     * updates the movement of the bonus car with dt ticks
     * @param dt the amount of a tick the car should move forward
     * @return none
     * @exception none
     */
    void BonusCar::updateMovement(double dt) {
        MovingObject::updateMovement(dt);
    }
    /**
    * constructor where location and speed is given
    * @param m_loc1 first location
    * @param m_loc2 second location
    * @param vertSpeed
    * @return none
    * @exception none
    */
    BonusCar::BonusCar(const Location &m_loc1, const Location &m_loc2, double vertSpeed)
    : MovingObject(m_loc1, m_loc2,vertSpeed , 0, 0) {
        MovingObject::setVerticalSpeed(vertSpeed);
    }

    /**
     * a function that will return true if the car should be removed from the game
     * @return a bool
     * @exception none
     */
    bool BonusCar::mustDelete() const {
        if(!isDelete()){
            return getLoc1().getY()>4;
        }
        return isDelete();

    }

    /**
     * overidden function from collisionobject that handles what should happen must this car collide with another object
     * for the bonus car it means the the collided function gets the bonus function called on them
     * @param collided another object this car collided with
     * @return none
     * @exception none
     */
    void BonusCar::collideWith(std::shared_ptr<CollisionObject> &collided) {
        collided->bonus();
    }

    /**
     * this function handles the crashing of the bonuscar
     * @return none
     * @exception none
     */
    void BonusCar::crash() {
        setDelete(true);
    }

    /**
    * this function handles the being shot of the bonuscar
     * @return none
     * @exception none
    */
    void BonusCar::shot() {
        setDelete(true);
        notify(-100);
    }

    /**
     * this function handles the bonus actions of this car
     * @return none
     * @exception none
     */
    void BonusCar::bonus() {
        setDelete(true);
    }

    /**
     * this function handles the win condition for this car
     * @return none
     * @exception none
     */
    void BonusCar::win() {}

    /**
     * updates the logic of the bonus car
     * @return none
     * @exception none
     */
    void BonusCar::updateLogic() {}
}