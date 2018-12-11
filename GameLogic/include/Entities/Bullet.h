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

        /**
         * constructor by values
         * @param m_loc1 first gamelocation(upper left corner)
         * @param m_loc2 second gamelocation (upper right corner)
         * @param m_maxVertSpeed
         * @param m_vertAccel
         * @param m_horAccel
         */
        Bullet(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
               double m_horAccel);

        /**
         * copy assigment for Bullet
         * @param other the Bullet that is being copied
         * @return a new Bullet that is equal to the other one
         */
        Bullet& operator=(const Bullet& other)= default;

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
        ~Bullet() override = default;

        /**
         * this function handles what should happen must a object colldie with this bullet
         * here it means the object get shot
         * @param collided the object the bullet collides with
         */
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        /**
         * this function handles the crash of a bullet
         */
        void crash() override;

        /**
         * this function handles the shot logic of the bullet
         */
        void shot() override;

        /**
         * this function handles the bonus function of the bullet
         */
        void bonus() override;

        /**
         * this function handles the win condition of a bullet
         */
        void win() override;


    };
}


#endif //GEVPROGROADFIGHTER_BULLET_H
