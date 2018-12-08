//
// Created by thibaut on 08.12.18.
//

#include "../../Include/Entities/SFMLPassingCar.h"

SFMLPassingCar::SFMLPassingCar(const std::shared_ptr<sf::RenderWindow> &window,
                               const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2,
                               double vertSpeed) : SFMLEntitySprite("../../SFMLConversion/resources/sprites/passing_car.png", window),
                                                   PassingCar(m_loc1, m_loc2, vertSpeed) {
    std::tuple<int,int> sfmlpos1=Transformation::getInstance().locationTransformation(getM_loc1());
    std::tuple<int,int> sfmlpos2=Transformation::getInstance().locationTransformation(getM_loc2());
    SFMLEntitySprite::scale(sf::Vector2f(
            ((std::get<0>(sfmlpos2)-std::get<0>(sfmlpos1))/SFMLEntitySprite::getGlobalBounds().width),
            ((std::get<1>(sfmlpos2)-std::get<1>(sfmlpos1))/SFMLEntitySprite::getGlobalBounds().height)));
    SFMLEntitySprite::rotate(180);
}

void SFMLPassingCar::draw() {
    std::tuple<int,int> newloc=Transformation::getInstance().locationTransformation(this->getM_loc1());
    setSpriteLocation(std::get<0>(newloc),std::get<1>(newloc));
    getWindow()->draw(*this);
}
