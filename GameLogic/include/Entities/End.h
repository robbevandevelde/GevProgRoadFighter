#ifndef GEVPROGROADFIGHTER_END_H
#define GEVPROGROADFIGHTER_END_H

#include "CollisionObject.h"
namespace roadfighter {
    class End : public CollisionObject {
    public:

        /**
         * a function that will handle what will happen when an object collides with this one
         * @param collided the object it collides with
         */
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        /**
         * this function handles what will happen when this object crashes
         */
        void crash() override;

        /**
         * this function handles what will happen when this object gets shot
         */
        void shot() override;

        /**
         * this function handles what will happen when this object gets a bonus
         */
        void bonus() override;

        /**
         * this function updates the logic of the end object
         * nothing at the moment
         */
        void updateLogic() override;

        /**
         * this function can update the movement of a collisionobject but as the end object doesnt move the function will do nothing
         * @param dt the amount of a tick this objecct will move forward with
         */
        void updateMovement(double dt) override;

        /**
         * this function handles what will happen when this object wins
         */
        void win() override;

        /**
         * constructor by value
         * @param m_loc1
         * @param m_loc2
         */
        End(const Location &m_loc1, const Location &m_loc2);
    };
}


#endif //GEVPROGROADFIGHTER_END_H
