//
// Created by thibaut on 05.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H
#define GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H

#include <Entity_Factory_base.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include <Location.h>
#include <Entities/Entity.h>
#include "Entities/SFMLWorld.h"
#include "Entities/SFMLBullet.h"
#include "Entities/SFMLPlayerCar.h"
#include "Entities/SFMLRacingCar.h"
#include "Entities/SFMLBonusCar.h"
#include "Entities/SFMLPassingCar.h"
#include "Entities/SFMLEnd.h"

class SFML_Entity_Factory: public roadfighter::Entity_Factory_base {
public:
    SFML_Entity_Factory(const std::shared_ptr<sf::RenderWindow> &window);

    std::shared_ptr<roadfighter::Entity> createBullet(double x,double y,double vSpeed) override;

    std::shared_ptr<roadfighter::Entity> creatPassingCar(double x,double y,double vSpeedl) override;


    std::shared_ptr<roadfighter::Entity> createPlayerCar(double x,double y,double max,double vAccel,double hAccel,double fuel) override;

    std::shared_ptr<roadfighter::Entity> createRacingCar(double x,double y,double max,double vAccel,double hAccel) override;

    std::shared_ptr<roadfighter::Entity> createWorld() override;

    std::shared_ptr<roadfighter::Entity> createBonusCar(double x, double y, double vSpeed) override;

    std::shared_ptr<roadfighter::Entity> createEnd(double y) override;


private:
    std::shared_ptr<sf::RenderWindow> window;
};


#endif //GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H
