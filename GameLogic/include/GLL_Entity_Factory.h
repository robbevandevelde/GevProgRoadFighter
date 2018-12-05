//
// Created by thibaut on 05.12.18.
//

#ifndef GEVPROGROADFIGHTER_GLL_ENTITY_FACTORY_H
#define GEVPROGROADFIGHTER_GLL_ENTITY_FACTORY_H

#include "Entity_Factory_base.h"
#include "Entities/Bullet.h"
#include "Entities/PlayerCar.h"
#include "Entities/RacingCar.h"
#include "Entities/World.h"
namespace roadfighter {
    class GLL_Entity_Factory : public Entity_Factory_base{
    public:
        Entity *createBullet() override;

        Entity *creatPassingCar() override;

        Entity *createPlayerCar() override;

        Entity *createRacingCar() override;

        Entity *createWorld() override;

    };
}


#endif //GEVPROGROADFIGHTER_GLL_ENTITY_FACTORY_H
