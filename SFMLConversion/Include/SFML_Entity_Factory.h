//
// Created by thibaut on 05.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H
#define GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H

#include <Entity_Factory_base.h>
#include <SFML/Graphics.hpp>
#include <memory>

class SFML_Entity_Factory:roadfighter::Entity_Factory_base {
    roadfighter::Entity *createBullet() override;

    roadfighter::Entity *creatPassingCar() override;

    roadfighter::Entity *createPlayerCar() override;

    roadfighter::Entity *createRacingCar() override;

    roadfighter::Entity *createWorld() override;

private:
    std::shared_ptr<sf::RenderWindow> window;
};


#endif //GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H
