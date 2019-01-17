/**
 * @file
 * this file contains the implementation of the RoadfighterGame class
 * @author Thibaut Van Goethem
 */

#include <utility>
#include <RoadFighterGame.h>
#include "GllException.h"

namespace roadfighter{
    /**
    * default constructor for RoadFighterGame
    * @return none
    * @exception none
    */
    RoadFighterGame::RoadFighterGame():m_status(gameRunning) {
        m_Factory=std::make_shared<GLL_Entity_Factory>(GLL_Entity_Factory());
        initialize();
    }

    /**
     * a constructor were the factory that is used to initialise all the objects is given
     * @param factory the factory that will be used to make everything
     * @return none
     * @exception none
     */
    RoadFighterGame::RoadFighterGame(std::shared_ptr<Entity_Factory_base> factory,double ticksPerSec):m_status(gameRunning) {
        m_logicTickSpeed=1/ticksPerSec;
        m_Factory= std::move(factory);
        initialize();
    }

    /**
    * a function that will tick the whole game with dt ticks
    * @param dt the amount of ticks the game should move (should be lower or equal to the logictickspeed otherwise it's possible more gameticks occur in 1 tick)
    *
    * in this function the position of the objects will always be updated by dt ticks
    * but the gamelogic will only be done if 1 tick has passed
    * so if you call this function with dt being 0.5 twice it will update only the positions the first time,
    * but the second time it will update both the positions and the gamelogic
     *
     * @return none
     * @exception none
    */
    void RoadFighterGame::tick(double dt) {
        if(m_status!=gamePaused) {
            movementTick(dt/m_logicTickSpeed);
            m_logicTick += dt;
            while (m_logicTick > m_logicTickSpeed) {
                m_logicTick -= m_logicTickSpeed;
                logicTick();
            }
        }
    }

    /**
     * a function that updates the movement of all entities by dt ticks
     * @param dt amount of a tick the positions must be updated with
     * @return none
     * @exception none
     */
    void RoadFighterGame::movementTick(double dt) {
        //first all cars move forward then the playercar gets moved back to the center
        // the amount the playercar had to move is the same all the other object will move back
        m_world->updateMovement(dt);
        normalizeWorld(getYvariance());
    }

    /**
     * a function that does a logic tick which will update the logic of all entities and possibly add new cars to the world
     * @return none
     * @exception none
     */
    void RoadFighterGame::logicTick() {
        if(m_status==gameRunning) {
            addRandomCars();
            if(testEnd()){
                endGame();
            }
        }
        if(m_status!=gameEnded) {
            m_world->updateLogic();
            m_Transporter->clear();
            if (m_status == gameEnding) {
                if (m_Player->getVerticalSpeed() == 0) {
                    m_status = gameEnded;
                }
            }
        }
        if(m_status==gameEnded&&!m_MoveController->getText().empty()){
            try {
                HighScoreManager::addHighScore(m_MoveController->getText(), m_ScoreObserver->getScore());
            }catch (GllException& except){
                std::cerr<<"an exception occured while adding the highscore"<<std::endl;
                std::cerr<<except.what()<<std::endl;
            }
            m_MoveController->setNone();
        }
    }

    /**
     * function that checks if the game has ended
     * @return bool
     * @exception none
     */
    bool RoadFighterGame::hasEnded() const {
        return m_status==gameEnded;
    }

    /**
     * function that checks if the game is won
     * @return bool
     * @exception none
     */
    bool RoadFighterGame::testEnd() const {
        if(m_status==gameEnded){
            throw GllException("tried to test end game that has already ended");
        }
        return m_Player->getStatus()==Won;
    }

    /**
     * function that ends the game and detaches the scoreobserver
     * @return none
     * @exception none
     */
    void RoadFighterGame::endGame() {
        if(m_status==gameEnded){
            throw GllException("tried to end game that has already ended");
        }
        m_status=gameEnding;
        m_world->dettachAllObservers();
    }

    /**
    * a function that calls the draw function on the world which will then call the draw function on all its entities
     * @return none
     * @exception none
    */
    void RoadFighterGame::drawWorld() const{
        m_world->draw();
    }

