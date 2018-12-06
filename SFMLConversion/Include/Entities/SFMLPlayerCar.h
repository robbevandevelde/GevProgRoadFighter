//
// Created by thibaut on 01.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLPLAYERCAR_H
#define GEVPROGROADFIGHTER_SFMLPLAYERCAR_H

#include <Entities/PlayerCar.h>
#include <SFML/Graphics.hpp>
#include "SFMLEntity.h"

class SFMLPlayerCar: public roadfighter::PlayerCar, public SFMLEntity{
public:


    SFMLPlayerCar(double m_maxVertSpeed, double m_vertAccel, double m_horAccel,
                  const std::shared_ptr<roadfighter::MoveController> &controller, int fuel,
                  const std::shared_ptr<sf::RenderWindow> &window);

    void draw() override;





};


#endif //GEVPROGROADFIGHTER_SFMLPLAYERCAR_H
