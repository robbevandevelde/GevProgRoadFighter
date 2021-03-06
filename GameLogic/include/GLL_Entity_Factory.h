/**
 * @file
 * this file contains a class derived from teh base entitie factory and will be teh default value if no abstract factory is given to the roadfighter game
 * this factory will be used to create all sorts of entities
 * @author Thibaut Van Goethem
 */

#ifndef GEVPROGROADFIGHTER_GLL_ENTITY_FACTORY_H
#define GEVPROGROADFIGHTER_GLL_ENTITY_FACTORY_H

#include <memory>
#include "Entity_Factory_base.h"
#include "Entities/EntityInclude.h"
namespace roadfighter {
    class GLL_Entity_Factory : public Entity_Factory_base{
    public:
        /**
         * default constructor
         */
        GLL_Entity_Factory()= default;

        //overridden function to create bullet
        std::shared_ptr<Entity> createBullet(double x,double y,double vSpeed) override;

        //overridden function to create passing car
        std::shared_ptr<Entity> creatPassingCar(double x,double y,double vSpeed) override;

       //overridden function to create player car
        std::shared_ptr<Entity> createPlayerCar(double x,double y,double max,double vAccel,double hAccel,double fuel) override;

        //overridden function to create racing car
        std::shared_ptr<Entity> createRacingCar(double x,double y,double max,double vAccel,double hAccel) override;

        //overridden function to create bonus car
        std::shared_ptr<Entity> createBonusCar(double x,double y,double vSpeed) override;

        //overridden function to create the gameworld
        std::shared_ptr<Entity> createWorld() override;

        //overridden function to create an end object
        std::shared_ptr<Entity> createEnd(double y) override;
    };
}


#endif //GEVPROGROADFIGHTER_GLL_ENTITY_FACTORY_H
