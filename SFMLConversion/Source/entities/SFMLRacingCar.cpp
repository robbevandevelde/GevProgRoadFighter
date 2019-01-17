/**
 *@file
 * implementation of the SFMLRacingCar class
 * @author Thibaut Van Goethem
 */

#include "../../Include/Entities/SFMLRacingCar.h"
namespace roadfighterSFML {

    /**
     * constructor for teh sfmlRacingCar class
     * @param m_loc1 first location of the car
     * @param m_loc2 second location of the car
     * @param m_maxVertSpeed the maximum vertical speed of the car
     * @param m_vertAccel the vertical acceleration of the car
     * @param m_horAccel the horizontal acceleration of the car
     * @param window the renderwindow that will be used to draw on
     * @return none
     * @exception none
     */
    SFMLRacingCar::SFMLRacingCar(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2,
                                 double m_maxVertSpeed, double m_vertAccel, double m_horAccel,
                                 const std::shared_ptr<sf::RenderWindow> &window) : RacingCar(m_loc1, m_loc2,
                                                                                              m_maxVertSpeed,
                                                                                              m_vertAccel,
                                                                                              m_horAccel),
                                                                                    SFMLEntitySprite(
                                                                                            "./resources/sprites/racing_car.png",
                                                                                            window) {
        std::tuple<double, double> sfmlpos1 = Transformation::getInstance().locationTransformation(getLoc1());
        std::tuple<double, double> sfmlpos2 = Transformation::getInstance().locationTransformation(getLoc2());
        setOrigin(SFMLEntitySprite::getGlobalBounds().width / 2, SFMLEntitySprite::getGlobalBounds().height / 2);
        SFMLEntitySprite::scale(sf::Vector2f(
                static_cast<float>((std::get<0>(sfmlpos2) - std::get<0>(sfmlpos1)) / SFMLEntitySprite::getGlobalBounds().width),
                static_cast<float>((std::get<1>(sfmlpos2) - std::get<1>(sfmlpos1)) / SFMLEntitySprite::getGlobalBounds().height)));
    }

    /**
   * draw function that is overriden from roadfighter::entity
   * @return none
   * @exception none
   */
    void SFMLRacingCar::draw() {
        std::tuple<double, double> newloc = Transformation::getInstance().locationTransformation(this->getLoc1());
        setSpriteLocation(std::get<0>(newloc) + SFMLEntitySprite::getGlobalBounds().width / 2,
                          std::get<1>(newloc) + SFMLEntitySprite::getGlobalBounds().height / 2);
        getWindow()->draw(*this);

        //if the car is immune then a shield is drawn around it
        if(isImmune()){
            sf::CircleShape shield;
            float raduis=SFMLEntitySprite::getGlobalBounds().width;
            shield.setRadius(raduis);
            shield.setOrigin(SFMLEntitySprite::getOrigin());
            shield.setFillColor(sf::Color(0,0,255,128));
            shield.setPosition(SFMLEntitySprite::getPosition().x-3*SFMLEntitySprite::getLocalBounds().width,SFMLEntitySprite::getPosition().y-3*SFMLEntitySprite::getLocalBounds().height);
            getWindow()->draw(shield);
        }
    }
}
