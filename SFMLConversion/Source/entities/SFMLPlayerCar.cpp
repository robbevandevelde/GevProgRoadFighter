/**
 *@file
 * implementation of the SFMLPlayerCar class
 */

#include "../../Include/Entities/SFMLPlayerCar.h"
namespace roadfighterSFML {

    /**
     * constructor for the sfmlPlayerCar
     * @param m_loc1 first location of the playercar
     * @param m_loc2 second location of the playercar
     * @param m_maxVertSpeed the maximum vertical speed of the car
     * @param m_vertAccel the vertical acceleration of the car
     * @param m_horAccel the horizontal acceleration of the car
     * @param m_fuel the starting fuel
     * @param m_moveController the controller that is going to be used to get input from
     * @param transporter the entity tranporter that the car will use to make bullets and get them to the world
     * @param factory the entity factory that the car will use to create the bullets
     * @param window the renderwindow that will be used to draw on
     * @return none
     * @exception none
     */
    SFMLPlayerCar::SFMLPlayerCar(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2,
                                 double m_maxVertSpeed, double m_vertAccel, double m_horAccel, double m_fuel,
                                 const std::shared_ptr<roadfighter::InputController> &m_moveController,
                                 const std::shared_ptr<roadfighter::EntityTransporter> &transporter,
                                 const std::shared_ptr<roadfighter::Entity_Factory_base> &factory,
                                 const std::shared_ptr<sf::RenderWindow> &window) : PlayerCar(
            m_loc1, m_loc2, m_maxVertSpeed, m_vertAccel, m_horAccel, m_fuel, m_moveController, transporter, factory),
                                                                                    SFMLEntitySprite(
                                                                                            "./resources/sprites/player_car.png",
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
    void SFMLPlayerCar::draw() {
        std::tuple<int, int> newloc = Transformation::getInstance().locationTransformation(this->getLoc1());
        setSpriteLocation(std::get<0>(newloc) + SFMLEntitySprite::getGlobalBounds().width / 2,
                          std::get<1>(newloc) + SFMLEntitySprite::getGlobalBounds().height / 2);
        if (getHorizontalSpeed() < 0) {
            SFMLEntitySprite::setRotation(-10);
        } else if (getHorizontalSpeed() > 0) {
            SFMLEntitySprite::setRotation(10);
        } else {
            if (getRotation() > 160) {
                SFMLEntitySprite::setRotation(getRotation() + 1);
            } else if (getRotation() > 0) {
                SFMLEntitySprite::setRotation(getRotation() - 1);
            }
        }
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
