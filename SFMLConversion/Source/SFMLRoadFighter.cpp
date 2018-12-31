/**
 *@file
 * implementation of the SFMLroadfighter class
 */

#include "../Include/SFMLRoadFighter.h"

using Clock=roadfighter::Clock;
namespace roadfighterSFML {
    /**
     * constructor for the SFMLRoadfighter game
     * @return none
     * @exception none
     */
    SFMLRoadFighter::SFMLRoadFighter() {
        m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "ROADFIGHTER");
        std::shared_ptr<SFML_Entity_Factory> factory = std::make_shared<SFML_Entity_Factory>(
                SFML_Entity_Factory(m_window));
        m_game = std::make_shared<roadfighter::RoadFighterGame>(roadfighter::RoadFighterGame(factory,30));
        m_nameGiven = false;

    }

    /**
     * function that runs the entire game
     * @return none
     * @exception none
     */
    void SFMLRoadFighter::rungame() {
        Clock gameclock = Clock();
        while (m_window->isOpen()) {
            if (gameclock.getTimeAsSeconds() > 0.00833) {
                m_window->clear();
                m_game->tick(gameclock.getTimeAsSeconds());
                draw(m_window);
                gameclock.restart();

            }
            sf::Event event{};
            while (m_window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    m_window->close();
                if (!m_game->hasEnded() && !m_game->ispaused()) {
                    MovementEvent(event);
                } else if (m_game->ispaused()) {
                    pauseScreenEvent(event);
                } else if (m_game->hasEnded() && !m_nameGiven) {
                    askNameEvent(event);
                } else {
                    endGameEvent(event);
                }
//
            }
            m_window->display();
        }
    }

    void SFMLRoadFighter::endGameEvent(sf::Event &event) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            m_window->close();
        }
    }

    void SFMLRoadFighter::MovementEvent(sf::Event &event) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            // left key is pressed: move our player to the left
            m_game->moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            // right key is pressed: move our player to the right
            m_game->moveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            m_game->accelerate();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            m_game->decelerate();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            m_game->pauseGame();
        }
        if (event.type == sf::Event::KeyReleased &&
            (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)) {
            m_game->stopHorizontalMove();

        }
        if (event.type == sf::Event::KeyReleased &&
            (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)) {
            m_game->stopVerticalMove();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            m_game->shoot();

        }
        if (event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::Space)) {
            m_game->stopShooting();
        }
    }

    void SFMLRoadFighter::pauseScreenEvent(sf::Event &event) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            m_game->continueGame();
        }
    }

    void SFMLRoadFighter::askNameEvent(sf::Event &event) {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128) {
                m_endName += static_cast<char>(event.text.unicode);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
            m_endName = m_endName.substr(0, m_endName.size() - 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            m_game->setText(m_endName);
            m_nameGiven = true;
        }
        if (m_endName.size() > 3) {
            m_endName = m_endName.substr(0, m_endName.size() - 1);
        }
    }


    void SFMLRoadFighter::draw(std::shared_ptr<sf::RenderWindow> &window) {
        m_game->drawWorld();
        drawSideStats(window);
        if (m_game->ispaused()) {
            drawPaused(window);
        }
        if (m_game->hasEnded()) {
            drawEnded(window);
        }

    }

    void SFMLRoadFighter::drawSideStats(std::shared_ptr<sf::RenderWindow> &window) {
        auto speedpos = Transformation::getInstance().locationTransformation(roadfighter::Location(6, -4));
        drawText(window, "speed: " + std::to_string((int) (round(m_game->getsSpeed() * 300))), speedpos);

        auto fuelpos = Transformation::getInstance().locationTransformation(roadfighter::Location(6, -3));
        drawText(window, "Fuel: " + std::to_string((int) (round(m_game->getFuel()))), fuelpos);

        auto scorepos = Transformation::getInstance().locationTransformation(roadfighter::Location(6, -2));
        drawText(window, "score: " + std::to_string(m_game->getScore()), scorepos);

    }

    void SFMLRoadFighter::drawPaused(std::shared_ptr<sf::RenderWindow> &window) {
        sf::RectangleShape transparenrect(sf::Vector2f(window->getSize().x, window->getSize().y));
        transparenrect.setFillColor(sf::Color(0, 0, 0, 200));
        window->draw(transparenrect);

        auto pausepos = Transformation::getInstance().locationTransformation(roadfighter::Location(-1.1, -1));
        drawText(window, "game has been paused", pausepos, sf::Color(128, 128, 128), 24);


        auto spacePos = Transformation::getInstance().locationTransformation(roadfighter::Location(-1, -0.5));
        drawText(window, "press space to continue", spacePos, sf::Color(128, 128, 128), 20);
    }

    void SFMLRoadFighter::drawText(std::shared_ptr<sf::RenderWindow> &window, std::string text,
                                   std::tuple<int, int> position,
                                   sf::Color color, int size) {
        sf::Font font;
        if(!font.loadFromFile("../../SFMLConversion/resources/open-sans/OpenSans-Regular.ttf")){
            throw SFMLConversionException("could not find font to draw text at ../../SFMLConversion/resources/open-sans/OpenSans-Regular.ttf");
        }

        sf::Text towrite;
        towrite.setFont(font);
        towrite.setString(text);
        towrite.setCharacterSize(static_cast<unsigned int>(size));
        towrite.setPosition(std::get<0>(position), std::get<1>(position));

        //setcolor is used instead of setFillcolor because new function wont run on travis/labo pc's
        towrite.setColor(color);
        window->draw(towrite);

    }

    void SFMLRoadFighter::drawEnded(std::shared_ptr<sf::RenderWindow> &window) {
        sf::RectangleShape transparenrect(sf::Vector2f(window->getSize().x, window->getSize().y));
        transparenrect.setFillColor(sf::Color(0, 0, 0, 200));
        window->draw(transparenrect);

        if (!m_nameGiven) {
            auto textpos = Transformation::getInstance().locationTransformation(roadfighter::Location(-2.5, -1.0));
            drawText(window, "please enter your name", textpos, sf::Color(255, 255, 255), 50);
            for (int i = 0; i < m_endName.size(); i++) {
                auto charpos = Transformation::getInstance().locationTransformation(roadfighter::Location(-1 + i, 0));
                drawText(window, std::string(1, m_endName[i]), charpos, sf::Color(255, 255, 255), 50);
            }
        } else {
            auto highscores = roadfighter::HighScoreManager::gethighScores();
            for (int i = 0; i < highscores.size(); i++) {
                auto textpos = Transformation::getInstance().locationTransformation(
                        roadfighter::Location(-1, -2.5 + (0.5 * i)));
                drawText(window,
                         std::to_string(i + 1) + ": " + highscores[i].name + " " + std::to_string(highscores[i].score),
                         textpos, sf::Color(255, 255, 255), 50);
            }
            auto textpos = Transformation::getInstance().locationTransformation(roadfighter::Location(-9, -4));
            drawText(window, "press escape to quit", textpos, sf::Color(128, 128, 128), 20);
        }

    }
}
