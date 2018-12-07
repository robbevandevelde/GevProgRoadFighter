//
// Created by thibaut on 28.11.18.
//

#include "../Include/SFMLRoadFighter.h"
#include <iostream>

SFMLRoadFighter::SFMLRoadFighter() {


    std::shared_ptr<sf::RenderWindow> window=std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "ROADFIGHTER");
    std::shared_ptr<SFML_Entity_Factory> factory=std::make_shared<SFML_Entity_Factory>(SFML_Entity_Factory(window));
    m_game=std::make_shared<roadfighter::RoadFighterGame>(roadfighter::RoadFighterGame(factory));
    Clock gameclock=Clock();
    while (window->isOpen())
    {

        if(gameclock.getTimeAsSeconds()>0.1) {
            window->clear();
            draw(window);
            m_game->tick(gameclock.getTimeAsSeconds()/0.1);
            gameclock.restart();

        }
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                // left key is pressed: move our player to the left
                m_game->moveLeft();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                // right key is pressed: move our player to the right
                m_game->moveRight();
            }
            if(event.type ==sf::Event::KeyReleased){
                m_game->stopHorizontalMove();
            }

        }
        window->display();
    }
}

void SFMLRoadFighter::draw(std::shared_ptr<sf::RenderWindow> window) {
    m_game->drawWorld();
}
