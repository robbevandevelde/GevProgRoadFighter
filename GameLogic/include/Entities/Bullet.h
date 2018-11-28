//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_BULLET_H
#define GEVPROGROADFIGHTER_BULLET_H

#include "Entity.h"
#include "CollisionObject.h"

namespace roadfighter {
    class Bullet: public CollisionObject,Entity {
        /**
         * default constructor for Bullet
         */
        Bullet();

        /**
         * copy constructor
         * @param copy the other Bullet that is being copied
         */
        Bullet(const Bullet &copy)= default;

        /**
         * move constructor
         * @param Move the other Bullet that is being moved in this one
         */
        Bullet(Bullet &&move)= default;

        /**
         * copy assigment for Bullet
         * @param other the Bullet that is being copied
         * @return a new Bullet that is equal to the other one
         */
        Bullet& operator=(Bullet& other)= default;

        /**
         * move assignment for Bullet
         * @param other other Bullet that is being moved
         * @return a Bullet
         * that contains all the data of the first one
         */
        Bullet& operator=(Bullet&& other)= default;


        /**
         * destructor for Bullet
         */
        virtual ~Bullet();

    };
}


#endif //GEVPROGROADFIGHTER_BULLET_H
