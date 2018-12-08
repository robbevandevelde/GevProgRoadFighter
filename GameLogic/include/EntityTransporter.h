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
        /**
         * add an entity to the transporter
         * @param toAdd a shared pointer to an entity
         */
        void addEntity(std::shared_ptr<Entity> toAdd);

        /**
         * gets all the entities currently in the transporter
         * @return a vector of shard pointers to entities
         */
        std::vector<std::shared_ptr<Entity>>& getEntities();

        /**
         * removes all teh enities that are currently in the vector
         */
        void clear();

    private:
        std::vector<std::shared_ptr<Entity> > m_entities;
    };
}


#endif //GEVPROGROADFIGHTER_ENTITYTRANSPORTER_H
