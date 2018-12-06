//
// Created by thibaut on 06.12.18.
//

#include <EntityTransporter.h>

#include "EntityTransporter.h"

void roadfighter::EntityTransporter::addEntity(std::shared_ptr<roadfighter::Entity> toAdd) {
    m_entities.push_back(toAdd);

}

std::vector<std::shared_ptr<roadfighter::Entity>> &roadfighter::EntityTransporter::getEntities() {
    return m_entities;
}

void roadfighter::EntityTransporter::clear() {
    m_entities.clear();
}
