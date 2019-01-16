//
// Created by thibaut on 20.11.18.
//

#include "../../include/Entities/Bullet.h"
namespace roadfighter {

    /**
     * this function handles what should happen must a object colldie with this bullet
     * here it means the object get shot
     * @param collided the object the bullet collides with
     * @return none
     * @exception none
     */
    void Bullet::collideWith(std::shared_ptr<CollisionObject> &collided) {
        collided->shot();
    }

    /**
     * this function handles the crash of a bullet
     * @return none
     * @exception none
     */
    void Bullet::crash() {
        setDelete(true);
    }

    /**
     * this function handles the shot logic of the bullet
     * @return none
     * @exception none
     */
    void Bullet::shot() {
        setDelete(true);
    }

    /**
     * this function handles the bonus function of the bullet
     * @return none
     * @exception none
     */
    void Bullet::bonus() {
        setDelete(true);
    }

    /**
     * this function handles the win condition of a bullet
     * @return none
     * @exception
     */
    void Bullet::win() {
        setDelete(true);
    }

    /**
     * cosntructor where all variables are given
     * @param m_loc1 first location
     * @param m_loc2 second location
     * @param vertspeed vertical speed
     * @return none
     * @exceeption none
     */
    Bullet::Bullet(const Location &m_loc1, const Location &m_loc2, double vertspeed) : MovingObject(m_loc1, m_loc2, vertspeed,0, 0) {
        setVerticalSpeed(vertspeed);
    }

    /**
     * overidden fucntion that denotes wether the bullet must be deletet or not
     * @return a bool
     * @exception none
     */
    bool Bullet::mustDelete() const {
        return isDelete();
    }

    /**
     * overidden function that updates the logic of the bullet
     * @return none
     * @exception none
     */
    void Bullet::updateLogic() {
        if(getLoc1().getY()<-5){
            setDelete(true);
        }
    }

}