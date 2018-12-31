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
        std::shared_ptr<Bullet> toreturn = std::make_shared<Bullet>(roadfighter::Location(x - 0.05, y - 0.05),
                                                                            roadfighter::Location(x + 0.05, y + 0.05),
                                                                            vSpeed);
        return toreturn;
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
        std::shared_ptr<PassingCar> toreturn = std::make_shared<PassingCar>(roadfighter::Location(x - 0.25,
                                                                                                          y - 0.25),
                                                                                    roadfighter::Location(x + 0.25,
                                                                                                          y + 0.25),
                                                                                    vSpeed);
        toreturn->attach(getScoreObserver());
        return toreturn;
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
        std::shared_ptr<PlayerCar> toreturn = std::make_shared<PlayerCar>(
                roadfighter::Location(x - 0.25, y - 0.25), roadfighter::Location(x + 0.25, y + 0.25),
                max, vAccel, hAccel, fuel, getController(), getTransporter(), shared_from_this());
        toreturn->attach(getScoreObserver());
        return toreturn;
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
        std::shared_ptr<RacingCar> toreturn = std::make_shared<RacingCar>(
                roadfighter::Location(x - 0.25, y - 0.25), roadfighter::Location(x + 0.25, y + 0.25), max, vAccel,
                hAccel);
        toreturn->attach(getScoreObserver());
        return toreturn;
    }

    /**
    * an overrided factory method for creating the world
    * @return a shared pointer to an entity
     * @exception none
    */
    std::shared_ptr<Entity>  GLL_Entity_Factory::createWorld() {
        std::shared_ptr<World> toreturn = std::make_shared<World>(getTransporter());
        return toreturn;
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
        std::shared_ptr<BonusCar> toreturn = std::make_shared<BonusCar>(roadfighter::Location(x - 0.25,
                                                                                                              y - 0.25),
                                                                                roadfighter::Location(x + 0.25,
                                                                                                      y + 0.25),
                                                                                vSpeed);
        toreturn->attach(getScoreObserver());
        return toreturn;
    }

    /**
     * an overrided factory method to create an end object
     * @param y the y value of th eend object
     * @return a shared pointer to the end
     * @exception none
     */
    std::shared_ptr<Entity> GLL_Entity_Factory::createEnd(double y) {
        std::shared_ptr<End> toreturn = std::make_shared<End>(roadfighter::Location(-3, y - 0.5),
                                                                      roadfighter::Location(3, y + 0.5));
        return toreturn;
    }
}