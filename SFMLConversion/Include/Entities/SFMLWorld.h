//
// Created by thibaut on 06.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLWORLD_H
#define GEVPROGROADFIGHTER_SFMLWORLD_H

#include <Entities/World.h>
#include <SFML/Graphics.hpp>
#include "SFMLEntitySprite.h"

class SFMLWorld: public roadfighter::World, public SFMLEntitySprite {
public:
    SFMLWorld(const std::shared_ptr<roadfighter::EntityTransporter> &m_Transporter,
              const std::shared_ptr<sf::RenderWindow> &window);

    void draw() override;
};


#endif //GEVPROGROADFIGHTER_SFMLWORLD_H
