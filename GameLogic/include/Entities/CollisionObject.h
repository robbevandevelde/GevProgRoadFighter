//
// Created by thibaut on 25.11.18.
//

#ifndef GEVPROGROADFIGHTER_COLLISIONOBJECT_H
#define GEVPROGROADFIGHTER_COLLISIONOBJECT_H

#include "Entity.h"
#include <memory>
#include "../Location.h"

namespace  roadfighter {
    class CollisionObject: public Entity{
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

        virtual bool mustDelete() const;

        const Location &getLoc1() const;

        void setLoc1(const Location &m_loc1);

        const Location &getLoc2() const;

        void setLoc2(const Location &m_loc2);

        bool checkCollision(std::shared_ptr<CollisionObject>& check) const ;

        virtual void collideWith(std::shared_ptr<CollisionObject>& collided)=0;

        virtual void crash()=0;

        virtual void shot()=0;

        virtual void bonus()=0;

        virtual void win()=0;
        bool isDelete() const;

        void setDelete(bool m_delete);

        void vertMove(double amount);

        void horMove(double amount);

        double getheight() const;

        double getWidth() const;

        bool operator==(const CollisionObject &rhs) const;

        bool operator!=(const CollisionObject &rhs) const;


    private:
        Location m_loc1;
        Location m_loc2;

        bool m_delete;

    };
}


#endif //GEVPROGROADFIGHTER_COLLISIONOBJECT_H
