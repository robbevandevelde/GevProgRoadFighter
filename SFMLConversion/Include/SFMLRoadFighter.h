/**
 * @file
 * header for the SFMLRoadfighter class
 * @author Thibaut Van Goethem
 */

#ifndef GEVPROGROADFIGHTER_SFMLROADFIGHTER_H
#define GEVPROGROADFIGHTER_SFMLROADFIGHTER_H

#include <RoadFighterGame.h>
#include <../../GameLogic/Utility/Clock.h>
#include "SFML_Entity_Factory.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <HighScoreManager.h>
#include <cmath>
#include "Entities/SFMLPlayerCar.h"
#include "SFMLconversionException.h"

namespace roadfighterSFML {
    class SFMLRoadFighter {
    public:
        //default constructor
        SFMLRoadFighter();

        //function that starts the game
        void rungame();


    private:
        //here are a bunch of helper function to help draw the screen

        void draw();

        void drawSideStats();

        void drawPaused();

        void drawEnded();

        void drawText(std::string text, std::tuple<int, int> position,
                      sf::Color color = sf::Color(255, 255, 255), int size = 24);


        //here are a bunch of helper function to handle sfml events (mostly keyboardinput)
        void MovementEvent(sf::Event &event);

        void pauseScreenEvent(sf::Event &event);

        void askNameEvent(sf::Event &event);

        void endGameEvent(sf::Event &event);

    private:

        std::shared_ptr<roadfighter::RoadFighterGame> m_game;

        std::shared_ptr<sf::RenderWindow> m_window;

        std::string m_endName;

        bool m_nameGiven;

        std::shared_ptr<roadfighter::InputController> m_input;
    };
}


#endif //GEVPROGROADFIGHTER_SFMLROADFIGHTER_H
