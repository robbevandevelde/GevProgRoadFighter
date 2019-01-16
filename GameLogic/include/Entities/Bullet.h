/**
 * @file
 * this file is the declaration of the class Bullet car and all it members
 */
#ifndef GEVPROGROADFIGHTER_BULLET_H
#define GEVPROGROADFIGHTER_BULLET_H

#include "Entity.h"
#include "MovingObject.h"
#include "CollisionObject.h"

namespace roadfighter {
    class Bullet: public MovingObject{
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
        Bullet(const Location &m_loc1, const Location &m_loc2, double vertspeed);

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

        //function that handles what must happen if something collides with this bullet
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        //handles crashing of the bullet
        void crash() override;

        //handles the bullet getting shot
        void shot() override;

        //handles the bullet getting a bonus
        void bonus() override;

        //handles the bullet getting a win
        void win() override;

        //updates the logic of the bullet
        void updateLogic() override;

        //says wetehr the bullet msut be deletet or not
        bool mustDelete() const override;

    };
}


#endif //GEVPROGROADFIGHTER_BULLET_H
