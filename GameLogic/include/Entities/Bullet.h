//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_BULLET_H
#define GEVPROGROADFIGHTER_BULLET_H

#include "Entity.h"
#include "MovingObject.h"
#include "CollisionObject.h"

namespace roadfighter {
    class Bullet: public MovingObject,public Entity {
    public:
        /**
         * default constructor for Bullet
         */
        Bullet()= default;

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

        Bullet(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
               double m_horAccel);

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
        virtual ~Bullet()= default;

        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        void crash() override;

        void shot() override;

        void bonus() override;

        void win() override;


    };
}


#endif //GEVPROGROADFIGHTER_BULLET_H
