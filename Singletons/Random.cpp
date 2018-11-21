//
// Created by thibaut on 21.11.18.
//

#include "Random.h"

Random::Random() {
 if(this->m_instance)
}

std::weak_ptr<Random> Random::getInstance() {
    return std::weak_ptr<Random>();
}

int Random::getRandom(const int to) const {
    return 0;
}
