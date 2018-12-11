//
// Created by thibaut on 10.12.18.
//

#include "../../Include/Entities/SFMLBullet.h"

void SFMLBullet::draw() {
    std::tuple<int,int> newloc=Transformation::getInstance().locationTransformation(this->getLoc1());
    setSpriteLocation(std::get<0>(newloc)+SFMLEntitySprite::getGlobalBounds().width/2,std::get<1>(newloc)+SFMLEntitySprite::getGlobalBounds().height/2);
    setRotation(90);
    getWindow()->draw(*this);
}

SFMLBullet::SFMLBullet(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2, double m_maxVertSpeed,
                       double m_vertAccel, double m_horAccel,
                       const std::shared_ptr<sf::RenderWindow> &window) : Bullet(m_loc1, m_loc2, m_maxVertSpeed,
                                                                                 m_vertAccel, m_horAccel),
                                                                          SFMLEntitySprite("../../SFMLConversion/resources/sprites/transport_car.png", window) {
    std::tuple<int,int> sfmlpos1=Transformation::getInstance().locationTransformation(getLoc1());
    std::tuple<int,int> sfmlpos2=Transformation::getInstance().locationTransformation(getLoc2());
    SFMLEntitySprite::scale(sf::Vector2f(
            ((std::get<0>(sfmlpos2)-std::get<0>(sfmlpos1))/SFMLEntitySprite::getGlobalBounds().width),
            ((std::get<1>(sfmlpos2)-std::get<1>(sfmlpos1))/SFMLEntitySprite::getGlobalBounds().height)));
}
