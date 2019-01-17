/**
 *@file
 * implementation of the SFMLroadfighter class
 * @author Thibaut Van Goethem
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
        m_input=factory->getController();
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
                //get possible input
                sf::Event event{};
                if (m_window->pollEvent(event)) {
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

                //clear the window, tick the game and redraw the window
                m_window->clear();
                m_game->tick(gameclock.getTimeAsSeconds());
                draw();
                gameclock.restart();

                m_window->display();
            }
        }
    }

    /**
     * all events that happen when the enscreen is being drawn go here
     * @param event the possible event
     * @return none
     * @exception none
     */
    void SFMLRoadFighter::endGameEvent(sf::Event &event) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            m_window->close();
        }
    }

    /**
     * all events that happen when the game is running go here
     * @param event the event
     * @return none
     * @exception none
     */
    void SFMLRoadFighter::MovementEvent(sf::Event &event) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            // left key is pressed: move our player to the left
            m_input->moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            // right key is pressed: move our player to the right
            m_input->moveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            m_input->accelerate();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            m_input->decelerate();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            m_game->pauseGame();
        }
        if (event.type == sf::Event::KeyReleased &&
            (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)) {
            m_input->stopHorizontalMove();

        }
        if (event.type == sf::Event::KeyReleased &&
            (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)) {
            m_input->stopVerticalMove();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            m_input->shoot();

        }
        if (event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::Space)) {
            m_input->noShoot();
        }
    }

    /**
     * all events that happen when the game is paused go here
     * @param event the event
     * @return none
     * @exception none
     */
    void SFMLRoadFighter::pauseScreenEvent(sf::Event &event) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            m_game->continueGame();
        }
    }

    /**
     * all events that happen when the name is being asked go here
     * @param event the event
     * @return none
     * @exception none
     */
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
            m_input->setText(m_endName);
            m_nameGiven = true;
        }
        if (m_endName.size() > 3) {
            m_endName = m_endName.substr(0, m_endName.size() - 1);
        }
    }


    /**
     * this function calls the draw function on the game and posibly draw some extras
     * @return none
     * @excepotion none
     */
    void SFMLRoadFighter::draw() {
        m_game->drawWorld();
        drawSideStats();
        if (m_game->ispaused()) {
            drawPaused();
        }
        if (m_game->hasEnded()) {
            drawEnded();
        }

    }

    /**
     * this function draws the statistics that you see on the right side of the screen
     * @return none
     * @exception none
     */
    void SFMLRoadFighter::drawSideStats() {
        auto speedpos = Transformation::getInstance().locationTransformation(roadfighter::Location(6, -4));
        drawText("speed: " + std::to_string((int) (round(m_game->getsSpeed() * 300))), speedpos);

        auto fuelpos = Transformation::getInstance().locationTransformation(roadfighter::Location(6, -3));
        drawText( "Fuel: " + std::to_string((int) (round(m_game->getFuel()))), fuelpos);

        auto scorepos = Transformation::getInstance().locationTransformation(roadfighter::Location(6, -2));
        drawText("score: " + std::to_string(m_game->getScore()), scorepos);

    }

    /**
     * this function draws the game when it is paused
     * @return none
     * @exception none
     */
    void SFMLRoadFighter::drawPaused() {
        sf::RectangleShape transparenrect(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
        transparenrect.setFillColor(sf::Color(0, 0, 0, 200));
        m_window->draw(transparenrect);

        auto pausepos = Transformation::getInstance().locationTransformation(roadfighter::Location(-1.1, -1));
        drawText("game has been paused", pausepos, sf::Color(128, 128, 128), 24);


        auto spacePos = Transformation::getInstance().locationTransformation(roadfighter::Location(-1, -0.5));
        drawText("press space to continue", spacePos, sf::Color(128, 128, 128), 20);
    }

    /**
     * this is a function that is used to draw text on the screen
     * @param text the text that is going to be drawn
     * @param position a tuple of screenpositions
     * @param color the color of the text
     * @param size the size of the text
     * @return none
     * @exception none
     */
    void SFMLRoadFighter::drawText(std::string text,
                                   std::tuple<int, int> position,
                                   sf::Color color, int size) {
        sf::Font font;
        if(!font.loadFromFile("./resources/open-sans/OpenSans-Regular.ttf")){
            throw SFMLConversionException("could not find font to draw text at ../../SFMLConversion/resources/open-sans/OpenSans-Regular.ttf");
        }

        sf::Text towrite;
        towrite.setFont(font);
        towrite.setString(text);
        towrite.setCharacterSize(static_cast<unsigned int>(size));
        towrite.setPosition(std::get<0>(position), std::get<1>(position));

        //setcolor is used instead of setFillcolor because new function wont run on travis/labo pc's
        towrite.setColor(color);
        m_window->draw(towrite);

    }

    /**
     * this function draws the end game screen with the scores
     * @return none
     * @exception none
     */
    void SFMLRoadFighter::drawEnded() {
        sf::RectangleShape transparenrect(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
        transparenrect.setFillColor(sf::Color(0, 0, 0, 200));
        m_window->draw(transparenrect);

        if (!m_nameGiven) {
            auto textpos = Transformation::getInstance().locationTransformation(roadfighter::Location(-2.5, -1.0));
            drawText( "please enter your name", textpos, sf::Color(255, 255, 255), 50);
            for (int i = 0; i < m_endName.size(); i++) {
                auto charpos = Transformation::getInstance().locationTransformation(roadfighter::Location(-1 + i, 0));
                drawText( std::string(1, m_endName[i]), charpos, sf::Color(255, 255, 255), 50);
            }
        } else {
            auto highscores = roadfighter::HighScoreManager::gethighScores();
            for (int i = 0; i < highscores.size(); i++) {
                auto textpos = Transformation::getInstance().locationTransformation(
                        roadfighter::Location(-1, -2.5 + (0.5 * i)));
                drawText(std::to_string(i + 1) + ": " + highscores[i].name + " " + std::to_string(highscores[i].score),
                         textpos, sf::Color(255, 255, 255), 50);
            }
            auto textpos = Transformation::getInstance().locationTransformation(roadfighter::Location(-9, -4));
            drawText("press escape to quit", textpos, sf::Color(150, 150, 150), 20);
        }

    }
}
