/**
 * @file
 * this is an interface header that contains a class entity implemented by all world objects of the game logic library
 */
#ifndef GEVPROGROADFIGHTER_ENTITY_H
#define GEVPROGROADFIGHTER_ENTITY_H

#include "../GllException.h"
namespace roadfighter {
    class Entity {
        public:
            /**
             * virtual void function that should be used to update the logic of the entity
             */
            virtual void updateLogic()=0;

            /**
             * virtual void function that should be used to update the movement of the entity
             * @param dt
             */
            virtual void updateMovement(double dt)=0;

            /**
             * virtual void function that is used to draw the entity
             * this function is not overriden in the game logic itself and should be implemented by the creator of the graphics implementation
             * the reason this function is not pure virtual is to make it posible to simulate throught the game logic library without actually implementing it
             */
            virtual void draw(){};

    };
}


#endif //GEVPROGROADFIGHTER_ENTITY_H
