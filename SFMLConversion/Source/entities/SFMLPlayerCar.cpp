//
// Created by thibaut on 01.12.18.
//

#include "../../Include/Entities/SFMLPlayerCar.h"

SFMLPlayerCar::SFMLPlayerCar(double m_maxVertSpeed, double m_vertAccel, double m_horAccel)
        : PlayerCar(m_maxVertSpeed, m_vertAccel, m_horAccel), SFMLEntity("../../SFMLConversion/resources/sprites/passing_car.png") {
    std::tuple<int,int> sfmlpos1=Transformation::getInstance().locationTransformation(getM_loc1());
    std::tuple<int,int> sfmlpos2=Transformation::getInstance().locationTransformation(getM_loc2());
    SFMLEntity::scale(sf::Vector2f(
            ((std::get<0>(sfmlpos2)-std::get<0>(sfmlpos1))/SFMLEntity::getGlobalBounds().width),
            ((std::get<1>(sfmlpos2)-std::get<1>(sfmlpos1))/SFMLEntity::getGlobalBounds().height)));
}

void SFMLPlayerCar::draw(sf::RenderWindow &window) {
    std::tuple<int,int> newloc=Transformation::getInstance().locationTransformation(this->getM_loc1());
    setSpriteLocation(std::get<0>(newloc),std::get<1>(newloc));
    window.draw(*this);
}
