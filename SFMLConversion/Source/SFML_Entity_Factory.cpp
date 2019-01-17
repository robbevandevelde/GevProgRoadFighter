/**
 *@file
 * implementation of the SFML_Entity_Factory class
 * @author Thibaut Van Goethem
 */

#include "../Include/SFML_Entity_Factory.h"

namespace roadfighterSFML {

    /**
     * function that creates a entity from  a bullet
     * @param x the x location
     * @param y the y location
     * @param vSpeed teh vertical speed of the bullet
     * @return std::shared_ptr<roadfighter::Entity>
     * @exception none
     */
    std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createBullet(double x, double y, double vSpeed) {
        std::shared_ptr<SFMLBullet> toreturn = std::make_shared<SFMLBullet>(roadfighter::Location(x - 0.05, y - 0.05),
                                                                            roadfighter::Location(x + 0.05, y + 0.05),
                                                                            vSpeed, window);
        return toreturn;
    }

    /**
     * function that creates an entity from a passingcar
     * @param x the x location
     * @param y the y location
     * @param vSpeed the vertical speed
     * @return std::shared_ptr<roadfighter::Entity>
     * @exception none
     */
    std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::creatPassingCar(double x, double y, double vSpeed) {
        std::shared_ptr<SFMLPassingCar> toreturn = std::make_shared<SFMLPassingCar>(window,
                                                                                    roadfighter::Location(x - 0.25,
                                                                                                          y - 0.25),
                                                                                    roadfighter::Location(x + 0.25,
                                                                                                          y + 0.25),
                                                                                    vSpeed);
        toreturn->attach(getScoreObserver());
        return toreturn;
    }

    /**
     * function that creates an entity from a bonuscar
     * @param x the x location
     * @param y the y location
     * @param vSpeed the vertical speed
     * @return std::shared_ptr<roadfighter::Entity>
     * @exception none
     */
    std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createBonusCar(double x, double y, double vSpeed) {
        std::shared_ptr<SFMLBonusCar> toreturn = std::make_shared<SFMLBonusCar>(window, roadfighter::Location(x - 0.25,
                                                                                                              y - 0.25),
                                                                                roadfighter::Location(x + 0.25,
                                                                                                      y + 0.25),
                                                                                vSpeed);
        toreturn->attach(getScoreObserver());
        return toreturn;
    }

    /**
     * a function that creates an entity from a playercar
     * @param x the x coordinate
     * @param y the y coordinate
     * @param max the max vertical speed
     * @param vAccel vertical acceleration
     * @param hAccel horizontal acceleration
     * @param fuel teh starting fuel
     * @return std::shared_ptr<roadfighter::Entity>$
     * @exception none
     */
    std::shared_ptr<roadfighter::Entity>
    SFML_Entity_Factory::createPlayerCar(double x, double y, double max, double vAccel, double hAccel, double fuel) {
        std::shared_ptr<SFMLPlayerCar> toreturn = std::make_shared<SFMLPlayerCar>(
                roadfighter::Location(x - 0.25, y - 0.25), roadfighter::Location(x + 0.25, y + 0.25),
                max, vAccel, hAccel, fuel, getController(), getTransporter(), shared_from_this(), window);
        toreturn->attach(getScoreObserver());
        return toreturn;
    }

    /**
     * a function that creates an entity from a racingcar
     * @param x the x coordinate
     * @param y the y coordinate
     * @param max max vertical
     * @param max max vertical speed
     * @param vAccel vertical acceleration
     * @param hAccel horizontal acceleration
     * @return std::shared_ptr<roadfighter::Entity>
     * @exception none
     */
    std::shared_ptr<roadfighter::Entity>
    SFML_Entity_Factory::createRacingCar(double x, double y, double max, double vAccel, double hAccel) {
        std::shared_ptr<SFMLRacingCar> toreturn = std::make_shared<SFMLRacingCar>(
                roadfighter::Location(x - 0.25, y - 0.25), roadfighter::Location(x + 0.25, y + 0.25), max, vAccel,
                hAccel, window);
        toreturn->attach(getScoreObserver());
        return toreturn;
    }

    /**
     * a function that creates an entity from a SFMLWorld
     * @return std::shared_ptr<roadfighter::Entity>
     * @exception none
     */
    std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createWorld() {
        std::shared_ptr<SFMLWorld> toreturn = std::make_shared<SFMLWorld>(getTransporter(), window);
        return toreturn;
    }

    /**
     * constructor for sfml_entity_factory
     * @param window the renderwindow that will be given to all entities
     * @return none
     * @exception none
     */
    SFML_Entity_Factory::SFML_Entity_Factory(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {}

    /**
     * function that creates an entity from a sfmlend object
     * @param y y location of the end object
     * @return std::shared_ptr<roadfighter::Entity>
     * @exception none
     */
    std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createEnd(double y) {
        std::shared_ptr<SFMLEnd> toreturn = std::make_shared<SFMLEnd>(roadfighter::Location(-3, y - 0.5),
                                                                      roadfighter::Location(3, y + 0.5), window);
        return toreturn;
    }
}

