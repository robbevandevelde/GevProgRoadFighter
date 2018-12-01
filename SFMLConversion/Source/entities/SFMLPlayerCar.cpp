//
// Created by thibaut on 01.12.18.
//

#include "../../Include/Entities/SFMLPlayerCar.h"


SFMLPlayerCar::SFMLPlayerCar(double m_maxVertSpeed, double m_vertAccel, double m_horAccel)
        : PlayerCar(m_maxVertSpeed, m_vertAccel, m_horAccel), SFMLEntity("../../SFMLConversion/resources/sprites/passing_car.png") {
//    SFMLEntity::loadSprite();
}

void SFMLPlayerCar::draw(sf::RenderWindow &window) {
    setSpriteLocation((4+this->getM_loc1().getX()),(3+this->getM_loc1().getY()));
    window.draw(*this);
}
