/**
 * @file header for the sfml_entity_factory class
 */


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
namespace roadfighterSFML {
    class SFML_Entity_Factory : public roadfighter::Entity_Factory_base {
    public:
        //constructor with only window parameter
        explicit SFML_Entity_Factory(const std::shared_ptr<sf::RenderWindow> &window);

        //function that creates an entity from a sfmlBullet, function is inherited from entity_factory_base
        std::shared_ptr<roadfighter::Entity> createBullet(double x, double y, double vSpeed) override;

        //function that creates an entity from a sfmlPassingCar, function is inherited from entity_factory_base
        std::shared_ptr<roadfighter::Entity> creatPassingCar(double x, double y, double vSpeedl) override;

        //function that creates an entity from a sfmlPlayerCar, function is inherited from entity_factory_base
        std::shared_ptr<roadfighter::Entity>
        createPlayerCar(double x, double y, double max, double vAccel, double hAccel, double fuel) override;

        //function that creates an entity from a sfmlracingCar, function is inherited from entity_factory_base
        std::shared_ptr<roadfighter::Entity>
        createRacingCar(double x, double y, double max, double vAccel, double hAccel) override;

        //function that creates an entity from a sfmlWorld, function is inherited from entity_factory_base
        std::shared_ptr<roadfighter::Entity> createWorld() override;

        //function that creates an entity from a sfmlBonusCar, function is inherited from entity_factory_base
        std::shared_ptr<roadfighter::Entity> createBonusCar(double x, double y, double vSpeed) override;

        //function that creates an entity from a sfmlend, function is inherited from entity_factory_base
        std::shared_ptr<roadfighter::Entity> createEnd(double y) override;


    private:
        std::shared_ptr<sf::RenderWindow> window;
    };
}


#endif //GEVPROGROADFIGHTER_SFML_ENTITY_FACTORY_H
