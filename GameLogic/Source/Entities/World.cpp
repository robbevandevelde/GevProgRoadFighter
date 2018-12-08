//
// Created by thibaut on 20.11.18.
//

#include <Entities/World.h>

#include "../../include/Entities/World.h"
namespace roadfighter {

    World::World() {}

    World::World(const std::shared_ptr<roadfighter::EntityTransporter> &m_Transporter) : m_Transporter(m_Transporter) {}


    World::~World() {

    }

    void World::getNewEntities() {
        for(auto i:m_Transporter->getEntities()){
            m_roadEntities.emplace_back(i);
        }
    }

    void World::updateMovement(double dt){
        for(auto& i:m_roadEntities){
            i->updateMovement(dt);
        }
    }

    void World::updateLogic() {
        getNewEntities();
        for(auto& i:m_roadEntities){
            i->updateLogic();
        }
    }

    void World::setBackY(double setback) {
        for(auto& i:m_roadEntities){
            auto temp=std::dynamic_pointer_cast<CollisionObject>(i);
            temp->vertMove(-setback);
        }
    }

    void World::addEntity(std::shared_ptr<Entity> obj) {
        m_roadEntities.push_back(obj);

    }

    void World::draw() {
        for(const auto& i:m_roadEntities){
            i->draw();
        }
    }

}