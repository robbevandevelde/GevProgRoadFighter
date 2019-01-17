/**
 * @file
 * this file contains the implementation of the Passingcar class
 * @author Thibaut Van Goethem
 */

#include "../../include/Entities/PassingCar.h"
namespace roadfighter {

    /**
    * update the movement of the passing car with dt ticks
    * @param dt the amount of a tick we need to move the car
     * @return none
     * @exception none
    */
    void PassingCar::updateMovement(double dt) {
        MovingObject::updateMovement(dt);
    }

    /**
    * update the logic of the passing car
     * ass this car only moves , there is no logic to be updated
     * @return none
     * @excpetion none
     */
    void PassingCar::updateLogic() {}

    /**
     * constructor with all the variables given
     * @param m_loc1 first location
     * @param m_loc2 second location
     * @param vertSpeed the vertical speed
     */
    PassingCar::PassingCar(const Location &m_loc1, const Location &m_loc2, double vertSpeed)
            : MovingObject(m_loc1, m_loc2,vertSpeed , 0, 0) {
        MovingObject::setVerticalSpeed(vertSpeed);
    }

    /**
    * a function that say whether the car needs to be removed from the game
    * @return a bool that is true if the car needs to be deleted
     * @exception none
    */
    bool PassingCar::mustDelete() const {
        if(!isDelete()) {
            return getLoc1().getY() > 4;
        }
        return true;
    }

    /**
    * a function that will handle what will happen when a object collides with this one
    * @param collided the object this ones collides with
     * @return none
     * @exception none
    */
    void PassingCar::collideWith(std::shared_ptr<CollisionObject> &collided) {
        collided->crash();

    }
    /**
    * function that handles what happens when this car crashes
     * @return none
     * @exception none
    */
    void PassingCar::crash() {
        setDelete(true);
    }

    /**
     * function that handles what happens when this car get shot
     * @return none
     * @excepetion
     */
    void PassingCar::shot() {
        setDelete(true);
        notify(100);
    }

    /**
    * function that handles what happens when this car gets a bonus
     * @return none
     * @exception none
    */
    void PassingCar::bonus() {
        setDelete(true);
    }

    /**
     * function that handles what happens when this car wins
     * @return none
     * @exception none
     */
    void PassingCar::win() {}

}