    //private function used in constructor
    void RoadFighterGame::initialize() {
        //creat transporter/movecontroller and set these into the factory so they can be given to the cars
        m_Transporter=m_Factory->getTransporter();
        m_MoveController=m_Factory->getController();
        m_ScoreObserver=std::dynamic_pointer_cast<ScoreObserver>(m_Factory->getScoreObserver());
        if(m_Transporter== nullptr||m_MoveController== nullptr||m_ScoreObserver== nullptr){
            throw GllException("no transporter, movecontroller or scoreobserver found while initialising");
        }
        m_world=std::dynamic_pointer_cast<World>(m_Factory->createWorld());

        //create player
        std::shared_ptr<Entity> player=m_Factory->createPlayerCar(-0.5,0,0.4,0.005,0.15,100);
        m_Transporter->addEntity(player);
        m_Player=std::dynamic_pointer_cast<PlayerCar>(player);

        //create 8 racingcars
        std::shared_ptr<Entity> enemy1=m_Factory->createRacingCar(0.5,-1,0.3333,0.005,0.15);
        m_Transporter->addEntity(enemy1);

        std::shared_ptr<Entity> enemy2=m_Factory->createRacingCar(-0.5,-2,0.3333,0.005,0.15);
        m_Transporter->addEntity(enemy2);

        std::shared_ptr<Entity> enemy3=m_Factory->createRacingCar(0.5,-3,0.3333,0.005,0.15);
        m_Transporter->addEntity(enemy3);

        std::shared_ptr<Entity> enemy4=m_Factory->createRacingCar(-0.5,-4,0.3333,0.005,0.15);
        m_Transporter->addEntity(enemy4);

        std::shared_ptr<Entity> enemy5=m_Factory->createRacingCar(0.5,1,0.3333,0.005,0.15);
        m_Transporter->addEntity(enemy5);

        std::shared_ptr<Entity> enemy6=m_Factory->createRacingCar(-0.5,2,0.3333,0.005,0.15);
        m_Transporter->addEntity(enemy6);

        std::shared_ptr<Entity> enemy7=m_Factory->createRacingCar(0.5,3,0.3333,0.005,0.15);
        m_Transporter->addEntity(enemy7);

        std::shared_ptr<Entity> enemy8=m_Factory->createRacingCar(-0.5,4,0.3333,0.005,0.15);
        m_Transporter->addEntity(enemy8);

        std::shared_ptr<Entity> end=m_Factory->createEnd(-100);
        m_Transporter->addEntity(end);
    }

    //private function used to add random cars to the gamefield
    void RoadFighterGame::addRandomCars() {
        int newCarProb=Random::getInstance().getRandom(15);
        if(newCarProb==0){
            int bonusorpassing=Random::getInstance().getRandom(5);
            if(bonusorpassing==0){
                int loc=Random::getInstance().getRandom(6)-3;
                auto bonus=m_Factory->createBonusCar(loc,-5,-0.15);
                m_Transporter->addEntity(bonus);
            }else{
                int loc=Random::getInstance().getRandom(6)-3;
                auto passing=m_Factory->creatPassingCar(loc,-5,-0.15);
                m_Transporter->addEntity(passing);
            }
        }
    }

    /**
    * gets the current speed of the playercar
    * @return a double representing the speed of the playercar
     * @exception none
    */
    double RoadFighterGame::getsSpeed() const {
        return m_Player->getVerticalSpeed();
    }

    //private funtion used to calculate the middle of a vehicle
    double RoadFighterGame::getYvariance() const {
        double toreturn= m_Player->getLoc2().getY()-m_Player->getheight()/2;
        if(toreturn>0){
            throw GllException("playercar with positive yvariance occurred,this should always be negative or 0");
        }
        return toreturn;
    }

    //private function used to set the player back to the middle of the screen
    void RoadFighterGame::normalizeWorld(double ySetback) {
        m_world->setBackY(ySetback);
    }


    /**
    * getter for the current amount of fuel in the playercar
     * @return none
     * @exception none
    */
    double RoadFighterGame::getFuel() const {
        return m_Player->getFuel();
    }

    /**
     * function that gets the score of the player
     * @return an unsigned int denoting the score
     * @exception none
     */
    unsigned int RoadFighterGame::getScore() const {
        return m_ScoreObserver->getScore();
    }

    /**
     * function that pauses the game
     * @return none
     * @exception none
     */
    void RoadFighterGame::pauseGame() {
        if(m_status!=gameEnding){
            m_status=gamePaused;
        }
    }

    /**
     * function that unpauses the game
     * @return none
     * @exception none
     */
    void RoadFighterGame::continueGame() {
        if(m_status!=gameEnding){
            m_status=gameRunning;
        }
    }

    /**
     * function that checks if the game is paused
     * @return bool
     * @exception none
     */
    bool RoadFighterGame::ispaused() const {
        return m_status==gamePaused;
    }

}