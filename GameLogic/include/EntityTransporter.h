/**
 * @file
 * this file is for the entityTransporter that will regulate the exchange of entities between the game and the world
 */

#ifndef GEVPROGROADFIGHTER_ENTITYTRANSPORTER_H
#define GEVPROGROADFIGHTER_ENTITYTRANSPORTER_H

#include "Entities/Entity.h"
#include <memory>
#include <vector>
namespace roadfighter {
    class EntityTransporter {
    public:

        //function that adds an entity
        void addEntity(std::shared_ptr<Entity> toAdd);

        //function that gets all entities currently in the transporter
        std::vector<std::shared_ptr<Entity>>& getEntities();

        //function that removes all entities currently in the transporter
        void clear();

    private:
        std::vector<std::shared_ptr<Entity> > m_entities;
    };
}


#endif //GEVPROGROADFIGHTER_ENTITYTRANSPORTER_H
