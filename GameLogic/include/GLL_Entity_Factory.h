//
// Created by thibaut on 05.12.18.
//

#ifndef GEVPROGROADFIGHTER_GLL_ENTITY_FACTORY_H
#define GEVPROGROADFIGHTER_GLL_ENTITY_FACTORY_H

#include <memory>
#include "Entity_Factory_base.h"
#include "Entities/Bullet.h"
#include "Entities/PlayerCar.h"
#include "Entities/RacingCar.h"
#include "Entities/World.h"
namespace roadfighter {
    class GLL_Entity_Factory : public Entity_Factory_base{
    public:
        GLL_Entity_Factory()= default;

        std::shared_ptr<Entity> createBullet() override;

        std::shared_ptr<Entity> creatPassingCar() override;

        std::shared_ptr<Entity> createPlayerCar() override;

        std::shared_ptr<Entity> createRacingCar() override;

        std::shared_ptr<Entity> createWorld() override;


    };
}


#endif //GEVPROGROADFIGHTER_GLL_ENTITY_FACTORY_H
