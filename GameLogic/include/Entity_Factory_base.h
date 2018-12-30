/**
 *@file
 * a abstract class that should be overidden and is used to represent the abstract factory that is used to create all the entities
 */

#ifndef GEVPROGROADFIGHTER_ENTITY_FACTORY_H
#define GEVPROGROADFIGHTER_ENTITY_FACTORY_H

#include <memory>
#include "Entities/Entity.h"
#include "Observer/ScoreObserver.h"
#include "InputController.h"
#include "EntityTransporter.h"
#include "Observer/ObserverBase.h"

namespace roadfighter {
    class Entity_Factory_base: public std::enable_shared_from_this<Entity_Factory_base> {
//here are all the pure virual function that should always be overridden in each class inheriting from this one
    public:
        /**
       * base factory method for creating a bullet
       * @return a shared pointer to an Entity
       */
        virtual std::shared_ptr<Entity> createBullet(double x,double y,double vSpeed)=0;

        /**
         * base factory method for creating a PassingCar
         * @param x coordinate of the passing car (the middle)
         * @param y coordinate of the passing car (the middle)
         * @param vSpeed the set speed of the passingcar
         * @return a shared pointer to an entity
         */
        virtual std::shared_ptr<Entity> creatPassingCar(double x,double y,double vSpeed)=0;

        /**
         * base factory method for crating the player car
         * @param x xoordinate of the player car (the middle)
         * @param y coordinate of the player car (the middle)
         * @param max the max vertical speed
         * @param vAccel the vertical acceleration per tick
         * @param hAccel the horizontal acceleration per tick
         * @param fuel the starting fuel of the car
         * @return a shared pointer to an entity
         */
        virtual std::shared_ptr<Entity> createPlayerCar(double x,double y,double max,double vAccel,double hAccel,double fuel)=0;

        /**
        * base factory method for crating a racing car
        * @param x xoordinate of the racing car (the middle)
        * @param y coordinate of the racing car (the middle)
        * @param max the max vertical speed
        * @param vAccel the vertical acceleration per tick
        * @param hAccel the horizontal acceleration per tick
        * @return a shared pointer to an entity
        */
        virtual std::shared_ptr<Entity> createRacingCar(double x,double y,double max,double vAccel,double hAccel)=0;

        /**
          * base factory method for creating a BonusCar
          * @param x coordinate of the bonus car (the middle)
          * @param y coordinate of the passing bonus car (the middle)
          * @param vSpeed the set speed of the passingcar
          * @return a shared pointer to an entity
          */
        virtual std::shared_ptr<Entity> createBonusCar(double x,double y,double vSpeed)=0;

        /**
          * base factory method for creating a End
          * @param y coordinate of the end
          * @return a shared pointer to an entity
          */
        virtual std::shared_ptr<Entity> createEnd(double y)=0;

        /**
         * base factory method for creating the world
         * @return a shared pointer to an enityt
         */
        virtual std::shared_ptr<Entity> createWorld()=0;

        /**
         * virtual destructor
         */
        virtual ~Entity_Factory_base()= default;

        //here are a bunch of non virtual function that should keep the smae functionality over all classe that inherit form this one
    public:

        //constructor
        Entity_Factory_base();
        //setter for the movementcontroller
        void setController(const std::shared_ptr<InputController> &m_controller);

        //setter for the entity transporter
        void setTransporter(const std::shared_ptr<EntityTransporter> &m_Transporter);

        //getter for the controller
        const std::shared_ptr<InputController> &getController() const;

        //getter for the entity transporter
        const std::shared_ptr<EntityTransporter> &getTransporter() const;

        //getter for the score observer
        const std::shared_ptr<ObserverBase> &getScoreObserver() const;

        //setter for the score observer
        void setScoreObserver(const std::shared_ptr<ObserverBase> &m_scoreObserver);

    private:
        std::shared_ptr<InputController> m_controller;

        std::shared_ptr<EntityTransporter> m_Transporter;

        std::shared_ptr<ObserverBase> m_scoreObserver;
    };
}

#endif //GEVPROGROADFIGHTER_ENTITY_FACTORY_H
