//
// Created by thibaut on 06.12.18.
//

#include "../../Include/Entities/SFMLWorld.h"

SFMLWorld::SFMLWorld(const std::shared_ptr<roadfighter::EntityTransporter> &m_Transporter,
                     const std::shared_ptr<sf::RenderWindow> &window) : World(m_Transporter),
                                                                        SFMLEntity("../../SFMLConversion/resources/sprites/passing_car.png", window) {}

void SFMLWorld::draw() {
    World::draw();
}
