//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_CAR_H
#define GEVPROGROADFIGHTER_CAR_H

#include "Entity.h"
#include "CollisionObject.h"

namespace roadfighter {
    class Car : public CollisionObject,Entity {
    public:

    private:
        double m_VerticalSpeed;
        double m_HorizontalSpeed;
    };
}


#endif //GEVPROGROADFIGHTER_CAR_H
