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
        /**
         * default constructor for CollisionObject
         */
        CollisionObject()=default;

        /**
         * a non default constructor for collsionObject where both postions are given
         * @param m_loc1 first location
         * @param m_loc2 second location
         */
        CollisionObject(const Location &m_loc1, const Location &m_loc2);

        /**
         * copy constructor
         * @param copy the other CollisionObject that is being copied
         */
        CollisionObject(const CollisionObject &copy)= default;

        /**
         * move constructor
         * @param Move the other CollisionObject that is being moved in this one
         */
        CollisionObject(CollisionObject &&move)= default;

        /**
         * copy assigment for CollisionObject
         * @param other the CollisionObject that is being copied
         * @return a new CollisionObject that is equal to the other one
         */
        CollisionObject& operator=(CollisionObject& other)= default;

        /**
         * move assignment for CollisionObject
         * @param other other CollisionObject that is being moved
         * @return a CollisionObject
         * that contains all the data of the first one
         */
        CollisionObject& operator=(CollisionObject&& other)= default;


        /**
         * destructor for CollisionObject
         */
        virtual ~CollisionObject();

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
