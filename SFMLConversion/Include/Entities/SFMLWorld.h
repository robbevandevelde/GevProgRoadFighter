/**
 * @file
 * header for SFMLWorld class
 * @author Thibaut Van Goethem
 */


#ifndef GEVPROGROADFIGHTER_SFMLWORLD_H
#define GEVPROGROADFIGHTER_SFMLWORLD_H

#include <Entities/World.h>
#include <SFML/Graphics.hpp>
#include "SFMLEntitySprite.h"
namespace roadfighterSFML {
    class SFMLWorld : public roadfighter::World, public SFMLEntitySprite {
    public:
        //constructor with parameters
        SFMLWorld(const std::shared_ptr<roadfighter::EntityTransporter> &m_Transporter,
                  const std::shared_ptr<sf::RenderWindow> &window);
        //draw function overriden from roadfighter::entity
        void draw() override;
    };
}


#endif //GEVPROGROADFIGHTER_SFMLWORLD_H
