/**
 * @file
 * header for SFMLEnd class
 * @author Thibaut Van Goethem
 */

#ifndef GEVPROGROADFIGHTER_SFMLEND_H
#define GEVPROGROADFIGHTER_SFMLEND_H

#include <Entities/End.h>
#include "SFMLEntitySprite.h"
namespace roadfighterSFML {
    class SFMLEnd : public roadfighter::End, public SFMLEntitySprite {
    public:
        //constructor with parameters
        SFMLEnd(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2,
                const std::shared_ptr<sf::RenderWindow> &window);
        //draw function overriden from roadfighter::entity
        void draw() override;
    };
}


#endif //GEVPROGROADFIGHTER_SFMLEND_H
