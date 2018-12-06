//
// Created by thibaut on 28.11.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLROADFIGHTER_H
#define GEVPROGROADFIGHTER_SFMLROADFIGHTER_H

#include <../../GameLogic/include/RoadFighterGame.h>
#include <../../GameLogic/Utility/Clock.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Entities/SFMLPlayerCar.h"


class SFMLRoadFighter{
public:
    SFMLRoadFighter();

    void startGame();

private:

    void draw(sf::RenderWindow& window) ;

    std::vector<std::shared_ptr<SFMLEntity>> m_drawings;

    std::shared_ptr<roadfighter::RoadFighterGame> m_game;





};


#endif //GEVPROGROADFIGHTER_SFMLROADFIGHTER_H
