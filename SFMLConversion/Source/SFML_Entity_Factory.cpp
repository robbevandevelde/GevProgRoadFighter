//
// Created by thibaut on 05.12.18.
//

#include "../Include/SFML_Entity_Factory.h"


std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createBullet() {
    return nullptr;
}

std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::creatPassingCar(double x,double y,double vSpeed) {
    std::shared_ptr<SFMLPassingCar> toreturn=std::make_shared<SFMLPassingCar>(window,roadfighter::Location(x-0.25,y-0.25),roadfighter::Location(x+0.25,y+0.25),vSpeed);
    return toreturn;
}

std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createBonusCar(double x, double y,double vSpeed) {
    std::shared_ptr<SFMLBonusCar> toreturn=std::make_shared<SFMLBonusCar>(window,roadfighter::Location(x-0.25,y-0.25),roadfighter::Location(x+0.25,y+0.25),vSpeed);
    return toreturn;
}

std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createPlayerCar(double x,double y,double max,double vAccel,double hAccel,double fuel) {
    std::shared_ptr<SFMLPlayerCar> toreturn=std::make_shared<SFMLPlayerCar>(roadfighter::Location(x-0.25,y-0.25),roadfighter::Location(x+0.25,y+0.25),
            max,vAccel,hAccel,fuel,getController(),window);
    return toreturn;
}

std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createRacingCar(double x,double y,double max,double vAccel,double hAccel) {
    std::shared_ptr<SFMLRacingCar> toreturn=std::make_shared<SFMLRacingCar>(roadfighter::Location(x-0.25,y-0.25),roadfighter::Location(x+0.25,y+0.25),max,vAccel,hAccel,window);
    return toreturn;
}

std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createWorld() {
    std::shared_ptr<SFMLWorld> toreturn=std::make_shared<SFMLWorld>(getTransporter(),window);
    return toreturn;
}

SFML_Entity_Factory::SFML_Entity_Factory(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {}

