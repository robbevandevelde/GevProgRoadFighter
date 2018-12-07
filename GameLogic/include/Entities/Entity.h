//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_ENTITY_H
#define GEVPROGROADFIGHTER_ENTITY_H

namespace roadfighter {
    class Entity {
        public:
            virtual void update(double dt)=0;

            virtual void draw()=0;

    };
}


#endif //GEVPROGROADFIGHTER_ENTITY_H
