//
// Created by thibaut on 20.11.18.
//

#include <Entities/World.h>

#include "../../include/Entities/World.h"
namespace roadfighter {

    World::World() {}

    World::~World() {

    }

    void World::update() {
        for(auto& i:m_roadEntities){
            i.get()->update();
        }
    }

    void World::setBackY(double setback) {
        for(auto& i:m_roadEntities){
            i->vertMove(-setback);
        }
    }

    void World::addEntity(std::shared_ptr<CollisionObject> obj) {
        m_roadEntities.push_back(obj);

    }

}