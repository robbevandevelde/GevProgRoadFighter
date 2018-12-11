/**
 * @file
 * this file contains a class that will be the brains of the logic behind the roadfighter game
 */

#ifndef GEVPROGROADFIGHTER_ROADFIGHTERGAME_H
#define GEVPROGROADFIGHTER_ROADFIGHTERGAME_H

#include <memory>
#include "Entity_Factory_base.h"
#include "Entities/World.h"
#include "Entities/PlayerCar.h"
#include "GLL_Entity_Factory.h"
#include "Entities/Entity.h"
#include "MoveController.h"
#include "EntityTransporter.h"
#include "../Utility/Random.h"
namespace roadfighter {

    class RoadFighterGame {
    public:
        /**
         * default constructor for RoadFighterGame
         */
        RoadFighterGame();

        /**
         * a constructor were the factory that is used to initalise all the objects is given
         * @param factory the factory that will be used to make everything
         */
        explicit RoadFighterGame(std::shared_ptr<Entity_Factory_base> factory);

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

        /**
         * a function that will tick the whole game with dt ticks
         * @param dt the amount of ticks the game should move (should be 1 or lower otherwise it's possible more gameticks occur in 1 tick)
         *
         * in this function the position of the objects will always be updated by dt ticks
         * but the gamelogic will only be done if 1 tick has passed
         * so if you call this function with dt being 0.5 twice it will update only the positions the first time,
         * but the second time it will update both the positions and the gamelogic
         */
        void tick(double dt);

        /**
         * a function that updates the movement of all entities by dt ticks
         * @param dt amount of a tick the postions must be updated with
         */
        void movementTick(double dt);

        /**
         * a function that does a logic tick which will update the logic of all entities and possibly add new cars to the world
         */
        void logicTick();

        /**
         * a function that will set the movementcontroller to go left next tick
         */
        void moveLeft();

        /**
         * a fucntion that sets the movementcontroller to none for the horizontal move
         */
        void stopHorizontalMove();

        /**
         * a function that will set the movementcontroller to go right next tick
         */
        void moveRight();

        /**
         * a function that will set the movementcontroller to accelerate in the vertical direction next tick
         */
        void accelerate();

        /**
         * a fucntion that sets the movementcontroller to none for the vertical move
         */
        void stopVerticalMove();

        /**
        * a function that will set the movementcontroller to decelerate in the vertical direction next tick
        */
        void decelerate();

        /**
         * gets the current speed of the playercar
         * @return a double represeting the speed of the playercar
         */
        double getsSpeed() const;

        /**
         * a function that calls the draw function on the world which will then call the draw function on all its entities
         */
        void drawWorld() const;

    private:

        void initialize();

        void addRandomCars();

        double getYvariance() const;

        void normalizeWorld(double ySetback);

    private:
        std::shared_ptr<PlayerCar> m_Player;

        std::shared_ptr<MoveController> m_MoveController;

        std::shared_ptr<EntityTransporter> m_Transporter;

        std::shared_ptr<World> m_world;

        std::shared_ptr<Entity_Factory_base> m_Factory;

        //adjusting the movement of cars can be done as much as you want in a tick but logic may only be done once in a tick
        //this is why this var is kept if it is higher than 1 it means a logicTick needs to be done
        double m_logicTick;

    };
}


#endif //GEVPROGROADFIGHTER_ROADFIGHTERGAME_H
