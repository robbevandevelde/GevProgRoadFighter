//
// Created by thibaut on 10.12.18.
//

#include "Entities/End.h"

void roadfighter::End::collideWith(std::shared_ptr<roadfighter::CollisionObject> &collided) {
    collided->win();

}

void roadfighter::End::crash() {}

void roadfighter::End::shot() {}

void roadfighter::End::bonus() {}

void roadfighter::End::updateLogic() {}

void roadfighter::End::updateMovement(double dt) {}

void roadfighter::End::win() {}



roadfighter::End::End(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2) : CollisionObject(
        m_loc1, m_loc2) {}
