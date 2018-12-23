//
// Created by thibaut on 10.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLEND_H
#define GEVPROGROADFIGHTER_SFMLEND_H

#include <Entities/End.h>
#include "SFMLEntitySprite.h"
namespace roadfighterSFML {
    class SFMLEnd : public roadfighter::End, public SFMLEntitySprite {
    public:
        SFMLEnd(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2,
                const std::shared_ptr<sf::RenderWindow> &window);

        void draw() override;
    };
}


#endif //GEVPROGROADFIGHTER_SFMLEND_H
