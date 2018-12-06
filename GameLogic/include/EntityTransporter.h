//
// Created by thibaut on 06.12.18.
//

#ifndef GEVPROGROADFIGHTER_ENTITYTRANSPORTER_H
#define GEVPROGROADFIGHTER_ENTITYTRANSPORTER_H

#include "Entities/Entity.h"
#include <memory>
#include <vector>
namespace roadfighter {
    class EntityTransporter {
    public:
        void addEntity(std::shared_ptr<Entity> toAdd);

        std::vector<std::shared_ptr<Entity>>& getEntities();

        void clear();

    private:
        std::vector<std::shared_ptr<Entity> > m_entities;
    };
}


#endif //GEVPROGROADFIGHTER_ENTITYTRANSPORTER_H
