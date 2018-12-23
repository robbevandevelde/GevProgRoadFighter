//
// Created by thibaut on 10.12.18.
//

#include "../../Include/Entities/SFMLEnd.h"
namespace roadfighterSFML {
    SFMLEnd::SFMLEnd(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2,
                     const std::shared_ptr<sf::RenderWindow> &window) : End(m_loc1, m_loc2),
                                                                        SFMLEntitySprite(
                                                                                "../../SFMLConversion/resources/sprites/Finishline.png",
                                                                                window) {
        std::tuple<int, int> sfmlpos1 = Transformation::getInstance().locationTransformation(getLoc1());
        std::tuple<int, int> sfmlpos2 = Transformation::getInstance().locationTransformation(getLoc2());
        SFMLEntitySprite::scale(sf::Vector2f(
                ((std::get<0>(sfmlpos2) - std::get<0>(sfmlpos1)) / SFMLEntitySprite::getGlobalBounds().width),
                ((std::get<1>(sfmlpos2) - std::get<1>(sfmlpos1)) / SFMLEntitySprite::getGlobalBounds().height)));
    }

    void SFMLEnd::draw() {
        std::tuple<int, int> newloc = Transformation::getInstance().locationTransformation(this->getLoc1());
        setSpriteLocation(std::get<0>(newloc), std::get<1>(newloc));
        getWindow()->draw(*this);
    }
}
