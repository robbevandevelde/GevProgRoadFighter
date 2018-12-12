//
// Created by thibaut on 10.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLBULLET_H
#define GEVPROGROADFIGHTER_SFMLBULLET_H

#include <Entities/Bullet.h>
#include "SFMLEntitySprite.h"


class SFMLBullet:public roadfighter::Bullet, public SFMLEntitySprite {
public:
    SFMLBullet(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2, double vertspeed,
               const std::shared_ptr<sf::RenderWindow> &window);

    void draw() override;
};


#endif //GEVPROGROADFIGHTER_SFMLBULLET_H
