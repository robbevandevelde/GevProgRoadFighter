//
// Created by thibaut on 05.12.18.
//

#include "../Include/SFML_Entity_Factory.h"


std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createBullet() {
    return nullptr;
}

std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::creatPassingCar() {
    return nullptr;
}

std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createPlayerCar() {
    std::shared_ptr<SFMLPlayerCar> toreturn=std::make_shared<SFMLPlayerCar>(400,10,0.1,getController(),100,window);
    return toreturn;
}

std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createRacingCar() {
    return nullptr;
}

std::shared_ptr<roadfighter::Entity> SFML_Entity_Factory::createWorld() {
    std::shared_ptr<SFMLWorld> toreturn=std::make_shared<SFMLWorld>(getTransporter(),window);
    return toreturn;
}

SFML_Entity_Factory::SFML_Entity_Factory(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {}
