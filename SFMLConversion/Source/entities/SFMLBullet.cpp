/**
 *@file
 * implementation of the sfmlBullet class
 */

#include "../../Include/Entities/SFMLBullet.h"
namespace roadfighterSFML {

    /**
     * constructor for sfmlNullet
     * @param m_loc1 first location of the bullet (top left)
     * @param m_loc2 second location of the buller (bottem right)
     * @param vertspeed vertical speed of the bullet
     * @param window the sfmlrenderwindow that is used to draw on
     * @return none
     * @exception none
     */
    SFMLBullet::SFMLBullet(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2, double vertspeed,
                           const std::shared_ptr<sf::RenderWindow> &window) : Bullet(m_loc1, m_loc2, vertspeed),
                                                                              SFMLEntitySprite(
                                                                                      "./resources/sprites/bullet.png",
                                                                                      window) {
        std::tuple<int, int> sfmlpos1 = Transformation::getInstance().locationTransformation(getLoc1());
        std::tuple<int, int> sfmlpos2 = Transformation::getInstance().locationTransformation(getLoc2());
        setOrigin(SFMLEntitySprite::getGlobalBounds().width / 2, SFMLEntitySprite::getGlobalBounds().height / 2);
        SFMLEntitySprite::scale(sf::Vector2f(
                ((std::get<0>(sfmlpos2) - std::get<0>(sfmlpos1)) / SFMLEntitySprite::getGlobalBounds().width),
                ((std::get<1>(sfmlpos2) - std::get<1>(sfmlpos1)) / SFMLEntitySprite::getGlobalBounds().height)));
    }

    /**
   * draw function that is overriden from roadfighter::entity
   * @return none
   * @exception none
   */
    void SFMLBullet::draw() {
        std::tuple<int, int> newloc = Transformation::getInstance().locationTransformation(this->getLoc1());
        setSpriteLocation(std::get<0>(newloc) + SFMLEntitySprite::getGlobalBounds().width / 2,
                          std::get<1>(newloc) + SFMLEntitySprite::getGlobalBounds().height / 2);
        if (getVerticalSpeed() < 0) {
            SFMLEntitySprite::setRotation(180);
        } else {
            SFMLEntitySprite::setRotation(0);
        }
        getWindow()->draw(*this);
    }
}
