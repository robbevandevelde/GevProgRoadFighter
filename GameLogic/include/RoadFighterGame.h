/**
 * @file
 * this file contains a class that will be the brains of the logic behind the roadfighter game
 * @author Thibaut Van Goethem
 */

#ifndef GEVPROGROADFIGHTER_ROADFIGHTERGAME_H
#define GEVPROGROADFIGHTER_ROADFIGHTERGAME_H

#include <memory>
#include "Entity_Factory_base.h"
#include "Entities/World.h"
#include "Entities/PlayerCar.h"
#include "GLL_Entity_Factory.h"
#include "Entities/Entity.h"
#include "InputController.h"
#include "EntityTransporter.h"
#include "../Utility/Random.h"
#include "Observer/ScoreObserver.h"
#include "HighScoreManager.h"
namespace roadfighter {

    enum EGameStatus{gameRunning,gameEnding,gameEnded,gamePaused};

    class RoadFighterGame {
    public:

        //default constructor
        RoadFighterGame();

        //constructor with the entity factory given and the ticks per second
        explicit RoadFighterGame(std::shared_ptr<Entity_Factory_base> factory,double ticksPerSec);

        /**
         * copy constructor
         * @param copy the other RoadFighterGame that is being copied
         */
        RoadFighterGame(const RoadFighterGame &copy)= default;

        /**
         * move constructor
         * @param Move the other RoadFighterGame that is being moved in this one
         */
        RoadFighterGame(RoadFighterGame &&move)= default;

        /**
         * copy assigment for RoadFighterGame
         * @param other the RoadFighterGame that is being copied
         * @return a new RoadFighterGame that is equal to the other one
         */
        RoadFighterGame& operator=(RoadFighterGame& other)= default;

        /**
         * move assignment for RoadFighterGame
         * @param other other RoadFighterGame that is being moved
         * @return a RoadFighterGame
         * that contains all the data of the first one
         */
        RoadFighterGame& operator=(RoadFighterGame&& other)= default;


        /**
         * destructor for RoadFighterGame
         */
        virtual ~RoadFighterGame()= default;

       //a function that ticks the game with dt ticks (dt should be below 1)
        void tick(double dt);

        //getter for the speed
        double getsSpeed() const;

        //function that calls the draw function on the world
        void drawWorld() const;

        //getter for the fuel
        double getFuel() const;

        //getter for the score
        unsigned int getScore() const;

        //getter for the ended bool
        bool hasEnded() const;

        //getter for whether the game is paused
        void pauseGame();

        //function that continues the game after it was paused
        void continueGame();

        //getter for the paused bool
        bool ispaused() const;

    //all private functions
    private:

        bool testEnd() const;

        void endGame();

        void initialize();

        void addRandomCars();

        double getYvariance() const;

        void normalizeWorld(double ySetback);

        void movementTick(double dt);

        void logicTick();

    //all private variables
    private:
        std::shared_ptr<PlayerCar> m_Player;

        std::shared_ptr<InputController> m_MoveController;

        std::shared_ptr<EntityTransporter> m_Transporter;

        std::shared_ptr<ScoreObserver> m_ScoreObserver;

        std::shared_ptr<World> m_world;

        std::shared_ptr<Entity_Factory_base> m_Factory;

        EGameStatus m_status;

        //adjusting the movement of cars can be done as much as you want in a tick but logic may only be done once in a tick
        //this is why this var is kept if it is higher than 1 it means a logicTick needs to be done
        double m_logicTick;

        //this variable denotes the amount of time goes before another logic ticks should be done
        double m_logicTickSpeed;

    };
}


#endif //GEVPROGROADFIGHTER_ROADFIGHTERGAME_H
