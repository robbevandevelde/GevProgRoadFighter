//
// Created by thibaut on 20.11.18.
//

#include <Entities/World.h>
#include <iostream>
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
        deleteUnused();
        getNewEntities();
        for(auto& i:m_roadEntities){
            i->updateLogic();
        }
        checkCollision();
    }

    void World::setBackY(double setback) {
        for(auto& i:m_roadEntities){
            auto temp=std::dynamic_pointer_cast<CollisionObject>(i);
            temp->vertMove(-setback);
        }
        m_tickMovement+=setback;
    }

    void World::addEntity(std::shared_ptr<Entity> obj) {
        m_roadEntities.push_back(obj);

    }

    void World::draw() {
        for(const auto& i:m_roadEntities){
            i->draw();
        }
        m_tickMovement=0;
    }

    void World::deleteUnused() {
        for(unsigned int i=0;i<m_roadEntities.size();i++){
            auto collision=std::dynamic_pointer_cast<CollisionObject>(m_roadEntities[i]);
            if(collision->mustDelete()){
                m_roadEntities.erase(m_roadEntities.begin()+i);
            }
        }

    }


    void World::checkCollision() {
        for(auto& i:m_roadEntities){
            std::shared_ptr<CollisionObject> checkFor=std::dynamic_pointer_cast<CollisionObject>(i);
            if(checkFor.get()!=NULL){
                for(auto& j:m_roadEntities){
                    std::shared_ptr<CollisionObject> checkWith=std::dynamic_pointer_cast<CollisionObject>(j);
                    if(checkWith.get()!=NULL&&*checkWith.get()!=*checkFor.get()){
                        if(checkFor->checkCollision(checkWith)){
                            checkFor->collideWith(checkWith);
                        }
                    }

                }
            }
        }
    }

    double World::getTickMovement() const {
        return m_tickMovement;
    }
}