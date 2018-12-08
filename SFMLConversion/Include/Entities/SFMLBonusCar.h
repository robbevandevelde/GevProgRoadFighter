//
// Created by thibaut on 08.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLBONUSCAR_H
#define GEVPROGROADFIGHTER_SFMLBONUSCAR_H


#include "SFMLEntitySprite.h"
#include <Entities/BonusCar.h>

class SFMLBonusCar: public SFMLEntitySprite, public roadfighter::BonusCar {
public:
    SFMLBonusCar(const std::shared_ptr<sf::RenderWindow> &window,
                 const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2, double vertSpeed);

    void draw() override;
};


#endif //GEVPROGROADFIGHTER_SFMLBONUSCAR_H
