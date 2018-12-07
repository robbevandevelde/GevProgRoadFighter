//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_ENTITY_FACTORY_H
#define GEVPROGROADFIGHTER_ENTITY_FACTORY_H

#include <memory>
#include "Entities/Entity.h"
#include "MoveController.h"
#include "EntityTransporter.h"

namespace roadfighter {
    class Entity_Factory_base {
    public:
        virtual std::shared_ptr<Entity> createBullet()=0;

        virtual std::shared_ptr<Entity> creatPassingCar()=0;

        virtual std::shared_ptr<Entity> createPlayerCar(double x,double y,double max,double vAccel,double hAccel,double fuel)=0;

        virtual std::shared_ptr<Entity> createRacingCar(double x,double y,double max,double vAccel,double hAccel)=0;

        virtual std::shared_ptr<Entity> createWorld()=0;

        virtual ~Entity_Factory_base();

        void setController(const std::shared_ptr<MoveController> &m_controller);

        void setTransporter(const std::shared_ptr<EntityTransporter> &m_Transporter);

        const std::shared_ptr<MoveController> &getController() const;

        const std::shared_ptr<EntityTransporter> &getTransporter() const;

    private:
        std::shared_ptr<MoveController> m_controller;

        std::shared_ptr<EntityTransporter> m_Transporter;
    };
}

#endif //GEVPROGROADFIGHTER_ENTITY_FACTORY_H
