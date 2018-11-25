//
// Created by thibaut on 25.11.18.
//

#ifndef GEVPROGROADFIGHTER_COLLISIONOBJECT_H
#define GEVPROGROADFIGHTER_COLLISIONOBJECT_H

#include "Entity.h"
#include "../Location.h"

namespace  roadfighter {
    class CollisionObject{
    public:
        CollisionObject()=default;

        CollisionObject(const Location &m_loc1, const Location &m_loc2);

        const Location &getM_loc1() const;

        void setM_loc1(const Location &m_loc1);

        const Location &getM_loc2() const;

        void setM_loc2(const Location &m_loc2);

        bool checkCollision(const CollisionObject& check) const ;



    private:
        Location m_loc1;
        Location m_loc2;

    };
}


#endif //GEVPROGROADFIGHTER_COLLISIONOBJECT_H
