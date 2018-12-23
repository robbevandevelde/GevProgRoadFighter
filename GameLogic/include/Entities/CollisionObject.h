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

        /**
         * a function that should be overriden and is used to denote wether an object should be deletet or not
         * @return a bool
         */
        virtual bool mustDelete() const;

        /**
         * getter for loc1
         * @return a gamelocation
         */
        const Location &getLoc1() const;

        /**
         * setter for loc1
         * @param m_loc1  a gamelocation
         */
        void setLoc1(const Location &m_loc1);

        /**
         * getter for loc2
         * @return  a gamelocation
         */
        const Location &getLoc2() const;

        /**
         * setter for loc2
         * @param m_loc2 a gamelocation
         */
        void setLoc2(const Location &m_loc2);

        /**
         * this function checks wether 2 collisionobjects collide
         * @param check the collsionobject you are cheking with
         * @return a bool that is true if they collide
         */
        bool checkCollision(std::shared_ptr<CollisionObject>& check) const ;

        /**
         * a function that must be overriden that will say what will happen to an objec tlust it collide with this one
         * @param collided the object this one collided with
         */
        virtual void collideWith(std::shared_ptr<CollisionObject>& collided)=0;

        /**
         * a function that must be overriden that will say what the object will do must it crash
         */
        virtual void crash()=0;

        /**
        * a function that must be overriden that will say what the object will do must it been shot
        */
        virtual void shot()=0;

        /**
        * a function that must be overriden that will say what the object will do must it get a bonus
        */
        virtual void bonus()=0;

        /**
        * a function that must be overriden that will say what the object will do must it win
        */
        virtual void win()=0;

        /**
         * getter for m_delete
         * @return a bool
         */
        bool isDelete() const;

        /**
         * setter for m_delete
         * @param m_delete a bool
         */
        void setDelete(bool m_delete);

        /**
         * this function moves the object forwar/backwar by "amount" space
         * @param amount the amount it is moving (negative is forward!!)
         */
        void vertMove(double amount);

        /**
         * this function moves the object sideways by "amount" space
         * @param amount the amount it is moving (negative is to the left)
         */
        void horMove(double amount);

        /**
         * this function calculates and returns the height of the object
         * @return a double
         */
        double getheight() const;

        /**
         * this function calculates and returns the width of the object
         * @return a double
         */
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
