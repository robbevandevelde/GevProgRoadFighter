//
// Created by thibaut on 28.11.18.
//

#include "../Include/SFMLRoadFighter.h"
#include <iostream>

SFMLRoadFighter::SFMLRoadFighter() {
    m_window=std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "ROADFIGHTER");
    std::shared_ptr<SFML_Entity_Factory> factory=std::make_shared<SFML_Entity_Factory>(SFML_Entity_Factory(m_window));
    m_game=std::make_shared<roadfighter::RoadFighterGame>(roadfighter::RoadFighterGame(factory));

}

void SFMLRoadFighter::rungame(){
    Clock gameclock=Clock();
    while (m_window->isOpen())
    {

        if(gameclock.getTimeAsSeconds()>0.016) {
            m_window->clear();
            draw(m_window);
            m_game->tick(gameclock.getTimeAsSeconds()/0.1);
            gameclock.restart();

        }
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window->close();
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
        m_window->display();
    }
}

void SFMLRoadFighter::draw(std::shared_ptr<sf::RenderWindow> window) {
    m_game->drawWorld();
    sf::Text speed;
    sf::Font font;
    font.loadFromFile("../../SFMLConversion/resources/open-sans/OpenSans-Regular.ttf");
    speed.setFont(font);
    speed.setString("speed: "+std::to_string((int)(round(m_game->getsSpeed()*300))));
    speed.setCharacterSize(24);
    auto speedpos=Transformation::getInstance().locationTransformation(roadfighter::Location(6,-4));
    speed.setPosition(std::get<0>(speedpos),std::get<1>(speedpos));
    window->draw(speed);

    sf::Text fuel;
    fuel.setFont(font);
    fuel.setString("Fuel: "+std::to_string((int)(round(m_game->getFuel()))));
    fuel.setCharacterSize(24);
    auto fuelpos=Transformation::getInstance().locationTransformation(roadfighter::Location(6,-3));
    fuel.setPosition(std::get<0>(fuelpos),std::get<1>(fuelpos));
    window->draw(fuel);


}
