//
// Created by thibaut on 05.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H
#define GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H

#include <Entity_Factory_base.h>

class SFML_Entity_Factory:roadfighter::Entity_Factory_base {
    roadfighter::Entity *createBullet() override;

    roadfighter::Entity *creatPassingCar() override;

    roadfighter::Entity *createPlayerCar() override;

    roadfighter::Entity *createRacingCar() override;

    roadfighter::Entity *createWorld() override;
};


#endif //GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H
