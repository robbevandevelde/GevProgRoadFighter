//
// Created by thibaut on 28.11.18.
//

#include "../Include/SFMLRoadFighter.h"
#include <iostream>

SFMLRoadFighter::SFMLRoadFighter() {
    std::shared_ptr<SFMLPlayerCar> player=std::shared_ptr<SFMLPlayerCar>(new SFMLPlayerCar(400,10,0.1));
    std::shared_ptr<roadfighter::PlayerCar> playerCar=std::make_shared<roadfighter::PlayerCar>(*player);
    std::shared_ptr<SFMLEntity> playerDraw=player;
    m_game=std::make_shared<roadfighter::RoadFighterGame>(roadfighter::RoadFighterGame(playerCar));
    m_drawings={};
    m_drawings.insert(m_drawings.begin(),std::move(playerDraw));
}

void SFMLRoadFighter::startGame() {
    Clock gameclock=Clock();
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "ROADFIGHTER");
    while (window.isOpen())
    {

        if(gameclock.getTimeAsSeconds()>0.1) {
            draw(window);
            m_game->tick();
            gameclock.restart();
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                // left key is pressed: move our player to the left
                m_game->setHorMove(roadfighter::h_left);

            }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                // right key is pressed: move our player to the right
                m_game->setHorMove(roadfighter::h_right);
            }
        }
//        sf::RectangleShape shape(sf::Vector2f(100,100));
//        shape.setFillColor(sf::Color(255,255,255));
//        window.draw(shape);
        window.display();
    }
}

void SFMLRoadFighter::draw(sf::RenderWindow& window) {
    window.clear();
    for(auto i:m_drawings){
        i->draw(window);
    }

}

