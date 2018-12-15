//
// Created by thibaut on 28.11.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLROADFIGHTER_H
#define GEVPROGROADFIGHTER_SFMLROADFIGHTER_H

#include <../../GameLogic/include/RoadFighterGame.h>
#include <../../GameLogic/Utility/Clock.h>
#include "SFML_Entity_Factory.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <cmath>
#include "Entities/SFMLPlayerCar.h"


class SFMLRoadFighter{
public:
    SFMLRoadFighter();

    void rungame();


private:

    void draw(std::shared_ptr<sf::RenderWindow> window) ;

    void drawSideStats(std::shared_ptr<sf::RenderWindow> window);

    void drawPaused(std::shared_ptr<sf::RenderWindow> window);

    void drawText(std::shared_ptr<sf::RenderWindow> window,std::string text,std::tuple<int,int> position,
            sf::Color color=sf::Color(255,255,255),int size=24);

    void checkMovement(sf::Event& event);

    std::shared_ptr<roadfighter::RoadFighterGame> m_game;

    std::shared_ptr<sf::RenderWindow> m_window;





};


#endif //GEVPROGROADFIGHTER_SFMLROADFIGHTER_H
