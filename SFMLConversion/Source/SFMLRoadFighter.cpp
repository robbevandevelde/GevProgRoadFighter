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

        if(gameclock.getTimeAsSeconds()>0.016) {
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                m_game->accelerate();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                m_game->decelerate();
            }
            if(event.type ==sf::Event::KeyReleased&&(event.key.code==sf::Keyboard::Left||event.key.code==sf::Keyboard::Right)){
                m_game->stopHorizontalMove();

            }
            if(event.type ==sf::Event::KeyReleased&&(event.key.code==sf::Keyboard::Up||event.key.code==sf::Keyboard::Down)){
                    m_game->stopVerticalMove();
            }

        }
        window->display();
    }
}

void SFMLRoadFighter::draw(std::shared_ptr<sf::RenderWindow> window) {
    m_game->drawWorld();
    sf::Text text;
    sf::Font font;
    font.loadFromFile("../../SFMLConversion/resources/open-sans/OpenSans-Regular.ttf");
    text.setFont(font);

    text.setString(std::to_string(m_game->getsSpeed()));

    text.setCharacterSize(24);

    //should use setFillColor but that function wont run on travis and pc's at university
    text.setColor(sf::Color::Red);

    window->draw(text);
}
