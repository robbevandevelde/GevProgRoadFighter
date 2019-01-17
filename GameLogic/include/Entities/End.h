/**
 * @file
 * this file is the declaration of the class End and all it members
 * @author Thibaut Van Goethem
 */
#ifndef GEVPROGROADFIGHTER_END_H
#define GEVPROGROADFIGHTER_END_H

#include "CollisionObject.h"
namespace roadfighter {
    class End : public CollisionObject {
    public:

        //function that handles what happens must an object collide with this one
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        //updates the logic of the end object
        void updateLogic() override;

        //updates the movement of this end object
        void updateMovement(double dt) override;

        //constructor where all the values are given
        End(const Location &m_loc1, const Location &m_loc2);
    };
}


#endif //GEVPROGROADFIGHTER_END_H
