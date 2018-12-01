//
// Created by thibaut on 01.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLPLAYERCAR_H
#define GEVPROGROADFIGHTER_SFMLPLAYERCAR_H

#include "../../../GameLogic/include/Entities/PlayerCar.h"
#include <SFML/Graphics.hpp>
#include "SFMLEntity.h"

class SFMLPlayerCar: public roadfighter::PlayerCar, public SFMLEntity{
public:

    SFMLPlayerCar(double m_maxVertSpeed, double m_vertAccel, double m_horAccel);

    void draw(sf::RenderWindow &window) override;

};


#endif //GEVPROGROADFIGHTER_SFMLPLAYERCAR_H
