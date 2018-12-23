
#ifndef GEVPROGROADFIGHTER_ENTITY_H
#define GEVPROGROADFIGHTER_ENTITY_H

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
             */
            virtual void draw()=0;

    };
}


#endif //GEVPROGROADFIGHTER_ENTITY_H
