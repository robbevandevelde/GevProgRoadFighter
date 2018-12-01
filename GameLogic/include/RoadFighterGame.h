//
// Created by thibaut on 01.12.18.
//

#ifndef GEVPROGROADFIGHTER_ROADFIGHTERGAME_H
#define GEVPROGROADFIGHTER_ROADFIGHTERGAME_H

#include <memory>
#include "Entities/World.h"
#include "Entities/PlayerCar.h"
namespace roadfighter {
    enum EVertMove{v_none,v_accel,v_decel};
    enum EHorMove{h_none,h_left,h_right};
    class RoadFighterGame {
    public:
        /**
         * default constructor for RoadFighterGame
         */
        RoadFighterGame();

        /**
         * constuctor were the player car is given
         * @param player the player
         */
        RoadFighterGame(std::shared_ptr<PlayerCar>& player);

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


        void addObject(std::shared_ptr<CollisionObject>& obj);

        void tick();

        void setVertMove(EVertMove move);

        void setHorMove(EHorMove move);
    private:
        std::shared_ptr<World> m_world;

        std::shared_ptr<PlayerCar> m_Player;

        EVertMove m_nextVertMove;

        EHorMove m_nextHorMove;

    };
}


#endif //GEVPROGROADFIGHTER_ROADFIGHTERGAME_H
