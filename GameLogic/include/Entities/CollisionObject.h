/**
 * @file
 * this file is the declaration of the class CollsionObject and all it members
 */
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
        CollisionObject& operator=(const CollisionObject& other)= default;

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
        virtual ~CollisionObject()= default;

        //function that says whether the objects must be removed or not
        virtual bool mustDelete() const;

        //getter for the first location
        const Location &getLoc1() const;

        //setter for the first location
        void setLoc1(const Location &m_loc1);

        //getter for the second location
        const Location &getLoc2() const;

        //setter for the second location
        void setLoc2(const Location &m_loc2);

        //checks the collision of this object with another
        bool checkCollision(std::shared_ptr<CollisionObject>& check) const ;

        /**
         * a function that can be overriden that will say what will happen to an objec tlust it collide with this one
         * @param collided the object this one collided with
         * it will do nothing by default
         */
        virtual void collideWith(std::shared_ptr<CollisionObject>& collided){};

        /**
         * a function that can be overriden that will say what the object will do must it crash
         * it will do nothing by default
         */
        virtual void crash(){};

        /**
        * a function that can be overriden that will say what the object will do must it been shot
         * it will do nothing by default
        */
        virtual void shot(){};

        /**
        * a function that can be overriden that will say what the object will do must it get a bonus
         * it will do nothing by default
        */
        virtual void bonus(){};

        /**
        * a function that can be overriden that will say what the object will do must it win
         * it will do nothing by default
        */
        virtual void win(){};

        //getter for the delete bool
        bool isDelete() const;

        //setter for the delete bool
        void setDelete(bool m_delete);

        //move the object bij "amount" vertically
        void vertMove(double amount);

        //move the object bij "amount" horizontally
        void horMove(double amount);

        //getter for the height
        double getheight() const;

        //getter for the width
        double getWidth() const;

        //equality operators
        bool operator==(const CollisionObject &rhs) const;

        bool operator!=(const CollisionObject &rhs) const;


    private:
        Location m_loc1;

        Location m_loc2;

        bool m_delete;

    };
}


#endif //GEVPROGROADFIGHTER_COLLISIONOBJECT_H
