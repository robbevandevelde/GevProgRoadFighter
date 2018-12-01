//
// Created by thibaut on 01.12.18.
//

#include <RoadFighterGame.h>

#include "RoadFighterGame.h"
namespace roadfighter{
    RoadFighterGame::RoadFighterGame() {
        m_world=std::make_shared<World>(World());
    }

    RoadFighterGame::RoadFighterGame(std::shared_ptr<PlayerCar>& player) {
        m_world=std::make_shared<World>(World());
        m_Player=player;
        m_world.get()->addEntity(m_Player);
    }

    void RoadFighterGame::addObject(std::shared_ptr<CollisionObject>& obj) {
        m_world.get()->addEntity(obj);
    }

    void RoadFighterGame::tick() {
        if(m_nextHorMove==h_left){
            m_Player.get()->setHorizontalSpeed(-1);
        }else if(m_nextHorMove==h_right){
            m_Player.get()->setHorizontalSpeed(1);
        }
        m_nextHorMove=h_none;
        if(m_nextVertMove==v_accel){
            m_Player.get()->accelerate();
        }else if(m_nextVertMove==v_decel){
            m_Player.get()->decelerate();
        }
        m_nextVertMove=v_none;

        m_world.get()->update();
    }

    void RoadFighterGame::setVertMove(EVertMove move) {
        m_nextVertMove=move;
    }

    void RoadFighterGame::setHorMove(EHorMove move) {
        m_nextHorMove=move;
    }



}