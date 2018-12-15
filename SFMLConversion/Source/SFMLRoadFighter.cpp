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
        if(gameclock.getTimeAsSeconds()>0.00833) {
            m_window->clear();
            draw(m_window);
            m_game->tick(gameclock.getTimeAsSeconds()/0.033 );
            gameclock.restart();

        }
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            checkMovement(event);
        }
        m_window->display();
    }
}

void SFMLRoadFighter::checkMovement(sf::Event &event) {
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        m_game->pauseGame();
    }
    if(event.type ==sf::Event::KeyReleased&&(event.key.code==sf::Keyboard::Left||event.key.code==sf::Keyboard::Right)){
        m_game->stopHorizontalMove();

    }
    if(event.type ==sf::Event::KeyReleased&&(event.key.code==sf::Keyboard::Up||event.key.code==sf::Keyboard::Down)){
        m_game->stopVerticalMove();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(m_game->getStatus()==roadfighter::gamePaused){
            m_game->continueGame();
        }else {
            m_game->shoot();
        }

    }
    if(event.type ==sf::Event::KeyReleased&&(event.key.code==sf::Keyboard::Space)){
        m_game->stopShooting();
    }

}

void SFMLRoadFighter::draw(std::shared_ptr<sf::RenderWindow> window) {
    m_game->drawWorld();
    drawSideStats(window);
    if(m_game->getStatus()==roadfighter::gamePaused){
        drawPaused(window);
    }

}

void SFMLRoadFighter::drawSideStats(std::shared_ptr<sf::RenderWindow> window) {
    auto speedpos=Transformation::getInstance().locationTransformation(roadfighter::Location(6,-4));
    drawText(window,"speed: "+std::to_string((int)(round(m_game->getsSpeed()*300))),speedpos);

    auto fuelpos=Transformation::getInstance().locationTransformation(roadfighter::Location(6,-3));
    drawText(window,"Fuel: "+std::to_string((int)(round(m_game->getFuel()))),fuelpos);

    auto scorepos=Transformation::getInstance().locationTransformation(roadfighter::Location(6,-2));
    drawText(window,"score: "+std::to_string(m_game->getScore()),scorepos);

}

void SFMLRoadFighter::drawPaused(std::shared_ptr<sf::RenderWindow> window) {
    sf::RectangleShape transparenrect(sf::Vector2f(window->getSize().x,window->getSize().y));
    transparenrect.setFillColor(sf::Color(0,0,0,200));
    window->draw(transparenrect);

    sf::Font font;
    font.loadFromFile("../../SFMLConversion/resources/open-sans/OpenSans-Regular.ttf");

    auto pausepos=Transformation::getInstance().locationTransformation(roadfighter::Location(-1.1,-1));
    drawText(window,"game has been paused",pausepos,sf::Color(128,128,128),24);


    auto spacePos=Transformation::getInstance().locationTransformation(roadfighter::Location(-1,-0.5));
    drawText(window,"press space to continue",spacePos,sf::Color(128,128,128),20);
}

void
SFMLRoadFighter::drawText(std::shared_ptr<sf::RenderWindow> window, std::string text, std::tuple<int, int> position,
                          sf::Color color, int size) {
    sf::Font font;
    font.loadFromFile("../../SFMLConversion/resources/open-sans/OpenSans-Regular.ttf");

    sf::Text towrite;
    towrite.setFont(font);
    towrite.setString(text);
    towrite.setCharacterSize(size);
    auto scorepos=Transformation::getInstance().locationTransformation(roadfighter::Location(-1,-1));
    towrite.setPosition(std::get<0>(position),std::get<1>(position));

    //setcolor is used instead of setFillcolor because new function wont run on travis/labo pc's
    towrite.setColor(color);
    window->draw(towrite);

}
