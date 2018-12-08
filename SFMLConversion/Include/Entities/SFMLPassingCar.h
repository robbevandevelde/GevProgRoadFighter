//
// Created by thibaut on 08.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLPASSINGCAR_H
#define GEVPROGROADFIGHTER_SFMLPASSINGCAR_H


#include <Entities/PassingCar.h>
#include "SFMLEntitySprite.h"

class SFMLPassingCar: public SFMLEntitySprite, public roadfighter::PassingCar {
public:
    SFMLPassingCar(const std::shared_ptr<sf::RenderWindow> &window,
                   const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2, double vertSpeed);

    void draw() override;
};


#endif //GEVPROGROADFIGHTER_SFMLPASSINGCAR_H
