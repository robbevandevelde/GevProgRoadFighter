//
// Created by thibaut on 01.12.18.
//

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
namespace roadfighter {

    class RoadFighterGame {
    public:
        /**
         * default constructor for RoadFighterGame
         */
        RoadFighterGame();

        /**
         * a constructor were the factory that is used to initalise all the objects is given
         * @param factory the fectory that will be used to make everything
         */
        RoadFighterGame(std::shared_ptr<Entity_Factory_base> factory);

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

        void tick(double dt);

        void moveLeft();

        void stopHorizontalMove();

        void moveRight();

        void accelerate();

        void stopVerticalMove();

        void decelerate();

        void initialize();

        double getsSpeed() const;

        void drawWorld() const;

    private:
        double getYvariance() const;

        void normalizeWorld(double ySetback);

    private:
        std::shared_ptr<PlayerCar> m_Player;

        std::shared_ptr<MoveController> m_MoveController;

        std::shared_ptr<EntityTransporter> m_Transporter;

        std::shared_ptr<World> m_world;

        std::shared_ptr<Entity_Factory_base> m_Factory;

    };
}


#endif //GEVPROGROADFIGHTER_ROADFIGHTERGAME_H
