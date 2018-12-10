//
// Created by thibaut on 10.12.18.
//

#ifndef GEVPROGROADFIGHTER_END_H
#define GEVPROGROADFIGHTER_END_H

#include "CollisionObject.h"
namespace roadfighter {
    class End : public CollisionObject {
    public:
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        void crash() override;

        void shot() override;

        void bonus() override;

        void updateLogic() override;

        void updateMovement(double dt) override;

        void win() override;

        End(const Location &m_loc1, const Location &m_loc2);
    };
}


#endif //GEVPROGROADFIGHTER_END_H
