/**
 * @file header for SFMLBullet
 */

#ifndef GEVPROGROADFIGHTER_SFMLBULLET_H
#define GEVPROGROADFIGHTER_SFMLBULLET_H

#include <Entities/Bullet.h>
#include "SFMLEntitySprite.h"

namespace roadfighterSFML {
    class SFMLBullet : public roadfighter::Bullet, public SFMLEntitySprite {
    public:
        //constructor with parameters
        SFMLBullet(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2, double vertspeed,
                   const std::shared_ptr<sf::RenderWindow> &window);
        //draw function overrided from roadfighter::entity
        void draw() override;
    };
}


#endif //GEVPROGROADFIGHTER_SFMLBULLET_H
