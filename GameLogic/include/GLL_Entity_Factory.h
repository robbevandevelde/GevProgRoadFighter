/**
 * @file
 * this file contains a class derived from teh base antitie factory and will be teh default value if no abstract factory is given to the roadfighter game
 * this factory will be used to create all sorts of entities
 */

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
        /**
         * derault constructor
         */
        GLL_Entity_Factory()= default;

        /**
         * an overrided factory method for creating a bullet
         * @return a shared pointer to an Entity
         */
        std::shared_ptr<Entity> createBullet(double x,double y,double vSpeed) override;

        /**
         * an overrided factory method for creating a PassingCar
         * @param x coordinate of the passing car (the middle)
         * @param y coordinate of the passing car (the middle)
         * @param vSpeed the set speed of the passingcar
         * @return a shared pointer to an entity
         */
        std::shared_ptr<Entity> creatPassingCar(double x,double y,double vSpeed) override;

        /**
         * an overrided factory method for crating the player car
         * @param x xoordinate of the player car (the middle)
         * @param y coordinate of the player car (the middle)
         * @param max the max vertical speed
         * @param vAccel the vertical acceleration per tick
         * @param hAccel the horizontal acceleration per tick
         * @param fuel the starting fuel of the car
         * @return a shared pointer to an entity
         */
        std::shared_ptr<Entity> createPlayerCar(double x,double y,double max,double vAccel,double hAccel,double fuel) override;

        /**
        * an overrided factory method for crating a racing car
        * @param x xoordinate of the racing car (the middle)
        * @param y coordinate of the racing car (the middle)
        * @param max the max vertical speed
        * @param vAccel the vertical acceleration per tick
        * @param hAccel the horizontal acceleration per tick
        * @return a shared pointer to an entity
        */
        std::shared_ptr<Entity> createRacingCar(double x,double y,double max,double vAccel,double hAccel) override;

        /**
          * an overrided factory method for creating a BonusCar
          * @param x coordinate of the bonus car (the middle)
          * @param y coordinate of the passing bonus car (the middle)
          * @param vSpeed the set speed of the passingcar
          * @return a shared pointer to an entity
          */
        std::shared_ptr<Entity> createBonusCar(double x,double y,double vSpeed) override;

        /**
         * an overrided factory method for creating the world
         * @return a shared pointer to an entity
         */
        std::shared_ptr<Entity> createWorld() override;


        std::shared_ptr<Entity> createEnd(double y) override;
    };
}


#endif //GEVPROGROADFIGHTER_GLL_ENTITY_FACTORY_H
