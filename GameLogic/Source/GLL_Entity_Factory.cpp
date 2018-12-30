//
// Created by thibaut on 05.12.18.
//

#include "GLL_Entity_Factory.h"
namespace roadfighter{

    /**
     * an overrided factory method for creating a bullet
     * @return a shared pointer to an Entity
     * @exception none
     */
    std::shared_ptr<Entity>  GLL_Entity_Factory::createBullet(double x,double y,double vSpeed) {
        return std::shared_ptr<Entity>(nullptr);
    }

    /**
     * an overrided factory method for creating a PassingCar
     * @param x coordinate of the passing car (the middle)
     * @param y coordinate of the passing car (the middle)
     * @param vSpeed the set speed of the passingcar
     * @return a shared pointer to an entity
     * @exception none
     */
    std::shared_ptr<Entity>  GLL_Entity_Factory::creatPassingCar(double x,double y,double vSpeed) {
        return nullptr;
    }
    /**
    * an overrided factory method for crating the player car
    * @param x xoordinate of the player car (the middle)
    * @param y coordinate of the player car (the middle)
    * @param max the max vertical speed
    * @param vAccel the vertical acceleration per tick
    * @param hAccel the horizontal acceleration per tick
    * @param fuel the starting fuel of the car
    * @return a shared pointer to an entity
     * @exception none
    */
    std::shared_ptr<Entity>  GLL_Entity_Factory::createPlayerCar(double x,double y,double max,double vAccel,double hAccel,double fuel) {
        return nullptr;
    }
    /**
    * an overrided factory method for crating a racing car
    * @param x xoordinate of the racing car (the middle)
    * @param y coordinate of the racing car (the middle)
    * @param max the max vertical speed
    * @param vAccel the vertical acceleration per tick
    * @param hAccel the horizontal acceleration per tick
    * @return a shared pointer to an entity
     * @exception none
    */
    std::shared_ptr<Entity>  GLL_Entity_Factory::createRacingCar(double x,double y,double max,double vAccel,double hAccel) {
        return nullptr;
    }

    /**
    * an overrided factory method for creating the world
    * @return a shared pointer to an entity
     * @exception none
    */
    std::shared_ptr<Entity>  GLL_Entity_Factory::createWorld() {
        return nullptr;
    }

    /**
      * an overrided factory method for creating a BonusCar
      * @param x coordinate of the bonus car (the middle)
      * @param y coordinate of the passing bonus car (the middle)
      * @param vSpeed the set speed of the passingcar
      * @return a shared pointer to an entity
      * @exception none
      */
    std::shared_ptr<Entity> GLL_Entity_Factory::createBonusCar(double x, double y, double vSpeed) {
        return std::shared_ptr<Entity>();
    }

    /**
     * an overrided factory method to create an end object
     * @param y the y value of th eend object
     * @return a shared pointer to the end
     * @exception none
     */
    std::shared_ptr<Entity> GLL_Entity_Factory::createEnd(double y) {
        return std::shared_ptr<Entity>();
    }
}