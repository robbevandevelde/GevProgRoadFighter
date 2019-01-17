/**
 * @file
 * this file contains the implementation of the end class
 * @author Thibaut Van Goethem
 */
#include "Entities/End.h"
namespace  roadfighter {
    /**
     * a function that will handle what will happen when an object collides with this one
     * @param collided the object it collides with
     * @return none
     * @exception none
     */
    void End::collideWith(std::shared_ptr<roadfighter::CollisionObject> &collided) {
        collided->win();
    }

    /**
    * this function updates the logic of the end object
    * it does nothing because there is no logic in the end object
     * @return none
     * @exception none
    */
    void End::updateLogic() {}

    /**
     * this function can update the movement of a collisionobject but as the end object doesnt move the function will do nothing
     * @param dt the amount of a tick this object will move forward with
     * @return none
     * @exception none
     */
    void End::updateMovement(double dt) {}

    /**
     * constructor for end where all the parameters are given
     * @param m_loc1 first location
     * @param m_loc2 second location
     * @return none
     * @exception none
     */
    End::End(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2) : CollisionObject(
            m_loc1, m_loc2) {}
}
