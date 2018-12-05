//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_ENTITY_FACTORY_H
#define GEVPROGROADFIGHTER_ENTITY_FACTORY_H

#include <memory>
#include "Entities/Entity.h"

namespace roadfighter {
    class Entity_Factory_base {
    public:
        virtual Entity* createBullet()=0;

        virtual Entity* creatPassingCar()=0;

        virtual Entity* createPlayerCar()=0;

        virtual Entity* createRacingCar()=0;

        virtual Entity* createWorld()=0;

        virtual ~Entity_Factory_base();
    };
}

#endif //GEVPROGROADFIGHTER_ENTITY_FACTORY_H
