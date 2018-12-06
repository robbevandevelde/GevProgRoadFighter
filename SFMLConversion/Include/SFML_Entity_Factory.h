//
// Created by thibaut on 05.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H
#define GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H

#include <Entity_Factory_base.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include <Entities/Entity.h>
#include "Entities/SFMLWorld.h"
#include "Entities/SFMLPlayerCar.h"

class SFML_Entity_Factory: public roadfighter::Entity_Factory_base {
public:
    SFML_Entity_Factory(const std::shared_ptr<sf::RenderWindow> &window);

    std::shared_ptr<roadfighter::Entity> createBullet() override;

    std::shared_ptr<roadfighter::Entity> creatPassingCar() override;

    std::shared_ptr<roadfighter::Entity> createPlayerCar() override;

    std::shared_ptr<roadfighter::Entity> createRacingCar() override;

    std::shared_ptr<roadfighter::Entity> createWorld() override;



private:
    std::shared_ptr<sf::RenderWindow> window;
};


#endif //GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H
